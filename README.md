# Stack and Queue System in C

This project implements a console-based system in C for managing two data structures: a **stack** and a **queue**, each with unique behaviors and interactions. It includes functionality for simulating patient service queues and performing operations based on values pushed onto a stack.

## Features

### Stack Module
- Push integers to the stack (up to 10 values at a time).
- Perform operations depending on parity:
  - Sum if both values are even.
  - Subtraction if both values are odd.
  - Multiplication if values are mixed.
- Show the top of the stack and its contents.
- Count of each operation performed.

### Queue Module (Patient Management)
- Add patients to a queue.
- Track position in the queue and estimated wait time.
- Attend a patient (FIFO logic).
- View current front and rear positions.

## How to Compile and Run

Use a C compiler such as `gcc`:

```bash
gcc -o stack_queue_app Proyecto.cpp
./stack_queue_app
```

Replace `Proyecto.cpp` with your actual filename if different.

## Example Menu

```
1. Pantalla de Presentacion
2. Pila
3. Cola
4. Salir del programa
```

## Technologies

- Language: C
- Compiler: Any standard C compiler
- Platform: Console-based application

## File Structure

```
stack-queue-system-c/
├── Proyecto.cpp      # Source code
├── README.md         # Project documentation
```

## Author

This repository was developed by **Julio Lara**, from the **Licenciatura en Ingeniería de Sistemas y Computación** career at the **Universidad Tecnológica de Panamá (UTP)**.

---

> **Note**: This project was originally developed in Spanish. The README is written in English for documentation and sharing purposes.
