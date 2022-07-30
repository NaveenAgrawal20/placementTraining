def solve(a):
    n = len(a)
    t = [0]*(n+1)
    t[n] = 0

    for i in range(n-1,-1,-1):
        t[i] = max(t[i+1],a[i])
    # print(t)
    MAX = 9999999
    ans = 0
    lowerValue = set(MAX)
    for i in range(0,n):
        if t[i+1] > a[i]:
            ans = max(ans,lowerValue.b)


    

while True:
    a = [int(x) for x in input().split()]
    print(solve(a))

"""
2 5 3 1 4 9
2 1 3 9 5
2 1 3 5 9 10 12 11
"""