#!/usr/bin/env python3

"""Megkapja paraméterül hogy meddig kell megtalálnunk az összes Münh. számot majd vissztér azok listájával """
def Münh(n):
    li=[]
    for e in range(n):
        stringe= str(e)
        numSum=sum([(int(n)**int(n)) for n in stringe if not(int(n)==0)])
        if numSum == e:
            li.append(e)
    return li


"""Kiszámolja a legnagyobb münh. számot és visszatér vele"""
def Legnagyobb():
    for e in range(440000000,1,-1):
        stringe= str(e)
        numSum=sum([(int(n)**int(n)) for n in stringe if not(int(n)==0)])
        if numSum == e:
            return e        
    return 0

def main():

    print("Münchausen számok 10000 alatt :")
    print(Münh(10000))

    print("Legnagyobb münchausen szám:")
    print(Legnagyobb())

    
            
            
    


if __name__ == '__main__':
    main()
    
