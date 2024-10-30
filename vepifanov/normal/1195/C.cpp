#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
int x[100000];
int y[100000];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	for (int i = 0; i < n; i++) scanf ("%d", &y[i]);
	ll bx = 0, by = 0;
	for (int i = 0; i < n; i++) {
		ll nx = max (bx, by + x[i]);
		ll ny = max (by, bx + y[i]);
		bx = nx;
		by = ny;
	}
	cout << max (bx, by) << endl;
	re 0;
}