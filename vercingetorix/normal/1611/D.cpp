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
        readv(b,n);
        forn(i,0,n) b[i]--;
        readv(p,n);
        forn(i,0,n) p[i]--;
        vi vis(n,-1);
        int pt = 0;
        while(b[pt] != pt) pt++;
        vis[pt] = 0;
        int mx = 0;
        if(p[0] != pt) {
            printf("-1\n");
            continue;
        }
        vi ans(n,0);
        int can = 1;
        forn(i,1,n) {
            int cur = p[i];
            if(vis[b[cur]] == -1) {
                can = 0;
                break;
            }
            ans[cur] = mx+1-vis[b[cur]];
            vis[cur] = ++mx;
        }
        if(can == 0) printf("-1\n");
        else {
            for(auto x : ans) printf("%d ", x);
            printf("\n");
        }
    }
    
    
}