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

ll n;
int m;

int main () {
    cin >> n;
    ll r1 = 1e18, r2 = 0;
    for (ll a = 1; a * a * a <= n; a++)
        if (n % a == 0)
            for (ll b = a; a * b * b <= n; b++)
                if (n % (a * b) == 0) {
                    ll c = n / (a * b);
                    ll d = (a + 1) * (b + 2) * (c + 2) - n;
                    r1 = min (r1, d);
                    r2 = max (r2, d);
                    d = (a + 2) * (b + 1) * (c + 2) - n;
                    r1 = min (r1, d);      
                    r2 = max (r2, d);
                    d = (a + 2) * (b + 2) * (c + 1) - n;
                    r1 = min (r1, d);
                    r2 = max (r2, d);
                }
    cout << r1 << " " << r2 << endl;
    return 0;
}