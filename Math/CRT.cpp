#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll euclid(ll a, ll b, ll& x, ll& y){
  if(b == 0){
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll g = euclid(b, a % b, x1, y1);
  x = y1;
  y = (x1 - a / b * y1);
  return g;
}
ll inv(ll n, int mod){
  ll x, y;
  euclid(n, mod, x, y);
  return x;
}
ll solve(vector<pair<int, int>> v){
  ll M = 1;
  for(auto &el : v)
    M *= el.second;
  ll res = 0;
  for(int i = 0;i < v.size();i++){
    res += v[i].first * (M / v[i].second) % M * inv(M / v[i].second, v[i].second) % M;
    res %= M;
  }
  return (res + M) % M;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
  cout << solve({{2, 3}, {3, 8}});
  return 0;
}

