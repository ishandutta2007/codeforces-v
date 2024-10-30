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

const int MAXN = 100000;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,a,b;
    scanf("%d %d %d", &n, &a, &b);
    readv(vx,n);
    int l = -1;
    int r = 1000000000;
    while(r-l > 1) {
        int m = (r+l)/2;
        if(abs(a-b) > m) {
            l = m;
            continue;
        }
        int pos = b;
        set<int> can;
        can.insert(a);
        for(auto x : vx) {
            while(!can.empty()) {
                auto it = can.begin();
                if(abs(*it - x) > m) can.erase(it);
                else break;
            }
            while(!can.empty()) {
                auto it = can.end();
                it--;
                if(abs(*it - x) > m) can.erase(it);
                else break;
            }
            if (abs(x-pos) <= m) can.insert(pos);
            pos = x;
            if(can.empty()) break;
        }
        if(can.empty()) l = m;
        else r = m;
    }
    cout<<r;
}