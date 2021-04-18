#!/usr/bin/env python3

def SzamBekeres():
    s=input("Adjon meg egy páratlan számot: ")
    if int(s)%2 == 0:
        print("A megadott szám páros!")
        return SzamBekeres()
    else:
        return int(s)    
    

def PrintDiamond(m):
    txt="*"
    
    for i in range(m):
        if i < m//2:
            print(txt.center(m," "))
            txt +='**'
        else:
            print(txt.center(m," "))
            txt = txt[0:len(txt)-2]
            

def main():
   
    PrintDiamond(SzamBekeres())



#############################################################################

if __name__ == "__main__":
    main()
