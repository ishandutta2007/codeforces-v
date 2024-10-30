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

const long long mod = 998244353;
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


ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

const int A = 20500;
ll nfac[A];
ll ifac[A];
ll in[A];

void initfac() {
    nfac[0] = 1;
    forn(i,1,A) nfac[i] = nfac[i-1]*i%mod;
    ifac[A-1] = invmod(nfac[A-1], mod);
    for(int i = A-1; i>=1; i--) ifac[i-1] = ifac[i]*i%mod;
    forn(i,1,A) in[i] = ifac[i]*nfac[i-1]%mod;
}

ll cnk(int n, int k) {
    if(k<0 || k>n) return 0;
    return nfac[n]*ifac[k]%mod*ifac[n-k]%mod;
}

const int B = 5001;
ll d[B][B];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    initfac();
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(b,n);
        map<int, int> cnt;
        for(auto x : b) cnt[x]++;
        vpi a;
        for(auto x : cnt) a.pb(x);
        forn(i,0,n+1) forn(j,0,n+1) d[i][j] = 0;
        if(a.back().second != 1) {
            printf("0\n");
            continue;
        }
        d[0][0] = 1;
        a.pop_back();
        reverse(all(a));
        if(a.empty()) {
            printf("0\n");
            continue;
        }
        auto last = a.back();
        a.pop_back();
        int i = 0;
        int left = n-1;
        for(auto x : a) {
            int k = x.second;
            forn(was,0,n+1) if(d[i][was] > 0) {
                int slot = was;
                if(slot + 1 == left) slot++;
                if(was >= k) d[i+1][was-k] = (d[i+1][was-k] + d[i][was]*cnk(slot, k))%mod;
                if(was >= k-1) d[i+1][was-k+2] = (d[i+1][was-k+2] + d[i][was]*cnk(slot, k-1))%mod;
            }
            left -= k;
            i++;
        }
        printf("%lld\n", d[i][last.second - 1]);
    }
    
    
}