// vertex u is an atrticulation point iff, in the dfs tree, it's the root and it has more than one child in it
// or the lowest back edge in its subtree points to u or one of its descendants
// dfs detects the articulation points in u's component
// tested on https://www.spoj.com/problems/SUBMERGE/
#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
const int M = 200001;
struct Edge{
  int u, v;
  int other(int i){
    return i ^ u ^ v;
  }
};
vector<int> adj[N];
Edge e[M];
bool is_artic[N];
int tt = 1;
int tin[N];
int dfs1(int u, int p = -1){
  tin[u] = tt++;
  int low = tin[u];
  int cnt = 0;
  for(auto el : adj[u]){
    int v = e[el].other(u);
    if(tin[v] == 0){// not yet visited
      int ch = dfs1(v, u);
      low = min(low, ch);
      if(p != -1 && ch >= tin[u])
        is_artic[u] = 1;
      cnt++;
    }else
      low = min(low, tin[v]);
  }
  if(cnt > 1 && p == -1)
    is_artic[u] = 1;
  return low;
}

int main(int argc, char** argv) {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    scanf("%d %d", &e[i].u, &e[i].v);
    e[i].u--;
    e[i].v--;
    adj[e[i].u].push_back(i);
    adj[e[i].v].push_back(i);
  }
  for(int i = 0;i < n;i++)
    if(!tin[i])
      dfs1(i);

  return 0;
}

