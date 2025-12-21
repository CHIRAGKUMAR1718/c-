class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> p0;
        priority_queue<int> p1;
        priority_queue<int> p2;
        for(auto i:nums){
            if(i%3==0) p0.push(i);
            if(i%3==1) p1.push(i);
            if(i%3==2) p2.push(i);
        }
        int p=0;
        if(p1.size()!=0 && p2.size()!=0 && p0.size()!=0) p+=p1.top()+p0.top()+p2.top();
        int x=0;
        int y=0;
        int z=0;
        if(p0.size()>=3){
            x+=p0.top();
            p0.pop();
            x+=p0.top();
            p0.pop();
            x+=p0.top();
        }
        if(p1.size()>=3){
            y+=p1.top();
            p1.pop();
            y+=p1.top();
            p1.pop();
            y+=p1.top();
        }
        if(p2.size()>=3){
            z+=p2.top();
            p2.pop();
            z+=p2.top();
            p2.pop();
            z+=p2.top();
        }
        return max({p,x,y,z});
    }
};