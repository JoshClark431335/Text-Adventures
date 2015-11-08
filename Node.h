#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>

enum Error_code {
	success,
	overflow,
	undefined
};

struct Node {
	char paragraph[512];
	int option_link[4];
	char option_text[4][80];
	int paragraph_num;
	bool final_state;
	
	Node();
};

class Storyboard {
	public:
		Storyboard();
		Error_code print_active();
		Error_code add_node(Node* new_node);
		Error_code change_active(int new_active);
		Error_code change_links(Node* this_node, int new_link[4],
			char new_text[4][80]);
		
	protected:
		Node* start; //page[0]
		Node* active; //easier than page[i]
		Node *page[100];
		int num_nodes;
};

#endif
