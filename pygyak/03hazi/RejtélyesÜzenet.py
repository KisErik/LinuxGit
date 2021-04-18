#!/usr/bin/env python3

TEXT = """
Cbcq Dgyk!

Dmeybh kce cew yrwyg hmrylyaqmr:
rylsjb kce y Nwrfml npmepykmxyqg lwcjtcr!

Aqmimjjyi:

Ynyb
"""


def fordito(szoveg):
    newTEXT=""
    for e in szoveg:
        if 65<= ord(e) <=88 or 97<= ord(e) <=120: 
            newTEXT += chr(ord(e)+2)
        elif 88<ord(e)<=90 or 120 < ord(e) <=122:
            newTEXT += chr(ord(e)-24)
        else:
            newTEXT += e    
    return newTEXT
    

def main():
    print("Eredeti szöveg:")
    print(TEXT)

    print("Dekódolt szöveg:")
    print(fordito(TEXT))

    
   

    



if __name__ == "__main__":
    main()