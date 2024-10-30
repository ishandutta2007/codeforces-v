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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    int k;
    scanf("%d %d", &n, &k);
    vi need(5,0);
    vi cnt(5,0);
    cnt[2] += 2*n;
    cnt[4] += n;
    forn(i,0,k) {
        int x;
        scanf("%d", &x);
        need[4] += x/4;
        x = x%4;
        if(x>=2) need[2]++;
        if(x%2) need[1]++;
    }
    int do4 = min(need[4], cnt[4]);
    need[4] -= do4;
    cnt[4] -= do4;
    if(need[4] > 0) {
        cnt[2] -= 2*need[4];
        need[4] = 0;
    }
    int do2 = min(need[2], cnt[2]);
    cnt[2] -= do2;
    need[2] -= do2;
    if(need[2] > 0) {
        int do21 = min(need[2], need[1]);
        if(cnt[4] < do21) {
            cout<<"NO";
            return 0;
        }
        cnt[4] -= do21;
        need[2] -= do21;
        need[1] -= do21;
        if(need[2] > 0) {
            do2 = min(cnt[4], need[2]);
            cnt[2] -= do2;
            cnt[1] += do2;
            need[2] -= do2;
            if(need[2] > 0) {
                if(cnt[1] < 2*need[2]) {
                    cout<<"NO";
                    return 0;
                }
                cnt[1] -= 2*need[2];
                need[2] = 0;
            }
        }
    }
    need[1] -= min(need[1], cnt[1]);
    need[1] -= min(need[1], cnt[2]);
    need[1] -= min(need[1], 2*cnt[4]);
    if(need[1] > 0) cout<<"NO";
    else cout<<"YES";
    
    
}