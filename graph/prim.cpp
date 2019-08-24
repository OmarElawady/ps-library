#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000001;
const int M = 1000001;
struct Edge{
  int u, v, w;
  Edge():u{0}, v{0}, w{0}{}
  Edge(int _u, int _v, int _w):u{_u}, v{_v}, w{_w}{}
  int other(int x){return x ^ u ^ v;}
} e[M];

vector<int> adj[N];
int prim(int root){
  int sum = 0;
  set<pair<int, int>> ss;
  bool done[N] = {0};
  ss.insert({0, root});
  while(ss.size()){
    pair<int, int> tp = *ss.begin();
    ss.erase(ss.begin());
    int u = tp.second, w = tp.first;
    if(done[u])continue;
    sum = sum + w;
    done[u] = 1;
    for(auto el : adj[u]){
      int v = e[el].other(u);
      int nw = e[el].w;
      if(!done[v])
        ss.insert({nw, v});
    }
  }
  return sum;
}
bool vis[N];
int dfs(int u){
  vis[u] = 1;
  int res = 1;
  for(auto el : adj[u]){
    int v = e[el].other(u);
    if(!vis[v])
      res += dfs(v);
  }
  return res;
}
int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

}

