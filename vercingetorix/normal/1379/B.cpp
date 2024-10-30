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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(af,0,t) {
        ll l,r,m;
        cin>>l>>r>>m;
        int good = 0;
        forn(a,l, r+1) {
            if(m%a <= r-l && m%a < m) {
                cout << a << ' ' << l+m%a << ' ' << l << endl;
                break;
            }
            if(a -(m%a) <= r-l) {
                cout << a << ' ' << l << ' ' << l + (a-m%a) << endl;
                break;
            }
        }
//        forn(n,1, m+r-l+1) {
//            if (n*l >= m) {
//                if (n*l-m <= r-l) {
//                    cout << l << ' ' << l << ' ' << l + n *l - m << endl;
//                    break;
//                }
//            }
//            else if (n*r <= m) {
//                if (m-n*r <= r-l) {
//                    cout << r << ' ' << r << ' ' << r + n *r - m << endl;
//                    break;
//                }
//            }
//            else {
//                ll f = m / n;
//                if (m-n*f <= r-l) {
//                    cout << f << ' ' << r << ' ' << r + n * f - m << endl;
//                    break;
//                }
//                f += 1;
//                if (n*f-m <= r-l) {
//                    cout << f << ' ' << l << ' ' << l + n *f - m << endl;
//                    break;
//                }
//            }
//        }
    }
}