// TC:o(nlogn) 
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        vector<vector<int>>ans(2);
        //   idx->(wins, lose)      
        map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
        for(auto i:mp){
            //  if won atleast 1 match and not lost any matches
            if(i.second.first>=1&&i.second.second==0){
                ans[0].push_back(i.first);
            }
            //  if lost only 1 match
            if(i.second.second==1){
                ans[1].push_back(i.first);
            }
        }
        
        return ans;
    }
};
