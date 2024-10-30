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

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int a,b,k;
    cin>>k>>a>>b;
    int an = a/k;
    int bn = b/k;
    int ak = a%k;
    int bk = b%k;
    if(an>0 && bn>0) {
        cout<<an+bn;
        return 0;
    }
    else if (an == 0 && bn == 0) {
        cout<<-1;
        return 0;
    }
    else if(an == 0) {
        if (bk > 0) cout<<-1;
        else cout<<bn;
        return 0;
    }
    else if(bn == 0) {
        if (ak > 0) cout<<-1;
        else cout<<an;
        return 0;
    }
    
}