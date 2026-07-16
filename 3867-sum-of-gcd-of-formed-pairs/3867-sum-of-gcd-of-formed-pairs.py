import math

class Solution:        
    def gcdSum(self, nums: list[int]) -> int:
        n = len(nums)
        prefixgcd = []
        maxi = -1
        for i in range(n):
            if nums[i] > maxi:
                maxi = nums[i]
            prefixgcd.append(math.gcd(nums[i],maxi))
        prefixgcd.sort()
        ans = 0
        for i in range(n//2):
            ans += math.gcd(prefixgcd[i],prefixgcd[n-1-i]) 
        return ans
        