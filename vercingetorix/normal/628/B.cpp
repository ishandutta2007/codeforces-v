#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,m;
    ll ans = 0;
    string s;
    cin >> s;
    vi a(s.length());
    for(int i=0; i<s.length(); i++) a[i]=s[i]-'0';
    int N = s.length();
    for(int i =0; i<N; i++) if((a[i]%4)==0) ans++;
    for(int i =1; i<N; i++) {
        if((10*a[i-1]+a[i])%4 == 0) ans+=i;
    }
    
    
    cout<<ans;
}