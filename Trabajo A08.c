#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>   
//Tiempo de programacion por colaborador
//Richie 2 horas
//Daniel 3 horas 
//Cesar 6 horas

//Definicion de Constantes
#define tamFolio 3
#define gradoArbol 2
#define folioMax 999   
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
  int leerEntero(const char *mensaje, int *valor);
  
  //Funciones del Arbol
  void *insertar(Nodo *nodo, int dato);
  void preOrder(Nodo *nodo, int *primero);   
  void inOrder(Nodo *nodo, int *primero);   
  void postOrder(Nodo *nodo, int *primero);   
  void *busqValNodo(Nodo *nodo, int dato);
  int arbolVacio(Nodo *arbol);
  void imprimirFolio(Nodo *nodo, int *primero);   
  void liberarArbol(Nodo *nodo);
  int pesoArbol(Nodo *nodo);
  
  //Funciones del Nodo
  char intToChar(int dato);
  Nodo *nuevoNodo(int dato);
  
  //Funciones de la opcion 1
  void *insertarNuevoNodo(Nodo *arbol);
  int verifDatoOpcUno(Nodo *arbol, int dato);
  void *insertMultNodos(Nodo *arbol);
  
  //Funciones de la opcion 2
  
  
  //Funciones de la opcion 3 #Trabajando Nano
  
  
  //Funciones de la opcion 4
  
  
  //Funciones de la opcion 5
  
  
  //Funciones de la opcion 6
  
  
  //Funciones de la opcion 7
  
  
  //Funciones de la opcion 8
  
  
  //Funciones de la opcion 9 #Trabajando Richie
  void mostrarPeso(Nodo *arbol);
  
  //Funciones de la opcion 10
  
  
  //Funciones de la opcion 11
  
  
  //Funciones de la opcion 12 #Trabajando Dani
  void recorridos(Nodo *arbol);   
  
  //Funciones de la opcion 13
  
  

