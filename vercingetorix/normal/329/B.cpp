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
    scanf("%d %d\n", &n, &m);
    vs a;
    char c[1200];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    vpi dir;
    forn(i,-1,2) forn(j,-1,2) if(i*j==0 && i+j!=0) dir.pb(mp(i,j));
    const int INF = 1e9;
    vvi d(n, vi(m, INF));
    auto good = [&](int i, int j) {return i>=0 && j>=0 && i<n && j<m&&a[i][j] != 'T';};
    int sx,sy,ex,ey;
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == 'S') {
            sx = i;
            sy= j;
        }
        if(a[i][j] == 'E') {
            ex = i;
            ey= j;
        }
    }
    deque<pi> q;
    q.pb(mp(ex,ey));
    d[ex][ey] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        int i = cur.first;
        int j = cur.second;
        for(auto to : dir) {
            int i1 = i+to.first;
            int j1 = j+to.second;
            if(good(i1,j1) && d[i1][j1] == INF) {
                d[i1][j1] = d[i][j] + 1;
                q.pb(mp(i1, j1));
            }
        }
    }
    int ans = 0;
    int len = d[sx][sy];
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] > '0' && a[i][j] <= '9' && d[i][j] <= len) {
            ans += a[i][j]-'0';
        }
    }
    cout<<ans;
    
    
}