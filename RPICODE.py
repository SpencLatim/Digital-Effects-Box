import tkinter as tk
from tkinter import ttk
import threading
import serial
import time
import re

char_map = {
range(0, 11): " ",
range(11, 22): "!",
range(22, 33): '"',
range(33, 44): "#",
range(44, 55): "$",
range(55, 66): "%",
range(66, 77): "&",
range(77, 88): "'",
range(88, 99): "(",
range(99, 110): ")",
range(110, 121): "*",
range(121, 132): "+",
range(132, 143): ",",
range(143, 154): "-",
range(154, 165): ".",
range(165, 176): "/",
range(176, 187): "0",
range(187, 198): "1",
range(198, 209): "2",
range(209, 220): "3",
range(220, 231): "4",
range(231, 242): "5",
range(242, 253): "6",
range(253, 264): "7",
range(264, 275): "8",
range(275, 286): "9",
range(286, 297): ":",
range(297, 308): ";",
range(308, 319): "<",
range(319, 330): "=",
range(330, 341): ">",
range(341, 352): "?",
range(352, 363): "@",
range(363, 374): "A",
range(374, 385): "B",
range(385, 396): "C",
range(396, 407): "D",
range(407, 418): "E",
range(418, 429): "F",
range(429, 440): "G",
range(440, 451): "H",
range(451, 462): "I",
range(462, 473): "J",
range(473, 484): "K",
range(484, 495): "L",
range(495, 506): "M",
range(506, 517): "N",
range(517, 528): "O",
range(528, 539): "P",
range(539, 550): "Q",
range(550, 561): "R",
range(561, 572): "S",
range(572, 583): "T",
range(583, 594): "U",
range(594, 605): "V",
range(605, 616): "W",
range(616, 627): "X",
range(627, 638): "Y",
range(638, 649): "Z",
range(649, 660): "[",
range(660, 671): "\\",
range(671, 682): "]",
range(682, 693): "^",
range(693, 704): "_",
range(704, 715): "`",
range(715, 726): "a",
range(726, 737): "b",
range(737, 748): "c",
range(748, 759): "d",
range(759, 770): "e",
range(770, 781): "f",
range(781, 792): "g",
range(792, 803): "h",
range(803, 814): "i",
range(814, 825): "j",
range(825, 836): "k",
range(836, 847): "l",
range(847, 858): "m",
range(858, 869): "n",
range(869, 880): "o",
range(880, 891): "p",
range(891, 902): "q",
range(902, 913): "r",
range(913, 924): "s",
range(924, 935): "t",
range(935, 946): "u",
range(946, 957): "v",
range(957, 968): "w",
range(968, 979): "x",
range(979, 990): "y",
range(990, 1001): "z",
range(1001, 1012): "{",
range(1012, 1024): "|"
#range(638, 649): "}", //may replace with space, it's a little tricky? currently turns MUTE OFF

#range(638, 649): "~" //used for turning MUTE ON
}

def update_value(sensor_index, value):
    
global serial_thread_running
global sensor_values
global selected_tab_index

if serial_thread_running:
    sensor_values[sensor_index] = int(value)
    ser.write(f"Slider Value {sensor_index + 1}:
    {sensor_values[sensor_index]}\n".encode('utf-8'))
else:
    sensor_values[sensor_index] = int(value)


char_values = [next(char for range_, char in char_map.items() if value in range_) for value in sensor_values]

print(selected_tab_index, end="")
print("".join(char_values))

def serial_reader():
global serial_thread_running
global sensor_values
global notebook
global selected_tab_index

ser = serial.Serial('/dev/ttyUSB0', 57600, timeout=1.0) #previously 115200
while True:
    time.sleep(0.03)
    if serial_thread_running:
        ser.write("READ_SENSOR\n".encode('utf-8'))
    if ser.in_waiting > 0:
        response = ser.readline().decode('utf-8').rstrip()
        print("NANO:", response)
pattern = r"\[(\d+),\s*(\d+),\s*(\d+),\s*(\d+)\]"
match = re.search(pattern, response)

if match:
    sensor_values = [int(match.group(i)) for i in range(1, 5)]
    selected_tab_index = notebook.index(notebook.select())
    scales = slider_sets[selected_tab_index]
    print(selected_tab_index, end="")

for i, value in enumerate(sensor_values):
    scales[i].set(value)

for range_, char in char_map.items():
    if value in range_:
    print(char, end="")
    break

def toggle_serial_thread():
global serial_thread_running
global ser

serial_thread_running = not serial_thread_running

if serial_thread_running:
    ser = serial.Serial('/dev/ttyUSB0', 57600, timeout=1.0)
    start_button.config(text="Stop External Control")
else:
    ser.close()
    start_button.config(text="Start External Control")

def create_sliders(tab, tab_index):
    scales = []
    frame = ttk.Frame(tab)
    frame.pack(fill='both', expand=True)
for i in range(4):
    if tab_index == 1: # For tab 2 (EQ)
        if i == 0:
            label_text = "Low"

        elif i == 1 or i == 2:
            label_text = "Mid"
        else:
            label_text = "High"
    else:
        label_text = f"Slider {i+1}"
        label = tk.Label(frame, text=label_text)
        label.grid(row=0, column=i, pady=5) # Place label above the slider
        scale = tk.Scale(frame, from_=1023, to=0, orient=tk.VERTICAL,
        length=100,width=106, command=lambda value, idx=i: update_value(idx, value))
        scale.grid(row=1, column=i, padx=20) # Place scale below the label
        scales.append(scale)
        return scales
    
def on_tab_selected(event):
global selected_tab_index

selected_tab_index = notebook.index(notebook.select())
print(selected_tab_index, end="")
print(" ")

def muteToggle():
global toggle_state

if toggle_state:
    mute_button.config(text="Mute Off")
    print("\n}}}}}")
else:
    mute_button.config(text="Mute On")
    print("\n~~~~~")
    toggle_state = not toggle_state

def reset_sliders():
    
for scales in slider_sets.values():
    for scale in scales:
        scale.set(0)
        toggle_state = False
        serial_thread_running = False
        sensor_values = [0, 0, 0, 0]
        root = tk.Tk()
        root.title("Starter Gig Effects Unit")
        notebook = ttk.Notebook(root)
        notebook.pack(fill='both', expand=True)
        notebook.bind("<<NotebookTabChanged>>", on_tab_selected)
for i, tab_name in enumerate(["Distortion", "EQ", "Tremolo"]):
    tab = ttk.Frame(notebook)
    notebook.add(tab, text=tab_name)
    start_button = tk.Button(root, text="Start External Control",
command=toggle_serial_thread)
    

start_button.pack(pady=10)
serial_thread = threading.Thread(target=serial_reader, daemon=True)
serial_thread.start()
mute_button = tk.Button(root, text="Mute Off", command=muteToggle)
mute_button.pack(pady=10)
reset_button = tk.Button(root, text="Reset Sliders", command=reset_sliders)
reset_button.pack(pady=10)
slider_sets = {}

for i in range(3):
    slider_sets[i] = create_sliders(notebook.winfo_children()[i], i)
root.mainloop()