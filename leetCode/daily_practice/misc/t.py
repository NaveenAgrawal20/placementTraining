class Solution(object):
    def findMedianSortedArrays(self, A, B):
        m = len(A)
        n = len(B)  # considering n small
        if n < m:
            return self.findMedianSortedArrays(B, A)

        MAX = 10**6+1
        MIN = -1*(MAX)

        start = 0
        end = m
        while(start <= end):
            cut1 = (start+end)//2
            cut2 = (m+n+1)//2 - cut1

            # max for A at Left side
            maxALeft = MIN if cut1 == 0 else A[cut1-1]
            # min at A (Right) side
            minARight = MAX if cut1 == m else A[cut1]

            # max at B left
            maxBLeft = MIN if cut2 == 0 else B[cut2-1]
            # min at B (Right) side
            minBRight = MAX if cut2 == n else B[cut2]

            if maxALeft > minBRight:
                end = cut1-1

            elif maxBLeft > minARight:
                start = cut1+1

            else:
                if maxALeft <= minBRight and maxBLeft <= minARight:
                    if (m+n)%2 == 0:
                        return (max(maxALeft,maxBLeft)+min(minARight,minBRight))/2.0
                    else:
                        return max(maxALeft,maxBLeft)
while(True):
    s = Solution()
    # a = [int(x) for x in input().split()]
    # b = []
    a =[10,22,26]
    b =[]
    print(s.findMedianSortedArrays(a, b))

# [1,3]
# [2]
# []
# [2]
# [2]
# []
# []
# [2,4,5]
# [4,5,9,10,12,14]
# []
# [1,4,5]

# 1,3
# 2
# 1,2
# 3,4
# 10,22,26
# 21,23,24,28
# 10,22,26,28
# 21,23,24
# 10,22,28
# 21,23,24
# 0,0,0,0,0
# -1,0,0,0,0,0,1
