n = int(input())

if n == 1:
    print(1)
elif 2 <= n <= 7:
    print(2)
elif 8 <= n <= 19:
    print(3)
elif 20 <= n <= 37:
    print(4)
elif 38 <= n <= 61:
    print(5)
elif 62 <= n <= 70:
    print(6)
    

# n = int(input())
# c = 1
# while n > 1: # n>0이 아닌 n>1인 이유는 입력이 1인 경우를 거르기 위해
#     n-=(6*c)
#     c+=1
# print(c)