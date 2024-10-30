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

int main() {
    string s;
    cin >> s;
    int a = 0, b = 0, n = sz (s);   
    for (int i = 0; i < n; i++) {
        a += int (s[i] >= 'a' && s[i] <= 'z');
        b += int (s[i] >= 'A' && s[i] <= 'Z');
    }
    for (int i = 0; i < n; i++)
        s[i] = s[i] - int (s[i] >= 'A' && s[i] <= 'Z' && a >= b) * ('A' - 'a') - int (s[i] >= 'a' && s[i] <= 'z' && a < b) * ('a' - 'A');

    cout << s << endl;
    return 0;
}