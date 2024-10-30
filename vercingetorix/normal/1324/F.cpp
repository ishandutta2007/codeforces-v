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
const int MAXN = 200500;
vvi g;
int a[MAXN];
int ans[MAXN];
int ansu[MAXN];
void dfs(int v, int p) {
    ans[v] = a[v];
    for(auto u : g[v]) {
        if(u==p) continue;
        dfs(u,v);
        ans[v] += max(0, ans[u]);
    }
}

int res[MAXN];

void dfsup(int v, int p) {
    res[v] = ans[v] + ansu[v];
    for(auto u : g[v]) {
        if(u==p) continue;
        ansu[u] = max(0, res[v] - max(0,ans[u]));
        dfsup(u, v);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    forn(i,0,n) scanf("%d", &a[i]);
    g.resize(n);
    forn(i,0,n) if(a[i] == 0) a[i] = -1;
    forn(i,0,n-1) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0, 0);
    dfsup(0, 0);
    forn(i,0,n) printf("%d ", res[i]);
    
    
}