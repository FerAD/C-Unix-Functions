/*
  Este archivo contiene las declaraciones necesarias para el uso de funciones y
  tipos correspondientes a una biblioteca de funciones de entrada/salida con
  archivos en el Lenguaje de Programación C.

  El archivo es parte de la tarea 2 de la materia Programación Avanzada del
  semestre 201511 del Campus Puebla del ITESM.
*/

typedef struct archivo ARCHIVO;
struct archivo {
  // Aquí debe ir la lista de atributos del tipo ARCHIVO. Sólo se incluye al
  // búfer del archivo.

  char *strA;
  char *permisos;
  char *nombre;
  int descriptor;
  int contadorBufer;
  char bufer[2048];  // El búfer. El tamaño puede ser cualquier otro
};

/* 
   La función abreArch crea una nueva instancia del tipo ARCHIVO, abriendo el
   archivo nombrado en el primer parámetro de la función en el modo indicado
   por el segundo, que puede ser para lectura, escritura o para ambas, aunque
   puede haber más opciones. Esta función debe devolver NULL si hubo algún
   error al abrir el archivo.
*/

ARCHIVO* abreArch(char *, char *);

/*
  La función cierraArch cierra un archivo abierto usando abreArch. El único
  parámetro de esta función es el archivo a cerrar.
*/

void cierraArch(ARCHIVO *);

/*
  La función AleeChar lee un caracter del archivo que se le pasa
  como parámetro y lo devuelve a la función que genera la llamada. Esta función
  debe devolver el siguiente caracter sin leer del archivo, sin importar qué
  caracter sea. Si se llegó al fin de archivo, debe devolver el caracter nulo.
*/

char AleeChar(ARCHIVO *);

/*
  La función AleeInt lee un número entero del archivo que se le pasa como
  argumento. La función debe leer tantos caracteres representando dígitos
  decimales como le sea posible (hasta encontrar el primer caracter que no es
  un dígito decimal) y devuelve el valor del número leído. El caracter que
  detiene la lectura de dígitos debe quedar en el búfer como no leído.
*/

int AleeInt(ARCHIVO *);

/*
  La función AleeFloat lee un número de punto flotante. Debe comportarse de
  manera similar a AleeInt.
*/

float AleeFloat(ARCHIVO *);

/*
  La función AleeString lee una cadena de caracteres del archivo que se le pasa
  como parámetro. Debe leer caracteres hasta encontrar un "retorno de carro"
  (\n) o hasta el número indicado por el tercer parámetro. Los caracteres deben
  ponerse en el segundo parámetro, que debe ser un arreglo de caracteres. Debe
  siempre terminarse con un caracter nulo (\0). Debe devolver 0 en caso de
  errores y 1 en caso contrario.
*/

int AleeString(ARCHIVO *, char *, int);

/*
  La función AescribeChar escribe el caracter que se le pasa como segundo
  argumento en el archivo que se le pasa como primer argumento. Debe devolver
  un 0 si hubo algún error y 1 en caso contrario.
*/


int AescribeChar(ARCHIVO *, char);

/*
  La función AescribeInt debe escribir el entero que se le pasa como segundo
  parámetro en el archivo que se le pasa como primer parámetro. Debe devolver
  un 0 si hubo algún error y 1 en caso contrario.
*/

int AescribeInt(ARCHIVO *, int);

/*
  La función AescribeFloat debe escribir el número que se le pasa como segundo
  parámetro en el archivo que se le pasa como primer argumento. Debe devolver
  un 0 si hubo algún error y 1 en caso contrario.
*/

int AescribeFloat(ARCHIVO *, float);

/*
  La función AescribeString debe escribir la cadena que se le pasa como segundo
  argumento en el archivo que se le pasa como primer argumento. La función debe
  asumir que la cadena está terminada con el caracter nulo. Debe devolver
  un 0 si hubo algún error y 1 en caso contrario.
*/

int AescribeString(ARCHIVO *, char *);
