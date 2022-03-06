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

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Light.hpp"
#include "../models/ufo/Draw_Engine.hpp"

//position of ???
float xPositionUfo = 0, yPositionUfo = 0, zPositionUfo = 0;

bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255); True will be pressed, and False will be not pressed.
bool* keySpecialStates = new bool[246]; // Create an array of boolean values of length 256 (0-255)

float movementTiltingAngle; //for tilting the ship, when moving
float movementTiltingAxisX {}, movementTiltingAxisY {}, movementTiltingAxisZ {};

////Keyboard control for normal keys: Driving function etc.
void KeyPressed (unsigned char key, int x, int y) {
    keyStates[key] = true; // Set the state of the current key to pressed
} // Registers which keys were pressed
void KeyUp (unsigned char key, int x, int y) {
    keyStates[key] = false; // Set the state of the current key to not pressed

    //tilting ship to normal/untilted position
    movementTiltingAngle = 0;
    movementTiltingAxisX = 1.0;
    movementTiltingAxisY = 1.0;
    movementTiltingAxisZ = 1.0;

} // Registers which keys were released

void KeyOperations (void) {
    ////movement-->
    if (keyStates['w'] && keyStates[32])//accelerated frontways moving speed
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f);
        xPositionUfo += float(1.25f * sin(yrotrad));
        zPositionUfo -= float(1.25f * cos(yrotrad));
        yPositionUfo -= float(1.25f * sin(xrotrad));

        //engine moves faster, when ship moves
        if (engineMovingUp) // If we are moving up
            yLocationEngine -= 0.02f; // Move up along our yLocation
        else  // Otherwise
            yLocationEngine += 0.02f; // Move down along our yLocation

        if (yLocationEngine < -0.5f) // If we have gone down too far
            engineMovingUp = false; // Reverse our direction so we are moving down
        else if (yLocationEngine > 0.0f) // Else if we have gone up too far
            engineMovingUp = true; // Reverse our direction so we are moving up
    }

    if (keyStates['w'])//normal frontways moving speed
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f);
        xPositionUfo += 0.5 * float(sin(yrotrad));
        zPositionUfo -= 0.5 * float(cos(yrotrad));
        yPositionUfo -= 0.5 * float(sin(xrotrad));

        //engine moves faster, when ship moves
        if (engineMovingUp) // If we are moving up
            yLocationEngine -= 0.02f; // Move up along our yLocation
        else  // Otherwise
            yLocationEngine += 0.02f; // Move down along our yLocation

        if (yLocationEngine < -0.5f) // If we have gone down too far
            engineMovingUp = false; // Reverse our direction so we are moving down
        else if (yLocationEngine > 0.0f) // Else if we have gone up too far
            engineMovingUp = true; // Reverse our direction so we are moving up

        //ship tilts frontways
        movementTiltingAngle = -20;
        movementTiltingAxisX = 1.0;
        movementTiltingAxisY = 0.0;
        movementTiltingAxisZ = 0.0;
    }
    if (keyStates['s'])
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f);
        xPositionUfo -= 0.5 * float(sin(yrotrad));
        zPositionUfo += 0.5 * float(cos(yrotrad));
        yPositionUfo += 0.5 * float(sin(xrotrad));

        //engine moves faster, when ship moves
        if (engineMovingUp) // If we are moving up
            yLocationEngine -= 0.02f; // Move up along our yLocation
        else  // Otherwise
            yLocationEngine += 0.02f; // Move down along our yLocation

        if (yLocationEngine < -0.5f) // If we have gone down too far
            engineMovingUp = false; // Reverse our direction so we are moving down
        else if (yLocationEngine > 0.0f) // Else if we have gone up too far
            engineMovingUp = true; // Reverse our direction so we are moving up

        //ship tilts backways
        movementTiltingAngle = 20;
        movementTiltingAxisX = 1.0;
        movementTiltingAxisY = 0.0;
        movementTiltingAxisZ = 0.0;
    }
    if (keyStates['d'])
    {
        float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xPositionUfo += 0.5 * float(cos(yrotrad)) * 1.5;
        zPositionUfo += 0.5 * float(sin(yrotrad)) * 1.5;

        //engine moves faster, when ship moves
        if (engineMovingUp) // If we are moving up
            yLocationEngine -= 0.02f; // Move up along our yLocation
        else  // Otherwise
            yLocationEngine += 0.02f; // Move down along our yLocation

        if (yLocationEngine < -0.5f) // If we have gone down too far
            engineMovingUp = false; // Reverse our direction so we are moving down
        else if (yLocationEngine > 0.0f) // Else if we have gone up too far
            engineMovingUp = true; // Reverse our direction so we are moving up

        //ship tilts backways
        movementTiltingAngle = -20;
        movementTiltingAxisX = 0.0;
        movementTiltingAxisY = 0.0;
        movementTiltingAxisZ = 1.0;
    }
    if (keyStates['a'])
    {
        float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xPositionUfo -= 0.5 * float(cos(yrotrad)) * 1.5;
        zPositionUfo -= 0.5 * float(sin(yrotrad)) * 1.5;

        //engine moves faster, when ship moves
        if (engineMovingUp) // If we are moving up
            yLocationEngine -= 0.02f; // Move up along our yLocation
        else  // Otherwise
            yLocationEngine += 0.02f; // Move down along our yLocation

        if (yLocationEngine < -0.5f) // If we have gone down too far
            engineMovingUp = false; // Reverse our direction so we are moving down
        else if (yLocationEngine > 0.0f) // Else if we have gone up too far
            engineMovingUp = true; // Reverse our direction so we are moving up

        //ship tilts backways
        movementTiltingAngle = 20;
        movementTiltingAxisX = 0.0;
        movementTiltingAxisY = 0.0;
        movementTiltingAxisZ = 1.0;
    }

    if (keyStates['e'])//e key: go up
    {
        yPositionUfo += 0.5f;
        //engine moves faster, when ship moves
        if (engineMovingUp) // If we are moving up
            yLocationEngine -= 0.02f; // Move up along our yLocation
        else  // Otherwise
            yLocationEngine += 0.02f; // Move down along our yLocation

        if (yLocationEngine < -0.5f) // If we have gone down too far
            engineMovingUp = false; // Reverse our direction so we are moving down
        else if (yLocationEngine > 0.0f) // Else if we have gone up too far
            engineMovingUp = true; // Reverse our direction so we are moving up
    }
    if (keyStates['q'])//'<'-key as substitute for shift: go down
    {
        yPositionUfo -= 0.5f;
        //engine moves faster, when ship moves
        if (engineMovingUp) // If we are moving up
            yLocationEngine -= 0.02f; // Move up along our yLocation
        else  // Otherwise
            yLocationEngine += 0.02f; // Move down along our yLocation

        if (yLocationEngine < -0.5f) // If we have gone down too far
            engineMovingUp = false; // Reverse our direction so we are moving down
        else if (yLocationEngine > 0.0f) // Else if we have gone up too far
            engineMovingUp = true; // Reverse our direction so we are moving up
    }
    ////<--movement

    ////escape-->
    if (keyStates[27])
    {
        exit(0);
    }
    ////<--escape

} // Key operation logic: commands for specific keys

////Keyboard control for special keys
void keySpecial (int key, int x, int y) {
    keySpecialStates[key] = true;
}
void keySpecialUp (int key, int x, int y) {
    keySpecialStates[key] = false;
}
void KeySpecialOperations(void) {
    ////Light1() light movement
    if (keySpecialStates[GLUT_KEY_UP]) {
        lightPositionY += 50.0; //move the light up
        std::cout << "lightPositionY: " << lightPositionY << std::endl;
    }
    if (keySpecialStates[GLUT_KEY_DOWN])
    {
        lightPositionY -= 50.0; //move the light down
        std::cout << "lightPositionY: " << lightPositionY << std::endl;
    }
    if (keySpecialStates[GLUT_KEY_LEFT])
    {
        lightPositionX -= 50.0; //move the light left
        std::cout << "lightPositionX: " << lightPositionX << std::endl;
    }
    if (keySpecialStates[GLUT_KEY_RIGHT])
    {
        lightPositionX += 50.0; //move the light right
        std::cout << "lightPositionX: " << lightPositionX << std::endl;
    }
}
#endif //KEYBOARD_HPP
