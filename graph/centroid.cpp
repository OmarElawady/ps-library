#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 400001;

vector<int> adj[N];
int sz[N];
void dfs(int u, int p = -1){
  sz[u] = 1;
  for(auto el : adj[u]){
    if(el != p){
      dfs(el, u);
      sz[u] += sz[el];
    }
  }
}
int n;
int centroid(int u, int p = -1){
  for(auto el : adj[u]){
    if(el != p && sz[el] > n / 2){
      return centroid(el, u);
    }
  }
  return u;
}

int main(int argc, char** argv) {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  int u, v;
  for(int i = 0;i < n - 1;i++){
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  int root = centroid(0);
  return 0;
}

