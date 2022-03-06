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
#ifndef DRAW_INNERBODY_HPP
#define DRAW_INNERBODY_HPP

float yRotationAngleInnerBody = 0.0f; // The angle of rotation for our object

//--for collision detection-->
GLfloat distanceUfoToCow {};
const int ufoRadius = 2;
//<--for collision detection--

Model* innerBody = new Model();

void Draw_InnerBody(){
    glPushMatrix();

    //--rotates the innerBody around the y-axis-->
    yRotationAngleInnerBody -= 4.f; // Increment our rotation value
    if (yRotationAngleInnerBody > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
        yRotationAngleInnerBody -= 360.0f; // Subtract 360 degrees off of our rotation
    glRotatef(yRotationAngleInnerBody, 0.0f, 1.0f, 0.0f); // Rotate our object around the y axis
    //<--rotates the innerBody around the y-axis--

    //--draws point inside the innerbody of the ufo for collision detection-->
    glBegin(GL_POINTS);
    glVertex3f(xPositionUfo,yPositionUfo,zPositionUfo); //is 0.0f and stays 0.0f
    glEnd();
    //<--draws point inside the innerbody of the ufo for collision detection--

    for (unsigned int i = 0; i < innerBody->getMeshes().size(); i++) {//draw the object meshes
        innerBody->Draw(innerBody->getMeshes().at(i));
    }
    glPopMatrix();
}

#endif //DRAW_INNERBODY_HPP
