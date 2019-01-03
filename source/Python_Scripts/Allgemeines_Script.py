import sys,os, subprocess
import json
def test():
    print("Hi hier ist die Test Funktion")

def erstelle_Data_Typ():
    return ["Blender Path"]

def open_data_typ(Speicherort,Name,Pc_Cache):
    jdata=json.load(Pc_Cache)

    
    subprocess.Popen([jdata["Blender Path"],Speicherort+"\\"+Name])

def erstellen(Speicherort,Name,Lokal_Pc_Cache):
    with open(file=Lokal_Pc_Cache,mode="r") as file:
        
        jdata=json.load(file)
    
    pythonscript=[
        "import bpy\n",
        "bpy.ops.wm.save_as_mainfile(filepath=\""+Speicherort+"/"+Name+".blend\")\n"
    ]
    endstring=""
    for line in pythonscript:
        endstring+=line
    print("moin")
    print(endstring)
    cmdcommand1=[jdata["Blender Path"],Speicherort+"/"+Name+".blend"]
    print(cmdcommand1)
    subprocess.Popen(cmdcommand1)
    #subprocess.Popen([jdata["Blender Path"],Speicherort+"\\"+Name+".blend"])




if __name__=="__main__":
    erstellen("H:/dev/Pipeline/tests/Lokal",
    "Object","H:/dev/Pipeline/tests/Lokal/Object/Pc_Cache.json")

