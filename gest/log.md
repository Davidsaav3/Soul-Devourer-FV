# Log del trabajo realizado por dia
**El log es obligatorio**

## 20210108 FidelAznar @(1h)
Debe contener un sub item como el anterior, con la fecha de la entrada y las cuestiones generales que se realizaron, así como el tiempo total dedicado en la sesión. 

---
## HITO 1 ##

## 2022-02-28 Davidsaav3 @(2h)
-Toma de contacto con git y directorios del proyecto

## 2022-03-01 Davidsaav3 @(3h)
-Arreglar problemas git 
-Crear subcarpetas prot por usuario
-Actualizar documentacion sobre el grupo y reparto de tareas

## 2022-03-06 Davidsaav3 @(3h)
-Investigación menus clases y funciones 
-Pruebas de ejecución carpetas
-Pruebas de botones en el menú y su enlace con otras páginas 
(Muchos errores de compilacion hasta entender organizacion en carpetas)

## 2022-03-06 jbr37 @(3h)
-Creación de la clase jugador
-Investigar estructura de clases y métodos
-Intentar dibujar el sprite del jugador, no conseguido

## 2022-03-07 Todos @(1h)
en la sesión 2 del hito 1 hemos tenido problemas para poder subir y descargar archivos de git.
Solucionado.

## 2022-03-07 Davidsaav3 @(2h) En clase
-Chequeo de formato de código, añadir comentarios explicativos para los compañeros (Rutinario pero util a la larga)

## 2022-03-07 Davidsaav3 @(4h) Por la tarde
-Investigar estructura (Motor y Run)
-Investigar bucle juego
-Investigar Input-Update-Render
(Mucho tiempo invertido, pero vale la pena para tener las estructuras claras)

## 2022-03-10 Davidsaav3 @(2h)
-Apuntar nuevas tareas de la semana
-Mejora estado-mapa
-git log para no subir carpeta build
(casi termnado el menú)

## 2022-03-08 jbr37 @(2h)
-Solucionar el dibujado del sprite del jugador en la pantalla

## 2022-03-08 amg334 @(2h)
-Inventigación movimiento y colisiones básicas

## 2022-03-09 jbr37 @(2h)
-Investigar sobre SFML, sobretodo sobre el uso del clock y las boundingboxes

## 2022-03-09 amg334 @(2h)
-Prueba con código para movimiento del personaje

## 2022-03-09 AlexandruCarlos @(5h)
-Investigar funciones sfml
-Investigar bucle juego
-Investigar Input-Update-Render
-Crear clases colision y enemigos
-Investigar como ponerle una IA al enemigo
-Intentar añadir enemigo pero no carga el sprite (solucion posteriormente)
-Problema sprite solucionado
-Investigar movimiento enemigo 
-Añadir un enemigo
-Añadir movimiento al enemigo

## 2022-03-10 Davidsaav3 @(3h)
-Primeras pruebas con mapas en formato tmx
-Eliminar warnings tontos
-Añadir tiny xml (investigación y errores de ejecucución de pérdida de memoia)

## 2022-03-10 jbr37 @(6h)
-Implementación de ataque básico del jugador: 
    -Cambio de sprite usando un clock para devolver al jugador a la animación iddle al terminar el ataque
    -Crear boundingbox del jugador
    -Creación de un enemigo estático para comprobar el ataque del jugador
    -Comprobar la intersección de las boundingboxes de ambos para saber si el ataque impacta
    -Restarle la vida al enemigo
    -Movimiento del personaje en el eje horizontal.
[He conseguido terminar el ataque básico por el momento, a la hora de implementar el codigo en grupo para el siguiente hito se tendran que cambiar sprites y hacer ajustes etc, pero es una buena base y ya se como funciona mas o menos un poco todo]

## 2022-03-12 Davidsaav3 @(1h)
-Primeras pruebas con map.cpp
(mucha investigación)

