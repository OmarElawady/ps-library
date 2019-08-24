#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200001;
const int M = 200001;
const int LGN = 19;// (1 << (LGN - 1)) >= N
vector<int> adj[N];

int depth[N];
int par[N][LGN];

void dfs(int u, int p = -1){
  for(auto el : adj[u])
    if(el != p){
      par[el][0] = u;
      depth[el] = depth[u] + 1;
      dfs(el, u);
    }
}
void init(){
  for(int i = 1;i < LGN;i++)
    for(int j = 0;j < N;j++)
      par[j][i] = par[par[j][i-1]][i-1];
}
int LCA(int u, int v){
  if(depth[u] < depth[v])swap(u, v);
  int dif = depth[u]  - depth[v];
  for(int i = 0;i < LGN;i++)
    if(dif & (1 << i))
      u = par[u][i];
  if(u == v)return u;
  for(int i = LGN - 1;i >= 0;i--)
    if(par[u][i] != par[v][i])
      u = par[u][i], v = par[v][i];
  return par[u][0];
}

int main(int argc, char** argv) {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  int u, v;
  for(int i = 0;i < m;i++){
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  init();

  return 0;
}

