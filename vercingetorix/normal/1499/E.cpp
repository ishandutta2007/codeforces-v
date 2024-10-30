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

const long long mod = 998244353 ;
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

ll d[26][1001][1001];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[1001];
    scanf("%s", c);
    string x(c);
    scanf("%s", c);
    string y(c);
    int k = x.size();
    int l = y.size();
    forn(i,0,26) d[i][k][l] = 1;
    ll ans = 0;
    for(int i = k; i>=0; i--) {
        for(int j= l; j>=0; j--) {
            if(i==k && j==l) continue;
            forn(lc,0,26) {
                d[lc][i][j] = 1;
                if(j!=l) {
                    if(lc != y[j]-'a') d[lc][i][j] += d[int(y[j]-'a')][i][j+1];
                    
                }
                if(i!=k) {
                    if(lc != x[i]-'a') d[lc][i][j] += d[int(x[i]-'a')][i+1][j];
                    
                }
                d[lc][i][j] %= mod;
            }
            if(i!=k && j!=l) {
                ans += d[int(y[j]-'a')][i][j+1] + mod - d[int(y[j]-'a')][k][j+1];
                ans += d[int(x[i]-'a')][i+1][j] + mod - d[int(x[i]-'a')][i+1][l];
                ans %= mod;
            }
            
        }
        
    }
    cout<<ans;
}