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
vi d2(1,1);
vi a;

int best(int lf, int rt) {
    if(lf>rt) return 0;
    if(lf==rt) return 1;
    int pt = lf;
    int cleft = 0;
    int ans = 0;
    for(int l = 30; l >= 0; l--) {
        int ptr = pt;
        while(ptr <= rt && (d2[l] & a[ptr])) ptr++;
        forn(i,pt,ptr) a[i] ^= d2[l];
        int cand = cleft + best(pt, ptr - 1);
        if(ptr<=rt) cand++;
        ans = max(ans, cand);
        if(ptr>pt) cleft++;
        pt = ptr;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    srtrev(a);
    
    forn(i,0,30) d2.pb(d2.back()*2);
    
    cout<<n-best(0,n-1);
    
}