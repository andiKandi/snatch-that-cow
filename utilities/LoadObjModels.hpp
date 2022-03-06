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

#ifndef INIT_OBJMODELS_HPP
#define INIT_OBJMODELS_HPP

#include "../models/npc/Draw_LegoCow.hpp"

void LoadObjModels (void){
    ////--Scene inclusion-->
    //scenedarkobjects
    char resolved_path_for_scenedarkobjects[PATH_MAX];
    realpath("../../gdv-final/obj/scene/scenedarkobjects.obj", resolved_path_for_scenedarkobjects);
    scenedarkobjects->importModel(resolved_path_for_scenedarkobjects);
    //scenebrightobjects
    char resolved_path_for_scenebrightobjects[PATH_MAX];
    realpath("../../gdv-final/obj/scene/scenebrightobjects.obj", resolved_path_for_scenebrightobjects);
    scenebrightobjects->importModel(resolved_path_for_scenebrightobjects);
    //sceneblackobjects
    char resolved_path_for_sceneblackobjects[PATH_MAX];
    realpath("../../gdv-final/obj/scene/sceneblackobjects.obj", resolved_path_for_sceneblackobjects);
    sceneblackobjects->importModel(resolved_path_for_sceneblackobjects);
    //couch
    char resolved_path_for_couch[PATH_MAX];
    realpath("../../gdv-final/obj/scene/couch.obj", resolved_path_for_couch);
    couch->importModel(resolved_path_for_couch);
    //branches
    char resolved_path_for_branches[PATH_MAX];
    realpath("../../gdv-final/obj/scene/branches.obj", resolved_path_for_branches);
    branches->importModel(resolved_path_for_branches);
    //leaves
    char resolved_path_for_leaves[PATH_MAX];
    realpath("../../gdv-final/obj/scene/leaves.obj", resolved_path_for_leaves);
    leaves->importModel(resolved_path_for_leaves);
    ////<--Scene inclusion--

    ////--NPC inclusion-->
    //legoCowBody
    char resolved_path_for_legoCowBody[PATH_MAX];
    realpath("../../gdv-final/obj/npc/legoCowBody.obj", resolved_path_for_legoCowBody);
     legoCowBody->importModel(resolved_path_for_legoCowBody);
    //legoCowHead
    char resolved_path_for_legoCowHead[PATH_MAX];
    realpath("../../gdv-final/obj/npc/legoCowHead.obj", resolved_path_for_legoCowHead);
    legoCowHead->importModel(resolved_path_for_legoCowHead);
    //legoCowHead
    char resolved_path_for_legoCowTail[PATH_MAX];
    realpath("../../gdv-final/obj/npc/legoCowTail.obj", resolved_path_for_legoCowTail);
    legoCowTail->importModel(resolved_path_for_legoCowTail);
    ////<--NPC inclusion--

    ////--UFO inclusion-->
    // hullUp
    char resolved_path_for_ufoHullUp[PATH_MAX];
    realpath("../../gdv-final/obj/ufo/hullUp.obj", resolved_path_for_ufoHullUp);
    hullUp->importModel(resolved_path_for_ufoHullUp);
    // hullUp
    char resolved_path_for_ufoHullDown[PATH_MAX];
    realpath("../../gdv-final/obj/ufo/hullDown.obj", resolved_path_for_ufoHullDown);
    hullDown->importModel(resolved_path_for_ufoHullDown);
    // innerBody
    char resolved_path_for_ufoInnerBody[PATH_MAX];
    realpath("../../gdv-final/obj/ufo/innerBody.obj", resolved_path_for_ufoInnerBody);
    innerBody->importModel(resolved_path_for_ufoInnerBody);
    //stacksDown
    char resolved_path_for_ufoStacksDown[PATH_MAX];
    realpath("../../gdv-final/obj/ufo/stacksDown.obj", resolved_path_for_ufoStacksDown);
    stacksDown->importModel(resolved_path_for_ufoStacksDown);
    //stacksUp
    char resolved_path_for_ufoStacksUp[PATH_MAX];
    realpath("../../gdv-final/obj/ufo/stacksUp.obj", resolved_path_for_ufoStacksUp);
    stacksUp->importModel(resolved_path_for_ufoStacksUp);
    // engine
    char resolved_path_for_ufoEngine[PATH_MAX];
    realpath("../../gdv-final/obj/ufo/engine.obj", resolved_path_for_ufoEngine);
    engine->importModel(resolved_path_for_ufoEngine);
    ////<--UFO inclusion-
}
#endif //INIT_OBJMODELS_HPP
