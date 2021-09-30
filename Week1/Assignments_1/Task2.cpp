#include <iostream>
#include <iomanip>
using namespace std;
class Point
{
public:
    double x;
    double y;
    void set()
    {
        cin >> x;
        cin >> y;
    }
};
void Intersection(Point a, Point b, Point c, Point d)
{
    Point e;

    double a1 = b.y - a.y;
    double b1 = a.x - b.x;
    double c1 = a1 * (a.x) + b1 * (a.y);

    double a2 = d.y - c.y;
    double b2 = c.x - d.x;
    double c2 = a2 * (c.x) + b2 * (c.y);

    double determinant = a1 * b2 - a2 * b1;
    if (determinant == 0)
    {
        cout << "NO";
    }
    else
    {
        e.x = (b2 * c1 - b1 * c2) / determinant;
        e.y = (a1 * c2 - a2 * c1) / determinant;
        cout << e.x << " " << e.y;
    }
}
int main()
{
    Point a;
    Point b;
    Point c;
    Point d;
    a.set();
    b.set();
    c.set();
    d.set();
    Intersection(a, b, c, d);
}