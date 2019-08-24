#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
struct Tr{
  vector<ll> tree;
  vector<ll> arr;
  int n;
  Tr(vector<ll> _arr){
    arr = _arr;
    n = arr.size();
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
    tree[in] = max(tree[in * 2], tree[in * 2 + 1]);
  }
  void update(int in, int v){
    update(1, 0, n - 1, in, v);
  }
  void update(int in, int l, int r, int i, int v){
    if(l > i || r < i)return;
    if(l == r){
      tree[in] = v;
      return;
    }
    int mid = (l + r) / 2;
    update(2 * in, l, mid, i, v);
    update(2 * in + 1, mid + 1, r, i, v);
    tree[in] = max(tree[in * 2], tree[in * 2 + 1]);
  }
  ll get(int s, int e){
    return get(1, 0, n - 1, s, e);
  }
  ll get(int in, int l, int r, int s, int e){
    cout << in << ' ' << l << ' ' << r << ' ' << s << ' ' << e << endl;
    if(l > e || r < s)return -1e9;
    if(l >= s && r <= e){
      return tree[in];
    }
    int mid = (l + r) / 2;
    ll le, ri;
    le = get(2 * in, l, mid, s, e);
    ri = get(2 * in + 1, mid + 1, r, s, e);
    return max(le, ri);
  }
};
int main()
{
  //  freopen("in.txt", "r", stdin);
  //  freopen("out.txt", "w", stdout);
  vector<ll> arr({1, 4, 2, 4 , 8, 9, -1});
  Tr tree(arr);
  cout << tree.get(4, 5);
  return 0;
}

