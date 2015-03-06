#!/usr/bin/env python

from random import randint
import sys
a=[0,1,2,3,4,5,6,7,8,9]
num=[]
def crea_perm():
    for i in range(10):
        for j in range(10):
            for k in range(10):
                for l in range(10):
                    if i!=j and i!=k and i!=l and j!=k and j!= l and k!=l:
                        num.append([i,j,k,l])

def mejora(a,b,p,f):
    for i in range(4):
        for j in range(4):
            if a[i]==b[j]:
                if i==j:
                    f=f-1
                else:
                    p=p-1
    return (p or f)

def picasYFijas(a,b):
    f=0
    p=0
    for i in range(4):
        for j in range(4):
            if a[i]==b[j]:
                if i==j:
                    f=f+1
                else:
                    p=p+1
    return [p,f]
    
def muestraHistoria():
    if hist==[]:
        print "\nno hay historial\n"
        return
    print "numero\tpicas\tfijas"
    for i in hist:
        print "%d%d%d%d\t%d\t%d"%(i[0][0],i[0][1],i[0][2],i[0][3],i[1],i[2])
def leeNum(pof):
    valido=0
    while not valido:
        pc=raw_input(pof)
        pc="".join(pc.split())
        if pc=="q" or pc == "Q":
            print "\nMi numero era",miNums,"\n"
            sys.exit(0)
        if len(pc)!=1 or pc not in "01234":
            print "ingrese un digito entre 0 y 4\n"
            continue
        p=int(pc)
        valido=1
    return p
def leePYF():
    valido=0
    while not valido:
        p=leeNum("picas? ")
        f=leeNum("fijas? ")
        if p+f>4:
            print "\nhay mas picas y fijas que numeros en el juego... Intente de nuevo\n"
            continue
        valido=1
    return (p,f)

def leeSuNumero():
    valido=0
    while not valido:
        crap=0
        n=raw_input("Ingrese su numero: ")
        n="".join(n.split())
        if n=="q" or n=="Q":
            print "\nMi numero era",miNums,"\n"
            sys.exit(0)
        if n=="h" or n=="H":
            muestraHistoria()
            continue
        if len(n)!=4:
            print "solo se acepta un numero de 4 digitos distintos\n"
            continue
        nn=[]
        for i in range(len(n)):
            if n[i] in "1234567890":
                nn.append(int(n[i]))
            else:
                print "ingrese SOLO numeros...\n"
                crap=1
                break 
        if crap:
            continue
        i=0
        while i<4 and not crap:
            j=i+1
            while j<4 and not crap:
                if nn[i]==nn[j]:
                    crap=1
                    print "todos los digitos deben ser diferentes\n"
                    continue
                j=j+1
            i=i+1
        if crap:
            continue
        valido=1
    return nn
#cuando el chango gana, el juego se acaba, y en ese caso se retorna cero
def juegaHumano():
    nn=leeSuNumero()
    sal=picasYFijas(nn,miNum)
    if sal[1]==4:
        print "Felicidades, ha ganado"
        print "Me faltaba decidirme por:"
        print num
        return 0
    else:
        print "tiene",sal[0],"picas y",sal[1],"fijas\n"
        hist.append((nn,sal[0],sal[1]))
        return 1
    
def juegoYo():
    p=num[randint(0,len(num)-1)]
    ps=str(p[0])+str(p[1])+str(p[2])+str(p[3])
    print "mi numero es",ps
    (picas,fijas)=leePYF()
    print
    if fijas==4:
        print "jeje, yo gano"
        print "Mi numero era",miNums
        return 0
    total=len(num)
    i=0
    while i<total:
        if not mejora(num[i],p,picas,fijas):
            i=i+1
        else:
            num.pop(i)
            total=total-1

#cuando la lista esta vacia, el jugador ha hecho trampa
    if len(num)==0:
        print "Chango tramposo"
        print "Mi numero era",miNums
        return 0
    return 1

#retorna 1 si la CPU empieza y 0 si el chango empieza
#tambien se encarga de mostrar la ayuda
def procesaParametros():
    if len(sys.argv)>2:
        sys.exit("Demasiados argumentos\n")
    if len(sys.argv)==1:
        return 0
    cmd=sys.argv[1]
    if cmd!="--help":
        if cmd!="--cpu":
            sys.exit("argumento no valido, pruebe la opcion --help\n")
        else:
            return 1
    else:
        print "modo de uso:"
        print "pyf [--cpu]\no\npyf --help"
        print "\nOPCIONES:"
        print "     --cpu: hace que la cpu sea quien juegue primero"
        print "     --help: muestra esta ayuda y termina el programa"
        print "\ndentro del juego se puede usar en cualquier momento el comando \"q\" para terminar el juego"
        print "\n puede verse un resumen de sus jugadas y los resultados obtenidos (picas y fijas para cada numero) al presionar \"h\" cuando sea SU turno\n"
        sys.exit(0)
#podria decirse que este es el main

empiezoYo=procesaParametros()
print "\n\nBienvenido a picas y fijas, version 0.3\n"
hist=[]
crea_perm()
miNum=num[randint(0,5039)]
miNums=str(miNum[0])+str(miNum[1])+str(miNum[2])+str(miNum[3])
si=1
if empiezoYo:
    P1=juegoYo
    P2=juegaHumano
elif 1==1:
    d=45
elif 2==P1:
    d=46
else:
    P2=juegoYo
    P1=juegaHumano

while si:
    si=P1()
    if si:
        si=P2()
