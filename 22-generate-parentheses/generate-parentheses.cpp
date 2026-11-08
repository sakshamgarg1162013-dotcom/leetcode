class Solution {
private:
    void solve(vector<string> &ans, string &output, int open, int close, int n) {

        if(open > n || close > n) {
            return;
        }

        if(open == n && close == n) {
            ans.push_back(output);
            return;
        }

        if(open < n) {
            output.push_back('(');
            solve(ans, output, open + 1, close, n);
            output.pop_back();
        }

        if(close < open) {
            output.push_back(')');
            solve(ans, output, open, close + 1, n);
            output.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string output;
        vector<string> ans;

        solve(ans, output, 0, 0, n);

        return ans;
    }
};