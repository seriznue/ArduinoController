String cadenaCharEntrada = "";  
char vectorChar[20];
bool finCadena = false;

void setup() {
  Serial.begin(115200);
  cadenaCharEntrada.reserve(20);
  pinMode(13,OUTPUT);

}

void loop() { 
  if(finCadena){                               //Se termino de recibir una cadena completa
    finCadena = false;                                  //Permitimos volver a recibir otra cadena
    cadenaCharEntrada.toCharArray(vectorChar,20);   //Convertimos el string a un vectorChar
    int numeroEntero = atoi(vectorChar);            //Convertimos un vectorChar a un entero
    
    //Serial.print("Se recibio ");
    //Serial.println(numeroEntero);
   
    if(numeroEntero == 1){
        digitalWrite(13,HIGH);
      
    }
    else if(numeroEntero == 2){
      digitalWrite(13,LOW);
    }
    else if(numeroEntero == 3){
      Serial.print(analogRead(A0));
      
    }
    cadenaCharEntrada = "";
    
    
  }
}

void serialEvent(){
  //Recepción de datos Seriales
  
  while (Serial.available()) {              //Si existen datos seriales, leer a todos
    char CaracterEntrada = Serial.read();   //Leer 1 byte serial recibido
   
    cadenaCharEntrada += CaracterEntrada;   //Agregar el nuevo char a una cadena String 
    if (CaracterEntrada == '\n') {          //Si el char o byte recibido es un fin de linea, activa la bandera
      finCadena = true;                        //Si la bandera finCadena = 1, entonces la transmision esta completa
    }
    
  }
  
}
