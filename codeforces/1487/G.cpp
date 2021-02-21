
// Problem : G. String Counting
// Contest : Codeforces - Educational Codeforces Round 104 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1487/problem/G
// Memory Limit : 1024 MB
// Time Limit : 10000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
	Normie's Template v2.0
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
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
ll dp[401][401][3][3];
ll dp2[401][401][3][3];
ll smaller[412][412];
ll con[26];
ll n,m,i,j,k,t,t1,u,v,a,b,c;
int main()
{
	fio;
	cin>>n;
	for (i=0;i<26;i++) cin>>con[i];
	dp[0][0][0][0]=1;
	for (t=0;t<n;t++)
	{
		for (i=0;i<=t+1;i++) for (j=0;j<=t+1;j++) for (a=0;a<3;a++) for (b=0;b<3;b++) 
		dp2[i][j][a][b]=0;
		for (i=0;i<=t;i++) for (j=0;j<=t;j++) 
		{
			for (a=0;a<3;a++) for (b=0;b<3;b++) for (c=0;c<3;c++)
			{
				if ((a==c)and(t>=2))
				{
					if (c==0) dp2[i][j][b][c]+=dp[i][j][a][b]*23;
				}
				else 
				{
					if (c==0) dp2[i][j][b][c]+=dp[i][j][a][b]*24;
					if (c==1) dp2[i+1][j][b][c]+=dp[i][j][a][b]*1;
					if (c==2) dp2[i][j+1][b][c]+=dp[i][j][a][b]*1;
				}
			}
		}
		for (i=0;i<=t+1;i++) for (j=0;j<=t+1;j++) for (a=0;a<3;a++) for (b=0;b<3;b++) 
		{
		dp[i][j][a][b]=dp2[i][j][a][b]%=MOD;
	//	cout<<i<<' '<<j<<' '<<a<<' '<<b<<' '<<dp[i][j][a][b]<<endl;
		}
	}
	for (i=n;i>=0;i--) for (j=n;j>=0;j--)
	{
		for (a=0;a<3;a++) for (b=0;b<3;b++) smaller[i][j]+=dp[i][j][a][b];
		smaller[i][j]+=smaller[i][j+1];
		smaller[i][j]+=smaller[i+1][j];
		smaller[i][j]-=smaller[i+1][j+1];
		smaller[i][j]+=MOD;
		smaller[i][j]%=MOD;
	}
	u=smaller[0][0];
//	cout<<u<<endl;
	for (i=0;i<26;i++)
	{
		u-=(smaller[con[i]+1][0]+MOD)%MOD;
		u+=MOD;
		u%=MOD;
	}
	for (i=0;i<26;i++) for (j=i+1;j<26;j++)
	{
		u+=(smaller[con[i]+1][con[j]+1]+MOD)%MOD;
		u+=MOD;
		u%=MOD;
	}
	cout<<u;
}