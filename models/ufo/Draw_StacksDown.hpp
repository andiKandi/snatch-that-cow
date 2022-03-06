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
#ifndef DRAW_STACKSDOWN_HPP
#define DRAW_STACKSDOWN_HPP

float yRotationAngleStacksDown = 0.0f; // The angle of rotation for our object

Model* stacksDown = new Model();

void Draw_StacksDown(){
    glPushMatrix();
    yRotationAngleStacksDown -= 4.f; // Increment our rotation value
    if (yRotationAngleStacksDown > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
        yRotationAngleStacksDown -= 360.0f; // Subtract 360 degrees off of our rotation

    glRotatef(yRotationAngleStacksDown, 0.0f, 1.0f, 0.0f); // Rotate our object around the y axis
    for (unsigned int i = 0; i < stacksDown->getMeshes().size(); i++) {
        stacksDown->Draw(stacksDown->getMeshes().at(i));
    }
    glPopMatrix();
}

#endif //DRAW_STACKSDOWN_HPP
