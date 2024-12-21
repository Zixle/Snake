

#include <stdio.h>
#define NORTH 3
#define SOUTH 1
#define EAST 0 //turtle starts at 0
#define WEST 2


void command1 ( int* penstat){//pen up

    *penstat=0;
}
void command2( int* row, int* column, int* penstat, char board[25][25]){//pen down
    *penstat=1;
    board [*row][*column]='*';// marks current position on board
    
}
void command3(int* direction){// turn right
    if (*direction < 3){
        (*direction)++;
    }
    else if (*direction ==3){
        *direction =0;//north
    }
    
}
void command4(int* direction){//turn left
    if (*direction >0){
        (*direction)--;
    }
    else if (*direction ==0){//east
        (*direction)=3;
    }
}
void command5(int *x, int* y, int* penstat, char board[25][25], int* direction ){// move foward x spaces
    int i=0;
    int spaces;
    scanf("%d", &spaces);

    if (*penstat== 1){   //pen down
        
        if (*direction== 0){ //east (adding to x)
            for (i=0;i<=spaces; i++){
               
                if((*x+i) <0|| (*x+i) >=25){ //will stop where ever it is if it goes outside of board
                    
                    break;
                }
               
                board[*y][*x+i] = '*';
               
            }
            *x+=spaces;//updates x's position
            if(*x<0){ //x cannot be negative
                
                    (*x)=0;
                
            }
            if(*x>=25){ //x cannot be over 25
                
                    (*x)=24;
                
            }
            
        }
        else if (*direction == 2){//west
            for (i=0; i<=spaces; i++){
                if((*x-i)<0|| (*x-i) >=25){//will stop where ever it is if it goes outside of board
                    
                    break;
                }
                board[*y][*x-i] = '*';
            }
            *x-=spaces;//updates x's position
            if(*x<0){ //x cannot be negative
                (*x)=0;
            }
            if(*x>=25){ //x cannot be over 25
                (*x)=24;
            }
            
        }
            
        
        
        else if(*direction ==3 ){//north
            for (i=0; i<=spaces; i++){
                if((*y-i)<0|| (*y-i) >=25){//will stop where ever it is if it goes outside of board
                    break;
                }
                board[*y-i][*x] = '*';
            }
            *y-=spaces;//update y position
            if(*y<0){ //y cannot be negative
                (*y)=0;
            }
            if (*y>=25){// y can't be over 25
                (*y)=24;
            }
            
        }
        else if(*direction ==1 ){//south
            for (i=0; i<=spaces; i++){
                if((*y+i)<0|| (*y+i) >=25){   //will stop where ever it is if it goes outside of board
                    
                    break;
                }
                board[*y+i][*x] = '*';
            }
            *y+=spaces;//updates y
            if(*y<0){ //y cannot be negative
                (*y)=0;
            }
            if (*y>=25){// y can't be over 25
                (*y)=24;
            }
            
            
        }
    }//end of pen down

    else if (*penstat== 0){     //pen up
        
        if (*direction== 0){ //east
            for (i=1; i<=spaces; i++){
                if(*x<0|| *x >=25){//will stop where ever it is if it goes outside of board
                    
                    
                    break;
                }
                (*x)++; //updates x position
               
            }
            if(*x<0){ //x cannot be negative
                (*x)=0;
            }
            if(*x>=25){
                *x=24;
            }
        }
        
        else if (*direction == 2){  //west
            for (i=1; i<=spaces; i++){
                if(*x<0|| *x >=25){//will stop where ever it is if it goes outside of board
                    
                    
                    break;
                }
                (*x)--; //updates x position
               
            }
           
            if(*x<0){ //x cannot be negative
                (*x)=0;
            }
            
            
            if(*x >=25){
               *x=24;
           }
            
           
        }
        
        
        else if(*direction ==3 ){//north
            for (i=1; i<=spaces; i++){
                if(*y<0|| *y >=25){//will stop where ever it is if it goes outside of board
                    
                    
                    break;
                }
                (*y)--; //updates y position
            }
            if(*y<0){ //y cannot be negative
                *y=0;
                
            }
            if(*y>=25){ //x cannot be negative
                *y=24;
            }
            
        }
        else if(*direction ==1 ){//south
            for (i=1; i<=spaces; i++){
                if(*y<0|| *y >=25){//will stop where ever it is if it goes outside of board
                    
                    
                    break;
                }
                (*y)++; //updates y position
            }
            if(*y<0){ //y cannot be negative
                *y=0;
                
            }
            if(*y>=25){ //y cannot be negative
                *y=24;
            }
        }
        
    }
}  //end of function
void command6(char board[25][25]){
    //Board Format//
    int i=0;
    int num=1;
    printf("%24d %19d\n   ", num, num+1);
    num = 0;
    for (i = 0; i < 2; i++){//top numbers
        while (num < 10) {
            printf("%-2d", num);
            num++;
        }
        num = 0;
        while (num < 5) {
            printf("%-2d", num);//10 to 25
            num++;
        }
    }
   

    int f=0;
   
    printf("\n  +-------------------------------------------------+\n");
    
    for (int k=0;k<25;k++){
        for (int g=0;g<25;g++){
            if (g==0 && f>=10){
                printf("%d|", f);
                
            }
            if (g==0 && f<10){
                printf("%2d|", f);
            }
            
            
            
            if (g== 24) {
                printf("%c",board[k][g]); //array content
                printf("|%d", f);
                printf("\n");
                continue;
            }
            
            printf("%-2c",board[k][g]); //array content
            
            
            
        }
        f++;
    }
    
    printf("  +-------------------------------------------------+\n   ");
    num = 0;
    for (i = 0; i < 2; i++){//bottom numbers
        while (num < 10) {
            printf("%-2d", num);
            num++;
        }
        num = 0;
        while (num < 5) {
            printf("%-2d", num);
            num++;
        }
    }
    num = 1;
    printf("\n%24d %19d\n   ", num, num+1);
}
int main(void) {
    char board[25][25];
    printf("EGRE245 Proj. #6 - Ziona Tucker\n");
    printf(" 0 = Pen Up 1 = Pen Down 3 = Turn Right 4 = Turn Left 5 = Move Foward x Spaces 6 = Print Board\n");
    
    for (int k=0;k<25;k++){//storing space array
        for (int g=0;g<25;g++){
            board[k][g]=' ';
        }
    }
    // start
    
    int row=0;//y
    int column=0;//x
    int dir= 0;
    int command=0;
    int penstate=0;//pen state, 0 = pen up, 1= pen down
    
    while (command != 9){
        scanf("%1d", &command);
     
                if (command == 1){// pen up
                    command1(&penstate);
                   
                }
                else if (command== 2){// pen down
                    command2(&row, &column, &penstate, board);
                   
                   
                }
                else if (command==3){//right
                    command3(&dir);
                  
                }
                else if (command== 4){//legt
                    command4(&dir);
                  
                }
                else if (command== 5){
                    command5(&column, &row, &penstate, board, &dir);
                   
                }
                else if (command== 6){//print board
                    command6(board);
                    
                }
            
                else if (command ==0 || command > 9){//invalid command.
                    return 1;
                }
        }
       
    
    
    return 0;

    }




