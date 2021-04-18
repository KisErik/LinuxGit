#!/usr/bin/env python3


def DecToBin(num):
    li=[]
    if num == 0:
        li.append(0)
    else:    
        while num > 0:
            li.append(num%2)
            num //= 2

    return reversed(li)



def main():
    s=input("Adjon meg egy számot: ")

    print("Binárisan: ")

    for e in DecToBin(int(s)):
        print(e, end="")
 
    print()
#############################################################################

if __name__ == "__main__":
    main()
