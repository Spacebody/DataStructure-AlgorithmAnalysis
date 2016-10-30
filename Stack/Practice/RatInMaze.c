/*
 * Rat In Maze
 *
 * Implement in Stack
 * Use Matrix to represent the maze
 * If the block is blue, we make the number to be 0, otherwise to be 1
 * Entrance is (1,1), and result we need to fine is (14,15)
 * Search the direction from right in Countclockwise
 * 
 * By Spacebody
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef _RatInMaze_h
typedef struct Direction Dir;
typedef struct MapRecord Map;
#define MAX_STACK_SIZE 210
#define MAXROW 16
#define MAXCOL 17

#endif /*  RatInMaze.h  */

struct Direction
{
    int v;//vertical direction
    int h;//horizontal direction
};

struct MapRecord
{
    int row;
    int col;
    int dir;
};

int top;//top of the stack
Dir Move[4]= {{0,1},{1,0},{0,-1},{-1,0}}; //search from right in countclockwise
int Mark[MAXROW][MAXCOL];//mark the block which is ever been searched
int Maze[MAXROW][MAXCOL]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                          {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
                          {1,0,1,0,0,1,1,1,1,1,1,0,0,0,0,0,1},
                          {1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
                          {1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
                          {1,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,1},
                          {1,0,1,1,1,0,0,0,0,0,0,0,0,1,0,0,1},
                          {1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                          {1,0,1,1,0,0,0,0,1,0,1,0,1,0,1,1,1},
                          {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
                          {1,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,1},
                          {1,0,1,1,0,0,1,1,0,0,0,0,1,0,0,0,1},
                          {1,0,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1},
                          {1,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
                          {1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1},
                          {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};//Map size is 14*15, surrounding by number 1
Map stack[MAX_STACK_SIZE];//declaration of the stack

//declaration of the functions
void Push(Map pos); //push into the stack
Map Pop(void); //pop out of the stack
int IsEmpty(void); //exam whether it is empty
int Path(int x_start,int y_start,int x_end,int y_end); //search for the solution

int main(void)
{
    int x1,y1,x2,y2;//coordinates of beginning and ending
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    if(Path(x1,y1,x2,y2))
    {
        printf("Fine the solution successfully.\n");
    }
    else
    {
        printf("Error! The rat might be missing.\n");
    }
    return 0;
}


void Push(Map pos)
{
    if(top >= MAX_STACK_SIZE)
    {
        printf("Full Stack!\n");
        exit(0);
    }
    stack[top++] = pos;
}


Map Pop(void)
{
    if(top == -1)
    {
        printf("Empty Stack!\n");
        exit(0);
    }
    return stack[--top];
}


int IsEmpty(void)
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}


int Path(int x_start,int y_start,int x_end,int y_end)
{
    int i,col,row,next_row,next_col,dir;
    Map tmp;
    tmp.row = x_start;
    tmp.col = y_start;
    tmp.dir = -1;
    Push(tmp); //push the beginning into stack
    Mark[x_start][y_start] = 1;//also mark it
    while(!IsEmpty())//continue to search if the stack is not empty
    {
        tmp = Pop();//pop the record for the base to search
        row = tmp.row;
        col = tmp.col;
        dir = tmp.dir+1; //change the direction
        while(dir < 4)
        {
            next_row = row + Move[dir].v;
            next_col = col + Move[dir].h;
            if(!Maze[next_row][next_col] && !Mark[next_row][next_col])
            { //continue to search if the block is not marked
                tmp.row = row;
                tmp.col = col;
                tmp.dir = dir;
                Push(tmp); //push into the stack to record the way
                row = next_row;
                col = next_col;
                Mark[row][col] = 1;
                if(row == x_end && col == y_end)
                {//exam whether it is result we need
                    //print the solution
                    for(i = 0; i < top; i++)
                    {
                        printf("(%d,%d)->\t",stack[i].row,stack[i].col);
                        if((i+1)%5 == 0)
                        { //make the printing more readable
                            printf("\n");
                        }
                    }
                    printf("(%d,%d)\n",row,col); //print the result to check
                    return 1;
                }
                else
                {
                    dir = 0;
                }
            }
            else
            {
                dir++;
            }
        }
    }
    return 0;
}

