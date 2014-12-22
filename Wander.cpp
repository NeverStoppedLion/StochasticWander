#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "Wander.h"

using namespace std;
void Wander::initRoom() {
    int i, j;
    room = (int *)malloc(lengthX * lengthY * sizeof(int));
    for(i = 0; i < lengthX; i++){
        for(j = 0; j < lengthY; j++)
            *(room + i * lengthY + j) = 0;
    }
    srand((unsigned) time(NULL));
}

Wander::~Wander() {
    free(room);
}

int Wander::getRadomDirection() {
    return rand() % NUMBER_DIRECTION;
}
Wander::Wander(int lengthx, int lengthy, int initPx, int initPy){
    lengthX = lengthx;
    lengthY = lengthy;
    px = initPx;
    py = initPy;
    initRoom();
    totalSteps = 1;
    *(room + px * lengthY + py) = *(room + px * lengthY + py) + 1;
}

Wander::Wander(int lengthx, int lengthy) {
    lengthX = lengthx;
    lengthY = lengthy;
    px = lengthX / 2;
    py = lengthY / 2;
    initRoom();
    totalSteps = 1;
    *(room + px * lengthY + py) = *(room + px * lengthY + py) + 1;
}

Wander::Wander() {
    lengthX = 20;
    lengthY = 20;
    px = 10;
    py = 10;
    initRoom();
    totalSteps = 1;
    *(room + px * lengthY + py) = *(room + px * lengthY + py) + 1;
}

void Wander::showInfo() {
    cout << "/*------*/" << endl;
    cout << "The total steps is: " << totalSteps << endl;
    cout << "Every brick: " << endl;
    for(int i = 0; i < lengthX; i++){
        for(int j = 0; j < lengthY; j++){
            cout << *(room + i * lengthY + j) << "\t" ;
        }
        cout << endl;
    }
}

void Wander::pxIncrease() {
    px++;
    if(px == lengthX)
        px--;
}
void Wander::pxDecrease() {
    px--;
    if(px == -1)
        px++;
}
void Wander::pyIncrease() {
    py++;
    if(py == lengthY)
        py--;
}
void Wander::pyDecrease() {
    py--;
    if(py == -1)
        py++;
}
void Wander::oneStep() {
    int direction = getRadomDirection();
    switch(direction){
    case 0 :
        pyIncrease();
        break;
    case 1:
        pxIncrease();
        pyIncrease();
        break;
    case 2:
        pxIncrease();
        break;
    case 3:
        pxIncrease();
        pyDecrease();
        break;
    case 4:
        pyDecrease();
        break;
    case 5:
        pxDecrease();
        pyDecrease();
        break;
    case 6:
        pxDecrease();
        break;
    case 7:
        pxDecrease();
        pyIncrease();
        break;
    }
    totalSteps++;
    *(room + px * lengthY + py) = *(room + px * lengthY + py) + 1;
}
void Wander::multiSteps(int number) {
    for(int i = 0; i < number; i++)
        oneStep();
}
bool Wander::isFull(){
    bool flag = true;
    for(int i = 0; i < lengthX; i++){
        for(int j = 0; j < lengthY; j++)
            if( *(room + i * lengthY + j) == 0){
                flag = false;
                return flag;
            }
    }
    return flag;
}
void Wander::stopWhenFull(){
    while(!isFull()) {
        oneStep();
    }
}
