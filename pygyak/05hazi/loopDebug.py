#!/usr/bin/env python3


"""Ez az eljárás kiírja 1-től a ism paraméterig a számok egymás mellé egyesével növelve  """
def loop(ism, debug=False):
    
    for i in range(1,ism+1):
        
        if debug and i==1:
            print(f"# {i} a ciklus eleje" ,sep="\n")
        
        print(i,end=" ")
        
        if debug and i==ism:
            print()
            print(f"# {i} a ciklus vége")
    print()


def main():
        
    loop(5)
    loop(5, debug=True)


if __name__ == '__main__':
    main()
    