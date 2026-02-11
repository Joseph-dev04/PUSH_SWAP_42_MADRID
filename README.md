# PUSH SWAP

Para empezar:
* El stack a contiene una cantidad aleatoria de números positivos y/o negativos.
* El stack b está vacío.
* El objetivo es ordenar los números del stack a en orden ascendente. Para hacerlo están disponibles las siguientes operaciones:

      sa (swap a): Intercambia los dos primeros elementos del stack a.
                  No hace nada si hay solo uno o ningún elemento.


      sb (swap b): Intercambia los dos primeros elementos del stack b.
                No hace nada si hay solo uno o ningún elemento.


      ss : sa y sb a la vez.


      pa (push a): Toma el primer elemento del stack b y lo coloca el primero en el stack a.
          No hace nada si b está vacío.


      pb (push b): Toma el primer elemento del stack a y lo coloca el primero en el stack b.
                  No hace nada si a está vacío.


      ra (rotate a): Desplaza hacia arriba todos los elementos del stack a una posición,
                    convirtiendo el primer elemento en el último.


      rb (rotate b): Desplaza hacia arriba todos los elementos del stack b una posición,
                     convirtiendo el primer elemento en el último.


      rr : ra y rb a la vez.
  

      rra (reverse rotate a): Desplaza hacia abajo todos los elementos del stack a una posición,
                             convirtiendo el último elemento en el primero.


      rrb (reverse rotate b): Desplaza hacia abajo todos los elementos del stack b una posición,
                             convirtiendo el último elemento en el primero


      rrr : rra y rrb a la vez.




### ¿Qué implica “algoritmo simple O(n²)” en push_swap?

En un push_swap, tienes dos stacks (A y B) y solo puedes manipularlos con operaciones:
sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr.

Un algoritmo simple no intenta ser eficiente en número de operaciones, sino extremadamente fácil de implementar.
La idea de O(n²) es que por cada elemento hagas un recorrido casi completo de la lista.

## Método 1: Ordenación por selección (Selection Sort adaptado a push_swap)
Este es uno de los más usados en proyectos push_swap para la parte simple porque:

Algoritmo simple — Selección del mínimo (O(n²)):
Recorro el stack A nodo a nodo para localizar el valor mínimo.
Muevo ese nodo a la cima mediante ra o rra según esté más cerca del principio o del final.
Lo envío a B mediante pb.
Repito el proceso hasta vaciar A.
Finalmente devuelvo todos los elementos de B a A con pa, quedando A ordenado en orden ascendente.
La complejidad es O(n²) porque para cada extracción del mínimo necesito un recorrido completo del stack A.

Inconveniente:
Genera demasiadas operaciones.



## Método 2: Ordenación por inserción (Insertion Sort adaptado a push_swap)
Es muy parecido al Selection, pero conceptualmente distinto.

Cómo funciona Insertion Sort en arrays
Empiezas desde el segundo elemento.
Lo vas “insertando” en la parte izquierda ya ordenada.
En push_swap
Dejas un elemento en A.
Mueves el siguiente a su sitio en B usando:
buscar dónde debería ir
llevar B a esa posición
pb
Al final vuelves todo a A.
Problema:
Insertion sort es más difícil de adaptar porque push_swap no permite insertar en medio fácilmente.
Pero es válido como O(n²).

## Método 3: Bubble Sort adaptado a push_swap
Este es fácil de explicar pero malo para implementar porque bubble sort intercambia elementos adyacentes, y en una lista enlazada con push_swap es engorroso.

Como solo tienes acceso a los dos primeros nodos de la lista (stack_a y stack_a->next), el proceso sería este:

Comparar: Miras los dos primeros nodos de A.
Swap (si hace falta): Si el primero es mayor que el segundo, haces sa.
Rotar: Haces ra. Ahora el que era el segundo está arriba, y el que era el primero (el más grande) ha bajado una posición.
Repetir: Haces esto 
𝑛
n veces (donde 
𝑛
n es el número de elementos).
Bucle externo: Al dar una vuelta completa, el número más grande de todos habrá llegado al fondo de la lista. Tienes que repetir todo el proceso otra vez para el siguiente número más grande.
3. Ejemplo visual con [3, 1, 4, 2]
Estado inicial: A: [3, 1, 4, 2]
¿3 > 1? Sí. → sa → A: [1, 3, 4, 2]
ra → A: [3, 4, 2, 1] (El 1 ya no lo tocamos en esta vuelta).
¿3 > 4? No.
ra → A: [4, 2, 1, 3]
¿4 > 2? Sí. → sa → A: [2, 4, 1, 3]
ra → A: [4, 1, 3, 2]
Si sigues haciendo esto, al final de la primera vuelta el 4 (el más grande) estará abajo del todo.


## Método 4: Extracción simple del mínimo/máximo
Esto es realmente una forma primitiva de selection sort:
ir sacando siempre el mínimo.

Puedes hacerlo de dos formas:

A) Orden ascendente → extraer mínimo
Busca mínimo → súbelo arriba → pb
Repite
B) Orden descendente → extraer máximo
Busca máximo → súbelo arriba → pb
Es literalmente una versión simplificada del selection sort.

¿Qué método te recomiendo elegir para tu O(n²)?
El más sencillo, claro y típico para explicar es:
→ Adaptación del orden por selección (Selection Sort)
Porque te permite explicar:

cómo buscar un nodo mínimo en una lista
cómo usar operaciones ra y rra según con cuál llegas más rápido
por qué la complejidad es O(n²)
cómo indexar ayuda (aunque no obligatorio)
Y además se adapta de manera natural a push_swap.
