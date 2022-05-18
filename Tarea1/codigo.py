
def rut_checker(rut):
    digito_verificador = rut.split('-')[-1]
    numeros = rut.split('-')[0].replace('.', '')
    numeros_reversed = list(reversed(numeros))
    largo_rut = len(numeros_reversed)
    serie_numerica = 2
    suma_productos = 0
    for x in range(largo_rut):
        if(largo_rut == serie_numerica):
            serie_numerica = 2
        suma_productos = suma_productos + int(numeros_reversed[x])*serie_numerica
        serie_numerica += 1

    regla_digito_verificador = 11 - suma_productos%11
    if(regla_digito_verificador == 11):
        digito = 0
    elif(regla_digito_verificador == 10):
        digito = 'k'
        if(digito == digito_verificador):
            return True
    else:
        digito = regla_digito_verificador    
    if(int(digito_verificador) == int(digito)):
        return True
    else:
        return False