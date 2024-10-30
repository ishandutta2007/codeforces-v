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
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int to[18][200500];
class stree {
public:
    vi t;
    int s;
    void build (const vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = min(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 12345678;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  min (
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }

};
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d", &n, &m, &q);
    readv(p,n);
    readv(a,m);
    forn(i,0,n) p[i]--;
    vi nxt(n);
    forn(i,0,n) nxt[p[i]] = p[(i+1)%n];
    forn(i,0,m) a[i]--;
    vi last(n,m);
    to[0][m] = m;
    for(int i = m-1; i>=0; i--) {
        to[0][i] = last[nxt[a[i]]];
        last[a[i]] = i;
    }
    forn(l,1,18) forn(i,0,m+1) to[l][i] = to[l-1][to[l-1][i]];
    vi mv;
    forn(i,0,18) if((1<<i)&(n-1)) mv.pb(i);
    vi r(m);
    forn(i,0,m) {
        int cur = i;
        for(auto l : mv) cur = to[l][cur];
        r[i] = cur;
//        cout<<r[i]<<endl;
    }
    stree st;
    st.build(r, 1, 0, m-1);
    forn(i,0,q) {
        int k,l;
        scanf("%d %d", &k, &l);
        k--;l--;
        if(st.get(1, 0, m-1, k, l) <= l) printf("1");
        else printf("0");
    }
    
}