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
int cnt[10];
string s;
int x[1000000];

int go (int i, int cur, int f) {
    if (i == n) {
        if (cur == 0) {
            for (int j = 0; j < n; j++)
                printf ("%d", x[j]);
            printf ("\n");
            re 1;
        }   
        re 0;
    }
    vii u;
    for (int j = 0; j < 10; j++) u.pb (mp (cnt[j], j));
    sort (all (u));
    reverse (all (u));
    for (int j = 0; j < 10; j++)
        if (u[j].fi > 0 && (f || u[j].se)) {
            cnt[u[j].se]--;
            x[i] = u[j].se;
            if (go (i + 1, (cur * 10 + u[j].se) % 7, f | int (u[j].se != 0))) re 1;
            cnt[u[j].se]++;
        }
    re 0;
}

int main () {
    cin >> s;
    n = sz (s);
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
    if (!go (0, 0, 0)) printf ("0\n");
    return 0;
}