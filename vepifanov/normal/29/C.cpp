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
int m = 0;
vi v[200000];
int w[200000];
map<int, int> all;

int get (int x) {
	int y = m;
	if (all.count (x)) y = all[x]; else m++;
	all[x] = y;
	w[y] = x;
	re y;
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b);
		int c = get (a);
		int d = get (b);
		v[c].pb (d);
		v[d].pb (c);
	}
	for (int i = 0; i < n; i++)
		if (sz (v[i]) == 1) {
			int x = i, l = 0;
			printf ("%d ", w[x]);
			for (int j = 0; j < n; j++) {
				int y = v[x][0];
				if (sz (v[x]) == 2) y += v[x][1] - l;
				l = x;
				x = y;
				printf ("%d ", w[x]);
			}
			printf ("\n");
			re 0;
		}
	return 0;
}