#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
struct Tr{
  vector<ll> tree;
  vector<ll> arr;
  vector<ll> lazy;
  int n;
  Tr(vector<ll> _arr){
    arr = _arr;
    n = arr.size();
    lazy.resize(4 * n);
    tree.resize(4 * n);
    build(1, 0, n - 1);
  }

  void build(int in, int l, int r){
    if(l == r){
      tree[in] = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    build(2 * in, l, mid);
    build(2 * in + 1, mid + 1, r);
    tree[in] = tree[in * 2] + tree[in * 2 + 1];
  }
  void pushdown(int in, int l, int r){
    tree[in] += lazy[in] * (r - l + 1);
    if(l != r){
      lazy[2 * in] += lazy[in];
      lazy[2 * in + 1] += lazy[in];
    }
    lazy[in] = 0;
  }
  void update(int in, ll v){
    update(1, 0, n - 1, in, v);
  }
  void update(int in, int l, int r, int i, ll v){
    pushdown(in, l, r);
    if(l > i ||  r < i)return;
    if(l == r){
      tree[in] += v;
      return;
    }
    int mid = (l + r) / 2;
    update(2 * in, l, mid, i, v);
    update(2 * in + 1, mid + 1, r, i, v);
    tree[in] = tree[in * 2] + tree[in * 2 + 1];
  }
  ll get(int s, int e){
    return get(1, 0, n - 1, s, e);
  }
  ll get(int in, int l, int r, int s, int e){
    pushdown(in, l, r);
    if(l > e || r < s)return 0;
    if(l >= s && r <= e){
      return tree[in];
    }
    int mid = (l + r) / 2;
    ll le, ri;
    le = get(2 * in, l, mid, s, e);
    ri = get(2 * in + 1, mid + 1, r, s, e);
    return le + ri;
  }
  void add(int s, int e, ll v){
    add(1, 0, n - 1, s, e, v);
  }
  void add(int in, int l, int r, int s, int e, ll v){
    pushdown(in, l, r);
    if(l > e || r < s)return;
    if(l >= s && r <= e){
      lazy[in] += v;
      pushdown(in, l, r);
      return;
    }
    int mid = (l + r) / 2;
    add(2 * in, l, mid, s, e, v);
    add(2 * in + 1, mid + 1, r, s, e, v);
    tree[in] = tree[2 * in] + tree[2 * in + 1];
  }
};
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  return 0;
}

