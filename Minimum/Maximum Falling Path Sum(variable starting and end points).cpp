//https://leetcode.com/problems/minimum-falling-path-sum/description/
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

int f(int row,int col,int n,int m,vector<vector<int>>&dp){
	if(row<1 || row>n || col<1 || col>m)return 1e9;
	if(row==1)return a[row][col];
	if(dp[row][col]!=-1)return dp[row][col];
	
	int down=1e9,right=1e9,left=1e9;
	down=a[row][col]+f(row-1,col,n,m,dp);
	left=a[row][col]+f(row-1,col-1,n,m,dp);
	right=a[row][col]+f(row-1,col+1,n,m,dp);
	return dp[row][col]=min(min(down,left),right);
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
	int mn=1e9;
	for(int i=1;i<=m;i++){
		int x=f(n,i,n,m,dp);
		mn=min(mn,x);
	}
	cout<<mn<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
