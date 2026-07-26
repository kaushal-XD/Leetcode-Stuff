class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        """n = len(nums)-1
        nums.sort()
        maxi = nums[n]*nums[n-1]*nums[n-2]
        mini = nums[0]*nums[1] * nums[n]
        return max(maxi,mini)"""
        m1 = m2 = m3 = float("-inf")
        n1 = n2 = float("inf")
        for num in nums:
            if num >= m1 :
                m3 = m2
                m2 = m1
                m1 = num
            elif num >= m2 :
                m3 = m2
                m2 = num
            elif num >= m3 :
                m3 = num
            if num <= n1 :
                n2 = n1
                n1 = num
            elif num <= n2:
                n2 = num
        return max(m1*m2*m3 , n1*n2*m1)
