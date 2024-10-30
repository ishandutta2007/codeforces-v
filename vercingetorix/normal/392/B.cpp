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
ll d[3][3][50];
ll c[3][3];

void rel(int l) {
    forn(it,0,5) {
        forn(i,0,3) forn(j,0,3) {
            if(i==j) continue;
            int k = 3-i-j;
            d[i][j][l] = min(d[i][j][l], d[i][k][l] + d[k][j][l]);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,3) forn(j,0,3) scanf("%lld", &d[i][j][1]);
    forn(i,0,3) forn(j,0,3) c[i][j] = d[i][j][1];
    rel(1);
    forn(l,2,41) {
        forn(i,0,3) forn(j,0,3) {
            if(i==j) continue;
            int k = 3-i-j;
            d[i][j][l] = d[i][k][l-1] + c[i][j] + d[k][j][l-1];
            ll cand = d[i][j][l-1] + c[i][k] + d[j][i][l-1] + c[k][j] + d[i][j][l-1];
            d[i][j][l] = min(d[i][j][l], cand);
        }
        rel(l);
    }
    int n;
    cin>>n;
    cout<<d[0][2][n];
    
    
}