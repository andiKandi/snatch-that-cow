# Snatch That Cow!
In this game you play a tiny alien that cruises around a bedroom in search of lego cows. 
The goal lies in abducting all of them by flying through them.

## Description of features
- Textures:
  - Floor, carpet, TV, 2 posters, photos, skybox.
- Light settings:
  - The position of the light source can be adjusted variably by the user.
- Vehicle animations
  - When stationary, the lower part of the UFO (engine) moves slowly in circles up and down.
    up and down. This up and down movement increases when the UFO is moving.
  - While hovering in the same position, the UFO wobbles slightly.
  - The rings of the UFO circle at any time in different directions around the
    the y-axis.
  - Depending on the direction of flight (forward, backward, sideways) the
    UFO into these.
- Sound/Music:
  - Collecting a cow activates a moo sound.
  - Game music is available through the menu and can be turned on and off.
  - When all cows have been collected, a victory melody sounds and the program ends.
    ended.
- Gameplay:
  - The goal is to collect all the cows by ramming them with the UFO.
    with the UFO.

## Controls
- Keyboard:
  - The UFO can be moved horizontally/diagonally using the w/a/s/d keys.
  - If the UFO is moved forward (w), a "boost" can additionally be activated by pressing the
    spacebar to activate a "boost" and the vehicle flies faster.
  - With the keys q/e the UFO can hover vertically up and down.
  - The arrow keys can be used to vary the position of the light source.
- Mouse:
  - The camera/view direction is subject to mouse control.
  - In addition, the mouse wheel can be used to zoom in/out.
  - The right mouse button opens a menu that contains information about the
    control as well as music settings (Music ON/OFF).
  - The music can be switched on/off and the game can be quit by clicking on "Quit".
    "Quit" to end the game.

## Installation
Because GitHub doesn't allow file sizes to be bigger than 100MB two files are packed and must be unpacked before running:
1. obj/blend/CompleteScene.7z
2. obj/scene/scenebrightobjects.7z

To run this project you need to install the following libraries:
- `sudo apt-get install libassimp-dev assimp-utils`
- `sudo apt-get install -y libsoil-dev`
- `sudo apt-get install freeglut3-dev`

## Credits
This project was created in cooperation with Stephan Harijan.
To compose the scene, the following external models were modified and incorporated:
- https://free3d.com/3d-model/low-poly-isometric-room-1-704614.html
- https://free3d.com/3d-model/shoes-89935.html
- https://free3d.com/3d-model/sport-cap-6044.html
- https://free3d.com/3d-model/isometric-room-362653.html
- https://free3d.com/3d-model/modular-ufo-190921.html
- https://free3d.com/3d-model/black-jack-drum-529078.html
- https://free3d.com/3d-model/nike-air-jordan-v1-488685.html
- https://free3d.com/3d-model/gaming-room-34242.html
- https://free3d.com/3d-model/dresser-old-65315.html

## Legal Info
The project is subject to the GNU GENERAL PUBLIC LICENSE version 3.