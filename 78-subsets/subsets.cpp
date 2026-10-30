class Solution {
private:
    void solve(vector<int>& nums, vector<int> output,
               vector<vector<int>>& ans, int index) {

        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        // Include
        output.push_back(nums[index]);
        solve(nums, output, ans, index + 1);

        // Exclude
        output.pop_back();
        solve(nums, output, ans, index + 1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        solve(nums, output, ans, 0);

        return ans;
    }
};