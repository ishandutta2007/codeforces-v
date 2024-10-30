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
vll d2(1,1);
vs ans;

ll aplus(ll x, ll y) {
    ans.pb(to_string(x) + " + " + to_string(y));
    return x + y;
}

ll axor(ll x, ll y) {
    ans.pb(to_string(x) + " ^ " + to_string(y));
    return x ^ y;
}

void go(ll x) {
    if(x % 4 == 3) {
        aplus(x, x);
        axor(x, 2*x);
        x = x^(2*x);
    }
    if(x == 1) return;
    int l = 1;
    while(x>=d2[l]) l++;
    forn(i,0,l) ans.pb(to_string(x*d2[i]) + " + " + to_string(x*d2[i]));
    ll A = aplus(x*d2[l-1], x);
    ll B = axor(x*d2[l-1], x);
    axor(A, B);
    while(l>0) {
        if(x&d2[l]) x = axor(x,d2[l]);
        if(x==1) break;
        ll y = x;
        while(y > 0) {
            y = aplus(y, y);
            if(y & d2[l]) y = axor(y, d2[l]);
        }
        
        l--;
    }
//    ll f = x ^ (x*d2[l-1]);
//    ans.pb(to_string(x) + " ^ " + to_string(x*d2[l-1]));
//    forn(k,l,2*l) {
//        if(f&d2[k] == 0) continue;
//        ll cool = d2[k] / x + 1;
//        ll cur = 0;
//        forn(j,0,l+2) if(cool&d2[j]) {
//            if(cur != 0) ans.pb(to_string(x*cur) + " + " + to_string(x*d2[j]));
//            cur += d2[j];
//        }
//        cool *= x;
//        ans.pb(to_string(f) + " ^ " + to_string(cool));
//        f ^= cool;
//    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,60) d2.pb(d2.back() * 2);
    ll x;
    cin>>x;
    go(x);
    
    printf("%d\n", ans.size());
    for(auto s : ans) printf("%s\n", s.c_str());
}