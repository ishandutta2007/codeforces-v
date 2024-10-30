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
ll x[100000];

int main () {
    scanf ("%d%d", &n, &m); m--;
    ll tmp = 2e9;
    for (int i = 0; i < n; i++) {
        scanf ("%I64d", &x[i]);
        tmp = min (tmp, max ((ll)0, x[i] - 1));
    }
    for (int i = 0; i < n; i++) x[i] -= tmp;
    ll ans = tmp * n;
    while (true) {
        if (x[m] == 0) {
            x[m] = ans;
            break;
        }
        x[m]--;
        ans++;
        m = (m - 1 + n) % n;
    }
    for (int i = 0; i < n; i++) printf ("%I64d ", x[i]);
    printf ("\n");
    return 0;
}