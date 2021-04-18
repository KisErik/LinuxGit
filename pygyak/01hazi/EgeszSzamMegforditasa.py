#!/usr/bin/env python3

def Szammegforditasa(s):
    r=str(s)[::-1]
    r=int(r)
    return r
    


def main():
    s = input("Adjon meg egy szamot: ")
    if s.isdigit():
       print( Szammegforditasa(int(s)))
    else:
       print("Nem számot adott meg!")


        
if __name__ == '__main__':
    main()
    
