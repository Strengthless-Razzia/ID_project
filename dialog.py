'''
Reception des données émise par un Arduino branché
à un port USB.
'''

import serial
import serial.tools.list_ports

print("Recherche d'un port serie...")

ports = serial.tools.list_ports.comports(include_links=False)

if (len(ports) != 0): # on a trouvé au moins un port actif

    if (len(ports) > 1):     # affichage du nombre de ports trouvés
        print (str(len(ports)) + " ports actifs ont ete trouves:") 
    else:
        print ("1 port actif a ete trouve:")

    ligne = 1

    for port in ports :  # affichage du nom de chaque port
        print(str(ligne) + ' : ' + port.device)
        ligne = ligne + 1
    portChoisi = int(input('Ecrivez le numero du port desire:'))
    
    baud = 9600
    # on établit la communication série
    arduino = serial.Serial(ports[portChoisi - 1].device, baud, timeout=1)

    print('Connexion a ' + arduino.name + ' a un baud rate de ' + str(baud))

    # si on reçoit un message, on l'affiche
    while True:
        data = arduino.readline()[:-2]
        if data:
            print(data)

else: # on n'a pas trouvé de port actif
    print("Aucun port actif n'a ete trouve")