/*
if the graph is undirected there's only back and tree edges.
vertex u is a descendant of u iff tin[u] < tin[v] < tout[v] < tout[u].
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001;
vector<int> adj[N];
int tin[N];
int tout[N];
int tt = 0;

void dfs(int u){
  tin[u] = ++tt;
  for(auto el : adj[u]){
    if(tin[el] == -1){ // tree edge
      dfs(u);
    }else if(tout[el] == -1){//back edge

    }else if(tin[u] < tin[el]){ // forward edge

    }else{// cross edge

    }
  }

  tout[u] = ++tt;
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
  memset(tin, -1, sizeof(tin));
  memset(tout, -1, sizeof(tout));
  dfs(0);
  return 0;
}

