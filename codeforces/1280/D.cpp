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
vector<int> gt[3001];
const ll brah=(1LL<<45);
ll n,m,i,j,k,t,t1,u,v,a,b;
ll dp[3001][3001];
ll tmp[3001];
ll sz[3001];
ll brr[3001],wrr[3001];
void dfs(ll x, ll p)
{
    for (auto g : gt[x]) if (g-p)
    {
        dfs(g,x);
        memset(tmp,0,sizeof(tmp));
        int ii,jj;
        ll u;
        for (ii=0;ii<sz[x];ii++) 
        for (jj=0;jj<sz[g];jj++)
        {
            u=dp[x][ii]+dp[g][jj];
            u-=brah;
            tmp[ii+jj]=max(tmp[ii+jj],u);
            u=dp[x][ii]+(((dp[g][jj]-1)>>45)<<45)+brah;
            u-=brah;
            tmp[ii+jj+1]=max(tmp[ii+jj+1],u);
        }
        memcpy(dp[x],tmp,sizeof(tmp));
        sz[x]+=sz[g];
    }
  //  cout<<"dp "<<x<<endl;
 //   for (int i=0;i<sz[x];i++) if (dp[x][i]%brah<=3e12) cout<<(dp[x][i]>>45)-1<<' '<<dp[x][i]%brah<<endl;
  //  else cout<<(dp[x][i]>>45)<<' '<<(dp[x][i]%brah)-brah<<endl;
}
int main()
{
	fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
        cin>>n>>m; 
        for (i=1;i<=n;i++) memset(dp[i],0,sizeof(dp[i]));
        for (i=1;i<=n;i++)
        {
            cin>>brr[i];
        }
        for (i=1;i<=n;i++)
        {
            cin>>wrr[i];
            dp[i][0]=brah+wrr[i]-brr[i];
            sz[i]=1;
        }
        for (i=1;i<=n;i++) gt[i].clear();
        for (i=1;i<n;i++)
        {
            cin>>a>>b;
            gt[a].push_back(b);
            gt[b].push_back(a);
        }
            dfs(1,-1);
        cout<<((dp[1][m-1]-1)>>45)<<endl;
    }
}
