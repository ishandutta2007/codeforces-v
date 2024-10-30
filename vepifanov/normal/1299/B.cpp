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
int x[100001];
int y[100001];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d%d", &x[i], &y[i]);
	x[n] = x[0];
	y[n] = y[0];
	if (n & 1) {
		printf ("NO\n");
		re 0;
	}
	n /= 2;
	for (int i = 0; i < n; i++)
		if ((x[i + 1] - x[i]) != (x[i + n] - x[i + n + 1]) || (y[i + 1] - y[i]) != (y[i + n] - y[i + n + 1])) {	
			printf ("NO\n");
			re 0;
		}
	printf ("YES\n");
	re 0;
}