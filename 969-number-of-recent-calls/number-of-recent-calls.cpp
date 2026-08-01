class RecentCounter {
private:
    queue <int> q;
    int count;
public:
    RecentCounter() {
        count =0;
    }
    
    int ping(int t) {
        q.push(t);
        count++;
        while(!q.empty() && q.front()<t-3000){
            q.pop();
            count--;;
        }
        
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */