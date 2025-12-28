# rpc

Ejemplo sencillo de programa RPC para Linux, donde el cliente pide al servidor que ejecute operaciones aritméticas de suma, resta, multiplicación y división.

Para poder crear programas que hagan uso de RPC es necesario contar con software que cree el archivo IDL.

Instalación de software:
+ sudo apt-get install rpcbind

Verificación de instalación:
+ rpcinfo

Archivo IDL 

```javascript

struct valores{
  float num1;
  float num2;
  char operation;
};

/*Programa, versión y definición de procedimiento*/

program CALCULADORA{
  version CALCULADORA_VERS{
  float ADD(valores)=1;
  float SUB(valores)=2;
  float MUL(valores)=3;
  float DIV(valores)=4;
  } = 6; 
} = 456123789;
```


  valores -> Este es el nombre de la estructura de datos que envía los parámetros del cálculo al servidor.
  CALCULADORA -> Este es el nombre del programa.
  CALCULADORA_VERS -> Este es el nombre de la versión del programa.
  ADD(valores) -> Este es uno de los métodos que vamos a llamar remotamente. La estructura de datos que contiene los dos operandos y la operación a realizar se proporciona como parámetro del método remoto. Esto es similar para los demás métodos.
		
		Se puede ver que al final de cada método, programa y versión, se asignan números. Estos números se utilizan para identificar de forma única cada entidad. Se puede asignar el número que se desee.
