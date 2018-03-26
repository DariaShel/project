#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct TreeNode {
	char *val;
	char *word;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct Tree {
	struct TreeNode *root;
};


void treeAdd (struct Tree *tree, char *s) {
	
	struct TreeNode *cur;
	struct TreeNode *node;
	struct TreeNode **cur_add;
	
	cur = (*tree).root;
	cur_add = &((*tree).root);
	
	node = (struct TreeNode *)malloc(1*sizeof(struct TreeNode));
	(*node).word = (char *)malloc(128*sizeof(char));
	(*node).val = (char *)malloc(128*sizeof(char));
	(*node).left = NULL;
	(*node).right = NULL;
	strcpy ((*node).val, s);
	strcpy ((*node).word, s);
	
	while (cur != NULL) {
		if (strcmp ((*cur).val, s) < 0) {
			cur_add = &((*cur).right);
			cur = (*cur).right;
		}
		else {
			cur_add = &((*cur).left);
			cur = (*cur).left;
		}
	}
	
	*cur_add = node;
	
	return;
	
}


void treePrintNode (struct TreeNode *cur) {
	
	if (cur == NULL) {
		return;
	}
	
	treePrintNode ((*cur).left);
	printf ("%s ", (*cur).val);
	printf ("%s ", (*cur).word);
	printf ("\n");
	treePrintNode ((*cur).right);
	
	return;
	
}

void treePrint (struct Tree *tree) {
	treePrintNode ((*tree).root);
}


int main () {
	
	FILE *f;
	char *s;
	struct Tree *tree;
	
	f = fopen ("input_char.txt", "r");
	
	tree = (struct Tree *)malloc(1*sizeof(struct Tree));
	(*tree).root = NULL;
	
	s = (char *)malloc(128*sizeof(char));
	
	while (fscanf(f, "%s", s) == 1) {
		treeAdd (tree, s);
	}
	
	treePrint (tree);
	
	return 0;
	
}