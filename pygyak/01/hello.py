#!/usr/bin/env python3


import sys


def hello(s):
    if s=='Batman' or s=='Robin':
        print("Denevérveszély!")
    else :   
        print("Hello "+s+"!")

#megjegyzés
def main():
        print("Hello "+sys.argv[1]+"!")
        hello(sys.argv[1])


if __name__ == '__main__':
    main()
    

