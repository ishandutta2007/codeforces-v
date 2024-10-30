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
vi pos, neg;
int zero = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) pos.pb (x);
        if (x < 0) neg.pb (x);
        if (x == 0) zero = 1;
    }
    sort (all (neg));
    if (sz (pos) > 0 || sz (neg) > 1) {
        for (int i = 0; i < sz (pos); i++) cout << pos[i] << " ";
        for (int i = 0; i + 1 < sz (neg); i += 2) cout << neg[i] << " " << neg[i + 1] << " ";
        cout << endl;
    } else 
    if (zero) {
        cout << "0" << endl;
    } else {
        cout << neg[0] << endl;
    }
    return 0;
}