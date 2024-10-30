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
int g[2000][2000];
int cnt[2001];
string s;

int main () {
    cin >> s;
    n = sz (s);
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            if (i == j)
                g[i][j] = 1;
            else
            if (i + 1 == j) 
                g[i][j] = int (s[i] == s[j]);
            else
                g[i][j] = int (s[i] == s[j]) * g[i + 1][j - 1];
    for (int i = n - 1; i >= 0; i--) {
        cnt[i] = cnt[i + 1];
        for (int j = i; j < n; j++)
            cnt[i] += g[i][j];
    }   
    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            ans += g[i][j] * cnt[j + 1];
    cout << ans << endl;
    return 0;
}