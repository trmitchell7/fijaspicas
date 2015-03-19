#!/usr/bin/python3

from random import randrange
answer = [[x for x in range(1,10)] for i in range(1,5)]
print (answer)
n1 = (len(answer[0]))
n2 = (len(answer[1]))
n3 = (len(answer[2]))
n4 = (len(answer[3]))
fija = 0
pica = 0
keyInAnswer = 0
guess = ""
bestGuess = 0
variable = []
guesshist = []
possible = []
picaVar = 0
fijaVar = 0
totalVar = 0



class Guess(object):
    def __init__(self,guess,fija,pica):
        self.guess = guess
        self.fija = fija
        self.pica = pica
        self.total = fija + pica


def computerGuess(x):
    global fija
    global pica
    print ("Is your number %s?" % (x))
    fija = int(input("How many fija? \t"))
    pica = int(input("How many pica? \t"))
    guesshist.append(Guess(x,fija,pica))
    return Guess(x,fija,pica)

# guesshist.append(guess(1234))
# guesshist.append(guess(5675))
# for i in range(len(guesshist)):
#     print (guesshist[i].guess)

computerGuess(1234)
computerGuess(5678)

if guesshist[0].total >= guesshist[1].total:
    guess = str(guesshist[0].guess)
    bestGuess = 0
else:
    guess = str(guesshist[1].guess)
    bestGuess = 1

if guesshist[0].total + guesshist[1].total < 4:
    keyInAnswer = True
else:
    keyInAnswer = False

def guess_gen():
    global variable
    global guess
    num = randrange(0,4)
    variable = num, int(guess[num])
    guess = guess.replace(str(variable[1]),"9")

def compare():
    global picaVar
    global fijaVar
    global totalVar
    picaVar = guesshist[len(guesshist)-1].pica - guesshist[bestGuess].pica
    fijaVar = guesshist[len(guesshist)-1].fija - guesshist[bestGuess].fija
    totalVar = guesshist[len(guesshist)-1].total - guesshist[bestGuess].total
    return totalVar, fijaVar, picaVar

def updatelogic():
    global picaVar
    global fijaVar
    global totalVar
    if keyInAnswer == True:
        if totalVar == 0:
            for i,v in enumerate(answer):
                answer[i].remove(variable[1])
        elif totalVar > 0:
            possible.append(variable[1])
    else:
        if totalVar < 0:
            possible.append(variable[1])
        elif totalVar == 0:
            for i,v in enumerate(answer):
                answer[i].remove(variable[1])

    if fijaVar < 0:
        for i,v in enumerate(answer):
            if i == variable[0]:
                answer[variable[0]] = [i for i in answer[variable[0]] if i == variable[1]]
            else:
                answer[i].remove(variable[1])


guess_gen ()
computerGuess (guess)
compare ()
print (fijaVar)
updatelogic ()
print (answer)
print (possible)


#while (n1 > 1) and (n2 > 1) and (n3 > 1) and (n4 >1):
