//https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?leftPanelTab=0

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
int a[mxn],mod=1e9+7;

int f(int idx, int target,vector<vector<int>>&dp){
	if(target==0)return 1;
	if(idx==1)return a[idx]==target;
	if(dp[idx][target]!=-1)return dp[idx][target];
	int notTake=f(idx-1,target,dp)%mod;
	int take=0;
	if(a[idx]<=target){
		take=f(idx-1,target-a[idx],dp)%mod;
	}
	return dp[idx][target]=(take+notTake)%mod;
}
void solve(){
	int n,target;
	cin>>n>>target;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
	cout<<f(n,target,dp)%mod<<endl;

}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
