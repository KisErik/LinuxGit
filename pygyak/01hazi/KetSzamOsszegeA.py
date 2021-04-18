#!/usr/bin/env python3

import sys


def main():
    if len(sys.argv)==3:
        print(int(sys.argv[1])+int(sys.argv[2]))
    else:
        print("Hiba az argumentumok megadásában!")    

    


        
if __name__ == '__main__':
    main()
    