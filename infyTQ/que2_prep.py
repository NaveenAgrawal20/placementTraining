n = int(input())
L2 = [int(x) for x in input().split()]
L1 = [int(x) for x in input().split()]
for i in range(n):
    L2[i]=L2[i]-L1[i]

print(L2)
sum = 0

for i in range(n):
    sum += L2[i]

if sum < 0:
    print(abs(sum))
else:
    print(sum)

"""
7
3 4 6 7 8 10 12  
3 4 5 6 9 9 15
"""