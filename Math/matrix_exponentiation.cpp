#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Mat;
Mat mul(const Mat& A, const Mat& B){
  Mat C(A.size(), vector<int>(A.size()));
  for(int i = 0;i < A.size();i++)
    for(int j = 0;j < A.size();j++)
      for(int k = 0;k < A.size();k++)
        C[i][j] += A[i][k] * B[k][j];
  return C;
}
Mat power(const Mat& A, int p){
  if(p == 1)
    return A;
  if(p & 1)
    return mul(A, power(A, p - 1));
  else
    return power(mul(A, A), p / 2);
}
int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int n, p;
  cin >> n >> p;
  Mat A(n, vector<int>(n));
  for(int i = 0;i < n;i++)
    for(int j = 0;j < n;j++)
      cin >> A[i][j];
  Mat R = power(A, p);
	for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++)
      cout << R[i][j] << ' ';
    cout << endl;
  }
	return 0;
}

