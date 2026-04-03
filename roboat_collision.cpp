class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<pair<int,pair<int,char>>> v(n);
        for(int i=0;i<n;i++) v[i]={positions[i],{i,directions[i]}};
        sort(v.begin(),v.end());
        stack<pair<int,char>> st;
        int i=0;
        while(i<n){
            while(i<n && st.size()!=0 && st.top().second=='R' && v[i].second.second=='L'){
                auto curr=st.top();
                st.pop();
                int idxr=curr.first;
                int idxl=v[i].second.first;
                if(healths[idxr]>healths[idxl]){
                    healths[idxr]--;
                    healths[idxl]=0;
                    st.push({idxr, 'R'});
                    i++;
                }
                else if(healths[idxr]<healths[idxl]){
                    healths[idxr]=0;
                    healths[idxl]--;
                }
                else if(healths[idxr]==healths[idxl]){
                    healths[idxr]=0;
                    healths[idxl]=0;
                    i++;
                }
            }
            if(i<n && (st.size()==0 || !(st.top().second=='R' && v[i].second.second=='L'))) st.push(v[i].second);
            i++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(healths[i]!=0) ans.push_back(healths[i]);
        }
        return ans;
    }
};