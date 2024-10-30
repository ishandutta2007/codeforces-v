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
    int n,m;
    scanf("%d %d", &n, &m);
    set<ll> h;
    vi a(m), b(m);
    forn(i,0,m) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
        if(a[i] > b[i]) swap(a[i], b[i]);
        h.insert(ll(n)*a[i] + b[i]);
    }
    forn(k,1,n) {
        if(n%k != 0) continue;
        bool good = true;
        forn(i,0,m) {
            int na = a[i] + k;
            int nb = b[i] + k;
            if(na >= n) na-=n;
            if(nb >= n) nb-=n;
            if(na > nb) swap(na, nb);
            if(h.find(ll(n)*na+nb) == h.end()) {
                good = false;break;
            }
        }
        if(good) {
            cout<<"Yes";
            exit(0);
        }
    }
    cout<<"No";
    
}