#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    map<char, int> u;
    string t = "AHIMOoTUVvWwXxY";
    for(auto c:t) u[c]++;
    string s;
    cin>>s;
    string ans = "TAK";
    n = s.size();
    forn(i,0,n) {
        char a = s[i];
        char b = s[n-1-i];
        if(a!=b) {
            string g(2,a);
            g[1]=b;
            if(g=="pq" || g=="qp" || g=="bd" || g =="db" ) {
                
            }
            else ans = "NIE";
        }
        else {
            if(u[a] == 0) ans = "NIE";
        }
    }
    cout<<ans;
    
}