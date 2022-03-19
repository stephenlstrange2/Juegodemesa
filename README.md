# Betrayal at the house on the hill

## Personajes
- Atributos físicos
  - Velocidad
  - Poder
- Atributos mentales
  - Cordura
  - Conocimiento
* Todo lo que haga daño en físico, reduce puntaje en los atributos físicos al igual que el daño
mental, en los atributos mentales. Si llega a cero, el personaje fallece. -> pierdes


## Valores iniciales
### Brandon Jaspers
- Velocidad: 4
- Poder: 4
- Cordura: 4
- Conocimiento: 3
### Zoe Ingstrom
- Velocidad: 4
- Poder: 3
- Cordura: 5
- Conocimiento: 3
### Father Rhinohardt
- Velocidad: 3
- Poder: 2
- Cordura: 6
- Conocimiento: 4
## Estructura de la casa
### PLANTA BAJA
- Entrada (Entrance Hall)
- Sala (Foyer)
- Escaleras (Grand Staircase).
### SÓTANO
- Entrada al sótano (Basement Landing).
### PISO DE ARRIBA
- Piso superior (Upper landing).
## Cada turno
- Tomar una carta para constuir el mapa
  - Cada carta indica un cuarto a explorar y se posiciona de acuerdo con el piso
que corresponda.
- Las cartas pueden tener tres símbolos diferentes.
  - Carnero: corresponde a una tarjeta de un ITEM.
  - Espiral: tarjeta de un evento (EVENT).
  - Pájaro: carta de maldición (OMEN).
- En tu turno sólo entras a la sala y tomas la carta (de item event u omen) de acuerdo con la figura que te salió.
  - Carta evento: tiras dado y de acuerdo con la ponderación de la carta es el
resultado es lo que se hace.
  - Carta maldición: te dice lo que tienes que hacer, tiras los dados (6 dados) y si
sacas menos puntos en comparación con las cartas de maldición que ya están
en el tablero, se desata la maldición.
- Sacas el libro del traidor y buscas la carta junto con la recámara para
determinar lo que se tiene que hacer para ganar. Del mismo modo, tus
oponentes sacan el libro del sobreviviente y buscan la misma carta con
la recámara para determinar su estrategia para ganar. Ninguno sabe
cual es la estrategia del otro.



## Cartas
- Habitaciones: 44 cartas
- Omen: 13 cartas
- Inventario: 22 cartas
- Evento: 45 cartas

## Dados
- Dados: 8
  - Solo puede sacar del 0 al 2

## Libros
- Survival: 1 
- Traitor:  1

## Diseno
- Carta del pajarito son inventario
```text
      _...._
    /       \
   /  o _ o
   (    \/  )
  )          (
(    -  -  -  )
(             )
 (            )
  [          ]
---/l\    /l\--------
  ----------------
     (  )
    ( __ _)
```
- carta de espiral son eventualidades
```text
(==(     )==)
 `-.`. ,',-'
    _,-'"
 ,-',' `.`-.
(==(     )==)
 `-.`. ,',-'
    _,-'"
 ,-',' `.`-.
(==(     )==)
 `-.`. ,',-'
    _,-'"
 ,-',' `.`-.
(==(     )==)
```

- carta del chivo son presagios
```text
   ()
   ))    ((
  //      \\
 | \\____// |
\~/ ~    ~\/~~/
 (|    _/o  ~~
  /  /     ,|
 (~~~)__.-\ |
  ``~~    | |
   |      | |
 
```
- Dados
```text
    _______            
  /\       \           
 /  \   ()  \          
/    \_______\         
\    /()     /         
 \  /       /          
  \/_____()/

```

## Funciones
### Dinamica
- Tirar dado
- Sacar carta
  - De habitacion
  - De Evento, Presagio, Inventario
- Colocar carta de mapa
- Dibujar mapa
- Menu de juego


### Estructuras
- Specs de los jugadores
  - Brandon Jaspers
  - Zoe Ingstrom
  - Father Rhinohardt
- Mapa
- Cuarto
- Libro Survival
- Libro Traitor
- Cartas Omen
- Cartas Item
- Cartas Event
