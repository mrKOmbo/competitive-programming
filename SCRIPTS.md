# 🛠️ Scripts de Automatización

Este repositorio incluye scripts para automatizar todo el flujo de trabajo de competitive programming: crear problemas, resolverlos y documentarlos.

## 🚀 Flujo de Trabajo Completo

```bash
# 1. Crear nuevo problema
./np cf 1234 "Problem Name"

# 2. Resolver el problema
# (editar archivo.cpp, probar con input.txt)

# 3. Marcar como completado
./cp archivo.cpp

# 4. Hacer commit
git add -A && git commit -m "Solve: Problem Name"
```

## 📝 Scripts Disponibles

### 1. `new_problem.py` - Script Python Interactivo

Script completo con interfaz interactiva para crear problemas con archivos de I/O.

#### Uso:
```bash
# Modo interactivo (recomendado)
python3 new_problem.py

# O hacer el script ejecutable
chmod +x new_problem.py
./new_problem.py
```

#### Características:
- ✅ Interfaz interactiva con colores
- ✅ Soporte para múltiples plataformas (Codeforces, CSES, LeetCode, etc.)
- ✅ Diferencia entre practice y contests
- ✅ Selección de plantillas
- ✅ Metadata automática (fecha, URL, ID)
- ✅ **Crea automáticamente input.txt y output.txt**
- ✅ **Incluye comando de compilación en el header**
- ✅ Opción para abrir en VS Code
- ✅ Validación de archivos existentes

### 2. `np` - Script Bash Rápido (New Problem)

Script minimalista para crear problemas rápidamente desde la terminal con archivos I/O.

#### Uso:

```bash
# Modo interactivo
./np

# Modo rápido - Codeforces practice
./np cf 1598A "Computer Game"

# Modo rápido - Codeforces contest
./np cf-c A "Greedy Monocarp"

# Modo rápido - CSES
./np cses 1234 "Building Teams"

# Modo rápido - LeetCode
./np lc 1 "Two Sum"

# Ver ayuda
./np -h
```

#### Plataformas soportadas:
- `cf` - Codeforces (practice)
- `cf-c` - Codeforces (contest)
- `cses` - CSES Problem Set
- `lc` - LeetCode

### 3. `complete_problem.py` - Script Python para Completar Problemas

Script completo para marcar un problema como resuelto, limpiar archivos temporales y actualizar la documentación.

#### Uso:
```bash
# Modo interactivo
python3 complete_problem.py

# O ejecutable
./complete_problem.py
```

#### Características:
- ✅ Elimina archivos input.txt, output.txt y ejecutables
- ✅ Actualiza automáticamente docs/PROBLEMS.md
- ✅ Extrae metadata del archivo .cpp
- ✅ Solicita información adicional (dificultad, categorías)
- ✅ Prepara el resumen para el commit
- ✅ Interfaz interactiva para seleccionar archivos

### 4. `cp` - Script Bash Rápido (Complete Problem)

Script minimalista para completar problemas rápidamente.

#### Uso:
```bash
# Modo interactivo
./cp

# Completar archivo específico
./cp archivo.cpp

# Completar último archivo modificado en directorio actual
./cp .

# Ver ayuda
./cp -h
```

#### Características:
- ✅ Limpieza rápida de archivos temporales
- ✅ Actualización de documentación
- ✅ Extracción automática de metadata
- ✅ Preparación para commit

## 📂 Estructura de Archivos Creados

Los scripts crearán archivos con el siguiente formato:

```cpp
/*
 * Problem: [Nombre del Problema]
 * Platform: [Plataforma]
 * Problem ID: [ID]
 * URL: [URL opcional]
 * Date: [Fecha actual]
 * Compilation: g++ -std=c++17 -O2 archivo.cpp -o programa && ./programa < input.txt > output.txt
 */

[Contenido de la plantilla seleccionada]
```

### Archivos creados automáticamente:
1. **archivo.cpp** - El archivo del problema con la plantilla
2. **input.txt** - Archivo vacío para los datos de entrada
3. **output.txt** - Archivo vacío para guardar la salida

### Ubicación de archivos:
- **Codeforces Practice**: `codeforces/practice/`
  - `[ID]-[Nombre].cpp`
  - `input.txt`
  - `output.txt`
- **Codeforces Contest**: `codeforces/contests/[nombre-contest]/`
  - `[ID]-[Nombre].cpp`
  - `input.txt`
  - `output.txt`
- **CSES**: `cses/`
- **LeetCode**: `leetcode/`

## 🎨 Plantillas Disponibles

Los scripts utilizan las plantillas en la carpeta `templates/`:

