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

#ifndef INIT_RENDERINGSETTINGS_HPP
#define INIT_RENDERINGSETTINGS_HPP
void Init_RenderingSetting (void) {
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0
    //glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE); //affect all faces, diffuse reflection properties (maybe keep switched off or everything looks "stale")
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
    glEnable(GL_NORMALIZE); //normalize normals for correct lighting calculation
    glClearDepth(1.0);
}
#endif //INIT_RENDERINGSETTINGS_HPP
