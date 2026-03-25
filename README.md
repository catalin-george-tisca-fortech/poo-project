# escape

Escape este un proiect C++ construit cu CMake, gandit ca baza pentru un motor de joc modern si usor de extins.
Aplicatia foloseste SDL3 pentru fereastra si randare, iar arhitectura interna se bazeaza pe un ECS simplu pentru gestionarea entitatilor si componentelor.
In acest moment proiectul include o demonstratie grafica de baza: un dreptunghi afisat in fereastra care poate fi mutat pe ecran cu tastele WASD.

## Cerinte OOP

- Sunt definite clasele `Vector2`, `Size2D`, `RenderStyle` si `PlayerRectangle`, iar `PlayerRectangle` foloseste compunere cu celelalte clase.
- Toate aceste clase au constructori cu parametri.
- Clasa `PlayerRectangle` are constructor de copiere, operator de atribuire prin copiere si destructor.
- Exista `operator<<` pentru clasele de model si pentru clasele principale din aplicatie (`WindowConfig`, `Color`, `Rectangle`, `Window`, `GameEngine`).
- Exista functii publice netriviale precum `Vector2::translated`, `Vector2::scaled`, `PlayerRectangle::move_with_direction`, `PlayerRectangle::clamp_to_bounds` si `PlayerRectangle::to_window_rectangle`.
- In `main` exista un scenariu de utilizare care construieste obiecte, afiseaza stari, foloseste ECS-ul si apeleaza functiile publice ale claselor de model definite pentru tema.
- Exemplele de intrare de la tastatura sunt in `tastatura.txt`.
- Exista configurare CI in `.github/workflows/ci.yml`.
- Exista configurare `.gitattributes` pentru a evidentia codul C++.

## Observatii

- Tag-ul local recomandat pentru aceasta etapa este `v0.1`.
- Cerinta de code review pentru alte 2 proiecte ramane o activitate externa fata de codul din acest repository si trebuie facuta separat.

## Build

```sh
cmake -S . -B build
cmake --build build
```

## Run

```sh
./build/escape
```
