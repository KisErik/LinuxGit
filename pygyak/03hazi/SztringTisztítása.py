#!/usr/bin/env python3


def tisztitas(txt):
    txt=txt.replace(" ","")
    return txt




def main():
    s = input("Adjon meg egy mondatot: ")
    print(tisztitas(s))

    


##############################################################################

if __name__ == "__main__":
    main()