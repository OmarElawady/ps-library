#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<int>> prufer_seqs(int n){
  int num = 1;
  for(int i = 0;i < n - 2;i++)
    num *= n;
  vector<vector<int>> seqs;
  for(int i = 0;i < num;i++){
    vector<int> seq;
    int x = i;
    for(int j = 0;j < n - 2;j++){
      seq.push_back(x % n);
      x /= n;
    }
    seqs.push_back(seq);
  }
  return seqs;
}
vector<vector<int>> prufer_to_tree(vector<int> seq){
  int n = seq.size() + 2;
  vector<vector<int>> adj(n);
  vector<int> deg(n);
  for(int i = 0;i < n - 2;i++)
    deg[seq[i]]++;
  set<int> ones;
  for(int i = 0;i < n;i++)
    if(deg[i] == 0)
      ones.insert(i);
  for(int i = 0;i < n - 2;i++){
    adj[*ones.begin()].push_back(seq[i]);
    adj[seq[i]].push_back(*ones.begin());
    deg[seq[i]]--;
    ones.erase(ones.begin());
    if(deg[seq[i]] == 0)
      ones.insert(seq[i]);
  }
  return adj;
}
vector<vector<vector<int>>> all_trees(int n){
  vector<vector<int>> seqs = prufer_seqs(n);
  vector<vector<vector<int>>> adjs;
  for(auto &el : seqs){
    adjs.push_back(prufer_to_tree(el));
  }
  return adjs;
}
int main()
{
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  for(int i = 0;i < 10;i++){
    cout << all_trees(i).size() << endl;
  }

  return 0;
}

