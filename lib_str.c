#include <stdlib.h>
#include <stdio.h>

char * my_strcopy(char * p);
int len_str(char * a);
void bubblepros(char * s);


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

void bubblepros(char * s){
	int i,n,j,tmp;
	char * a;
	n=len_str(s);
	a=malloc(n*sizeof(char));
	for(i=0;i<n-1;i++){
		if(s[i]>s[i+1]){
			j=i+1;
			tmp=s[j];
			while((j>0)&&(tmp<s[j-1])){
				a[j]=s[j-1];
				a[j-1]=tmp;
				j--;
			}
		}
	}
}