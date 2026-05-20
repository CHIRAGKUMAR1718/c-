class Solution {
public:
    static bool cmp(const vector<int>&a , const vector<int>&b){
        return (a[1]-a[0])>(b[1]-b[0]);
    }
    bool f(vector<vector<int>>& tasks,int target){
        for(auto i:tasks){
            if(target>=i[1]) target-=i[0];
            else return false;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        int lo=0;
        int hi=0;
        int sum1=0;
        int sum2=0;
        for(auto i:tasks) sum1+=i[1];
        for(auto i:tasks) sum2+=i[0];
        hi=sum1+sum2;
        int ans=0;
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(f(tasks,mid)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};