/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_va.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:27:04 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/29 19:02:34 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	my_function(int count, ...)
{
	int		first_argument;
	double	second_argument;

	va_list	args;
	va_start(args, count);
	first_argument = va_arg(args, int);
	second_argument = va_arg(args, double);
	va_end(args);
}

/*
 * Sintaxis C

type va_arg(
   va_list arg_ptr,
   type
);
void va_copy(
   va_list dest,
   va_list src
); // (ISO C99 and later)
void va_end(
   va_list arg_ptr
);
void va_start(
   va_list arg_ptr,
   prev_param
); // (ANSI C89 and later)
void va_start(
   arg_ptr
);  // (deprecated Pre-ANSI C89 standardization version)

Parámetros

type
Tipo de argumento que se va a recuperar.

arg_ptr
Puntero a la lista de argumentos.

dest
Puntero a la lista de argumentos que se van a inicializar desde src

src
Puntero a la lista de argumentos inicializada que se va a copiar en dest.

prev_param
Parámetro que precede al primer argumento opcional.
Valor devuelto

va_arg devuelve el argumento actual. va_copyy va_start va_end no devuelven valores.

Comentarios

Las macros va_arg, va_copy, va_end y va_start proporcionan una manera portable de obtener acceso
a los argumentos de una función cuando la función toma un número variable de argumentos. Hay dos
versiones de las macros. las macros definidas en STDARG.H cumplen el estándar ISO C99. Las definidas
en VARARGS.H están en desuso, pero se conservan por razones de compatibilidad con el código escrito
antes del estándar ANSI C89.

Estas macros suponen que la función toma un número fijo de argumentos necesarios, seguido por un
número variable de argumentos opcionales. Los argumentos necesarios se declaran como parámetros
ordinarios de la función; se puede obtener acceso a ellos con los nombres de parámetro. El acceso a
los argumentos opcionales se realiza mediante las macros de STDARG.H (o VARARGS.H para el código
escrito antes del estándar ANSI C89), que establece un puntero al primer argumento opcional de la
lista de argumentos, recupera argumentos de la lista y restablece el puntero cuando finaliza el
procesamiento de argumentos.

Las macros estándar de C, definidas en STDARG.H, se usan de la manera siguiente:

va_start establece arg_ptr en el primer argumento opcional de la lista de argumentos que se pasa a
la función. El argumento arg_ptr debe tener el tipo va_list. El argumento prev_param es el nombre del
parámetro necesario inmediatamente anterior al primer argumento opcional de la lista de argumentos. Si
prev_param se declara con la clase de almacenamiento de registro, el comportamiento de la macro es
indefinido. Es necesario usar va_start antes de usar va_arg por primera vez.

va_arg recupera un valor de type de la ubicación determinada por arg_ptr, y aumenta arg_ptr para señalar
al argumento siguiente de la lista usando el tamaño de type para determinar donde empieza el argumento
siguiente. va_arg se puede usar un número ilimitado de veces en la función para recuperar argumentos de
la lista.

va_copy realiza una copia de una lista de argumentos en su estado actual. El parámetro de src debe estar
ya inicializado con va_start; puede haberse actualizado con llamadas de va_arg, pero no puede haberse
restablecido con va_end. El siguiente argumento recuperado por va_arg de dest es el mismo que el siguiente
argumento se recupera de src.

Después de que todos los argumentos se hayan recuperado, va_end restablece el puntero a NULL. Es necesario
llamar a va_end en cada lista de argumentos que se inicialice con va_start o va_copy antes de que la función
devuelva su resultado.

Nota:

Las macros de VARARGS.H han dejado de usarse y se conservan solo por compatibilidad con el código escrito
antes de la existencia del estándar ANSI C89. En todos los demás casos, se deben usar las macros de STDARGS.H.

Cuando se compilan mediante /clr (Compilación de Common Language Runtime), los programas que usan estas macros
pueden generar resultados inesperados debido a las diferencias entre los sistemas de tipos nativos y de Common
Language Runtime (CLR). Observe este programa: C

#include <stdio.h>
#include <stdarg.h>

void testit (int i, ...)
{
    va_list argptr;
    va_start(argptr, i);

    if (i == 0)
    {
        int n = va_arg(argptr, int);
        printf("%d\n", n);
    }
    else
    {
        char *s = va_arg(argptr, char*);
        printf("%s\n", s);
    }

    va_end(argptr);
}

int main()
{
    testit(0, 0xFFFFFFFF); // 1st problem: 0xffffffff is not an int
    testit(1, NULL);       // 2nd problem: NULL is not a char*
}

testit espera que su segundo parámetro sea un valor int o char*. Los argumentos que se pasan son 0xffffffff
(un valor unsigned int, no un valor int) y NULL (en realidad, un valor int, no un valor char*). Cuando el
programa se compila para código nativo, genera este resultado:

Output

-1

(null)

Requisitos

Encabezado: <stdio.h> y <stdarg.h>

Encabezado en desuso: <varargs.h>
Bibliotecas

Todas las versiones de las bibliotecas en tiempo de ejecución de C.
Ejemplo
C

// crt_va.c
// Compile with: cl /W3 /Tc crt_va.c
// The program below illustrates passing a variable
// number of arguments using the following macros:
//      va_start            va_arg              va_copy
//      va_end              va_list

#include <stdio.h>
#include <stdarg.h>
#include <math.h>

double deviation(int first, ...);

int main( void )
{
    Call with 3 integers (-1 is used as terminator).
    printf("Deviation is: %f\n", deviation(2, 3, 4, -1 ));

    Call with 4 integers.
    printf("Deviation is: %f\n", deviation(5, 7, 9, 11, -1));

    Call with just -1 terminator.
    printf("Deviation is: %f\n", deviation(-1));
}

Returns the standard deviation of a variable list of integers.

double deviation(int first, ...)
{
    int count = 0, i = first;
    double mean = 0.0, sum = 0.0;
    va_list marker;
    va_list copy;

    va_start(marker, first);     Initialize variable arguments.
    va_copy(copy, marker);       Copy list for the second pass
    while (i != -1)
    {
        sum += i;
        count++;
        i = va_arg(marker, int);
    }
    va_end(marker);              Reset variable argument list.
    mean = sum ? (sum / count) : 0.0;

    i = first;                  reset to calculate deviation
    sum = 0.0;
    while (i != -1)
    {
        sum += (i - mean)*(i - mean);
        i = va_arg(copy, int);
    }
    va_end(copy);               Reset copy of argument list.
    return count ? sqrt(sum / count) : 0.0;
}

Output

Deviation is: 0.816497
Deviation is: 2.236068
Deviation is: 0.000000
*/
