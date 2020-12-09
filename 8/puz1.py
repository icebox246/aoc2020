inputFile = open("./in1","r")
lines = inputFile.readlines()
inputFile.close()


class Instr:
    visited = False
    instr = ''
    arg = 0
    jmpInd = 0
    TjmpInd = 0
    def __init__(self, instr, arg):
        self.visited = False
        self.instr = instr
        self.arg = int(arg[1:])
        if instr != 'acc':
            self.jmpInd = Instr.TjmpInd
            Instr.TjmpInd+=1
        if arg[0] == '-':
            self.arg*=-1

Instrs = [] 


for line in lines:
    instr, arg = line.split(" ")
    Instrs.append(Instr(instr,arg))


for skip in range(Instr.TjmpInd):
    index = 0
    acc = 0
    while Instrs[index].visited == False:
        Instrs[index].visited = True
        if Instrs[index].instr == "nop":
            if Instrs[index].jmpInd == skip:
                index+=Instrs[index].arg
            else:
                index+=1
        elif Instrs[index].instr == "jmp":
            if Instrs[index].jmpInd != skip:
                index+=Instrs[index].arg
            else:
                index+=1
        elif Instrs[index].instr == "acc":
            acc+=Instrs[index].arg
            index+=1
        if index >= len(Instrs) or index < 0:
            print(acc)
            break
            
    for i in Instrs:
        i.visited = False

