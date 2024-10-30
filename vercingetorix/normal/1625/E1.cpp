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
int n,q;
#ifdef LOCAL
const int A = 20;
#else
const int A = 300500;
#endif
int par[A];
vi ch[A];
ll num[A];
int chnum[A];
vll pref[A];

void dfs(int v) {
//    printf("in %d children %d:", v, ch[v].size());
    num[v] = ll(ch[v].size())*(ch[v].size() + 1)/2;
    ll sum = 0;
    for(auto u : ch[v]) {
        dfs(u);
        num[v] += num[u];
        sum += num[u];
        pref[v].pb(sum);
//        printf(" %d", u);
    }
//    printf("\n");
//    for(auto u : ch[v]) dfs(u);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &q);
    char c[300500];
    scanf("%s", c);
    vi op;
    vi l(n,-1);
    vi r(n,-1);
    forn(i,0,n) {
        if(c[i] == '(') op.pb(i);
        else {
            if(!op.empty()) {
                l[i] = op.back();
                r[op.back()] = i;
                op.pop_back();
                if(op.empty()) {
                    par[l[i] + 1] = 0;
                }
                else {
                    par[l[i] + 1] = op.back() + 1;
                }
                ch[par[l[i] + 1]].pb(l[i] + 1);
            }
        }
    }
    for(auto bad : op) {
        for(auto son : ch[bad + 1]) {
            par[son] = 0;
            ch[0].pb(son);
        }
        ch[bad + 1].clear();
    }
    forn(i,0,n+1) forn(j,0,ch[i].size()) chnum[ch[i][j]] = j;
    dfs(0);
    
    forn(i,0,q) {
        int tp, sl, sr;
        scanf("%d %d %d", &tp, &sl, &sr);
        sl--;
        sr--;
        int p = par[sl+1];
        int il = chnum[sl+1];
        int ir = chnum[l[sr] + 1];
        ll k = ir-il+1;
        ll ans = k*(k+1)/2 + pref[p][ir];
        if(il>0) ans -= pref[p][il-1];
        printf("%lld\n", ans);
    }
    
    
    
    
}