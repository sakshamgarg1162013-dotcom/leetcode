class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>0){
            if(pq.size()==1){
                return pq.top();
            }
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a>b){
                pq.push(a-b);
            }
            else if(b>a){
                pq.push(b-a);
            }
        }
        return 0;
    }
};