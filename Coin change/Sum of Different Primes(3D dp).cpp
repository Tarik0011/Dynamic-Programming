//https://vjudge.net/problem/UVA-1213

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

bool is_prime[mxn];
vector<int>primes;
int dp[260][1200][15];

int f(int idx,int n,int cnt){
	if(idx<0 ||cnt==0 || n<=0){
		return (n==0 and cnt==0);
	}
	if(dp[idx][n][cnt]!=-1)return dp[idx][n][cnt];
	int notTake=f(idx-1,n,cnt);
	int take=f(idx-1,n-primes[idx],cnt-1);
	return dp[idx][n][cnt]=take+notTake;
}
void sieve(int n){
	for(int i=1;i<=n;i++)is_prime[i]=1;
		for(int i=2;i<=n;i++){
			if(is_prime[i]){
				primes.pb(i);
				for(int j=i*i;j<=n;j+=i){
					is_prime[j]=0;
				}
			}
		}
}
void solve(){
	int n,k;
	while(cin>>n>>k){
		if(n==0 and k==0)break;
		memset(dp,-1,sizeof(dp));
		int m=primes.size();
		cout<<f(m-1,n,k)<<endl;
	}
}
signed main(){ 
    fastio; 
    int t=1;
    sieve(1200);
    //cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}










			//second Approach



/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/
/*
 
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

bool is_prime[mxn];
vector<int>primes;
int dp[200][1200][15];

int f(int idx,int sum,int cnt,int n,int k){
	if(idx<0 || cnt>=k || sum>=n){
		return (sum==n and cnt==k);
	}
	if(dp[idx][sum][cnt]!=-1)return dp[idx][sum][cnt];
	int notTake=f(idx-1,sum,cnt,n,k);
	int take=f(idx-1,sum+primes[idx],cnt+1,n,k);
	return dp[idx][sum][cnt]=take+notTake;
}
void sieve(int n){
	for(int i=1;i<=n;i++)is_prime[i]=1;
		for(int i=2;i<=n;i++){
			if(is_prime[i]){
				primes.pb(i);
				for(int j=i*i;j<=n;j+=i){
					is_prime[j]=0;
				}
			}
		}
}
void solve(){
	int n,k;
	while(cin>>n>>k){
		if(n==0 and k==0)break;
		memset(dp,-1,sizeof(dp));
		int m=primes.size();
		cout<<f(m-1,0,0,n,k)<<endl;
	}
}
signed main(){ 
    fastio; 
    int t=1;
    sieve(1200);
    //cin>>t;
    for(int i=1;i<=t;i++){
       solve();
    }
}
*/
