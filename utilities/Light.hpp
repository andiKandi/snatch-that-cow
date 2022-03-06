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

#ifndef LIGHT_HPP
#define LIGHT_HPP

GLfloat whiteSpecularMaterial[] = {1.0, 1.0, 1.0}; //set the material to white
GLfloat mShininess[] = {128}; //set the shininess of the material

// Create light components
GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat diffuseLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };

//light position variables
GLfloat lightPositionX = 100.f;
GLfloat lightPositionY = 100.0;
GLfloat lightPositionZ = 100.0;
GLfloat lightPositionW = 1.0;

void Light (void) {
    //light settings
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);   //Set ambient intensity for entire scene

    GLfloat LightPosition[] = {lightPositionX, lightPositionY, lightPositionZ, lightPositionW}; //set the LightPosition to the specified values
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    //material settings
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, whiteSpecularMaterial);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mShininess);

}

#endif //LIGHT_HPP
