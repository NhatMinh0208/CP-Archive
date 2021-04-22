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
typedef int ll;
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

//---------END-------//
/*
	Normie's implementation of suffix array.
	This implementation will actually sort the cyclic shifts, so you should to put a marker that's lower than
	any character (e.g. '$') at the end of the string.
	Right now it's gonna be basic, with only sorting of the suffixes.
*/
struct suff
{
	vector<int> s; // The string we will be using
	int n; // Its length
	int ord[400011]; // The ordering of each suffix/cyclic shift in the current sorted list (pairwise distinct)
	int rank[400011]; // The eqivalency rank of each suffix/cyclic shift in the current sorted list
	int rank2[400011]; // A temporary storage for rank.
	vector<int> buc[400011]; // Buckets for use during algorithm. 
	int fin[400011]; // The current sorted suffix/cyclis shift array (suffixes are represented by starting index)
	int lcp[400011]; // The lcp array: Longest common prefix between 2 sufixes/cyclic shifts.
	void build(vector<int> ss)
	{
		// Initializing stuff. 
		s=ss;
		n=s.size();
		for (int i=0;i<n;i++) 
		{
			ord[i]=i;
			rank[i]=0;
		}
		// Sorts the cyclic segments with increasing length until the cyclic segments become cyclic shifts. 
		for (int lv=0;(1<<lv)<=2*n;lv++) // Current iteration. The lv-th iteration sorts cyclic segments of size (2^lv).
		{
			if (lv==0) // For the first iteration, we simply use radix sort.
			{
				for (int i=0;i<n;i++)
				{
					buc[s[i]].push_back(i);
				}
				int u=0,v=0;
				for (int i=0;i<400000;i++)
				{
					u=v;
					for (int g : buc[i])
					{
						ord[g]=v;
						rank[g]=u;
						fin[ord[g]]=g;
						v++;
					}
					buc[i].clear();
				}
			}
			else // For the following iterations, we represent each segment of size 2^lv 
			     // based on the rank of it's two subsegments of size 2^(lv-1).
			     // (First by rank[ [a...a+2^(lv-1)) ], then by rank[ [a+2^(lv-1)...a+2^lv) ]).
			{
				for (int i=0;i<n;i++) 
				// Here, we insert the segments [a..a+2^lv)
				// into the buckets in increasing order of rank[ [a+2^(lv-1)...a+2^lv) ].
				// But the segments are added into the buckets corresponding to rank[ [a...a+2^(lv-1)) ]. 
				// So when we iterate through the buckets and then the elements in each bucket, we should get the correct ordering
				// of segments of length (2^lv).
				{
					buc[rank[(fin[i]+n-(1<<(lv-1)))%n]].push_back((fin[i]+n-(1<<(lv-1)))%n);
				}
				int u=0;
				int v=0;
				// Alright, now we can update the arrays with new the new ordering and ranks.
				for (int i=0;i<n;i++)
				{
					u=v;
					for (int j=0;j<buc[i].size();j++)
					{
						if ((j)and(rank[(buc[i][j]+n+(1<<(lv-1)))%n]!=rank[(buc[i][j-1]+n+(1<<(lv-1)))%n]))
						{
							u=v;
						}
						ord[buc[i][j]]=v;
						rank2[buc[i][j]]=u;
						fin[v]=buc[i][j];
						v++;
					}
					buc[i].clear();
				}
				for (int i=0;i<n;i++) rank[i]=rank2[i];
			}
		//	cout<<"debugging at level "<<lv<<endl;
		//	cout<<"ord: "; for (int i=0;i<n;i++) cout<<ord[i]<<' '; cout<<endl;
		//	cout<<"rank: "; for (int i=0;i<n;i++) cout<<rank[i]<<' '; cout<<endl;
		//	cout<<"fin: "; for (int i=0;i<n;i++) cout<<fin[i]<<' '; cout<<endl;
		}
		// And that's it! I guess.
	}
	void buildlcp() // Builds the lcp array.
	{
		int k=0; // Current lower bound for lcp of next suffix.
		for (int i=0;i<n;i++) // Iterate through suffixes from long to short.
		{
			int u=ord[i];
			if (u==n-1) lcp[u]=0,k=0; // If the current suffix is last in array, lcp is by default, 0.
			else
			{ 
			while(s[(i+k)%n]==s[(fin[u+1]+k)%n]) k++; // Increases k while possible.
			lcp[u]=k; 
			k=max(k-1,0); // Moves on to next suffix.
			}
		}
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////??
struct node
{
    ll l=0,r=0,val=0;
    node(int _l=0, int _r=0, int _val=0)
    {
        l=_l;
        r=_r;
        val=_val;
    }
};
struct seg
{
    vector<node> tre[2000001];
    void reset(int c, int l, int r)
    {
        tre[c].clear();
        tre[c].emplace_back(0,0,0);
        if (l<r)
        {
            int mid=(l+r)/2;
            reset((c<<1),l,mid);
            reset((c<<1)+1,mid+1,r);
        }
    }
    int upd(int c, int l, int r, int t, ll x)
    {
        if ((l<=t)and(t<=r))
        {
            node prv=tre[c][tre[c].size()-1];
            if (l==r)
            {
                prv.l=0;
                prv.r=0;
                prv.val=x;
            }
            else
            {
                int mid=(l+r)/2;
                prv.l=upd((c<<1),l,mid,t,x);
                prv.r=upd((c<<1)+1,mid+1,r,t,x);
                prv.val=tre[(c<<1)][prv.l].val+tre[(c<<1)+1][prv.r].val;
            }

                tre[c].push_back(prv);
        }
        return tre[c].size()-1;
    }
    ll get(int c, int ind, int l, int r, int tl, int tr)
    {
        if ((tl>r)or(tr<l)) return 0;
        if ((l>=tl)and(r<=tr))
        {
            return tre[c][ind].val;
        }
        else
        {
            int mid=(l+r)/2;
            ll a=get((c<<1),tre[c][ind].l,l,mid,tl,tr);
            ll b=get((c<<1)+1,tre[c][ind].r,mid+1,r,tl,tr);
            return (a+b);
        }
    }
};
suff sa;
seg st;
///////////////////////////////////////////////////////////////////////////////////////////////////////////??
vector<int> sent;
string s[200001];
int start[200001];
int l[200001],r[200001];
int jmp[400001][20];
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b,c;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>s[i];
		for (auto g: s[i]) sent.push_back(g);
		sent.push_back(200+i);
		start[i]=start[i-1]+s[i].length();
	}
//	for (auto g : sent) cout<<((g<128)?(char(g)):(g))<<' ';
//	cout<<endl;
	
