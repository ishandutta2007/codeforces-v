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
const int N = 20000000;
int mindiv[N+1];
ll ans[N+1];
int cnt[N+1];
int sqf[N+1];

int pt;


vi getdiv(int n) {
    if(n==1) return vi(1,1);
    int p = mindiv[n];
    int deg = 1;
    n/=p;
    while(n%p == 0) {
        deg++;
        n/=p;
    }
    vi ret = getdiv(n);
    int k = ret.size();
    int dp = p;
    forn(i,0,deg) {
        forn(j,0,k) ret.pb(ret[j]*dp);
        dp*=p;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vector<ll> pr;
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    sqf[1] = 1;
    forn(i,2,N+1) {
        int m = i / mindiv[i];
        sqf[i] = sqf[m];
        if(mindiv[m] != mindiv[i]) sqf[i] *= mindiv[i];
    }
    int n;
    read(n);
    readv(a,n);
    forn(i,0,n) {
        for(auto x : getdiv(a[i])) cnt[x]++;
    }
    cnt[1] = n;
    ans[1] = n;
    ll res = n;
    forn(i,2,N+1) {
        int m = sqf[i];
        while(m!=1) {
            int p = mindiv[m];
            ans[i] = max(ans[i], ans[i/p] + ll(i-i/p)*cnt[i]);
            m/=p;
        }
        res = max(res, ans[i]);
    }
    cout<<res;

    
    
}