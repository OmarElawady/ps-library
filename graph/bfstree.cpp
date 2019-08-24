#include <bits/stdc++.h>
#define ll long long
using namespace std;

// WATCH OUT FOR LONG LONG
const int N = 100001;
vector<int> adj[N];
int dist[N];
int par[N];
int col[N];// 0 white, 1, grey, 1 black
// like CLRS but why not only 0 and 1?
void bfs(){
  memset(col, 0, sizeof(col));
  memset(dist, -1, sizeof(dist));
  memset(par, -1, sizeof(par));

  queue<int> q; // weight, node
  q.push(0);
  col[0] = 1;
  while(q.size()){
    int tp = q.front();
    q.pop();
    for(auto el : adj[tp]){
      if(col[el] == 0){
        col[el] = 1;
        par[el] = tp;
        dist[el] = dist[tp] + 1;
        q.push(el);
      }
    }
    col[tp] = 2;
  }

}

int main(int argc, char** argv) {
  int n, m;
  cin >> n >> m;
  int u, v, w;
  for(int i = 0;i < m;i++){
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bfs();
  return 0;
}

