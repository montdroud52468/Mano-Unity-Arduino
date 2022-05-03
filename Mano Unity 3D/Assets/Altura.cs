using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class Altura : MonoBehaviour
{
    SerialPort serialPort=new SerialPort("COM15",9600);

    void Start(){
        serialPort.Open();
        serialPort.ReadTimeout=100;

    }
    
    void Update(){
        try{
           if(serialPort.IsOpen){
               print(serialPort.ReadLine());
           }  
        }catch (System.Exception ex){     
            ex=new System.Exception();
        }
    }
    
}
