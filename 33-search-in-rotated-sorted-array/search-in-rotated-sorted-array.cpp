class Solution {
private:
    int pivot(vector<int>& nums){
        int s = 0;
        int e = nums.size() - 1;
        int mid;

        while(s < e){
            mid = s + (e - s) / 2;
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;  
    }

    int binary(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid + 1;   // FIXED
            }
            else{
                e = mid - 1;   // FIXED
            }
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        int pi = pivot(nums);
        int n = nums.size();
        if(target >= nums[pi] && target <= nums[n-1]){
            return binary(nums, pi, n-1, target);
        } else {
            return binary(nums, 0, pi-1, target);
        }
    }
};