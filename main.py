#-*-coding:utf8;-*-
#!/usr/bin/python3
#qpy:3
#qpy:console

from area import *
import os

def validate_choice(options=[]):
    try:
        choice = int(input())
    except(ValueError):
        choice = 0
    if (choice<1 or choice>len(options)):
        choice = 0
    return choice
    
def print_page(current=Area()):
    current.print_para()
    print()
    for i in range(len(current.options)):
        print('    ', i+1, '. ', current.options[i], sep='')

page_no = 0
#for my android
#book = load_story('/storage/sdcard0/com.hipipal.qpyplus/projects3/TBA_RPG/story1.json')
#for linux
book = load_story('./story1.json')

while (book[page_no].final == False):
    page = book[page_no]
    os.system('clear')
    print_page(page)
    while (True):
        choice = validate_choice(page.options)
        if (choice!=0):
            break
        os.system('clear')
        print('Invalid option. please pick again')
        print()
        print_page(page)
    page_no = page.links[choice-1]

os.system('clear')
book[page_no].print_para()
print("the end")

