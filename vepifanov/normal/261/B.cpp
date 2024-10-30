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
map<vi, double> all;
vi v;

double go (int n, int m) {
    if (all.find (v) != all.end ()) re all[v];
    double cur = 0;
    for (int i = 1; i <= m; i++)
        if (v[i]) {
            v[i]--;
            cur += (go (n - 1, m - i) + 1) * (v[i] + 1) / n;
            v[i]++;
        }
    re all[v] = cur;
}

int main () {
    scanf ("%d", &n);
    v.resize (51);
    for (int i = 0; i < n; i++) {
        int x;
        scanf ("%d", &x);
        v[x]++;
    }
    scanf ("%d", &m);
    printf ("%.10f\n", go (n, m));
    return 0;
}