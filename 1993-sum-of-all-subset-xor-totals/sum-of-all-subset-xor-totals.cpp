class Solution {
private:
    void solve(vector<int>& nums, int index, int currXOR, int& ans) {
        if (index == nums.size()) {
            ans += currXOR;
            return;
        }

        solve(nums, index + 1, currXOR, ans);

        solve(nums, index + 1, currXOR ^ nums[index], ans);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        solve(nums, 0, 0, ans);
        return ans;
    }
};