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
char w[200];
int x[3];

int main() {
    for (int i = 0; i < 3; i++) {
        gets (w);
        for (int j = 0; w[j]; j++)
            if (w[j] == 'a' || w[j] == 'e' || w[j] == 'i' || w[j] == 'u' || w[j] == 'o')
                x[i]++;
    }
    if (x[0] == 5 && x[1] == 7 && x[2] == 5) printf ("YES\n"); else printf ("NO\n");
    return 0;
}