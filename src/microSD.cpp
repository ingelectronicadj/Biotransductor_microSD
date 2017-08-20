/** CONEXIONES PINOUT ARDUINO NANO
microcontrolador    microSD
        CS    ----    D4
        SCK   ----    D13
        MOSI  ----    D11
        MISO  ----    D12
        5V    ----    +5v
        GND   ----    GND
**/
/***********************************************************************
 *              LIBRERIAS y CONSTANTES
 ***********************************************************************/
 #include <Arduino.h>
 #include <SD.h>
 #include <SPI.h>

 /***** microSD ******/
File myFile;

void configSerial(){
  Serial.begin(9600);
  Serial.println("Iniciando comunicacion serial ...");
}

void configMicroSD(){
  if (!SD.begin(4)){ //La declaracion del pin CS puede ser cualquier pinDigital
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("Inicializacion exitosa de la microSD");

  if(!SD.exists("dataset.csv")){
      myFile = SD.open("dataset.csv", FILE_WRITE);
      if (myFile) {
        myFile.println("Tiempo(ms),Sensor1,Sensor2,Sensor3"); // Escribe la primer fila del archivo
        myFile.close();
      } else {
        Serial.println("Error creando el archivo dataset.csv");
      }
  }
}
 /****** FIN FUNCIONES ADICIONALES AL SETUP******/

 /***********************************************************************
  *              SETUP CONFIGURACIÓN INICIAL
  ***********************************************************************/
  void setup() {
    configSerial();
    configMicroSD();
}

/****** FIN FUNCIONES ADICIONALES LOOP******/

/***********************************************************************
 *              LOOP BUCLE PRINCIPAL
 ***********************************************************************/
void loop() {
  myFile = SD.open("dataset.csv", FILE_WRITE);//abrimos  el archivo

  if (myFile) {
        Serial.print("Escribiendo SD: ");
        int sensor1 = analogRead(0);
        int sensor2 = analogRead(1);
        int sensor3 = analogRead(2);

        myFile.print(millis());
        myFile.print(",");
        myFile.print(sensor1);
        myFile.print(",");
        myFile.print(sensor2);
        myFile.print(",");
        myFile.println(sensor3);

        myFile.close(); //cerramos el archivo

        Serial.println("Tiempo(ms)=" + String(millis()) + ", sensor1=" + String(sensor1)
                        + ", sensor2=" + String(sensor2) + ", sensor3=" + String(sensor3));

    } else {
    Serial.println("Error al abrir el archivo");
    }
  delay(1000); //Escribe en la tabla cada 1s
}
