def f():
    global a
    print(a)
    a = "hello"
    print(a)

a = 'world'
f()
print(a)