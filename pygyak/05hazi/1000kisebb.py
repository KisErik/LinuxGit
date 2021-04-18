#!/usr/bin/env python3

"""Ezernél kisebb számok összege amik oszthatóak 3-mal vagy 5-tel """

def main():
    num= sum([n for n in range(1,1000) if n%3==0 or n%5==0 ])
    print(num)


if __name__ == '__main__':
    main()
    