## 2022-03-12 AlexandruCarlos @(5h)
-Investigar deteccion de jugador 
-Vision de enmigo insertada con rectangle shapes
-Perseguir al jugador al entrar en su campo de vision
-Cambiar sprite enemigo al acercarse

## 2022-03-13 jbr37 @(2h)
-Investigar sistema de ficheros para poder realizar el guardado

## 2022-03-13 amg334 @(3h)
-Investigar mapa y meter algo relacionado con la historia(idea relacionada con las runas)

## 2022-03-14 Davidsaav3 @(6h en total, varios dias)
-Problema al integrar tinyxml.Mucho tiempo para solucionar el error de compilación
-Dia completo dedicado a visualizar mapa de forma correcta
-Encuadre mapa / crear m1.tmx en formato default
-Investigar funciones Tinytmx
-Muchos push para guardar el avance

## 2022-03-14 jbr37 @(2h)
-Crear fichero txt para guardar datos
-Volcar la información del jugador en ese fichero si pulsamos una tecla determinada (solo tenemos la posicion actualmente)

## 2022-03-14 AlexandruCarlos @(5h)
-Añadir clase runa
-Intentar mejorar movimiento enemigo
-Añadir sonido al enemigo cuando ataca
-Añadidas las runas
-Cada runa te da una habilidad nueva
-Por cada runa que tengas se aumentan las habilidades, es decir puslas una tecla adicional y hace una accion que no tenias antes
-Las runas desaparecen al cojerlas
-Movimiento enemigo mejorado

## 2022-03-14 amg334  @(2h)
-Avance con movimiento , creando otra clase se solucionan los problemas
-Desechar idea con la historia (runas)
-Investigación de diálogos con personaje

## 2022-03-15 Davidsaav3 @(2h)
-Apumtar avance en Autoevaluacion y log
-En el tiempo de clase solucioné warnings
Resolví dudas con Filel sobre el mapa 
y edité el bucle principal del suelo

## 2022-03-15 amg334 @(3h)
-Problemas en movimiento con jugador
-Colisiones con borde de mapa terminada
-Crear nueva clase para hacer diálogos
-Investigar sobre mapa 

## 2022-03-15 amg334@ (2h)
-Actualización log
-Investigar idea obtención almas como elemento explicativo de la historia con el que interactuar

## 2022-03-16 Davidsaav3 @(4h)
-Mejora visual en map.cpp
-Rescalado de m1.tmx
-Optimización de bucles en map.cpp
(Algunos poblemas, pero al final el mapa se imprime perfectamente 16*9 tiles en pantalla)

## 2022-03-17 Davidsaav3 @(2h)p/
-Mejora de el aspecto visual de menu.cpp 
-Reajuste en Estado.cpp (más tiempo del estimado)
(aprender herencia cpp)
-https://www.sourcecodeexamples.net/2020/09/c-state-pattern-example.html

## 2022-03-17 amg334@ (2h)
-Buscar Información sobre creación de diálogos

## 2022-03-19 amg334@ (5h)
-Mejora en movimiento
-Creación de npc
-Mejora de juego
-Solucionar problema con código
-Algunos cambios que mejoran el código
-Implementación de imagen de fondo y cuadro de diálogo primitivo

## 2022-03-20 amg334@ (4h)
-Terminar clase npc
-Mejora en los diálogos y implementación de más
-Terminar algunas cosas clase jugador

## 2022-03-20 Davidsaav3 @(4h)
-Arreglo algunos warnings
-Comento código
-Ajuste Log, Tareas y autoevaluacion grupal
(sin incidentes)

## 2022-03-20 amg334@ (2h)
-Limpiar código y comentar
-Escribir log,tareas y autoevaluación

## 2022-03-19 IsabelBox @(10min)
-Nuevo planteamiento de la clase Jefe (Boss):
    - Boss es un enemigo con muchas diferencias del resto --> agrupar sus características a parte
