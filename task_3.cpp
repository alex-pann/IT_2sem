#include <iostream>
#include <vector>
#include <cmath>

class Figure {
public:
    virtual double perimeter() = 0;
    virtual double square() = 0;
    virtual int angles() = 0;
};

class Square : public Figure {
public:
    Square(int a) : a(a){};
    double perimeter() override {
        return 4*a;
    }
    double square() override {
        return a*a;
    }
    int angles() override {
        return n;
    }
private:
    int a;
    int n = 4;
};

class Rectangle : public Figure {
public:
    Rectangle(double a, double b) : a(a), b(b) {};
    double perimeter() override {
        return 2*(a+b);
    }
    double square() override {
        return a*b;
    }
    int angles() override {
        return n;
    }
private:
    double a, b;
    int n = 4;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {};
    double perimeter() override {
        return a+b+c;
    }
    double square() override {
        double p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    int angles() override {
        return n;
    }
private:
    double a, b, c;
    int n = 3;
};

class Circle : public Figure {
public:
    Circle(double r) : r(r){};
    double perimeter() override {
        return 2*pi()*r;
    }
    double square() override {
        return pi()*r*r;
    }
    static double pi() {
        return std::acos(-1);
    }
    int angles() override {
        return n;
    }
private:
    double r;
    int n = 0;
};

class Ellipse : public Figure {
public:
    Ellipse(double a, double b) : a(a), b(b) {};
    double perimeter() override {
        return 2*pi()*sqrt((a*a + b*b)/2);
    }
    double square() override {
        return pi()*a*b;
    }
    static double pi() {
        return std::acos(-1);
    }
    int angles() override {
        return n;
    }
private:
    double a, b;
    int n = 0;
};


int main() {
    std::cout << "Square:" << std::endl;
    Square sq(5);
    std::cout << "Number of angles: " << sq.angles() << std::endl;
    std::cout << "Perimeter: " << sq.perimeter() << std::endl;
    std::cout << "Square: " << sq.square() << std::endl;
    std::cout << std::endl;

    std::cout << "Rectangle:" << std::endl;
    Rectangle rec(5, 2);
    std::cout << "Number of angles: " << rec.angles() << std::endl;
    std::cout << "Perimeter: " << rec.perimeter() << std::endl;
    std::cout << "Square: " << rec.square() << std::endl;
    std::cout << std::endl;

    std::cout << "Triangle:" << std::endl;
    Triangle tr(3,4,5);
    std::cout << "Number of angles: " << tr.angles() << std::endl;
    std::cout << "Perimeter: " << tr.perimeter() << std::endl;
    std::cout << "Square: " << tr.square() << std::endl;
    std::cout << std::endl;

    std::cout << "Circle:" << std::endl;
    Circle circ(5);
    std::cout << "Number of angles: " << circ.angles() << std::endl;
    std::cout << "Perimeter: " << circ.perimeter() << std::endl;
    std::cout << "Square: " << circ.square() << std::endl;
    std::cout << std::endl;

    std::cout << "Ellipse:" << std::endl;
    Ellipse el(2, 3);
    std::cout << "Number of angles: " << el.angles() << std::endl;
    std::cout << "Perimeter: " << el.perimeter() << std::endl;
    std::cout << "Square: " << el.square() << std::endl;
    return 0;
}
