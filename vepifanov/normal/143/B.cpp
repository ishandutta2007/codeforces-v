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
string s;

int main () {
    cin >> s;
    int neg = 0;
    if (s[0] == '-') {
        neg = 1;
        s.erase (0, 1);
    }
    int k = sz (s);
    for (int i = 0; i < sz (s); i++)
        if (s[i] == '.')
            k = i;
    if (k == sz (s)) s += '.';
    while (sz (s) - k < 3) s += '0';
    while (sz (s) - k > 3) s.erase (sz (s) - 1, 1);
    if (neg) printf ("(");
    printf ("$");
    for (int i = 0; i < k; i++) {
        if (i > 0 && (k - i) % 3 == 0) printf (",");
        printf ("%c", s[i]);
    }
    printf (".%c%c", s[k + 1], s[k + 2]);   
    if (neg) printf (")");
    return 0;
}