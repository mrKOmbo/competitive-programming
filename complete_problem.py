#!/usr/bin/env python3
"""
Script para marcar un problema como completado:
- Elimina archivos input.txt y output.txt
- Actualiza docs/PROBLEMS.md con el nuevo problema resuelto
"""

import os
import sys
import re
from datetime import datetime
from pathlib import Path

# Ruta base del repositorio
BASE_DIR = "/Users/milo/Files/reps/competitive-programming"

# Colores para la terminal
class Colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    END = '\033[0m'
    BOLD = '\033[1m'

def print_header():
    """Imprime el header del script"""
    print(f"\n{Colors.BOLD}{Colors.GREEN}{'='*60}")
    print("   ✅ PROBLEM COMPLETED - CLEANUP & DOCUMENTATION")
    print(f"{'='*60}{Colors.END}\n")

def find_cpp_files(directory):
    """Encuentra archivos .cpp en el directorio especificado"""
    cpp_files = []
    try:
        for file in os.listdir(directory):
            if file.endswith('.cpp') and not file.startswith('base') and not file.startswith('template'):
                cpp_files.append(file)
        return sorted(cpp_files)
    except:
        return []

def select_problem_file():
    """Permite al usuario seleccionar el archivo del problema completado"""
    print(f"{Colors.BLUE}📂 ¿Dónde está el problema que completaste?{Colors.END}")
    print("   1. Codeforces Practice")
    print("   2. Codeforces Contest")
    print("   3. CSES")
    print("   4. LeetCode")
    print("   5. Buscar en todo el repositorio")

    choice = input(f"\n{Colors.CYAN}Opción (1-5): {Colors.END}").strip()

    directory = None
    if choice == '1':
        directory = os.path.join(BASE_DIR, "codeforces/practice")
    elif choice == '2':
        # Listar contests disponibles
        contests_dir = os.path.join(BASE_DIR, "codeforces/contests")
        if os.path.exists(contests_dir):
            contests = [d for d in os.listdir(contests_dir) if os.path.isdir(os.path.join(contests_dir, d))]
            if contests:
                print(f"\n{Colors.BLUE}Selecciona el contest:{Colors.END}")
                for i, contest in enumerate(contests, 1):
                    print(f"   {i}. {contest}")
                contest_choice = int(input(f"{Colors.CYAN}Contest: {Colors.END}").strip()) - 1
                if 0 <= contest_choice < len(contests):
                    directory = os.path.join(contests_dir, contests[contest_choice])
    elif choice == '3':
        directory = os.path.join(BASE_DIR, "cses")
    elif choice == '4':
        directory = os.path.join(BASE_DIR, "leetcode")
    elif choice == '5':
        # Buscar en todo el repositorio
        all_cpp = []
        for root, dirs, files in os.walk(BASE_DIR):
            # Excluir directorios no deseados
            if 'templates' in root or '.git' in root or 'utils' in root:
                continue
            for file in files:
                if file.endswith('.cpp') and not file.startswith('base') and not file.startswith('template'):
                    all_cpp.append(os.path.join(root, file))

        if all_cpp:
            print(f"\n{Colors.BLUE}Archivos .cpp encontrados:{Colors.END}")
            for i, file in enumerate(all_cpp[-20:], 1):  # Mostrar últimos 20
                print(f"   {i}. {os.path.relpath(file, BASE_DIR)}")
            file_choice = int(input(f"{Colors.CYAN}Archivo: {Colors.END}").strip()) - 1
            if 0 <= file_choice < len(all_cpp):
                return all_cpp[file_choice]

    # Si tenemos un directorio, listar archivos
    if directory and os.path.exists(directory):
        cpp_files = find_cpp_files(directory)
        if cpp_files:
            print(f"\n{Colors.BLUE}Archivos disponibles:{Colors.END}")
            for i, file in enumerate(cpp_files, 1):
                print(f"   {i}. {file}")

            file_choice = int(input(f"{Colors.CYAN}Archivo: {Colors.END}").strip()) - 1
            if 0 <= file_choice < len(cpp_files):
                return os.path.join(directory, cpp_files[file_choice])

    # Opción manual
    print(f"\n{Colors.CYAN}Ingresa la ruta completa del archivo .cpp:{Colors.END}")
    filepath = input().strip()
    if os.path.exists(filepath):
        return filepath

    return None

