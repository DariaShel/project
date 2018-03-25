#include<stdio.h>
#include<stdlib.h>

struct TREE{
	char val1[128];
	char val2[128];
	struct TREE * right;
	struct TREE * left;
}

struct L1{
	char s[128];
	struct L1 * next;
}

void bubblepros(char * a);
void prn_str(char * p);
int my_strlen(char * p);
char * my_strcopy(char * p);

int main(){
	struct TREE * root = NULL;
	struct L1 * list = NULL;
	return 0;
}

void bubblepros(char * a){
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
}

void prn_str(char * p){
	int i=0;
	printf("\n");
	while(p[i]!='\0'){
		printf("%c ",p[i]);
		i++;
	}
}

int my_strlen(const char * r){
	int i=0;
	while(r[i]!='\0'){i++;}
	return i;
}

void my_strcopy(const char * p,char * copys){
	int n,i;
	n=my_strlen(p);
	for(i=0;i<n;i++){
		copys[i]=p[i];
	}
	copys[n]='\0';
}

struct L1 * init(char * val){
	struct L1 * begin=NULL, * end=NULL, * cur;
	int n,x;
	cur=(struct L1 *)malloc(sizeof(struct L1));
	n=my_strlen(val);
	cur->s=(char*)malloc((n+1)*sizeof(char));
	my_strcopy(val,cur->s);
	cur->next=NULL;
	if(end==NULL){
		begin = cur;
		end = cur;
	}
	else{
		end->next=cur;
		end=cur;
	}
	
	return begin;
}