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
string s;

int main () {
    cin >> s;
    for (int a = 3; a <= 4; a++)
        for (int b = 1; a + b + 2 <= sz (s); b++) {
            int c = sz (s) - a - b - 2;
            if (s.substr (0, a) == "http" || s.substr (0, a) == "ftp")
                if (s.substr (a + b, 2) == "ru") {
                    if (c == 0) {
                        cout << s.substr (0, a) << "://" << s.substr (a, b) << ".ru" << endl;
                        re 0;
                    } else {
                        cout << s.substr (0, a) << "://" << s.substr (a, b) << ".ru/" << s.substr (a + b + 2, c) << endl;
                        re 0;
                    }
                }
        }
    return 0;
}