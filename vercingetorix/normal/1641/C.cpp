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
const int INF = 1e9;
class streemin {
public:
    vi t;
    int s;
    void build (int n, int v, int tl, int tr) {
        t = vi(4*n, INF);
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return INF;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  min(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
    
    void update (int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr)
            t[v] = min(t[v],new_val);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update (v*2, tl, tm, pos, new_val);
            else
                update (v*2+1, tm+1, tr, pos, new_val);
            t[v] =  min(t[v*2], t[v*2+1]);
        }
    }
};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    streemin st;
    st.build(n, 1, 0, n-1);
    set<int> sick;
    forn(i,-1,n+1) sick.insert(i);
    while(q--) {
        int tp;
        scanf("%d", &tp);
        if(tp == 0) {
            int l,r,x;
            scanf("%d %d %d", &l, &r, &x);
            l--;
            r--;
            if(x == 0) {
                vi del;
                auto it = sick.lower_bound(l);
                while(it!=sick.end() && *it <= r) {
                    del.pb(*it);
                    it++;
                }
                for(auto y : del) sick.erase(y);
            }
            else {
                st.update(1, 0, n-1, l, r);
            }
        }
        else {
            int i;
            scanf("%d", &i);
            i--;
            if(!sick.count(i)) {
                printf("NO\n");
            }
            else {
                auto it = sick.find(i);
                it--;
                int l = *it;
                it++; it++;
                int r = *it;
                if(st.get(1, 0, n-1, l+1, i) < r) printf("YES\n");
                else printf("N/A\n");
            }
        }
    }
    
    
}