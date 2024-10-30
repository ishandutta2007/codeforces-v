#include <bits/stdc++.h>

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
        int n;
        cin>>n;
        map<int,int> cnt;
        while(n--)
        {
            int x;
            cin>>x;
            cnt[abs(x)]++;
        }
        int ans=0;
        for(auto[x,y]:cnt)
            ans+=min(y,x==0?1ll:2ll);
        cout<<ans<<"\n";
    }
}