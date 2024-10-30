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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n,m,k;
        scanf("%d %d %d", &n, &m, &k);
        if(n%2 == 0 && k%2 == 1) {
            printf("NO\n");
            continue;
        }
        if(n%2 == 0 && m%2 == 1 && n+2*k > m*n) {
            printf("NO\n");
            continue;
        }
        if(n%2 == 1 && k%2 != (m/2)%2) {
            printf("NO\n");
            continue;
        }
        if(n%2 == 1 && k < m/2) {
            printf("NO\n");
            continue;
        }
        vs ans(n, string(m, '.'));
        int nw =  n;
        if(n%2 == 1) {
            for(int i = 0; i < m; i+=2) {
                ans[n-1][i] = "yz"[(i/2)%2];
                ans[n-1][i+1] = "yz"[(i/2)%2];
            }
            k -= m/2;
            n--;
        }
        if(m%2 == 1) {
            for(int i = 0; i < n; i+=2) {
                ans[i][m-1] = "yz"[(i/2)%2];
                ans[i+1][m-1] = "yz"[(i/2)%2];
            }
            m--;
        }
        
        for(int i = 0; i < n; i+=2) {
            for(int j = 0; j < m; j+=2) {
                int ad = ((i/2+j/2)%2) * 2;
                if(k>0) {
                    ans[i][j] = "abcd"[ad];
                    ans[i][j+1] = "abcd"[ad];
                    ans[i+1][j] = "abcd"[ad+1];
                    ans[i+1][j+1] = "abcd"[ad+1];
                    k-=2;
                }
                else {
                    ans[i][j] = "abcd"[ad];
                    ans[i+1][j] = "abcd"[ad];
                    ans[i][j+1] = "abcd"[ad+1];
                    ans[i+1][j+1] = "abcd"[ad+1];
                }
            }
        }
        printf("YES\n");
        forn(i,0,nw) printf("%s\n", ans[i].c_str());
    }
    
}