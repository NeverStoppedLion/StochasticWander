#ifndef _WANDER_
#define _WANDER_
class Wander {
public:
    Wander(int lengthx, int lengthy, int initPx, int initPy);
    Wander(int lengthx, int lengthy);
    Wander();
    ~Wander();
    void multiSteps(int number);
    void stopWhenFull();
    void showInfo();
private:
    static const int NUMBER_DIRECTION = 8;
    int *room, lengthX, lengthY;
    int px, py;
    int totalSteps;
    void initRoom();
    int getRadomDirection();
    void pxIncrease();
    void pyIncrease();
    void pxDecrease();
    void pyDecrease();
    void oneStep();
    bool isFull();
};
#endif // _WANDER_
