# 📘 RESUMEN TEÓRICO COMPLETO – FT_PRINTF (42)
## 1️⃣ ¿QUÉ ES printf Y QUÉ ESTOY REIMPLEMENTANDO?

printf es una función de la libc que:

Recibe un string de formato

Recibe un número variable de argumentos

Interpreta el string y sustituye los especificadores

Escribe el resultado en la salida estándar

Devuelve el número de bytes escritos

👉 En ft_printf:

No uso la implementación original

Uso write

Gestiono manualmente los argumentos variádicos

Soporto solo un subconjunto de conversiones

## 2️⃣ FUNCIONES VARIÁDICAS (PILAR DEL PROYECTO)
Concepto clave

Las funciones variádicas permiten recibir un número indefinido de argumentos, pero sin información de tipo en tiempo de ejecución.

Herramientas:

va_list → estructura interna que apunta a los argumentos

va_start(list, last_named_param) → inicializa la lectura

va_arg(list, type) → lee el siguiente argumento como type

va_end(list) → limpia el estado

Regla de oro

👉 El tipo pasado a va_arg debe coincidir EXACTAMENTE con el tipo real.

Si no:

Comportamiento indefinido

Lecturas corruptas

Segfaults silenciosos

## 3️⃣ PROMOCIÓN DE TIPOS EN VARIÁDICAS

En funciones variádicas:

char → se promueve a int

short → int

float → double

Por eso:

%c → va_arg(args, int)

%s → va_arg(args, char *)

## 4️⃣ PARSEO DEL STRING DE FORMATO
Lógica general:

Recorrer el string carácter a carácter

Si el carácter no es % → imprimirlo directamente

Si es %:

Avanzar

Leer el selector

Ejecutar la función correspondiente

Acumular los bytes escritos

Caso especial:

%% → imprime %, no consume argumentos

## 5️⃣ SELECTOR DE CONVERSIÓN

El selector determina:

Qué tipo leer con va_arg

Qué función de impresión usar

Cómo contar los bytes

Ejemplo:

'd' → int → decimal

'x' → unsigned int → base 16

'p' → void * → dirección en hexadecimal

## 6️⃣ CONVERSIÓN DE NÚMEROS (BASE 10 Y BASE N)
Idea fundamental:

Un número se convierte a string usando:

Divisiones sucesivas por la base

Módulo para obtener cada dígito

Construcción del string desde el final

Pasos mentales:

Calcular cuántos dígitos tendrá

Reservar memoria

Rellenar desde atrás hacia delante

Añadir \0

## 7️⃣ SIGNADOS VS NO SIGNADOS
int (signed):

Puede ser negativo

Requiere manejar el signo

Se usa long internamente para evitar overflow (INT_MIN)

unsigned int:

Nunca negativo

No hay signo

Base 10 o base 16

## 8️⃣ BASE HEXADECIMAL

Base 16 utiliza:

0123456789abcdef
0123456789ABCDEF


Conversión:

Módulo 16 → índice de la tabla

División por 16

Resultado en string

## 9️⃣ IMPRESIÓN DE PUNTEROS %p
Conceptos clave:

Un puntero es una dirección de memoria

Se imprime en hexadecimal

Siempre con prefijo 0x

Pasos:

Leer como void *

Cast a unsigned long

Convertir a base 16

Imprimir "0x" + número

## 🔟 GESTIÓN DE MEMORIA
Regla sagrada:

👉 Quien hace malloc, hace free.

En ft_printf:

Las funciones de conversión reservan memoria

El selector imprime y libera

No quedan fugas

Caso especial:

%s con NULL → no se reserva memoria → se imprime (null)

## 1️⃣1️⃣ CONTADOR DE BYTES

ft_printf debe devolver:
👉 el número exacto de caracteres impresos

Por eso:

Cada función devuelve cuántos bytes imprime

El total se acumula en el bucle principal

## 1️⃣2️⃣ WRITE VS PRINTF

No uso printf porque:

Está prohibido

Oculta la lógica real

write obliga a pensar en bytes reales

## 1️⃣3️⃣ COMPORTAMIENTO INDEFINIDO

Ejemplos:

Formato incorrecto

Tipo incorrecto en va_arg

Acceso a memoria inválida

👉 En C, el compilador no te protege.

## 1️⃣4️⃣ SEGFAULT (SEGMENTATION FAULT)

Ocurre cuando:

Accedes a memoria que no te pertenece

Dereferencias NULL

Lees fuera de un bloque reservado

Muy común en:

Strings

Punteros

Variádicas mal usadas

## 1️⃣5️⃣ NORMINETTE Y DISEÑO

Restricciones:

Máx 25 líneas por función

Máx 5 funciones por archivo

Solución:

Separación por responsabilidad

Funciones pequeñas

Selector central

## 1️⃣6️⃣ MAKEFILE Y LIBRERÍAS
Librería estática:

Conjunto de .o empaquetados en .a

Se enlaza en tiempo de compilación

Comandos clave:

ar rcs libftprintf.a

-L → ruta de librerías

-lftprintf → busca libftprintf.a

## 1️⃣7️⃣ DEFENSA ORAL (MENTALIDAD)

No buscan perfección.
Buscan:

Comprensión

Coherencia

Decisiones justificadas

Frase clave:

“No implementé X porque no era obligatorio, pero la estructura lo permite.”