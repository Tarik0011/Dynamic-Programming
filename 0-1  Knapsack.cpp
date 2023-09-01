//https://atcoder.jp/contests/dp/tasks/dp_d
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
int a[mxn],b[mxn];

int f(int idx,int w,vector<vector<int>>&dp){
	if(idx==1){
		if(a[idx]<=w){
			return b[idx];
		}
		else return 0;
	}
	if(dp[idx][w]!=-1)return dp[idx][w];
	int notPick=f(idx-1,w,dp);
	int pick=INT_MIN;
	if(a[idx]<=w){
		pick=b[idx]+f(idx-1,w-a[idx],dp);
	}
	return dp[idx][w]=max(pick,notPick);
}
void solve(){
	int n,w;
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
	cout<<f(n,w,dp)<<endl;
	
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
