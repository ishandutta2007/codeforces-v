#pragma GCC optimize("O3")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define DEBUG
#ifdef DEBUG
    #define IFD(...) __VA_ARGS__
    #define IFN(...)
    #define L cout<<__LINE__<<"\n";
    #define PRINT(...) __VA_ARGS__ cout<<__LINE__<" : "<<#__VA_ARGS__<<"\n"
    #define PRT(x) cout<<__LINE__<<" : "<<#x<<" = "<<x<<"\n"
#else // DEBUG
    #define IFD(...)
    #define IFN(...) __VA_ARGS__
    #define L
    #define PRINT(...) __VA_ARGS__
    #define PRT(x)
#endif // DEBUG

//#define it iterator
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

using namespace __gnu_pbds;
using namespace std;

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template
<
    class key,
    class val=null_type,
    class comp=less<key>
>
using ord_set=tree
<
    key,
    val,
    comp,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

const int N=1e5+10;
int p[N];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>p[i];
    set<pii> s;
    for(int i=0;i<n;i++)
    {
        int x=p[i];
        if(s.empty())
        {
            int l=x-k+1;
            if(l<0)
                l=0;
            s.insert(pii{l,x});
            x=l;
            cout<<x<<" ";
            continue;
        }
        auto it=s.upper_bound(pii{x,300});
        if(it==s.begin())
        {
            int l=x-k+1;
            if(l<0)
                l=0;
            s.insert(pii{l,x});
            x=l;
            cout<<x<<" ";
            continue;
        }
        it--;
        if(x<=it->second)
            x=it->first;
        else
        {
            int r=it->first+k-1;
            if(r>=x)
            {
                int l=it->first;
                s.erase(it);
                s.insert(pii{l,x});
                x=l;
            }
            else
            {
                int l=x-k+1;
                if(l<=it->second)
                    l=it->second+1;
                s.insert(pii{l,x});
                x=l;
            }
        }
        cout<<x<<" ";
    }
}