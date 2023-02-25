# Cat_Laser_Toy

Cat Laser Toy é um projeto desenvolvido no primeiro semestre da faculdade de ciência da computação para a aula de circuitos elétricos e eletrônicos. Ele tem o objetivo de aplicar os nossos conhecimentos teóricos sobre Arduino, componentes eletrônicos e linguagem C++. A ideia do trabalho surgiu do projeto: https://projecthub.arduino.cc/Seafox_C/eeca5121-6ee3-4c70-84e5-c95e6a6a8677?ref=platform&ref_id=424_popular_part__&offset=721, onde a base de movimentação do Arduino é a mesma, porém com adaptações significativas no código e um acréscimo na parte física.

## Objetivo

O projeto tem o objetivo de entreter os gatos (ou outros animais) que acabam ficando sozinhos em casa o dia todo, evitando com que eles fiquem muito solitários e sedentários.

## Funcionamento

A base de funcionamento do projeto vêm da movimentação do diodo laser por dois servomotores, um no eixo x e outro no eixo y, formando assim um movimento fluído que vai em todas as direções aleatoriamente. Além disso, há um botão que marca o início da movimentação dos servos por um tempo em minutos que é pré-programado no código. Após esse tempo, os servos param e o laser desliga pela mesma quantidade de minutos e, quando esses minutos acabarem, ele religará novamente, com um funcionamento de intervalos em looping.

Para realizar esse timer de liga e desliga, também teriam outras soluções como o uso de uma tomada inteligente conectada à Alexa, assim o dono poderia ligar o brinquedo à distância.

Link para o esquema eletrônico do projeto: https://www.tinkercad.com/things/kFJVjPogW2b-copy-of-projeto-cee-versao-final/
