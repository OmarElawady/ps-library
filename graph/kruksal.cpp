#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000001;
const int M = 1000001;
struct Edge{
  int u, v, w;
  Edge() : u {-1}, v {-1}, w{-1}{}
  Edge(int _u, int _v, int _w) : u {_u}, v {_v}, w{_w}{}
  int other(int x){
    return x ^ u ^ v;
  }
} e[M];
vector<int> adj[N];
int par[N];
int find_set(int u){
  return par[u] == u ? u : par[u] = find_set(par[u]);
}
bool join(int u, int v){
  u = find_set(u);
  v = find_set(v);
  if(u == v)return false;
  if(rand() & 1)swap(u, v);
  par[u] = v;
  return true;
}
void init(){
  for(int i = 0;i < N;i++)
    par[i] = i;
}
// cost of minimum spanning tree
int kruksal(int num_edges){
  init();
  vector<Edge> se(e, e + num_edges);
  sort(se.begin(), se.end(), [](const Edge & a, const Edge & b){
    return a.w < b.w;
  });
  int res = 0;
  for(int i = 0;i < num_edges;i++){
    if(join(se[i].u, se[i].v)){
      res += se[i].w;
    }
  }
  return res;

}
int main(int argc, char** argv) {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;

  cin >> n >> m;
  int u, v, w;
  for(int i = 0;i < m;i++){
    scanf("%d %d %d", &u, &v, &w);
    adj[u].push_back(i);
    adj[v].push_back(i);
    e[i] = Edge(u, v, w);
  }
  cout << kruksal(m);

  return 0;
}

