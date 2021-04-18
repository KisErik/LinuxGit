#!/usr/bin/env python3

def Xor(var1,var2):
    if bool(var1):
        if bool(var2):
            return False
        else:    
            return True    
    else:
        if bool(var2):
            if bool(var1):
                return False
            else:    
                return True    
        return False


def main():
    str1="akarmi"
    str2="valami"
    str3=None
    str4=None

    li1=[1,2,3,4,5]
    li2=[5,6,7,8]
    li3=[]
    li4=[]
    print("Proba sztringekkel: (akarmi-valami) expected:False")
    print(Xor(str1,str2))
    print("--"*20)
    print("Proba sztringekkel: (akarmi-None) expected:True")
    print(Xor(str1,str3))
    print("--"*20)
    print("Proba sztringekkel: (None-None) expected:False")
    print(Xor(str3,str4))
    print("--"*20)
    
    print("Proba listákkal: ([1,2,3,4,5] - [5,6,7,8]) expected:False")
    print(Xor(li1,li2))
    print("--"*20)
    print("Proba listákkal: ([1,2,3,4,5] - []) expected:True")
    print(Xor(li1,li3))
    print("--"*20)
    print("Proba listákkal: ([] - []) expected:False")
    print(Xor(li3,li4))
    print("--"*20)
    

#############################################################################

if __name__ == "__main__":
    main()