Fuentes utilizadas para el desarrollo del código:
https://www.youtube.com/watch?v=--EYcZW6mfY
Parte del código de mi compañero Alexu dado que la base es similar --> Su clase colisiones.

## 2022-03-19 IsabelBox @(1h 30min)
-Bases de la clase Boss (basadas en la estructura de la clase enemigo) --> elementos de aquí irán cambiando con el desarrollo de la clase, pero son clave para tener una base de trabajo

## 2022-03-20 IsabelBox @(2h)
-Se descarta la forma anterior de hacer el Boss. Se utiliza mucho código de enemigo, conviene heredar. Rearganizo basándome en la clase enemigo de Alexu.
Investigando ciertas características de herencia que me ocasionan problemas. Todavía no está del todo claro.

## 2022-03-20 IsabelBox @(1h)
-Arreglos de compilación e investigación base de herencia en c++ para aplicarla a métodos.
Fuentes:
https://parzibyte.me/blog/2019/06/19/herencia-clases-cpp/#Llamar_a_metodos_de_la_clase_padre
https://parzibyte.me/blog/2019/06/19/herencia-clases-cpp/#Sobreescribir_metodos
dis.um.es/~bmoros/privado/apuntes/Curso08-09/POO3-C++-0809.pdf

## HITO 2 ##
## 2022-03-30 amg334 @(2h)
-Investigación salto y gravedad
## 2022-03-30 davidsaav3 @(2h)
-problemas como las capas. Ya que si añado más de 3 capas me da error la impresión y no entiendo porque.
Por lo tanto decido imprimir el fondo como una imagen y dejar 3 capas. Una para colisiones. Otra para objetos superiores al personaje y otra invisible para runas, nps y otro tipo de colocaciones. 

## 2022-04-03 davidsaav3 @(4h)
-Intenté crear una clase jugador para ayudar a mis compañeros y estuve mucho tiempo intentando que un personaje se imprimiera pero no lo consigo. 

## 2022-04-04 davidsaav3 @(1h)
-he añadido en resources-mapas un txt junto a cada mapa con más descripción del tensheet, para así ayudarme a crear el mapa lo más fiel posible. 

## 2022-04-04 davidsaav3 @(2h)
-el sistema de estados intermedios entre mapas no funciona bien porque tengo un problema de como hacer una llamada desde estado gana.cpp a nivel.cpp para que devuelva a estado numero 0 (mapa).
Continuaré trabajando en eso. 

## 2022-04-05 AlexandruCarlos @(4h)
-Crear enemigo y introducirlo en el mapa con sus animaciones y la IA

## 2022-04-05 jbr37 @(3h)
-hacer que el personaje se imprima correctamente por pantalla, he tenido que cambiar cosas con respecto al codigo que implementé del hito 1 y ha llevado mas de lo que planeaba
-añadir un stat de vida, crear diferentes getters y correciones menores

## 2022-04-05 davidsaav3 @(2h)
-Alado colision con bordes (aun no va col con tiles) 
-Añado puertas para cambiar de nivel 

## 2022-04-06 AlexandruCarlos @(6h)
-Mejorar la IA del enemigo que te persiga , solucionar las animaciones del enemigo
-Posicionarlo en el mapa
-Hacer varios enemigos
-Timear bien el ataque con la hitbox del jugador

## 2022-04-06 davidsaav3 @(6h)
Este día actualice el bucle del juego para que cuando acabes el juego puedas re jugarlo. Me llevo un tiempo entender como hacerlo. Puse el spawn personalizado para el personaje en cada nivel. Sencillo pero laborioso. Prototipos con movimiento con cámara, un lío pero funciona bien. 
Mejore las colisiones q fallaban en ciertos puntos como rampas, creía que iba a ser más difícil. Y arregle bug en algunos niveles con las colisiones, laborioso.

## 2022-04-06 amg334 @(2h)
-Implementación del código en el salto y colisiones

