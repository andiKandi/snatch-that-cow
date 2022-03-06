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
#ifndef MAINMENU_HPP
#define MAINMENU_HPP
#include "../irrKlang/include/irrKlang.h"
using namespace irrklang;
ISoundEngine *SoundEngine = createIrrKlangDevice();

void menuCB(int item)
{
    switch (item) {                     /* process the popup menu commands */
        case 1:
            /* process menu option A... */
            break;
        case 2:
            /* process menu option sound OFF... */
            SoundEngine->stopAllSounds();
            break;
        case 3:
            /* process menu option sound ON... */
            SoundEngine->play2D("../../gdv-final/sound/breakout.mp3", true);
            break;
        case 4:
            /* process menu option D... */
            break;
        case 5:
            exit(0);                          /* quit the program */
            break;
    }
}
void initMainMenu()
{
    glClearColor ( 0.33f, 0.225f, 0.0f, 1.0f);	//Hintergrundfarbe definieren
    int sub1, sub2, sub3, sub4;                    /* submenu identifiers */
    sub4 = glutCreateMenu(menuCB);             /* submenu sound */
    glutAddMenuEntry("Sound OFF.",2);
    glutAddMenuEntry("Sound ON",3);

    sub3 = glutCreateMenu(menuCB);             /* submenu mouse */
    glutAddMenuEntry("Rotate mouse to look around.",1);
    glutAddMenuEntry("Scroll mouse wheel to zoom in & out.",1);
    glutAddMenuEntry("Right mouse to go back.",1);

    sub2 = glutCreateMenu(menuCB);             /* submenu keyboard */
    glutAddMenuEntry("Horizontal Movement: w a s d", 4);
    glutAddMenuEntry("Vertical Movement: q e", 4);
    glutAddMenuEntry("Light position: arrow keys", 4);

    sub1 = glutCreateMenu(menuCB);             /* submenu controls */
    glutAddSubMenu("Keyboard",  sub2);
    glutAddSubMenu("Mouse",  sub3);

    glutCreateMenu(menuCB);                    /* main popup menu */
    glutAddSubMenu("Controls: ",  sub1);
    glutAddSubMenu("Music: ",  sub4);
    glutAddMenuEntry("Quit",     5);   /* quit option */

    glutAttachMenu(GLUT_RIGHT_BUTTON); /* tie popup menu to right mouse button */
}

#endif //MAINMENU_HPP
