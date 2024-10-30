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
    int n;
    read(n);
    vvi a(n, vi(n));
    forn(i,0,n) {
        forn(j,0,n) read(a[i][j]);
    }
    readv(b,n);
    vi loc(n+1,0);
    forn(i,0,n) loc[b[i]] = i;
    vpi ans(n, mp(n,-1));
    int p1 = 0;
    int p2 = 0;
    loc[0] = n;
    forn(i,1,n+1) {
        if(loc[i] < loc[p1]) {
            p2 = p1;
            p1 = i;
        }
        else if(loc[i] < loc[p2]) {
            p2 = i;
        }
        forn(j,0,n) {
            if(p1 != j+1) {
                forn(k,0,n) if(a[j][k] == p1) if(k < ans[j].first) ans[j] = mp(k, i);
            }
            else {
                forn(k,0,n) if(a[j][k] == p2) if(k < ans[j].first) ans[j] = mp(k, i);
            }
        }
//        forn(i,0,n) printf("%d ", ans[i].second); printf("\n");
    }
    forn(i,0,n) printf("%d ", ans[i].second);
    
}