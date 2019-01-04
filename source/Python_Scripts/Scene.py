import sys,os, subprocess
import json
def test():
    print("Hi hier ist die Test Funktion")

def erstelle_Data_Typ():
    return []

def open_data_typ(Speicherort,Name,Pc_Cache):
    

    
    subprocess.Popen(["explorer /select",Speicherort])

def erstellen(Name,Inputlist,root,Lokal_Pc_Cache):
    Speicherort=root+"\\"+Name
    os.makedirs(Speicherort)
    return Speicherort




if __name__=="__main__":
    erstellen("shoot1",[["Scene","Projects\\Scene1"]],"H:/dev/Pipeline/tests/Lokal",
    "H:/dev/Pipeline/tests/Lokal/Object/Pc_Cache.json")

