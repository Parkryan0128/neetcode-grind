class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> count1(26,0);
        vector<int> count2(26,0);

        for (int i=0; i<s1.size(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        int l = 0;

        for (int i=s1.size(); i < s2.size(); i++) {
            if (count1 == count2) return true;

            count2[s2[i]-'a']++;
            count2[s2[l]-'a']--;
            l++;
        }

        return count1 == count2;

    }
};
