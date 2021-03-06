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
int n,m,i,j,k,t,t1,u,v,a,b,l,r;
int val[200001];
int spmax[200001][20];
int spmin[200001][20];
int getmax(int l, int r)
{
	int br=floor(log2(r-l+1));
	return max(spmax[l][br],spmax[r-(1<<br)+1][br]);
}
int getmin(int l, int r)
{
	int br=floor(log2(r-l+1));
	return min(spmin[l][br],spmin[r-(1<<br)+1][br]);
}
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		for (i=1;i<=n;i++)
		{
			char c;
			cin>>c;
			val[i]=val[i-1];
			if (c=='+') val[i]++;
			else val[i]--;
		}
		for (j=0;j<20;j++)
		{
			for (i=0;i<=n;i++)
			{
				if (j==0) spmax[i][j]=val[i];
				else 
				{
					spmax[i][j]=spmax[i][j-1];
					if (i+(1<<(j-1))<=n) spmax[i][j]=max(spmax[i][j],spmax[i+(1<<(j-1))][j-1]);
				}
			}
		}
		for (j=0;j<20;j++)
		{
			for (i=0;i<=n;i++)
			{
				if (j==0) spmin[i][j]=val[i];
				else 
				{
					spmin[i][j]=spmin[i][j-1];
					if (i+(1<<(j-1))<=n) spmin[i][j]=min(spmin[i][j],spmin[i+(1<<(j-1))][j-1]);
				}
			}
		}
		for (i=1;i<=m;i++)
		{
			cin>>l>>r;
			l--;
			u=getmin(0,l);
			v=getmax(0,l);
			a=getmin(r,n)-val[r]+val[l];
			b=getmax(r,n)-val[r]+val[l];
			cout<< max(b,v)-min(u,a)+1<<endl;
		}
	}
}