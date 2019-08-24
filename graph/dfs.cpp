#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001;
vector<int> adj[N];
int depth[N];
int sz[N];
void dfs(int u, int p = -1){
  if(p == -1)
    depth[u] = 1;
  else
    depth[u] = depth[p] + 1;
  sz[u] = 1;
  for(auto el : adj[u])
    if(el != p){
      dfs(u, p);
      sz[p] += sz[u];
    }
}

int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;
  int u, v;
  for(int i = 0;i < m;i++){
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  return 0;
}

