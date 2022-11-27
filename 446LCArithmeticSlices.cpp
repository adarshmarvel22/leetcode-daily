//TC O(2^n) 

class Solution {
public:
    long long int ans=0;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        ans=0;
     vector<long long int>cur;
        f(0,cur,nums);
        return ans;
    }
    void f(int i,vector<long long int>cur,vector<int>a){
        if(i==a.size()){
            if(cur.size()<3)  return;
            for(int i=2;i<cur.size();i++){
                if(cur[i]-cur[i-1]!=cur[1]-cur[0])  return;
            }
            ans++;
            return;
        }
//         not take
        f(i+1,cur,a);
        cur.push_back(a[i]);
//         take
        f(i+1,cur,a);
    }
};

//TC: O(n^2) 
class Solution {
public:
    long long int ans=0;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
         int n=nums.size();
        long ans=0;
        vector<map<long long int,long int>>dp(n);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long int diff=(long long int)nums[i] - (long long int)nums[j];
                long sum=0; 
                if(dp[j].count(diff)){  // if previusly stored
                    sum=dp[j][diff]; 
                }
                dp[i][diff]+=1+sum; 
                ans+=sum;
            }
        }
        return ans;
    }
};
