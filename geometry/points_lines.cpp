// not really
#include <bits/stdc++.h>

using namespace std;

struct Point{
  double x, y;
  Point(double x, double y):x(x), y(y){}

  Point():x(0), y(0){}

  //operators
  Point& operator=(const Point& o){
    x = o.x;
    y = o.y;
    return *this;
  }

  Point& operator+=(const Point& o){
    x += o.x;
    y += o.y;
    return *this;
  }

  Point& operator-=(const Point& o){
    x -= o.x;
    y -= o.y;
    return *this;
  }

  Point& operator*=(double fact){
    x -= fact;
    y -= fact;
    return *this;
  }
  Point& operator/=(double fact){
    x /= fact;
    y /= fact;
    return *this;
  }
};

Point any;

//------------------------operators---------------------------
//minus
Point operator-(const Point &a){
  return Point(-a.x, -a.y);
}
//addition
Point operator+(const Point &a, const Point &b){
  return Point(a.x+b.x, a.y+b.y);
}
//subtraction
Point operator-(const Point &a, const Point &b){
  return Point(a.x-b.x, a.y-b.y);
}
//dot product
double operator*(const Point &a, const Point &b){
  return a.x*b.x + a.y*b.y;
}

//cross product
double operator^(const Point &a, const Point &b){
  return a.x*b.y - a.y*b.x;
}
//multiplication by a factor
Point operator*(const double factor, const Point & p){
  return Point(factor * p.x, factor * p.y);
}
Point operator*(const Point & p, const double factor){
  return Point(factor * p.x, factor * p.y);
}
//comparisons (precision error)
bool operator==(const Point & a, const Point & b){
  return a.x == b.x && a.y == b.y;
}
bool operator!=(const Point & a, const Point & b){
  return a.x != b.x || a.y != b.y;
}
//---------------------functions----------------------
// angle [-pi, pi]
double angle(const Point& p){
  return atan2(p.y, p.x);
}
double angle(const Point& a, const Point& b){
  return atan2(a^b, a*b);
}
Point rotate(const Point &p, double an){
  return Point(p.x * cos(an) - p.y * sin(an), p.x * sin(an) + p.y * cos(an));
}
Point rotate(const Point &p, double an, Point& around){
  return rotate(p - around, an) + around;
}
double norm(const Point &p){
  return sqrt(p*p);
}
Point perp(const Point &p){
  return Point(-p.y, p.x);
}
Point bisector(const Point &a, const Point &b){
  return a * norm(b) + b * norm(a);
}
//projection
double proj(const Point &a, const Point &b){
  return a * b / norm(b);
}

//ccw , 0 -> collinear, > 0 counter clockwise, < 0 clockwise
double ccw(const Point &a, const Point &b, const Point &orig){
  return (a - orig) ^ (b - orig);
}

double ccw(const Point &a, const Point &b){
  return (a) ^ (b);
}
//--------------------------------------lines------------------------------------------------
struct Line{
  Point a, ab;
  Line(const Point &a, const Point &b):a(a), ab(b-a){}
  Line():a(), ab(){}
  Point b(){
    return a + ab;
  }
};
// precision
bool online(const Line& l, Point& p){
  return ((p - l.a) ^ l.ab) == 0;
}
double dist(const Line& r, Point& p){
  return abs(proj(p-r.a, perp(r.ab)));
}

bool inter(const Line& s1, const Line &s2, Point& res){
  if((s1.ab ^ s2.ab) == 0){
    if(online(s1, s2.a)); // coincident
    else; // parallel
    return 0;
  }
  double t = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
  res = s1.a + s1.ab * t;
  return 1;
}
double proj(const Point &p, const Line &l, Point &res){
  double t = (p - l.a) * l.ab;
  res = l.a + t * l.ab;
  return t;
}
void reflection(const Point &p, const Line &l, Point &res){
  Point pr;
  proj(p, l, pr);
  res = p + 2 * (pr - p);
}
//-----------------------------segment----------------------------------
struct Segment{
  Point a, ab;
  Segment(const Point &a, const Point &b):a(a), ab(b-a){}
  Segment():a(), ab(){}
  Point b () const {
    return a + ab;
  }
};
bool onsegment(const Segment& l, const Point& p){
  return ((p - l.a) ^ l.ab) == 0 && ((p - l.a) * (p - l.b())) <= 0;
}


double dist(const Segment& r, const Point& p, Point& res = any){
  if((p - r.a) * (r.ab) <= 0){res = r.a;return norm(p - r.a);}
  if((p - r.b()) * (-r.ab) <= 0){res = r.b();return norm(p - r.b());};
  res = r.a + proj((p - r.a), r.ab) / norm(r.ab) * r.ab;
  return abs(proj(p-r.a, perp(r.ab)));
}

bool inter(const Segment& s1, const Segment &s2, Point& res = any){
  if((s1.ab ^ s2.ab) == 0)return (onsegment(s1, s2.a)
                                  || onsegment(s1, s2.b())
                                  || onsegment(s2, s1.a)
                                  || onsegment(s2, s1.b())
                                  ); // parallel
  double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
  double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
  if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1)return 0;// does not intersect
  res = s1.a + s1.ab * t1;
  return 1;
}

int main()
{
//  freopen("in.txt", "r", stdin);
  return 0;
}

