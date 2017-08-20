# Biotransductor_microSD
Este proyecto propone el diseño e implementación de un Monitor tipo Holter, capaz de almacenar el registro cardiaco en una unidad de almacenamiento externa con el fin de visualizarlo y realizar su analisis posteriormente en una PC con la ayuda de MatLab.  
## Señal ECG
La señal ECG es en pocas palabras el resultado de la medida de diferencias de potencial que se obtienen en la superficie corporal debida a la propagación de ondas de despolarización a lo largo del miocardio que producen dipolos.  
![grafo](https://github.com/ingelectronicadj/Biotransductor_microSD/blob/master/ecg.png?raw=true "grafo")  

Para obtener la señal en cuestión se colocan 9 electrodos distribuidos en el tronco y, algunas veces, las extremidades del paciente los cuales sirven de transductores para obtener las diferencias de potenciales de tipo iónico debidas a las despolarizaciones de las diferentes regiones del músculo cardiaco, y convertirlas en potenciales electrónicos. Con esa cantidad de electrodos se obtienen 12 derivaciones que se clasifican en bipolares y unipolares las cuales permiten ver el corazón desde diferentes planos.
