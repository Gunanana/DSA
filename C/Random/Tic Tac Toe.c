#include<stdlib.h>
#include<stdio.h>

//declare the matrix
char matrix[3][3];

//initialise the matrix
void create_matrix(){
    int i,j;
    char matrix[3][3];
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            matrix[i][j]=" ";
            }
    }
}

//check for winners
char check(){
    //check rows
    for(int i=0;i<3;i++){
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2])
        return matrix[i][0];
    }
    //check columns
    for(int i=0;i<3;i++){
        if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
            return matrix[0][i];
    }
    //check diagonals
    for(int i=0;i<3;i++){
        if(matrix[1][1]==matrix[2][2] && matrix[1][1]==matrix[3][3])
            return matrix[0][0];
    }
    //return space if no winner yet
    return ' ';

}

//get computer's move
void c_move(){
    int i,j;
    //check for empty space
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matrix[i][j]==' ') break;
        }
        if(matrix[i][j]==' ') break;
    }
    //matrix is full
    if(i*j==9){
        printf("draw!!\n");
        exit(0);
    }
    //enter move into matrix
    else matrix[i][j]='O';
}

//get player's move
void p_move(){
    int x,y;
    printf("Enter the coordinates where u wanna place\n");
    scanf("%d %d",&x,&y);
    x--,y--;
    if(matrix[x][y]!=" "){
        printf("Ivalid Position. PLease enter again\n");
        p_move();
    }
    else matrix[x][y]=='X';
}

//throw matrix on the terminal after each move
void display_matrix(){
    int i;
    for (i=0;i<3;i++){
        printf("%c | %c | %c",matrix[i][0],matrix[i][1],matrix[i][2]);
        if(i!=2){
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

void main(){
    char status=' ';
    printf("Welcome to Tic Tac Toe!!\n");
    printf("You'll be playing against a computer!\n");
    create_matrix();
    while(1){
            p_move();
            status=check();
            if (status==' ') break;

            

    }





}

