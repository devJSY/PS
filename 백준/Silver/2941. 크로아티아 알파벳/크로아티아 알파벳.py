s = input()
conut = 0
box = ["c=","c-","dz=","d-","lj","nj","s=","z="]

for i in box:
    if i in s:
        s = s.replace(i,",")
    else:
        continue

print(len(s))