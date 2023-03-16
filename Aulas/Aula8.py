import requests 
import pyodbc
import time
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


def get_infos_DHT():
    proxies = {'https':"https://disrct:etsds10243110@10.224.200.26:8080"}    
    url_temeperatura = 'https://teste2-9e0e2-default-rtdb.firebaseio.com/Freire/Sensor/Temperatura.json'
    url_umidade = 'https://teste2-9e0e2-default-rtdb.firebaseio.com/Freire/Sensor/Umidade.json'
    
    temperatura = float(requests.get(url_temeperatura, proxies = proxies).content)
    umidade = float(requests.get(url_umidade, proxies = proxies).content)
    return temperatura, umidade


server = 'CT-C-0013G\SQLEXPRESS'
database = 'tempdb'
driver = '{ODBC Driver 17 for SQL Server}'

conn = pyodbc.connect('DRIVER='+driver+';SERVER='+server+'; \
                      DATABASE='+database+';Trusted_Connection=yes')
                      
cursor=conn.cursor()
cursor.execute("SELECT Temperatura, Umidade, timestamp FROM dbo.Sensor")
row = cursor.fetchone()

listaTemp=[]
listaUmid=[]
listatempo=[]

while row:
    listaTemp.append(row[0])
    listaUmid.append(row[1])
    listatempo.append(str(row[2]))
    row = cursor.fetchone()
    print("MyROW:", row)
    


#  Plot no gráfico

horas = []
listaX=[]

listaY=[x for x in range(0, max(listaUmid), 5)]

for i, e in enumerate(listatempo):
    horas.append(e[10:16])
    if i % 5 == 0:
        listaX.append(i)
    

plt.plot(horas, listaTemp, label="Temperatura")
plt.plot(horas, listaUmid, label="Umidade")
plt.xticks(listaX)
plt.yticks(listaY)
plt.legend()
plt.show()
