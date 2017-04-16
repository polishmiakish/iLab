//2. Класс фигура - абстрактный(координаты х у, методы - вывод координат, перемещение фигуры, умножение значения координат на мастабные коэфф, подсчет площади) 
//, прямоугольник, треугольник и круг(дополнительно: проверка, что точка внутри круга, проверка, что другой круг внутри этого круга)
#include <iostream>
#include <cmath>

class Figure{
protected:
    float x;
    float y;
public:
    Figure(int a, int b){
        x = a;
        y = b;
    }
    Figure(){
        x = 0;
        y = 0;
    }
    virtual void dumpFigure() = 0;
    virtual void moveFigure(float a, float b) = 0;
    virtual void shapeFigure(float l, float w) = 0;
    virtual float square() = 0;
};

class Square: public Figure {
    float x1, y1, x2, y2;
public:
    Square():Figure(){
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
    }
    Square (int a, int b, int a1, int b1, int a2, int b2) : Figure(a, b){
        x1 = a1;
        x2 = a2;
        y1 = b1;
        y2 = b2;
    }
    void dumpFigure(){
        std::cout << x << " " << y << std::endl;
        std::cout << x1 << " " << y1 << std::endl;
        std::cout << x2 << " " << y2 << std::endl;
        std::cout << x2 + x1 - x << " " << y2 + y1 - y << std::endl;
    }
    float square(){
        float s = ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) * ((x2 -x) * (x2 - x) + (y2 - y) * (y2 - y));
        return sqrt(s);
    }
    void moveFigure(float a, float b){
        x = x + a;
        y = y + b;
        x1 = x1 + a;
        y1 = y1 + b;
        x2 = x2 + a;
        y2 = y2 + b;
    }
    void shapeFigure(float l, float w){
        x = x * l;
        y = y * w;
        x1 = x1 * l;
        y1 = y1 * w;
        x2 = x2 * l;
        y2 = y2 * w;
    }
};

class Tri: public Figure {
    float x1, y1, x2, y2;
public:
    Tri():Figure(){
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
    }
    Tri (int a, int b, int a1, int b1, int a2, int b2) : Figure(a, b){
        x1 = a1;
        x2 = a2;
        y1 = b1;
        y2 = b2;
    }
    void dumpFigure(){
        std::cout << x << " " << y << std::endl;
        std::cout << x1 << " " << y1 << std::endl;
        std::cout << x2 << " " << y2 << std::endl;
    }
    float square(){
        float s1 = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
        float s2 = sqrt((x2 -x) * (x2 - x) + (y2 - y) * (y2 - y));
        float s3 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        float s = (s1 + s2 + s3) / 2;
        return sqrt(s * (s - s1) * (s - s2) * (s - s3));
    }
    void moveFigure(float a, float b){
        x = x + a;
        y = y + b;
        x1 = x1 + a;
        y1 = y1 + b;
        x2 = x2 + a;
        y2 = y2 + b;
    }
    void shapeFigure(float l, float w){
        x = x * l;
        y = y * w;
        x1 = x1 * l;
        y1 = y1 * w;
        x2 = x2 * l;
        y2 = y2 * w;
    }
};

class Circle: public Figure {
    float x1, y1;
public:
    Circle():Figure(){
        x1 = 0;
        y1 = 0;
    }
    Circle (int a, int b, int a1, int b1) : Figure(a, b){
        x1 = a1;
        y1 = b1;
    }
    void dumpFigure(){
        std::cout << x << " " << y << std::endl;
        std::cout << x1 << " " << y1 << std::endl;
    }
    float square(){
        float s = 3.14 * ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
        return s;
    }
    void moveFigure(float a, float b){
        x = x + a;
        y = y + b;
        x1 = x1 + a;
        y1 = y1 + b;
    }
    void shapeFigure(float l, float w){
        x = x * l;
        y = y * w;
        x1 = x1 * l;
        y1 = y1 * w;
    }
    void checkDot(float a, float b){
        float R, r;
        R = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
        r = (a - x) * (a - x) + (b - y) * (b - y);
        if (r < R)
            std::cout << "Dot is inside" << std::endl;
        else
            std::cout << "Dot is outside" << std::endl;
    }
    void checkCircle(Circle A){
        float R, r;
        R = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
        r = (A.x1 - A.x) * (A.x1 - A.x) + (A.y1 - A.y) * (A.y1 - A.y) +  (A.x - x) * (A.x - x) + (A.y - y) * (A.y - y);
        if (r < R)
            std::cout << "Circle is inside" << std::endl;
        else
            std::cout << "Circle is outside" << std::endl;
    }
};

int main(){
    Square* A = new Square(1, 1, 3, 1, 3, 3);
    (*A).dumpFigure();
    std::cout << (*A).square() << std::endl;
    (*A).moveFigure(1, 1);
    (*A).dumpFigure();
    (*A).shapeFigure(2, 3);
    (*A).dumpFigure();
    Tri* C = new Tri(1, 1, 3, 1, 3, 3);
    (*C).dumpFigure();
    std::cout << (*C).square() << std::endl;
    (*C).moveFigure(1, 1);
    (*C).dumpFigure();
    (*C).shapeFigure(2, 3);
    (*C).dumpFigure();
    Circle *B = new Circle(0, 0, 1, 1);
    (*B).checkDot(1, 2);
    (*B).checkDot(0.5, 0.5);
    Circle *D = new Circle(0, 0, 0.5, 0.5);
    (*D).checkCircle(*B);
    return 0;
}
