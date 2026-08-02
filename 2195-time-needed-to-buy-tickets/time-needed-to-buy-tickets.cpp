class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        queue<int> q;

        for (int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int idx = q.front();
            q.pop();

            tickets[idx]--;
            count++;

            if (idx == k && tickets[k] == 0) {
                return count;
            }

            if (tickets[idx] > 0) {
                q.push(idx);
            }
        }

        return count;
    }
};