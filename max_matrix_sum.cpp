class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg=0;
        int mini=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0) neg++;
                mini=min(abs(matrix[i][j]),mini);
                sum+=abs(matrix[i][j]);
            }
        }
        cout<<mini<<" "<<sum;
        if(neg%2==0) return sum;
        return sum-(2*mini);
    }
};