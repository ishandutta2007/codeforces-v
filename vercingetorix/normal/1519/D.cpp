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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vll a(n);
    vll b(n);
    forn(i,0,n) scanf("%lld", &a[i]);
    forn(i,0,n) scanf("%lld", &b[i]);
    vll pref(1,0);
    forn(i,0,n) pref.pb(pref.back() + ll(a[i])*b[i]);
    ll ans = pref.back();
    ll def = ans;
    forn(md,0,n) {
        int l = md;
        int r = md;
        ll cand = def;
        while(1) {
            l--;
            r++;
            if(l < 0 || r >= n) break;
            cand += a[r]*b[l] + a[l]*b[r] - a[l]*b[l] - a[r]*b[r];
            ans = max(ans, cand);
        }
    }
    forn(md,0,n-1) {
        int r = md;
        int l = md+1;
        ll cand = def;
        while(1) {
            l--;
            r++;
            if(l < 0 || r >= n) break;
            cand += a[r]*b[l] + a[l]*b[r] - a[l]*b[l] - a[r]*b[r];
            ans = max(ans, cand);
        }
    }
    cout<<ans;
    
}