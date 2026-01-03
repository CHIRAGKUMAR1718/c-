class Solution {
public:
    bool f(priority_queue<long long>& pq,long long sum){
        if(pq.top()==1) return true;
        long long diff=sum-pq.top();
        if(diff==1) return true;
        if(diff==0 || diff>pq.top() || pq.top()%diff==0) return false;
        long long x=pq.top()%diff;
        sum=diff+x;
        pq.pop();
        pq.push(x);
        return f(pq,sum);
    }
    bool isPossible(vector<int>& target) {
        priority_queue<long long> pq;
        long long sum=0;
        for(auto i:target){
            pq.push(i);
            sum+=i;
        }
        return f(pq,sum);
    }
};