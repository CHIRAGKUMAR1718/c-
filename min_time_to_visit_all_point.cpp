class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& nums) {
        int row=nums.size();    
        int sum=0;
        for(int i=0;i<row-1;i++){
            int x1=nums[i][0];
            int x2=nums[i+1][0];
            int y1=nums[i][1];
            int y2=nums[i+1][1];
            int p1=abs(x2-x1);
            int p2=abs(y2-y1);
            sum+=max(p1,p2);
        }
        return sum;
    }
};