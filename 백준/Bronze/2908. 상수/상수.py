myNum = input().split()

box = []

rev_first_num = int(str(myNum[0])[::-1]);
box.append(rev_first_num)
rev_second_num = int(str(myNum[1])[::-1]);
box.append(rev_second_num)

print(max(box))


