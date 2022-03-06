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
#ifndef RENDERSCENE_HPP
#define RENDERSCENE_HPP

#include "CollisionDetection.hpp"
#include "../models/npc/Draw_LegoCow.hpp"
#include "Draw_Textures.hpp"
#include "WinningCondition.hpp"
void RenderScene (void) {

    KeyOperations(); // Control of character with normal keys
    KeySpecialOperations(); // Control of character with special keys

    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    Light(); // Diffuse light variations

    DisplaySkyboxTextures(); // must be before loadIdentity!

    glLoadIdentity();
    WinningCondition();
    ////--Collision detection between ufo and cow npc-->
    CollisionDetection(cowOnePosition, cowOneIsAlive);//1
    CollisionDetection(cowTwoPosition, cowTwoIsAlive);//2
    CollisionDetection(cowThreePosition, cowThreeIsAlive);//3
    CollisionDetection(cowFourPosition, cowFourIsAlive);//4
    CollisionDetection(cowFivePosition, cowFiveIsAlive);//5
    CollisionDetection(cowSixPosition, cowSixIsAlive);//6
    CollisionDetection(cowSevenPosition, cowSevenIsAlive);//7
    CollisionDetection(cowEightPosition, cowEightIsAlive);//8
    CollisionDetection(cowNinePosition, cowNineIsAlive);//9
    CollisionDetection(cowTenPosition, cowTenIsAlive);//10
    ////<--Collision detection between ufo and cow npc--

    ////--camera and action around the "Character"-->
    glTranslatef(0.0f, 0.0f, -camDistance);
    glRotatef(xrot,1.0,0.0,0.0);

    ////--UFO-Model-->
    glPushMatrix();
    glRotatef(movementTiltingAngle,movementTiltingAxisX,movementTiltingAxisY,movementTiltingAxisZ);//tilts the UFO when it moves
    Draw_Ufo();
    glPopMatrix();
    ////<--UFO-Model--


    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xPositionUfo, -yPositionUfo, -zPositionUfo); //translate the screen to the position of our camera
    ////<--Camera and Action around the "Character"--

    ////--static objects-->
    glPushMatrix();
    Draw_Textures();
    Draw_LegoCow(cowOnePosition,cowOneIsAlive);//draws npc;
    Draw_LegoCow(cowTwoPosition,cowTwoIsAlive);//draws npc;
    Draw_LegoCow(cowThreePosition,cowThreeIsAlive);//draws npc;
    Draw_LegoCow(cowFourPosition,cowFourIsAlive);//draws npc;
    Draw_LegoCow(cowFivePosition,cowFiveIsAlive);//draws npc;
    Draw_LegoCow(cowSixPosition,cowSixIsAlive);//draws npc;
    Draw_LegoCow(cowSevenPosition,cowSevenIsAlive);//draws npc;
    Draw_LegoCow(cowEightPosition,cowEightIsAlive);//draws npc;
    Draw_LegoCow(cowNinePosition,cowNineIsAlive);//draws npc;
    Draw_LegoCow(cowTenPosition,cowTenIsAlive);//draws npc;
    Draw_CompleteScene();
    glPopMatrix();
    ////<--static objects--

    glutSwapBuffers(); //swap the buffers
}
#endif //RENDERSCENE_HPP
