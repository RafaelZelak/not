#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define Rkey 100
#include <limits.h>

int boss_var = 0;
int hp = 20;
int hp_inimigo = 10;
int countdown = 3;
int inimigo_hp = 1;
int batalha_var = 1, batalha_var_2 = 1, batalha_var_3 = 1;





void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void boss(){
gotoxy(67,3);
printf("/%c__/%c",92,92);
gotoxy(66,4);
printf("| %c  / |",92);
gotoxy(66,5);
printf("| 0  0 |");
gotoxy(67,6);
printf("%c .. /",92);
gotoxy(68,7);
printf("%c__/",92);

}
void sprite_inimigo_circulo1()
{


    gotoxy(30,12);
    printf("%c",3);
    if(batalha_var == 0){
    gotoxy(20, 21);
    printf(" ");
    }if(batalha_var == 1){
    gotoxy(20, 21);
    printf("%c",190);
    }if(batalha_var_2 == 0){
    gotoxy(40, 2);
    printf(" ");
    }if(batalha_var_2 == 1){
    gotoxy(40, 2);
    printf("%c",190);
    }if(batalha_var_3 == 0){
    gotoxy(60, 21);
    printf(" ");
    }if(batalha_var_3 == 1){
    gotoxy(60, 21);
    printf("%c",190);
    }









}
void circulo1()
{

  system("color 87");
  int a;
  gotoxy(50, 50);
  printf("%c",130);

//

  for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(0, a);
  }
//Parede horizontal superior
    for(a = 1; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 0);
  }

//Parede horizontal inferior
    for(a = 1; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 23);
  }

//sala1
//Parede vertical direita 1
  for(a = 1; a < 20; a++){
    printf("%c",219);
    gotoxy(20, a);

  }
//Sala 2
//Parede vertical direita 2
  for(a = 4; a < 24; a++){
    printf("%c",219);
    gotoxy(40, a);
  }
//Sala 3
//Parede vertical direita 3
  for(a = 1; a < 20; a++){
    printf("%c",219);
    gotoxy(60, a);
  }
//Parede canto direito
  for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(79, a);
  }

}
void npc_velh_1()
{
    gotoxy(13,6);
    printf("%c",2);
    gotoxy(0,7);
    printf("Oh ignobil cavalheiro o que lhe traz em direcao de tao decreptas profundezas\npegue esta pungente espada para proteger-lhe em sua turbulenta jornada\nnunca esqueça o nome dela que e Virgilio.\n\n");
    system("pause");
    system("cls");
    gotoxy(13,6);
    printf("%c",2);


    gotoxy(50, 50);
    printf("%c",130);
}
void atk_inimigo()
{

    srand(time(0));
    int val_atk = rand() % 4;


    if(val_atk == 0){
        hp--;
        gotoxy(41,12);
        printf("O INIMIGO UTILIZOU UM ATAQUE SIMPLES");
    }else if(val_atk == 1){
        hp = hp-3;
        gotoxy(43,12);
        printf("O INIMIGO UTILIZOU UM ATAQUE FORTE");
    }else if(val_atk == 2){
            hp_inimigo++;
            gotoxy(56,12);
        printf("O INIMIGO SE DEFENDEU");
        }else if(val_atk == 3){
        gotoxy(56,12);
        printf("O INIMIGO N/ FEZ NADA");
    }


}
void personagem()
{



    int x,a,d=2,cx[300]={2,2},cy[300]={2,2},t=1;
    char tecla='a';
    char run;

    while(tecla != 's')
    {
        sprite_inimigo_circulo1();
        while(tecla != 's' &&! (tecla=kbhit()))
        {
            //Apaga o caractere de traz
            for(x = t; x > 0; x--)
            {
                cx[x] = cx[x-1];
                cy[x] = cy[x-1];
            }
            //Bug personagem anda em qualquer tecla
            //Movimentação
             run=getch();

             if(d==0)cx[0]--;
             if(d==1)cy[0]--;
             if(d==2)cx[0]++;
             if(d==3)cy[0]++;


             gotoxy(cx[t],cy[t]);
             printf(" ");
             gotoxy(cx[0],cy[0]);
             printf("%c",219);

            //Velocidade
             Sleep(50);

            //Colisão Limite
             if(cy[0]==23)cy[0]--;
             if(cx[0]==79)cx[0]--;
             if(cy[0]==0)cy[0]++;
             if(cx[0]==0)cx[0]++;

             if(cx[0]==20){
                if(cy[0]>=1 && cy[0]<=19){

                    if(d == 2){cx[0]--;}
                    if(d == 0){cx[0]++;}
                }
             }
             if(cx[0]==40){
                if(cy[0]>=4 && cy[0]<=24){

                    if(d == 2){cx[0]--;}
                    if(d == 0){cx[0]++;}
                }
             }
                          if(cx[0]==60){
                if(cy[0]>=1 && cy[0]<=19){

                    if(d == 2){cx[0]--;}
                    if(d == 0){cx[0]++;}
                }
             }





            boss();
        //Ativador boss
            if(cy[0]==9){
                if(cx[0]>=60 && cx[0]<=70){batalha();boss_var = 1;  }
            }

        //Ativador inimigo 1
             if(batalha_var == 1){

                if(cx[0]==20){
                    if(cy[0]>=19 && cy[0]<=22){batalha(); batalha_var = 0; }
                }
             }
        //Ativador inimigo 2
             if(batalha_var_2 == 1){
                if(cx[0]==40){hp_inimigo = 10;batalha(); batalha_var_2 = 0;}
             }
        //Ativador inimigo 3
             if(batalha_var_3 == 1){
                if(cx[0]==60){hp_inimigo = 10;batalha(); batalha_var_3 = 0;}
             }
            if(cx[0]== 30 ){
                    if(cy[0] == 12){
                        hp = 20;
                    }
                }


        }

         if(tecla!='s')tecla=getch();
         if(tecla=='K')d=0;
         if(tecla=='H')d=1;
         if(tecla=='M')d=2;
         if(tecla=='P')d=3;
         //Limite Tela
         if(cy[0]==0||cy[0]==23||cx[0]==0||cx[0]==79)tecla='s';

    }


}
void batalha()
{
    int a;
    int k;

    int opcao;



    system("cls");
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(0, a);
  }
