#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
using namespace std; using namespace __gnu_pbds; typedef long long ll; typedef gp_hash_table<ll, ll, hash<ll>> ht;
ll mod = 1000000007; ll dp[3001][3001]; ll uni[3001]; int main() { int m; cin >> m; vector<int> a(m); for(int i=0;i<m;i++) cin >> a[i]; for(int i=1;i<=m;i++) dp[i][i-1] = 1; for(int len=1;len<=m;len++) { for(int i=1;i+len-1<=m;i++) { int j=  i+len-1; if(len==1) dp[i][j] = 1LL; else { for(int x=1;x<=4;x++) { if(x<=len) { if(x==4) { int cmp = 0; for(int k=j-3;k<=j;k++) if(a[k-1]) cmp+=1<<(j-k); if(cmp==3 || cmp==5 || cmp==14 || cmp==15) { continue; } else { dp[i][j]+=dp[i][j-x]; } } else { dp[i][j]+=dp[i][j-x]; } } } } while(dp[i][j]>=mod) dp[i][j]-=mod; } } ll t[3001]; t[0] = 1; ht in; const int p = 37; const ll hm = 2760727302517; for(int i=1;i<=3000;i++) { t[i] = (t[i-1]*1LL*37)%hm; } for(int len=1;len<=m;len++) { ll hash_val = 0; in.clear(); for(int i=1;i<=len;i++) { if(a[i-1]) { hash_val+=t[len-i]; } } hash_val%=hm; in[hash_val] = 1; uni[len]+=dp[1][len]; uni[len]%=mod; for(int i=len+1;i<=m;i++) { if(a[i-len-1]) hash_val-=t[len-1]; hash_val%=hm; hash_val*=p; hash_val%=hm; if(hash_val<0) hash_val+=hm; if(a[i-1]) ++hash_val; if(hash_val>=hm) hash_val-=hm; if(in.find(hash_val)==in.end()) { uni[i]+=dp[i-len+1][i]; uni[i]%=mod; in[hash_val] = 1; } } } for(int i=1;i<=m;i++) { uni[i]+=uni[i-1]; uni[i]%=mod; if(uni[i]<0) uni[i]+=mod; cout << uni[i] << "\n"; } }