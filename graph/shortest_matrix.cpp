#include <bits/stdc++.h>
using namespace std;
const int OO = 1000000000;
typedef long long ll;
typedef vector<vector<int>> Mat;
Mat sqr(const Mat& A){
  Mat C(A.size(), vector<int>(A.size(), OO));
  for(int i = 0;i < A.size();i++)
    for(int j = 0;j < A.size();j++)
      for(int k = 0;k < A.size();k++)
        C[i][j] = min(C[i][j], A[i][k] + A[k][j]);
  return C;
}
Mat shortest(Mat adj){
  int n = adj.size();
  int x = 1;
  while(x < n - 1){
    x *= 2;
    adj = sqr(adj);
  }
  return adj;
}
int main(int argc, char** argv) {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;

  Mat adj(n, vector<int>(n, OO));
  for(int i = 0;i < n;i++)
    adj[i][i] = 0;
  int u, v, w;
  for(int i = 0;i < m;i++){
    cin >> u >> v >> w;
    u--, v--;
    adj[u][v] = adj[v][u] = w;
  }
  adj = shortest(adj);
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++)
      cout << adj[i][j] << ' ';
    cout << endl;
  }
  return 0;
}


