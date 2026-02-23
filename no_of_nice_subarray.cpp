class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int key=1;
        int co=0;
        unordered_map<int,int> m;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                m[key]=i;
                key++;
                co++;
            }
        }
        
        m[0]=-1;               
        m[co+1]=nums.size();   
        
        int ans=0;
        int f=1;
        int l=k;
        
        while(l<=co){
            int f1=f-1;
            int f2=f;
            int l1=l;
            int l2=l+1;
            
            int a=m[f2]-m[f1];
            int b=m[l2]-m[l1];
            
            ans+=(a*b);
            
            f++;
            l++;
        }
        
        return ans;
    }
};