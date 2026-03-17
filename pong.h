
//(0,0) is the top left of the screen
typedef struct{
    int height;
    int width;
}Screen;

typedef enum{
    LEFT, RIGHT
}Side;

typedef struct{
    int x, y;
    int xVel, yVel;
}Ball;

typedef struct{
    int length;
    int x, y;
}Paddle;

typedef struct{
    int score;
    Paddle paddle;
    Side side;
}Player;

typedef struct{
    Screen screen;
    Ball ball;
    Player player_1;
    Player player_2;
    int (*getPlayer1Direction)();//Returns the change in player paddle
    int (*getPlayer2Direction)();//Returns the change in player paddle
}Game;

void runGameTick(Game *);