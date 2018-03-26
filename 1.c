#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct L1{
	char * s;
	struct L1 * next;
};

struct TreeNode {
	char *val;
	char *word;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct Tree {
	struct TreeNode *root;
};

int super_strcmp(char * s1,char * s2);
void search(struct TreeNode * cur,struct L1 ** list,struct L1 * end,char * s);
struct L1 * L1_add(struct L1 ** list,struct L1 * end,char * s);
char * my_strcopy(char * p);
int len_str(char * a);
char * bubblepros(char * s);
void treeAdd (struct Tree *tree, char *s);
void treePrintNode (struct TreeNode *cur);
void treePrint (struct Tree *tree);
void prn(struct L1 * l);

int main () {
	struct L1 * list=NULL, * end=NULL;
	FILE *f;
	char *s;
	char *k;
	struct Tree *tree;
	
	f = fopen ("words.txt", "r");
	
	tree = (struct Tree *)malloc(sizeof(struct Tree));
	(*tree).root = NULL;
	
	s = malloc(128*sizeof(char));
	k = malloc(128*sizeof(char));
	while (fscanf(f, "%s", s) == 1) {
		treeAdd (tree, s);
	}
	printf("Введите слово: ");
	scanf("%s",k);
	search(tree->root,&list,end,bubblepros(k));
	prn(list);
	return 0;
	
}

struct L1 * L1_add(struct L1 ** list,struct L1 * end,char * s){
	struct L1 * cur;
	cur=(struct L1 *)malloc(sizeof(struct L1));
	cur->s=my_strcopy(s);
	if(end!=NULL){
		cur->next=NULL;
		end->next=cur;
		end=cur;
	}
	else{
		cur->next=NULL;
		end=cur;
		*list=end;
	}
	return end;
}



void prn(struct L1 * l){
	struct L1 * tmp;
	printf("\n");
	tmp=l;
	while(tmp!=NULL){
		printf("%s\n",tmp->s);
		tmp=tmp->next;
	}
	printf("\n");
}

char * my_strcopy(char * p){
	int n,i;
	char * copys;
	n=len_str(p);
	copys=malloc((n+1)*sizeof(char));
	for(i=0;i<n;i++){
		copys[i]=p[i];
	}
	copys[n]='\0';
	return copys;
}

int len_str(char * a){
	int i=0;
	while(a[i]!='\0'){i++;}
	return i;
}

char * bubblepros(char * a){
	int i,n,j,tmp;
	n=len_str(a);
	for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			j=i+1;
			tmp=a[j];
			while((j>0)&&(tmp<a[j-1])){
				a[j]=a[j-1];
				a[j-1]=tmp;
				j--;
			}
		}
	}
	return a;
}

int my_strcmp(char * s1,char * s2){
	while((*s1!='\0')&&(*s2!='\0')&&(*s1==*s2)){
		s1=s1+1;
		s2=s2+1;
	}
	return *s1-*s2;
}

void treeAdd (struct Tree *tree, char *s) {
	
	struct TreeNode *cur;
	struct TreeNode *node = malloc(sizeof(struct TreeNode));
	struct TreeNode **cur_add;
	char * a;
	
	cur = (*tree).root;
	cur_add = &((*tree).root);
	(*node).left = NULL;
	(*node).right = NULL;
	a=my_strcopy(s);
	node->val=my_strcopy(bubblepros(s));
	node->word=my_strcopy(a);
	
	while (cur != NULL) {
		if(my_strcmp (bubblepros(s),(*cur).val) > 0) {
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
	printf("%s ",cur->val);
	printf("%s\n",cur->word);
	treePrintNode ((*cur).right);
	return;
	
}

int super_strcmp(char * s1,char * s2){
	while((*s1!='\0')&&(*s2!='\0')&&(*s1==*s2)){
		s1=s1+1;
		s2=s2+1;
	}
	if(*s2=='\0'){return 0;}
	else{return *s1-*s2;}
}

void search(struct TreeNode * cur,struct L1 ** list,struct L1 * end,char * s){
	int i,j=0,tmp=0;
	if (cur == NULL) {
		return;
	}
	for(i=0;i<len_str(cur->val)+1;i++){
		while((j<len_str(s)+1)&&(cur->val[i]!=s[j])){
			j++;
		}
		if(j==len_str(s)+1){
			tmp=0;
			break;
		}
		else{tmp++;}
	}
	if(tmp>0){end=L1_add(list,end,cur->word);}
	j=0;
	tmp=0;
	search(cur->left,list,end,s);
	if(my_strcmp(s,cur->val)>=0){search(cur->right,list,end,s);}
	return;
}

void treePrint (struct Tree *tree) {
	treePrintNode ((*tree).root);
}

