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
#ifndef DRAW_COMPLETESCENE_HPP
#define DRAW_COMPLETESCENE_HPP

Model* scene = new Model();
Model* couch = new Model();
Model* scenedarkobjects = new Model();
Model* scenebrightobjects = new Model();
Model* sceneblackobjects = new Model();
Model* branches = new Model();
Model* leaves = new Model();

void Draw_CompleteScene() {
    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

    glPushMatrix();
    glTranslatef(0.f, 0.f, 0.f);
    glScalef(10.f, 10.f, 10.f);

    glEnable (GL_COLOR_MATERIAL);
    glColor4f(0.92156862745098f,0.658823529411765f,0.243137254901961f,0.482352941176471f);
    for (unsigned int i = 0; i < couch->getMeshes().size(); i++) {///couch
        couch->Draw(couch->getMeshes().at(i));
    }
    glColor4f(0.141176470588235f,0.04705882352941f,0.0f,0.054901960784314f);
    for (unsigned int i = 0; i < scenedarkobjects->getMeshes().size(); i++) {///scenedarkobjects
        scenedarkobjects->Draw(scenedarkobjects->getMeshes().at(i));
    }
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    for (unsigned int i = 0; i < scenebrightobjects->getMeshes().size(); i++) {///scenebrightobjects
        scenebrightobjects->Draw(scenebrightobjects->getMeshes().at(i));
    }
    glColor4f(0.082352941176471f,0.133333333333333f,0.184313725490196f,0.070588235294118f);
    for (unsigned int i = 0; i < sceneblackobjects->getMeshes().size(); i++) {///sceneblackobjects
        sceneblackobjects->Draw(sceneblackobjects->getMeshes().at(i));
    }
    glColor4f(0.745098039215686f,0.611764705882353f,0.317647058823529f,0.294117647058823f);
    for (unsigned int i = 0; i < branches->getMeshes().size(); i++) {///branches
        branches->Draw(branches->getMeshes().at(i));
    }
    glColor4f(0.325490196078431f,0.611764705882353f,0.211764705882353f,0.23921568627451f);
    for (unsigned int i = 0; i < leaves->getMeshes().size(); i++) {///leaves
        leaves->Draw(leaves->getMeshes().at(i));
    }
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
}

#endif //DRAW_COMPLETESCENE_HPP
