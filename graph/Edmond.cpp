#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int OO = 1e9;
class Edmond{
  public:
    bool directed;
    int n;
    int add;
    Edmond(int _n):directed{1}, n{_n}, add{0}{}
    Edmond(int _n, bool _directed):n{_n}, directed{_directed}, add{0}{
      par.resize(n);
      vis.resize(n);
      adj.resize(n);
      vis.resize(n);
    }
    void add_edge(int u, int v, int c){
      add_directed(u, v, c);
      if(!directed)
        add_directed(v, u, c);
    }
    ll max_flow(int s, int t){
      if(adj.size() <= s)return 0;
      ll res = 0;
      int aug = 0;
      while(aug = augment(s, t)){
        tt++;
        res += aug;
      }
      return res;
    }
    struct Edge{
      int oc;
      int u, v, c;
      Edge(int _u, int _v, int _c):u{_u}, v{_v}, c{_c}{oc = c;}
    };
    vector<vector<int>> adj;
    vector<Edge> e;
  private:
    const int OO = 1e9;
    int tt = 1;
    vector<int> vis;
    vector<int> par;
    int fix_path(int s, int u, int flow){
      if(u == s)
        return flow;
      int res = fix_path(s, e[par[u]].u, min(flow, e[par[u]].c));
      e[par[u]].c     -= res;
      e[par[u] ^ 1].c += res;
      return res;
    }
    int augment(int s, int t){
      queue<int> q;
      q.push(s);
      vis[s] = tt;
      while(q.size()){
        int u = q.front();q.pop();
        if(u == t)break;
        for(auto el : adj[u]){
          Edge& ee = e[el];
          if(vis[ee.v] != tt && ee.c != 0){
            vis[ee.v] = tt;
            par[ee.v] = el;
            q.push(ee.v);
          }
        }
      }
      if(vis[t] != tt)
        return 0;
      return
        fix_path(s, t, OO);
    }
    void add_directed(int u, int v, int c){
      e.push_back(Edge(u, v, c));
      adj[u].push_back(e.size() - 1);
      e.push_back(Edge(v, u, 0));
      adj[v].push_back(e.size() - 1);
    }
};

int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  int u, v, c;
  Edmond mf(n, m, false);
  for(int i = 0;i < m;i++){
    scanf("%d %d %d", &u, &v, &c);
    u--, v--;
    mf.add_edge(u, v, c);
  }
  printf("%lld", mf.max_flow(0, n - 1));
  return 0;
}

