#!/usr/bin/env python3

def NumberSum_01(n):
    sum = 0
    for e in range(0,n+1):
        stringNum=str(e)
        for i in stringNum:
            sum += int(i)
    
    return sum


def NumberSum_02(n):
    li=[]
    for e in range(0,n+1):
        stringNum=str(e)
        for i in stringNum:
            li.append(int(i))
    return sum(li)        

            
def main():
    
    print(NumberSum_01(100))
    print("--"*8)    
    print(NumberSum_02(100))

#############################################################################

if __name__ == "__main__":
    main()
