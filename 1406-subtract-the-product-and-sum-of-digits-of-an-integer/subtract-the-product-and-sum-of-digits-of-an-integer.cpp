class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro=1;
    int sum=0;
    while(n!=0){
        int digit=n%10;
        pro=pro*digit;
        sum=sum+digit;
        n=n/10;
    }
    int ans =pro-sum;
    return ans;
    }
};