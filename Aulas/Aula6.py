import requests 
import json 


def get_info_by_URLs():
    proxies = {'https':"https://disrct:etsds10243110@10.224.200.26:8080"}    
    r = requests.get('https://github.com/', proxies = proxies)    
    print(r)
    print(r.content)


def download_random_dogs():
    proxies = {'https':"https://disrct:etsds10243110@10.224.200.26:8080"}
    url = 'https://random.dog/woof.json'
    
    img_data = requests.get(url, proxies = proxies).content
    new_url = json.loads(img_data)['url']
    img = requests.get(new_url, proxies = proxies).content
    
    with open('dog.jpg','wb') as dog_file:
        dog_file.write(img)
        
        
def get_infos_DHT():
    proxies = {'https':"https://disrct:etsds10243110@10.224.200.26:8080"}    
    url_temeperatura = 'https://teste2-9e0e2-default-rtdb.firebaseio.com/Freire/Sensor/Temperatura.json'
    url_umidade = 'https://teste2-9e0e2-default-rtdb.firebaseio.com/Freire/Sensor/Umidade.json'
    
    temperatura = int(requests.get(url_temeperatura, proxies = proxies).content)
    umidade = int(requests.get(url_umidade, proxies = proxies).content)
    print("Temperatura:", temperatura)
    print("Umidade:", umidade)
    

def get_info_by_name(Nome, country = ''): # Desafio
    proxies = {'https':"https://disrct:etsds10243110@10.224.200.26:8080"} 
    API = f"https://api.agify.io/?name={Nome}" if country == '' else f"https://api.agify.io/?name={Nome}&country_id={country}"
    
    my_json = requests.get(API, proxies = proxies).content
    infos = json.loads(my_json)
    
    print("Name:", infos["name"])
    print("Average age:", infos["age"])
    print("Count:", infos["count"])
    
# digite seu nome
get_info_by_name("Lucas")
