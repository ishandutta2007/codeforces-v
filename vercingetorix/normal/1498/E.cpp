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

char c[1000];
bool ask(pi x) {
    int u = x.first;
    int v = x.second;
    printf("? %d %d\n", u+1, v+1);
    fflush(stdout);
    scanf("%s", c);
    if(c[0]=='Y') return true;
    else return false;
}

void win(pi x) {
    printf("! %d %d\n", x.first+1, x.second+1);
    exit(0);
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int n;
    scanf("%d", &n);
    readv(k,n);
    vector<pair<int, pi>> q;
    pi can(-1,-1);
    forn(i,0,n) forn(j,i+1,n) {
        if(k[i] > k[j]) q.pb(mp(k[j]-k[i], mp(i, j)));
        else if(k[i] < k[j]) q.pb(mp(k[i]-k[j], mp(j, i)));
        else if(k[i] == k[j]) can = mp(i,j);
    }
    srt(q);
    for(auto x : q) {
        if(ask(x.second)) {
            win(x.second);
        }
    }
    win(can);
    
    
    
}