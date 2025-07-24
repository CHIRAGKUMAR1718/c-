class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int f=-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            if(arr[mid]==target){
                f=mid;
                j=mid-1;
            }
            else if(arr[mid]>target) j=mid-1;
            else i=mid+1;
        }
        if(f==-1) return 0;
        int l=0;
        i=0;
        j=n-1;
        while(j>=i){
            int mid=i+(j-i)/2;
            if(arr[mid]==target){
                l=mid;
                i=mid+1;
            }
            else if(arr[mid]>target) j=mid-1;
            else i=mid+1;
        }
        if(l==-1) return 0;
        return l-f+1;
    }
};
