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

int solve1(ll k) {
    ll d10 = 1;
    ll len = 1;
    while(len*d10*9 < k) {
        k -= len*d10*9;
        len++;
        d10*=10;
    }
    k--;
    ll num = d10 + k/len;
    k%=len;
    return to_string(num)[k] - '0';
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    scanf("%d", &q);
    while(q--) {
        ll k;
        scanf("%lld", &k);
        ll d10 = 1;
        int len = 1;
        ll nx = d10*10;
        ll bef = 0;
        while(1) {
            ll block = bef*d10*9 + len*(d10*9+1)*d10*9/2;
            if(block < k) {
                k-=block;
                bef += len*d10*9;
                d10*=10;
                len++;
            }
            else {
                ll l = 0;
                ll r = d10*9;
                while(r-l>1) {
                    ll m = (r+l)/2;
                    block = bef*m + len*(m+1)*m/2;
                    if(block < k) l = m;
                    else r = m;
                }
                block = bef*l + len*(l+1)*l/2;
                k -= block;
                printf("%d\n", solve1(k));
                break;
            }
        }
    }
    
    
}