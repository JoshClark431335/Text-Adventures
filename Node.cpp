#include "Node.h"
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <stdlib.h>

Node::Node(){
	paragraph = "";
	for (int i=0; i<4; i++){
		option_link[i] = i+1;
		option_text[i] = "Asfg";
	}
	paragraph_num = 0;
	final_state = false;
}

Storyboard::Storyboard(){
	num_nodes = 0;
	active = NULL;
	start = NULL;
	for (int i=0; i<100; i++)
		page[i] = NULL;
}

Error_code Storyboard::print_active(){
	/*if (this_node==NULL)
		return undefined;*/
	printf("\n%s\n\n",page[active]->paragraph);
	printf("Select an option:\n");
	for (int i=0; i<4; i++) {
		printf("\t%d. %s\n", i, page[active]->option_text[i]);
	}
	printf("\n");
	return success;
}

Error_code Storyboard::add_node(Node* new_node){
	if (num_nodes==100)
		return overflow;
	page[num_nodes] = new_node;
	if (num_nodes == 0)
		start = new_node;
	num_nodes++;
	return success;
}

Error_code Storyboard::change_active(int new_active){
	if (page[new_active] = NULL)
		return undefined;
	active = page[new_active];
	return success;
}

Error_code Storyboard::change_links(Node* this_node, int new_link[4], char new_text[4][80]){
	if (this_node = NULL)
		return undefined;
	for (int i=0; i<4; i++){
		this_node->option_link[i] = new_link[i];
		if (strcmp(new_text[i],""))
			this_node->option_text[i] = new_text[i];
	}
	return success;
}
