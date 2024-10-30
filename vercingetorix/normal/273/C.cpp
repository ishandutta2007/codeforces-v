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
    int n,m;
    scanf("%d %d", &n, &m);
    vvi g(n);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi bad(n,0);
    vi ans(n,0);
    set<int> q;
    forn(i,0,n) if(g[i].size() > 1) {
        bad[i] = 1;
        q.insert(i);
    }
    while(!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        int nbad = 0;
        for(auto u : g[v]) if(ans[u] == ans[v]) nbad++;
        if(nbad < 2) continue;
        int op = -1;
        ans[v] ^= 1;
        for(auto u : g[v]) if(ans[u] == ans[v]) op = u;
        if(op!=-1) {
            int cnt = 0;
            for(auto u : g[op]) if(ans[u] == ans[op]) cnt++;
            if(cnt == 2) q.insert(op);
        }
    }
    forn(i,0,n) printf("%d", ans[i]);
    
    
}