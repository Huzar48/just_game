#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

/////////RESOLUTION ONLY INT//////////////
#define RES_X 1920
#define RES_Y 1080

////////degress to radians//////////
#define DEGTORAD 0.017453f

///////Control Settings//////////
#define PLR_UP W
#define PLR_DOW S
#define PLR_RR D
#define PLR_RL A
#define PLR_SHOOT Space //Space is only correct format of typing space or SPACE won't work
#define EXIT Escape //Escape is only correct format of typing escape or escape won't work

//////paths to textures////////
#define BACKGROUND "background.png"
#define PLAYER_TEXTURE "./player.png"
#define ENEMY_TEXTURE "enemy.png"
#define METEOR_TEXTURE "meteor.png"
#define BULLET_TEXTURE "bullet.png"
#define PROJECT_OWNER "P.HUZAR"

////////Texture scales////////
#define player_scale 0.25f
#define bullet_scale 0.5f

#endif