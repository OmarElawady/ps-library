// Strongly connected components

/*
if the graph is undirected there's only back and tree edges.
vertex u is a descendant of u iff tin[u] < tin[v] < tout[v] < tout[u].

a directed graph G = (V, E) has connected components {C0, C1, ..., Cm-1}.
We construct a new graph by contracting all the vertices in the same SCC,
G_S = (V_S, E_S), V_S = {v0, v1, ..., vm-1}, where vi is the represenntative vertex for the ith component.
(vi, vj) belongs to E_S iff there's a directed edge from any vertex in the ith component to a vertex in the jth component.

G_S is a DAG, because if it contains a cycle then all components whose representatives forms a cycle can be merged into one SCC.

let f(Ci) be the biggest finishing time in the ith component.
then if (vi, vj) belongs to G_S, then f(Ci) > f(Cj).
proof consists of 2 cases:
1 - if we visit some vertex x that belongs to the ith component first, then all vertices that belong to ith or jth component is a descendant
of the vertex x. Hence, f(x) is greater than f(y) for any y that belongs to Ci or Cj.

2 - if we visit y that belongs to the jth component first, then vertices that belong to the ith component can NOT be reachable from y
(otherwise we would have a cycle in G_S). But all vertices in jth SCC is a descendant from y by definition.
So jth is greyed and blacked before any vertex in the ith component is visited.

Corollary: if Ci and Cj are 2 distinct SCC. And (u, v) belongs to G transpose where u belongs to Ci, v belongs to Cj.
then f(Ci) < f(Cj).

So by caclulating the finishing time using a dfs for each vertex. And then calling another dfs on G transpose on non visited vertices
in decreasing order of finishing time. we can calculate every connected component.

connected componnets is caclulated in topological order in G_S.

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001;
vector<int> adj[N];
vector<int> adj_tr[N];

int tt = 0;
bool vis[N];

void dfs_final(int u, vector<int>& vv){
  vis[u] = 1;
  for(auto el : adj[u])
    if(!vis[el])
      dfs_final(el, vv);
  vv.push_back(u);
}
int cnt = 0;
int rep[N]; // the index of the connected component that i belongs to
vector<int> adj_s[N];
int car[N];
// adj_s contains multiple edges (can be fixed by unordered_set, sorting and calling unique, or in actual problem)
void dfs(int u){
  vis[u] = 1;
  rep[u] = cnt;
  car[cnt]++;
  for(auto el : adj_tr[u])
    if(!vis[el]){
      dfs(el);
    }else if(rep[el] != rep[u]){
      adj_s[rep[el]].push_back(rep[u]);
    }
}
/*
8 14
0 1
4 0
1 4
4 5
1 5
1 2
5 6
6 5
2 6
2 3
3 2
6 7
7 7
3 7
*/
int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;
  int u, v;
  for(int i = 0;i < m;i++){
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj_tr[v].push_back(u);
  }
  vector<int> vv;

  dfs_final(0, vv);
  memset(vis, 0, sizeof(vis));
  for(int i = vv.size() - 1;i >= 0;i--){
    cout << vv[i] << endl;
    if(!vis[vv[i]]){
      dfs(vv[i]);
      cnt++;
    }

  }

  cout << cnt << endl; // number of strongly connected components
  for(int i = 0;i < cnt;i++){
    cout << i << '\n';
    for(auto el : adj_s[i]){
      cout << el << ' ';
    }
    cout << endl;
  }
  return 0;
}

