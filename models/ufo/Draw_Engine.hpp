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
#ifndef DRAW_ENGINE_HPP
#define DRAW_ENGINE_HPP

#include "../../assimp/Model.h"

Model* engine = new Model();
bool engineMovingUp = false; // Whether or not we are moving up or down
float yLocationEngine = 0.0f; // Keep track of our position on the y axis.
float yRotationAngleEngine = 0.0f; // The angle of rotation for our object

void Draw_Engine(){
    glPushMatrix();
    if (engineMovingUp) // If we are moving up
        yLocationEngine -= 0.003f; // Move up along our yLocation
    else  // Otherwise
        yLocationEngine += 0.003f; // Move down along our yLocation

    if (yLocationEngine < -0.5f) // If we have gone down too far
        engineMovingUp = false; // Reverse our direction so we are moving down
    else if (yLocationEngine > 0.0f) // Else if we have gone up too far
        engineMovingUp = true; // Reverse our direction so we are moving up

    yRotationAngleEngine += 5.f; // Increment our rotation value
    if (yRotationAngleEngine > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
        yRotationAngleEngine -= 360.0f; // Subtract 360 degrees off of our rotation

    glTranslatef(0.0f, yLocationEngine, 0.0f); // Translate our object along the y axis
    glScalef(1.1f, 1.1, 1.1f);
    glRotatef(yRotationAngleEngine, 0.075f, 1.0f, 0.0f); // Rotate our object around the y axis
    for (unsigned int i = 0; i < engine->getMeshes().size(); i++) {
        engine->Draw(engine->getMeshes().at(i));
    }
    glPopMatrix();
}

#endif //DRAW_ENGINE_HPP
