#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
vi v, w;
string s;

int main () {
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'R')
            v.pb (i);
        else
        if (s[i] == 'L')    
            w.pb (i);
    if (sz (v) == 0) printf ("%d %d\n", w[sz (w) - 1] + 1, w[0]); else 
    if (sz (w) == 0) printf ("%d %d\n", v[0] + 1, v[sz (v) - 1] + 2); else 
            printf ("%d %d\n", v[0] + 1, v[sz (v) - 1] + 1);
    return 0;
}