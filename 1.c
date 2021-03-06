#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct L1{
	char * s;
	int v;
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

struct L1 * list=NULL;

int super_strcmp(char * s1,char * s2);
void search(struct TreeNode * cur,char * s);
struct L1 * L1_add(struct L1 * list,char * s);
char * my_strcopy(char * p);
int len_str(char * a);
char * bubblepros(char * s);
void treeAdd (struct Tree *tree, char *s);
void treePrintNode (struct TreeNode *cur);
void treePrint (struct Tree *tree);
void prn(struct L1 * l);
void global_add(char * s);
void L1_Search(char * s,struct L1 * begin);
int my_strcmp(char * s1,char * s2);

int main () {
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
	search(tree->root,bubblepros(k));
	printf("Введите слова, которые можно составить из этого слова\n Когда закончите, введите '0':\n");
	while(*k!='0'){
		scanf("%s",k);
		if(*k!='0'){L1_Search(k,list);}
	}
	prn(list);
	return 0;
	
}

void L1_Search(char * s,struct L1 * begin){
	struct L1 * cur=(struct L1 *)malloc(sizeof(struct L1));
	struct L1 * tmp;
	tmp=begin;
	while((tmp->next!=NULL)&&(my_strcmp(s,tmp->s)!=0)){tmp=tmp->next;}
	if(my_strcmp(s,tmp->s)==0){
		begin->v=1;
	}
	else{
		cur->v=-1;
		cur->s=my_strcopy(s);
		cur->next=NULL;
		tmp->next=cur;
	}
}

struct L1 * L1_add(struct L1 * list,char * s){
	struct L1 * cur;
	struct L1 * tmp;
	cur=(struct L1 *)malloc(sizeof(struct L1));
	cur->s=my_strcopy(s);
	cur->v=0;
	cur->next=NULL;
	if(list==NULL){list=cur;}
	else{
		tmp=list;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=cur;
	}
	return list;
}



void prn(struct L1 * l){
	struct L1 * tmp;
	printf("\n");
	tmp=l;
	printf("Ещё возможные слова:\n");
	while((tmp!=NULL)&&(tmp->v>=0)){
		if(tmp->v==0){printf("<%s>\n",tmp->s);}
		tmp=tmp->next;
	}
	printf("\n");
	printf("Неверно введённые слова:\n");
	while((tmp!=NULL)&&(tmp->v==-1)){
		printf("<%s>\n",tmp->s);
		tmp=tmp->next;
	}
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
	while(*s2!='\0'){
		while((*s1!='\0')&&(*s2>*s1)){s1=s1+1;}
		if(*s1=='\0'){return -1;}
		else if(*s1>*s2){return 1;}
		s2=s2+1;
		s1=s1+1;
	}
	return 0;
}

void search(struct TreeNode * cur,char * s){
	int tmp=0;
	if (cur == NULL) {
		return;
	}
	search(cur->left,s);
	tmp=super_strcmp(s,cur->val);
	if(tmp==0){global_add(cur->word);}
	search(cur->right,s);
	return;
}

void global_add(char * s){
	list=L1_add(list,s);
}

void treePrint (struct Tree *tree) {
	treePrintNode ((*tree).root);
}

