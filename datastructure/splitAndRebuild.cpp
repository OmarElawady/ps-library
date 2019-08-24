#include <bits/stdc++.h>
#include <ulimit.h>
using namespace std;
#define ll long long
int timeforBuild;
int timePerSum;
struct Awesome{
  struct Range{
    vector<int> vs;
    vector<int> sorted;
    vector<ll> sum;
    int flipped;
    Range(){
      flipped = 0;
    }
    Range(vector<int> vs, bool flipped){
      this -> vs = vs;
      this -> flipped = flipped;
      if(!vs.size())
        return;
      sorted = vs;
      sort(sorted.begin(), sorted.end());
      sum.resize(sorted.size());
      sum[0] = sorted[0];
      for(int i = 1;i < sorted.size();i++)
        sum[i] = sorted[i] + sum[i - 1];
    }
    void adjust(){
      if(flipped)
        reverse(vs.begin(), vs.end());
      flipped = 0;
    }
    int length(){return vs.size();}

    Range* subRange(int s, int e){
      vector<int> newVs(e - s + 1);
      for(int i = s;i <= e;i++)
        newVs[i - s] = vs[i];
      return new Range(newVs, 0);
    }
    ll sumGreater(int x){
      int in = upper_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
      return sum.back() - (in ? sum[in - 1] : 0);
    }
  };

  int k;
  vector<int> arr;
  vector<Range*> ranges;
  int n;
  Awesome(vector<int> arr) : arr {arr}{
    n = arr.size();
    build();
  }
  void destroyRanges(){
    for(auto& el : ranges)
      delete el;
    ranges.clear();
  }
  ~Awesome(){
    destroyRanges();
  }
  void rebuild(){
    fill();
    build();
  }

  void build(){
    destroyRanges();
    k = 2.8 * sqrt(n);
    int blockSize = n / k;
    for(int i = 0;i * blockSize < n;i++){
      vector<int> vs;
      for(int j = 0;j < blockSize && i * blockSize + j < n;j++)
        vs.push_back(arr[i * blockSize + j]);
      ranges.push_back(new Range(vs, 0));
    }
  }

  void fill(){
    arr.clear();
    for(auto range : ranges)
      for(int i = 0;i < range -> vs.size();i++)
        arr.push_back(range ->  vs[(range -> flipped ? range -> vs.size() - 1 - i : i)]);
  }
  int split(int in){
    int cur = 0;
    int res = ranges.size();
    for(int i = 0;i < ranges.size();i++){
      if(cur + ranges[i] -> length() > in){
        ranges[i] -> adjust();
        if(in == cur){
          res = i;
          break;
        }
        Range* l = ranges[i] -> subRange(0, in - cur - 1);
        Range* r = ranges[i] -> subRange(in - cur, ranges[i] -> length() - 1);
        delete ranges[i];
        ranges[i] = l;
        ranges.insert(ranges.begin() + i + 1, r);
        res = i + 1;
        break;
      }
      cur += ranges[i] -> length();
    }
    return res;
  }
  void insert(int in, int v){
    int rangeIn = split(in);
    Range* newRange = new Range({v}, 0);
    ranges.insert(ranges.begin() + rangeIn, newRange);
    n++;
    rebuildIfNecessary();
  }

  void erase(int in){
    int rangeIn = split(in);
    split(in + 1);
    delete ranges[rangeIn];
    ranges.erase(ranges.begin() + rangeIn);
    n--;
    rebuildIfNecessary();
  }
  void rebuildIfNecessary(){
    if(ranges.size() > 2.5 * k)
      rebuild();
  }

  ll sum(int l, int r, int x){
    int s = split(l)
      , e = split(r + 1);
    ll res = 0;
    for(int i = s;i < e;i++)
      res += ranges[i] -> sumGreater(x);
    rebuildIfNecessary();
    return res;
  }
  void flip(int l, int r){
    int lr = split(l)
      , rr = split(r + 1);
    reverse(ranges.begin() + lr, ranges.begin() + rr);
    for(int i = lr;i < rr;i++)
      ranges[i] -> flipped ^= 1;
    rebuildIfNecessary();
  }
};
int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // 0 i x    insert
  // 1 i      erase
  // 2 l r x  sum greater
  // 3 l r    flip

  int n, m;
  cin >> n >> m;
  vector<int> arr(n);
  for(int i = 0;i < n;i++)
    scanf("%d", &arr[i]);
  Awesome ds(arr);
  int t, in, l, r, x;
  for(int i = 0;i < m;i++){
    scanf("%d", &t);
    if(t == 0){
      scanf("%d %d", &in, &x);
      ds.insert(in, x);
    }else if(t == 1){
      scanf("%d", &in);
      ds.erase(in);
    }else if(t == 2){
      scanf("%d %d %d", &l, &r, &x);
      printf("%lld\n", ds.sum(l, r, x));
    }else{
      scanf("%d %d", &l, &r);
      ds.flip(l, r);
    }
  }
}

