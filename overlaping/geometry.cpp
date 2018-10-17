#include "geometry.h"

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(float rectangleX,float rectangleY,float rectangleWidth, float rectangleHeight)
{
    this->rectangleY = rectangleY;
    this->rectangleX = rectangleX;
    this->rectangleWidth = rectangleWidth;
    this->rectangleHeight = rectangleHeight;
}

void Rectangle::setHeight(float rectangleHeight)
{
    this->rectangleHeight = rectangleHeight;
}

void Rectangle::setWidth(float rectangleWidth  )
{
    this->rectangleWidth = rectangleWidth;
}

void Rectangle::setX(float rectangleX )
{
    this->rectangleX = rectangleX;
}
void Rectangle::setY(float rectangleY )
{
    this->rectangleY = rectangleY;
}

float Rectangle::getHeight()
{
    return rectangleHeight;
}

float Rectangle::getWidth()
{
    return rectangleWidth;
}

float Rectangle::getX()
{
    return rectangleX;
}
float Rectangle::getY()
{
    return rectangleY;
}

Rectangle ConditionChecker::createOverlappedRectangle(Rectangle firstRectangle, Rectangle secondRectangle) {
        Rectangle upperRect;
        Rectangle lowerRect;
        Rectangle leftRect;
        Rectangle rightRect;

        int overlapX;
        int overlapY;
        int overlapWidth;
        int overlapHeight;

        if (firstRectangle.getX() <= secondRectangle.getX()) {
            leftRect = firstRectangle;
            rightRect = secondRectangle;
        } else {
            leftRect = secondRectangle;
            rightRect = firstRectangle;
        }

        if (firstRectangle.getY() <= secondRectangle.getY()) {
            upperRect = secondRectangle;
            lowerRect = firstRectangle;

        } else {
            upperRect = firstRectangle;
            lowerRect = secondRectangle;
        }

        if (leftRect.getX() + leftRect.getWidth() <= rightRect.getX()) {
            return Rectangle(0.0, 0.0, 0.0, 0.0);
        } else if (leftRect.getX() + leftRect.getWidth() >= rightRect.getX() + rightRect.getWidth())
            overlapWidth = rightRect.getWidth();
        else {
            overlapWidth = leftRect.getX() + leftRect.getWidth() - rightRect.getX();
        }


        if (lowerRect.getY() + lowerRect.getHeight() <= upperRect.getY()) {
            return Rectangle(0.0, 0.0, 0.0, 0.0);
        } else if (lowerRect.getY() + lowerRect.getHeight() >= upperRect.getY() + upperRect.getHeight()) {
            overlapHeight = lowerRect.getHeight();
        } else {
            overlapHeight = lowerRect.getY() + lowerRect.getHeight() - upperRect.getY();
        }

        overlapX = rightRect.getX();
        overlapY = upperRect.getY();

        return Rectangle(overlapX, overlapY, overlapWidth, overlapHeight);
    }

