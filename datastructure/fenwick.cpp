#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;
struct Fenwick{
  vector<int> tree;
  Fenwick(int n){
    tree.resize(n);
  }
  Fenwick(){}
  void add(int in, int val){
    in++;
    while(in < tree.size()){
      tree[in] += val;
      in += in & -in;
    }
  }
  ll get(int in){
    in++;
    ll res = 0;
    while(in){
      res += tree[in];
      in -= in & -in;
    }
    return res;
  }
  ll get(int l, int r){
    if(l == 0)return get(r);
    return get(r) - get(l - 1);
  }
  ll get_at(int in){
    return get(in, in);
  }
};

int main(int argc, char** argv) {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  return 0;
}

