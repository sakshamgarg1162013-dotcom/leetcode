class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1){
            return true;
        }
        else if(n<=0){
            return false;
        }
        int m;
    while (n>1)
    {
        m=n%2;
        if (m==1)
        {
            return false;
        }
        n=n/2;
        
    }
    return true;
    }
};