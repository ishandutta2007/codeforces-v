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

const long long mod = 1000000000;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

struct m2 {
    m2() {forn(i,0,2) forn(j,0,2) x[i][j] = 0;};
    ll x[2][2];
};

m2 prod(m2 a, m2 b) {
    m2 c;
    forn(i,0,2) forn(j,0,2) {
        c.x[i][j] = (a.x[i][0]*b.x[0][j]+a.x[i][1]*b.x[1][j])%mod;
    }
    return c;
}

void mul(m2 & a, ll x) {
    forn(i,0,2) forn(j,0,2) a.x[i][j] = (a.x[i][j]*x)%mod;
}

m2 sum(m2 a, m2 b) {
    m2 c;
    forn(i,0,2) forn(j,0,2) {
        c.x[i][j] = (a.x[i][j]+b.x[i][j])%mod;
    }
    return c;
}

pll sum(pll a, pll b) {
    return pll(a.first+b.first, a.second+b.second);
}

void mplus(m2 & a, m2 b) {
    forn(i,0,2) forn(j,0,2) a.x[i][j] = (a.x[i][j] + b.x[i][j]) % mod;
}

vector<m2> fp;
vector<m2> fpinv;
m2 id;
vll fval;
ll gsum(int l, int r) {
    return (fval[r+3]+mod-fval[l+2])%mod;
}
const int A = 200100;
vector<ll> pp(4*A);
vector<ll> pp1(4*A);


class stree {
public:
    vll t;
    vll t1;
    vll lazy;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            t1.resize(a.size() * 4);
            s = a.size();
            lazy = vll(4*s,0);
        }
        if (tl == tr) {
            t[v] = fval[tl+1]*a[tl]%mod;
            t1[v] = fval[tl]*a[tl]%mod;
        }
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = (t[v*2]+t[v*2+1])%mod;
            t1[v] = (t1[v*2]+t1[v*2+1])%mod;
        }
    }
    
    void dfs(int v, int tl, int tr) {
        pp[v] = gsum(tl, tr);
        pp1[v] = gsum(tl-1, tr-1);
        if(tl == tr) return;
        int tm = (tl + tr) / 2;
        dfs (v*2, tl, tm);
        dfs (v*2+1, tm+1, tr);
    }
    
    void push(int v) {
        if (lazy[v] == 0) return;
        lazy[v] = lazy[v] % mod;
        ll add = pp[v];
        ll add1 = pp1[v];
        t[v] = (t[v] + add*lazy[v])%mod;
        t1[v] = (t1[v] + add1*lazy[v])%mod;
        if(v<2*s) {
            lazy[v*2] += lazy[v];
            lazy[v*2+1] += lazy[v];
        }
        lazy[v] = 0;
    }
    
    void update (int v, int tl, int tr, int l, int r, int add) {
        push(v);
        if (l > r)
            return;
        if (l == tl && tr == r) {
            lazy[v] += add;
            push(v);
        }
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
            t[v] = (t[v*2]+t[v*2+1])%mod;
            t1[v] = (t1[v*2]+t1[v*2+1])%mod;
        }
    }
    
    void set (int v, int tl, int tr, int pos, int val) {
        push(v);
        if (pos == tl && tr == pos) {
            t[v] = fval[tl+1]*val%mod;
            t1[v] = fval[tl]*val%mod;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) {
                set(v*2, tl, tm, pos,val);
                push(v*2+1);
            }
            else {
                set(v*2+1, tm+1, tr, pos,val);
                push(v*2);
            }
            t[v] = (t[v*2]+t[v*2+1])%mod;
            t1[v] = (t1[v*2]+t1[v*2+1])%mod;
        }
    }
    
    pll get (int v, int tl, int tr, int l, int r) {
        push(v);
        if(l>r) return mp(0,0);
        if (tl == l && tr == r)
            return mp(t[v], t1[v]);
        int tm = (tl + tr) / 2;
        pll res = sum(get (v*2, tl, tm, l, min(r,tm)), get(v*2+1, tm+1, tr, max(l,tm+1), r));
        t[v] = (t[v*2]+t[v*2+1])%mod;
        t1[v] = (t1[v*2]+t1[v*2+1])%mod;
        return res;
    }
};



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    fval.pb(0);
    fval.pb(1);
    forn(i,0,1000000) fval.pb((fval[i]+fval[i+1])%mod);
    m2 fib;
    m2 finv;
    finv.x[0][0] = mod-1; finv.x[0][1] = 1;
    finv.x[1][0] = 1; finv.x[1][1] = 0;
    fib.x[0][0] = 0; fib.x[0][1] = 1;
    fib.x[1][0] = 1; fib.x[1][1] = 1;
    fp.resize(2);
    fpinv.resize(2);
    fp[0].x[0][0] = 1; fp[0].x[1][1] = 1;
    fp[0].x[0][1] = 0; fp[0].x[1][0] = 0;
    id = fp[0];
    fp[1] = fib;
    fpinv[1] = finv;
    fpinv[0] = fp[0];
    m2 cur = fib;
    m2 curi = finv;
    forn(i,2,A+1) {
        cur = prod(cur, fib);
        curi = prod(curi, finv);
        fp.pb(cur);
        fpinv.pb(curi);
    }
    
    int n,m;
    scanf("%d %d", &n, &m);
    vi a(n);
    stree st;
    forn(i,0,n) scanf("%d", &a[i]);
    st.build(a, 1, 0, n-1);
    st.dfs(1, 0, n-1);
    forn(i,0,m) {
        int t,x,y;
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1) {
            st.set(1, 0, n-1, x-1,y);
        }
        else if(t==2) {
            x--; y--;
            pll res = st.get(1, 0, n-1, x, y);
            res.first%=mod;
            res.second%=mod;
            m2 lul;
            lul.x[0][0] = res.second;
            lul.x[1][0] = res.first;
            lul.x[0][1] = res.first;
            lul.x[1][1] = res.first + res.second;
            
            lul = prod(lul, fpinv[x]);
//            cout<<lul.x[0][0]<<' '<<lul.x[0][1]<<'\n'<<lul.x[1][0]<<' '<<lul.x[1][1]<<endl<<endl;
//            res = prod(res, fpinv[x]);
//            ll ans = res.x[0][0] + res.x[1][0];
//            printf("%lld %lld\n", res.first, res.second);
            printf("%lld\n", lul.x[0][1]);
        }
        else if(t==3) {
            int d;
            scanf("%d", &d);
            st.update(1, 0, n-1, x-1, y-1, d);
        }
    }
    return 0;
}