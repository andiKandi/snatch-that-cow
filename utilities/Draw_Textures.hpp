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

#ifndef DRAW_PICTURES_HPP
#define DRAW_PICTURES_HPP

#include "LoadTextures.hpp"

void Draw_Textures(){
    glEnable(GL_TEXTURE_2D);            // enable texturing
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
 //   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); //lower resolution
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // higher resolution

    //// --amongus-picture front-->
    glPushMatrix();
    glScalef(20., 35., 1.);
    glRotatef(90.f,0.f,0.f,1.f);
    glRotatef(-90.f,1.f,0.f,0.f);
    glRotatef(90.f,0.f,1.f,0.f);
    glTranslatef(5.7f,19.6f,-0.5f);
    glBindTexture(GL_TEXTURE_2D, pictures[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
    //// <--amongus-picture front--

    //// --believe-picture front-->
    glPushMatrix();
    glScalef(20., 35., 1.);
    glRotatef(90.f,0.f,0.f,1.f);
    glRotatef(-270.f,1.f,0.f,0.f);
    glRotatef(90.f,0.f,1.f,0.f);
    glTranslatef(-1.6f,220.f,0.0f);
    glBindTexture(GL_TEXTURE_2D, pictures[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
    //// <--believe-picture front--

    //// --floor-texture-->
    glPushMatrix();
    glScalef(190., 1., 260.);
    glTranslatef(0.35f,-50.0f,0.4f);
    glBindTexture(GL_TEXTURE_2D, pictures[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
    //// <--floor-texture--

    //// --carpet-texture-->
    glPushMatrix();
    glRotatef(95.f,0.f,1.f,0.f);
    glScalef(80., 1., 110.);
    glTranslatef(-1.6f,-49.0f,0.55f);
    glBindTexture(GL_TEXTURE_2D, pictures[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
    //// <--carpet-texture--

    ////--rift-texture-->
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glRotatef(90.0f,0.0f,0.0f,1.0f);
    glScalef(30.0f, 1.0f, 40.0f);
    glTranslatef(0.0f,30.0f,0.5f);
    glBindTexture(GL_TEXTURE_2D, pictures[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glDisable(GL_BLEND);
    glPopMatrix();
    //// <--rift-texture--

    ////--static-texture-->
    glPushMatrix();
    glScalef(47.1f, 25.5f, 1.0f);
    glRotatef(90.f,0.f,0.f,1.f);
    glRotatef(-90.f,1.f,0.f,0.f);
    glRotatef(90.f,0.f,1.f,0.f);
    glTranslatef(1.0145f,12.5f,-0.66f);
    glBindTexture(GL_TEXTURE_2D, pictures[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
    //// <--static-texture--

    ////--stephan-picture-->
    glPushMatrix();
    glScalef(1.0f, 13.0f, 17.5f);
    glRotatef(90.f,0.f,0.f,1.f);
    glRotatef(90.f,0.f,1.f,0.f);
    glTranslatef(-8.645,16.0f,-0.1825f);
    glBindTexture(GL_TEXTURE_2D, pictures[6]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
    //// <--stephan-picture--

    ////--andi-picture-->
    glPushMatrix();
    glScalef(1.0f, 21.3f, 10.5f);
    glRotatef(90.f,0.f,0.f,1.f);
    glRotatef(90.f,0.f,1.f,0.f);
    glTranslatef(-15.95f,16.0f,-0.088);
    glBindTexture(GL_TEXTURE_2D, pictures[7]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 0); glVertex3f( 0.5f,-0.5f,-0.5f);
    glTexCoord2f(1, 1); glVertex3f( 0.5f,-0.5f, 0.5f);
    glTexCoord2f(0, 1); glVertex3f(-0.5f,-0.5f, 0.5f);
    glEnd();
    glPopMatrix();
    //// <--andi-picture--

    glDisable(GL_TEXTURE_2D);
}

#endif //DRAW_PICTURES_HPP
