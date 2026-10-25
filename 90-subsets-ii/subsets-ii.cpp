class Solution {
private:
    void solve(vector<vector<int>>& ans, vector<int>& nums,int index, vector<int>& output) {

        ans.push_back(output);

        for (int i = index; i < nums.size(); i++) {

            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            int element = nums[i];
            output.push_back(element);

            solve(ans, nums, i + 1, output);

            output.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> output;

        solve(ans, nums, 0, output);

        return ans;
    }
};