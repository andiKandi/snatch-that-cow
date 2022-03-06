cmake_minimum_required(VERSION 3.17)
project(snatchThatCow)

set(CMAKE_CXX_STANDARD 14)

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/irrKlang/bin/libIrrKlang.so" DESTINATION .)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/irrKlang/bin/ikpMP3.so" DESTINATION .)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/irrKlang/bin/ikpFlac.so" DESTINATION .)
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/sound" DESTINATION .)

include_directories(irrKlang/include)
link_directories(irrKlang/bin)

add_executable(snatchThatCow
        main.cpp
        skybox/skybox.cpp skybox/skybox.h
        utilities/Keyboard.hpp
        utilities/MouseMovement.hpp
        assimp/Mesh.cpp
        assimp/Model.cpp
        assimp/assimpLogger.h
        utilities/Light.hpp
        models/scene/Draw_CompleteScene.hpp
        models/ufo/Draw_Engine.hpp
        models/ufo/Draw_HullDown.hpp
        models/ufo/Draw_HullUp.hpp
        models/ufo/Draw_InnerBody.hpp
        models/ufo/Draw_HullDown.hpp
        models/ufo/Draw_StacksUp.hpp
        models/ufo/Draw_Ufo.hpp
        models/ufo/Draw_StacksDown.hpp
        utilities/LoadObjModels.hpp
        utilities/Init_WindowSettings.hpp
        utilities/Init_RenderingSettings.hpp
        utilities/Reshape.hpp
        utilities/RenderScene.hpp
        utilities/CollisionDetection.hpp
        models/npc/Draw_LegoCow.hpp
        utilities/MainMenu.hpp
        utilities/Draw_Textures.hpp
        utilities/LoadTextures.hpp
        utilities/WinningCondition.hpp)


target_link_libraries (snatchThatCow -lglut -lGL -lGLU -lSOIL -lassimp -lIrrKlang -lpthread )