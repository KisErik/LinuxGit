#!/usr/bin/env python3


class MyQueue:
    def __init__(self):
        self.ver1=[]
        self.ver2=[]
        

    def append(self,num):
        return self.ver2.append(num)

    def popleft(self):   
        if(len(self.ver1)+len(self.ver2)==0):
            return None
        elif len(self.ver1)==0:
            return self.ver2.pop(0)
        else:
            return self.ver1.pop(0)

    def is_empty(self):
        if len(self.ver1)+len(self.ver2)==0:
            return True
        return False  


    def size(self):
        return len(self.ver1)+len(self.ver1)  


    def __str__(self):
        
        st1=[str(a) for a in self.ver1]
        st2=[str(a) for a in self.ver2]
        return  "["+" ".join(st1) + " ".join(st2)         


def main():
    s=MyQueue()

    print(s)                    #[
    print(s.is_empty())           #True         
    s.append(5)
    s.append(4)
    s.append(2)
    s.append(1)    
    print(s)                    #[5 4 2 1
    print(s.is_empty())           #False   
    print(s.size())               #4
    print(s.popleft())          #5
    print(s.popleft())          #4
    print(s.popleft())          #2
    print(s.popleft())          #1
    print(s.popleft())          #None

###########################################################################################
if __name__ == '__main__':
    main()
    