#include <iostream>
#include <numeric>

class frac{
public:
    frac() {
        this->a = 0;
        this->b = 1;
    }
    frac(int a) : a(a), b(1) {};
    frac(int a, int b) : a(a), b(b) {};
    frac(const frac& another) {
        this->a = another.a;
        this->b = another.b;
    }
    ~frac(){};

    auto get_a() {
        return a;
    }
    auto get_b() {
        return b;
    }

    void get_frac() {
        std::cout << this->get_a() << "/" << this->get_b() << std::endl;
    }

    void set_a(int a) {
        this->a = a;
    }
    void set_b(int b) {
        this->b = b;
    }

    void operator=(frac x){
        this->a = x.get_a()/std::gcd(x.get_a(), x.get_b());
        this->b = x.get_b()/std::gcd(x.get_a(), x.get_b());
    }
    void operator=(int x){
        this->a = x;
        this->b = 1;
    }

    void operator+=(frac x){
        int n_a = a*x.get_b() + b*x.get_a();
        int n_b = b*x.get_b();
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }
    void operator+=(int x) {
        int n_a = a + x*b;
        int n_b = b;
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }

    void operator-=(frac x){
        int n_a = a*x.get_b() - b*x.get_a();
        int n_b = b*x.get_b();
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }
    void operator-=(int x) {
        int n_a = a - x*b;
        int n_b = b;
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }

    void operator*=(frac x){
        int n_a = a*x.get_a();
        int n_b = b*x.get_b();
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }
    void operator*=(int x) {
        int n_a = a*x;
        int n_b = b;
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }

    void operator/=(frac x){
        int n_a = a*x.get_b();
        int n_b = b*x.get_a();
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }
    void operator/=(int x) {
        int n_a = a;
        int n_b = b*x;
        this->a = n_a/(std::gcd(n_a, n_b));
        this->b = n_b/(std::gcd(n_a, n_b));
    }

private:
    int a;
    int b;

};

frac operator+(frac& x, frac& y) {
    frac sum;
    if (x.get_b() == y.get_b()) {
        int s_a = x.get_a() + y.get_a();
        int s_b = x.get_b();
        sum.set_a(s_a/(std::gcd(s_a, s_b)));
        sum.set_b(s_b/(std::gcd(s_a, s_b)));
    } else {
        int s_a = x.get_a()*y.get_b() + x.get_b()*y.get_a();
        int s_b = x.get_b()*y.get_b();
        sum.set_a(s_a/std::gcd(s_a, s_b));
        sum.set_b(s_b/std::gcd(s_a, s_b));
    }
    return sum;
}

frac operator-(frac& x, frac& y) {
    frac sum;
    if (x.get_b() == y.get_b()) {
        int s_a = x.get_a() - y.get_a();
        int s_b = x.get_b();
        sum.set_a(s_a/(std::gcd(s_a, s_b)));
        sum.set_b(s_b/(std::gcd(s_a, s_b)));
    } else {
        int s_a = x.get_a()*y.get_b() - x.get_b()*y.get_a();
        int s_b = x.get_b()*y.get_b();
        sum.set_a(s_a/std::gcd(s_a, s_b));
        sum.set_b(s_b/std::gcd(s_a, s_b));
    }
    return sum;
}

frac operator*(frac& x, frac& y) {
    frac comp;
    int c_a = x.get_a()*y.get_a();
    int c_b = x.get_b()*y.get_b();
    comp.set_a(c_a/std::gcd(c_a, c_b));
    comp.set_b(c_b/std::gcd(c_a, c_b));
    return comp;
}

frac operator/(frac& x, frac& y) {
    frac div;
    int c_a = x.get_a()*y.get_b();
    int c_b = x.get_b()*y.get_a();
    div.set_a(c_a/std::gcd(c_a, c_b));
    div.set_b(c_b/std::gcd(c_a, c_b));
    return div;
}

std::ostream& operator<< (std::ostream &out, frac& x) {
    out << x.get_a() << "/" << x.get_b() << std::endl;
    return out;
}

std::istream& operator>> (std::istream& in, frac& p) {
    int a, b;
    char sl;
    in >> a;
    in >> sl;
    in >> b;
    p.set_a(a);
    p.set_b(b);
    return in;
}

double make_double(frac x){
    double d;
    d = static_cast<double>(x.get_a())/static_cast<double>(x.get_b());
    return d;
}

int main() {

    frac x(5, 6);
    frac y(1, 7);

    frac z = x + y;
//    z.get_frac();
    std::cout << z;

    z = x - y;
    std::cout << z;

    z = x*y;
    std::cout << z;
    z = x/y;
    std::cout << z;

    z += 3;
    std::cout << z;
    z += x;
    std::cout << z;
    z -= 3;
    std::cout << z;
    z -= x;
    std::cout << z;

    z *= 5;
    std::cout << z;
    z *= x;
    std::cout << z;
    z /= 5;
    std::cout << z;
    z /= x;
    std::cout << z;

    frac p;
    std::cin >> p;
    std::cout << p;

    std::cout << make_double(p);
    return 0;
}