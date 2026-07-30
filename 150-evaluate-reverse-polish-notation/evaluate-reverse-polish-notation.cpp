class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s.push(stoi(tokens[i]));

            }
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(tokens[i]== "+"){
                    s.push(b+a);
                }
                if(tokens[i]=="-"){
                    s.push(b-a);
                }
                if(tokens[i]=="*"){
                    s.push(b*a);
                }
                if(tokens[i]=="/"){
                    s.push(b/a);
                }
            }
        }
        return s.top();
    }
};