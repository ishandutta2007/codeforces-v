#include<bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<#x<<"="<<x<<"\n"
#else
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

#define it iterator
#define rit reverse_iterator
#define mp make_pair
#define mems(a,b) memset(a,b,sizeof(a))
#define mem0(a) mems(a,0)
#define mem1(a) mems(a,1)
#define mem255(a) mems(a,255)
#define halt exit(0)
#define all(c) (c).begin() , (c).end()
#define sz(c) ((long long)((c).size()))
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
#define fort0(i,a,b) for(ll i=a,i##_TO=b;i<i##_TO;i++)
#define for0(i,n) fort0(i,0,n)
#define fort1(i,a,b) for(ll i=a,i##_TO=b;i<=i##_TO;i++)
#define for1(i,n) fort1(i,1,n)
#define ford(i,a,b) for(ll i=a,i##_TO=b;i>=i##_TO;i--)
#define forc(i,c) for(auto _N_##i##_=c.begin(),i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++);\
                      i!=c.end();\
                      i=(_N_##i##_==c.end())?_N_##i##_:(_N_##i##_++))
#define forr(i,c) for(auto _N_##i##_=c.rbegin(),i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++);\
                      i!=c.rend();\
                      i=(_N_##i##_==c.rend())?_N_##i##_:(_N_##i##_++))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef array<int,26> info;

const int N=3e5;

vector<int> g[N];
int u[N];
info res[N];
string s;

info dfs(int v)
{
    if(u[v]==1)
        cout<<-1,exit(0);
    if(u[v]==2)
        return res[v];
    u[v]=1;
    info& tres=res[v];
    for(int to:g[v])
    {
        info t=dfs(to);
        for(int i=0;i<26;i++)
            tres[i]=max(tres[i],t[i]);
    }
    tres[s[v]-'a']+=1;
    u[v]=2;
    return tres;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].phb(y);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        info t=dfs(i);
        for(int j=0;j<26;j++)
            ans=max(ans,t[j]);
    }
    cout<<ans;
}