#!/usr/bin/env python3

def drawTable(li):
    if len(li) > 8:
        print("Hiba")

    li2=[abs(n-7) for n in li]    

    print("+","-"*16,"+",sep="")   

    for i in range(8):
        print("|",end=" ")
        for k in li2:
                if k==i:
                    print("Q",end=" ")
                else:
                    print('.',end=" ")    
        print("|") 
    print("+","-"*16,"+",sep="")       



def main():

    drawTable([0,4,7,5,2,6,1,3])
    
        

###########################################################################################
if __name__ == '__main__':
    main()
    