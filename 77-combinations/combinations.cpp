class Solution {
private:
    void solve(vector <vector<int>> &ans,vector <int> &output,int &n,int &k,int index){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<=n;i++){
            output.push_back(i);
            solve(ans,output,n,k,i+1);
            output.pop_back();
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector <vector<int>> ans;
        vector <int> output;
        solve(ans,output,n,k,1);
        return ans;
    }
};