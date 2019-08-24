#include <bits/stdc++.h>
#include <complex>
using namespace std;

typedef long long ll;


struct Complex{
  double x, y;
  Complex(){
    x = y = 0;
  }
  Complex(double _x, double _y) : x {_x}, y {_y}{}
  Complex(double _x) : x {_x}, y {0} {}
};
Complex operator*(const Complex& a, const Complex& b){
  return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
Complex operator/(const Complex& a, const double d){
  return Complex(a.x / d, a.y / d);
}
Complex operator+(const Complex& a, const Complex& b){
  return Complex(a.x + b.x, a.y + b.y);
}
Complex operator-(const Complex& a, const Complex& b){
  return Complex(a.x - b.x, a.y - b.y);
}

const int LG = 19;
const int N = (1 << LG);
int rev[N];
Complex root[N];
void init(){
  rev[0] = 0;
  for(int i = 1;i < N;i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (LG - 1));
  root[1].x = 1;
  for(int i = 1;i < LG;i++){
    double th = 2 * M_PI / (1 << (i + 1));
    Complex z(cos(th), sin(th));
    for(int j = (1 << (i - 1));j < (1 << i);j++){
      root[2 * j] = root[j];
      root[2 * j + 1] = root[j] * z;
    }
  }
//  for(int i = 0;i < N / 2;i++){
//    double th = 2 * M_PI * i / N;
//    root[i + N / 2] = Complex(cos(th), sin(th));
//  }
//  for(int i = N / 2 - 1;i >= 1;i--)
//    root[i] = root[2 * i];
}
vector<Complex> FFT(const vector<Complex>& arr){
  int n = arr.size();
  vector<Complex> perm(n);
  for(int i = 0;i < n;i++)
    perm[i] = arr[rev[i]];
  for(int i = 1;i < n;i *= 2){
    for(int j = 0;j < n;j += 2 * i){
      for(int k = j;k < i + j;k++){
        Complex x = root[i + k - j] * perm[k + i];
        perm[k + i] = perm[k] - x;
        perm[k] = perm[k] + x;
      }
    }
  }
  return perm;
}
vector<Complex> multiply(vector<Complex> a, vector<Complex> b){
  a = FFT(a);
  b = FFT(b);
  vector<Complex> r(a.size());
  for(int i = 0;i < r.size();i++){
    r[i] = a[i] * b[i];
    r[i].y *= -1;
  }
  r = FFT(r);
  for(auto& el : r){
    el = el / (double)N;
    el.y *= -1;
  }
  return r;
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  init();

  return 0;
}

