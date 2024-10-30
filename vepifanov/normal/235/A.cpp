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

ll gcd (ll a, ll b) { re a ? gcd (b % a, a) : b; }

int main () {
    cin >> n;
    ll ans = 0;
    for (ll a = n; a >= n - 100 && a > 0; a--)
        for (ll b = a; b >= n - 100 && b > 0; b--)
            for (ll c = b; c >= n - 100 && c > 0; c--) {
                ll tmp = a * b / gcd (a, b);
                tmp = tmp * c / gcd (tmp, c);
                ans = max (ans, tmp);
            }
    cout << ans << endl;
    return 0;
}