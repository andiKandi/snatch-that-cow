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

#ifndef WINNINGCONDITION_HPP
#define WINNINGCONDITION_HPP

#include "../irrKlang/include/irrKlang.h"
#include <chrono>
#include <thread>
using namespace irrklang;
ISoundEngine *winningSoundEngine = createIrrKlangDevice();

void WinningCondition(){
    if( !(  cowOneIsAlive || cowTwoIsAlive ||
            cowThreeIsAlive || cowFourIsAlive ||
            cowFiveIsAlive || cowSixIsAlive ||
            cowSevenIsAlive || cowEightIsAlive ||
            cowNineIsAlive || cowTenIsAlive)){
        if(!collisionSoundEngine->isCurrentlyPlaying("../../gdv-final/sound/cowmooing.mp3")) {
            winningSoundEngine->play2D("../../gdv-final/sound/drumroll.mp3");
            std::this_thread::sleep_for(std::chrono::milliseconds(11000));
            exit(0);
        }
    }
}

#endif //WINNINGCONDITION_HPP
