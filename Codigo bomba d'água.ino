#define boia_caixa 3
#define boia_cisterna 2
#define rele_bomba 7

#define ledcaixa   6
#define ledbomba  4
#define ledcisterna 5

#define tempoocioso 30000   //1800000
int estadocaixa;
int estadocisterna;

void setup() {
  Serial.begin(9600);
  pinMode(boia_caixa,INPUT_PULLUP);
  pinMode(boia_cisterna,INPUT_PULLUP);
  
  pinMode(rele_bomba,OUTPUT);
  
  pinMode(ledcaixa,OUTPUT);
  pinMode(ledbomba,OUTPUT);
  pinMode(ledcisterna,OUTPUT);

  Serial.println("INICIALIZANDO 1/2");
  digitalWrite(ledcaixa,HIGH);
  digitalWrite(ledcisterna,HIGH);
  digitalWrite(ledbomba,HIGH);
  delay(2000);
  digitalWrite(ledcaixa,LOW);
  digitalWrite(ledcisterna,LOW);
  digitalWrite(ledbomba,LOW);
  Serial.println("INICIALIZANDO 2/2");
  
}

void loop() {
  estadocaixa = !digitalRead(boia_caixa);
  estadocisterna = !digitalRead(boia_cisterna);
  
  Serial.println(estadocaixa);
  Serial.println(estadocaixa);

  if(estadocaixa == 0 and estadocisterna == 1){
    Serial.println("---------------------");
    digitalWrite(rele_bomba,LOW);//invertido
    Serial.println("CAIXA VASIA");   digitalWrite(ledcaixa,LOW);
    Serial.println("CISTERNA CHEIA");digitalWrite(ledcisterna,HIGH);
    Serial.println("BOMBA LIGADA");  digitalWrite(ledbomba,HIGH);
    Serial.println("---------------------");
    delay(4000);
    }
  if(estadocaixa == 1 and estadocisterna == 1){
    Serial.println("---------------------");
    digitalWrite(rele_bomba,HIGH);//invertido
    Serial.println("CAIXA CHEIA");    digitalWrite(ledcaixa,HIGH);
    Serial.println("CISTERNA CHEIA"); digitalWrite(ledcisterna,HIGH);
    Serial.println("BOMBA DESLIGADA");digitalWrite(ledbomba,LOW);
    Serial.println("---------------------");
    }
  if(estadocaixa == 1 and estadocisterna == 0){
    Serial.println("---------------------");
    digitalWrite(rele_bomba,HIGH);//invertido
    Serial.println("CAIXA CHEIA");    digitalWrite(ledcaixa,HIGH);
    Serial.println("CISTERNA VASIA"); digitalWrite(ledcisterna,LOW);
    Serial.println("BOMBA DESLIGADA");digitalWrite(ledbomba,LOW);
    Serial.println("---------------------");
    }
  if(estadocaixa == 0 and estadocisterna == 0){
    Serial.println("---------------------");
    digitalWrite(rele_bomba,HIGH );//invertido
    Serial.println("CAIXA VASIA");    digitalWrite(ledcaixa,LOW);
    Serial.println("CISTERNA VASIA"); digitalWrite(ledcisterna,LOW);
    Serial.println("BOMBA DESLIGADA");digitalWrite(ledbomba,LOW);
    Serial.println("---------------------");
    
    }
  delay(tempoocioso);
}
