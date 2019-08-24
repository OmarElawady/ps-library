#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100001;
vector<int> adj[N];
int dist[N];
bool vis[N];
void bfs(){
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  int sz;
  int dp = 0;
  while(sz = q.size()){
    for(int i = 0;i < sz;i++){
      int tp = q.front();
      q.pop();
      dist[tp] = dp;
      for(auto el : adj[tp]){
        if(!vis[el]){
          vis[el] = 1;
          q.push(el);
        }
      }
    }
    dp++;
  }
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
  bfs();
  return 0;
}

