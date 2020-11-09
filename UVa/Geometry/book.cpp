#include<bits/stdc++.h>
using namespace std;
#define EPS 10e-9

class Point{
    public:
        double x, y;
        Point(double xv=0, double yv=0){
            this->x = xv;
            this->y = yv;
        };

        bool operator == (Point other) const {
            if ( abs(x-other.x) < EPS && abs(y-other.y) < EPS ) return 1;
            return 0;
        }

        bool operator < (Point other) const {
            if ( abs(x-other.x) > EPS ) return x < other.x;
            return y < other.y;
        }
};


double dist(Point a, Point b){
    return hypot((a.x-b.x), (a.y-b.y));
}

class Line {
    public:
        double a,b,c;
        Line(double av, double bv=0, double cv=0){
            this->a = av;
            this->b = bv;
            this->c = cv;
        }
};

void p2L(Point a, Point b, Line &l){
    if ( abs(b.x-a.x)<EPS ){
        l.a = 1; l.b=0; l.c=-a.x;
        return;
    }
    double m = (b.y-a.y)/(b.x-a.x);
    double c = a.y - m*a.x;
    l.a = -m; l.c = -c; l.b=1;
}

bool areParallel(Line l1, Line l2){
    return (abs(l1.a-l2.a)<EPS);
}

bool areSame(Line l1, Line l2){
    return (areParallel(l1,l2) && abs(l1.c-l2.c)<EPS);
}



int main(){
    Point p1(1,1), p2(5,1), p3(1,2);
    vector<Point> a = {p1, p2, p3};
    sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++){
        cout << a[i].x << ' ' << a[i].y << endl;
    }
    // cout << (p1==p3) << endl;

    return 0;
}