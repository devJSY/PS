min_time = 0

n = input()
n = n.lower()
n = list(n)
for i in n:
    if i == 'a' or i == 'b' or i == 'c':
        min_time += 3 
    elif i == 'd' or i == 'e' or i == 'f':
        min_time += 4 
    elif i == 'g' or i == 'h' or i == 'i':
        min_time += 5
    elif i == 'j' or i == 'k' or i == 'l':
        min_time += 6
    elif i == 'm' or i == 'n' or i == 'o':
        min_time += 7 
    elif i == 'p' or i == 'q' or i == 'r' or i == 's':
        min_time += 8 
    elif i == 't' or i == 'u' or i == 'v':
        min_time += 9    
    elif i == 'w' or i == 'x' or i == 'y' or i == 'z':
        min_time += 10
           
print(min_time)

##Another answer
# 1.
# s = input()
# sum = 0
# code = ["ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"]
# for i in s:
#     for j in range(8):
#         if i in code[j]:
#             sum += j + 3
# print(sum)    

# 2.
# import sys

# S = list(sys.stdin.readline().strip())

# alphabet = {'A':3, 'B':3, 'C':3,
#             'D':4, 'E':4, 'F':4,
#             'G':5, 'H':5, 'I':5,
#             'J':6, 'K':6, 'L':6,
#             'M':7, 'N':7, 'O':7,
#             'P':8, 'Q':8, 'R':8, 'S':8,
#             'T':9, 'U':9, 'V':9,
#             'W':10, 'X':10, 'Y':10, 'Z':10}

# ans = 0
# for s in S:
#     ans += alphabet[s]
# print(ans)
