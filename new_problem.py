#!/usr/bin/env python3
"""
Script para crear automáticamente archivos de problemas de programación competitiva
con la plantilla correcta, archivos de entrada/salida y en la ubicación adecuada.
"""

import os
import sys
import re
from datetime import datetime

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
    print(f"\n{Colors.BOLD}{Colors.CYAN}{'='*60}")
    print("   📝 COMPETITIVE PROGRAMMING - PROBLEM SETUP")
    print(f"{'='*60}{Colors.END}\n")

def get_platform():
    """Obtiene la plataforma del problema"""
    platforms = {
        '1': 'codeforces',
        '2': 'cses',
        '3': 'leetcode',
        '4': 'atcoder',
        '5': 'codechef',
        '6': 'other'
    }

    print(f"{Colors.BLUE}🎯 Selecciona la plataforma:{Colors.END}")
    for key, value in platforms.items():
        print(f"   {key}. {value.capitalize()}")

    while True:
        choice = input(f"\n{Colors.CYAN}Plataforma (1-6): {Colors.END}").strip()
        if choice in platforms:
            return platforms[choice]
        print(f"{Colors.WARNING}⚠️  Opción inválida. Por favor elige del 1 al 6.{Colors.END}")

def get_problem_type(platform):
    """Determina si es contest o practice (solo para codeforces)"""
    if platform != 'codeforces':
        return None

    print(f"\n{Colors.BLUE}📂 Tipo de problema:{Colors.END}")
    print("   1. Practice")
    print("   2. Contest")

    while True:
        choice = input(f"\n{Colors.CYAN}Tipo (1-2): {Colors.END}").strip()
        if choice == '1':
            return 'practice'
        elif choice == '2':
            return 'contest'
        print(f"{Colors.WARNING}⚠️  Opción inválida. Por favor elige 1 o 2.{Colors.END}")

def get_contest_info():
    """Obtiene información del contest"""
    print(f"\n{Colors.BLUE}🏆 Información del Contest:{Colors.END}")
    contest_name = input(f"{Colors.CYAN}Nombre del contest (ej: Educational Round 173): {Colors.END}").strip()
    division = input(f"{Colors.CYAN}División (ej: div2, div1): {Colors.END}").strip().lower()

    # Crear nombre de carpeta normalizado
    folder_name = contest_name.lower().replace(' ', '-').replace('(', '').replace(')', '')
    if division:
        folder_name += f"-{division}"

    return folder_name, contest_name

def get_problem_info():
    """Obtiene información del problema"""
    print(f"\n{Colors.BLUE}📋 Información del Problema:{Colors.END}")

    problem_id = input(f"{Colors.CYAN}ID/Número del problema (ej: 1598A, 1234, A): {Colors.END}").strip()
    problem_name = input(f"{Colors.CYAN}Nombre del problema (ej: Computer Game): {Colors.END}").strip()
    problem_url = input(f"{Colors.CYAN}URL del problema (opcional): {Colors.END}").strip()

    # Normalizar el nombre del archivo
    if problem_id and problem_id[0].isdigit():
        # Si empieza con número (ej: 1598A)
        filename = f"{problem_id}-{problem_name.replace(' ', '-')}.cpp"
    else:
        # Si es letra (ej: A, B, C)
        filename = f"{problem_id}-{problem_name.replace(' ', '-')}.cpp"

    # Eliminar caracteres especiales del nombre del archivo
    filename = re.sub(r'[^\w\-.]', '', filename)

    return problem_id, problem_name, problem_url, filename

def get_template_choice():
    """Permite al usuario elegir la plantilla"""
    templates_dir = os.path.join(BASE_DIR, "templates")

    if not os.path.exists(templates_dir):
        return None

    templates = [f for f in os.listdir(templates_dir) if f.endswith('.cpp')]

    if not templates:
        return None

    if len(templates) == 1:
        return os.path.join(templates_dir, templates[0])

    print(f"\n{Colors.BLUE}📄 Selecciona una plantilla:{Colors.END}")
    for i, template in enumerate(templates, 1):
        print(f"   {i}. {template}")

    while True:
        choice = input(f"\n{Colors.CYAN}Plantilla (número): {Colors.END}").strip()
        try:
            idx = int(choice) - 1
            if 0 <= idx < len(templates):
                return os.path.join(templates_dir, templates[idx])
        except ValueError:
            pass
        print(f"{Colors.WARNING}⚠️  Opción inválida.{Colors.END}")

def create_io_files(directory):
    """Crea archivos input.txt y output.txt en el directorio especificado"""
    input_file = os.path.join(directory, "input.txt")
    output_file = os.path.join(directory, "output.txt")

    # Crear input.txt si no existe
    if not os.path.exists(input_file):
        with open(input_file, 'w') as f:
            f.write("")  # Archivo vacío para entrada
        print(f"{Colors.GREEN}✅ Creado: {input_file}{Colors.END}")

    # Crear output.txt si no existe
    if not os.path.exists(output_file):
        with open(output_file, 'w') as f:
            f.write("")  # Archivo vacío para salida
        print(f"{Colors.GREEN}✅ Creado: {output_file}{Colors.END}")

    return input_file, output_file

