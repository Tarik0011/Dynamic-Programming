//https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?leftPanelTab=1
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
int f(int idx,int cost,vector<vector<int>>&dp){
	if(idx==1){
		return a[idx]*cost;
	}
	if(dp[idx][cost]!=-1)return dp[idx][cost];
	int notTake=f(idx-1,cost,dp);
	int take=INT_MIN;
	if(idx<=cost){
		take=a[idx]+f(idx,cost-idx,dp);
	}
	return dp[idx][cost]=max(take,notTake);
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	cout<<f(n,n,dp)<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
