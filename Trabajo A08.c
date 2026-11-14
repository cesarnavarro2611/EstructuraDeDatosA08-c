#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Tiempo de programacion por colaborador
//Richie
//Daniel
//Cesar

//Declaracion de las funciones
  //Funciones principales del programa
  int menuPrinc();
  void limparPantalla();
  void pausarPantalla();

int main(){
  int opcMenuPrincSel = 0;
  do{
    opcMenuPrincSel = menuPrinc();
    switch (opcMenuPrincSel){
      case 1:
      
        break;
      case 2:
      
        break;
      case 3:
      
        break;
      case 4:
      
        break;
      case 5:
      
        break;
      case 6:
      
        break;
      case 7:
      
        break;
      case 8:
      
        break;
      case 9:
      
        break;
      case 10:
      
        break;
      case 11:
        printf("Va a salir del programa \n Que tenga un buen dia :D");
        break;
      default:
      
        break;
    }
  }while(opcMenuPrincSel != 11);
  return 0;
}

//Definicion de las funciones
  //Funciones principales del programa
  int menuPrinc(){
    int opcSel;
    printf("Deben ingresar Aqui el Menu");
    printf("\nIngrese la opcion que va a seleccionar: ");
    scanf("%d",&opcSel);
    return opcSel;
  }
  void limparPantalla(){
    
  }
  void pausarPantalla(){
    
  }
  
//Este es mi comentario escrito desde el editor de la tablet
//Si pueden verlo entonces ya puedo programar comodamente desde un editor instalado en la tablet