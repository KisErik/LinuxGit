class Sor:
    

    def __init__(self):
        self.sor = []


    def __str__(self):
        return str(self.sor)


    def ures(self):
        if not(len(self.sor) == 0):
            return False        
        else:
            return True


    def betesz(self,num):
        self.sor.append(num)


    def kivesz(self):
        if self.ures():
            return None
        else:
            return self.sor.pop(0)


    def meret(self):
        return len(self.sor)

def main():
    v = Sor()      # üres sor létrehozása
    print(v)         # [
    print(v.ures())  # True
    v.betesz(1)
    v.betesz(4)
    v.betesz(5)
    print(v)         # [1 4 5
    print(v.meret()) # 3
    print(v.ures())  # False
    x = v.kivesz()
    print(x)         # 1
    print(v)         # [4, 5
    v.kivesz()
    v.kivesz()       # most már üres
    x = v.kivesz()
    print(x)         # None (jelezzük pl. így, hogy egy üres veremből akarunk kivenni)
        

###########################################################################################
if __name__ == '__main__':
    main()
    