#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
ll pow1(ll n, ll p, ll m){
  ll c = n, r = 1;
  while(p){
    if(p & 1)
      (r *= c) %= m;
    p /= 2;
    (c *= c) %= m;
  }
  return r;
}
ll sqrtmod(ll n, ll p){
  assert(pow1(n, (p - 1) / 2, p) == 1);
  ll Q = p - 1, S = 0;
  while(Q % 2 == 0)
    Q /= 2, ++S;
  ll R = pow1(n, (Q + 1) / 2, p)
   , t = pow1(n, Q, p);
  int M = S;
  ll Z = rand() % p;
  while(pow1(Z, (p - 1) / 2, p) != p - 1)
    Z = rand() % p;
  Z = pow1(Z, Q, p);
  while(t != 1){
    if(pow1(t, (1 << (M - 2)), p) == p - 1){
      ll x = pow1(Z, 1 << (S - M), p);
      R = R * x % p;
      t = t * x * x % p;
    }
    M--;
  }
  return R;
}

int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  return 0;
}

