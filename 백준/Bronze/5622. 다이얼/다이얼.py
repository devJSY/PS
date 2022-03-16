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