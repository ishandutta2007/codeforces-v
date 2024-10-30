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
vi v;

int calc (string s, int t) {
    int cur = 0;
    for (int i = 0; i < sz (s); i++) {
        int x = 0;
        if (s[i] >= '0' && s[i] <= '9') x = s[i] - '0'; else x = s[i] - 'A' + 10;
        if (x >= t) re -1;
        cur = cur * t + x;
    }
    re cur;
}

int main () {
    string s;
    cin >> s;
    for (int i = 0; i < sz (s); i++)
        if (s[i] == ':')
            s[i] = ' ';
    stringstream in (s);
    string a, b;
    in >> a >> b;
    for (int k = 2; k < 100; k++) {
        int x = calc (a, k);
        int y = calc (b, k);
        if (x >= 0 && x < 24 && y >= 0 && y < 60) v.pb (k);
    }
    if (sz (v) == 0) printf ("0\n"); else 
    if (v[sz (v) - 1] == 99) printf ("-1\n"); else {
        for (int i = 0; i < sz (v); i++) printf ("%d ", v[i]);
        printf ("\n");
    }
    return 0;
}