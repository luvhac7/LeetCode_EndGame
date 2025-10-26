class Bank {
public:
vector<long long>balance;
int n;
    Bank(vector<long long>& balance) {
      n=balance.size();
      this->balance=balance;  
    }
    
    bool transfer(int ac1, int ac2, long long money) {
        if(ac1>n || ac2>n || balance[ac1-1]<money)
        {
            return false;
        }
        balance[ac1-1]-=money;
        balance[ac2-1]+=money;
        return true;
    }
    
    bool deposit(int ac, long long money) {
        if(ac>n)
        {
            return false;
        }
        balance[ac-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>n || balance[account-1]<money)
            return false;
        balance[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */