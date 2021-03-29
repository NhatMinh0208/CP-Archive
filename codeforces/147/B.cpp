// Problem: B. Smile House
// Contest: Codeforces - Codeforces Testing Round #4
// URL: https://codeforces.com/problemset/problem/147/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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

//---------END-------//
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int minn[301][301][9];
int cur[301][301],cur2[301][301];
int main()
{
	fio;
	cin>>n>>m;
	for (t=0;t<=8;t++)for (i=1;i<=n;i++) for (j=1;j<=n;j++) minn[i][j][t]=1e7+7;
	for (t=0;t<=8;t++)for (i=1;i<=n;i++)  minn[i][i][t]=0;
	for (i=1;i<=n;i++) for (j=1;j<=n;j++) cur[i][j]=1e7+7;
	for (i=1;i<=n;i++)  cur[i][i]=0;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v>>a>>b;
		minn[u][v][0]=-a;
		minn[v][u][0]=-b;
	}
	for (t=1;t<=8;t++) 
	{
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) for (k=1;k<=n;k++) 
		{
			chkmin(minn[i][k][t],minn[i][j][t-1]+minn[j][k][t-1]);
		}
	}
	a=0;
	for (t=8;t>=0;t--)
	{
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) cur2[i][j]=1e7+7;
		for (i=1;i<=n;i++)  cur2[i][i]=0;
	//	cout<<"Attempt "<<t<<endl;
		//	for (i=1;i<=n;i++)
		//	{
		//		for (j=1;j<=n;j++) cout<<cur[i][j]<<' ';
		//		cout<<endl;
		//	}
		//	cout<<endl;
		//	for (i=1;i<=n;i++)
		//	{
		//		for (j=1;j<=n;j++) cout<<minn[i][j][t]<<' ';
		//		cout<<endl;
		//	}
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) for (k=1;k<=n;k++) 
		{
			chkmin(cur2[i][k],cur[i][j]+minn[j][k][t]);
		}
		//	cout<<endl;
		//	for (i=1;i<=n;i++)
		//	{
		//		for (j=1;j<=n;j++) cout<<cur2[i][j]<<' ';
		//		cout<<endl;
		//	}
		b=1;
		for (i=1;i<=n;i++) if (cur2[i][i]<0) b=0;
		if (b)
		{
			a^=(1<<t);
			for (i=1;i<=n;i++) for (j=1;j<=n;j++) cur[i][j]=cur2[i][j];
	//		cout<<"YES "<<a<<endl;
		}
	}
	if (a>=n) cout<<0; else cout<<a+1;
}