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
#ifndef DRAW_LEGOCOW_HPP
#define DRAW_LEGOCOW_HPP

GLfloat cowOnePosition []{105.f, -20.5f, 15.f}; //drumset
GLfloat cowTwoPosition []{50.f, -38.f, 30.f}; //couch table
GLfloat cowThreePosition []{30.f, -40.f, -5.f}; //tv
GLfloat cowFourPosition []{31.f, -31.7f, 60.f}; //couch
GLfloat cowFivePosition []{75.f, -48.f, 130.f}; //carpet
GLfloat cowSixPosition []{140.f, -30.f, 165.f}; //alarmclock
GLfloat cowSevenPosition []{-8.5f, 17.f, 100.f}; //book cupboard
GLfloat cowEightPosition []{5.f, -26.f, 175.f}; //desktop
GLfloat cowNinePosition []{30.f, -23.5f, 215.f}; //dresser
GLfloat cowTenPosition []{140.f, -28.f, 205.f}; //bed

bool cowOneIsAlive {true};
bool cowTwoIsAlive {true};
bool cowThreeIsAlive {true};
bool cowFourIsAlive {true};
bool cowFiveIsAlive {true};
bool cowSixIsAlive {true};
bool cowSevenIsAlive {true};
bool cowEightIsAlive {true};
bool cowNineIsAlive {true};
bool cowTenIsAlive {true};

const int cowRadius = 1;

Model* legoCowBody = new Model();
Model* legoCowHead = new Model();
Model* legoCowTail = new Model();

void Draw_LegoCowBody(bool isAlive) {
    glPushMatrix();
    glColor4f(0.231372549019608f, 0.035294117647059f, 0.007843137254902f, 0.090196078431373f);
    if (isAlive) {
        for (unsigned int i = 0; i < legoCowBody->getMeshes().size(); i++) {
            legoCowBody->Draw(legoCowBody->getMeshes().at(i));
        }
    }
    glPopMatrix();
}

void Draw_LegoCowHead(bool isAlive) {
    glPushMatrix();
    glColor4f(0.913725490196078, 0.682352941176471f, 0.654901960784314f, 0.356862745098039f);
    if (isAlive) {
        for (unsigned int i = 0; i < legoCowHead->getMeshes().size(); i++) {
            legoCowHead->Draw(legoCowHead->getMeshes().at(i));
        }
    }
    glPopMatrix();
}

float tailRotationAngle {};
bool tailRotationRightWays {false};
void Draw_LegoCowTail(bool isAlive) {
    glPushMatrix();
    if (tailRotationAngle < 45.f && !tailRotationRightWays){
        tailRotationAngle += 0.5f;
    }
    if (tailRotationAngle >= 45.0f){
        tailRotationRightWays = true;
    }
    if (tailRotationAngle <= 45.f && tailRotationRightWays){
        tailRotationAngle -= 0.5f;
    }
    if (tailRotationAngle <= -45.f){
        tailRotationRightWays = false;
    }
    glColor4f(0.913725490196078, 0.682352941176471f, 0.654901960784314f, 0.356862745098039f);
    glRotatef(tailRotationAngle, 0.f,0.f,1.f);
    if (isAlive) {
        for (unsigned int i = 0; i < legoCowTail->getMeshes().size(); i++) {
            legoCowTail->Draw(legoCowTail->getMeshes().at(i));
        }
    }
    glPopMatrix();
}

void Draw_LegoCow (const GLfloat cowPosition[], bool isAlive){
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable (GL_COLOR_MATERIAL);

    glPushMatrix();

    //--draws point inside the body of the cow for collision detection-->
    glColor4f(1.0f,.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    glVertex3f(cowPosition[0],cowPosition[1],cowPosition[2]+1);
    glEnd();
    //<--draws point inside the body of the cow for collision detection--

    glTranslatef(cowPosition[0], cowPosition[1], cowPosition[2]);
    glScalef(0.3f,0.3f,0.3f);
    Draw_LegoCowBody(isAlive);
    Draw_LegoCowHead(isAlive);
    Draw_LegoCowTail(isAlive);

    glPopMatrix();

    glDisable(GL_COLOR_MATERIAL);
}



#endif //DRAW_LEGOCOW_HPP
