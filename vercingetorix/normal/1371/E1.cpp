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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vi a;
int n,p;

int g(int s) {
    int r = 0;
    int l = 0;
    int can = 1;
    while(r < n) {
        while(r < n and a[r] <= s) {
            r += 1;
        }
        if (r > l) {
            s += 1;
            if (r-l >= p) can = 2;
            l += 1;
        }
        else return 0;
    }
    return can;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>n>>p;
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    sort(all(a));
    int l = 0;
    int r = a[n-1];
    while(r-l > 1) {
        int m = (r+l)/2;
        if (g(m) == 0) {
            l = m;
        }
        else r = m;
    }
    int mpos = r;
    l = 0;
    r = a[n-1];
    while(r-l > 1) {
        int m = (r+l)/2;
        if (g(m) == 2) {
            r = m;
        }
        else l = m;
    }
    cout << r-mpos<<endl;
    if (r > mpos) {
        cout << mpos;
        forn(i,mpos+1,r) cout<<' '<<i;
    }
}