## 2022-04-06 jbr37 @(3h)
-documentarme sobre sfml y c++ para poder empezar a hacer los ataques y sus respectivas animaciones

## 2022-04-07 AlexandruCarlos @(6h)
-Añadir enemigo nuevo que de dispara
-Movimiento y animacion del enemigo
-Añadir proyectil
-Crear movimiento proyectil
-Funciones del proyectil de quitar vida, desaparecer , etc...

## 2022-04-07 jbr37 @(4h)
-documentarme sobre animaciones en sfml y c++, 
-primer intento de crear animación de ataque para el personaje

## 2022-04-07 jbr37 @(7h)
-crear un gestor de animaciones para poder usarlo con todas las animaciones posteriores que quiera añadir de forma facil
-documentarme sobre las clases y ver como y donde podia hacer gestionar las colisiones de enemigo y el personaje para crear el ataque
-programar ataque del personaje en base a lo anterior, ha salido bien y tenemos un ataque básico funcional con una animación propia.

## 2022-04-07 jbr37 @(1h)
-crear animacion de correr para el personaje, he utilizado el gestor que creé previamente pero aun asi he tenido alguna dificultad a la hora de cambiar sprites y detectar cuando tiene que parar de hacer la animación.

## 2022-04-07 davidsaav3 @(6h)
Este día cree el mapa final de todos los niveles restantes al inicial y el último. Me llevo mucho tiempo y creatividad. Añadí de nuevo colisiones q habían desaparecido. Errores corregidos en mapas, al ser nuevos había muchos. Y conseguí centrar el personaje con la cámara en los mapas que lo necesitaban. Que me llevo mucho tiempo pero estoy muy contento porque era de lo que pensaba que era más difícil. 

## 2022-04-08 AlexandruCarlos @(6h)
-Varios tipos de enemigos
-Mejora IA del enemigo
-Posicionamiento enemigos en los mapas
-Funciones de proyectiles

## 2022-04-08 jbr37 @(2h)
-crear ataque fuerte del personaje

## 2022-04-09 AlexandruCarlos @(5h)
-Colisiones proyectiles mapas
-Colisiones proyectiles personaje
-Mejora deteccion de colision
-Runas añadidas

## 2022-04-09 davidsaav3 @(8h)
Este día arreglé un bug extraño con varias escaleras del mapa. Termine el estilo visual de los menús, a mi parecer atractivos.  Arregle un bug del nivel 6 en el cual el fondo se descentraba con la cámara. Y otro bug con los corazones del hud. Además de añadir un sonido de feedback en el menú. Y su respectiva investigación (sonidos cpp).

## 2022-04-10 AlexandruCarlos @(3h)
-Funcionamiento de las runas
-Ataques por runa

## 2022-04-10 amg334 @(5h)
-Intento de implementación final de las colisiones sin exito y más investigación

## 2022-04-10 davidsaav3 @(8h)
<<<<<<< HEAD
Día largo de trabajo, Intenté crear un prototipo de animación inicial, pero no me funcionó. Añadí con éxito corazones en el hud del juego que se van restando de medio corazón en medio corazón. También hice funciones como llave() para facilitar colisiones con tiles a los compañeros. Hicimos un Mercedes con developer y arregle un problema derivado de esto. Por último arregle un bug que hacía q en mapas superiores al inicial no se mostraba pantalla de muerte ni pausa y era que estaba descentrado de la vista este menú. 

## 2022-04-11 davidsaav3 @(8h)
ultimo dia antes de la entrega del hito 2, solucionando errores menores a otros compañeros y propios. En el nivel 3 seguún que puertas selcciones irás al nivel secreto 3.1 o al nivel 4, Además también insertar interpolación y dejar a punto la lista de tareas. Dia intenso de trabajo ultimando carectirísticas. Además de algún error con las capas de los mapas.
Por la tarde centre el sprite de la puerta cerrada encima de la puerta abierta. También hice que no se aumentara la velocidad al
Ir en , como nos explicó Fidel en teoría. Esto me costó un poco, pero sin problemas. También ajústenlas características del mapa que tenían que reactivarse de nuevo al morir y reaparecer, que también tarde un poco, pero lo conseguí. Por último intenté el tema de la interpolación ya que nadie lo había implementado, pero obtuve muchos errores y desistí, en el tercer hito se añadirá.


