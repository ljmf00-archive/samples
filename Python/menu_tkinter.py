
from tkinter import *

class Window(Frame):

    def __init__(self, master=None):
        Frame.__init__(self, master)                  
        self.master = master
        self.init_window()

    def init_window(self):     
        self.master.title("GUI")
        self.pack(fill=BOTH, expand=1)
        menu = Menu(self.master)
        self.master.config(menu=menu)
        file = Menu(menu)
        file.add_command(label="Exit", command=self.client_exit)
        menu.add_cascade(label="File", menu=file)
        edit = Menu(menu)
        edit.add_command(label="Undo")
        menu.add_cascade(label="Edit", menu=edit)
    def client_exit(self):
        exit()

root = Tk()

root.geometry("400x300")
app = Window(root)
root.mainloop() 