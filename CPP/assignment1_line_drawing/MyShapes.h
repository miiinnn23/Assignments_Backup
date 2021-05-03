#ifndef __SHAPES_H__
#define __SHAPES_H__
#include "BaseShape.h"

class Line : public Shape {
private:
    int x2, y2;
public:
    Line(int x1, int y1, int x2, int y2) : Shape(x1, y1), x2(x2), y2(y2) {}
    int f(double x) {
        double y = (x - x2) * (y2 - p.getY()) / (x2 - p.getX()) + y2;
        return Round(y);
    }
    int g(double y) {
        double x = (y - y2) * (x2 - p.getX()) / (y2 - p.getY()) + x2;
        return Round(x);
    }
    virtual void draw(Canvas &canvas, string val = "*") {
        canvas.draw(p.getX(), p.getY(), val);
        canvas.draw(x2, y2, val);
        
        if((x2 - p.getX())*(y2 - p.getY()) != 0) {
            if(Abs((y2 - p.getY())/ (x2 - p.getX())) >= 1) {
                for(int i = 1; i < Abs(y2 - p.getY()); i++) {
                    if(p.getY() <= y2) {
                        canvas.draw(g(p.getY() + i), p.getY() + i, val);
                    }
                    else {
                        canvas.draw(g(p.getY() - i), p.getY() - i, val);
                    }
                }
            }

            else {
                for(int i = 1; i < Abs(x2 - p.getX()); i++) {
                    if(p.getX() <= x2) {
                        canvas.draw(p.getX() + i, f(p.getX() + i), val);
                    }
                    else {
                        canvas.draw(p.getX() - i, f(p.getX() - i), val);
                    }                    
                }
            }           
            
        }
        else {
            if(Abs(x2 - p.getX()) == 0) { // 수직선
                for(int i = 0; i < Abs(y2 - p.getY()); i++){
                    if(y2 >= p.getY()) {
                        canvas.draw(p.getX(), p.getY() + i, val);
                    }
                    else {
                        canvas.draw(p.getX(), p.getY() - i, val);
                    }
                }
            }
            else { // 수평선
                for(int i = 0; i < Abs(x2 - p.getX()); i++) {
                    if(x2 >= p.getX()) {
                        canvas.draw(p.getX() + i, p.getY(), val);
                    }
                    else {
                        canvas.draw(p.getX() - i, p.getY(), val);
                    }

                }
            }            
        }
    }
    
    virtual void move(int dx, int dy) {
        p.move(dx, dy);
        x2 += dx;
        y2 += dy; 
    }
};

class Rect : public Shape {
private:
    int width, height;
public:
    Rect(int x, int y, int wid, int hei) : Shape(x, y), width(wid), height(hei) {}
    virtual void draw(Canvas &canvas, string val = "O") {
        for(int i = 0; i < Abs(height); i++) {
            for(int j = 0; j < Abs(width); j++) {
                if(i == 0 || i == Abs(height) - 1) {   
                    if(height >= 0 && width >= 0) {
                        canvas.draw(p.getX() + j, p.getY() + i, val);
                    }
                    else if (height >= 0 && width < 0) {
                        canvas.draw(p.getX() - j, p.getY() + i, val);
                    }
                    else if (height < 0 && width >= 0) {
                        canvas.draw(p.getX() + j, p.getY() - i, val);
                    }
                    else {
                        canvas.draw(p.getX() - j, p.getY() - i, val);
                    }                                
                    
                }
                else {
                    if (j == 0 || j == Abs(width) - 1) {
                        if(height >= 0 && width >= 0) {
                        canvas.draw(p.getX() + j, p.getY() + i, val);
                    }
                    else if (height >= 0 && width < 0) {
                        canvas.draw(p.getX() - j, p.getY() + i, val);
                    }
                    else if (height < 0 && width >= 0) {
                        canvas.draw(p.getX() + j, p.getY() - i, val);
                    }
                    else {
                        canvas.draw(p.getX() - j, p.getY() - i, val);
                    } 
                        //canvas.draw(p.getX() + j, p.getY() + i, val);
                    }
                } 
            }
        }
    }
    virtual void move(int dx, int dy) {
        p.move(dx, dy);
    }
};

class VLine : public Shape {
private:
    int length;
public:
    VLine(int x, int y, int len) : Shape(x, y), length(len) {}
    virtual void draw(Canvas &canvas, string val = "|") {
        for(int i = 0; i < Abs(length); i++) {
            if(length >= 0) {
                canvas.draw(p.getX(), p.getY() + i, val);
            }
            else {
                canvas.draw(p.getX(), p.getY() - i, val);
            }
        }
    }
    virtual void move(int dx, int dy) {
        p.move(dx, dy);
    }
};

class HLine : public Shape {
private:
    int length;
public:
    HLine(int x, int y, int len) : Shape(x, y), length(len) {}
    virtual void draw(Canvas &canvas, string val = "_") {
        for(int i = 0; i < Abs(length); i++) {
            if(length >= 0) {
                canvas.draw(p.getX() + i, p.getY(), val);
            }
            else {
                canvas.draw(p.getX() - i, p.getY(), val);
            }
        }
    }
    virtual void move(int dx, int dy) {
        p.move(dx, dy);
    }
};

class Square : public Shape {
private:
    int length;
public:
    Square(int x, int y, int len) : Shape(x, y), length(len) {}
    virtual void draw(Canvas &canvas, string val = "O") {
        for(int i = 0; i < Abs(length); i++) {
            for(int j = 0; j < Abs(length); j++) {
                if(i == 0 || i == Abs(length) - 1) {
                    if(length >= 0) {
                        canvas.draw(p.getX() + j, p.getY() + i, val);
                    }
                    else{
                        canvas.draw(p.getX() - j, p.getY() - i, val);
                    }
                    
                }
                else {
                    if (j == 0 || j == Abs(length) - 1) {
                        if(length >= 0) {
                        canvas.draw(p.getX() + j, p.getY() + i, val);
                    }
                        else {
                            canvas.draw(p.getX() - j, p.getY() - i, val);
                        }
                    }
                } 
            }
        }
    }
    virtual void move(int dx, int dy) {
        p.move(dx, dy);
    }
};

#endif