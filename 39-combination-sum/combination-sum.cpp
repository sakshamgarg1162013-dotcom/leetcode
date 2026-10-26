class Solution {
private:
    void solve(vector<int>& candidates, vector<vector<int>>& ans,vector<int>& output, int target, int index) {

        if (target == 0) {
            ans.push_back(output);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            output.push_back(candidates[i]);

            solve(candidates, ans, output,target - candidates[i], i);

            output.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, ans, output, target, 0);

        return ans;
    }
};