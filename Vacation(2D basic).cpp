//https://atcoder.jp/contests/dp/tasks/dp_c

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
int a[mxn][4];

int f(int day,int last,vector<vector<int>>&dp){
	if(day==1){
		int mx=0;
		for(int i=1;i<=3;i++){
			if(i!=last){
				mx=max(mx,a[day][i]);
			}
		}
		return mx;
	}
	if(dp[day][last]!=-1){
		return dp[day][last];
	}
	int mx=0;
	for(int i=1;i<=3;i++){
		if(i!=last){
		  int points=a[day][i]+f(day-1,i,dp);
		  mx=max(mx,points);
		}
	}
	return dp[day][last]=mx;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	vector<vector<int>>dp(n+1,vector<int>(5,-1));

	cout<<f(n,4,dp)<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
