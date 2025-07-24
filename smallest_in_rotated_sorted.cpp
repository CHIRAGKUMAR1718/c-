class Solution {
  public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(j>i){
            int mid=i+(j-i)/2;
            if(arr[mid]>arr[j]){
                i=mid+1;
            }
            else j=mid;
        }
        return arr[i];
    }
};