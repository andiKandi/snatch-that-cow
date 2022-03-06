/**
 * Copyright (C) 17/03/2021 Harijan Stephan, Kraus Andreas
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "Model.h"


//Import die angegebene 3D-Szene mit dem Assimp importer und speichert die Vertex-Daten in den
void Model::importModel(std::string filename)
{
    importer = new Assimp::Importer();
    scene = importer->ReadFile(filename,
                               aiProcess_Triangulate            |
                               aiProcess_GenSmoothNormals       |
                               aiProcess_JoinIdenticalVertices  |
                               aiProcess_ImproveCacheLocality   |
                               aiProcess_SortByPType);

    for(unsigned int i = 0; i < scene->mNumMeshes; i++)
    {
        Mesh* tempMesh = new Mesh(scene->mMeshes[i]->mNumVertices,
                                  scene->mMeshes[i]->mVertices,
                                  scene->mMeshes[i]->mNormals,
                                  scene->mMeshes[i]->mNumFaces,
                                  scene->mMeshes[i]->mFaces);

        meshes.push_back(tempMesh);
    }
}

//In der Draw-Methode werden die Objekte in den Backbuffer gezeichnet.
void Model::Draw(Mesh* mesh)
{
    //Zeichnet das Mesh mittels Vertex array.
    //Aktiviert die Arrays für Vertices und Normals.
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);

    //Setzt den Pointer auf den Normal- und Vertex-Array
    glNormalPointer(GL_FLOAT, 0, mesh->getNormals());
    glVertexPointer(3, GL_FLOAT, 0, mesh->getVertices());

    //Zeichnet die Elemente als Dreiecke anhand der Indices
    glDrawElements(GL_TRIANGLES, mesh->getNumIndices(), GL_UNSIGNED_INT, mesh->getIndices());

    //Deaktiviert danach wieder die Arrays.
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
}


Model::Model() {
}


Model::~Model() {
    aiReleaseImport(scene);
}

const std::vector<Mesh *> &Model::getMeshes() const {
    return meshes;
}
