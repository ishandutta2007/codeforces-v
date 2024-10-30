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

const int B = 320;
const int A = 100001;
const int C = A*(10+B);
int d[2*C];
int a[A];
int cand[2*A];
int touch[A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    forn(i,0,n) read(a[i]);
    int best = 0;
    forn(step,-B, B+1) {
        int add = C;
        forn(i,0,n) {
            best = max(best, ++d[a[i]+add]);
            add+=step;
        }
        add = C;
        forn(i,0,n) {
            d[a[i]+add] = 0;
            add+=step;
        }
    }
    forn(l,0,n) {
        forn(r,l+1,min(l+B,n)) if((a[r] - a[l])%(r-l) == 0){
            int cur = (a[r]-a[l])/(r-l);
            touch[r-l] = A+cur;
            best = max(best, 1+(++cand[A+cur]));
        }
        forn(r,l+1,min(l+B,n)) {
            cand[touch[r-l]] = 0;
        }
    }
    cout<<n-best;
}