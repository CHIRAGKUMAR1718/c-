class Solution {
public:

    int f(vector<int>&nums){
        int n=nums.size();
        if(n==0) return 0;
        //next
        vector<int> next(n);
        stack<int> ni;
        next[n-1]=n;
        ni.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(ni.size()!=0 && nums[ni.top()]>=nums[i]) ni.pop();
            if(ni.size()==0) next[i]=n;
            else next[i]=ni.top();
            ni.push(i);
        }
        //prev
        vector<int> prev(n);
        stack<int> pi;
        prev[0]=-1;
        pi.push(0);
        for(int i=1;i<n;i++){
            while(pi.size()!=0 && nums[pi.top()]>=nums[i]) pi.pop();
            if(pi.size()==0) prev[i]=-1;
            else prev[i]=pi.top();
            pi.push(i);
        }
        int area=0;
        for(int i=0;i<n;i++){
            int x=next[i]-prev[i]-1;
            area=max(area,nums[i]*x);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> prev(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> v(m,0);
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') v[j]=1+prev[j];
                ans=max(ans,f(v));
            }
            prev=v;
        }
        return ans;
    }
};