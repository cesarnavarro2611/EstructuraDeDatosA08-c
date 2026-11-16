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
    char datoChar[tamFolio + 1];
    struct Nodo *hijos[gradoArbol];
  } Nodo;

//Declaracion de las funciones
  //Funciones principales del programa #Terminado
  int menuPrinc();
  void limpiarPantalla();
  void pausarPantalla();
  int solicDatoInt();
  
  //Funciones del Arbol
  void insertar(Nodo **nodo, int dato);
  void preOrder(Nodo *nodo);
  void inOrder(Nodo *nodo);
  void postOrder(Nodo *nodo);
  Nodo *busqValNodo(Nodo *nodo, int dato);
  int arbolVacio(Nodo *arbol);
  
  //Funciones del Nodo
  char intToChar(int dato);
  Nodo *nuevoNodo(int dato);
  
  //Funciones de la opcion 1
  void insertarNuevoNodo(Nodo **arbol);
  int verifDatoOpcUno(Nodo *arbol, int dato);
  void insertMultNodos(Nodo **arbol);
  
  //Funciones de la opcion 2
  void busqNodo(Nodo *arbol);
  
  //Funciones de la opcion 3 #Trabajando Nano
  void elimHoja(Nodo *nodoP, int dato);
  void elimSimple(Nodo *nodoP, int dato);
  void elimDoble(Nodo *nodoP, int dato);
  void supresion(Nodo **arbol, int dato);
  
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
        printf("Va a salir del programa \n Que tenga un buen dia :D\n");
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
    getchar();
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
    getchar();
    return n;
  }
  //Funciones del Arbol
  void insertar(Nodo **nodo, int dato){
    if(*nodo == NULL){
      *nodo = nuevoNodo(dato);
      return;
    }
    if(dato < (*nodo)->dato){
      insertar(&((*nodo)->hijos[0]), dato);
    }else{
      insertar(&((*nodo)->hijos[1]), dato);
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
    if(nodo == NULL) return NULL;
    Nodo *nodoAct = nodo;
    while(nodoAct != NULL){
      if(nodoAct->dato == dato)
        return nodoAct;
      else if(nodoAct->dato > dato){
        nodoAct = nodoAct->hijos[0];
      }else{
        nodoAct = nodoAct->hijos[1];
      }
    }
    return NULL;
  }
  int arbolVacio(Nodo *arbol){
    return (arbol == NULL);
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
  void insertarNuevoNodo(Nodo **arbol){
    int dato;
    do{
      dato = solicDatoInt();
      if(busqValNodo(*arbol, dato) != NULL)
        printf("\nEl Folio ya se encuentra registrado");
      if(dato > (pow(10, tamFolio) - 1) || dato < 0)
        printf("\nEl folio no es valido");
    }while( verifDatoOpcUno(*arbol, dato) );
    insertar(arbol, dato);
  }
  int verifDatoOpcUno(Nodo *arbol, int dato){
    return (dato > (pow(10, tamFolio) - 1) || dato < 0 || busqValNodo(arbol, dato) != NULL);
  }
  void insertMultNodos(Nodo **arbol){
    limpiarPantalla();
    printf(" ========== Ingreso de Multiples Datos ==========\n\n");
    int numFolios = solicDatoInt();
    for(int i = 0; i < numFolios; i++){
      limpiarPantalla();
      printf("========== Ingresar elementos ==========");
      printf("\nElemento #%d", i + 1);
      if(*arbol == NULL){
        printf("\n\nEl arbol ha sido creado!");
      }
      insertarNuevoNodo(arbol);
      pausarPantalla();
    }
  }
  
  //Funciones de la opcion 2
  void busqNodo(Nodo *arbol){
    limpiarPantalla();
    printf(" ========== Buscar un Folio ========== \n\n");
    printf("1. Ingrese el Folio que desea buscar \n");
    int numFolio = solicDatoInt();
    printf("\n2. Resultado \n");
    if(arbol == NULL)
      printf("El arbol está vacío");
    else{
      if(busqValNodo(arbol, numFolio) == NULL)
        printf("Folio No Encontrado");
      else
        printf("Folio Encontrado");
    }
  }
  
  //Funciones de la opcion 3
  void elimHoja(Nodo *nodoP, int dato){
    Nodo *nodoTmp;
    for(int i = 0; i < gradoArbol; i++){
      nodoTmp = nodoP->hijos[i];
      if(nodoTmp != NULL){
        if(nodoTmp->dato == dato){
          nodoP->hijos[i] = NULL;
          free(nodoTmp);
          break;
        }
      }
    }
  }
  void elimSimple(Nodo *nodoP, int dato){
    Nodo *nodoAct = NULL, *nodoHijo = NULL;
    for(int i = 0; i < gradoArbol; i++){
      nodoAct = nodoP->hijos[i];
      nodoHijo = NULL;
      if(nodoAct != NULL){
        if(nodoAct->dato == dato){
          for(int j = 0; j < gradoArbol; j++){
            nodoHijo = nodoAct->hijos[j];
            if(nodoHijo != NULL)
              break;
          }
          nodoP->hijos[i] = nodoHijo;
          free(nodoAct);
          break;
        }
      }
    }
  }
  void elimDoble(Nodo *nodoP, int dato){
    for(int i = 0; i < gradoArbol; i++){
      Nodo *nodoAct = nodoP->hijos[i];
      if(nodoAct != NULL && nodoAct->dato == dato){
        Nodo *suc = nodoAct->hijos[1];
        Nodo *sucP = nodoAct;
        while(suc->hijos[0] != NULL){
          sucP = suc;
          suc = suc->hijos[0];
        }
        if(sucP != nodoAct){
          sucP->hijos[0] = suc->hijos[1];
          suc->hijos[1] = nodoAct->hijos[1];
        }
        suc->hijos[0] = nodoAct->hijos[0];
        nodoP->hijos[i] = suc;
        free(nodoAct);
        break;
      }
    }
  }
  void supresion(Nodo **arbol, int dato){
    if(*arbol == NULL){
      printf("El arbol esta vacio\n");
      return;
    }
    if(busqValNodo(*arbol, dato) == NULL){
      printf("Folio no encontrado\n");
      return;
    }
    Nodo ficticio;
    ficticio.hijos[0] = *arbol;
    ficticio.hijos[1] = NULL;
    Nodo *padre = &ficticio;
    Nodo *act = *arbol;
    while(act->dato != dato){
      padre = act;
      act = (dato < act->dato) ? act->hijos[0] : act->hijos[1];
    }
    int numHijos = (act->hijos[0] != NULL) + (act->hijos[1] != NULL);
    if(numHijos == 0)      elimHoja(padre, dato);
    else if(numHijos == 1) elimSimple(padre, dato);
    else                   elimDoble(padre, dato);
    
    *arbol = ficticio.hijos[0];
    
    printf("Folio eliminado\n");
  }
  
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
  
  