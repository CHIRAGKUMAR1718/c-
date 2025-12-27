#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = 1, cur = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]){
                cur++;
            } 
            else {
                cur = 1;
            }
            ans = max(ans, cur + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}