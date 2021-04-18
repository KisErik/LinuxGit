#!/usr/bin/env python3


MELY_MGHK = 'aáoóuú'
MAGAS_MGHK = 'eéiíöőüű'

def hangrend(string):
    mely=False
    magas=False

    for e in string:
        if e in MELY_MGHK:
            mely=True
        if e in MAGAS_MGHK:
            magas=True

    if mely and magas:
        return "Vegyes"
    if mely and not magas:
        return "Mély"
    if not mely and magas:
        return "Magas"
    if not mely and not magas:
        return "Semmilyen"          


def main():
    words = ["ablak", "erkély", "kisvasút", "magas", "mély"]

    for e in words:
        print("{} --> {}".format(e,hangrend(e)))


#############################################################################

if __name__ == "__main__":
    main()
