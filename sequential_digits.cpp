class Solution {
public:
    void f(unordered_map<long long,long long>&m,long long count){
        while(count>9){
            m[count]++;
            count/=10;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        unordered_map<long long,long long> m;
        for(int i=1;i<9;i++){
            long long count=0;
            for(int j=i;j<=9;j++){
                count*=10;
                count+=j;
            }
            f(m,count);
        }
        vector<int> ans;
        for(auto i:m){
            if(i.first>=low && i.first<=high) ans.push_back(i.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};