#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

vector<int> g[N];
int ans;

bool dfs(int v,int p)
{
    int l=0,b=0;
    for(int to:g[v])
        if(to!=p)
            if(dfs(to,v))
                b++;
            else
                l++;
    if(l&&v!=1)
        ans--;
    if(!l)
        ans++;
    return l;
}

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
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ans=0;
        dfs(1,-1);
        cout<<ans<<"\n";
    }
}