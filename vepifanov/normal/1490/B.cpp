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
int cnt[3];

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d", &n);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			cnt[x % 3]++;
		}
		int ans = 0;
		for (int i = 0; i < 6; i++) {
			int tmp = max (0, cnt[i % 3] - n / 3);
			ans += tmp;
			cnt[i % 3] -= tmp;
			cnt[(i + 1) % 3] += tmp;
		}
		printf ("%d\n", ans);
	}
	re 0;
}