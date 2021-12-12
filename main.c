#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function Declarations
void draw(void);
void draw_splash_screen(void);
void draw_border(void);
void fruit_generate(void);
void queue_update(int x, int y);
//Declarations of base varuables
const int board_height = 20;
const int board_width = 30;
bool gameover = false;
int score = 0;
int fruit_x;
int fruit_y;
int dir;
const int MAX_LENGTH = 10;
int board[board_width][board_height];
// Create a queue to store the positions of the snake
struct position{
    int x_pos;
    int y_pos;
};
struct position pos_queue[MAX_LENGTH];

int main(void)
{
    printf("Welcome to snek\n");
    printf("Press x to exit\n");
    draw();
}

void queue_update(int x, int y)
{
    for (int i = MAX_LENGTH-1; i>0; i++)
    {
        pos_queue[i].x_pos = pos_queue[i-1].x_pos;
        pos_queue[i].y_pos = pos_queue[i-1].y_pos;
    }
    pos_queue[0].x_pos = x;
    pos_queue[0].y_pos = y;
} 

void setup(void)
{
    pos_queue[0].x_pos = rand()%board_width-2;
    pos_queue[0].y_pos = rand()%board_height-2; 
    fruit_generate(); 
    board[fruit_x][fruit_y] = 50;
} 

void draw(void)
{
    for (int y = 0; y < board_height; y++)
    {
        for (int x = 0; x < board_width; x++)
        {
            if (board[x][y] == 50)
            {                    
                printf("X");     
            }
            for (int a = 0; a < MAX_LENGTH; a++)
            {
                if (pos_queue[a].x_pos == x || pos_queue[a].y_pos == y)
                {
                    printf("0");
                }
            }
            if (y == 0 || y == board_height-1 || x == 0 || x == board_width-1)
            {
                printf("#");
            }else {
                printf(" ");
            }
        }
        printf("\n");
    }


}

void draw_border(void)
{
    for (int i = 0; i < board_height; i++)
    {
        for (int j = 0; j < board_width; j++)
        {
            if (i == 0 || i == board_height-1 || j == 0 || j == board_width-1)
            {
                printf("#");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

void fruit_generate(void)
{
    fruit_y = rand() % board_height-2;
    fruit_x = rand() % board_width-2;
}

void input(void)
{
    char direction[2];
    direction[1] = 0;
    scanf("%c", direction);
    switch (direction[0])
    {
        case 'a':
            dir = 4;
            break;
        case 'w':
            dir = 1;
            break;
        case 's':
            dir = 3;
            break;
        case 'd':
            dir = 2;
            break;
    }
}
