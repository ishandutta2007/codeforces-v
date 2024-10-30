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
bool check(const string & s) {
    forn(i,0,s.size()) if(s[i]!=s[s.size()-1-i]) return true;
    return false;
}

vi build(int n, int m, int c, int s) {
    vi ret;
    s %= m ;
    ret.pb(s);
    forn(i,0,n-1) ret.pb((ret.back() + c)%m);
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    while(t--) {
        int n;
        read(n);
        readv(a,n);
        set<int> c;
        set<int> dec;
        forn(i,1,n) if(a[i] >= a[i-1]) c.insert(a[i]-a[i-1]);
        else dec.insert(a[i-1]-a[i]);
        if(c.size() > 1 || dec.size() > 1) printf("-1\n");
        else if(c.size() == 1 && dec.size() == 1) {
            if(build(n, *c.begin() + *dec.begin(), *c.begin(), a[0]) == a) printf("%d %d\n", *c.begin() + *dec.begin(), *c.begin());
            else printf("-1\n");
        }
        else printf("0\n");
    }
    
    
}