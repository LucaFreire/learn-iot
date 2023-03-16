import pyodbc
import matplotlib.pyplot as plt


def Plot_Contador(): # Gráfico baseado por quantidade de inserts
    server = 'CT-C-0013J\SQLEXPRESS01'
    database = 'tempdb'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    cursor.execute(f"SELECT Temperatura, Umidade, Contador FROM dbo.Sensor")
    infos = cursor.fetchone()
    
    lista_Temperatura=[]
    lista_Hum=[]
    lista_Contador=[]
    
    while infos:
        lista_Temperatura.append(infos[0])
        lista_Hum.append(infos[1])
        lista_Contador.append(infos[2])
        infos = cursor.fetchone()
    
    plt.plot(lista_Contador, lista_Temperatura, label="Temperatura")
    plt.plot(lista_Contador, lista_Hum, label="Umidade")
    plt.xlabel('Quantidade de Inserts')
    plt.legend()
    plt.show()


def Plot_by_Date(): # Gráfico baseado por data 
    server = 'CT-C-0013J\SQLEXPRESS01'
    database = 'tempdb'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    cursor.execute(f"SELECT Temperatura, Umidade, Tempo, Contador FROM dbo.Sensor")
    infos = cursor.fetchone()
    
    lista_Temperatura=[]
    lista_Hum=[]
    lista_Count=[]
    
    while infos:
        lista_Temperatura.append(infos[0])
        lista_Hum.append(infos[1])
        lista_Count.append(infos[2])
        infos = cursor.fetchone()
    
    plt.plot(lista_Count, lista_Temperatura, label="Temperatura")
    plt.plot(lista_Count, lista_Hum, label="Umidade")
    plt.xlabel('Data')
    plt.legend()
    plt.show()


Plot_Contador()
Plot_by_Date()
