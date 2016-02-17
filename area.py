#-*-coding:utf8;-*-
#qpy:3
#qpy:console

import json

class Area():
    def __init__(self):
        para = "paragraph"
        options = []
        links = []
        final = False
    def print_para(self):
        print(self.para)
    para = "paragraph"
    options = []
    links = []
    final = False

def load_story(json_file):
    json_data = open(json_file, 'r')
    prebook = json.load(json_data)
    book = []
    for page in prebook:
        new_page = Area()
        new_page.para = page['para']
        new_page.options = page['options']
        new_page.links = []
        for link in page['links']:
            new_page.links.append(int(link))
        if (page['final']=='true' or 
        	    page['final']=='True'):
            new_page.final = True
            #continue
        else:
            new_page.final = False
        book.append(new_page)
    json_data.close()
    return book
