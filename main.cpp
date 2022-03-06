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
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <cstdio>

#include "utilities/MouseMovement.hpp"
#include "utilities/Keyboard.hpp"
#include "utilities/Light.hpp"

#include "skybox/skybox.h"

#include "assimp/Model.h"
#include "assimp/assimpLogger.h"

#include "models/scene/Draw_CompleteScene.hpp"
#include "models/ufo/Draw_Ufo.hpp"
#include "utilities/LoadObjModels.hpp"
#include "utilities/Init_WindowSettings.hpp"
#include "utilities/Init_RenderingSettings.hpp"
#include "utilities/Reshape.hpp"
#include "utilities/RenderScene.hpp"
#include "utilities/MainMenu.hpp"

int main (int argc, char **argv) try {
    glutInit (&argc, argv);
    ////--Initialization of general (mandatory) settings-->
    Init_WindowSettings(); // Set general window settings
    Init_RenderingSetting(); // Enable general display settings
    ////<--Initialization of general (mandatory) settings--
    initMainMenu();
    ////--Loading of scene objects-->
    LoadTextures(); // loads all textures for texturing surfaces
    LoadObjModels(); //Loading of object models via assimp
    LoadSkyboxTextures(); // loads the Room background
    ////<--Loading of scene objects

    ////--Rendering of the scene-->
    glutDisplayFunc(RenderScene); // Tell GLUT to use the method "RenderScene" for rendering
    glutReshapeFunc(Reshape); // Tell GLUT to use the method "Reshape" for rendering: window size adjustment + gluPerspective
    glutIdleFunc(RenderScene); //“idle” method, which handles nothing but calculations: all our variables are updated every time our “display” method is called as if they were in an “idle” method, but we can also get the maximum frame rate possible by utilizing the “idle” methods resources
    ////<--Rendering of the scene--

    ////--mouse control-->
    glutSetCursor(GLUT_CURSOR_NONE);
    glutPassiveMotionFunc(MouseMovement); //check for mouse movement
    glutMouseFunc(MouseFunc); // for zooming in and out
    ////<--mouse control--

    ////--Keyboard control for normal keys: Driving function etc.-->
    glutKeyboardFunc(KeyPressed); // Tell GLUT to use the method "keyPressed" for key presses
    glutKeyboardUpFunc(KeyUp); // Tell GLUT to use the method "keyUp" for key up events
    ////<--Keyboard control for normal keys: Driving function etc.--

    ////--Keyboard control for special keys-->
    glutSpecialFunc(keySpecial); // Tell GLUT to use the method "keySpecial" for special key presses
    glutSpecialUpFunc(keySpecialUp); // Tell GLUT to use the method "keySpecialUp" for special up key events
    ////<--Keyboard control for special keys--

    glutMainLoop ();

    delete scene;
    delete engine;
    delete hullDown;
    delete hullUp;
    delete innerBody;
    delete stacksDown;
    delete stacksUp;
    delete legoCowTail;
    delete legoCowHead;
    delete legoCowBody;
    delete couch;
    delete scenedarkobjects;
    delete scenebrightobjects;
    delete sceneblackobjects;
    delete branches;
    delete leaves;
    SoundEngine->drop(); // delete SoundEngine
    collisionSoundEngine->drop();
    winningSoundEngine->drop();

    return 0;
} catch (std::exception exception) {
    std::cerr << exception.what();
    return -1;
}
//Mittwoch
//TODO final: Video aufzeichnen & Projekt hochladen!!!!!!!!!

