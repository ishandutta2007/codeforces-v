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

int h, r;

int can (ld x, ld y) {
    ld d = sqrt (x * x + y * y);
    if (y < 0 || d < r / 2.0 + 1e-10) re 1;
    re 0;
}
       
int main () {
    scanf ("%d%d", &r, &h);
    int k = h / r;
    if (can (r / 2.0, (k + 0.5) * r - h)) {
        if (can (0, (k + 1 + sqrt (3.0 / 4) - 0.5) * r - h)) printf ("%d\n", 2 * k + 3); else printf ("%d\n", 2 * k + 2);
    } else
    if (k == 0) printf ("1\n"); else
    if (can (0, (k + sqrt (3.0 / 4) - 0.5) * r - h)) printf ("%d\n", 2 * k + 1); else printf ("%d\n", 2 * k);
    return 0;
}