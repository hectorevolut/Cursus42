*Este proyecto ha sido creado como
parte del currículo de 42 por <hecalder@student.42madrid.com>*
# get_next_line
## Descripción
El proyecto `get_next_line` consiste en implementar una función en `C` capaz de leer un archivo línea por línea a partir de un file descriptor. Cada llamada a la función devuelve la siguiente línea disponible, gestionando internamente la memoria y el estado de lectura entre llamadas sucesivas.

Este proyecto introduce conceptos fundamentales de gestión de memoria dinámica, lectura con read, buffers, y persistencia de datos entre llamadas, siendo una pieza clave para comprender cómo funcionan las funciones de entrada/salida a bajo nivel en `C`.

## Instrucciones

### Compilación
Para compilar tu programa con `get_next_line`, puedes usar `cc` de la siguiente manera:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -o nombre_programa archivo_principal.c get_next_line.c get_next_line_utils.c
```

## Objetivo
Implementar la función:
```C
char *get_next_line(int fd);
```
que:

* Devuelve una línea leída desde el file descriptor `fd`

* Incluye el carácter `\n` si existe en la línea

* Devuelve `NULL` al alcanzar el `EOF` o en caso de error

* Funciona correctamente independientemente del valor de `BUFFER_SIZE`


## Funcionamiento
* La lectura se realiza mediante la función `read`, utilizando un buffer de tamaño `BUFFER_SIZE`.

* La función conserva el contenido sobrante entre llamadas para asegurar que ninguna parte del archivo se pierde.

* Se gestionan correctamente casos como:

	* Líneas más largas que `BUFFER_SIZE`

	* Líneas vacías

	* Archivos sin salto de línea final

	* Lectura hasta `EOF`

* Toda la memoria asignada dinámicamente es liberada correctamente para evitar memory leaks.


## Estructura del proyecto
El proyecto se organiza en los siguientes archivos:

* **get_next_line.c**
Contiene la implementación principal de la función `get_next_line`.

* **get_next_line_utils.c**
Incluye funciones auxiliares para manipulación de strings y gestión de memoria.

* **get_next_line.h**
Archivo de cabecera con prototipos, includes necesarios y la definición de `BUFFER_SIZE`.

## Conceptos clave aprendidos

Uso de read y file descriptors

Manejo de buffers y lectura incremental

Gestión precisa de memoria dinámica (malloc / free)

Persistencia de estado entre llamadas - variables `static`

Prevención de segmentation faults y memory leaks

## Pruebas

El proyecto puede ser probado utilizando distintos archivos de texto con:

Líneas cortas y largas

Líneas vacías

Diferentes valores de `BUFFER_SIZE`

Última línea con y sin `\n`

El uso de herramientas como `valgrind` permite verificar una correcta gestión de memoria.

## Funciones
1. [**ft_strlen**](#ft_strlen)
2. [**ft_strdup**](#ft_strdup)
3. [**ft_strjoin**](#ft_strjoin)
4. [**ft_strchr**](#ft_strchr)
5. [**get_line**](#get_line)
6. [**read_to_stash**](#read_to_stash)
7. [**update_stash**](#update_stash)
8. [**get_next_line**](#get_next_line)
9. [**CABECERA**](#CABECERA)

### **ft_strlen**
***
La función `ft_strlen` calcula la longitud de una cadena de caracteres terminada en `'\0'`.

Devuelve el número de caracteres presentes en la cadena sin incluir el carácter nulo final.
Si el puntero recibido es `NULL`, la función devuelve `0`, evitando comportamientos indefinidos.
```C
size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}
```
#### Funcionamiento
* Recorre la cadena carácter por carácter hasta encontrar `'\0`'
* Incrementa un contador por cada carácter válido
* No modifica el contenido de la cadena original
#### Parámetros
* **s**: puntero a la cadena de caracteres a evaluar
#### Valor de retorno
* Número de caracteres de la cadena
* `0` si s es `NULL`

