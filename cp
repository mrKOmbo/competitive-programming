#!/bin/bash

# Script para marcar un problema como completado
# cp = complete problem
# Uso: ./cp [archivo.cpp]

# Directorio base del repositorio
BASE_DIR="/Users/milo/Files/reps/competitive-programming"

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
NC='\033[0m' # No Color

# Cambiar al directorio del repositorio
cd "$BASE_DIR"

# Función para mostrar ayuda
show_help() {
    echo -e "${BOLD}${GREEN}=== Complete Problem - Cleanup & Documentation ===${NC}\n"
    echo -e "${BOLD}Uso:${NC}"
    echo -e "  ./cp                    ${BLUE}# Modo interactivo${NC}"
    echo -e "  ./cp archivo.cpp        ${BLUE}# Completar archivo específico${NC}"
    echo -e "  ./cp .                  ${BLUE}# Completar último .cpp modificado en directorio actual${NC}\n"
    echo -e "${BOLD}Acciones:${NC}"
    echo -e "  - Elimina input.txt, output.txt y ejecutables"
    echo -e "  - Actualiza docs/PROBLEMS.md"
    echo -e "  - Prepara para commit"
    exit 0
}

# Función para extraer metadata del archivo
extract_metadata() {
    local file=$1
    local metadata=""

    # Extraer información del header del archivo
    problem=$(grep "Problem:" "$file" 2>/dev/null | sed 's/.*Problem: //' | sed 's/\*//' | sed 's/^[[:space:]]*//' | sed 's/[[:space:]]*$//')
    platform=$(grep "Platform:" "$file" 2>/dev/null | sed 's/.*Platform: //' | sed 's/\*//' | sed 's/^[[:space:]]*//' | sed 's/[[:space:]]*$//')
    problem_id=$(grep "Problem ID:" "$file" 2>/dev/null | sed 's/.*Problem ID: //' | sed 's/\*//' | sed 's/^[[:space:]]*//' | sed 's/[[:space:]]*$//')
    url=$(grep "URL:" "$file" 2>/dev/null | sed 's/.*URL: //' | sed 's/\*//' | sed 's/^[[:space:]]*//' | sed 's/[[:space:]]*$//')

    echo "$problem|$platform|$problem_id|$url"
}

