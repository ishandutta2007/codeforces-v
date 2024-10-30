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
const ll INF = 1e18;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,q;
        scanf("%d %d", &n,&q);
        vi a(n+2,0);
        forn(i,1,n+1) scanf("%d", &a[i]);
        ll cur = 0;
        forn(i,1,n+1) {
            if(a[i]>a[i-1] && a[i] > a[i+1]) cur+=a[i];
            else if(a[i]<a[i-1] && a[i] < a[i+1]) cur-=a[i];
        }
        printf("%lld\n", cur);
        auto sg = [&](int i) {
            if(a[i] > a[i-1] && a[i] > a[i+1]) return a[i];
            if(a[i] < a[i-1] && a[i] < a[i+1]) return -a[i];
            return 0;
        };
        while(q--) {
            int l,r;
            scanf("%d %d", &l, &r);
            set<int> ind;
            forn(i,l-1,l+2) if(i>0 && i<=n) ind.insert(i);
            forn(i,r-1,r+2) if(i>0 && i<=n) ind.insert(i);
            for(auto i : ind) cur -= sg(i);
            swap(a[l], a[r]);
            for(auto i : ind) cur += sg(i);
            printf("%lld\n", cur);
        }
    }
    
    
}