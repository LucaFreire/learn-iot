import requests 
import pyodbc
import time

def get_infos_DHT():
    proxies = {'https':"https://disrct:etsds10243110@10.224.200.26:8080"}    
    url_temeperatura = 'https://teste2-9e0e2-default-rtdb.firebaseio.com/Freire/Sensor/Temperatura.json'
    url_umidade = 'https://teste2-9e0e2-default-rtdb.firebaseio.com/Freire/Sensor/Umidade.json'
    
    temperatura = int(requests.get(url_temeperatura, proxies = proxies).content)
    umidade = int(requests.get(url_umidade, proxies = proxies).content)
    return temperatura, umidade


def Insert(infos): # INSERT
    server = 'CT-C-0013G\SQLEXPRESS'
    database = 'temp.db'
    cnxn = pyodbc.connect('DRIVER={ODBC Driver 17 for SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    cursor.execute(f"INSERT dbo.Sensor (Temperatura, Umidade) VALUES ({infos[0]}, {infos[1]});")
    cursor.commit()
    print("Inserido com sucesso!")


def View(infos): # VIEW
    print(f"Temperatura: {infos[0]}")
    print(f"Umidade: {infos[1]}")
    

while True:
    valores = get_infos_DHT()
    View(valores)
    Insert(valores)
    time.sleep(120)

