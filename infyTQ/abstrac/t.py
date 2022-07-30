class A:
    def test1(self):
        print('a')

class B(A):
    def test(self):
        print('b')

class C():
    def test(self):
        print('c')

class D(C,B):
    def test2(self):
        print('d')

obj = D()
obj.test1()