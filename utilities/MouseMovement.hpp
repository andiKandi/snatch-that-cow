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
#ifndef MOUSEMOVEMENT_HPP
#define MOUSEMOVEMENT_HPP

float lastx, lasty;

//angle of rotation
float xrot = 0, yrot = 0;

float camDistance = 10.0f; // our radius distance from our character

void MouseMovement(int x, int y) {
    int diffx=x-lastx; //check the difference between the     current x and the last x position
    int diffy=y-lasty; //check the difference between the     current y and the last y position
    lastx=x; //set lastx to the current x position
    lasty=y; //set lasty to the current y position
    xrot += (float) diffy; //set the xrot to xrot with the addition    of the difference in the y position
    yrot += (float) diffx;    //set the xrot to yrot with the addition     of the difference in the x position
}

void MouseFunc(int button, int state, int x, int y){

    GLfloat min_z = -1.0;
    GLfloat max_z = 100.0;

    if (button == 4 && camDistance < max_z) {
        camDistance += 3.0;
    }
    else if (button == 3 && camDistance > min_z) {
        camDistance -= 3.0;
    }
}
#endif //MOUSEMOVEMENT_HPP