1. **base.cpp** - Plantilla simple y ligera
2. **template-extended.cpp** - Plantilla completa con más utilidades
3. **1.cpp** - Plantilla personalizada (si existe)

## 🔧 Compilación y Ejecución

Después de crear los archivos, puedes compilar y ejecutar con:

```bash
# Comando incluido en el header del archivo
g++ -std=c++17 -O2 archivo.cpp -o programa && ./programa < input.txt > output.txt

# O manualmente:
cd codeforces/practice
g++ -std=c++17 -O2 1598A-Computer-Game.cpp -o programa
./programa < input.txt > output.txt
```

## 💡 Ejemplos de Uso

### Ejemplo 1: Problema de Codeforces Practice

```bash
./np cf 1932D "Colored Balls"
```

Creará:
- `codeforces/practice/1932D-Colored-Balls.cpp`
- `codeforces/practice/input.txt`
- `codeforces/practice/output.txt`

### Ejemplo 2: Contest de Codeforces

```bash
python3 new_problem.py
# Seleccionar: Codeforces > Contest
# Nombre del contest: Educational Round 173
# División: div2
# ID: A
# Nombre: Problem Name
```

Creará:
- `codeforces/contests/educational-round-173-div2/A-Problem-Name.cpp`
- `codeforces/contests/educational-round-173-div2/input.txt`
- `codeforces/contests/educational-round-173-div2/output.txt`

### Ejemplo 3: Problema de CSES

```bash
./np cses 1668 "Building Teams"
```

Creará:
- `cses/1668-Building-Teams.cpp`
- `cses/input.txt`
- `cses/output.txt`

## 🔧 Configuración Inicial

1. Asegúrate de tener Python 3 instalado:
```bash
python3 --version
```

2. Da permisos de ejecución a los scripts:
```bash
chmod +x new_problem.py np
```

3. (Opcional) Crea un alias para usar desde cualquier lugar:
```bash
# Agregar al ~/.zshrc o ~/.bashrc
alias np="/Users/milo/Files/reps/competitive-programming/np"
alias newp="python3 /Users/milo/Files/reps/competitive-programming/new_problem.py"
```

## 🔄 Flujo de Trabajo Completo - Ejemplo Real

```bash
# 1. Crear un nuevo problema de Codeforces
./np cf 1598A "Computer Game"

# 2. Se crean automáticamente:
#    - codeforces/practice/1598A-Computer-Game.cpp
#    - codeforces/practice/input.txt
#    - codeforces/practice/output.txt

# 3. Abrir en VS Code y resolver
code codeforces/practice/1598A-Computer-Game.cpp
code codeforces/practice/input.txt

# 4. Pegar casos de prueba en input.txt

# 5. Compilar y ejecutar
cd codeforces/practice
g++ -std=c++17 -O2 1598A-Computer-Game.cpp -o programa
./programa < input.txt > output.txt

# 6. Verificar salida
cat output.txt

# 7. Una vez aceptado, marcar como completado
cd ../..
./cp codeforces/practice/1598A-Computer-Game.cpp
# Te preguntará:
#   - Dificultad: 800
#   - Categorías: implementation, dfs
#   - ¿Aceptado?: s

# 8. Los archivos temporales se eliminan y PROBLEMS.md se actualiza

# 9. Hacer commit
git add -A
git commit -m "Solve: Computer Game (1598A)"
git push
```

## ⚡ Tips de Productividad

1. **Usa el modo rápido** del script `np` para problemas simples
2. **Usa el script Python** cuando necesites más opciones o estés en un contest
3. **Personaliza las plantillas** en `templates/` según tus preferencias
4. **Mantén actualizado** el archivo `docs/PROBLEMS.md` después de resolver cada problema
5. **Usa los archivos I/O** para probar con diferentes casos de prueba
6. **Crea aliases** para acceder rápidamente a los scripts desde cualquier lugar
7. **Usa `./cp .`** para completar el último archivo modificado rápidamente

## 🐛 Solución de Problemas

### Error: "bad interpreter"
```bash
# Arreglar saltos de línea
sed -i '' 's/\r$//' np
```

### Error: "Permission denied"
```bash
# Dar permisos de ejecución
chmod +x new_problem.py np
```

### Error: "python3: command not found"
```bash
# Instalar Python 3 (macOS)
brew install python3
```

### Los archivos se crean en lugar incorrecto
Verifica que los scripts tengan la ruta correcta:
```bash
BASE_DIR="/Users/milo/Files/reps/competitive-programming"
```

---

*¡Happy Coding! 🚀*