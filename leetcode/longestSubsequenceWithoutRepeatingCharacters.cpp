class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<int> m(256, -1);
		int i = 0, res = 0;
	    for (int j = 0; j < s.length(); j++) {
			 i = max(i, m[s[j]] + 1);
			 m[s[j]] = j;
	         res = max(res, j - i + 1);
	    }
		return res;
	}
};