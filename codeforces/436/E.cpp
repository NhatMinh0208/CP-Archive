/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#define N 300005
int n,m,mx,a[N],b[N];
int tot=0,cnt=0;
int vis[N];
bool useout[N];
string s;
ll ans=0;
struct cost
{
    int v,ct,id;
    cost (int V=0,int Ct=0,int Id=0)
    {
        v=V,ct=Ct,id=Id;
    }
    bool operator < (const cost &A) const
    {
        return v<A.v || v==A.v && ct>A.ct;
    }
    bool operator > (const cost &A) const
    {
        return v>A.v || v==A.v && ct<A.ct;
    }
};
priority_queue<cost,vector<cost> ,greater<cost> >q;
priority_queue<cost>q2;
int main()
{  
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i],&b[i]);
        q.push(cost(a[i] << 1,1,i));
        q.push(cost(b[i],2,i));
    }
    for (int i=0;i<n;++i)
        s+='0';
    while (m)
    {
        if (m==1)
        {
            int les=1000000007;
            while (!q2.empty() && (useout[abs(q2.top().id)] && q2.top().id>0))
                q2.pop();
            if (q2.empty())
                mx=-1000000007; else
                mx=q2.top().v;
            int cid=0;
            while (!q.empty() && q.top().ct==2 || q.top().id>0 && vis[q.top().id])
            {
                if (q.top().ct==2 && (q.top().id<0 || !vis[q.top().id]) && les>q.top().v)
                    les=q.top().v,cid=q.top().id;
                q.pop();
            }
            if ((mx+q.top().v) >> 1>les)
                ans-=mx >> 1,ans+=les,--s[abs(q2.top().id)-1],s[abs(cid)-1]='2'; else
                ans+=q.top().v >> 1,++s[abs(q.top().id)-1];
            break;
        }
        cost u=q.top();
        q.pop();
        if (u.id>0 && vis[u.id])
            continue;
        if (u.id>0)
            vis[u.id]=u.ct; else
        if (u.ct==2 || u.id<0)
            useout[abs(u.id)]=true;
        m-=u.ct;
        if (u.ct==1)
        {
            q2.push(u);
            ans+=u.v >> 1;
            if (u.id>0)
                s[abs(u.id)-1]='1',q.push(cost((b[u.id]-a[u.id]) << 1,1,-u.id)); else
                s[abs(u.id)-1]='2';
        } else
            s[abs(u.id)-1]='2',ans+=u.v,q2.push(cost((b[u.id]-a[u.id]) << 1,1,-u.id));
    }
    printf("%lld\n",ans);
    cout << s << endl;
}