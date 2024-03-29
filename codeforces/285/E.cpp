// Problem: E. Positions in Permutations
// Contest: Codeforces - Codeforces Round #175 (Div. 2)
// URL: https://codeforces.com/contest/285/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define MOD (ll(1000000007))
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
const int maxn=1e3+10;
ll fact[maxn],inv[maxn],dp[maxn][maxn][2][2];
ll C(int n,int m)
{
	return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int n,k;
int main()
{
	fio;
	cin>>n>>k;
	fact[0]=1;
	for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%MOD;
	for(int i=0;i<=n;i++)inv[i]=INV(fact[i],MOD);
	dp[1][0][1][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=n;j++)
	for(int a=0;a<=1;a++)
	for(int b=0;b<=1;b++)
	if(dp[i][j][a][b])
	{
		dp[i+1][j][b][0]=(dp[i+1][j][b][0]+dp[i][j][a][b])%MOD;
		dp[i+1][j+1][b][1]=(dp[i+1][j+1][b][1]+dp[i][j][a][b])%MOD;
		if(!a)dp[i+1][j+1][b][0]=(dp[i+1][j+1][b][0]+dp[i][j][a][b])%MOD;
	}
	ll ans=0;
	for(int i=k;i<=n;i++)
	{
		int t=((i-k)%2==0)?1:-1;
		ll sum=(dp[n+1][i][1][0]+dp[n+1][i][0][0])%MOD;
		ans+=t*C(i,k)*fact[n-i]%MOD*sum%MOD;
		ans=(ans%MOD+MOD)%MOD;
	}
	cout<<ans;
}
