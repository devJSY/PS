# 내가 푼 타임에러 코드
t = int(input())

for _ in range(t):
    k = int(input())
    n = int(input())

    array = [[0]*n for i in range(14)]

    #first array
    for i in range(n):
        array[0][i] = i + 1
        
    for i in range(1, 14):
        for j in range(n):
            array[i][j] = sum(array[i-1][:j+1])
            
    print(array[k][n-1])

# 정답 소스 코드
T = int(input())

for _ in range(T):

    k = int(input())

    n = int(input())

    people = [ i for i in range(1, n+1)]

    for __ in range(k):

        for j in range(1,n):

            people[j] += people[j-1]

    print(people[-1])