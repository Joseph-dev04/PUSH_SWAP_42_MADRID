*Este proyecto ha sido creado como parte del currículo de 42 por jopajuel y aitorres*

# 📖 Push_swap
Porque Swap_push no suena tan natural
<br><br>

# 🔍 Descripción

Este programa trata de ordenar una serie de números, tanto positivos como negativos, en orden creciente, de menor a mayor.
Soo disponemos de dos pilas de datos, comenzaremos con ellas vacíos, los números que le metamos al programa, se añaden al stack A y B empieza vacío. Todos los números se suman inicialmente a la pila A y la pila B está vacía.
COmo resumen:
Para empezar:
* El stack a contiene una cantidad aleatoria de números positivos y/o negativos.
* El stack b está vacío.
* El objetivo es ordenar los números del stack a en orden ascendente. Para hacerlo están disponibles las siguientes operaciones:


### Operaciones

| Operaciones 	| Explicación |
| :--- 			| :--- |
| sa 			| swap a - Intercambia los dos primeros elementos del stack a. No hace nada si hay solo uno o ningún elemento. |
| sb 			| swap b - intercambia los dos primeros elementos encima del stack b. No hace nada si hay solo uno o ningún elemento.|
| ss 			| swap a y swap b a la vez. |
| pa 			| push a -  toma el primer elemento del stack b y lo pone encima del stack a. No hace nada si b está vacío.|
| pb 			| push b -  toma el primer elemento del stack a y lo pone encima del stack b. No hace nada si a está vacío.|
| ra 			| rotate a - desplaza hacia arriba todos los elementos del stack a una posición, el primer elemento se convierte en el último. |
| rb 			| rotate b - desplaza hacia arriba todos los elementos del stack b una posición, el primer elemento se convierte en el último. |
| rr 			| ra y rb a la vez. |
| rra 			| reverse rotate a - desplaza hacia abajo todos los elementos del stack a una posición, el último elemento se convierte en el primero. |
| rrb 			| reverse rotate b - desplaza hacia abajo todos los elementos del stack b una posición, el último elemento se convierte en el primero. |
| rrr 			| rra y rrb a la vez. |


Este programa nos ordenrá los números según el tipo de orden, disponemos de 4 métodos:


Disponemos de 4 métodos de ordenacion, los podremos aplicar con las siguientes flags:

| flags 		| Explicación |
| :--- 			| :--- |
| --simple 		| fuerza algoritmo O(n2) seleccionado. |
| --medium 		| fuerza el uso de el algoritmo O(n√n) seleccionado.|
| --complex 	| fuerza el uso de el algoritmo O(n log n) seleccionado.|
| --adaptive 	| uerza el uso de el algoritmo adaptativo basado en desorden seleccionado. Este será el comportamiento por defecto si no se indica un selector. |

Por último, 
La salida por consola de esta estrategia deberá ser la secuencia de operaciones (sa, sb, rra,....) necesarias para ordenar el stack.
Tambien nos mostrará el índice de desorden, con un mensaje en ppantalla. Este dato se medirá en 0 si está ordenado y 1 Si está muy muy desordenado.
Todo lo que haya entre medias del 0 y el 1, significará que el stack se encuentra parcialmente ordenado, pero sigue teniendo desorden. 


### Algoritmia

* Algoritmo simple (O(n2)):
	* Se usa cuando el conjunto de datos es pequeño o el nivel de desorden es bajo.
		* 10 elementos → 10 × 10 = 100 operaciones máximas
		* 100 elementos → 100 × 100 = 10,000 operaciones
	* Técnica interna: Basado en la Extracción del Mínimo. El algoritmo busca el valor más pequeño en el stack A, lo posiciona en la parte superior mediante rotaciones inteligentes (eligiendo entre ra o rra según la distancia más corta) y lo desplaza al stack B con pb. Una vez que A está vacío, se devuelven todos los elementos con pa.
	aitorres

* Algoritmo intermedio (O(n√n)):
	* Se usa cuando el desorden es moderado. Divide parcialmente el problema.
		* 100 elementos
		* √100 = 10
		* 100 × 10 = 1,000 operaciones
	* Técnica interna: Estrategia de Partición por Rangos. Dividimos el total de números en nn ​ bloques (chunks). El algoritmo identifica los números que pertenecen al rango actual y los envía al stack B. Al usar bloques, limitamos el rango de búsqueda y reducimos drásticamente las rotaciones necesarias en comparación con el método simple.
	aitorres

* Algoritmo complejo (O(n log n)):
	* Se usa cuando el desorden es alto. Divide el problema en partes y las combina eficientemente.
		* 100 elementos
		* log₂(100) ≈ 7
		* 100 × 7 = 700 operaciones aproximadas
	* Técnica interna: Se encarga de hacer una indexacion real a traves de un array de enteros, y luego a traves de cada bit empieza hacer comapraciones y a ordenarlos. Utilizamos una mezcla de el radix mezclado con el calculo de la complejidad por movimiento.
	jopajuel

