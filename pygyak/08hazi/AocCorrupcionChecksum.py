#!/usr/bin/env python3


def main():
    with open ("day02.txt" ,"r") as f:
        linesSum = 0

        for line in f.readlines():
            numli=[int(e) for e in line.split() ]                 
            maxNum=max(numli)
            minNUM=min(numli)
            linesSum += maxNum-minNUM

    print(linesSum)

###########################################################################################
if __name__ == '__main__':
    main()
    