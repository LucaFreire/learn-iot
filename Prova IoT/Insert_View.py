import requests 
import pyodbc
import time

proxies = {'https':"http://disrct:etsds10243110@10.224.200.26:8080"}

lista_Temperatura=[]
lista_Hum=[]
lista_Tempo=[]


def get_info_DHT():
    url_Temp = "https://prova-84054-default-rtdb.firebaseio.com/Freire/Sensor/Temperatura.json"
    url_Hum = "https://prova-84054-default-rtdb.firebaseio.com/Freire/Sensor/Umidade.json"
    
    Temp_Val = float(requests.get(url_Temp, proxies=proxies).content)
    hum_Val = float(requests.get(url_Hum, proxies=proxies).content)
    
    return Temp_Val, hum_Val


def Insert(sinal):
    server = 'CT-C-0013J\SQLEXPRESS01'
    database = 'tempdb'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    cursor.execute(f"INSERT dbo.Sensor (Temperatura, Umidade) VALUES ({sinal[0]},{sinal[1]});")
    cursor.commit()
    print("Inserido com sucesso!")
    

def View(sinal):
    print(f"Temperatura: {sinal[0]}")
    print(f"Umidade: {sinal[1]}")
    
    
while True:
    sinal = get_info_DHT()
    Insert(sinal)
    View(sinal)
    time.sleep(30)
