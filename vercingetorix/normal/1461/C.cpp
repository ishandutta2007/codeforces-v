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
#include <math.h>
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
    cin>>t;
    forn(aff,0,t) {
        long double f;
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a,n);
        int mgood = n-1;
        while(mgood >= 0 && a[mgood] == mgood + 1) mgood--;
        
        long double pbad = 1;
        long double plog = 0;
        int good = 0;
        forn(i,0,m) {
            int l;
            scanf("%d %Lf", &l, &f);
            
            if (l>mgood) {
                if (f > 0.99999999) {
                    good = 1;
                }
                else {
                    plog += log(1-f);
                }
                pbad *= (1-f);
            }
        }
        if(mgood == -1) {
            cout<<1<<endl;
            continue;
        }
        if(good == 1) {
            cout<<1<<endl;
        }
        else {
            printf("%.15Lf\n", 1-exp(plog));
        }
        
    }
}