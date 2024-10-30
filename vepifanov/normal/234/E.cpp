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
pair<int, string> v[64];
vector<pair<int, string> > w[4];
int x, a, b, c;

int main () {
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    cin >> n >> x >> a >> b >> c;
    for (int i = 0; i < n; i++) cin >> v[i].se >> v[i].fi;
    m = n / 4;
        sort (v, v + n);
        reverse (v, v + n);
        for (int i = 0; i < n; i++) w[i / m].pb (v[i]);
        for (int i = 0; i < m; i++) {
            printf ("Group %c:\n", 'A' + i);
            for (int j = 0; j < 4; j++) {
                x = (x * a + b) % c;
                int y = x % (m - i);
                printf ("%s\n", w[j][y].se.c_str ());
                w[j].erase (w[j].begin () + y);
            }
        }
        return 0;
}