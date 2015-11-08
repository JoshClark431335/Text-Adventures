#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;

int main(int argc, char *argv[]) {
	int option_taken = 0;

	if (argc != 2) {
		cerr << "Incorrect parameters\n";
		cerr << "usage: ./a.out <filename>\n";
		return 1;
	}

	Storyboard story;

	Node Node1;
	Node1.paragraph = "paragraph 1";
	story.add_node(&Node1);
	story.change_links(&Node1, {1,2,3,4}, {
		"go to paragraph 1",
		"go to paragraph 2",
		"go to paragraph 3",
		"go to paragraph 4"});
/*	Node1->option_link[0] = 1;
	Node1->option_text[0] = "go to paragraph 1";
	Node1->option_link[1] = 2;
	Node1->option_text[1] = "go to paragraph 2";
	Node1->option_link[2] = 3;
	Node1->option_text[2] = "go to paragraph 3";
	Node1->option_link[3] = 4;
	Node1->option_text[3] = "go to paragraph 4";*/

	story.change_active(0);
	
	while (!active.final_node) {
		story.print_active();
		for (int i=0; i<4; i++){
			printf("\t%d. %s\n", i,active->option_text[i]);
		}
		//link to appropriate node
	}

	return 0;
}
