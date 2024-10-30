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

const ll N=1e5+10,mod=1e9+7;

ll a[N],b[N];

ll ppow(ll x,ll y)
{
    if(!y)
        return 1;
    if(y&1)
        return (ppow(x,y-1)*x)%mod;
    ll p=ppow(x,y>>1);
    return (p*p)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll j=0;j<n;j++)
        cin>>b[j];
    ll p=0,q=1;
    for(ll i=n-1;i>=0;i--)
    {
        ll tp,tq;
        if(a[i]==0)
            if(b[i]==0) /// a=0 , b=0
                tp=m-1,tq=2*m;
            else /// a=0 , b!=0
                tp=m-b[i],tq=m;
        else
            if(b[i]==0) /// a!=0 , b=0
                tp=a[i]-1,tq=m;
        if(a[i]!=0&&b[i]!=0)
        {
            if(a[i]>b[i])
                p=1,q=1;
            else if(a[i]<b[i])
                p=0,q=1;
        }
        else
        {
            q=(q*m)%mod;
            p=(p*tq+tp*q)%mod;
            q=(q*tq)%mod;
        }
    }
    //cout<<p<<" "<<q<<"\n";
    cout<<(p*ppow(q,mod-2))%mod;
}