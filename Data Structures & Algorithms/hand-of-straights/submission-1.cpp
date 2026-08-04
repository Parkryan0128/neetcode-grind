class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        std::unordered_map<int,int> my_map;
        for (int item : hand) {
            my_map[item]++;
        }

        for (int num : hand) {
            if (my_map[num] == 0) continue;

            int start = num;

            while (my_map[start-1] > 0) {
                start--;
            }

            while (my_map[start] > 0) {
                for (int i = start; i < start+groupSize; i++) {
                    if (my_map[i] == 0) return false;
                    my_map[i]--;
                }
            }
        }

        return true;

    }
};