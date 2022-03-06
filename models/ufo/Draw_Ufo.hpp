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
#ifndef DRAW_UFO_HPP
#define DRAW_UFO_HPP

#include "../../models/ufo/Draw_HullDown.hpp"
#include "../../models/ufo/Draw_InnerBody.hpp"
#include "../../models/ufo/Draw_HullUp.hpp"
#include "../../models/ufo/Draw_StacksDown.hpp"
#include "../../models/ufo/Draw_StacksUp.hpp"
#include "../../models/ufo/Draw_Engine.hpp"
bool UfoMovingUp = false; // Whether or not we are moving up or down
float yRotationAngleUfo = 0.0f; // The angle of rotation for our object
float yLocationUfo = 0.0f; // Keep track of our position on the y axis.

void Draw_Ufo(){
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);

    glPushMatrix();
    if (UfoMovingUp) { // If we are moving up
        yLocationUfo -= 0.003f; // Move up along our yLocation
    }
    else {// Otherwise
        yLocationUfo += 0.003f; // Move down along our yLocation
    }

    if (yLocationUfo < -0.15f) { // If we have gone down too far
        UfoMovingUp = false; // Reverse our direction so we are moving down
    }
    else if (yLocationUfo > 0.15f) { // Else if we have gone up too far
        UfoMovingUp = true; // Reverse our direction so we are moving up
    }

    yRotationAngleUfo += 1.f; // Increment our rotation value
    if (yRotationAngleUfo > 360.0f) {// If we have rotated beyond 360 degrees (a full rotation)
        yRotationAngleUfo -= 360.0f; // Subtract 360 degrees off of our rotation
    }
    
    glTranslatef(0.0f, yLocationUfo, 0.0f); // Translate our object along the y axis
    glRotatef(yRotationAngleUfo, 0.03, 1.0f, 0.0f); // Rotate our object around the y axis

    glColor4f(0.87843137254902f, 0.23921568627451f, 0.184313725490196f, 0.345098039215686f); // Set the colour to green and fully opaque
    Draw_Engine();
    glColor4f(0.368627450980392f, 0.87843137254902f, 0.592156862745098f, 0.345098039215686f); // Set the colour
    Draw_HullDown();
    glColor4f(0.87843137254902f, 0.784313725490196f, 0.274509803921569f, 0.345098039215686f); // Set the colour
    Draw_HullUp();
    glColor4f(1.0f,0.0f,0.0f,1.0f);
    Draw_InnerBody();
    glColor4f(0.184313725490196f, 0.141176470588235f, 0.87843137254902f, 0.345098039215686f); // Set the colour to green and fully opaque
    Draw_StacksDown();
    glColor4f(0.184313725490196f, 0.141176470588235f, 0.87843137254902f, 0.345098039215686f); // Set the colour to green and fully opaque
    Draw_StacksUp();
    glPopMatrix();

    glDisable(GL_COLOR_MATERIAL);
}

#endif //DRAW_UFO_HPP
