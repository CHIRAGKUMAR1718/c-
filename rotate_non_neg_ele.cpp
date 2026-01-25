class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
            count++;
            }
        }
        vector<int> v(count*2);
        int yy=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                v[yy++]=nums[i];
            }
        }
        if(count==0) return nums;
        k%=count;
        for(int i=0;i<count;i++) v[count+i]=v[i];
        vector<int> p(count);
        int xx=0;
        for(int i=k;i<count+k;i++) p[xx++]=v[i];
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0) nums[i]=p[idx++];
        }
        return  nums;
    }
};