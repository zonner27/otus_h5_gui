#ifndef GRAPHICELEMENTS213208092019_H
#define GRAPHICELEMENTS213208092019_H

#include <iostream>

class GraphicElements
{
public:
    virtual void create() = 0;
    virtual void remove() = 0;
};

class Circle : public GraphicElements
{
public:
    void create() override
    {
        std::cout << "Create circle" << std::endl;
    }

    void remove() override
    {
        std::cout << "Remove circle" << std::endl;
    }
};

class CircleWithFrame : public GraphicElements
{
    GraphicElements *circle;

public:
    void create() override
    {
        circle->create();
        std::cout << "with frame" << std::endl;
    }

    void remove() override
    {
        circle->remove();
        std::cout << "with frame" << std::endl;
    }

    CircleWithFrame(GraphicElements *circle_) : circle(circle_) {};
};

class Square : public GraphicElements
{
public:
    void create() override
    {
        std::cout << "Create square " << std::endl;
    }

    void remove() override
    {
        std::cout << "Remove square" << std::endl;
    }
};

#endif //GRAPHICELEMENTS213208092019_H