//Parede horizontal superior
    for(a = 1; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 0);
  }

//Parede horizontal inferior
    for(a = 1; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 23);
  }

//Parede canto direito
    for(a = 1; a < 24; a++){
    printf("%c",219);
    gotoxy(79, a);
  }
//menu
    for(a = 1; a < 80; a++){
    printf("%c",219);
    gotoxy(a, 16);
  }
  //Ataque
    gotoxy(6,7);
    gotoxy(2,18);
    printf("Clique [1] | Ataque Basico: 1 ATK");
    gotoxy(2,20);
    printf ("Clique [2] | Ataque Especial: 3 ATK");
    if(countdown <= 0){
    gotoxy(2,22);
    printf ("Countdown do 'Ataque Especial' - [0]");
    }else{
    gotoxy(2,22);
    printf("Countdown do 'Ataque Especial' - [%d]", countdown);
    }



//loop batalha
if(boss == 1){



}else{
while(hp_inimigo > 0){
  gotoxy(64,14);
  printf ("HP INIMIGP: %d",hp_inimigo);
  gotoxy(3,3);
  atk_inimigo();
  gotoxy(3,14);
  printf("HP: %d/20",hp);
  gotoxy(3,12);
  printf ("Escolha um ataque: ");

  gotoxy(22,12);
  scanf("%d",&opcao);


  if(opcao == 1){
    countdown--;
    hp_inimigo--;
    gotoxy(64,14);
    printf ("HP INIMIGP: %d",hp_inimigo);
    gotoxy(19,25);

    system("pause");
    batalha();
    system("cls");

  }else if(opcao == 2){
    if(countdown <= 0){
    hp_inimigo = hp_inimigo-3;
    countdown = 3;
    gotoxy(64,14);
    printf ("HP INIMIGP: %d",hp_inimigo);
    gotoxy(19,25);
    }else{
    gotoxy(3,10);
    printf("A habilidade esta em countdown, espere mais %d rodadas",countdown);
    gotoxy(19,25);
    }

    system("pause");
    batalha();
    system("cls");
        }
    //ATK DEV -- APAGAR ANTES DE POSTAR
    else if(opcao == 3){

    hp_inimigo = 0;
    gotoxy(65,14);
    printf ("HP INIMIGP: %d/10",hp_inimigo);
    gotoxy(19,25);

    system("pause");
    batalha();
    system("cls");

    }else{
        gotoxy(3,12);
        printf("Ataque n/ existente               ");
        gotoxy(19,24);
        system("pause");
        batalha();
        system("cls");
        }
    hp = 20;
    circulo1();
    }
}

}
int main()
{

    system("cls");
    circulo1();
    npc_velh_1();
    circulo1();
    personagem();
    getchar();

}
