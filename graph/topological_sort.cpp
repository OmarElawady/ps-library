/*
if the graph is undirected there's only back and tree edges.
vertex u is a descendant of u iff tin[u] < tin[v] < tout[v] < tout[u].
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001;
vector<int> adj[N];
bool vis[N];

void topological_sort(int u, vector<int>& vv){
  for(auto el : adj[u])
    if(!vis[el])
      topological_sort(u, vv);
  vv.push_back(u);
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
  memset(vis, 0, sizeof(vis));
  vector<int> vv;
  for(int i = 0;i < n;i++){
    if(!vis[i])
      topological_sort(i, vv);
  }
  reverse(vv.begin(), vv.end());
  return 0;
}

