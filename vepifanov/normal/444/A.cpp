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
#include <cassert>

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
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
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
int v[500];

int main () {
    scanf ("%d%d", &n, &m);
    double ans = 0;
    for (int i = 0; i < n; i++) scanf ("%d", &v[i]);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        ans = max (ans, (v[a] + v[b] + 0.0) / c);
    }
    printf ("%.10f\n", ans);
    return 0;
}