first = int(input())
second = int(input())

second1 = second//100
second2 = (second%100)//10
second3 = (second%100)%10

print(first*second3)
print(first*second2)
print(first*second1)
print(first*second)