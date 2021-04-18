#!/usr/bin/env python3



def main():
    all=0
    valid=0
    invalid=0

    file = open('day04.txt', 'r')

    passphrases=file.readlines()

    for line in passphrases:
        for word in line.split():
            all+=1
            count=line.count(word) 
            if count > 1:
                invalid+=1
            else:
                valid+=1               

    print("all:",all)
    print("valid:",valid)
    print("invalid",invalid)
    file.close()
    
    
###########################################################################################
if __name__ == '__main__':
    main()
    
