// Credit to robs77 for this template
/***********HEADER***************/
#include <bits/stdc++.h>
using namespace std;
/***********MACROS***************/
//#define int long long 
#define ll int64_t 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
 
/*********VARIABLE****************/
struct bd {ll v; ll c;};
typedef pair<int,int> ii;
/******************************/
const ll po[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
ll n,i,j,x,y,z,minn=0,t,pr,a,b,k;
bd all[300001]; bd h;
ll dp[300001][3];
/*********FUNCTIONS**************/
 
 
/***********MAIN**************/
 
signed main()
{ 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for (z=1;z<=t;z++) { x=1;
	cin>>n;
	for (i=1;i<=n;i++) {pr=h.v; cin>>h.v>>h.c; 
	all[i]=h;}
	if (n==1) {cout<<0<<endl; continue;}
	for (i=1;i<=n;i++) for (j=0;j<=2;j++) dp[i][j]=1500000000000000001;
	dp[1][0]=0;
	dp[1][1]=all[1].c;
	dp[1][2]=2*dp[1][1];
	for (i=2;i<=n;i++) for (j=0;j<=2;j++)
	for (k=0;k<=2;k++) if (all[i-1].v+k!=all[i].v+j){
	x=dp[i-1][k]+all[i].c*j;
	if (x<dp[i][j]) dp[i][j]=x;
}
	if ((dp[n][0]<=dp[n][1])and(dp[n][0]<=dp[n][2])) cout<<dp[n][0];
	else if ((dp[n][1]<=dp[n][2])and(dp[n][1]<=dp[n][0])) cout<<dp[n][1];
	else cout<<dp[n][2];
	cout<<endl;
}
}