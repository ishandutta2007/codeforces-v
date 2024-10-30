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
string s;
vector<pair<string, ii> > v;
int g[5000][5000];

int go (int pos, int l, int r, int m, string res) {
    if (sz (v[l].fi) == pos) l++;
    for (int c = 'a'; c <= 'b'; c++) {
        int s = l, cur = 0, tmp = 0;
        while (s <= r && v[s].fi[pos] == c) {
            tmp += g[v[s].se.fi][v[s].se.fi + pos];
            cur += v[s].se.se;
            s++;
        }
//      printf ("%c: %d %d %d %d\n", c, l, s, tmp, cur);
        if (tmp >= m) {
            res += c;
            cout << res << endl;
            re 0;
        }
        if (cur >= m) {
            for (int i = l; i < s; i++)
                v[i].se.se -= g[v[i].se.fi][v[i].se.fi + pos];
            res += c;
            go (pos + 1, l, s - 1, m - tmp, res);
            re 0;
        }
        m -= cur;
        l = s;
    }
    re 0;
}

int main () {
    cin >> s >> m;
    n = sz (s);
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            if (j - i <= 3)
                g[i][j] = int (s[i] == s[j]);
            else    
                g[i][j] = int (s[i] == s[j] && g[i + 2][j - 2]);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i; j < n; j++)
            cur += g[i][j];
        v.pb (mp (s.substr (i, n - i), mp (i, cur)));
    }
    sort (all (v));
    go (0, 0, n - 1, m, "");
    return 0;
}