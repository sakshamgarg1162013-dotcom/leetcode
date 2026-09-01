class Compare {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {

        if (a.second > b.second) {
            return true;
        }
        if (a.second == b.second && a.first < b.first) {
            return true;
        }

        return false;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        priority_queue<
            pair<int,int>,vector<pair<int,int>>,Compare> pq;

        for (auto it : mp) {
            pq.push({it.first, it.second});
        }

        vector<int> ans;

        while (!pq.empty()) {
            
            int num = pq.top().first;
            int freq = pq.top().second;

            for (int i = 0; i < freq; i++) {
                ans.push_back(num);
            }

            pq.pop();
        }

        return ans;
    }
};