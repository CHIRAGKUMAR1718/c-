class Solution {
public:
    #define mod 1000000007
    vector<int> productQueries(int n, vector<vector<int>>& nums) {
        vector<int> power;
        for(int i=0;i<32;i++){
            if(((n)&(1<<i))!=0) power.push_back(1<<i);
        }
        for(auto i:power) cout<<i<<"    ";
        vector<int> ans;
        for(auto& i:nums){
            int s=i[0];
            int e=i[1];
            long long ppp=1;
            for(int p=s;p<=e;p++){
                ppp=(ppp*power[p])%mod;
            }
            ans.push_back((int)ppp);
        }
        return ans;
    }
};