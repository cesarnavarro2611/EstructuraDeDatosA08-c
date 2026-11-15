#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Tiempo de programacion por colaborador
//Richie
//Daniel
//Cesar 6 horas

//Definicion de Constantes
#define tamFolio 3
#define gradoArbol 2

//Estructuras
  typedef struct Nodo{
    int dato;
    char datoChar[tamFolio];
    struct Nodo *hijos[gradoArbol];
  } Nodo;

//Declaracion de las funciones
  //Funciones principales del programa #Terminado
  int menuPrinc();
  void limparPantalla();
  void pausarPantalla();
  int solicDatoInt();
  
  //Funciones del Arbol
  void insertar(Nodo *nodo, int dato);
  void preOrder(Nodo *nodo);
  void inOrder(Nodo *nodo);
  void postOrder(Nodo *nodo);
  Nodo *busqValNodo(Nodo *nodo, int dato);
  
  //Funciones del Nodo
  char intToChar(int dato);
  Nodo *nuevoNodo(int dato);
  
  //Funciones de la opcion 1
  void insertarNuevoNodo(Nodo *arbol);
  int verifDatoOpcUno(Nodo *arbol, int dato);
  
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
  Nodo *arbol = NULL;
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
  int solicDatoInt(){
    int n;
    printf("Ingresa el dato: ");
    scanf("%d",&n);
  }
  //Funciones del Arbol
  void insertar(Nodo *nodo, int dato){
    if(dato < nodo->dato){
      if(nodo->hijos[0] == NULL){
        nodo->hijos[0] = nuevoNodo(dato);
      }else{
        insertar(nodo->hijos[0], dato);
      }
    }else{
      if(nodo->hijos[1] == NULL){
        nodo->hijos[1] = nuevoNodo(dato);
      }else{
        insertar(nodo->hijos[1], dato);
      }
    }
  }
  void preOrder(Nodo *nodo){
    if(nodo != NULL){
      printf("[%d] ", nodo->dato);
      preOrder(nodo->hijos[0]);
      preOrder(nodo->hijos[1]);
    }
  }
  void inOrder(Nodo *nodo){
    if(nodo != NULL){
      inOrder(nodo->hijos[0]);
      printf("[%d] ", nodo->dato);
      inOrder(nodo->hijos[1]);
    }
  }
  void postOrder(Nodo *nodo){
    if(nodo != NULL){
      postOrder(nodo->hijos[0]);
      postOrder(nodo->hijos[1]);
      printf("[%d] ", nodo->dato);
    }
  }
  Nodo *busqValNodo(Nodo *nodo, int dato){
    Nodo *nodoM = NULL, *nodoAct = nodo;
    do{
      if(nodoAct->dato == dato)
        return nodoAct;
      else{
        if(nodoAct->dato < dato){
          if(nodoAct->hijos[0] != NULL)
            nodoAct = nodoAct->hijos[0];
          else
            break;
        }else if(nodoAct->dato > dato){
          if(nodoAct->hijos[1] != NULL)
            nodoAct = nodoAct->hijos[1];
          else
            break;
        }
      }
    }while(nodoM == NULL);
    return nodoAct;
  }
  
  //Funciones del Nodo
  char intToChar(int dato){
    switch(dato){
      case 0: return '0'; break;
      case 1: return '1'; break;
      case 2: return '2'; break;
      case 3: return '3'; break;
      case 4: return '4'; break;
      case 5: return '5'; break;
      case 6: return '6'; break;
      case 7: return '7'; break;
      case 8: return '8'; break;
      case 9: return '9'; break;
      default: return 'X'; break;
    }
  }
  Nodo *nuevoNodo(int dato){
    Nodo *nodo = (Nodo *) calloc(1, sizeof(Nodo));
    nodo->dato = dato;
    int decim = 1;
    for(int i = 0; i < tamFolio - 1; i++)
      decim = decim * 10;
    for(int i=0; i < tamFolio; i++){
      nodo->datoChar[i] = intToChar(dato / decim);
      dato = dato % decim;
      decim = decim / 10;
    }
    for(int i = 0; i < gradoArbol; i++)
      nodo->hijos[i] = NULL;
    return nodo;
  }
  
  //Funciones de la opcion 1
  void insertarNuevoNodo(Nodo *arbol){
    int dato;
    do{
      dato = solicDatoInt();
      if(busqValNodo(arbol, dato) != NULL)
        printf("\nEl Folio ya se encuentra registrado");
      if(dato < (pow(10, tamFolio) - 1) && dato >= 0)
        printf("\nEl folio no es valido");
    }while( verifDatoOpcUno(arbol, dato) );
    insertar(arbol, dato);
  }
  int verifDatoOpcUno(Nodo *arbol, int dato){
    return (dato < (pow(10, tamFolio) - 1) && dato >= 0 && busqValNodo(arbol, dato) != NULL);
  }
  void insertMultNodos(Nodo *arbol){
    int numFolios = solicDatoInt();
    for(int i = 0; i < numFolios; i++){
      limpiarPantalla();
      printf("========== Ingresar elementos ==========");
      printf("\nElemento #%d", i + 1);
      insertarNuevoNodo(arbol);
    }
  }
  
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
  
  