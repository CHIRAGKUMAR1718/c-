class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(),restrictions.end());
        vector<vector<int>> height=restrictions;
        height.push_back({1,0});
        if(restrictions.size()==0 || restrictions[restrictions.size()-1][0]!=n) height.push_back({n,n-1});
        vector<int> left(height.size());
        sort(height.begin(),height.end());
        left[0]=0;
        for(int i=1;i<height.size();i++){
            int space=height[i][0]-height[i-1][0]-1;
            int maxi=left[i-1]+space+1;
            left[i]=min(maxi,height[i][1]);
        }
        vector<int> right(height.size());
        right[height.size()-1]=height[height.size()-1][1];
        for(int i=height.size()-2;i>=0;i--){
            int space=-height[i][0]+height[i+1][0]-1;
            int maxi=right[i+1]+space+1;
            right[i]=min(maxi,height[i][1]);
        }
        vector<int> ans(height.size());
        for(int i=0;i<height.size();i++){
            ans[i]=min(left[i],right[i]);
        }
        for(int i=0;i<ans.size();i++) height[i][1]=ans[i];
        int original_ans=0;
        // for(int i=1;i<ans.size();i++){
        //     int space=height[i][0]-height[i-1][0]-1;
        //     space-=abs(height[i][1]-height[i-1][1]);
        //     if(space<0) space=0;
        //     int maxi=max(height[i][1],height[i-1][1])+space;
        //     original_ans=max(maxi,original_ans);
        // }
        for(int i=1;i<ans.size();i++){
            int d=height[i][0]-height[i-1][0];
            int peak=(height[i][1]+height[i-1][1]+d)/2;
            original_ans=max(peak,original_ans);
        }
        return original_ans;
    }
};