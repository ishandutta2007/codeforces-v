#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define mp make_pair
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front

using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int r,b,k;
        cin>>r>>b>>k;
        int g=__gcd(r,b);
        r/=g,b/=g;
        if(r>b)
            swap(r,b);
        int c=(b+r-2)/r;
        cout<<(c<k?"OBEY":"REBEL")<<"\n";
    }
}