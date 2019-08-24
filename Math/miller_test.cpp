#include <bits/stdc++.h>
#define EPS 1e-38
#define OO 1e9
#define ll long long
#define forn(i, n) for(int i = 0;i < n;i++)
const ll MOD = 1000000007;
using namespace std;
ll pow1(ll n, int p, int MOD){
  ll cur = n, res = 1;
  while(p){
    if(p & 1)
      (res *= cur) %= MOD;
    p /= 2;
    (cur *= cur) %= MOD;
  }
  return res;
}
bool is_prime(ll n){
  if(n == 2 || n == 3)
    return true;
  if(n < 2)
    return false;
  int s = 0;
  int m = n - 1;
  while(m % 2 == 0){
    m /= 2;
    s++;
  }
  for(int i = 0;i < 30;i++){
    ll x = rand() % (n - 3) + 2;
    ll p1 = pow1(x, m, n);

    if(p1 == 1 || p1 == n - 1)
      continue;
    bool ok = 0;
    for(int j = 0;j < s;j++){
      (p1 *= p1) %= n;
      if(p1 == n - 1){
        ok = 1;
        break;
      }
    }
    if(!ok)
      return false;
  }
  return true;
}

int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  srand(time(0));
  cout << is_prime(1000000009) << endl;
}

