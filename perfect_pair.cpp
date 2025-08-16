class Solution {
public:
    int f(int a, vector<int>& nums, int s) {
        int i = s;
        int j = nums.size() - 1;
        int ans = s;  
        while (i <= j) {
            int mid = (i + j) / 2;
            int b = nums[mid];
            int mn = min(abs(a), abs(b));
            int mx = max(abs(a), abs(b));
            if (min(abs(a - b), abs(a + b)) <= mn &&
                max(abs(a - b), abs(a + b)) >= mx) {
                ans = mid;
                i = mid + 1; 
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }
    long long perfectPairs(vector<int>& nums) {
        long long ans = 0;
        for(int i=0;i<nums.size();i++) nums[i]=abs(nums[i]);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            ans += f(nums[i], nums, i) - i;
        }
        return ans;
    }
};