### **ft_strdup**
***
La función `ft_strdup` crea una copia dinámica de una cadena de caracteres terminada en `'\0'`.

Reserva memoria suficiente para duplicar la cadena recibida, copia su contenido carácter por carácter y devuelve un puntero a la nueva cadena. La cadena duplicada es independiente de la original y debe ser liberada posteriormente con free.
```C
char	*ft_strdup(const char *s)
{
	char	*temp;
	char	*dup;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	temp = malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	dup = temp;
	while (*s)
	{
		*temp = *s;
		temp++;
		s++;
	}
	*temp = '\0';
	return (dup);
}
```
#### Funcionamento
* Comprueba que el puntero de entrada no sea `NULL`
* Calcula la longitud de la cadena usando `ft_strlen`
* Reserva memoria para la copia `(len + 1)`
* Copia cada carácter hasta el terminador nulo
* Añade el carácter `'\0'` al final de la nueva cadena
#### Parámetros
* `s`: puntero a la cadena de caracteres a duplicar
#### Valor de retorno
* Puntero a la nueva cadena duplicada
* `NULL` si s es `NULL` o si la reserva de memoria falla

### **ft_strjoin**
***
La función `ft_strjoin` crea una nueva cadena resultante de la concatenación de `s1` y `s2`, reservando memoria dinámica para el resultado.

El contenido de `s1` se copia primero, seguido del contenido completo de `s2`. La cadena resultante termina correctamente en `'\0'`.
```C
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
```
#### Funcionamiento
* Comprueba si `s2` es `NULL` y, en ese caso, devuelve `NULL`
* Si `s1` es `NULL`, devuelve una copia dinámica de `s2` usando `ft_strdup`
* Reserva memoria suficiente para contener ambas cadenas y el terminador nulo
* Copia los caracteres de `s1`
* Añade a continuación los caracteres de `s2`
* Finaliza la cadena con `'\0'`
#### Parámetros
* `s1`: primera cadena (puede ser `NULL`)
* `s2`: segunda cadena a concatenar
#### Valor de retorno
* Puntero a la nueva cadena concatenada
* `NULL` si `s2` es `NULL` o si falla la reserva de memoria

### ft_strchr
La función `ft_strchr` localiza la primera aparición del carácter `c` en la cadena de caracteres `s`.

Devuelve un puntero a la posición donde se encuentra el carácter o `NULL` si no está presente en la cadena. El carácter nulo `'\0'` también puede ser buscado.
```C
char	*ft_strchr(const char *s, int c)
{
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}
```
#### Funcionamiento
* Comprueba que la cadena de entrada no sea `NULL`
* Convierte el carácter `c` a tipo char
* Recorre la cadena carácter por carácter
* Si encuentra una coincidencia, devuelve un puntero a esa posición
* Si c es `'\0'`, devuelve un puntero al final de la cadena
#### Parámetros
* `s`: puntero a la cadena de caracteres donde buscar
* `c`: carácter a localizar
#### Valor de retorno
* Puntero a la primera aparición de `c` en `s`
* Puntero al carácter `'\0'` si `c` es `'\0'`
`NULL` si `s` es `NULL` o si el carácter no se encuentra

### get_line
La función `get_line` extrae y devuelve la primera línea completa almacenada en `stash`.

