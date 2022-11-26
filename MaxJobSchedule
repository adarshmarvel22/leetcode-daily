class node{
    public:
    int s;
    int e;
    int p;

    node(int a,int b,int c){
        s=a,e=b,p=c;
    }
};
bool comp(class node&a,class node&b){
    if(a.s<b.s)  return true;
    return false;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        // node v[n];
        vector<node>v;
        vector<int> dp(n,-1);
        
        for(int i=0;i<n;i++){
            // v[i].s=startTime[i];  v[i].e=endTime[i];  v[i].p=profit[i];
            v.push_back(node(startTime[i],endTime[i],profit[i]));
        }
        
        sort(v.begin(),v.end(),comp);
        sort(startTime.begin(),startTime.end());
        
        int ans=0;
        ans=max(f(0,v,n,dp,startTime),ans);
        
        return ans;
    }
    int f(int i,vector<node>&v,int n,vector<int> &dp,vector<int>&st){
        //base
        if(i>=n)  return 0;
            
        int take=0,not_take=0;
        if(dp[i]!=-1)  return dp[i];
        int ind=lower_bound(st.begin(),st.end(),v[i].e)-st.begin();
        //take
        take=f(ind,v,n,dp,st)+v[i].p;
        // not take
        not_take=f(i+1,v,n,dp,st);
        
        return dp[i]=max(take,not_take);
    }
};
