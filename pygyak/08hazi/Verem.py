#!/usr/bin/env python3


class Verem:


    def __init__(self):
        self.verem = []


    def __str__(self):
        st=[str(a) for a in self.verem]
        return "["+" ".join(st)


    def ures(self):
        if not(len(self.verem) == 0):
            return False        
        else:
            return True


    def betesz(self,num):
        self.verem.append(num)


    def kivesz(self):
        if self.ures():
            return None
        else:
            return self.verem.pop()


    def meret(self):
        return len(self.verem)

def main():
    v = Verem()      # üres verem létrehozása
    print(v)         # [
    print(v.ures())  # True
    v.betesz(1)
    v.betesz(4)
    v.betesz(5)
    print(v)         # [1 4 5
    print(v.meret()) # 3
    print(v.ures())  # False
    x = v.kivesz()
    print(x)         # 5
    print(v)         # [1 4
    v.kivesz()
    v.kivesz()       # most már üres
    x = v.kivesz()
    print(x)         # None (jelezzük pl. így, hogy egy üres veremből akarunk kivenni)
        

###########################################################################################
if __name__ == '__main__':
    main()
    