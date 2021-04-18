#!/usr/bin/env python3


"""List comprehensions házifeladat  """


"""Az eljárás kiírja a stringeket tartalmazó listát és nagybetűsitett stringet + ! is"""
def ex_1():
    szavak=['auto', 'villamos', 'metro']
    nagybetüsSzavak=[sz.upper() + "!" for sz in szavak]
    print(f"ex_1: {szavak} --> {nagybetüsSzavak}")


"""Az eljárás kiírja a stringeket tartalmazó listát és a nagykezdőbetüs változatukat is """
def ex_2():
    szavak=['aladar', 'bela', 'cecil']
    nagybetüsSzavak=[sz.capitalize() for sz in szavak]
    print(f"ex_2: {szavak} --> {nagybetüsSzavak}")


"""Az eljárás kiír egy 10-elemű listát csupa 0-val.  """
def ex_3():
    li=[0 for n in range(10)]
    print(f"ex_3: {li}")


"""Az eljárás kiírja az inteket tartalmazó listát és a lista elemeinek 2* tartalmazó listát is """
def ex_4():
    numsli=[n for n in range(1,10+1)]
    doublenumli= [2*n for n in numsli]
    print(f"ex_4: {numsli} --> {doublenumli}")


"""Az eljárás kiírja az stringeket tartalmazó listát és a egészszámokkal teli listát is  """
def ex_5():
    strnums=[str(n) for n in range(1,10+1)]
    intnum = [int(n) for n in strnums]
    print(f"ex_5: {strnums} --> {intnum}")


"""Az eljárás kiír egy számot sztring formátumban, s egy listát amibe berakjuk a számunkat (számonként)"""
def ex_6():
    strszam="1234567"
    nums=[int(n) for n in strszam]
    print(f"ex_6: {strszam} --> {nums}")


"""Az eljárás kiír egy stringet és egy listát amin a szavak hosszát tartalmazza"""
def ex_7():
    mondat= 'The quick brown fox jumps over the lazy dog'
    wordslen=[len(w) for w in mondat.split()]
    print(f"ex_7: {mondat} --> {wordslen}")

"""Az eljárás kiír egy stringet és a szavainak kezdőbetűit egy listában  """
def ex_8():
    mondat= "python is an awesome language"
    words=[w[0] for w in mondat.split()]
    print(f"ex_8: {mondat} --> {words}")

"""Az eljárás kiír egy stringet és egy tuple-t ami a string szót és annak hosszát tartalmazza """
def ex_9():
    mondat='The quick brown fox jumps over the lazy dog'
    wpluslen= [(w,len(w)) for w in mondat.split()]
    print(f"ex_9: {mondat} --> {wpluslen}")


"""Az eljárás kiír egy listát a 10-nél kisebb páros számokat """
def ex_10():
    nums= [n for n in range(10) if n%2==0]
    print(f"ex_10: {nums}")

"""Az eljárás kiírja a 20 kisebb számok négyzetét ha a négyzetük páros """
def ex_11():
    nums= [n**2 for n in range(20) if n**2%2==0]
    print(f"ex_11: {nums}")


"""Az eljárás kiírja a 20 kisebb számok négyzetét ha a négyzetük 4-esre végződik """
def ex_12():
    nums= [n**2 for n in range(20) if n**2%10==4]
    print(f"ex_12: {nums}")



"""Az eljárás kiírja egy listában abc nagy betűit és kiírja egy stringként """
def ex_13():
    abc = [(chr(n)) for n in range(65,90+1)]
    abcinone =  ""
    for c in abc:
        abcinone+=c
    print(f"ex_13: {abc} --> {abcinone}")


"""Az eljárás kiírja listában lévő szavakat majd egy 
másik listát ahol el távolítsuk  a whitespace karaktereket  """
def ex_14():
    szavak=[' apple ', ' banana ', ' kiwi']
    köznélkül=[w.strip() for w in szavak]
    print(f"ex_14: {szavak} --> {köznélkül}")


"""Az eljárás kiírja listában a számokat és egyben"""
def ex_15():
    nums=[1, 0, 1, 1, 0, 1, 0, 0]
    strnums=''
    for c in nums:
        strnums+=str(c)
    print(f"ex_15: {nums} --> {strnums}")

def main():

    ex_1()
    ex_2()
    ex_3()
    ex_4()
    ex_5()
    ex_6()
    ex_7()
    ex_8()
    ex_9()
    ex_10()
    ex_11()
    ex_12()
    ex_13()
    ex_14()
    ex_15()

        
        


if __name__ == '__main__':
    main()
    