# Función para limpiar archivos I/O
clean_files() {
    local dir=$1
    local removed=0

    # Eliminar archivos I/O
    if [ -f "$dir/input.txt" ]; then
        rm "$dir/input.txt"
        echo -e "  ${GREEN}✓${NC} Eliminado: input.txt"
        ((removed++))
    fi

    if [ -f "$dir/output.txt" ]; then
        rm "$dir/output.txt"
        echo -e "  ${GREEN}✓${NC} Eliminado: output.txt"
        ((removed++))
    fi

    # Eliminar ejecutables
    if [ -f "$dir/programa" ]; then
        rm "$dir/programa"
        echo -e "  ${GREEN}✓${NC} Eliminado: programa"
        ((removed++))
    fi

    # Eliminar archivos .out, .exe, .o
    for file in "$dir"/*.out "$dir"/*.exe "$dir"/*.o; do
        if [ -f "$file" ]; then
            rm "$file"
            echo -e "  ${GREEN}✓${NC} Eliminado: $(basename $file)"
            ((removed++))
        fi
    done

    return $removed
}

# Función mejorada para actualizar PROBLEMS.md
update_documentation() {
    local filepath=$1
    local metadata=$2
    local difficulty=$3
    local category=$4
    local status=$5

    # Separar metadata
    IFS='|' read -r problem platform problem_id url <<< "$metadata"

    # Archivo de problemas
    local problems_file="$BASE_DIR/docs/PROBLEMS.md"

    # Crear archivo si no existe con estructura completa
    if [ ! -f "$problems_file" ]; then
        mkdir -p "$BASE_DIR/docs"
        cat > "$problems_file" << 'EOF'
# Problem Index

Lista completa de problemas resueltos organizados por plataforma.

## Codeforces

### Contests

#### Educational Codeforces Round 172 (Div. 2)
| Problema | Archivo | Estado |
|----------|---------|--------|
| A. Greedy Monocarp | [A-Greedy-Monocarp.cpp](../codeforces/contests/educational-round-172-div2/A-Greedy-Monocarp.cpp) | ✅ |
| B. Game with Colored Marbles | [B-Game-with-Colored-Marbles.cpp](../codeforces/contests/educational-round-172-div2/B-Game-with-Colored-Marbles.cpp) | ✅ |

### Practice Problems
| ID | Problema | Archivo | Dificultad | Categoría | Estado |
|----:|----------|---------|------------|-----------|--------|

## CSES Problem Set
| ID | Problema | Archivo | Dificultad | Categoría | Estado |
|----:|----------|---------|------------|-----------|--------|

## LeetCode
| ID | Problema | Archivo | Dificultad | Categoría | Estado |
|----:|----------|---------|------------|-----------|--------|

---

*Última actualización: Diciembre 2024*
EOF
    fi

    # Crear la entrada
    local filename=$(basename "$filepath")
    local relpath=$(echo "$filepath" | sed "s|$BASE_DIR/||")

    # Formatear entrada según tenga URL o no
    local entry=""
    if [ ! -z "$url" ] && [ "$url" != " " ]; then
        entry="| $problem_id | [$problem]($url) | [$filename](../$relpath) | $difficulty | $category | $status |"
    else
        entry="| $problem_id | $problem | [$filename](../$relpath) | $difficulty | $category | $status |"
    fi

    # Verificar si ya existe
    if grep -q "$filename" "$problems_file" 2>/dev/null; then
        echo -e "  ${YELLOW}⚠${NC} El problema ya está en PROBLEMS.md"
        return 1
    fi

    # Determinar en qué sección insertar
    local section=""
    local platform_lower=$(echo "$platform" | tr '[:upper:]' '[:lower:]')

    if [[ "$filepath" == *"codeforces/contests"* ]]; then
        section="### Contests"
    elif [[ "$platform_lower" == *"codeforces"* ]] || [[ "$platform_lower" == "cf" ]]; then
        section="### Practice Problems"
    elif [[ "$platform_lower" == *"cses"* ]]; then
        section="## CSES Problem Set"
    elif [[ "$platform_lower" == *"leetcode"* ]] || [[ "$platform_lower" == "lc" ]]; then
        section="## LeetCode"
    else
        section="### Practice Problems"
    fi

    # Usar Python para insertar en el lugar correcto
    python3 << EOF
import re

with open("$problems_file", 'r') as f:
    lines = f.readlines()

# Buscar la sección correcta
inserted = False
for i in range(len(lines)):
    if "$section" in lines[i]:
        # Buscar el encabezado de la tabla (línea con |---|)
        for j in range(i+1, min(i+10, len(lines))):
            if '|----' in lines[j] or '|---' in lines[j]:
                # Insertar después del encabezado
                # Buscar dónde insertar (antes de una línea vacía o al final de la tabla)
                insert_pos = j + 1
                while insert_pos < len(lines):
                    if lines[insert_pos].strip() == '' or not lines[insert_pos].startswith('|'):
                        break
                    insert_pos += 1
                lines.insert(insert_pos, "$entry\n")
                inserted = True
                break
        break

if not inserted:
    # Si no encontramos la sección, agregar al final antes de la línea de actualización
    for i in range(len(lines)-1, -1, -1):
        if '---' in lines[i]:
            lines.insert(i, "$entry\n")
            break

# Actualizar fecha
content = ''.join(lines)
import datetime
month_year = datetime.datetime.now().strftime("%B %Y")
content = re.sub(r'\*Última actualización:.*\*', f'*Última actualización: {month_year}*', content)

with open("$problems_file", 'w') as f:
    f.write(content)

print("✅ Actualizado correctamente")
EOF

    if [ $? -eq 0 ]; then
        echo -e "  ${GREEN}✓${NC} Actualizado: docs/PROBLEMS.md"
        return 0
    else
        echo -e "  ${RED}✗${NC} Error actualizando PROBLEMS.md"
        return 1
    fi
}

# Función principal para completar problema
complete_problem() {
    local filepath=$1

    if [ ! -f "$filepath" ]; then
        echo -e "${RED}❌ Error: No se encontró el archivo $filepath${NC}"
        return 1
    fi

    echo -e "\n${BOLD}${GREEN}📋 Completando problema...${NC}"
    echo -e "${CYAN}Archivo: $(basename $filepath)${NC}\n"

    # Extraer metadata
    metadata=$(extract_metadata "$filepath")
    IFS='|' read -r problem platform problem_id url <<< "$metadata"

    if [ ! -z "$problem" ]; then
        echo -e "${BOLD}Problema:${NC} $problem"
        echo -e "${BOLD}Plataforma:${NC} $platform"
        echo -e "${BOLD}ID:${NC} $problem_id"
    fi

    # Solicitar información adicional
    echo -e "\n${CYAN}Información adicional (opcional):${NC}"

    echo -n "Dificultad: "
    read difficulty

    echo -n "Categorías/Tags (ej: dp, graphs): "
    read category

    echo -n "¿Solución aceptada? (s/n): "
    read accepted
    if [ "$accepted" == "s" ]; then
        status="✅"
    else
        status="⚠️"
    fi

    # Limpiar archivos
    echo -e "\n${BLUE}🧹 Limpiando archivos...${NC}"
    directory=$(dirname "$filepath")
    clean_files "$directory"

    # Actualizar documentación
    echo -e "\n${BLUE}📚 Actualizando documentación...${NC}"
    update_documentation "$filepath" "$metadata" "$difficulty" "$category" "$status"

    # Resumen
    echo -e "\n${GREEN}═══════════════════════════════════════════${NC}"
    echo -e "${BOLD}${GREEN}✅ ¡PROBLEMA COMPLETADO!${NC}"
    echo -e "${GREEN}═══════════════════════════════════════════${NC}\n"

    echo -e "${CYAN}Próximos pasos:${NC}"
    echo -e "  1. ${BOLD}git add -A && git commit -m \"Solve: $problem\"${NC}"
    echo -e "  2. ${BOLD}./np${NC} para crear un nuevo problema\n"

    echo -e "${GREEN}🎉 ¡Felicitaciones!${NC}\n"
}

# Modo interactivo
interactive_mode() {
    echo -e "${BOLD}${GREEN}=== Complete Problem ===${NC}\n"

    # Seleccionar ubicación
    echo -e "${BLUE}¿Dónde está el problema?${NC}"
    echo "  1. Codeforces Practice"
    echo "  2. Codeforces Contest"
    echo "  3. CSES"
    echo "  4. LeetCode"
    echo "  5. Directorio actual"
    echo -n "Opción: "
    read choice

    case $choice in
        1) dir="$BASE_DIR/codeforces/practice" ;;
        2)
            echo -n "Nombre del contest: "
            read contest
            dir="$BASE_DIR/codeforces/contests/$contest"
            ;;
        3) dir="$BASE_DIR/cses" ;;
        4) dir="$BASE_DIR/leetcode" ;;
        5) dir="." ;;
        *) echo -e "${RED}❌ Opción inválida${NC}"; exit 1 ;;
    esac

    # Listar archivos .cpp
    echo -e "\n${BLUE}Archivos disponibles:${NC}"
    files=($(find "$dir" -maxdepth 1 -name "*.cpp" -not -name "base*" -not -name "template*" 2>/dev/null | sort))

    if [ ${#files[@]} -eq 0 ]; then
        echo -e "${RED}❌ No se encontraron archivos .cpp${NC}"
        exit 1
    fi

    for i in "${!files[@]}"; do
        echo "  $((i+1)). $(basename ${files[$i]})"
    done

    echo -n "Selecciona el archivo: "
    read file_choice

    if [ $file_choice -gt 0 ] && [ $file_choice -le ${#files[@]} ]; then
        complete_problem "${files[$((file_choice-1))]}"
    else
        echo -e "${RED}❌ Selección inválida${NC}"
        exit 1
    fi
}

# Main
if [ $# -eq 0 ]; then
    interactive_mode
elif [ "$1" == "-h" ] || [ "$1" == "--help" ]; then
    show_help
elif [ "$1" == "." ]; then
    # Completar el último archivo modificado en el directorio actual
    latest=$(ls -t *.cpp 2>/dev/null | grep -v "base\|template" | head -1)
    if [ ! -z "$latest" ]; then
        complete_problem "$latest"
    else
        echo -e "${RED}❌ No se encontraron archivos .cpp en el directorio actual${NC}"
        exit 1
    fi
else
    # Completar archivo específico
    complete_problem "$1"
fi