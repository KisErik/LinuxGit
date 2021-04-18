#!/usr/bin/env python3


"""vissza adja azokat a karaktereket amik szerepelnek text-ben és chars-ben is   """
def valid(text, chars="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"):
    li = [c for c in text]
    betük=""
    for e in li :
        if e in chars:
            betük+=e
    return betük


def main():
    print(valid("Barking!"))                              
    print(valid("KL754", "0123456789"))
    print(valid("BEAN", "abcdefghijklmnopqrstuvwxyz"))    

        
if __name__ == '__main__':
    main()
    
