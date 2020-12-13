inp = open("./in1")
lines = inp.readlines()
inp.close()

px = 0
py = 0

cx = 10
cy = 1

angle = 0

for line in lines:
    if line[0] == 'F':
        num = int(line[1:])
        for i in range(num):
            px += cx
            py += cy
        # if angle == 0:
        #     cx += num
        # elif angle == 90:
        #     cy -= num
        # elif angle == 180:
        #     cx -= num
        # elif angle == 270:
        #     cy += num
    if line[0] == 'L':
        num = int(line[1:])
        while num > 0:
            tmp =cx
            cx = -cy
            cy = tmp
            num-=90

        # angle = (angle - num + 360) % 360
    if line[0] == 'R':
        num = int(line[1:])
        while num > 0:
            tmp =cx
            cx = cy
            cy = -tmp
            num-=90
        # angle = (angle + num + 360) % 360
    if line[0] == 'N':
        num = int(line[1:])
        cy+=num
    if line[0] == 'S':
        num = int(line[1:])
        cy-=num
    if line[0] == 'E':
        num = int(line[1:])
        cx+=num
    if line[0] == 'W':
        num = int(line[1:])
        cx-=num

print(str(px) + " " + str(py))
print(abs(px) + abs(py))

