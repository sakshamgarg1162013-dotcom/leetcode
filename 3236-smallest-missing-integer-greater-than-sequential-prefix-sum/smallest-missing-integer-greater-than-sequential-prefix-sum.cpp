class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int sum = nums[0];
        int i = 1;
        while (i < nums.size() &&
               nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }
        while (true) {

            bool found = false;
            for (int x : nums) {
                if (x == sum) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return sum;

            sum++;
        }
    }
};