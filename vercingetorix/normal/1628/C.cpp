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
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        vvi a(n, vi(n));
        forn(i,0,n) forn(j,0,n) scanf("%d", &a[i][j]);
        int ans = 0;
        auto add = [&](int i, int j) {
            ans ^= a[i][j];
        };
        forn(j,0,n) {
            if(n%4 == 0 && (j % 4 == 1 || j % 4 == 2)) {
                forn(i,0,n) ans ^= a[i][j];
            }
            if(n%4 == 2 && (j % 4 == 0 || j % 4 == 1)) {
                forn(i,0,n) ans ^= a[i][j];
            }
        }
        forn(i,0,n) forn(j,0,n) {
            if(i+j < n) {
                if(n%4 == 0) {
                    if((i+j)%4 == 0 || (i+j) %4 == 1) ans ^= a[i][j];
                }
                else if(n%4 == 2) {
                    if((i+j)%4 == 0 || (i+j) %4 == 3) ans ^= a[i][j];
                }
            }
            if(j + n- 1 -i < n) {
                if(n%4 == 0) {
                    if((j + n- 1 -i)%4 == 0 || (j + n- 1 -i) %4 == 1) ans ^= a[i][j];
                }
                else if(n%4 == 2) {
                    if((j + n- 1 -i)%4 == 0 || (j + n- 1 -i) %4 == 3) ans ^= a[i][j];
                }
            }
        }
        printf("%d\n", ans);
    }
    
    
}