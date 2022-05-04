#include <iostream>
#include <cmath>

using namespace std;
class Point
{
    int x;
    int y;
    int id;
public:
    static int value;
    Point()
    {
        x = y = 0;
        id = ++value;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        id = ++value;
    }

    void print()
    {
        cout << "x=" << x << "\ny=" << y << endl;
    }

    int getX() const;

    int getY() const;

    int getId() const;

    void setX(int x);

    void setY(int y);

    void setId(int id);

};

inline double getLine(Point p1, Point p2) {
    return (sqrt(pow(p2.getX() - p1.getX(),2) + pow(p2.getY() - p1.getY(),2)));
}

inline double getArea(double a, double b, double c) {
    double halfP = (a + b + c) / 2;
    return sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c));
}

int Point::value = 0;

int main()
{
    int length = 3;
    Point* p = new Point[length]{Point(0, 0), Point(0, 1), Point(1, 0)};

    p[1].print();
    cout << "ID of point p[0]: " << p[0].getId() << endl;
    cout << "ID of point p[1]: " << p[1].getId() << endl;
    cout << "ID of point p[2]: " << p[2].getId() << endl;
    cout << Point::value << endl;

    double a, b, c, s;
    a = getLine(p[0], p[1]);
    b = getLine(p[1], p[2]);
    c = getLine(p[2], p[0]);

    s = getArea(a, b, c);

    cout << "Area: " << s << endl;

    delete[] p;

    return 0;
}

//реализация геттеров и сеттеров
int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(int x) {
    Point::x = x;
}

void Point::setY(int y) {
    Point::y = y;
}

void Point::setId(int id) {
    Point::id = id;
}

int Point::getId() const {
    return id;
}
