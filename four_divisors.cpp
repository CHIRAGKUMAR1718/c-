class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto ele:nums){
            set<int> s;
            for(int i=1;i<=sqrt(ele);i++){
                if(ele%i==0){
                    s.insert(i);
                    s.insert(ele/i);
                }
            }
            if(s.size()==4){
                for(auto k:s) ans+=k;
            }
        }
        return ans;
    }
};