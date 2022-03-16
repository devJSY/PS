a = list(map(int,input().split()))
c = int(input())

a[1] = a[1] + c

plusA = a[1]//60

a[0] = a[0] + plusA
a[1] = a[1] - 60*plusA

if a[0] >= 24:
    a[0] = a[0] - 24

print(a[0], end=" ")
print(a[1], end=" ")