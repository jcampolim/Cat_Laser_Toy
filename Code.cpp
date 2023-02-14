/* Programa em C++

=^.^= "Cat Laser Toy": Lazer para seu Gato =^.^=

Esse programa faz com que você possa sair de casa sem se preocupar em deixar seu
gato entediado e solitário. Ao sair de casa, basta apertar um botão e o laser
começará a funcionar, ficando ligado e sendo movido pelos servos durante o tempo
pré-determinado no código (default = 60s) e desligado pelo tempo também preestabe-
lecido(default = 10s).
Você também pode determinar quantos ciclos ou etapas gostaria que o brinquedo rea-
lize (default = 3 ciclos), de modo que, terminados os ciclos, o brinquedo para de
funcionar. */

//Importação da biblioteca referente aos servos
#include <Servo.h> 

//Declaração das variáveis
Servo baseServo;			//Servo da base
Servo topoServo;			//Servo do topo
int basePos = 0;			//Posição inicial do servo da base
int topoPos = 0;			//Posição inicial do servo do topo
int baseMaxAngle = 60; 		//Ângulo máximo do servo da base
int topoMaxAngle = 45; 		//Ângulo máximo do servo do topo 
int laserPin = 1; 			//Laser
int laserIntens = 180; 		//Intensidade do Laser
int buttonPin = 2;			//Botão
int buttonState = 0; 		//Estado do botão
int etapaAtual = 0;			//Etapa atual
int etapaInicial = 0; 		//Etapa inicial
int etapaFinal = 3;			//Etapa final
unsigned long onTime = 0;	//Duração

//Inicialização das variáveis
void setup() {
  pinMode(laserPin, OUTPUT); //Configura o modo do pino do laser como saída 
  pinMode(buttonPin, INPUT);	//Configura o modo do pino do botão como entrada
}

//Comandos a serem executados enquanto o dispositivo estiver ligado
void loop() {
  
  //1ª condicional: no início, será lido o estado do botão e, enquanto não for
  //pressionado, nada acontecerá. Quando o botão for pressionado, "dá-se início
  //ao programa"
  if (etapaAtual == 0) {					
    buttonState = digitalRead(buttonPin);	
    if (buttonState == HIGH) {				
      etapaAtual = 1;						
    }
  }
  //Fim da 1ª condicional
  
  //2ª condicional: se, uma vez pressionado o botão, ainda não foi realizada a
  //quantidade de ciclos pré-determinados
  if (etapaAtual > etapaInicial && etapaAtual <= etapaFinal){
  
    baseServo.attach(6); //Conecta o servo da base ao pino 6
    topoServo.attach(8); //Conecta o servo do topo ao pino 8
    
    for (onTime = 0; onTime <= 60; onTime ++){             
  	//Tendo em vista o delay abaixo estipulado em 1s, esse laço durará 60s
      
      analogWrite(laserPin, laserIntens);
      //Acende o laser na intensidade pré-determinada
      
      basePos = rand() % baseMaxAngle; 
      topoPos = rand() % topoMaxAngle;
      //A posição de cada servo recebe um valor aleatório e com base no ângulo
      
      baseServo.write(basePos);
 	  topoServo.write(topoPos);
 	  //Os servos se movem para a nova posição 
      
      delay(1000);
      //Os servos permanecem por 1s na posição     
    }
    //Fim do laço de repetição
    
    digitalWrite(laserPin, LOW);	//Apaga o laser
    
    basePos = 0;				//Posição do servo da base = 0
    topoPos = 0;				//Posição do servo do topo = 0
    baseServo.write(basePos);	//Servo da base vai para a posição 0
    topoServo.write(topoPos);	//Servo do topo vai para a posição 0
    baseServo.detach();			//Desconecta-se o servo da base
    topoServo.detach();			//Desconecta-se o servo do topo
    //Esses comandos visam fazer com que os servos parem de funcionar
    
    delay(10000);
    //Aguarda por 10s com os servos parados e o laser apagado
    
    etapaAtual ++;
    //Com o final do ciclo (funcionamento + repouso), passa-se para o próximo,
    //a fim de que, eventualmente, complete-se todos 
  }
  //Fim da 2ª condicional
  
  //3ª condicional: se todos os ciclos tiverem sido realizados, volta-se ao ciclo
  //inicial
  if (etapaAtual == etapaFinal + 1) {
    etapaAtual = etapaInicial;
  }
  //Fim da 3ª condicional
}
//Fim do programa
