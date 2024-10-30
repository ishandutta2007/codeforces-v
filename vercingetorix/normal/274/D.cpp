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
    int n,m;
    scanf("%d %d", &n, &m);
    vvi a(n, vi(m, 0));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
    vi ans;
    vvpi rnum(n);
    forn(i,0,n) forn(j,0,m) if(a[i][j] != -1) rnum[i].pb(mp(a[i][j], j));
    forn(i,0,n) srt(rnum[i]);
    vi pt(n,0);
    vi nban(m,0);
    vi q;
    auto unban = [&] (int j) {
        forn(i,0,n) if(a[i][j] != -1) {
            pt[i]++;
            if(pt[i] != rnum[i].size() && rnum[i][pt[i]].first != rnum[i][pt[i]-1].first) {
                int f = pt[i];
                while(f < rnum[i].size() && rnum[i][f].first == rnum[i][pt[i]].first) {
                    nban[rnum[i][f].second]--;
                    if(nban[rnum[i][f].second] == 0) q.pb(rnum[i][f].second);
                    f++;
                }
            }
        }
    };
    forn(j,0,m) {
        forn(i,0,n) if(a[i][j] != -1 && a[i][j] != rnum[i][pt[i]].first) nban[j]++;
        if(nban[j] == 0) q.pb(j);
    }
    while(!q.empty()) {
        int v = q.back();
        ans.pb(v);
        q.pop_back();
        unban(v);
    }
    if(ans.size() != m) cout<<-1;
    else {
        forn(i,0,m) printf("%d ", ans[i]+1);
    }
    
}