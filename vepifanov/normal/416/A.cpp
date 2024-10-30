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

int main () {
    cin >> n;
    int l = -2e9, r = 2e9;
    for (int i = 0; i < n; i++) {
        string s, t;
        int x;
        cin >> s >> x >> t;
        if (s == ">") {
            s = ">=";
            x++;
        }
        if (s == "<") {
            s = "<=";
            x--;
        }
        if (s == "<=") {
            if (t == "Y") r = min (r, x); else l = max (l, x + 1);
        } else {
            if (t == "Y") l = max (l, x); else r = min (r, x - 1);
        }
    }
    if (l <= r) printf ("%d\n", l); else printf ("Impossible\n");
    return 0;
}