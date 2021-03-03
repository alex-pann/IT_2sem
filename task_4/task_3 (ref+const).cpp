#include <iostream>
#include <cmath>

class Figure {
public:
    virtual double perimeter() const = 0;
    virtual double square() const = 0;
    virtual int angles() const = 0;
};

class Square : public Figure {
public:
    Square(int a) : a(a){};
    double perimeter() const {
        return 4*a;
    }
    double square() const {
        return a*a;
    }
    int angles() const {
        return n;
    }
private:
    int a;
    int n = 4;
};

class Rectangle : public Figure {
public:
    Rectangle(double a, double b) : a(a), b(b) {};
    double perimeter() const {
        return 2*(a+b);
    }
    double square() const {
        return a*b;
    }
    int angles() const {
        return n;
    }
private:
    double a, b;
    int n = 4;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {};
    double perimeter() const {
        return a+b+c;
    }
    double square() const {
        double p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    int angles() const {
        return n;
    }
private:
    double a, b, c;
    int n = 3;
};

class Circle : public Figure {
public:
    Circle(double r) : r(r){};
    double perimeter() const {
        return 2*pi()*r;
    }
    double square() const {
        return pi()*r*r;
    }
    static double pi() {
        return std::acos(-1);
    }
    int angles() const {
        return n;
    }
private:
    double r;
    int n = 0;
};

class Ellipse : public Figure {
public:
    Ellipse(double a, double b) : a(a), b(b) {};
    double perimeter() const {
        return 2*pi()*sqrt((a*a + b*b)/2);
    }
    double square() const {
        return pi()*a*b;
    }
    static double pi() {
        return std::acos(-1);
    }
    int angles() const {
        return n;
    }
private:
    double a, b;
    int n = 0;
};

int angles_amount(const Figure& f) {
    return f.angles();
}

double perimeter(const Figure& f) {
    return f.perimeter();
}
double square(const Figure& f) {
    return f.square();
}


int main() {
    std::cout << "Square:" << std::endl;
    Square sq(5);
    std::cout << "Number of angles: " << angles_amount(sq) << std::endl;
    std::cout << "Perimeter: " << perimeter(sq) << std::endl;
    std::cout << "Square: " << square(sq) << std::endl;
    std::cout << std::endl;

    std::cout << "Rectangle:" << std::endl;
    Rectangle rec(5, 2);
    std::cout << "Number of angles: " << angles_amount(rec) << std::endl;
    std::cout << "Perimeter: " << perimeter(rec) << std::endl;
    std::cout << "Square: " << square(rec) << std::endl;
    std::cout << std::endl;

    std::cout << "Triangle:" << std::endl;
    Triangle tr(3,4,5);
    std::cout << "Number of angles: " << angles_amount(tr) << std::endl;
    std::cout << "Perimeter: " << perimeter(tr) << std::endl;
    std::cout << "Square: " << square(tr) << std::endl;
    std::cout << std::endl;

    std::cout << "Circle:" << std::endl;
    Circle circ(5);
    std::cout << "Number of angles: " << angles_amount(circ) << std::endl;
    std::cout << "Perimeter: " << perimeter(circ) << std::endl;
    std::cout << "Square: " << square(circ) << std::endl;
    std::cout << std::endl;

    std::cout << "Ellipse:" << std::endl;
    Ellipse el(2, 3);
    std::cout << "Number of angles: " << angles_amount(el) << std::endl;
    std::cout << "Perimeter: " << perimeter(el) << std::endl;
    std::cout << "Square: " << square(el) << std::endl;

    return 0;
}
