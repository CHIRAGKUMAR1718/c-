class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> pre(n);
        pre[0] = prices[0];
        for (int i = 1; i < n; i++) pre[i] = prices[i] + pre[i - 1];
        vector<long long> original(n);
        for (int i = 0; i < n; i++) original[i] = 1LL * prices[i] * strategy[i];
        vector<long long> pre2(n);
        pre2[0] = original[0];
        for (int i = 1; i < n; i++) pre2[i] = pre2[i - 1] + original[i];
        vector<long long> change, as_it_is;
        for (int i = 0; i <= n - k; i++) {
            long long totalPrice = pre[i + k - 1] - (i > 0 ? pre[i - 1] : 0);
            long long leftPrice  = pre[i + k/2 - 1] - (i > 0 ? pre[i - 1] : 0);
            change.push_back(totalPrice - leftPrice); 
            long long totalOrig = pre2[i + k - 1] - (i > 0 ? pre2[i - 1] : 0);
            as_it_is.push_back(totalOrig); 
        }
        int zz = -1;
        long long bestGain = 0;
        for (int i = 0; i < (int)change.size(); i++) {
            long long gain = change[i] - as_it_is[i];
            if (gain > bestGain) {
                bestGain = gain;
                zz = i;
            }
        }
        if (zz != -1) {
            for (int i = zz; i < zz + k/2; i++) strategy[i] = 0;
            for (int i = zz + k/2; i < zz + k; i++) strategy[i] = 1;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += 1LL * prices[i] * strategy[i];
        return ans;
    }
};
