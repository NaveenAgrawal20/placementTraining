def LCS(s1,s2):
    m = len(s1)
    n = len(s2)
    dp = [[0]*(n+1) for _ in range(m+1)]
    
    for i in range(0,m+1):
        for j in range(0,n+1):
            if i == 0 or j == 0:
                continue
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1+dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j],dp[i][j-1])

    index = dp[m][n]            
    lcs = ['']*index
    # print(lcs)
    i = m
    j = n
    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]:
            lcs[index-1] = s1[i-1]
            i-= 1
            j -= 1
            index -= 1
        else:
            if dp[i-1][j] > dp[i][j-1]:
                i -= 1
            else:
                j -= 1
    t = ''.join(lcs)
    print(t)
    
s1 = input()
s2 = input()
LCS(s1,s2)