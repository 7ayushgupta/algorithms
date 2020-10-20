class Solution:
    def solve(self, S):
        if (S==""):
            return []
        start = {}
        end = {}
        sort = []
        for i in range(len(S)):
            if S[i] not in start:
                start[S[i]] = i
                sort.append(S[i])
            end[S[i]] = i
        i = j = 0
        res = []
        for c in sort:
            if start[c] <= j:
                j = max(j, end[c])
            else:
                res.append(j - i + 1)
                i = start[c]
                j = end[c]
        res.append(j - i + 1)
        return res