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
#ifndef RESHAPE_HPP
#define RESHAPE_HPP
// Handles window size adjustments
void Reshape (int w, int h){
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport: to the current window specifications/to the size of our window
    glMatrixMode (GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
    glLoadIdentity (); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.01, 1000.0); //field of view (FOVY = 60°, 30° to the left and 30° to the right), aspect ratio of our window (w/h), near and far plane (0.001, 10000.0): anything with a position less than 0.001 units (away from the camera) won’t be drawn and anything with a position greater than 10000.0 units (away from the camera) won’t be drawn.
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
    glLoadIdentity (); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
}
#endif //RESHAPE_HPP
