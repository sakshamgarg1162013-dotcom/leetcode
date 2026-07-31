class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string dir;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {

                if (dir == "" || dir == ".") {
                
                }
                else if (dir == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else {
                    st.push(dir);
                }

                dir.clear();
            }
            else {
                dir += path[i];
            }
        }

        vector<string> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        string res;

        for (string &s : ans) {
            res += "/" + s;
        }

        return res.empty() ? "/" : res;
    }
};