* Algoritmo adaptativo personalizado: 
	* Examina su grado de complejidad, según ese grado de complejidad aplicará un Algoritmo simple, intermedio o complejo.
		* Índice de desorden bajo: Si desorden < 0,2, el método elegido debe ejecutarse en O(n).
		* Índice de desorden medio: Si 0,2 ≤ desorden < 0,5, el método elegido debe ejecutarse en O(n√n).
		* Índice de desorden alto: Si desorden ≥ 0,5, el método elegido debe ejecutarse en O(n log n).
	jopajuel

### Benchmark
El proyecto incluye un sistema de benchmarking integrado que permite analizar el rendimiento de los algoritmos en tiempo real. Este modo se activa mediante la flag --bench y está diseñado para integrarse con herramientas de evaluación externas.

Redirección de Métricas:
* Todas las estadísticas se envían a través del canal de errores estándar (stderr, fd 2). Esto permite capturar las métricas en un archivo independiente (ej. 2> bench.txt) mientras el programa sigue funcionando normalmente.

Métricas capturadas:
* Índice de Desorden (DD):
	* Cálculo preciso del estado inicial del stack (de 0.0 a 1.0) mediante el conteo de inversiones.
* Estrategia Seleccionada:
	* Identifica qué algoritmo ha decidido aplicar el modo adaptativo basándose en el desorden detectado.
* Contador Total de Operaciones:
	* Suma acumulada de todos los movimientos realizados.
* Desglose por Operación:
	* Conteo individualizado de cada instrucción (sa, pb, ra, rra, etc.), lo que permite identificar cuellos de botella en la lógica de rotación.
<hr><hr><br><br>

# 📝 Instrucciones

Una vez tengas el respositorio, ejecuta la consola/Terminal dentro de ella.

Escribe `make`para compilar todo, `make clean` para borrar la creaccioón de los objetos.

A continuacion ekecuta ese archivo nuevo creado llamado pushswap, escribe en consola `./push_swap` y acontinuación todos los números que quieras, negativos o positivos, puedes meterlos entre `"8 10 8"` sin ellas `8 4 -55` o mezclado `"10 -999 78" 87  6 -888 "4"` incluso con espacios de separación entre ellos `"10             -999            78" 87  6 -888      "4"`.

En caso que se detecten números duplicados o caracteres no admitidos como un signo negativo o positivo, el programa trasnmitirá un `ERROR`.

Una vez tengas tu lista, pulsa Enter y disfruta de una cadena de mensajes de cada paso y sus operaciones que ha realizado el programa. Ejemplos:

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

Como hablamos anteriormente, podemos incluir una serie de flags antes de ejecutar el programa con el grado de complejidad, en el ejemplo anterior, al no haber escrito ninguno, se ejecutará con el adaptativo, sino `--simple`, `--medium`, `--complex`e incluso `--adaptative` si quieres:

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



./push_swap --bench "10             -999            78" 87  6 -888      "4" 2> bench.txt

cat bench.txt

	[bench] disorder: 40.00%
	[bench] strategy: Adaptive / O(n√n)
	[bench] total_ops: 13
	[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
	[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0

Ejemplo sin ninguna flag de complejidad ni benchmark (usa modo adaptativo por defecto):

	./push_swap "10             -999            78" 87  6 -888      "4"
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

### Verificación con el Checker:

Para confirmar que la lista se ha ordenado correctamente, puedes redirigir la salida de push_swap al programa checker:

	ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG 
	OK

Si el resultado es OK, significa que la secuencia de operaciones es válida y el stack ha quedado ordenado.
jopajuel y aitorres

<hr><hr><br><br>


# 🛠️ Recursos

Para la realización de este proyecto, hemos seguido una metodología de investigación y resolución de problemas basada en diversas fuentes:

Documentación y Algoritmia

* Análisis de Complejidad: Consulta de documentación sobre estructuras de datos (listas enlazadas) y análisis de algoritmos para comprender las diferencias entre O(n2)O(n2), O(nn)O(nn​) y O(nlog⁡n)O(nlogn).
* Comunidad 42: Intercambio de lógica con otros estudiantes para optimizar el número de movimientos y entender casos límite (edge cases).

Herramientas de Depuración

* Valgrind: Utilizado exhaustivamente para garantizar la ausencia de fugas de memoria (memory leaks) y errores de gestión de punteros.
* Visualizadores de Push_swap: Uso de herramientas gráficas de la comunidad para observar el comportamiento de los algoritmos y detectar ineficiencias en las rotaciones.

Apoyo Tecnológico e IA
* Se ha utilizado la Inteligencia Artificial como un recurso de apoyo crítico cuando la lógica teórica chocaba con errores de implementación difíciles de detectar a simple vista.
