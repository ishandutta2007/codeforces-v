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

class stree {
public:
    vll t;
    int s;
    void build (vll & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    void set (int v, int tl, int tr, int pos) {
        if (pos == tl && tr == pos) {
            t[v] = 0;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos);
            else set(v*2+1, tm+1, tr, pos);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    ll get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return get (v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
    }
    
    pll getr(int v, int tl, int tr, int l, ll sum) {
        if(tl == tr) {
            if(t[v] <= sum) return mp(l+1, t[v]);
            else return mp(l, 0);
        }
        int tm = (tl + tr) / 2;
        if (tm < l) return getr(v*2+1, tm+1, tr, l, sum);
        pll res = getr(v*2, tl, tm, l, sum);
        if(res.first < tm+1) return res;
        else {
            pll res2 = getr(v*2+1,tm+1,tr,tm+1,sum-res.second);
            res2.second += res.second;
            return res2;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n; ll t;
    scanf("%d %lld", &n, &t);
    vll a(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    forn(i,0,n) a.pb(a[i]);
    ll sum = 0;
    forn(i,0,n) sum += a[i];
    stree st, cnt;
    vll cn1(2*n, 1);
    cnt.build(cn1, 1, 0, 2*n-1);
    st.build(a, 1, 0, 2*n-1);
    int cur = 0;
    int num = n;
    ll ans = 0;
    while(num > 0) {
        ans += t/sum * num;
        t %= sum;
        pll res = st.getr(1, 0, 2*n-1, cur, t);
        ans += cnt.get(1, 0, 2*n-1, cur, res.first-1);
        t -= res.second;
        cur = res.first % n;
        num--;
        sum -= a[cur];
        cnt.set(1, 0, 2*n-1, cur);
        cnt.set(1, 0, 2*n-1, cur+n);
        st.set(1, 0, 2*n-1, cur);
        st.set(1, 0, 2*n-1, cur+n);
    }
    cout<<ans;
    
}