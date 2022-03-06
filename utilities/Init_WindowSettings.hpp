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

#ifndef INIT_WINDOWSETTINGS_HPP
#define INIT_WINDOWSETTINGS_HPP
void Init_WindowSettings (void) {
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize (1920, 1080);
    glutInitWindowPosition (450, 100);
    glutCreateWindow ("Snatch That Cow!");
    glutFullScreen(); // making the window full screen
}
#endif //INIT_WINDOWSETTINGS_HPP
