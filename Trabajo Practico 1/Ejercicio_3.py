#  Ignacio Berridy 11987
#  Programación Orientada a objetos/ Trabajo Práctico 1 - Ejercicio 3

texto = open('Tarea_Robot.MML','r')
texto_completo = texto.readlines()
texto.close()


#Mostrar texto en pantalla
for a in texto_completo:
    print (a)

#Cuenta y muestra en pantalla la cantidad de acciones

texto_cadena = str(texto_completo) #Convierte lo guardado en texto_completo para porder utilizar el metodo count
c=len(texto_cadena) #Cantidad de caracteres de la cadena

acciones = texto_cadena.count("Accion")
print ('La cantidad de acciones realizadas por el robot son:', int(acciones/2))

#Guarda las posiciones en donde compienza la palabra tiempo

#Arreglos que guardan las posiciones inicial y final 
tiempos_i = []
tiempos_f = []

tiempos_i.append(texto_cadena.find('<Tiempo>')+8)
tiempos_f.append(texto_cadena.find('<',tiempos_i[0]+1,c)-1)
tiempo_total =float(texto_cadena[tiempos_i[0]:tiempos_f[0]])

for i in range(texto_cadena.count('<Tiempo>')-1):
    tiempos_i.append(texto_cadena.find('<Tiempo>',tiempos_i[i]+1,c)+8)
    tiempos_f.append(texto_cadena.find('<',tiempos_i[i+1]-1,c)-1)
    if tiempos_i[i+1] != tiempos_f[i+1]:
        tiempo_total = tiempo_total + float(texto_cadena[tiempos_i[i+1]:tiempos_f[i+1]])
    else:
        tiempo_total = tiempo_total + float(texto_cadena[tiempos_i[i+1]])

print ("El tiempo total de funcionamiento del robot fue: ",tiempo_total)