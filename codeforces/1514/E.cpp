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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int answer[101][101];
int reg[101];
int ask1(int x, int y)
{
	cout<<1<<' '<<x-1<<' '<<y-1<<endl;
	int xx;
	cin>>xx;
	if (xx==-1) assert(0);
	else return xx;
}
int ask2(int x, vector<int> y)
{
	cout<<2<<' '<<x-1<<' '<<y.size();
	for (auto g : y) cout<<' '<<g-1;
	cout<<endl;
	int xx;
	cin>>xx;
	if (xx==-1) assert(0);
	else return xx;
}
int ans()
{
	cout<<3<<endl;
	for (int i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++) cout<<answer[i][j];
		cout<<endl;
	}
	int xx;
	cin>>xx;
	if (xx==-1) assert(0);
	else return xx;
}
vector<int> get_path(int l, int r)
{
	if (l==r) return {l};
	else 
	{
		vector<int> res;
		int mid=(l+r)/2;
		vector<int> a=get_path(l,mid);
		vector<int> b=get_path(mid+1,r);
		merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(res),[](int a, int b){
			return (ask1(a,b));
		});
		return res;
	}
}
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		vec=get_path(1,n);
		vector<int> sta,bruh;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) answer[i][j]=0;
	//	for (auto g : vec) cout<<g<<' '; cout<<endl;
		for (i=0;i<n;i++)
		{
			while(sta.size())
			{
				bruh.clear();
				for (j=0;j<=sta[sta.size()-1];j++)
				{
					bruh.push_back(vec[j]);
				}
				if (ask2(vec[i],bruh)) sta.pop_back();
				else break;
			}
				sta.push_back(i);
		}
	//	for (auto g : sta) cout<<g<<' '; cout<<endl;
		j=0;
		for (i=0;i<sta.size();i++)
		{
			for (j=j;j<=sta[i];j++) {reg[vec[j]]=i; }
		}
	//	for (i=1;i<=n;i++) cout<<reg[i]; cout<<endl;
		for (i=1;i<=n;i++) for (j=1;j<=n;j++) if (reg[i]<=reg[j]) answer[i][j]=1;
		ans();
	}
}
