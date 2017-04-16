#include <iostream>
#include <cstdlib>
#define SIDE 8
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4

int length = 1;
int x[SIDE] = {0};
int y[SIDE] = {0};
int foodStatus = -1;
        

void food(int Ax, int Ay){ // if shake ate food
    if ((Ax == -1) && (Ay == -1)){
        foodStatus = -1;
    } else if ((x[0] == Ax) && (y[0] == Ay)){
        foodStatus = 1;
    } else 
        foodStatus = 0;
}
        
void down(int *Ax, int *Ay){
    if (foodStatus == 1){
        x[length] = x[length - 1] % SIDE;
        y[length] = y[length - 1] % SIDE;
    }
    for(int i = length - 1; i > 0; i--){
        x[i] = x[i - 1] % SIDE;
        y[i] = y[i - 1] % SIDE;
    }
    x[0] = (x[0] + 1) % SIDE;
    if (foodStatus == 1){
        length++;
        foodStatus = -1;
        *Ax = -1;
        *Ay = -1;
    }
}

void up(int *Ax, int *Ay){
    if (foodStatus == 1){
        x[length] = x[length - 1] % SIDE;
        y[length] = y[length - 1] % SIDE;
    }
    for(int i = length - 1; i > 0; i--){
        x[i] = x[i - 1] % SIDE;
        y[i] = y[i - 1] % SIDE;
    }
    x[0] = x[0] - 1;
    if (x[0] < 0)
        x[0] = x[0] + SIDE;
    if (foodStatus == 1){
        length++;
        foodStatus = -1;
        *Ax = -1;
        *Ay = -1;
    }
}

void right(int *Ax, int *Ay){
    if (foodStatus == 1){
        x[length] = x[length - 1] % SIDE;
        y[length] = y[length - 1] % SIDE;
    }
    for(int i = length - 1; i > 0; i--){
        x[i] = x[i - 1] % SIDE;
        y[i] = y[i - 1] % SIDE;
    }
    y[0] = (y[0] + 1) % SIDE;
    if (foodStatus == 1){
        length++;
        foodStatus = -1;
        *Ax = -1;
        *Ay = -1;
    }
}

void left(int *Ax, int *Ay){
    if (foodStatus == 1){
        x[length] = x[length - 1] % SIDE;
        y[length] = y[length - 1] % SIDE;
    }        
    for(int i = length - 1; i > 0; i--){
        x[i] = x[i - 1] % SIDE;
        y[i] = y[i - 1] % SIDE;
    }
    y[0] = y[0] - 1;
    if (y[0] < 0)
        y[0] = y[0] + SIDE;
    if (foodStatus == 1){
        length++;
        foodStatus = -1;
        *Ax = -1;
        *Ay = -1;
    }
}

void snakeDump(int Ax, int Ay){
    int arr[SIDE][SIDE] = {0};
    if ((Ax != -1) && (Ay != -1)){
        arr[Ax][Ay] = 7;
    }
    for (int i = 0; i < length; i++){
        arr[x[i]][y[i]] = 1;
    }
    arr[x[0]][y[0]] = 2;
    for (int i = 0; i < SIDE; i++){
        for (int j = 0; j < SIDE; j++){
            std::cout <<arr[i][j] << " ";//switch the diod
        }
        std::cout << std::endl;
    }
}

void putFood(int * rx, int * ry){
    int Ax, Ay;
    int c = 0;
    bool smthWentWrong = false;
    if (foodStatus == -1){
        while (c != 1){
            smthWentWrong = false;
            Ax = rand() % SIDE;
            Ay = rand() % SIDE;
            for(int i = 0; i < length; i++){
                if ((x[i] == Ax) && (y[i] == Ay)){
                    smthWentWrong = true;
                }
            }
            if (!smthWentWrong){
                c = 1;
            }
        }
        *rx = Ax;
        *ry = Ay;
    }
}

int checkHead(){
    int c = 0;
    bool smthWentWrong = false;
    smthWentWrong = false;
    for(int i = 1; i < length; i++){
        if ((x[i] == x[0]) && (y[i] == y[0]) && (foodStatus != 1) && (length > 2)){
            smthWentWrong = true;
        }
    }
    if (smthWentWrong){
        c = 5;
    }
    return c;
}
        

//end = 5

void mySnake(){
    int c = 0;
    int Bx = -1, By = -1;
    snakeDump(Bx, By);
    while (c != 5){ 
        std::cin.clear();
        std::cin >> c; // read the button information
        switch(c){
            case RIGHT:
                right(&Bx, &By);
                food(Bx, By);
                break;
            case LEFT:
                left(&Bx, &By);
                food(Bx, By);
                break;
            case DOWN:
                down(&Bx, &By);
                food(Bx, By);
                break;
            case UP:
                up(&Bx, &By);
                food(Bx, By);
                break;
            case 5:
                break;
            default:
                break;
        }
        snakeDump(Bx, By);
        putFood(&Bx, &By);
        if (checkHead() == 5)
            c = 5;
    }
}

int main(){
    mySnake();
    return 0;
}
