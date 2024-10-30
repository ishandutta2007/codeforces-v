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
    int n,h;
    scanf("%d %d", &n, &h);
    readv(a,n);
    vi b = a;
    srt(b);
    if(n==2) {
        printf("0\n");
        printf("1 2\n");
        exit(0);
    }
    int f = b[n-1]+b[n-2]-b[0]-b[1];
    int s = max(b[n-1]+b[0]+h, b[n-1]+b[n-2]) - min(b[1]+b[2], b[0]+b[1]+h);
    if(f <= s) {
        printf("%d\n", f);
        forn(i,0,n) printf("1 ");
        printf("\n");
    }
    else {
        int pt = 0;
        while(a[pt] != b[0]) pt++;
        printf("%d\n", s);
        forn(i,0,n) {
            if(i==pt) printf("1 ");
            else printf("2 ");
        }
        printf("\n");
    }
    
    
}