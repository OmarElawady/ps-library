#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s[(1 << 24)] = {0};
ll F[(1 << 24)];
void merg(int a[2], int b[2]){
  int arr[4] = {a[0], a[1], b[0], b[1]};
  sort(arr, arr + 4);
  a[0] = arr[2];
  a[1] = arr[3];
}
// or plus max atcoder
int main(){
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  int len = (1 << n);
  int a[len];
  for(int i = 0;i < len;i++)
    scanf("%d", a + i);
  int two[len][2];
  for(int i = 0;i < len;i++)
    two[i][0] = -1, two[i][1] = a[i];
  for(int i = 0;i < n;i++)
    for(int j = 0;j < len;j++)
      if(j & (1 << i))
        merg(two[j], two[j ^ (1 << i)]);
  int res[len];
  res[1] = two[1][0] + two[1][1];
  cout << res[1]<< endl;
  for(int i = 2;i < len;i++){
    res[i] = max(res[i - 1], two[i][0] + two[i][1]);
    cout << res[i]<< endl;
  }
  return 0;

}

