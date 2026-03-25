# escape

Escape este un proiect C++ construit cu CMake, gandit ca baza pentru un motor de joc modern si usor de extins.
Aplicatia foloseste SDL3 pentru fereastra si randare, iar arhitectura interna se bazeaza pe un ECS simplu pentru gestionarea entitatilor si componentelor.
In acest moment proiectul include o demonstratie grafica de baza: un dreptunghi afisat in fereastra care poate fi mutat pe ecran cu tastele WASD.

## Build

```sh
cmake -S . -B build
cmake --build build
```

## Run

```sh
./build/escape
```
