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
int x[100001], cnt[100001];

int main () {
    scanf ("%d", &n);
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        if (x[i] & 1) c1++; else c0++;
    }
    sort (x, x + n);
    for (int i = 0; i + 2 < n; i++)
        if (x[i] != x[i + 1] && x[i + 1] != x[i + 2]) {
            printf ("NO\n");
            re 0;
        }
    for (int i = 0; i + 1 < n; i++)
        if (x[i] <= x[i + 1] - 2) {
            printf ("NO\n");
            re 0;
        }
    if (c0 == c1) printf ("YES\n"); else printf ("NO\n");
    return 0;
}