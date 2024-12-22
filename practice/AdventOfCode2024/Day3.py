with open('./in-out/in.txt', 'r') as file:
    data = file.read().rstrip()
import re
nums = re.findall( r'mul\(([0-9]{1,3}),([0-9]{1,3})\)|don\'(t)\(\)|(d)o\(\)', data)
sum = 0
stopped = False
for num in nums:
    if num[3] == 'd':
        stopped = False
    elif num[2] == 't':
        stopped = True
    elif stopped == False:
        sum += int(num[0]) * int(num[1])
print(sum)