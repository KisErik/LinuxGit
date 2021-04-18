#!/usr/bin/env python3

def ListaSzorzata(li):
    n=1
    if len(li)!=0:
        for e in li:
            n*= e  
    return n             



def main():
    li1 = [1, 2, 3, 4, 5, 6] #szorzat:720
    li2 = [3, 33, 13, 34, 34] #1487772
    li3 = [12, 1, 0, 3, 4]#0
    li4 = []

    print(ListaSzorzata(li1))
    print("--"*10)
    print(ListaSzorzata(li2))
    print("--"*10)
    print(ListaSzorzata(li3))
    print("--"*10)
    print(ListaSzorzata(li4))

if __name__ == '__main__':
    main()
    