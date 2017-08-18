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

void configMicroSD(){
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(4)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
}
 /****** FIN FUNCIONES ADICIONALES AL SETUP******/

 /***********************************************************************
  *              SETUP CONFIGURACIÓN INICIAL
  ***********************************************************************/
  void setup() {
    configMicroSD();
}

/****** FIN FUNCIONES ADICIONALES LOOP******/

/***********************************************************************
 *              LOOP BUCLE PRINCIPAL
 ***********************************************************************/
void loop() {
  myFile = SD.open("tomalo.txt", FILE_WRITE);//abrimos  el archivo
  if (myFile) {
        Serial.print("Escribiendo SD: ");
        int sensor1 = analogRead(0);
        int sensor2 = analogRead(1);
        int sensor3 = analogRead(2);
        myFile.print("Tiempo(ms)=");
        myFile.print(millis());
        myFile.print(", sensor1=");
        myFile.print(sensor1);
        myFile.print(", sensor2=");
        myFile.print(sensor2);
        myFile.print(", sensor3=");
        myFile.println(sensor3);

        myFile.close(); //cerramos el archivo

        Serial.print("Tiempo(ms)=");
        Serial.print(millis());
        Serial.print(", sensor1=");
        Serial.print(sensor1);
        Serial.print(", sensor2=");
        Serial.print(sensor2);
        Serial.print(", sensor3=");
        Serial.println(sensor3);
    } else {
    Serial.println("Error al abrir el archivo");
    }
  delay(100);
}
