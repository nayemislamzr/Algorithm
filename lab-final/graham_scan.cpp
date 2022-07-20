#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    double x, y;
    Point() = default;
    Point(double _x, double _y)
        : x{_x}, y{_y}
    {
    }
    double operator-(Point other)
    {
        return ((x - other.x) * (x - other.x)) + ((y - other.y) * (y - other.y));
    }
};

class Vector
{
public:
    double x, y;
    Vector() = default;
    Vector(Point a, Point b)
    {
        x = (b.x - a.x);
        y = (b.y - a.y);
    }
    double operator*(Vector other)
    {
        return (x * other.y) - (y * other.x);
    }
};

int orientation(Point a, Point b, Point c)
{
    Vector ab(a, b);
    Vector ac(a, c);
    double o = ab * ac;
    return (o ? o > 0 ? +1 : -1 : 0);
}

bool ccw(Point a, Point b, Point c)
{
    return orientation(a, b, c) > 0;
}

vector<Point> graham_scan(vector<Point> &points)
{
    Point a = *min_element(points.begin(), points.end(), [](Point a, Point b)
                           { return make_pair(a.y, a.x) < make_pair(b.y, b.x); });

    sort(points.begin(), points.end(), [&a](Point b, Point c)
         {
        int o = orientation(a,b,c);
        if(o == 0)
            return ((a-b)<(a-c));
        return o > 0; });

    vector<Point> hull;
    for (int i = 0; i < points.size(); i++)
    {
        while (hull.size() > 1 && !ccw(hull[hull.size() - 2], hull.back(), points[i]))
            hull.pop_back();
        hull.push_back(points[i]);
    }
    return hull;
}

vector<Point> jarvis_march(vector<Point> &points)
{
    int start = 0;
    int n = points.size();
    for (int i = 1; i < n; i++)
    {
        if (points[i].y < points[start].y)
            start = i;
    }
    int p = start;
    vector<Point> hull;
    do
    {
        hull.push_back(points[p]);
        int q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (i == p || i == q)
                continue;
            if (!ccw(points[p], points[q], points[i]))
                q = i;
        }
        p = q;
    } while (p != start);
    return hull;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    // auto hull = graham_scan(points);
    auto hull = jarvis_march(points);
    for (auto &point : hull)
        cout << point.x << ' ' << point.y << '\n';
}