class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int max_h=1;
        int max_c=1;
        int count=1;
        sort(hBars.begin(),hBars.end());
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-1==hBars[i-1]) count++;
            else count=1;
            max_h=max(max_h,count);
        }
        max_h++;
        sort(vBars.begin(),vBars.end());
        count=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-1==vBars[i-1]) count++;
            else count=1;
            max_c=max(max_c,count);
        }
        max_c++;
        int x=min(max_h,max_c);
        return x*x;
    }
};