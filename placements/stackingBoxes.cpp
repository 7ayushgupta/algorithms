#include "solution.hpp"
using namespace std;

class Solution {
    public:
    int solve(vector<vector<int>>& matrix) {
        sort(matrix.begin(), matrix.end(), [](auto a, auto b) {
            if (a[0] == b[0]) return a[1] > b[1];  // sort ht by larger
            return a[0] < b[0];                    // width by smaller first
        });
        vector<int> hts;
        for (auto x : matrix) {
            hts.push_back(x[1]);
        }
        vector<int> lis;
        for (int x : hts) {
            auto lower = lower_bound(lis.begin(), lis.end(), x);
            if (lower == lis.end())
                lis.push_back(x);
            else
                *lower = x;
        }
        return lis.size();
    }
};
