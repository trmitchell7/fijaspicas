#!/usr/bin/python3

answer = input("\n\nPlease enter correct answer: ")

def checkAnswer():
    question = input("\n\nPlease enter your guess: ")
    if len(question) == 4 and question.isdigit():
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

    else:
        print ("Guess needs to be 4 numbers, please try entering your guess again. \n \n")
        return checkAnswer()

def playGame():
    tries = 1
    while checkAnswer() < 4:
        tries += 1
        print ("Guess again!")
    print ("You won in " + str(tries) + " tries!")

playGame()
