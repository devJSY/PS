m = input()
list = []

for i in str(m):
    list.append(ord(i))
    
def num_pos(num: int):
    for i in list:
        if num == i:
            return list.index(i)
        else:
            pass
    return -1
        
for i in range(97,123):
    if num_pos(i) >= 0:
        print(num_pos(i), end =' ')
    else:
        print(-1, end=' ')

# string = input()
# alphabet = 'abcdefghijklmnopqrstuvwxyz'
# for i in alphabet:
#     print(string.find(i), end = ' ')
        

        