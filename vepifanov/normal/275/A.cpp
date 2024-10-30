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
int g[3][3];

int main () {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf ("%d", &g[i][j]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int ok = g[i][j] + 1;
            if (i > 0) ok += g[i - 1][j];
            if (j > 0) ok += g[i][j - 1];
            if (i < 2) ok += g[i + 1][j];
            if (j < 2) ok += g[i][j + 1];
            printf ("%d", ok & 1);
        }
        printf ("\n");
    }
    return 0;
}