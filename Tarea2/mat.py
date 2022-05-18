# regla = [1,1,-1,-1,-1,1,-1,1,-1]

tiempo = [-4,-3,-2,-1,0,1,2,3,4]
funcion = [2,1,0,1,2,3,0,2,1]
aux = 5
aux2 = 0
tiempo2 = []
funcion2 = []
j = 0
for i in range(len(tiempo) + aux):
    if (i < len(tiempo)):
        tiempo2.append(tiempo[i])
        
    else:  
        tiempo2.append(tiempo[-1] + aux2)
        aux2 = aux2 + 1
    if (i < aux):
        funcion2.append(0)
    else:
        funcion2.append(funcion[j])
        j = j + 1
        

    print(tiempo2, i)
    print(funcion2)
