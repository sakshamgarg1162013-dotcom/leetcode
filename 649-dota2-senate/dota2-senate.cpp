class Solution {
public:
    string predictPartyVictory(string senate) {
        queue <int> r;
        queue <int> d;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
        }
        while(!d.empty() && !r.empty()){
            if(d.front()<r.front()){
                int val = d.front();
                d.pop();
                r.pop();
                d.push(val + senate.size());
            }
            else{
                int val = r.front();
                r.pop();
                d.pop();
                r.push(val + senate.size());
            }
        }
        if(r.empty()){
            return "Dire";
        }
        else{
            return "Radiant";
        }
        
    }
};