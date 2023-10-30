//https://leetcode.com/submissions/detail/845036151/


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
#define  BLOCK        700
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 
 
const int mxn=1e6+123;
int a[mxn];

string s,t;
int dp[1001][1001];

int solve(int i,int j,int n,int m){
	if(i>=n || j>=m)return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	if(s[i]==t[j])return dp[i][j]=1+solve(i+1,j+1,n,m);
	int l=solve(i+1,j,n,m);
	int r=solve(i,j+1,n,m);
	return dp[i][j]=max(l,r);
}

void solve(){
	cin>>s>>t;
	int n=s.size(),m=t.size();
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0,n,m)<<endl;

}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
