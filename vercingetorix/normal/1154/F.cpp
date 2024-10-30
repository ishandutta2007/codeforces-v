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
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    readv(a,n);
    srt(a);
    vll pref(1,0);
    
    ll sum = 0;
    for(auto x : a) {
        sum += x;
        pref.pb(sum);
    }
    const ll INF = 1e18;
    vll d(n+1, INF);
    d[0] = 0;
    
    vi bo(k+1,0);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        if(x <= k) bo[x] = max(bo[x], y);
    }
    vpi offer;
    forn(i,1,k+1) if(bo[i] > 0) offer.pb(mp(i, bo[i]));
    forn(r,0,n) {
        d[r+1] = min(d[r+1], d[r] + a[r]);
        for(auto x : offer) {
            int p = x.first;
            int q = x.second;
            if(r + p <= n) {
                d[r+p] = min(d[r+p], d[r] + pref[r+p]-pref[r+q]);
            }
        }
    }
    cout<<d[k];
    
    
}