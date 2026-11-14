#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Tiempo de programacion por colaborador
//Richie
//Daniel
//Cesar

//Definicion de Constantes
#define tamFolio 3
#define gradoArbol 2

//Estructuras
  typedef struct Nodo{
    int dato;
    char dato[tamFolio];
    struct Nodo *hijos[gradoArbol];
  }

//Declaracion de las funciones
  //Funciones principales del programa #Terminado
  int menuPrinc();
  void limparPantalla();
  void pausarPantalla();
  
  //Funciones del Arbol # Trabajando Cesar Principal
  
  
  //Funciones del Nodo
  
  
  //Funciones de la opcion 1
  
  
  //Funciones de la opcion 2
  
  
  //Funciones de la opcion 3
  
  
  //Funciones de la opcion 4
  
  
  //Funciones de la opcion 5
  
  
  //Funciones de la opcion 6
  
  
  //Funciones de la opcion 7
  
  
  //Funciones de la opcion 8
  
  
  //Funciones de la opcion 9
  
  
  //Funciones de la opcion 10
  
  
  //Funciones de la opcion 11
  
  
  //Funciones de la opcion 12
  
  
  //Funciones de la opcion 13
  
  
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
      
        break;
      case 12:
      
        break;
      case 13:
        printf("Va a salir del programa \n Que tenga un buen dia :D");
        break;
      default:
      
        break;
    }
  }while(opcMenuPrincSel != 13);
  return 0;
}

//Definicion de las funciones
  //Funciones principales del programa
  int menuPrinc(){
    int opcSel;
    printf("==================== Menu Principal ====================");
    printf("\n1. Inserción\n2. Busqueda\n3. Supresión");
    printf("\n4. Descendientes (Nodos hijos)\n5.Ancestro (Nodo padre)");
    printf("\n6. Hojas\n7. Nivel\n8. Altura\n9. Peso\n10. Camino");
    printf("\n11. Longitud del camino\n12. Recorridos\n13. Salir");
    printf("\n\nIngrese la opcion que va a seleccionar: ");
    scanf("%d",&opcSel);
    return opcSel;
  }
  void limpiarPantalla() {
		#ifdef _WIN32
			system("cls");   // Para Windows
		#else
			system("clear"); // Para Linux / macOS
		#endif
	}
  void pausarPantalla(){
    printf("\n\nPresione [ENTER] para continuar ");
    int c;
    while( (c = getchar()) != '\n' && c != EOF);
  }
  //Funciones del Arbol
  
  
  //Funciones del Nodo
  
  
  //Funciones de la opcion 1
  
  
  //Funciones de la opcion 2
  
  
  //Funciones de la opcion 3
  
  
  //Funciones de la opcion 4
  
  
  //Funciones de la opcion 5
  
  
  //Funciones de la opcion 6
  
  
  //Funciones de la opcion 7
  
  
  //Funciones de la opcion 8
  
  
  //Funciones de la opcion 9
  
  
  //Funciones de la opcion 10
  
  
  //Funciones de la opcion 11
  
  
  //Funciones de la opcion 12
  
  
  //Funciones de la opcion 13
  
  