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
//Mesh.cpp - Implementiert die Mesh-Klasse und dessen Konstruktor
//und Destruktor.
#include "Mesh.h"

//übergibt die Werte des Meshes an die eigenen Variablen
//und extrahiert die Indices aus den einzelnen Faces.
Mesh::Mesh(unsigned int numVertices, aiVector3D* vertices,
           aiVector3D* normals, unsigned int numFaces, aiFace* faces)
{
    this->numVertices = numVertices;
    this->vertices = vertices;
    this->normals = normals;
    this->numIndices = numFaces*3;
    this->indices = new GLuint[this->numIndices];
    for(unsigned int i = 0; i < numFaces; i++)
    {
        indices[i*3] = (GLuint)faces[i].mIndices[0];
        indices[i*3+1] = (GLuint)faces[i].mIndices[1];
        indices[i*3+2] = (GLuint)faces[i].mIndices[2];
    }
}

//Löscht die gespeicherten Indices
Mesh::~Mesh(void)
{
    delete [] indices;
}

aiVector3D *Mesh::getVertices() const {
    return vertices;
}

aiVector3D *Mesh::getNormals() const {
    return normals;
}

aiVector3D *Mesh::getTextureCoords() const {
    return textureCoords;
}

GLuint *Mesh::getIndices() const {
    return indices;
}

GLuint Mesh::getNumVertices() const {
    return numVertices;
}

GLuint Mesh::getNumIndices() const {
    return numIndices;
}
