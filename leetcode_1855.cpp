class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        int m=nums1.size();
        int maxi=INT_MIN;
        int i=0;
        int j=0;
        while(j<n && i<m){
            while(j<n && nums2[j]>=nums1[i]) j++;
            maxi=max(maxi,j-1-i);
            while(i<m && j<n && nums1[i]>nums2[j]) i++;
            if(i>j) j=i;
        }
        return (maxi<0)?0:maxi;
    }
};