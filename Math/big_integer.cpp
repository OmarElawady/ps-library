#include <bits/stdc++.h>
#define EPS 1e-38
#define OO 1e9
#define ll long long
#define forn(i, n) for(int i = 0;i < n;i++)
const ll MOD = 1000000007;
const int BASE = 1000000000;
const int L    = 9;
//const int BASE = 100;
using namespace std;
struct Bigint{
  vector<long long> v;
  Bigint(vector<long long> _v): v{_v}{

  }
  Bigint(string num){
    int len = (num.size() + L - 1) / L;
    v.resize(len);
    ll n = 0;
    int fir = num.size() - (len - 1) * L;
    for(int i = 0;i < fir;i++){
      n *= 10;
      n += num[i] - '0';
    }
    v[len - 1] = n;
    for(int i = 0;i < len - 1;i++){
      n = 0;
      for(int j = 0;j < L;j++){
        n *= 10;
        n += num[L * i + j + fir] - '0';
      }
      v[len - i - 2] = n;
    }
  }
  void add_once(vector<long long>& vec, long long val, int in){
    while(in >= vec.size())
      vec.push_back(0);
    vec[in] += val;
  }
  void add(vector<long long>& vec, long long val, int in){
    add_once(vec, val, in);

    while(vec[in] >= BASE){
      add_once(vec, vec[in] / BASE, in + 1);
      vec[in] %= BASE;
      in++;
    }
  }
  Bigint operator*(const Bigint& b){
    vector<long long> nv(v.size());
    for(int i = 0;i < v.size();i++)
      for(int j = 0;j < b.v.size();j++)
        add(nv, v[i] * b.v[j], i + j);
    return Bigint(nv);
  }
  Bigint operator+(const Bigint& b){
    vector<long long> nv(max(v.size(), b.v.size()));
    for(int i = 0;i < v.size();i++){
      add(nv, (i < v.size() ? v[i] : 0) + (i < b.v.size() ? b.v[i] : 0), i);
    }
    return Bigint(nv);
  }
  string to_string(){
    string res;
    if(v.size() == 0)
      return "0";
    for(int i = 0;i < v.size();i++){
      res += to_string(v[i]);
    }
    reverse(res.begin(), res.end());
    return res.substr(res.find_first_not_of('0'));
  }
  string to_string(int num){
    string res;
    while(num){
      res += num % 10 + '0';
      num /= 10;
    }
    while(res.size() != L)
      res += '0';
    return res;
  }
};


int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  string num1 = "91023481204823940231748901273490723047923740212398";
  string num2 = "234189032740234738294701374210384021973";
  Bigint a (num1);
  Bigint b (num2);
  Bigint c = a * b;
  cout << c.to_string();
}

