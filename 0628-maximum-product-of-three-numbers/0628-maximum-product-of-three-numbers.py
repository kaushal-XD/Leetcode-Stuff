class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        n = len(nums)-1
        nums.sort()
        maxi = nums[n]*nums[n-1]*nums[n-2]
        mini = nums[0]*nums[1] * nums[n]
        return max(maxi,mini)