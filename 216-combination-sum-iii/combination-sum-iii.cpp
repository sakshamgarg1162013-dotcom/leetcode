class Solution {
private:
    void solve(vector<vector<int>> &ans,vector<int> &output,int &k,int n,int element){
        if(output.size()>k || n<0){
            return;
        }
        if(output.size()==k && n==0){
            ans.push_back(output);
            return;
        }
        for(int i=element;i<=9;i++){
            output.push_back(i);
            solve(ans,output,k,n-i,i+1);
            output.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        if(k>=n){
            return ans;
        }
        solve(ans,output,k,n,1);
        return ans;
    }
};