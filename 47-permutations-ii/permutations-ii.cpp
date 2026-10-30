class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int index) {

        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = index; i < nums.size(); i++) {

            if (used.find(nums[i]) != used.end()) {
                continue;
            }

            used.insert(nums[i]);

            swap(nums[index], nums[i]);

            solve(nums, ans, index + 1);

            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        solve(nums, ans, 0);

        return ans;
    }
};