La línea devuelta incluye el carácter separador (`SEPARATOR`, normalmente `'\n'`) si está presente. No modifica el contenido original de stash.
#### Funcionamiento
* Comprueba que `stash` exista y no esté vacío
* Recorre la cadena hasta encontrar el carácter separador o el final de la cadena
* Si el separador está presente, lo incluye en la longitud de la línea
* Reserva memoria dinámica para la nueva línea
* Copia los caracteres correspondientes desde `stash`
* Termina la cadena con `'\0'`
#### Parámetros
* `stash`: cadena que contiene el contenido acumulado leído del archivo
#### Valor de retorno
* Puntero a la línea extraída
* `NULL` si `stash` es `NULL` o `tá vacío
* `NULL` si falla la reserva de memoria

### read_to_stash
La función `read_to_stash` lee datos desde un `file descriptor` y los acumula en `stash` hasta encontrar un separador de línea (`SEPARATOR`) o alcanzar el `EOF`.

Su objetivo es garantizar que `stash` contenga al menos una línea completa antes de que `get_next_line` intente extraerla.
```C
static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;
	char	*tmp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(stash, SEPARATOR))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(stash), NULL);
		buf[bytes] = '\0';
		tmp = ft_strjoin(stash, buf);
		if (!tmp)
			return (free(buf), free(stash), NULL);
		free(stash);
		stash = tmp;
	}
	free(buf);
	return (stash);
}
```
#### Funcionamiento
* Reserva un buffer temporal de tamaño `BUFFER_SIZE + 1`
* Inicializa el bucle de lectura mientras:
	* La lectura no haya finalizado (`bytes > 0`)
	* No exista aún un separador de línea en stash
* Lee desde el `file descriptor` usando `read`
* Finaliza la cadena leída con `'\0'`
* Concatena el contenido leído al `stash` existente usando `ft_strjoin`
* Libera el `stash` anterior y actualiza el puntero
* Libera el `buffer` al finalizar la lectura
#### Parámetros
* `fd`: `file descriptor` desde el que se realiza la lectura
* `stash`: cadena que contiene los datos acumulados previamente
#### Valor de retorno
* Puntero al `stash` actualizado con el nuevo contenido leído
* `NULL` en caso de error de lectura o fallo en la reserva de memoria

### update_stash
La función `update_stash` actualiza el contenido de `stash` eliminando la línea ya extraída y conservando únicamente el contenido restante para la siguiente llamada a `get_next_line`.

Si no existe contenido pendiente después del separador de línea, libera la memoria y devuelve `NULL`.
```C
char	*update_stash(char *stash)
{
	char	*new_stash;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != SEPARATOR)
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}
```
#### Funcionamiento
* Comprueba que `stash` no sea `NULL`
* Avanza hasta encontrar el carácter separador (`SEPARATOR`)
* Si no hay separador, libera `stash` y devuelve `NULL`
* Avanza una posición para saltar el separador
* Reserva memoria para el nuevo `stash` con el contenido restante
* Copia los caracteres sobrantes
* Termina la nueva cadena con `'\0'`
* Libera el `stash` original
#### Parámetros
* `stash`: cadena que contiene los datos acumulados leídos del archivo
#### Valor de retorno
* Puntero al nuevo `stash` con el contenido restante
* `NULL` si no hay datos pendientes o si ocurre un error de memoria

### get_next_line
La función `get_next_line` lee y devuelve una línea por llamada desde un `file descriptor`. Mantiene internamente el estado de lectura entre llamadas sucesivas, permitiendo continuar exactamente donde se dejó la lectura anterior.

La línea devuelta incluye el carácter separador (`SEPARATOR`, normalmente `'\n'`) si está presente.
```C
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}
```
#### Funcionamiento
1. Validación de entrada
	* Comprueba que el `file descriptor` sea válido
	* Verifica que `BUFFER_SIZE` sea mayor que 0
2. Lectura incremental
	* Llama a `read_to_stash` para leer desde el archivo y acumular el contenido en `stash`
	* La lectura se detiene al encontrar un separador de línea o al llegar al `EOF`
3. Extracción de la línea
	* Utiliza `get_line` para extraer la primera línea completa almacenada en `stash`
4. Actualización del estado
	* Llama a `update_stas`h para eliminar la línea ya procesada
	* Conserva el contenido restante para la siguiente llamada
5. Retorno
	* Devuelve la línea leída
	* Devuelve `NULL` cuando no quedan líneas por leer o ocurre un error

### CABECERA
```C
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef SEPARATOR
#  define SEPARATOR '\n'
# endif

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *a, char *b);
char	*ft_strchr(const char *s, int c);
char	*get_line(char *stash);
char	*update_stash(char *stash);
char	*get_next_line(int fd);

#endif
```