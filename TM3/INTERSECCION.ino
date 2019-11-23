
int interseccion(int color0,int color1){
  for(int i = 0;i>5;i++){
    pal.readColor(DER);
    pal.readColor(IZ);
  }
  
  if (color0 == GREEN && color1 == GREEN) {
      Serial.println("DAR VUELTA");
      mover(-200, 200);
      delay(2000);
      return 0;
  }
  if (color1 == GREEN) {
    Serial.println("Girar hacia izquierda");
      mover(200,200);
      delay(200);
      mover(-200,200);
      delay(600);
      mover(200,200);
      delay(200);
    return 0;
  }
  if ( color0 == GREEN) {
      Serial.println("Girar hacia derecha");
      mover(200,200);
      delay(200);
      mover(200, -200);
      delay(600);
      mover(200,200);
      delay(200);
      return 0;
  }
  
//  iu
  else{
    mover(200,200);
    delay(300);
    return 0;
  }
} 
