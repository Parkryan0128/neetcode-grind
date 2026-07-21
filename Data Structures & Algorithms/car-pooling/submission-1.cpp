class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> add_p;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> remove_p;

        for (int i=0; i<trips.size(); i++) {
            add_p.push({trips[i][1] , trips[i][0]});
            remove_p.push({trips[i][2], trips[i][0]});
        }
    
        int location = 0;
        int passenger = 0;
        while (!add_p.empty()) {
            while (!add_p.empty() && add_p.top().first == location) {
                passenger += add_p.top().second;
                add_p.pop();
            }

            while (!remove_p.empty() && remove_p.top().first == location) {
                passenger -= remove_p.top().second;
                remove_p.pop();
            }

            if (passenger > capacity) return false;

            location++;
        }

        return true;
    }
};