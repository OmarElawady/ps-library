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
      vis.resize(n);
      adj.resize(n);
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
    static const int OO = 1e9;
    int tt = 1;
    vector<int> vis;
    int augment(int s, int t, int flow = OO){
      if(s == t)
        return flow;
      vis[s] = tt;
      for(auto el : adj[s]){
        if(vis[e[el].v] != tt && e[el].c != 0){
          int res = augment(e[el].v, t, min(flow, e[el].c));
          if(res){
            e[el].c -= res;
            e[el ^ 1].c += res;
            return res;
          }
        }
      }
      return 0;
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
   int m;
  cin >> m;
  char a, b;
  int c;
  Edmond mf(123, true);
  for(int i = 0;i < m;i++){
    cin >> a >> b >> c;
    mf.add_edge(a, b, c);
  }
  cout << mf.max_flow('A', 'Z');
  return 0;
}

