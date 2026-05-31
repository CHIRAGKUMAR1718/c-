class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int i=0;
        int n=asteroids.size();
        sort(asteroids.begin(),asteroids.end());
        long long sum=mass;
        while(i<n){
            if(sum>=asteroids[i]) sum+=(long long)asteroids[i];
            else break;
            i++;
        }
        return i==n;
    }
};