def extract_metadata(filepath):
    """Extrae metadata del archivo .cpp"""
    metadata = {
        'problem': 'Unknown',
        'platform': 'Unknown',
        'problem_id': '',
        'url': '',
        'date_created': '',
        'difficulty': '',
        'category': '',
        'filename': os.path.basename(filepath)
    }

    try:
        with open(filepath, 'r') as f:
            content = f.read(1000)  # Leer primeros 1000 caracteres

            # Buscar metadata en comentarios
            if match := re.search(r'\* Problem: (.+)', content):
                metadata['problem'] = match.group(1).strip()

            if match := re.search(r'\* Platform: (.+)', content):
                metadata['platform'] = match.group(1).strip()

            if match := re.search(r'\* Problem ID: (.+)', content):
                metadata['problem_id'] = match.group(1).strip()

            if match := re.search(r'\* URL: (.+)', content):
                metadata['url'] = match.group(1).strip()

            if match := re.search(r'\* Date: (.+)', content):
                metadata['date_created'] = match.group(1).strip()
    except:
        pass

    # Determinar ruta relativa para el enlace
    rel_path = os.path.relpath(filepath, BASE_DIR)
    metadata['filepath'] = rel_path

    return metadata

def get_additional_info(metadata):
    """Solicita información adicional sobre el problema"""
    print(f"\n{Colors.BLUE}📝 Información adicional (opcional):{Colors.END}")

    # Dificultad
    if metadata['platform'].lower() == 'codeforces':
        print(f"{Colors.CYAN}Dificultad (800-3500): {Colors.END}", end='')
    elif metadata['platform'].lower() == 'leetcode':
        print(f"{Colors.CYAN}Dificultad (Easy/Medium/Hard): {Colors.END}", end='')
    else:
        print(f"{Colors.CYAN}Dificultad: {Colors.END}", end='')

    difficulty = input().strip()
    if difficulty:
        metadata['difficulty'] = difficulty

    # Categoría/Tags
    print(f"{Colors.CYAN}Categorías/Tags (ej: dp, graphs, greedy): {Colors.END}", end='')
    category = input().strip()
    if category:
        metadata['category'] = category

    # Estado
    print(f"{Colors.CYAN}¿Solución aceptada? (s/n): {Colors.END}", end='')
    accepted = input().strip().lower()
    metadata['status'] = '✅' if accepted == 's' else '⚠️'

    return metadata

def clean_io_files(directory):
    """Elimina archivos input.txt y output.txt"""
    removed = []

    input_file = os.path.join(directory, "input.txt")
    output_file = os.path.join(directory, "output.txt")

    if os.path.exists(input_file):
        os.remove(input_file)
        removed.append("input.txt")

    if os.path.exists(output_file):
        os.remove(output_file)
        removed.append("output.txt")

    # También eliminar el ejecutable si existe
    if os.path.exists(os.path.join(directory, "programa")):
        os.remove(os.path.join(directory, "programa"))
        removed.append("programa")

    # Buscar y eliminar archivos .out y .exe
    for file in os.listdir(directory):
        if file.endswith(('.out', '.exe', '.o')):
            os.remove(os.path.join(directory, file))
            removed.append(file)

    return removed

def update_problems_md(metadata):
    """Actualiza el archivo PROBLEMS.md"""
    problems_file = os.path.join(BASE_DIR, "docs/PROBLEMS.md")

    # Si no existe, crear el archivo
    if not os.path.exists(problems_file):
        os.makedirs(os.path.dirname(problems_file), exist_ok=True)
        with open(problems_file, 'w') as f:
            f.write("# Problem Index\n\n")
            f.write("Lista completa de problemas resueltos organizados por plataforma.\n\n")

    # Leer el contenido actual
    with open(problems_file, 'r') as f:
        content = f.read()

    # Preparar la nueva entrada
    platform = metadata['platform'].lower()

    # Determinar la sección correcta
    if platform == 'codeforces':
        if 'contest' in metadata['filepath'].lower():
            section = "### Contests"
        else:
            section = "### Practice Problems"
    elif platform == 'cses':
        section = "## CSES Problem Set"
    elif platform == 'leetcode':
        section = "## LeetCode"
    else:
        section = f"## {metadata['platform']}"

    # Crear la entrada de la tabla
    if metadata['url']:
        problem_link = f"[{metadata['problem']}]({metadata['url']})"
    else:
        problem_link = metadata['problem']

    file_link = f"[{metadata['filename']}](../{metadata['filepath']})"

    new_entry = f"| {metadata['problem_id']} | {problem_link} | {file_link} | {metadata['difficulty']} | {metadata['category']} | {metadata['status']} |"

    # Verificar si ya existe esta entrada
    if metadata['filename'] in content:
        print(f"{Colors.WARNING}⚠️  Este problema ya está en PROBLEMS.md{Colors.END}")
        return False

    # Buscar la sección correcta y agregar la entrada
    lines = content.split('\n')
    updated = False

    for i, line in enumerate(lines):
        if section in line:
            # Buscar la tabla después de esta sección
            for j in range(i+1, min(i+20, len(lines))):
                if '|' in lines[j] and '---' in lines[j]:
                    # Encontramos el separador de la tabla
                    # Insertar después de la siguiente línea con contenido
                    for k in range(j+1, len(lines)):
                        if lines[k].strip() == '' or (k+1 < len(lines) and not lines[k+1].startswith('|')):
                            # Insertar aquí
                            lines.insert(k, new_entry)
                            updated = True
                            break
                    break
            break

    if not updated:
        # Si no encontramos la sección, agregarla al final
        if platform == 'codeforces':
            lines.append("\n## Codeforces\n")
            if 'contest' in metadata['filepath'].lower():
                lines.append("### Contests\n")
            else:
                lines.append("### Practice Problems\n")
            lines.append("| ID | Problema | Archivo | Dificultad | Categoría | Estado |")
            lines.append("|----:|----------|---------|------------|-----------|--------|")
            lines.append(new_entry)
        elif platform == 'cses':
            lines.append("\n## CSES Problem Set\n")
            lines.append("| ID | Problema | Archivo | Dificultad | Categoría | Estado |")
            lines.append("|----:|----------|---------|------------|-----------|--------|")
            lines.append(new_entry)
        elif platform == 'leetcode':
            lines.append("\n## LeetCode\n")
            lines.append("| ID | Problema | Archivo | Dificultad | Categoría | Estado |")
            lines.append("|----:|----------|---------|------------|-----------|--------|")
            lines.append(new_entry)

    # Escribir el archivo actualizado
    with open(problems_file, 'w') as f:
        f.write('\n'.join(lines))

    # Actualizar fecha de última actualización
    content = '\n'.join(lines)
    if '---' in content and 'Última actualización:' in content:
        content = re.sub(
            r'\*Última actualización:.*\*',
            f'*Última actualización: {datetime.now().strftime("%B %Y")}*',
            content
        )
    else:
        content += f"\n\n---\n\n*Última actualización: {datetime.now().strftime('%B %Y')}*"

    with open(problems_file, 'w') as f:
        f.write(content)

    return True

