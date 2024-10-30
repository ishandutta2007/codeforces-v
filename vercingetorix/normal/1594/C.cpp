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
    int t;
    scanf("%d\n", &t);
    char c[300500];
    while(t-- ) {
        int n;
        char b;
        scanf("%d %c\n", &n, &b);
        scanf("%s", c);
        int nc = 0;
        forn(i,0,n) if(c[i] != b) nc++;
        if(nc == 0) {
            printf("0\n");
            continue;
        }
        int can = 0;
        forn(l,1,n+1) {
            int cc = 0;
            for(int i = l-1; i < n; i += l) if(c[i] != b) cc++;
            if(cc == 0) {
                can = 1;
                printf("1\n");
                printf("%d\n", l);
                break;
            }
        }
        if(can == 0) {
            printf("2\n");
            printf("%d %d\n", n-1, n);
        }
        
        
    }
    
    
}