class Solution {
public:
    vector<pair<int,int>> f(vector<pair<int,int>> v){
        vector<pair<int,int>> ans;
        if(v.size()==0) return ans;
        int p_left=v[0].first;
        int p_right=v[0].second;
        for(int i=1;i<v.size();i++){
            int c_left=v[i].first;
            int c_right=v[i].second;
            if(c_left<=p_right){
                p_left=min(c_left,p_left);
                p_right=max(p_right,c_right);
            }else{
                ans.push_back({p_left,p_right});
                p_left=c_left;
                p_right=c_right;
            }
        }
        ans.push_back({p_left,p_right});
        return ans;
    }
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            if(lights[i]!=0) v.push_back({max(0,i-lights[i]),min(n-1,i+lights[i])});
        }
        vector<pair<int,int>> merged;
        merged=f(v);
        int ans=0;
        int left=0;
        int right=n;
        for(auto i:merged){
            auto curr=i;
            right=min(right,curr.first);
            int x=right-left;
            ans+=(x/3)+((x%3>0)?1:0);
            left=curr.second+1;
            right=n;
        }
        int sum=right-left;
        ans+=(sum/3)+(((sum%3)>0)?1:0);
        return ans;
    }
};