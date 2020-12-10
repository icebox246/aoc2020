
inpFile = open("./in1")
lines = inpFile.readlines();
inpFile.close();

numbers = []

for line in lines:
    num = int(line)
    numbers.append(num)

numbers.sort()

lN = 0

# cntD1 = 0
# cntD3 = 1

# for n in numbers:
#     if n - lN == 1:
#         cntD1+=1
#     elif n - lN == 3:
#         cntD3+=1
#     lN = n

target = numbers[-1] + 3

dp = list(range(200))
ex = list(range(200))

for i in range(200):
    dp[i] = 0
    ex[i] = 0

for n in numbers:
    ex[n] = 1

dp[0] = 1
ex[0] = 1
ex[target] = 1

for i in range(196):
    if dp[i] == 0 or ex[i] == 0:
        continue
    for j in range(1,4):
        if ex[i+j] == 1:
            dp[i+j]+=dp[i]  

print(dp[target])
