// Problem : E. TV Game
// Contest : Codeforces - Codeforces Beta Round #31 (Div. 2, Codeforces format)
// URL : https://codeforces.com/problemset/problem/31/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef __int128 ll;
//---------END-------//
ll n,m,k,pos[100001],t,t1,i,j,p10[20];
pair<ll,ll> dp[20][20];
int buf;
string s;
int main()
{
//  ofile;
    fio;
    p10[0]=1;
    for (i=1;i<20;i++) p10[i]=p10[i-1]*10; 
    cin>>buf;
    n=buf;
    cin>>s;
    for (i=0;i<=n;i++) for (j=0;j<=n;j++) if (i+j)
    {
        dp[i][j].fi=-1;
    	if ((i)and(dp[i][j].fi<dp[i-1][j].fi+(ll(s[2*n-1-(i+j-1)])-48)*p10[i-1]))
    	{
    		dp[i][j].fi=dp[i-1][j].fi+(ll(s[2*n-1-(i+j-1)])-48)*p10[i-1];
    		dp[i][j].se=0;
    	}
    	if ((j)and(dp[i][j].fi<dp[i][j-1].fi+(ll(s[2*n-1-(i+j-1)])-48)*p10[j-1]))
    	{
    		dp[i][j].fi=dp[i][j-1].fi+(ll(s[2*n-1-(i+j-1)])-48)*p10[j-1];
    		dp[i][j].se=1;
    	}
    }
 //   buf=dp[n][n].fi;
 //   cout<<buf<<endl;
    i=n;j=n;
    while (i+j)
    {
    	if (dp[i][j].se==0)
    	{
    		cout<<'H'; i--;
    	}
    	else
    	{
    		cout<<'M'; j--;
    	}
    }
}
  