int main(){
  int opcMenuPrincSel = 0;
  Nodo *arbol = NULL;
  do{
    limpiarPantalla();  
    opcMenuPrincSel = menuPrinc();
    switch (opcMenuPrincSel){
      case 1:
        arbol = insertMultNodos(arbol);
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
        mostrarPeso(arbol);
        break;
      case 10:
      
        break;
      case 11:
      
        break;
      case 12:
        recorridos(arbol);  
        break;
      case 13:
        printf("Va a salir del programa \n Que tenga un buen dia :D");
        break;
      default:
        printf("Opcion no valida");
        break;
    }
    if(opcMenuPrincSel != 13)   
      pausarPantalla();
  }while(opcMenuPrincSel != 13);
  liberarArbol(arbol);   
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
    if(!leerEntero("\n\nIngrese la opcion que va a seleccionar: ", &opcSel))
      opcSel = 0;
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
    while(!leerEntero("Ingresa el dato: ", &n))
      printf("Debes ingresar un numero entero.\n");
    return n;
  }
  //Lee una linea completa y la convierte a entero. Regresa 1 si fue valido, 0 si no
  int leerEntero(const char *mensaje, int *valor){
    char buf[64], *fin;
    printf("%s", mensaje);
    if(fgets(buf, sizeof(buf), stdin) == NULL)
      return 0;
    long n = strtol(buf, &fin, 10);
    if(fin == buf)
      return 0;
    while(*fin == ' ' || *fin == '\t')
      fin++;
    if(*fin != '\n' && *fin != '\0')
      return 0;
    *valor = (int) n;
    return 1;
  }
  
  //Funciones del Arbol
  Nodo *insertar(Nodo *nodo, int dato){
    if(nodo == NULL)
      return nuevoNodo(dato);
    if(dato < nodo->dato)
      nodo->hijos[0] = insertar(nodo->hijos[0], dato);
    else
      nodo->hijos[1] = insertar(nodo->hijos[1], dato);
    return nodo;
  }
  void preOrder(Nodo *nodo, int *primero){
    if(nodo != NULL){
      imprimirFolio(nodo, primero);
      preOrder(nodo->hijos[0], primero);
      preOrder(nodo->hijos[1], primero);
    }
  }
  void inOrder(Nodo *nodo, int *primero){
    if(nodo != NULL){
      inOrder(nodo->hijos[0], primero);
      imprimirFolio(nodo, primero);
      inOrder(nodo->hijos[1], primero);
    }
  }
  void postOrder(Nodo *nodo, int *primero){
    if(nodo != NULL){
      postOrder(nodo->hijos[0], primero);
      postOrder(nodo->hijos[1], primero);
      imprimirFolio(nodo, primero);
    }
  }
  Nodo *busqValNodo(Nodo *nodo, int dato){
    Nodo *nodoAct = nodo;
    while(nodoAct != NULL && nodoAct->dato != dato){
      if(dato < nodoAct->dato)
        nodoAct = nodoAct->hijos[0];
      else
        nodoAct = nodoAct->hijos[1];
    }
    return nodoAct;
  }
  int arbolVacio(Nodo *arbol){
    return (arbol == NULL);
  }
  //Imprime el folio separado por " - " (el primero va sin separador)
  void imprimirFolio(Nodo *nodo, int *primero){
    if(!*primero)
      printf(" - ");
    printf("%s", nodo->datoChar);
    *primero = 0;
  }
  void liberarArbol(Nodo *nodo){
    if(nodo != NULL){
      liberarArbol(nodo->hijos[0]);
      liberarArbol(nodo->hijos[1]);
      free(nodo);
    }
  }
  //Regresa la cantidad de nodos del arbol
  int pesoArbol(Nodo *nodo){
    if(nodo == NULL)
      return 0;
    return 1 + pesoArbol(nodo->hijos[0]) + pesoArbol(nodo->hijos[1]);
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
  Nodo *insertarNuevoNodo(Nodo *arbol){
    int dato;
    do{
      dato = solicDatoInt();
      if(dato < 0 || dato > folioMax)
        printf("\nEl folio no es valido (debe estar entre 000 y 999)\n");
      else if(busqValNodo(arbol, dato) != NULL)
        printf("\nEl folio de la cita ya existe, ingrese un folio diferente\n");
    }while( verifDatoOpcUno(arbol, dato) );
    return insertar(arbol, dato);
  }
  //regresa 1 si el dato NO es valido (fuera de rango o repetido) para repetir 
  int verifDatoOpcUno(Nodo *arbol, int dato){
    return (dato < 0 || dato > folioMax || busqValNodo(arbol, dato) != NULL);
  }
  Nodo *insertMultNodos(Nodo *arbol){
    limpiarPantalla();
    printf(" ========== Ingreso de Multiples Datos ==========\n\n");
    int numFolios;
    do{
      numFolios = solicDatoInt();
    }while(numFolios < 1);
    for(int i = 0; i < numFolios; i++){
      limpiarPantalla();
      printf("========== Ingresar elementos ==========");
      printf("\nElemento #%d\n", i + 1);
      arbol = insertarNuevoNodo(arbol);
    }
    printf("\nEl árbol fue creado");
    return arbol;
  }
  
  //Funciones de la opcion 2
  
  //Funciones de la opcion 3
  
  //Funciones de la opcion 4
  
  //Funciones de la opcion 5
  
  //Funciones de la opcion 6
  
  //Funciones de la opcion 7
  
  //Funciones de la opcion 8
  
  //Funciones de la opcion 9
  void mostrarPeso(Nodo *arbol){
    limpiarPantalla();
    printf(" ========== Peso del Arbol ========== \n\n");
    if(arbolVacio(arbol)){
      printf("El árbol está vacío");
      return;
    }
    printf("El peso del árbol es %d", pesoArbol(arbol));
  }
  //Funciones de la opcion 10
  
  //Funciones de la opcion 11
  
  //Funciones de la opcion 12
  void recorridos(Nodo *arbol){
    limpiarPantalla();
    printf(" ========== Recorridos ========== \n\n");
    if(arbolVacio(arbol)){
      printf("El árbol está vacío");
      return;
    }
    int primero;
    primero = 1; printf("PreOrder: ");  preOrder(arbol, &primero);  printf("\n");
    primero = 1; printf("InOrder: ");   inOrder(arbol, &primero);   printf("\n");
    primero = 1; printf("PostOrder: "); postOrder(arbol, &primero); printf("\n");
  }
  
  //Funciones de la opcion 13
