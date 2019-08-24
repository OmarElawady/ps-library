// tested on https://www.spoj.com/problems/ARBITRAG/
#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const int M = 20000;
const int OO = 1000000000;
struct Edge{
  int u, v, w;
  Edge(){}
  Edge(int _u, int _v, int _w): u{_u}, v{_v}, w{_w}{}
  int other(int x){
    return x ^ u ^ v;
  }
} e[M];

int dist[N];
int par[N];
// directed weighted graph
bool bellman_ford(int s, int n = N, int m = M){
  for(int i = 0;i < n;i++)
    dist[i] = OO;
  dist[s] = 0;
  auto relax = [dist](int u, int edge){
    int v = e[edge].other(u);
    if(dist[u] + e[edge].w < dist[v])
      par[v] = u, dist[v] = dist[u] + e[edge].w;
  };
  for(int i = 0;i < n - 1;i++)
    for(int j = 0;j < m;j++)
      relax(e[j].u, j);
  for(int i = 0;i < m;i++)
    if(dist[e[i].u] + e[i].w < dist[e[i].v])
      return false;
  return true;
}
int main() {
  return 0;
}

