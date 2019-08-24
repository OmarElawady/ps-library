#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mancher(string s){
  int n = s.size();
  int d[2][n];
  for(int z = 0;z < 2;z++)
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = i > r ? z ^ 1 : min(d[z][l + r - i + z], r - i + 1);
        while (0 <= i - k - z && i + k < n && s[i - k - z] == s[i + k])
            k++;
        d[z][i] = k--;
        if (i + k > r) {
            l = i - k - z;
            r = i + k;
      }
    }
  int res = 0;
  for(int i = 0;i < n;i++)
    res += d[0][i] + d[1][i];
  return res;
}
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  return 0;
}

