#include <bits/stdc++.h>
using namespace std;
 #define MOD 1000000007
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
 #define endl "\n"
 struct frac {long x; long y;};
 frac operator+(frac a, frac b)
 {
 	frac res;
 	res.x=((a.x)*(b.y))%MOD+((b.x)*(a.y))%MOD;
 	res.x%=MOD;
 	res.y=a.y*b.y;
 	res.y%=MOD;
 	return res;
 }
 
 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
 long long get_mod(long long x, long long y)
 {
 	long long d=__gcd(x,y);
 	x/=d;
 	y/=d;
 	x%=MOD;
 	y%=MOD;
 	return (x*(bow(y,MOD-2)))%MOD;
 }
 
long long t,k,n,m, i,j,jj,mid,a,b,root,count0;
vector <long long> maxx;
long long lis[1001][101],lds[1001][101],res[2501];
multiset<long long> pre;
 
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   long long n,d;
   cin>>n>>m;
   for (j=1;j<=m;j++) for (i=1;i<=n;i++)
   {
   	if (j==1) {lis[i][j]=1; continue;}
   	for (k=1;k<=i;k++) {lis[i][j]+=lis[k][j-1]; lis[i][j]%=MOD;}
   }
   for (j=1;j<=m;j++) for (i=1;i<=n;i++)
   {
   	if (j==1) {lds[i][j]=1; continue;}
   	for (k=i;k<=n;k++) {lds[i][j]+=lds[k][j-1]; lds[i][j]%=MOD;}
   }
   for (i=1;i<=n;i++) for (j=i;j<=n;j++) {root+=(lis[i][m]*lds[j][m])%MOD; root%=MOD;}
   cout<<root;
}
/*
1880/1900
n>=2sqrt(d)
a/c <=b

b+1=10ex
*/