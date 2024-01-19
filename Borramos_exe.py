"""
Este escript borra todos los archivos de extencion .exe
"""

import os

def eliminar_archivos_exe_en_carpeta(ruta):
    try:
        for directorio_actual, subdirectorios, archivos in os.walk(ruta):
            for archivo in archivos:
                if archivo.endswith(".exe"):
                    ruta_completa = os.path.join(directorio_actual, archivo)
                    os.remove(ruta_completa)
                    print(f"Archivo eliminado: {ruta_completa}")

    except Exception as e:
        print(f"Error al eliminar archivos: {e}")

if __name__ == "__main__":

    # Reemplaza esto con la ruta de tu carpeta
    carpeta_a_limpiar = "D:\Progrmacion"  

    eliminar_archivos_exe_en_carpeta(carpeta_a_limpiar)
