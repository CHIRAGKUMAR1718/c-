class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        for(int i=0;i<100;i++){
            if(pow(2,i)>n) return pow(2,i);
        }
        return 0;
    }
};