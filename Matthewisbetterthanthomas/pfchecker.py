#!/usr/bin/python3

answer = 0
guess = 0
tries = 1

def inputAnswer():
    global answer
    answer = input("\n\nPlease enter correct answer: ")
    return answer

def inputGuess():
    global guess
    guess = input("\n\nPlease enter your guess: ")
    return guess

def errorChecking(x):
    if len(x) == 4 and x.isdigit():
        duplicates = 0

        for e in x:
            for p in range(4):
                if e == x[p]:
                    duplicates += 1
        if duplicates == 4:
            return True
        else:
            return False

    else:
        return False

def checkAnswer(x, y):
        fija = 0
        pica = 0

        for i in range(4):
            if x[i] == y[i]:
                fija += 1

        for n in x:
            for p in range(4):
                if n == y[p]:
                    pica += 1

        pica = pica - fija

        print ("Guess: " + y + "\tFijas: " + str(fija) + "\tPicas: " + str(pica))
        return fija

def play():
    global tries
    while errorChecking(inputAnswer()) == False:
        print ("Answer needs to be 4 nonrepeating numbers, please try entering the answer again.")
    while errorChecking(inputGuess()) == False:
        print ("Guess needs to be 4 nonrepeating numbers, please try entering your guess again.")
    while checkAnswer(answer, guess) < 4:
        print ("Guess again!")
        while errorChecking(inputGuess()) == False:
            print ("Guess needs to be 4 nonrepeating numbers, please try entering your guess again.")
        tries += 1
    print ("You won in %s tries!" % (tries))

play()
