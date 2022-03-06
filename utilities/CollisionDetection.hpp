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

#ifndef COLLISIONDETECTION_HPP
#define COLLISIONDETECTION_HPP


#include "../models/npc/Draw_LegoCow.hpp"
#include "../irrKlang/include/irrKlang.h"
using namespace irrklang;
ISoundEngine *collisionSoundEngine = createIrrKlangDevice();

void CollisionDetection (const GLfloat cowPosition[], bool& isAlive) {
    distanceUfoToCow = sqrt(
            ((xPositionUfo - (cowPosition[0])) * (xPositionUfo - (cowPosition[0])))
            + ((yPositionUfo - (cowPosition[1] )) * (yPositionUfo - (cowPosition[1])))
            + ((zPositionUfo - (cowPosition[2] )) * (zPositionUfo - (cowPosition[2]))));

    if (distanceUfoToCow <= ufoRadius + cowRadius){
        if(isAlive && !collisionSoundEngine->isCurrentlyPlaying("../../gdv-final/sound/cowmooing.mp3")) {
            collisionSoundEngine->play2D("../../gdv-final/sound/cowmooing.mp3");
        }
        isAlive = false;
        std::cout << "collision" << std::endl;

    }
}

#endif //COLLISIONDETECTION_HPP
