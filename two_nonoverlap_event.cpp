class Solution {
public:
int n;
    int mem[100001][3];
    int binarys(int sc,int end,vector<vector<int>>& events){
        int lo=sc;
        int hi=n-1;
        int ans=n;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(events[mid][0]>end){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
    int f(int i,int count,vector<vector<int>>& events){
        if(count==2) return 0;
        if(i>=n) return 0;
        if(mem[i][count]!=-1) return mem[i][count];
        int val=events[i][2];
        int x=val+f(binarys(i,events[i][1],events),count+1,events);
        int y=0+f(i+1,count,events);
        return mem[i][count]=max(x,y);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
      n=events.size();
      memset(mem,-1,sizeof(mem));
      sort(events.begin(),events.end());
      return f(0,0,events);  
    }
};