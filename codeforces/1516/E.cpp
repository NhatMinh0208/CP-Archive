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
vector<ll> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll dp[202][202][202];
ll loc[202][202];
ll fac[100001],inv[100001];
ll exte[402];
ll res[202];
int main()
{
	fio;
	cin>>m>>n;
	fac[0]=1;
	inv[0]=1;
	for (i=1;i<=100000;i++)
	{
		fac[i]=(fac[i-1]*i)%MOD;
		inv[i]=INV(fac[i],MOD);
	}
	for (i=2;i<=n+1;i++) 
	{
		loc[i][0]=1;
		for (j=1;j<=n;j++)
		{
			loc[i][j]=loc[i][j-1];
			loc[i][j]*=fac[i*j-1]; loc[i][j]%=MOD;
			loc[i][j]*=inv[i*j-i]; loc[i][j]%=MOD;
			loc[i][j]*=inv[i-1]; loc[i][j]%=MOD;
		}
		u=1;
		for (j=1;j<=n;j++)
		{
			u=(u*fac[i-1])%MOD;
			loc[i][j]=(loc[i][j]*u)%MOD;
		}
	}
	dp[0][0][1]=1;
	for (k=2;k<=n+1;k++) for (i=0;i<=200;i++) for (j=0;j<=200;j++)
	for (t=0;((t+i<=200)and(t*(k-1)+j<=200));t++)
	{
		dp[i+t][j+t*(k-1)][k]+=dp[i][j][k-1]*fac[i+j+k*t]%MOD*inv[i+j]%MOD*inv[k*t]%MOD*loc[k][t]%MOD;
		dp[i+t][j+t*(k-1)][k]%=MOD;
	}
	exte[0]=1;
	for (i=1;i<=min(m,2*n);i++)
	{
		exte[i]=exte[i-1];
		exte[i]*=m-i+1;
		exte[i]%=MOD;
		exte[i]*=INV(i,MOD);
		exte[i]%=MOD;
	//	cout<<"Ext "<<i<<' '<<exte[i]<<endl;
	}
	for (i=0;i<=200;i++) for (j=0;j<=200;j++) if ((j<=n)and(i+j<=m)) { 
		//if (n<=10) cout<<i<<' '<<j<<' '<<dp[i][j][n+1]<<endl;
		 res[j]+=dp[i][j][n+1]*exte[i+j]; res[j]%=MOD;}
	a=b=0;
	b=res[0]%MOD;
	for (i=1;i<=n;i++) if (i%2) {a=(a+res[i])%MOD; cout<<a<<' ';} else {b=(b+res[i])%MOD; cout<<b<<' ';}
}
