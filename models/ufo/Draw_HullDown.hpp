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
#ifndef DRAW_HULLDOWN_HPP
#define DRAW_HULLDOWN_HPP


float yRotationAngleHullDown = 0.0f; // The angle of rotation for our object

Model* hullDown = new Model();

void Draw_HullDown() {
    glPushMatrix();
    yRotationAngleHullDown += 2.f; // Increment our rotation value
    if (yRotationAngleHullDown > 360.0f) // If we have rotated beyond 360 degrees (a full rotation)
        yRotationAngleHullDown -= 360.0f; // Subtract 360 degrees off of our rotation

    glRotatef(yRotationAngleHullDown, 0.0f, 1.0f, 0.0f); // Rotate our object around the y axis
    for (unsigned int i = 0; i < hullDown->getMeshes().size(); i++) {
        hullDown->Draw(hullDown->getMeshes().at(i));
    }
    glPopMatrix();
}

#endif //DRAW_HULLDOWN_HPP
