class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int freq[101] = {0};
        for(int x:nums){
            freq[x]++;
        }
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());

        vector <int> ans;
        for(int i=mn +1;i<mx;i++){
            if(freq[i]==0){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};