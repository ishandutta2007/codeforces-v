#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    map<int, vpi> h,v,d1,d2;
    int n,m;
    scanf("%d %d", &n, &m);
    vi ans(m,0);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        h[x].pb(mp(y, i));
        v[y].pb(mp(x, i));
        d1[x+y].pb(mp(x, i));
        d2[x-y].pb(mp(x, i));
    }
    for(auto & mpa : {h,v,d1,d2}) {
        for(auto x : mpa) {
            srt(x.second);
            int l = x.second.size();
            if(l > 1) forn(i,0,l) {
                if(i==0 || i == l-1) ans[x.second[i].second]++;
                else ans[x.second[i].second]+=2;
            }
        }
    }
    vi res(9,0);
    forn(i,0,m) res[ans[i]]++;
    forn(i,0,9) cout<<res[i]<<' ';
    
}