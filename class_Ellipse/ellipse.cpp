#include <iostream>
#include "ellipse.hpp"
#include <cmath>
namespace Prog2{
    Ellipse::Ellipse(double a, double b) :p(0,0){
        if (a < 0)
            throw std::underflow_error("ERROR - invalid a");
        this->a = a;
        if (b < 0)
            throw std::underflow_error("ERROR - invalid b");
        this->b = b;
    }

    Ellipse::Ellipse(const Point &p0, double a, double b) :p(p0){
        if (a < 0)
            throw std::underflow_error("ERROR - invalid a");
        this->a = a;
        if (b < 0)
            throw std::underflow_error("error - invalid b");
        this->b = b;
    }

    Ellipse &Ellipse::setA(double a) {
        if (a < 0)
            throw std::underflow_error("error - invalid a");
        this->a = a;
        return *this;
    }

    Ellipse &Ellipse::setB(double b) {
        if (b < 0)
            throw std::underflow_error("error - invalid b");
        this->b = b;
        return *this;
    }

    double Ellipse::focal() const {
        return a>b? 2*std::sqrt(a*a - b*b) : 2*std::sqrt(b*b - a*a);
    }

    double Ellipse::excent() const {
        return this->focal()/(2*a);
    }

    double Ellipse::length() const {
        return a>b? 4*(M_PI*a*b + (a-b)*(a-b)) / (a+b) : 4*(M_PI*a*b + (b-a)*(b-a)) / (a+b);
    }

    double Ellipse::square() const {
        return M_PI*a*b;
    }

    double Ellipse::min() const {
        return a>b? a - this->focal()/2 : b - this->focal()/2;
    }

    double Ellipse::max() const {
        return a>b? a + this->focal()/2 : b + this->focal()/2;
    }

    double Ellipse::findY(double x1) const {
        if (std::abs(x1 - this->p.x) > a)
            throw std::underflow_error("Данное значение вне зоны определения!");
        return b*std::sqrt(1 - x1*x1 / (a*a));
    }

}