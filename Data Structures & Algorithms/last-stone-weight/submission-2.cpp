class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq;

        for (int item : stones) {
            pq.push(item);
        }

        while(pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            int res = abs(first-second);

            if (res > 0) {
                pq.push(res);
            }
        }


        return pq.size() == 0 ? 0 : pq.top();
    }
};
