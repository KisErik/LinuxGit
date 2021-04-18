#!/usr/bin/env python3


def main():
    li=[]
    li2=[]
    for e in range(100+1):
        li.append(e)
        li2.append(e**2)

    #  első száz természetes szám összegének a négyzete
    SquersOfSum= sum(li)**2

    #első száz természetes szám négyzetösszege
    SumOfSquers= sum(li2)

    print("""
    első száz természetes szám összegének a négyzete: {}
    
    első száz természetes szám négyzetösszege: {}

    az első száz természetes szám összegének a négyzete és 
    az első száz természetes szám négyzetösszege közti különbsége:

                            {}
     """.format(SquersOfSum,SumOfSquers,SquersOfSum-SumOfSquers))


#############################################################################

if __name__ == "__main__":
    main()
