class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_map<int,int> h;
        hFences.push_back(1);
        hFences.push_back(m);
        sort(hFences.begin(),hFences.end());
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                h[hFences[j]-hFences[i]]++;
            }
        }
        unordered_map<int,int> v;
        vFences.push_back(1);
        vFences.push_back(n);
        sort(vFences.begin(),vFences.end());
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                v[vFences[j]-vFences[i]]++;
            }
        }
       long long ans=-1;
       for(auto i:h){
        if(v.find(i.first)!=v.end()) ans=max(ans,(long long)i.first*i.first); 
       }
       return ans%1000000007;
    }
};