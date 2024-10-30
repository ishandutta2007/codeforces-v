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


ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int k;
    char c[1000000];
    scanf("%d\n", &k);
    scanf("%s", c);
    string s(c);
    vi d2(1,1);
    forn(i,0,20) d2.pb(d2.back()*2);
    int n = s.size();
//    reverse(all(s));
    vi t(n+1, 0);
    forn(i,0,n+1) t.pb(1);
    for(int i = n; i>=1; i--) {
        if(s[n-i] == '1') t[i] = t[2*i];
        else if(s[n-i] == '0') t[i] = t[2*i+1];
        else t[i] = t[2*i]+t[2*i+1];
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int i;
        char x;
        scanf("%d %c", &i, &x);
        i--;
        s[i] = x;
        i = n-i;
        while(i>0) {
            if(s[n-i] == '1') t[i] = t[2*i];
            else if(s[n-i] == '0') t[i] = t[2*i+1];
            else t[i] = t[2*i]+t[2*i+1];
            i/=2;
        }
        printf("%d\n", t[1]);
    }
    
    
    
}