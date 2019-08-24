#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Line{
  double a, b;
  double eval(double x){
    return a * x + b;
  }
  bool operator<(const Line& l2) const {
    return a == l2.a ? b < l2.b : a < l2.a;
  }
  double inter(const Line& l2) const {
    double x = 1.0 * (l2.b - b) / (a - l2.a);
    return x;
  }
  Line(){
    a = b = 0;
  }
 Line(double _a, double _b){
    a = _a;
    b = _b;
  }
};
const int OO = 1e9;
struct Convex{
  vector<pair<double, Line>> v;
  void add(const Line& l){
    while(v.size() > 1 && l.inter(v[v.size() - 2].second) < v.back().first)
      v.pop_back();
    if(v.empty())
      v.push_back({-OO, l});
    else
      v.push_back({l.inter(v.back().second), l});
  }

  double max(double x){
    auto it = upper_bound(v.begin(), v.end(), make_pair(x, Line()));
    return (--it) -> second.eval(x);
  }
};


struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  return 0;
}

