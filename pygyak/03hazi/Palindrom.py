#!/usr/bin/env python3   


def palindrome_1(szoveg):
    szoveg2=""
    hossz=len(szoveg)-1
    while hossz >= 0:
        szoveg2 += szoveg[hossz]
        hossz-=1  
    return szoveg==szoveg2    


def palindrome_2(szoveg):
    return szoveg == szoveg[::-1]  


def palindrome_3(szoveg):
    if len(szoveg)<=1:
        return True
    else:
        if szoveg[0]==szoveg[len(szoveg)-1]:
            return palindrome_3(szoveg[1:len(szoveg)-1])
        else:
            return False    

          


def main():
    txt="ablak"
    txt2="görög"
    

    print("PALINDROM_1:")
    print(" {0}: {1}".format(txt,palindrome_1(txt)))
    print(" {0}: {1}".format(txt2,palindrome_1(txt2)))
   
    print("PALINDROM_2:")
    print(" {0}: {1}".format(txt,palindrome_2(txt)))
    print(" {0}: {1}".format(txt2,palindrome_2(txt2)))
   

    print("PALINDROM_3:")
    print(" {0}: {1}".format(txt,palindrome_3(txt)))
    print(" {0}: {1}".format(txt2,palindrome_3(txt2)))
 


  

if __name__ == '__main__':
    main()
    
