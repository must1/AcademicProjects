class Rectangle
{
private:
    float rectangleX;
    float rectangleY;
    float rectangleWidth;
    float rectangleHeight;
public:
    Rectangle();
    Rectangle(float,float,float,float);
    void setX(float);
    void setY(float);
    void setWidth(float);
    void setHeight(float);
    float getX();
    float getY();
    float getWidth();
    float getHeight();
};

class ConditionChecker
{
public:
    Rectangle createOverlappedRectangle(Rectangle firstRectangle, Rectangle secondRectangle);
};
