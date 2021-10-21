#ifndef LAB2_ELLIPSE_HPP
#define LAB2_ELLIPSE_HPP
#include <cmath>
namespace Prog2 {
    struct Point {
        double x, y;
        Point(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
    };

    class Ellipse {
    private:
        Point p;
        double a;
        double b;
    public:
        Ellipse(double a = 5, double b = 3);//пустой конструктор, инициализирующий
        Ellipse(const Point &p0, double a = 5, double b = 3);//

        Point getP() const { return p; }
        double getA() const { return a; }
        double getB() const {return b; }

        Ellipse& setP(const Point &p0) { p = p0; return *this; }
        Ellipse& setP(double x0, double y0){p.x = x0; p.y = y0; return *this;}
        Ellipse& setA(double a);
        Ellipse& setB(double b);

        double focal() const;
        double excent() const;
        double length() const;
        double square() const;
        double min() const;
        double max() const;
        double findY(double x) const;
    };
}

#endif //LAB2_ELLIPSE_HPP
