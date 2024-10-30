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
#define prev PREV
                         
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
ii v[200000];

int main () {
    scanf ("%d", &n);
    for (int i = n - 1; i >= 0; i--) {
        scanf ("%d", &v[i].fi);
        v[i].se = i;
        v[i].fi -= i;
    }
    sort (v, v + n);
    reverse (v, v + n);
    for (int i = n - 1; i > 0; i--)
        if (v[i - 1].fi + (i - 1) < v[i].fi + i) {
            printf (":(\n");
            re 0;
        }
    for (int i = n - 1; i >= 0; i--) printf ("%d ", v[i].fi + i);
    printf ("\n");
    return 0;
}