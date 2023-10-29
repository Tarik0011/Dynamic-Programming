//https://leetcode.com/submissions/detail/1075996471/

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
 
const int mxn=1e6+123;
int a[mxn];
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<int>dp(n+1,1);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]>a[j]){
				if(dp[j]+1>dp[i]){
					dp[i]=dp[j]+1;
				}
			}
		}
	}
	
	for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
	cout<<endl;
}
signed main(){ 
    fastio; 
    int t=1;
   // cin>>t;
    for(int i=1;i<=t;i++){
      // cout<<"Case "<<i<<": ";
       solve();
    }
}