=======
-Añado un prototipo de animacion inicial / Añado los corazones al hud corazones hud (prot); 
-Elimino las cajas del mapa / Añado texto en menu pausa , en menu muertey menu final; 
-sprite corazoncitos de vida añadidos / Añadida nueva pariencia en pagina desarrollador y controles;
-Añadida funcion llave() para isabel y uarreglo n bug tonto; 
-La lava ahora mata / Subido prot de puerta cerrada hasta que no matas todos los enemigos; 
-Error no poder poner pausa en niveles superires al 0  solucionado;
-Las puertas funcionan perfectas ya; 
-Añadido acceso desde pausa controles para poder volver a mapa;
-subido launch.json arreglado al pasar a rama develop; 

## 2022-04-11 davidsaav3 @(6h)
-Ultimo dia antes de la entrega del hito 2, solucionando errores menores a otros compañeros y propios. En el nivel 3 seguún que puertas selcciones irás al nivel secreto 3.1 o al nivel 4, Además también insertar interpolación y dejar a punto la lista de tareas. Dia intenso de trabajo ultimando carectirísticas. Además de algún error con las capas de los mapas.
-Puertas cerradas encajan con las abiertas; 30min; davidsaav3`
-Al ir en diagonal ya no corres; 1h; davidsaav3`
-Problemas con algunas escaleras arreglado; 45min; davidsaav3`
-Añadida logica de puetas / Nivel secreto ya es secreto; 2h; davidsaav3`
-Al morir aparecen los enemigos que habian muerto / Al rejuegar la vida vueve a ser 10; 1h; davidsaav3`
-Caja quitada; 1min xd; davidsaav3`
-Solucionado error escalera mapa 2 / controles actualizados; 1h; davidsaav3`
-Prot INTERPOLACION

## 2022-04-10 jbr37 @(2h)
-primera aproximacion al ataque a distancia, me he documentado acerca de los proyectiles que ya estabamos utilizando en la clase enemigo, y he escrito una parte del código pero todavia no funciona.

## 2022-04-10 jbr37 @(3h)
-crear ataque a distancia practicamente funcional, dispara y le resta vida al enemigo y todo eso bien, pero actualmente solo dispara hacia el lado derecho, tengo que arreglarlo

## 2022-04-11 jbr37 @(1h)
-arreglar el ataque a distancia, ya dispara hacia el lado que estes mirando perfectamente

## 2022-04-11 jbr37 @(3h)
-primer prototipo del dash, funciona relativamente bien pero solo hacia la derecha, tengo que corregir eso
-dash arreglado, ya funciona hacia el lado que estes mirando

## 2022-04-11 amg334 @(5h)
-Intento de implementación final de las colisiones y el salto sin exito y más investigación
-Implementación de animaciones de salto y caida 
-Ivestigación sobre diálogos

## 2022-04-11 IsabelBox @(20h)
Voy a juntar la investigación de estos dos últimos días en este log:
-Funcionamiento de impresión de Sprites.
-Reorganización de la clase Jefe.
-Investigación sobre colisiones y tipos (para detectar al personaje, para que infrinjan daño).
-Funcionamiento de las animaciones (base).
-Separar el jefe en dos clases:
    -Esto es debido a que a lo largo del juego, menos al final, hace una función distinta en el juego. No merece la pena tenerlo junto, era más sencillo separarlo en dos clases. La clase jefe está desarrollada, pero jefeNPC no (pero ya sé cómo hacerla con el conocimiento que he adquirido, es sencillo, listo para el hito 3).
-Dejar los elementos de dibujo en el mapa al motor, pero crear mi propio render del jefe para espeficar.
-Nuevo planteamiento de las fases del jefe según su vida (tres fases según el rano de vida en el que esté).
-Cambio de esprites según la posición del personaje en el rángo de visión del jefe.
-Planteaminto de cómo dibujar los nuevos sprites del jefe (el que tiene ahora es una base conveniente sobre la que dibujar en el siguiente hito)
-Planteamiento de un escudo (intención de que sea un circleShape que le rodee, previsto de implementar).
-Sprite espíritu (jefeNPC) preparado para su implementación.
-Nuevo planteamiento de las colisiones de daño:
    -Antes eran distintos rectángulos por cada lado, ahora es un rectángulo dentral.
-Usar colisiones de observación (para ver al parsonaje) tambíen para atacar (implementación pendiente de lo segundo).

Voy a juntar la investigación de estos últimos días en este log:
    - Métodos de edición de sprites
    - Repaso a métodos de animación
    - Investigación sobre animación de formas

## 2022-05-03 davidsaav3 @(4h)
He creado una nueva clase interpolación, como recomendó el profesor en clase de prácticas. Además he tenido que modificar el método renders de cada clase. Primeros pasos necesarios para la interpolación.

## 2022-05-04 davidsaav3 @(8h)
Día totalmente enfocado a la interpolación. Primero adapte la clase enemigo ya que me pareció más sencilla cambiar la función move() por mis variables auxiliares para interpolación. Y por último el prototipo del agua con transparencias. 
Depsues he cambiado el spawn de la clase nivel a la clase interpolación, después he intentado aplicar ya por fin a los enemigos la interpolación pero sin éxito ya que son muchos y tendría que controlar sus posiciones de manera individual.
Por lo que decidí sólo implementar interpolación en el jefe final y en el personaje principal refinarla para que funcionara perfectamente. Costoso pero útil en el proyecto.

## 2022-05-07 davidsaav3 @(5h)
Hoy he implementado destructores en cada una de las clases, he tenido que investigar un poco. Depsues he decidido hacer algo más sencillo como añadir música al juego. Por último he comenzado a implementar lo que nos recomendó el profesor de solocarprot fuego agua en movimiento; 

## 2022-05-08 davidsaav3 @(2h)
Hoy he seguido con mejoras al sistema de la lava y el agua en movimiento y ya está casi casi terminado.

## 2022-05-09 davidsaav3 @(6h)
Ahora ya funciona perfecto la lava y el agua en movimiento. Por otra parte austé la fuerza de salto del personaje para que accediera bien a  todas las partes. 
Y por último y más importante el personaje ya no vuela, ni asciende ni desciende si no hay escalera para poder subir por ellas. Ni tampoco se puede mover en diagonal.

## 2022-05-11 davidsaav3 @(4h)
Despues de clase me puse a arreglar el subir escaler. Sin problema. Por otra parte tambien al bajar de la escalera ya no baja mas de la cuenta, porque se quedaba pillado el personaje. Por último mejoré las rampas en todas las dirccciones y sentidos. Para bajarlas hay que pulsar la dirección + S. Dia completo de trabajo. 

## 2022-05-15 davidsaav3 @(10h)
La página de controles actualizada con los nuevos y la Z se activa el modo hacker para que se abra la puerta sin matar a ningún enemigo ni optener runa.
 
Además de esto he crreado el powerpoint que se usará en la presentación y compartido a mis compañeros para que realicen algun minimo cámbio si lo desean.
 
## 2022-05-16 davidsaav3 @(7h)
Último dia antes de la entrega del Hito3. He adaptado la textura de la puerta cerrada almestilo pixel art que usamos ahora. Además he implemnetado un texto que indique si se activa o desactiva el modo hacker nates explicado. Por último he hecho al personaje más alto. Y l bajar una escalera se situa el correcto. EEl único problema ha sido el cansancio y el esrés de solucionar el máximo número de bugs antes de la entrega. 