	sa.build(sent);
	sa.buildlcp();
	//for (i=0;i<sent.size();i++) cout<<sa.fin[i]<<' '; cout<<endl;
	//for (i=0;i<sent.size();i++) cout<<sa.lcp[i]<<' '; cout<<endl;
	for (i=0;i<sent.size();i++) jmp[i][0]=sa.lcp[i];
	for (t=1;t<20;t++) for (i=0;i<sent.size();i++)
	{
		jmp[i][t]=jmp[i][t-1];
		if (i+(1<<(t-1))<sent.size()) jmp[i][t]=min(jmp[i][t],jmp[(i+(1<<(t-1)))][t-1]);
	}
	
	for (i=1;i<=n;i++)
	{
		l[i]=sa.ord[start[i-1]+(i-1)];
		j=l[i];
		for (t=19;t>=0;t--) if (jmp[j][t]>=s[i].length()) j+=(1<<t);
		r[i]=j;
		j=l[i];
		for (t=19;t>=0;t--) if ((j>=(1<<t))and(jmp[j-(1<<t)][t]>=s[i].length())) j-=(1<<t);
		l[i]=j;
	}
	st.reset(1,0,sent.size()-1);
	for (i=1;i<=n;i++)
	{
		for (j=0;j<s[i].length();j++)
		{
			st.upd(1,0,sent.size()-1,sa.ord[start[i-1]+(i-1)+j],1);
//			cout<<i<<' '<<j<<' '<<sa.ord[start[i-1]+(i-1)+j]<<endl;
		}
	}
	for (i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		cout<<st.get(1,start[b],0,sent.size()-1,l[c],r[c])-
		st.get(1,start[a-1],0,sent.size()-1,l[c],r[c]);
		cout<<endl;
	}
	
}
