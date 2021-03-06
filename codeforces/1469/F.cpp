
// Problem : Power Sockets
// Contest : Codeforces
// URL : https://m1.codeforces.com/contest/1469/problem/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
ll add[400001];
ll n,m,i,j,k,t,t1,u,v,a,b,cnt,l,r,mid;
vector<ll> lis;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>u;
		lis.push_back(u);
	}
	sort(lis.begin(),lis.end(),[](int a, int b){return (a>b);});
	l=2,r=310000;
	while(l<r)
	{
		int mid=(l+r)/2;
		for (i=0;i<=400000;i++) add[i]=0;
		add[1]=-1;
		cnt=1;
		k=1;
		u=1;
		i=0;
	//	cout<<l<<' '<<r<<' '<<mid<<endl;
		for (int g : lis)
		{
			while(!u)
			{
				i++;
				if (i>mid) break;
				k+=add[i];
				u=k;
			}
			if (i+2>mid) break;
					v=min((mid-(i+2)+1)*2,g-1);
		//	cout<<i<<' '<<u<<' '<<k<<' '<<cnt<<' '<<g<<' '<<v<<endl;
					if (v-1>0)
					{
							cnt+=v-1;
							add[i+2]+=2;
							if (v%2)
							{
								add[i+2+v/2]--;
								add[i+3+v/2]--;
							}
							else
							{
								add[i+2+v/2]-=2;
							}
							u--;
					}
		}
		if (cnt>=m) r=mid; else l=mid+1;
	}
	if (l==310000) cout<<-1; else cout<<l;
}