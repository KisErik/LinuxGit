#!/usr/bin/env python3


def normalize(string):
    return string.lower().replace(" ","")
    

def is_anagramma_01(string1,string2):
    string1=normalize(string1)
    string2=normalize(string2)

    st1_d={}
    st2_d={}

    for n in string1:
        if n not in st1_d:
            st1_d[n]=0       
        #    
        st1_d[n] += 1    

    for n in string2:
        if n not in st2_d:
            st2_d[n]=0       
        #    
        st2_d[n] += 1  

    for c in list(st1_d.keys()): 
        if c not in string2 or not(st1_d[c] == st2_d[c]):
            return False
        del st1_d[c],st2_d[c]    
    
    
    if len(st1_d)+len(st2_d)==0:
        return True

    return False    


def is_anagramma_02(string1,string2):
    
    li1=sorted(list(normalize(string1)))
    li2=sorted(list(normalize(string2)))
    
    for x,y in zip(li1,li2):
        if not(x==y):
            return False
    return True        

def main():
    
    print(is_anagramma_01("listen","silent"))
    print(is_anagramma_01("A gentleman","Elegant man"))
    print(is_anagramma_01("Clint Eastwood","Old west action"))
    print(is_anagramma_01("dormitory","dirty room"))  

    print(is_anagramma_02("listen","silent"))
    print(is_anagramma_02("A gentleman","Elegant man"))
    print(is_anagramma_02("Clint Eastwood","Old west action"))
    print(is_anagramma_02("dormitory","dirty room"))      

###########################################################################################
if __name__ == '__main__':
    main()
    