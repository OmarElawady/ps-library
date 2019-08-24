#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const int LG = 18;
vector<int> adj[N];
int sz[N];
int sc[N];
int par[N];
int depth[N];
// sizes
void dfs(int nd, int p, int d){
  par[nd] = p;
  depth[nd] = d;
  sz[nd] = 1;
  for(auto el : adj[nd]){
    if(el == p)continue;
    dfs(el, nd, d + 1);
    sz[nd] += sz[el];
    if(sc[nd] == 0 || sz[el] > sz[sc[nd]])sc[nd] = el;
  }
}
// tree is decomposed into paths. Each path is stored in contiguous subarray in arr.
// hld
int pos_in_arr[N];
int arr[N*2];
int chain[N];
int chain_num = 0;
int head[N];
int pos = 0;
void hld(int nd){
  pos_in_arr[nd] = pos++;
  assert(pos <= N);
  arr[pos - 1] = -1;
  chain[nd] = chain_num;
  if(sc[nd] != 0){
    head[sc[nd]] = head[nd];
    hld(sc[nd]);
  }
  for(auto el : adj[nd]){
    if(sz[el] > sz[nd])continue;
    if(sc[nd] == el)continue;
    chain_num++;
    head[el] = el;
    hld(el);
  }
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    dfs(0, -1, 0);
    hld(0);
}

