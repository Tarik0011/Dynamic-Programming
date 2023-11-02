//https://leetcode.com/problems/maximum-profit-in-job-scheduling/

class Solution {
public:
    int bs(int l,int end,vector<vector<int>>&nums){
        int n=nums.size();
        int r=n-1,ans=n+1;
        while(l<=r){
            int m=(l+r)>>1;
            if(nums[m][0]>=end){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
    int f(int idx,vector<vector<int>>&nums,vector<int>&dp){
        int n=nums.size();
        if(idx>=n)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int skip=f(idx+1,nums,dp);
        int next=bs(idx+1,nums[idx][1],nums);
        int take=nums[idx][2]+f(next,nums,dp);
        return dp[idx]=max(skip,take);
        
        
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>nums(n,vector<int>(3));
        for(int i=0;i<n;i++){
            nums[i][0]=startTime[i];
            nums[i][1]=endTime[i];
            nums[i][2]= profit[i];
        }
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,-1);
        return f(0,nums,dp);
        
    }
};
