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
    scanf("%d %d %d", &n, &m, &k);
    vvi a(n, vi(m, 0));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
    if(n > 20) {
        vi stamp(1,0);
        forn(j,1,m) {
            int dif = 0;
            int sam = 0;
            forn(i,0,n) if(a[i][j-1] == a[i][j]) sam++;
            else dif++;
            if(sam > dif) stamp.pb(stamp.back());
            else stamp.pb(stamp.back()^1);
        }
        int ans = 0;
        forn(i,0,n) {
            int dif = 0;
            int sam = 0;
            forn(j,0,m) if(a[i][j] == stamp[j]) sam++;
            else dif++;
            ans += min(sam, dif);
        }
        if(ans > k) ans = -1;
        printf("%d\n", ans);
    }
    else if(m > 20){
        vi stamp(1,0);
        forn(i,1,n) {
            int dif = 0;
            int sam = 0;
            forn(j,0,m) if(a[i][j] == a[i-1][j]) sam++;
            else dif++;
            if(sam > dif) stamp.pb(stamp.back());
            else stamp.pb(stamp.back()^1);
        }
        int ans = 0;
        forn(j,0,m) {
            int dif = 0;
            int sam = 0;
            forn(i,0,n) if(a[i][j] == stamp[i]) sam++;
            else dif++;
            ans += min(sam, dif);
        }
        if(ans > k) ans = -1;
        printf("%d\n", ans);
    }
    else {
        int best = 500;
        forn(mask,0,1<<(m-1)) {
            int cur = mask;
            vi stamp(1,0);
            forn(i,0,m-1) {
                stamp.pb(stamp.back()^(cur%2));
                cur/=2;
                
            }
            int ans = 0;
            forn(i,0,n) {
                int dif = 0;
                int sam = 0;
                forn(j,0,m) if(a[i][j] == stamp[j]) sam++;
                else dif++;
                ans += min(sam, dif);
            }
            best = min(best, ans);
        }
        if(best > k) best = -1;
        cout<<best;
    }
    
    
}