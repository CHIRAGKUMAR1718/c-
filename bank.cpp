class Bank {
public:
    vector<long long> nums;
    Bank(vector<long long>& balance) {
        nums=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        int n=nums.size();
        if(account1>n || account2>n) return false;
        if(nums[account1-1]>=money){
            nums[account1-1]-=money;
            nums[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>nums.size()) return false;
        nums[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>nums.size()) return false;
        if(nums[account-1]>=money){
            nums[account-1]-=money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */