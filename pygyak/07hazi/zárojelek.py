#!/usr/bin/env python3

nyit=["(","{","["]
csuk=[")","}","]"]

def test(kifejezés):
    zaro_jelek=[]
    for i in kifejezés:
        if i in nyit or i in csuk:
            zaro_jelek.append(i)

    if not(len(zaro_jelek)%2==0) or not(zaro_jelek[0] in nyit):
        return False

    for i in range(len(zaro_jelek)-1):
        if zaro_jelek[i] in nyit:
            if zaro_jelek[i+1]

    return True    


def main():
    test("((5+3)*2+1)") == True
    test("{[(3+1)+2]+}") == True
    test("(3+{1-1)}") == False
    test("[1+1]+(2*2)-{3/3}") == True
    test("(({[(((1)-2)+3)-3]/3}-3)") == False
        

###########################################################################################
if __name__ == '__main__':
    main()
    