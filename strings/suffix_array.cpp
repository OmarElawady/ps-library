#include <bits/stdc++.h>

using namespace std;
// N should be at least 1.5 * (2 ^ LGN)
const int N = 2 * (1 << 10);
// LGN is max power of 2 >= max size
const int LGN = 10;
class Suffix_array{
  public:
    int sort_index[LGN + 1][N];
    int n;
    string str;
    vector<int> suff;
    vector<int> lcp;
    Suffix_array(string _str){
      str = _str;
      memset(sort_index, -1, sizeof(sort_index));
      vector<pair<pair<int, int>, int>> L; // pair of previous sorted index, index
      n = str.size();
      init_L(L);
      assign_sort_index(L, 0);
      for(int i = 1;i <= LGN;i++){
        assign_L(L, i);
        assign_sort_index(L, i);
      }
      assign_suff(LGN);
      compute_lcp();
    }

  private:
    void init_L(vector<pair<pair<int, int>, int>>& L){
      L.resize(n);
      for(int i = 0;i < n;i++)
        L[i] = {{str[i], -1}, i};
      sort(L.begin(), L.end());
    }

    void assign_L(vector<pair<pair<int, int>, int>>& L, int in){
      for(int i = 0;i < n;i++)
        L[i] = {{sort_index[in-1][i], sort_index[in-1][i + (1 << (in - 1))]}, i};
      sort(L.begin(), L.end());
    }
    void assign_sort_index(vector<pair<pair<int, int>, int>>& L, int in){
      for(int i = 0;i < n;i++){
        if(i && L[i].first == L[i-1].first)
          sort_index[in][L[i].second] = sort_index[in][L[i-1].second];
        else
          sort_index[in][L[i].second] = i;
      }
    }
    void assign_suff(int in){
      suff.resize(n);
      for(int i = 0;i < n;i++){
        suff[sort_index[in][i]] = i;
      }
    }
    void compute_lcp(){
      lcp.resize(n);
      vector<int> rank(n);
      int k = 0;
      for(int i = 0;i < n;i++)
        rank[suff[i]] = i;
      for(int i = 0;i < n;i++, k && k--){
        if(rank[i] == n - 1){
          k = 0;
          continue;
        }
        int j = suff[rank[i] + 1];
        while(i + k < n && j + k < n && str[i+k] == str[j+k])k++;
        lcp[rank[i]] = k;
      }
    }
};



int main(){
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int tc;
  cin >> tc;
  while(tc--){
    string str;
    cin >> str;
    int n = str.size();
    Suffix_array arr(str);
    int res = 0;
    res = n * (n + 1) / 2;
    for(int i = 0;i < n - 1;i++){
        res -= arr.lcp[i];
    }
    cout << res << endl;
  }
}

