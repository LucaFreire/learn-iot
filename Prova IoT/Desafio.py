import pyodbc


def get_count_Inserts():
    server = 'CT-C-0013J\SQLEXPRESS01'
    database = 'tempdb'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    cursor.execute(f"SELECT Contador FROM dbo.Sensor")
    infos = cursor.fetchone()
    
    lista=[]
    
    while infos:
        lista.append(infos[0])
        infos = cursor.fetchone()
        
        
    print("Número de Inserts:" , lista[len(lista) - 1])
    
get_count_Inserts()
