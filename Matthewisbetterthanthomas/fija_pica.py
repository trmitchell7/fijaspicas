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
keyLocations = [i for i in range(4)]
guess = ""
bestGuess = 0
variable = []
guesshist = []
possible = []
notpossible = []
picaVar = 0
fijaVar = 0
totalVar = 0
tries = 0


class Guess(object):
    def __init__(self,guess,fija,pica):
        self.guess = guess
        self.fija = fija
        self.pica = pica
        self.total = fija + pica


def computerGuess(x):
    global fija
    global pica
    global tries
    print ("Is your number %s?" % (x))
    fija = int(input("How many fija? \t"))
    pica = int(input("How many pica? \t"))
    guesshist.append(Guess(x,fija,pica))
    tries += 1
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
    possible.append(9)
else:
    keyInAnswer = False
    for i,v in enumerate(answer):
        answer[i].remove(9)
    notpossible.append(9)

def guess_gen():
    global variable
    global guess
    global keyLocations
    num = keyLocations[randrange(0,len(keyLocations))]
    keyLocations.remove(num)
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
            possible.append(variable[1])
        elif totalVar > 0:
            for i,v in enumerate(answer):
                if len(answer[i]) != 1:
                    answer[i].remove(variable[1])
            notpossible.append(variable[1])
    else:
        if totalVar < 0:
            possible.append(variable[1])
        elif totalVar == 0:
            for i,v in enumerate(answer):
                if len(answer[i]) != 1:
                    answer[i].remove(variable[1])
            notpossible.append(variable[1])

    if fijaVar < 0:
        for i,v in enumerate(answer):
            if i == variable[0]:
                answer[variable[0]] = [i for i in answer[variable[0]] if i == variable[1]]
            elif len(answer[i]) != 1:
                answer[i].remove(variable[1])
    elif fijaVar > 0:
        for i,v in enumerate(answer):
            if i == variable[0]:
                answer[variable[0]] = [i for i in answer[variable[0]] if i == 9]
            elif len(answer[i]) != 1:
                answer[i].remove(9)

if keyInAnswer == True:
    while len(possible)-1 != guesshist[bestGuess].total and len(notpossible) != (4-guesshist[bestGuess].total):
        guess_gen ()
        computerGuess (guess)
        compare ()
        updatelogic ()
        guess = guess.replace("9",str(variable[1]))
        print (answer)
        print (possible)
        print (notpossible)
else:
    while len(possible) != guesshist[bestGuess].total and len(notpossible) != (4-guesshist[bestGuess].total+1):
        guess_gen ()
        computerGuess (guess)
        compare ()
        updatelogic ()
        guess = guess.replace("9",str(variable[1]))
        print (answer)
        print (possible)
        print (notpossible)

if len(possible) == guesshist[bestGuess].total:
            for i in str(guesshist[bestGuess].guess):
                if int(i) not in possible and int(i) not in notpossible:
                    for j,v in enumerate(answer):
                        if len(answer[j]) != 1:
                            answer[j].remove(int(i))
                    notpossible.append(int(i))

else:
    for j in str(guesshist[bestGuess].guess):
        if int(j) not in notpossible and int(j) not in possible:
            possible.append(int(j))


for i,v in enumerate(guesshist):
    if guesshist[i].fija > 0 and guesshist[i].pica == 0:
        for j,t in enumerate(str(guesshist[i].guess)):
            if int(t) in possible:
                answer[j] = [u for u in answer[j] if u == int(t)]
                for k,p in enumerate(answer):
                    if len(answer[k]) != 1 and int(t) in answer[k]:
                        answer[k].remove(int(t))

bestGuess = guesshist[len(guesshist)-1]

print (answer)
print (possible)
print (notpossible)

print ("Number guessed in %s tries!" % (tries))
