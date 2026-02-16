# 📖 Push_swap

Este proyecto ha sido creado como parte del currículo de 42 por jopajuel, aitorres

## Descripción
Este programa trata de ordenar una serie de números, tanto positivos como negativos, en orden creciente, de menor a mayor.
Soo disponemos de dos pilas de datos, comenzaremos con ellas vacíos, los números que le metamos al programa, se añaden al stack A y B empieza vacío. Todos los números se suman inicialmente a la pila A y la pila B está vacía.
COmo resumen:
Para empezar:
* El stack a contiene una cantidad aleatoria de números positivos y/o negativos.
* El stack b está vacío.
* El objetivo es ordenar los números del stack a en orden ascendente. Para hacerlo están disponibles las siguientes operaciones:


### Operaciones 🔁

| Operaciones | Explicación |
| :--- | :--- |
| sa | swap a - Intercambia los dos primeros elementos del stack a. No hace nada si hay solo uno o ningún elemento. |
| sb | swap b - intercambia los dos primeros elementos encima del stack b. No hace nada si hay solo uno o ningún elemento.|
| ss | swap a y swap b a la vez. |
| pa | push a -  toma el primer elemento del stack b y lo pone encima del stack a. No hace nada si b está vacío.|
| pb | push b -  toma el primer elemento del stack a y lo pone encima del stack b. No hace nada si a está vacío.|
| ra | rotate a - desplaza hacia arriba todos los elementos del stack a una posición, el primer elemento se convierte en el último. |
| rb | rotate b - desplaza hacia arriba todos los elementos del stack b una posición, el primer elemento se convierte en el último. |
| rr | ra y rb a la vez. |
| rra | reverse rotate a - desplaza hacia abajo todos los elementos del stack a una posición, el último elemento se convierte en el primero. |
| rrb | reverse rotate b - desplaza hacia abajo todos los elementos del stack b una posición, el último elemento se convierte en el primero. |
| rrr | rra y rrb a la vez. |


Este programa nos ordenrá los números según el tipo de orden, disponemos de 4 métodos:


Disponemos de 4 métodos de ordenacion, los podremos aplicar con las siguientes flags:

| flags | Explicación |
| :--- | :--- |
| --simple, | fuerza algoritmo O(n2) seleccionado. |
| --medium | fuerza el uso de el algoritmo O(n√n) seleccionado.|
| --complex | fuerza el uso de el algoritmo O(n log n) seleccionado.|
| --adaptive | uerza el uso de el algoritmo adaptativo basado en desorden seleccionado. Este será el comportamiento por defecto si no se indica un selector. |

Por último, 
La salida por consola de esta estrategia deberá ser la secuencia de operaciones (sa, sb, rra,....) necesarias para ordenar el stack.
Tambien nos mostrará el índice de desorden, con un mensaje en ppantalla. Este dato se medirá en 0 si está ordenado y 1 Si está muy muy desordenado.
Todo lo que haya entre medias del 0 y el 1, significará que el stack se encuentra parcialmente ordenado, pero sigue teniendo desorden. 


### Algoritmia

* Algoritmo simple (O(n2)):
	* Se usa cuando el conjunto de datos es pequeño o el nivel de desorden es bajo.
		* 10 elementos → 10 × 10 = 100 operaciones máximas
		* 100 elementos → 100 × 100 = 10,000 operaciones
	* PD: Crecimiento cuadrático.

* Algoritmo intermedio (O(n√n)):
	* Se usa cuando el desorden es moderado. Divide parcialmente el problema.
		* 100 elementos
		* √100 = 10
		* 100 × 10 = 1,000 operaciones
	* PD: Es más eficiente que O(n²), pero menos que O(n log n).

* Algoritmo complejo (O(n log n)):
	* Se usa cuando el desorden es alto. Divide el problema en partes y las combina eficientemente.
		* 100 elementos
		* log₂(100) ≈ 7
		* 100 × 7 = 700 operaciones aproximadas
	PD: Mucho más eficiente que O(n²) para valores grandes.

* Algoritmo adaptativo personalizado: 
	* Examina su grado de complejidad, según ese grado de complejidad aplicará un Algoritmo simple, intermedio o complejo.
		* Índice de desorden bajo: Si desorden < 0,2, el método elegido debe ejecutarse en O(n).
		* Índice de desorden medio: Si 0,2 ≤ desorden < 0,5, el método elegido debe ejecutarse en O(n√n).
		* Índice de desorden alto: Si desorden ≥ 0,5, el método elegido debe ejecutarse en O(n log n).


## Instrucciones

Una vez tengas el respositorio, ejecuta la consola/Terminal dentro de ella.
escribe `make`para compilar todo, make clean para borrar la creaccioón de lso objetos.
A continuacion ekecuta ese archivo nuevo creado llamado pushswap, escribe en consola `./push_swap` y acontinuación todos los números que quieras, negativos o positivos, puedes meterlos entre `"8 10 8"` sin ellas `8 4 -55` o mezclado `"10 -999 78" 87  6 -888 "4"` incluso con espacios de separación entre ellos `"10             -999            78" 87  6 -888      "4"`.
En caso que se detecten números duplicados o caracteres no admitidos como un signo negativo o positivo, el programa trasnmitirá un `ERROR`.

Una vez tengas tu lista, pulsa Enter y disfruta de una cadena de mensajes de cada paso Operación que ha realizado el programa.

		./push_swap "10             -999            78" 87  6 -888      "4"
		ra
		pb
		rra
		pb
		pb
		ra
		pb
		ra
		pb
		pb
		pa
		pa
		pa
		pa
		pa
		pa

Como hablamos anteriormente, podemos incluir una serie de flags antes de ejecutar el programa con el grado de complejidad, en el ejemplo anterior, al no haber escrito ninguno, se ejecutará con el adaptativo.

		./push_swap --simple "10             -999            78" 87  6 -888      "4"
		rra
		pb
		rra
		pb
		rra
		pb
		ra
		pb
		pb
		pa
		pa
		pa
		pa
		pa


## Recursos

Para este proyecto se ha utilizado disntitas fuentes de internet para comprender fallos de compilación. Se ha utilizado la IA como recurso tras no encontrar errores que deberían funcionar si o si y no es conseguido por 4 ojos humanos ver donde estaba. Tras su explicación hemos descubierto pequeños fallos de escritura que nos nos dejaba avanzar.



