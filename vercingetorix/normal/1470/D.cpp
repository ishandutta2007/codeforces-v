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

const long long mod = 1000000007;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    vi cnt(1000010, 0);
    forn(affa,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        vvi g(n);
        forn(i,0,m) {
            int u,v;
            scanf("%d %d", &u, &v);
            u--;v--;
            g[u].pb(v);
            g[v].pb(u);
        }
        vi vis(n,0);
        vi ans;
        vi q;
        q.pb(0);
        while(!q.empty()) {
            int v = q.back();
            q.pop_back();
            if(vis[v]) continue;
            ans.pb(v);
            vis[v] = 1;
            for(auto u : g[v]) if(!vis[u]) {
                vis[u] = 1;
                for(auto l : g[u]) q.pb(l);
            }
        }
        int s = 0;
        forn(i,0,n) s+=vis[i];
        if(s != n) printf("NO\n");
        else {
            printf("YES\n");
            printf("%d\n", int(ans.size()));
            for(auto x : ans) printf("%d ", x+1);
            printf("\n");
        }
        
    }
}