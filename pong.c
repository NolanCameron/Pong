#include "pong.h"

void scoreGame(Game *game){

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
        if(player_1->side == RIGHT)
            player_2->score++;
        if(player_2->side == RIGHT)
            player_1->score++;

        scoreGame(game);
        return;
    }

    if(ball->x + ball->xVel < 0){
        if(player_1->side == LEFT)
            player_2->score++;
        if(player_2->side == LEFT)
            player_1->score++;

        scoreGame(game);
        return;
    }

    //Check player paddle x
    if(ball->x < rightPlayer->paddle.x && ball->x + ball->xVel >= rightPlayer->paddle.x) //Check x collosion
        if(ball->y + ball->yVel <= rightPlayer->paddle.y && ball->y + ball->yVel >= rightPlayer->paddle.y + rightPlayer->paddle.length){//Check y collosion
            ball->xVel *= -1;
            ball->yVel *= -1;
        }

    if(ball->x < rightPlayer->paddle.x && ball->x + ball->xVel >= rightPlayer->paddle.x) //Check x collosion
        if(ball->y + ball->yVel <= rightPlayer->paddle.y && ball->y + ball->yVel >= rightPlayer->paddle.y + rightPlayer->paddle.length){//Check y collosion
            ball->xVel *= -1;
            ball->yVel *= -1;
        }
    

}