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
#include <climits>
#include "GL/glut.h"
#include "SOIL/SOIL.h"
#include "skybox.h"
#include <stdlib.h>
#include <linux/limits.h>

GLuint skybox[6]; // skybox sites

// load textures
void LoadSkyboxTextures() {

    char resolved_path[PATH_MAX];

    realpath("../../gdv-final/textures/stars.jpg", resolved_path);
    skybox[0] = SOIL_load_OGL_texture
            (
                    resolved_path,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}


// display skybox
void DisplaySkyboxTextures() {
    glEnable(GL_TEXTURE_2D);            // enable texturing
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPushMatrix();

    glScalef(1000., 1000., 1000.);
    glDisable(GL_DEPTH_TEST);

    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(0, 1); glVertex3f(0.5f, 0.5f, -0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 1); glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0, 1); glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 1); glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1, 0); glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f( 0.5f, 0.5f, 0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f, 0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f,-0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, skybox[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();

    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}