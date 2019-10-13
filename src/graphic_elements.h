#ifndef GRAPHICELEMENTS213208092019_H
#define GRAPHICELEMENTS213208092019_H

#include <iostream>

class GraphicElements {

public:
    virtual void draw() = 0;
    virtual void remove() = 0;
    virtual ~GraphicElements() {}
};

class Circle : public GraphicElements {

public:
    void draw() override {
        std::cout << "Create circle" << std::endl;
    }

    void remove() override {
        std::cout << "Remove circle" << std::endl;
    }
    ~Circle() {}
};

class CircleWithFrame : public GraphicElements {

    GraphicElements *circle;
public:
    void draw() override {
        circle->draw();
        std::cout << "with frame" << std::endl;
    }

    void remove() override {
        circle->remove();
        std::cout << "with frame" << std::endl;
    }

    CircleWithFrame(GraphicElements *circle_) : circle(circle_) {};
    ~CircleWithFrame() {}
};

class Square : public GraphicElements {

public:
    void draw() override {
        std::cout << "Create square " << std::endl;
    }

    void remove() override {
        std::cout << "Remove square" << std::endl;
    }
    ~Square() {}
};

#endif //GRAPHICELEMENTS213208092019_H
