class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> mp;
        for(char task : tasks) {
            mp[task]++;
        }

        priority_queue<int> pq;

        for(auto it : mp) {
            pq.push(it.second);
        }

        int ans = 0;

        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 0; i <= n; i++) {

                if(!pq.empty()) {

                    int freq = pq.top();
                    pq.pop();

                    freq--;

                    if(freq > 0) {
                        temp.push_back(freq);
                    }
                }

                ans++;

                if(pq.empty() && temp.empty()) {
                    break;
                }
            }

            for(int freq : temp) {
                pq.push(freq);
            }
        }

        return ans;
    }
};