class Solution {
public:
    string reorganizeString(string s) {
        std::unordered_map<char,int> my_map;

        for (char c : s) {
            my_map[c]++;
        }

        std::priority_queue<pair<int,char>> pq;

        for (auto& item : my_map) {
            pq.push({item.second,item.first});
        }

        pair<int,char> temp;
        string res = "";
        while (!pq.empty()) {
            auto [count, ch] = pq.top();
            pq.pop();
            res += ch;
            count--;
            if (temp.first > 0) {
                pq.push(temp);
            }
            temp = {count, ch};
        }

        if (res.length() != s.length()) {
            return "";
        }


        return res;
    }
};