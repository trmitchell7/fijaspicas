#!/usr/bin/python3

answer = list(map(int, input("Please enter correct answer: ")))

def checkAnswer():
    question = list(map(int, input("Please enter your guess: ")))
    fija = 0
    pica = 0
    for i in range(4):
        if answer[i] == question[i]:
            fija += 1

    for n in answer:
        for p in range(4):
            if n == question[p]:
                pica += 1

    pica = pica - fija

    print ("Guess: " + ''.join(str(e) for e in question) + "\tFijas: " + str(fija) + "\tPicas: " + str(pica))
    return fija

def playGame():
    tries = 0
    while checkAnswer() < 4:
        tries += 1
        print ("Guess again!")
    print ("You won in " + str(tries) + " tries!")

playGame()
