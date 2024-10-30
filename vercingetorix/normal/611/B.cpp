#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    ll d2 = 1;
    map<ll,int> deg2;
    vll vd2;
    while(d2 < 4000000000000000000) {
        deg2[d2]++;
        vd2.pb(d2);
        d2*=2;
    }
    ll l,r;
    cin>>l>>r;
    int ans = 0;
    forn(i,0,vd2.size()) {
        forn(j,0,i-1) {
            ll cand = vd2[i]-1-vd2[j];
            if(cand>=l && cand<=r) ans++;
        }
    }
    cout<<ans;
}