def show_summary(metadata, removed_files, doc_updated):
    """Muestra un resumen de las acciones realizadas"""
    print(f"\n{Colors.GREEN}{'='*60}{Colors.END}")
    print(f"{Colors.BOLD}{Colors.GREEN}✅ PROBLEMA COMPLETADO{Colors.END}")
    print(f"{Colors.GREEN}{'='*60}{Colors.END}\n")

    print(f"{Colors.BOLD}📋 Problema:{Colors.END} {metadata['problem']}")
    if metadata['problem_id']:
        print(f"{Colors.BOLD}🔢 ID:{Colors.END} {metadata['problem_id']}")
    print(f"{Colors.BOLD}🎯 Plataforma:{Colors.END} {metadata['platform']}")
    if metadata['difficulty']:
        print(f"{Colors.BOLD}📊 Dificultad:{Colors.END} {metadata['difficulty']}")
    if metadata['category']:
        print(f"{Colors.BOLD}🏷️ Categorías:{Colors.END} {metadata['category']}")

    if removed_files:
        print(f"\n{Colors.BLUE}🧹 Archivos eliminados:{Colors.END}")
        for file in removed_files:
            print(f"   - {file}")

    if doc_updated:
        print(f"\n{Colors.GREEN}📚 Documentación actualizada:{Colors.END}")
        print(f"   ✅ docs/PROBLEMS.md actualizado con el nuevo problema")

    print(f"\n{Colors.CYAN}💡 Próximos pasos:{Colors.END}")
    print(f"   1. Hacer commit de los cambios: git add -A && git commit -m 'Solve: {metadata['problem']}'")
    print(f"   2. Crear un nuevo problema: ./np")
    print(f"\n{Colors.GREEN}🎉 ¡Felicitaciones por resolver el problema!{Colors.END}\n")

def main():
    """Función principal"""
    print_header()

    try:
        # Seleccionar archivo del problema
        filepath = select_problem_file()

        if not filepath:
            print(f"{Colors.FAIL}❌ No se pudo encontrar el archivo del problema.{Colors.END}")
            sys.exit(1)

        print(f"\n{Colors.GREEN}✅ Archivo seleccionado: {os.path.relpath(filepath, BASE_DIR)}{Colors.END}")

        # Extraer metadata
        metadata = extract_metadata(filepath)

        # Solicitar información adicional
        metadata = get_additional_info(metadata)

        # Limpiar archivos I/O
        directory = os.path.dirname(filepath)
        removed_files = clean_io_files(directory)

        # Actualizar documentación
        doc_updated = update_problems_md(metadata)

        # Mostrar resumen
        show_summary(metadata, removed_files, doc_updated)

    except KeyboardInterrupt:
        print(f"\n\n{Colors.FAIL}❌ Operación cancelada por el usuario.{Colors.END}")
        sys.exit(0)
    except Exception as e:
        print(f"\n{Colors.FAIL}❌ Error: {str(e)}{Colors.END}")
        import traceback
        traceback.print_exc()
        sys.exit(1)

if __name__ == "__main__":
    main()