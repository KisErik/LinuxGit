#!/usr/bin/env python3


def main():
    lista = [
    [ 'Anna', 159, 46, 19 ],
    [ 'Peti', 172, 74, 21 ],
    [ 'Ádám', 180, 80, 20 ],
    [ 'Gergő', 183, 78, 18 ],
    [ 'Bence', 176, 90, 23 ],
]

    #      balra igazítás|jobbra igazítás |jobbra igazítás|jobbra igazítás
    row = "| {nev:<16s} | {magassag:2d}cm | {suly:2d}kg | {eletkor:2d} |".format
    
    for p in lista:
        print(row(nev=p[0], magassag=p[1], suly=p[2], eletkor=p[3]))  

    


        
if __name__ == '__main__':
    main()
    