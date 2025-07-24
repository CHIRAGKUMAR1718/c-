class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int idx=-1;
        int n=arr.size();
        if(n==1) return 0;
        int i=0;
        int j=n-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            if(mid-1>=0 && arr[mid-1]>arr[mid]) j=mid-1;
            else if(mid+1<n && arr[mid+1]>arr[mid]) i=mid+1;
            else{
                idx=mid;
                break;
            }
        }
        return idx;
    }
};