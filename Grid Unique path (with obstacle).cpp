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
 
const int mxn=200;
int a[mxn][mxn];

int f(int n,int m,vector<vector<int>>&dp){
	if(n==1 and m==1 and a[n][m]==0)return 1;
	if(n<1 || m<1 || a[n][m]==1)return 0;
	if(dp[n][m]!=-1)return dp[n][m];
	int down=f(n-1,m,dp);
	int right=f(n,m-1,dp);
	return dp[n][m]=right+down;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	cout<<f(n,m,dp)<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
