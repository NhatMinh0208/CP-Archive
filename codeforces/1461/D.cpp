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
ll arr[100001];
ll pre[100001];
vector<ll> sums;
ll n,m,i,j,k,t,t1,u,v,a,b;
void add (ll l, ll r)
{
	if (l>r) return;
	auto it1=lower_bound(arr,arr+n,l);
	auto it2=upper_bound(arr,arr+n,r);
	sums.push_back(pre[it2-arr]-pre[it1-arr]);
	if ((*it1)>r) return;
	l=(*it1);
	it2--;
	r=(*it2);
	int mid=(l+r)/2;
	if (l==r) return;
	else
	{
		add(l,mid);
		add(mid+1,r);
	}
	
}
int main()
{
	fio;
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n>>m;
		sums.clear();
		for (i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n);
		for (i=1;i<=n;i++)
		{
			pre[i]=pre[i-1]+arr[i-1];
		}
		add(arr[0],arr[n-1]);
		sort(sums.begin(),sums.end());
		for (i=1;i<=m;i++)
		{
			cin>>u;
			auto it=lower_bound(sums.begin(),sums.end(),u);
			if ((it!=sums.end())and((*it)==u)) cout<<"Yes"; else cout<<"No";
			cout<<endl;
		}
	}
}