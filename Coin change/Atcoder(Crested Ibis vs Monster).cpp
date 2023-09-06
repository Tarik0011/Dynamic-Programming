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
int f(int h,int idx,vector<vector<int>>&dp){
	if(h<=0)return 0;
	if(idx<1)return 1e16;
	if(dp[h][idx]!=-1)return dp[h][idx];
	int notPick=f(h,idx-1,dp);
	int pick=1e16;
	pick=b[idx]+f(h-a[idx],idx,dp);
	return dp[h][idx]=min(pick,notPick);
}
void solve(){
	int h,n;
	cin>>h>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	vector<vector<int>>dp(h+1,vector<int>(n+1,-1));
	cout<<f(h,n,dp)<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
