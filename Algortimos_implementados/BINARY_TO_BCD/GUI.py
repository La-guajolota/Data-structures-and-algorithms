import tkinter as tk
import ctypes

# Cargar la biblioteca compartida (DLL en Windows)
lib_bin = ctypes.CDLL("D:/Progrmacion/Algortimos_implementados/BINARY_TO_BCD/binary_utils.dll")

# Definir los tipos de datos de entrada y salida de las funciones importadas
lib_bin.BINARY_TO_BCD.argtypes = [ctypes.c_uint16, ctypes.POINTER(ctypes.c_uint8)]
lib_bin.BINARY_TO_BCD.restype = None

lib_bin.BCD_TO_SEVEN_SEGMENT.argtypes = [ctypes.c_uint8]
lib_bin.BCD_TO_SEVEN_SEGMENT.restype = ctypes.c_uint8

# Función para convertir y actualizar los resultados
def convertir_y_actualizar():
    # Obtener el valor binario desde la entrada de texto
    try:
        binary_value = ctypes.c_uint16(int(binario_entry.get()))
    except ValueError:
        resultado_label.config(text="Error: Ingrese un número entero válido")
        return
    
    # Crear un arreglo de c_uint8 para almacenar el resultado BCD
    BCD_array = (ctypes.c_uint8 * 4)()
    
    # Llamar a BINARY_TO_BCD desde Python
    ctypes.cast(BCD_array, ctypes.POINTER(ctypes.c_uint8))
    lib_bin.BINARY_TO_BCD(binary_value, BCD_array)
    
    # Mostrar el resultado BCD
    bcd_values = [BCD_array[i] for i in range(4)]
    bcd_representation = ' '.join(map(str, bcd_values))
    resultado_label.config(text=f'Representación BCD: {bcd_representation}')
    
    # Calcular y mostrar la representación en segmentos de siete segmentos para cada dígito BCD
    seven_segment_representations = []
    for bcd_value in bcd_values:
        seven_segment_result = lib_bin.BCD_TO_SEVEN_SEGMENT(ctypes.c_uint8(bcd_value))
        seven_segment_representations.append(seven_segment_result)
    
    seven_segment_representation = ' '.join(map(str, seven_segment_representations))
    seven_segment_label.config(text=f'Representación en 7 segmentos: {seven_segment_representation}')

# Crear la ventana principal
root = tk.Tk()
root.title("Conversor BCD")

# Etiqueta y entrada para el valor binario
binario_label = tk.Label(root, text="Ingrese un número binario (entero):")
binario_label.pack(pady=10)

binario_entry = tk.Entry(root, width=20)
binario_entry.pack()

# Botón para iniciar la conversión
convertir_button = tk.Button(root, text="Convertir", command=convertir_y_actualizar)
convertir_button.pack(pady=10)

# Etiquetas para mostrar los resultados
resultado_label = tk.Label(root, text="")
resultado_label.pack()

seven_segment_label = tk.Label(root, text="")
seven_segment_label.pack()

# Ejecutar el bucle principal de la interfaz gráfica
root.mainloop()