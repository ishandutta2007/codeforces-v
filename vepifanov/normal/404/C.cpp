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
vii res;
vi v[100000];

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        v[x].pb (i + 1);
    }
    if (sz (v[0]) != 1) {
        printf ("-1\n");
        re 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < sz (v[i]); j++)
            if (m == 0 || j / m >= sz (v[i - 1])) {
                printf ("-1\n");
                re 0;
            } else res.pb (mp (v[i - 1][j / m], v[i][j]));
        if (i == 1) m--;
    }
    printf ("%d\n", sz (res));
    for (int i = 0; i < sz (res); i++)
        printf ("%d %d\n", res[i].fi, res[i].se);
    return 0;
}