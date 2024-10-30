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

int p[1000], q[1000], e[1000];

int main () {
	scanf ("%d%d", &n, &m);	
	for (int i = 0; i < n; i++) p[i] = q[i] = -1;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		p[a] = b;
		q[b] = a;
		e[a] = c;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (q[i] == -1 && p[i] != -1)
			ans++;
	printf ("%d\n", ans);
	for (int i = 0; i < n; i++)
		if (q[i] == -1 && p[i] != -1) {
			int j = i, k = 1e9;
			while (p[j] != -1) {
				k = min (k, e[j]);
				j = p[j];
			}
			printf ("%d %d %d\n", i + 1, j + 1, k);
		}
	return 0;
}