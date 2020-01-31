#include<bits/stdc++.h> 
using namespace std;  
  #define int long long
int lis(vector<int>& v)  
{  
    if (v.size() == 0)  
        return 0;  
  
    std::vector<int> tail(v.size(), 0);  
    int length = 1; 
  
    tail[0] = v[0];  
      
    for (int i = 1; i < v.size(); i++) {  
        auto b = tail.begin(), e = tail.begin() + length; 
        auto it = lower_bound(b, e, v[i]);  
        if (it == tail.begin() + length) 
        tail[length++] = v[i];  
        else   
        *it = v[i];  
    }  
  
    return length;  
}  
  
signed main()  
{  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i,j,m;
    vector<int> v;
	cin>>n;
	for (i=0;i<n;i++) {cin>>m; v.push_back(m);}  
    cout << lis(v);  
}   