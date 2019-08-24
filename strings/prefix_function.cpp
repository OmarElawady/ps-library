#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> prefix_function(string str){
  int n = str.size();
  vector<int> pre(n);
  for(int i = 1;i < str.size();i++){
    int k = pre[i - 1];
    while(k && str[i] != str[k])
      k = pre[k - 1];

    if(str[k] == str[i])
      k++;

    pre[i] = k;
  }
  return pre;
}
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  string str = "abababcbd";
  vector<int> pre = prefix_function(str);
}


