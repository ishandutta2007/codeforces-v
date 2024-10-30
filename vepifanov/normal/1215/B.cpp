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
vi v;
ll sum[200010];

int main () {
	scanf ("%d", &n);
	v.pb (0);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		if (x < 0) v.pb (i + 1);
	}
	v.pb (n + 1);
	ll ans = 0;
	for (int i = sz (v) - 2; i > 0; i--) {
		sum[i] = v[i + 1] - v[i];
		if (i + 2 <= sz (v) - 2) sum[i] += sum[i + 2];
		ans += (ll)(v[i] - v[i - 1]) * sum[i];
	}
	cout << ans << " " << (ll)n * (n + 1) / 2 - ans << endl;
	re 0;
}