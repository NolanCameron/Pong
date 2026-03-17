#include "pong.h"
#include "math.h"

void scoreGame(Game *game, Side side){

    Ball *ball = &(game->ball);
    Screen *screen = &(game->screen);

    //Print who scored

    ball->x = screen->width/2;
    ball->y = screen->height/2;

    ball->xVel = ball->xVel/abs(ball->xVel);
    ball->yVel = ball->yVel/abs(ball->yVel);

    if(game->player_1.side == side){
        game->player_1.score += 1;
    }else{
        game->player_2.score += 1;
    }

}

void runGameTick(Game *game){

    Player *player_1 = &(game->player_1);
    Player *player_2 = &(game->player_2);

    Player* rightPlayer;
    Player* leftPlayer;

    if(player_1->side = RIGHT){
        rightPlayer = player_1;
        leftPlayer = player_2;
    }else{
        rightPlayer = player_2;
        leftPlayer = player_1;
    }


    Ball *ball = &(game->ball);

    Screen *screen = &(game->screen);

    //Get Player input
    int player_1Direction = game->getPlayer1Direction();
    int player_2Direction = game->getPlayer2Direction();


    if(player_1->paddle.y + player_1Direction > 0 && player_1->paddle.y + player_1Direction + player_1->paddle.length < screen->height){
        player_1->paddle.y += + player_1Direction;
    }

    if(player_2->paddle.y + player_2Direction > 0 && player_2->paddle.y + player_2Direction + player_2->paddle.length < screen->height){
        player_2->paddle.y += + player_2Direction;
    }

    //Check ball score
    if(ball->x + ball->xVel > screen->width){

        scoreGame(game, RIGHT);
        return;
    }

    if(ball->x + ball->xVel < 0){

        scoreGame(game, LEFT);
        return;
    }

    //Check player paddle x
    if(ball->x < rightPlayer->paddle.x && ball->x + ball->xVel >= rightPlayer->paddle.x) //Check x collosion
        if(ball->y + ball->yVel <= rightPlayer->paddle.y && ball->y + ball->yVel >= rightPlayer->paddle.y + rightPlayer->paddle.length){//Check y collosion
            ball->xVel *= -1;
            ball->xVel += ball->xVel/abs(ball->xVel);
            ball->yVel += ball->yVel/abs(ball->yVel);
        }

    if(ball->x > leftPlayer->paddle.x && ball->x + ball->xVel <= leftPlayer->paddle.x) //Check x collosion
        if(ball->y + ball->yVel >= leftPlayer->paddle.y && ball->y + ball->yVel <= leftPlayer->paddle.y + leftPlayer->paddle.length){//Check y collosion
            ball->xVel *= -1;
            ball->xVel += ball->xVel/abs(ball->xVel);
            ball->yVel += ball->yVel/abs(ball->yVel);
        }

    
    //Check top bottom collosion
    if(ball->y + ball->yVel < 0 || ball->y + ball->yVel > screen->height){
        ball->yVel *= -1;
    }

    ball->x += ball->xVel;
    ball->y += ball->yVel;
    

}