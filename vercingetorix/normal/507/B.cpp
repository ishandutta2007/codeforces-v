#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll r,x,y,x2,y2;
    cin>>r>>x>>y>>x2>>y2;
    double dist=sqrt((double)((x-x2)*(x-x2)+(y-y2)*(y-y2)));
    int ans = (int) floor(dist/(double)(2*r));
    if(((x-x2)*(x-x2)+(y-y2)*(y-y2)) > 4*r*r*ans*ans) ans++;
    cout<<ans;
    
}