def solve(arr,sm):
    hashMap = {}
    n = len(arr)
    for i in range(0,n):
        comp = sm - arr[i]
        if comp in hashMap:
            return hashMap[comp],i
        hashMap[arr[i]] = i

A = [1, 4, 45, 6, 10, 8]
n = 16
i,j = solve(A,16)
 
print(f'Sum = {n} is given by index {i},{j} which are {A[i]},{A[j]}')