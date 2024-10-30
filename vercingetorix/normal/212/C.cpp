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

const int A = 104;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    string s;
    cin>>s;
    int n = s.size();
    vi fix(n,0);
    forn(i,0,n) if(s[i] == s[(i+1)%n]) {
        if(s[i] == 'A') fix[(i+1)%n] = 1;
        else fix[i] = 1;
    }
    int sum = 0;
    forn(i,0,n) sum += fix[i];
    if(sum == 0) {
        int k = n/2;
        vvll d(2, vll(2, 0));
        d[0][0] = 1;
        d[1][1] = 1;
        forn(i,0,k-1) {
            vvll nd(2, vll(2, 0));
            forn(f,0,2) forn(last,0,2) forn(nx,0,2) {
                if(last + nx >= 1) {
                    nd[f][nx] += d[f][last];
                }
            }
            swap(d, nd);
        }
        ll ans = 0;
        forn(f,0,2) forn(last,0,2) if(f + last >= 1) ans += d[f][last];
        cout<<ans;
        exit(0);
    }
    ll ans = 1;
    forn(i,0,n) {
        int j = (i+1)%n;
        if(fix[i] && fix[j] && s[i] == 'A' && s[j] == 'B') {
            cout<<0;
            exit(0);
        }
    }
    forn(i,0,n) if(fix[i] == 1 && fix[(i+1)%n] == 0) {
        int len = 0;
        int l = i;
        int pt = (i+1)%n;
        while(fix[pt] == 0) {
            len++;
            pt = (pt+1)%n;
        }
        int r = pt;
        int k = len/2;
        if(s[l] == 'A') k--;
        if(s[r] == 'B') k--;
        if(k > 0) {
            vll d(2, 1);
            forn(it,0,k-1) {
                vll nd(2, 0);
                forn(was,0,2) forn(nx,0,2) if(was+nx>=1) nd[nx] += d[was];
                swap(d,nd);
            }
            ans *= (d[0] + d[1]);
        }
    }
    cout<<ans;
    
}