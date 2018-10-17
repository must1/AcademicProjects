#include <iostream>
#include "geometry.h"

using namespace std;

int main()
{
    cout << "Input data. X/Y/WIDTH/HEIGHT" << endl;

    float rectangleX;
    float rectangleY;
    float rectangleWidth;
    float rectangleHeight;

    cin >> rectangleX >> rectangleY >> rectangleWidth >> rectangleHeight;

    Rectangle r1;
    r1.setHeight(rectangleHeight);
    r1.setWidth(rectangleWidth);
    r1.setX(rectangleX);
    r1.setY(rectangleY);

    cout << "Input data. X/Y/WIDTH/HEIGHT" << endl;

    cin >> rectangleX >> rectangleY >> rectangleWidth >> rectangleHeight;

    Rectangle r2;
    r2.setHeight(rectangleHeight);
    r2.setWidth(rectangleWidth);
    r2.setX(rectangleX);
    r2.setY(rectangleY);

    ConditionChecker cond;

    Rectangle r3 = cond.createOverlappedRectangle(r1,r2);

    cout << r3.getX() <<" " << r3.getY() <<" " <<  r3.getWidth() <<" " << r3.getHeight();

    return 0;
}
