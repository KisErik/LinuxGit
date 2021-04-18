#!/usr/bin/env python3


def hello(s):
    print("Hello "+s+"!")


def main():
    s=input("Név:        ")
    

    hello(s)


    a=input("Adjon meg egy szöveget: ")
    #eredeti szöveg
    print(a)
    #A szöveg elsőbetűjét naggyá az összes többit kis betüvé írja át
    print(a.capitalize())
    #Minden betűt naggyá tesz
    print(a.upper())
    #Minden betűt kicsivé tesz
    print(a.lower())

    


        


if __name__ == '__main__':
    main()
    
