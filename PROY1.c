#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SerialPort.h"
#include <windows.h>
#include <mmsystem.h>
#define MAX_DATA_LENGTH 255

// Funciones prototipo
void autoConnect(SerialPort *arduino,char*);

int main(void)
{
 int num;
 //Arduino SerialPort object
 SerialPort *arduino;
 // Puerto serie en el que est� Arduino
 char* portName = "\\\\.\\COM3";
 // Buffer para datos procedentes de Arduino
 char incomingData[MAX_DATA_LENGTH];

 // Crear estructura de datos del puerto serie
 arduino = (SerialPort *)malloc(sizeof(SerialPort));
 // Apertura del puerto serie
 Crear_Conexion(arduino,portName);
 autoConnect(arduino,incomingData);
 
 
}
void autoConnect(SerialPort *arduino,char *incomingData)
 {
   int readResult;
   int i,n,j;
   char fichero1[]="arpa.wav";
   char fichero2[]="gong.wav";
   char fichero3[]="platillo.wav";
   

 
   // Espera la conexi�n con Arduino
   while (!isConnected(arduino))
    {
      Sleep(100);
      Crear_Conexion(arduino,arduino->portName);
    }
   //Comprueba si arduino est� connectado
   if (isConnected(arduino))
   {
      printf ("Conectado con Arduino en el puerto %s\n",arduino->portName);
   }
    // Bucle de la aplicaci�n
   while (isConnected(arduino))
   {
      readResult = readSerialPort(arduino,incomingData,MAX_DATA_LENGTH);
      if (readResult!=0){
      	printf("%s", incomingData);
      	//printf("\n%d\n",readResult);
 
        for(i=0;i<MAX_DATA_LENGTH;i++){
        	n=0;
	      if(incomingData[i]=='A'){
	 	   for(j=i+1;incomingData[j]!='@';j++)
	        {
	           if (incomingData[j]>='0' && incomingData[j]<='9')
	    	    n=n*10+incomingData[j]-'0';
		      
	        }
	         
	         
	         PlaySound(fichero1,NULL,SND_FILENAME | SND_ASYNC);
	       
	      }

		
		    
		      if(incomingData[i]=='B'){
		      	for(j=i+1;incomingData[j]>='@';j++){
		        	if (incomingData[j]>='0' && incomingData[j]<='9')
	    	          n=n*10+incomingData[j]-'0';
				}
				 
		          PlaySound(fichero2,NULL,SND_FILENAME | SND_ASYNC);	
                 
			  }
			  
			  if(incomingData[i]=='C'){
		      	for(j=i+1;incomingData[j]>='@';j++){
		        	if (incomingData[j]>='0' && incomingData[j]<='9')
	    	          n=n*10+incomingData[j]-'0';
				}
				  
		          PlaySound(fichero3,NULL,SND_FILENAME | SND_ASYNC);	
                 
			  }
			 
	  
	 } 	
   	
   }	     
    }
	
      Sleep(10);


   if (!isConnected(arduino))
      printf ("Se ha perdido la conexi�n con Arduino\n");
  
}



