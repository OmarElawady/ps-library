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
bool is_bridge[M];
int tt = 1;
int tin[N];

int dfs1(int u, int edge = -1){
  tin[u] = tt++;
  int res = tin[u];
  for(auto el : adj[u]){
    int v = e[el].other(u);
    if(tin[v] == 0)// not yet visited
      res = min(res, dfs1(v, el));
    else if(el != edge)// not the parent edge
      res = min(res, tin[v]);
  }
  if(edge != -1 && res == tin[u])// no back edges from u's subtree
    is_bridge[edge] = true;
  return res;
}
vector<int> tree[N];
int com = 0;
bool vis[N];
int rep[N];
void build(int u, int cur){
  vis[u] = 1;
  rep[u] = cur;
  for(auto el : adj[u]){
    int v = e[el].other(u);
    if(vis[v])continue;
    if(is_bridge[el]){
      tree[cur].push_back(com);
      tree[com].push_back(cur);
      build(v, com++);
    }else
      build(v, cur);
  }
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
  dfs1(0);
  build(0, com++);

  return 0;
}

