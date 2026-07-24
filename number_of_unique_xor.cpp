class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int x=nums[i]^nums[j];
                v.insert(x);
            }
        }
        unordered_set<int> s;
        
        for(auto ele:v){
            for(int i=0;i<n;i++){
                int x=nums[i]^ele;
                s.insert(x);
            }
        }
        return s.size();
    }
};