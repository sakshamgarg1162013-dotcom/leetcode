class Solution {
private:
    void solve(vector<string>& ans, string& s, string output,int index, int parts){
        
        if(parts == 4) {
            if(index == s.size()) {
                output.pop_back();
                ans.push_back(output);
            }
            return;
        }
        for(int len = 1; len <= 3; len++) {
            if(index + len > s.size()) {
                break;
            }
            string temp = s.substr(index, len);
            if(len > 1 && temp[0] == '0') {
                continue;
            }
            if(stoi(temp) > 255) {
                continue;
            }
            string newOutput = output + temp + ".";
            solve(ans, s, newOutput, index + len, parts + 1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {

        vector<string> ans;

        if(s.size() < 4 || s.size() > 12) {
            return ans;
        }

        solve(ans, s, "", 0, 0);

        return ans;
    }
};