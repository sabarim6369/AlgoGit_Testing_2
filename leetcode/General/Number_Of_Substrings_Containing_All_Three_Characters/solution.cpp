class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int left = 0;
        int count = 0;
        for (int right = 0; right < n; right++) {
            mp[s[right]]++;
            while (mp.size() == 3) {
                count++;
                count += n - (right + 1);
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
        }
        return count;
    }
};