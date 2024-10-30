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
    int ta;
    read(ta);
    char c[1000500];
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vs boa;
        forn(i,0,n) {
            scanf("%s", c);
            boa.pb(string(c));
        }
        int ans = 0;
        forn(r2,0,2) {
            vvi a(n);
//            forn(i,0,n) forn(j,0,m) {
//                if((i+j)%2==r2 && boa[i][j] == '1') a[i].pb(j);
//            }
            forn(i,0,n) for(int j= m-1; j>=0; j--) {
                if((i+j)%2==r2 && boa[i][j] == '1') a[i].pb(j);
            }
            forn(aefit,0,m) {
                vpi left;
                forn(i,0,n) if(!a[i].empty()) left.pb(mp(a[i].back(), i));
                if(left.empty()) break;
                ans++;
                srt(left);
                set<pi> taken;
                taken.insert(mp(-10000000,r2));
                taken.insert(mp(10000000,r2));
                for(auto x : left) {
                    int i = x.second;
                    int l = x.first;
                    auto it = taken.lower_bound(mp(i,l));
                    int can = 1;
                    if(l-it->second > it->first - i) can=0;
                    it--;
                    if(l-it->second > i - it->first) can=0;
                    if(can) {
                        a[i].pop_back();
                        taken.insert(mp(i,l));
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    
    
}