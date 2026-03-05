class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxi;
        maxi.push(a);
        maxi.push(b);
        maxi.push(c);
        int ans=0;
        while(maxi.size()>=2){
            ans++;
            int x=maxi.top()-1;
            maxi.pop();
            int y=maxi.top()-1;
            maxi.pop();
            if(x!=0) maxi.push(x);
            if(y!=0) maxi.push(y);
        }
        return ans;
    }
};