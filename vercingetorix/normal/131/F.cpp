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
    int n,m,k;
    scanf("%d %d %d\n", &n, &m, &k);
    if(n<3 || m<3) {
        cout<<0;
        exit(0);
    }
    vs b;
    char c[555];
    forn(i,0,n) {
        scanf("%s", c);
        b.pb(string(c));
    }
    n-=2;
    m-=2;
    vvi a(n, vi(m,0));
    forn(i,0,n) forn(j,0,m) {
        if(b[i+1][j] == '1' && b[i][j+1] == '1' && b[i+2][j+1] == '1' && b[i+1][j+2] == '1' && b[i+1][j+1] == '1') a[i][j] = 1;
    }
    forn(i,1,n) forn(j,0,m) a[i][j] += a[i-1][j];
    ll ans = 0;
    forn(u,0,n) {
        forn(d,u,n) {
            int r = 0;
            int cur = 0;
            while(r < m && cur < k) {
                cur += a[d][r++];
            }
            forn(l,0,m) {
                if(cur<k) break;
                ans += m+1-r;
                cur-=a[d][l];
                while(r < m && cur < k) {
                    cur += a[d][r++];
                }
                
            }
        }
        forn(i,u+1,n) forn(j,0,m) a[i][j] -= a[u][j];
    }
    cout<<ans;
    
    
}