[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Battleship]

## Descripción del Proyecto

Este proyecto consiste en la creación del juego Battleship, en el cual dos jugadores reales se enfrentan por turnos en un tablero de 10x10. Cada jugador coloca sus barcos de forma estratégica sin que el otro los vea, y luego se turnan para adivinar la ubicación de los barcos enemigos disparando a coordenadas específicas. El objetivo es hundir todos los barcos del oponente antes de que él hunda los tuyos.

El juego incluye algunas funciones adicionales como la colocación de minas (que hacen perder un turno si se activan), la aparición de cajas sorpresa que pueden dar ventajas durante la partida, y un sistema de logros por acciones destacadas. También se lleva un historial de las partidas jugadas, incluso si no se terminan.

Para su desarrollo se utilizaron estructuras básicas de programación como condicionales (if, switch), ciclos (for, do-while), arreglos bidimensionales para representar los tableros, y cadenas de texto para ingresar coordenadas o mostrar mensajes. Todo esto con el objetivo de hacer una experiencia de juego fluida y entretenida entre dos personas.

## Equipo

- **Nombre del equipo:** [Ciclo while sin break]

### Integrantes del equipo

1. **Nombre completo:** [Andrés Eleazar Hernández García]  
   **Carnet:** [00062625]

2. **Nombre completo:** [Gerardo Enrique Blanco Beltran]  
   **Carnet:** [00208424]

3. **Nombre completo:** [Magaly Brendali Aguilar Granillo]  
   **Carnet:** [00209425]

4. **Nombre completo:** [Gabriela Nicole Hernández Diaz]  
   **Carnet:** [00217225]


   ## Documentacion
   ### Flujogramas
   https://drive.google.com/file/d/1NtFZZK9xpot_sQOpZgHA2dQNeXewBq2-/view?usp=drive_link
   •	Nota: Al abrir el enlace, se recomienda seleccionar la opción "Abrir con draw.io" para una visualización correcta,
    ya que los flujogramas están organizados en diferentes páginas dentro del mismo archivo.
   
   ### documento PDF
   
   [Proyecto final - ciclo while sin break.pdf](https://github.com/user-attachments/files/21115418/Proyecto.final.-.ciclo.while.sin.break.pdf)


## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [https://github.com/FDP-01-2025/project-ciclo-while-sin-break.git]
   Abre la terminal
2. Navega a la carpeta del proyecto
Usa el comando cd para entrar a la carpeta donde está main.cpp y la carpeta
src/.
3. Ejecuta el comando de compilación
g++ main.cpp src/*.cpp -o battleship.exe -lwinmm
o main.cpp: archivo principal.
o src/*.cpp: todos los archivos .cpp dentro de src/.
o -o battleship.exe: define el nombre del ejecutable.
o -lwinmm: enlaza la librería winmm (útil si usas funciones de multimedia
como sonido).
4. Verifica que se generó battleship.exe
Revisa que aparezca el archivo en la carpeta.
5. Ejecuta el juego
battleship.exe
