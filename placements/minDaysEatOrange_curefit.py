memo={}; f=min
class Solution:
    def minDays(self, n: int) -> int:
        if n<2: return n
        if n in memo: return memo[n]
        a=1+f(self.minDays(n//2)+n%2, self.minDays(n//3)+n%3);memo[n]=a        
        return a