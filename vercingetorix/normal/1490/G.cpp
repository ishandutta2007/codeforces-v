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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a,n);
        vpll e;
        ll sum = a[0];
        e.pb(mp(sum, 0ll));
        forn(i,1,n) {
            sum += a[i];
            if(sum > e.back().first) e.pb(mp(sum, i));
        }
        forn(i,0,m) {
            int xd;
            scanf("%d", &xd);
            ll x = xd;
            if(sum <= 0) {
                auto it = lower_bound(all(e), mp(x, 0ll));
                if(it == e.end()) printf("-1 ");
                else printf("%d ", (int)it->second);
            }
            else {
                ll addo = 0;
                if(e.back().first < x) {
                    ll st = (x - e.back().first + sum - 1) / sum;
                    addo += st*n;
                    x -= st*sum;
                }
                auto it = lower_bound(all(e), mp(x, 0ll));
                printf("%lld ", addo + it->second);
            }

        }
        printf("\n");
    }
    
}