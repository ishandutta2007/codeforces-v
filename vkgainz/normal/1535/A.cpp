#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;

int main() {
  int t; cin >> t;
  while(t--) {
      int s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;
      if(max(s3, s4) > min(s1, s2) && max(s1, s2) > min(s3, s4)) {
        cout << "YES" << "\n";
      }
      else cout << "NO" << "\n";
  }
}