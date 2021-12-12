#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>

void draw(void);
void start_setup(void);
void input(void);
void update_board(void);

#define MAX_LENGTH 10
static int tickrate = 15;
#define width 40 
#define height 20

int board[height][width];
int fruit_x;
int fruit_y;
bool gameover = false;
int x_pos;
int y_pos;
int dir = 1;
int score = 0;

struct positions
{
    int x_pos;
    int y_pos;
};

struct positions pos_queue[MAX_LENGTH];


int main (void)
{
    start_setup();
   // while (!gameover)
    //{
       // draw();
       // printf("Welcome to Snek\n");
       // printf("To exit simply press: x\n");;
       // printf("Score: %i", score);
       // input();
       // update_board();
      //  sleep(0.5);
    //}
    //
    initscr();
    noecho();
    curs_set(false);
    mvprintw(fruit_x, fruit_y, "X");
    mvprintw(0,0,"A");
    sleep(1);
    endwin();
}

void start_setup(void)
{
    fruit_x = rand()%width-2;
    fruit_y = rand()%height-2;
    x_pos = rand()%width;
    y_pos = rand()%height;
}

void draw(void)
{
    system("clear");
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y <width; y++)
        {
            if (board[x][y]==1)
            {
                printf("0");
            }
            else if (board[x][y] == 2){
                printf("X");
            }
            else 
            {
                printf("░");
            }
        }
        printf("\n");
    }
}

void input(void)
{
    char in[2];
    in[1] = 0;
    scanf("%c", in[0]);
    switch (in[0])
    {
        case 'w':
            dir = 1;
            break;
        case 'a':
            dir = 4;
            break;
        case 's':
            dir = 3;
            break;
        case 'd':
            dir = 2;
            break;
        case 'x':
            gameover = true;
            break;
    }
}

void update_board(void)
{
    switch (dir)
    {
        case 1:
            y_pos++;
        case 2:
            x_pos++;
        case 3:
            y_pos--;
        case 4:
            x_pos--;
    }         

    if (x_pos > width || x_pos < 0 || y_pos > height || y_pos < 0 )
    {
        gameover = true;
    }
    for (int a = MAX_LENGTH; a >0; a--)
    {
        pos_queue[a].x_pos = pos_queue[a-1].x_pos;
        pos_queue[a].y_pos = pos_queue[a-1].y_pos;
    }
    pos_queue[0].x_pos = x_pos;
    pos_queue[0].y_pos = y_pos;
    for (int x = 0; x < width; x++)
    {
        for (int y =0 ; y< height; y++)
        {
            for (int a =0 ; a < MAX_LENGTH; a++)
            {
                if (pos_queue[a].x_pos == x && pos_queue[a].y_pos == y)
                {
                    board[x][y] = 1;
                }
            }
            if (fruit_x == x && fruit_y == y)
            {
                board[x][y] = 2;
            }
        }
    }
}

