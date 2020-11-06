#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void cifratura();

int main(){
  cifratura();
}


void cifratura(){
  //inizializzo la stringa dell'utente
  char M[128];
  printf("Inserire stringa da cifrare: ");
  fgets(M, 128, stdin);
  printf("La tua stringa: %s\n", M);

  int scelta; //scegliere quale operazione eseguire
  char k[128]; //chiave
  time_t t;
  srand((unsigned) time(&t)); //seme

  puts("Premere 1 per inserire manualmente una chiave con cui cifrare la tua stringa");
  puts("Premere 2 per generare casualmente una chiave con cui cifrare la tua stringa");
  puts("Premere 0 o qualsiasi altro numero per uscire dal programma");
  printf("Inserire scelta: ");
  scanf("%d", &scelta);

  //ripulisco da eventuali caratteri rimasti
  char C[128]; //stringa risultante dallo XOR

  //uso un while e uno switch per gestire le opzioni e farle terminare quando l'utente non preme 1 o 2
  while(scelta==1 || scelta==2){
    switch(scelta){
      case 1:
       printf("Inserire chiave: ");
       getchar();
       fgets(k, 128, stdin);
       //la chiave deve avere la stessa lunghezza della stringa
       while(strlen(k)<strlen(M)){
         printf("Chiave troppo corta, reinserire: ");
         fgets(k, 128, stdin);
       }
       printf("Chiave di lunghezza corretta!\nLa tua chiave: %s", k);
       printf("La tua stringa cifrata: ");
       //faccio lo xor di carattere per carattere
       for(int i=0;i<strlen(M)-1;i++){
         C[i]=M[i]^k[i];
         printf("%c", C[i]);
       }
       printf("\nLa tua stringa di partenza ricifrata: ");
       //rieffettuo lo XOR tra C e k
       for(int i=0;i<strlen(M)-1;i++){
         printf("%c", C[i]^k[i]);
       }
       printf("\n");
       break;
      case 2:
       //genero carattere per carattere casualmente
       for(int i=0;i<strlen(M)-1;i++){
         k[i]=rand()%128;
       }
       printf("La tua chiave casuale: %s\n", k);
       printf("La tua stringa cifrata: ");
       //faccio lo XOR di carattere per carattere
       for(int i=0;i<strlen(M)-1;i++){
         C[i]=M[i]^k[i];
         printf("%c", C[i]);
       }
       printf("\nLa tua stringa di partenza ricifrata: ");
       //rieffettuo lo XOR tra C e k
       for(int i=0;i<strlen(M);i++){
         printf("%c", C[i]^k[i]);
       }
       printf("\n");
       break;
    }
    printf("Inserire scelta: ");
    scanf("%d", &scelta);
  }
}
