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
//Model.h - Definiert die Model-Klasse.
#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include <assimp/scene.h>
#include <assimp/cimport.h>
#include "vector"
class Model
{
public:
    Model();
    ~Model();
    void importModel(std::string filename);
    void Draw(Mesh* mesh);
    const std::vector<Mesh *> &getMeshes() const;
private:
    //Assimp Szene und Importer
    const aiScene* scene;
    Assimp::Importer* importer;
    //Die Meshes in unserer Szene
    std::vector<Mesh*> meshes;
};

#endif //MODEL_H