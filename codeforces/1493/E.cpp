#include <bits/stdc++.h>
using namespace std;
string a,b;
int n,m,i,j,k,t,t1;
int main()
{
    cin>>n;
    cin>>a>>b;
    if (a[0]-b[0]) {for (auto g : a) cout<<1; return 0;}
    if (b[n-1]=='1') {cout<<b; return 0;}
    for (j=0;j<2;j++)
    {
        if (a==b) break;
        for (i=n-1;i>=0;i--) if (b[i]=='0') b[i]='1'; else{b[i]='0'; break;}
    }
    if (j==2) j++;
    b="0"+b;
    for (j=j;j;j--)
    {
        for (i=n;i>=0;i--) if (b[i]=='1') b[i]='0'; else{b[i]='1'; break;}
    }
    if (b[0]=='0') b.erase(b.begin());
    cout<<b;
}