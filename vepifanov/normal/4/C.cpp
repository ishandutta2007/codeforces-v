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
map<string, int> all;
char w[40];

int main() {
	int n;
	scanf ("%d\n", &n);
	for (int i = 0; i < n; i++) {
		gets (w);
		string s(w);
		if (all.find (s) != all.end ()) {
			cout << s << all[s] << endl;
			all[s]++;
		} else {
			cout << "OK" << endl;
			all[s] = 1;
		}
	}
	return 0;
}