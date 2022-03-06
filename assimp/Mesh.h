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
//Mesh.h - Definiert die Mesh-Klasse für die Speicherung
//und den Zugriff auf die Daten eines Meshes.
#ifndef MESH_H
#define MESH_H


#include <GL/freeglut.h>
#include <assimp/scene.h>
#include "assimp/Importer.hpp"
#include "assimp/postprocess.h"
class Mesh
{
public:
    //Konstruktor, der alle wichtigen Werte des Meshes übernimmt.
    Mesh(unsigned int numVertices, aiVector3D* vertices,
         aiVector3D* normals, unsigned int numFaces, aiFace* faces);
    aiVector3D *getVertices() const;
    aiVector3D *getNormals() const;
    aiVector3D *getTextureCoords() const;
    GLuint *getIndices() const;
    GLuint getNumVertices() const;
    GLuint getNumIndices() const;
    //Destruktor, der am Ende des Programms aufräumt.
    ~Mesh(void);
private:
    //Die geladenen Vertices, Normals und Texturkoordinaten als Vektoren
    aiVector3D* vertices;
    aiVector3D* normals;
    aiVector3D* textureCoords;
    GLuint* indices;

    //Die Anzahl der Vertices bzw. Indices
    GLuint numVertices;
    GLuint numIndices;
};

#endif //MESH_H
