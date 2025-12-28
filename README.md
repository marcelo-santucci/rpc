# rpc

Ejemplo sencillo de programa RPC para Linux, donde el cliente pide al servidor que ejecute operaciones aritméticas de suma, resta, multiplicación y división.

*Cuando clone el repositorio renombre los archivos IDL_client.c e IDL_server.c agregandoles "bk".

## Instalación de software:
+ sudo apt-get install rpcbind

Verificación de instalación:
+ rpcinfo

## Archivo IDL 

Para poder crear programas que hagan uso de RPC es necesario contar con software que cree elementos a partir del archivo IDL.

```c

struct values{
  float num1;
  float num2;
  char operation;
};

/*Programa, versión y definición de procedimiento*/

program CALCULADORA{
  version CALCULADORA_VERS{
  float ADD(values)=1;
  float SUB(values)=2;
  float MUL(values)=3;
  float DIV(values)=4;
  } = 6; 
} = 456123789;
```


  + values -> Este es el nombre de la estructura de datos que envía los parámetros del cálculo al servidor.
  + CALCULADORA -> Este es el nombre del programa.
  + CALCULADORA_VERS -> Este es el nombre de la versión del programa.
  + ADD(valores) -> Este es uno de los métodos que vamos a llamar remotamente. La estructura de datos que contiene los dos operandos y la operación a realizar se proporciona como parámetro del método remoto. Similar para el resto de los métodos.
  + Se puede ver que al final de cada método, programa y versión, se asignan números. Estos números se utilizan para identificar de forma única cada entidad. Se puede asignar el número que se desee.

Al compilarse con rpcgen se crean varios archivos a partir del archivo IDL:

1. Stub del cliente
2. Skeleton del servidor
3. Programa cliente de ejemplo
4. Programa servidor de ejemplo
5. Archivo de encabezado
6. Rutinas XDR utilizadas tanto por el cliente como por el servidor
7. Archivo Makefile

## Comando de compilación:
```
	rpcgen -a -C IDL.x
```

### Compilar todos los archivos

Ahora compilar todos los archivos generados, incluyendo los programas cliente y servidor que fueron editados previamente.  
No editar ningún otro archivo generado por el compilador rpcgen.

Comando para compilar:
```
	make -f Makefile.IDL
```

## Ejecutar el servidor y el cliente

Ahora se puede ejecutar el servidor en una ventana de terminal usando el comando.
```	
	sudo ./IDL_server
```	
Ahora se puede ejecutar el cliente en otra ventana de terminal usando el comando.
```	
	sudo ./IDL_client localhost
```
