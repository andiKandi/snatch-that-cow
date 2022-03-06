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

#ifndef INIT_TEXTURES_HPP
#define INIT_TEXTURES_HPP

#include "SOIL/SOIL.h"

GLuint pictures[8]; // pictures
void LoadTextures (void){
    ////Textures
    //amongus
    char resolved_path_for_amongus[PATH_MAX];
    realpath("../../gdv-final/textures/amongus.jpg", resolved_path_for_amongus);
    pictures[0] = SOIL_load_OGL_texture
            (
                    resolved_path_for_amongus,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //believe
    char resolved_path_for_believe[PATH_MAX];
    realpath("../../gdv-final/textures/believe.png", resolved_path_for_believe);
    pictures[1] = SOIL_load_OGL_texture
            (
                    resolved_path_for_believe,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //floor_bright
    char resolved_path_for_floor[PATH_MAX];
    realpath("../../gdv-final/textures/floor_bright.jpg", resolved_path_for_floor);
    pictures[2] = SOIL_load_OGL_texture
            (
                    resolved_path_for_floor,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //carpet_white
    char resolved_path_for_carpet[PATH_MAX];
    realpath("../../gdv-final/textures/carpet_white.jpg", resolved_path_for_carpet);
    pictures[3] = SOIL_load_OGL_texture
            (
                    resolved_path_for_carpet,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //rift
    char resolved_path_for_rift[PATH_MAX];
    realpath("../../gdv-final/textures/RiftAndPortal.png", resolved_path_for_rift);
    pictures[4] = SOIL_load_OGL_texture
            (
                    resolved_path_for_rift,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[4]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //static
    char resolved_path_for_static[PATH_MAX];
    realpath("../../gdv-final/textures/static.png", resolved_path_for_static);
    pictures[5] = SOIL_load_OGL_texture
            (
                    resolved_path_for_static,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[5]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //stephan
    char resolved_path_for_stephan[PATH_MAX];
    realpath("../../gdv-final/textures/stephan.png", resolved_path_for_stephan);
    pictures[6] = SOIL_load_OGL_texture
            (
                    resolved_path_for_stephan,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[6]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //stephan
    char resolved_path_for_andi[PATH_MAX];
    realpath("../../gdv-final/textures/andi.png", resolved_path_for_andi);
    pictures[7] = SOIL_load_OGL_texture
            (
                    resolved_path_for_andi,
                    SOIL_LOAD_AUTO,
                    SOIL_CREATE_NEW_ID,
                    SOIL_FLAG_INVERT_Y
            );
    glBindTexture(GL_TEXTURE_2D, pictures[7]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);        // clamp edges
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

#endif //INIT_TEXTURES_HPP
