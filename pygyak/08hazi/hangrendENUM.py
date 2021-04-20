#!/usr/bin/env python3


from enum import Enum


class Mghk(Enum):
    MAGAS = 'eéiíöőüű'
    MELY = 'aáoóuú'




def hangrend(string):
    mely=False
    magas=False

    for e in string:
        if e in Mghk.MELY.value:
            mely=True
        if e in Mghk.MAGAS.value:
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
