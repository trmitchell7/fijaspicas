#!/usr/bin/python3

# test stuff, first py file

def test():
    var1=13
    var2=7
    while var1 != 0:
        print ("runing while var1 doesn't equal 0")
        if var1 < var2:
            print "\n this is a thing \n"
            var1 -= 1
            continue
        elif var1 = var2:
            print ("variables: var1 $var2 _var1")
            var1 = var2 - var1
    print ("done")

test()