def create_problem_file(platform, problem_type, contest_folder, problem_info, template_path):
    """Crea el archivo del problema con la plantilla"""
    problem_id, problem_name, problem_url, filename = problem_info

    # Determinar la ruta del archivo
    if platform == 'codeforces':
        if problem_type == 'contest':
            base_path = os.path.join(BASE_DIR, f"codeforces/contests/{contest_folder}")
        else:
            base_path = os.path.join(BASE_DIR, "codeforces/practice")
    elif platform == 'cses':
        base_path = os.path.join(BASE_DIR, "cses")
    elif platform == 'leetcode':
        base_path = os.path.join(BASE_DIR, "leetcode")
    else:
        base_path = os.path.join(BASE_DIR, platform)

    # Crear directorios si no existen
    os.makedirs(base_path, exist_ok=True)

    filepath = os.path.join(base_path, filename)

    # Verificar si el archivo ya existe
    if os.path.exists(filepath):
        overwrite = input(f"\n{Colors.WARNING}⚠️  El archivo {filename} ya existe. ¿Sobrescribir? (s/n): {Colors.END}").lower()
        if overwrite != 's':
            print(f"{Colors.FAIL}❌ Operación cancelada.{Colors.END}")
            return None, None

    # Leer la plantilla
    if template_path and os.path.exists(template_path):
        with open(template_path, 'r') as f:
            template_content = f.read()
    else:
        # Plantilla por defecto si no hay ninguna
        template_content = get_default_template()

    # Agregar comentarios con información del problema
    header_comments = f"""/*
 * Problem: {problem_name}
 * Platform: {platform.capitalize()}"""

    if problem_id:
        header_comments += f"\n * Problem ID: {problem_id}"

    if problem_url:
        header_comments += f"\n * URL: {problem_url}"

    header_comments += f"\n * Date: {datetime.now().strftime('%Y-%m-%d')}"
    header_comments += f"\n * Compilation: g++ -std=c++17 -O2 {filename} -o programa && ./programa < input.txt > output.txt"
    header_comments += "\n */"

    # Combinar header con plantilla
    final_content = header_comments + "\n\n" + template_content

    # Escribir el archivo
    with open(filepath, 'w') as f:
        f.write(final_content)

    # Crear archivos de entrada/salida
    input_file, output_file = create_io_files(base_path)

    return filepath, base_path

def get_default_template():
    """Retorna una plantilla por defecto si no hay ninguna disponible"""
    return """#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

#define all(v) (v).begin(), (v).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define endl '\\n'

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void solve() {
    // Solution code here

}

int main() {
    fastIO();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}"""

def show_compilation_command(filepath, directory):
    """Muestra el comando de compilación"""
    filename = os.path.basename(filepath)
    print(f"\n{Colors.BLUE}🔧 Comando de compilación:{Colors.END}")
    print(f"{Colors.BOLD}cd {directory}{Colors.END}")
    print(f"{Colors.BOLD}g++ -std=c++17 -O2 {filename} -o programa && ./programa < input.txt > output.txt{Colors.END}")

def update_problems_index(platform, problem_info, contest_name=None):
    """Actualiza el archivo PROBLEMS.md con el nuevo problema"""
    problems_file = os.path.join(BASE_DIR, "docs/PROBLEMS.md")

    if not os.path.exists(problems_file):
        print(f"{Colors.WARNING}⚠️  No se encontró el archivo de índice de problemas.{Colors.END}")
        return

    problem_id, problem_name, problem_url, filename = problem_info

    print(f"\n{Colors.CYAN}💡 Recuerda actualizar docs/PROBLEMS.md con este nuevo problema.{Colors.END}")

def main():
    """Función principal"""
    print_header()

    # Cambiar al directorio del repositorio
    os.chdir(BASE_DIR)

    try:
        # Obtener información del usuario
        platform = get_platform()

        problem_type = None
        contest_folder = None
        contest_name = None

        if platform == 'codeforces':
            problem_type = get_problem_type(platform)
            if problem_type == 'contest':
                contest_folder, contest_name = get_contest_info()

        problem_info = get_problem_info()

        # Seleccionar plantilla
        template_path = get_template_choice()

        # Crear el archivo
        filepath, directory = create_problem_file(
            platform,
            problem_type,
            contest_folder,
            problem_info,
            template_path
        )

        if filepath:
            print(f"\n{Colors.GREEN}✅ ¡Archivos creados exitosamente!{Colors.END}")
            print(f"{Colors.BOLD}📍 Problema: {filepath}{Colors.END}")
            print(f"{Colors.BOLD}📥 Entrada: {os.path.join(directory, 'input.txt')}{Colors.END}")
            print(f"{Colors.BOLD}📤 Salida: {os.path.join(directory, 'output.txt')}{Colors.END}")

            # Mostrar comando de compilación
            show_compilation_command(filepath, directory)

            # Ofrecer abrir el archivo
            if sys.platform == 'darwin':  # macOS
                open_file = input(f"\n{Colors.CYAN}¿Abrir el archivo en VS Code? (s/n): {Colors.END}").lower()
                if open_file == 's':
                    os.system(f"code {filepath}")
                    os.system(f"code {os.path.join(directory, 'input.txt')}")

            # Actualizar el índice de problemas
            update_problems_index(platform, problem_info, contest_name)

            print(f"\n{Colors.GREEN}🎉 ¡Listo para programar! ¡Buena suerte!{Colors.END}\n")

    except KeyboardInterrupt:
        print(f"\n\n{Colors.FAIL}❌ Operación cancelada por el usuario.{Colors.END}")
        sys.exit(0)
    except Exception as e:
        print(f"\n{Colors.FAIL}❌ Error: {str(e)}{Colors.END}")
        sys.exit(1)

if __name__ == "__main__":
    main()