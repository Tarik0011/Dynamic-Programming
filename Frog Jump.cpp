//https://atcoder.jp/contests/dp/tasks/dp_a

/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define  pb        push_back
#define  all(v)    v.begin(),v.end()
#define  endl       '\n'  
#define  uint       long long
#define  int        long long
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 
 
const int mxn=1e6+69;
int a[mxn];
int f(int idx,vector<int>&dp){
	if(idx==1)return 0;
	if(dp[idx]!=-1)return dp[idx];
	int l=2e9,r=2e9;
	l=abs(a[idx]-a[idx-1])+f(idx-1,dp);
	if(idx-2>=1)r=abs(a[idx]-a[idx-2])+f(idx-2,dp);
	return dp[idx]=min(l,r);
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>dp(n+1,-1);
	cout<<f(n,dp)<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
