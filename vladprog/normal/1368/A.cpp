#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        int ans=0;
        while(a<=n&&b<=n)
        {
            ans++;
            if(a<b)
                a+=b;
            else
                b+=a;
        }
        cout<<ans<<"\n";
    }
}