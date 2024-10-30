#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
int p[50], cnt[50];
vector<pair<int, int> > res;

int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	if (n < m) {
		printf ("NO\n");
		return 0;
	}
	for (int i = 0; i < n; i++) p[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		cnt[a]++;
		cnt[b]++;
		int u = p[a], v = p[b];
		for (int j = 0; j < n; j++)
			if (p[j] == v) p[j] = u;
		if (cnt[a] > 2 || cnt[b] > 2) {
			printf ("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < n - m; i++) {
		int a = -1, b = -1;
		for (int j = 0; j < n; j++)
			if (cnt[j] < 2) {
				a = j;
				break;
			}
		if (a == -1) { printf ("NO\n"); return 0; }
		cnt[a]++;
		for (int j = 0; j < n; j++)
			if (cnt[j] < 2 && p[j] != p[a]) {
				b = j;
				break;
			}
		if (b == -1)
			for (int j = 0; j < n; j++)
				if (cnt[j] < 2) {
					b = j;
					break;
				}
		if (b == -1) { printf ("NO\n"); return 0; }
		cnt[b]++;
		res.push_back (make_pair (a + 1, b + 1));
		int u = p[a], v = p[b];
		for (int j = 0; j < n; j++)
			if (p[j] == v) p[j] = u;
	}
	for (int i = 0; i < n; i++)
		if (p[i] != p[0]) {
			printf ("NO\n");
			return 0;
		}
	printf ("YES\n%d\n", n - m);
	for (int i = 0; i < n - m; i++) printf ("%d %d\n", res[i].first, res[i].second);
	return 0;
}