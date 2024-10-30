#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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

const long long mod = 998244353;
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
#ifdef LOCAL
const int A = 10;
#else
const int A = 1005;
#endif
int d[A][A];
int p[A][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a,n);
    srt(a);
    vi l;
    forn(i,0,n) l.pb(i-1);
    ll ans = 0;
    forn(b,1,100001) {
        if(b*(k-1) > 100000) break;
        forn(i,0,n) while(l[i] >= 0 && a[i] - a[l[i]] < b) l[i]--;
        forn(i,0,n) forn(j,0,k+1) {
            d[i][j] = 0;
            p[i][j] = 0;
        }
        d[0][0] = 1;
        d[0][1] = 1;
        p[0][0] = 1;
        p[0][1] = 1;
        forn(i,1,n) {
            forn(j,0,k+1) p[i][j] = p[i-1][j];
            int prev = l[i];
            if(prev == -1) {
                d[i][1] = 1;
            }
            else {
                forn(j,1,k+1) d[i][j] = p[prev][j-1];
            }
            forn(j,0,k+1) p[i][j] = (p[i][j] + d[i][j])%mod;
        }
        ans = (ans +  p[n-1][k])%mod;
    }
    cout<<ans;
    
}