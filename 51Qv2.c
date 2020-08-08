#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

LInt parteAmeio (LInt *l){
    int n;
    LInt inicio = *l, *aux = l;
    n = length (*l)/2;
    if(n==0) {
    	*l = inicio;
    	return NULL;
    }
    while(n>0){
        aux = &((*aux)->prox);
        n--;
    }
    *l = *aux;
    *aux = NULL;
    return inicio;
}
int length (LInt l){
	int n=1;
	if (!l) n=0;
	else while (l->prox){
	    n++;
		l=l->prox;
	} 
	return n;
}

LInt parteAmeio (LInt *l){
    int n;
    LInt nova, aux = *l:
    for(n=0; aux; n++) aux = aux->prox;
    n = n/2;
	novo = *l;
	while(n){
		novo = novo->prox;
		aux = *l;
		l = &((*l)->prox);
		free aux;
		n--;
	}
	return novo;
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l){
    	if(l->valor < x){
    		*mx = l; 
    		mx = &((*mx)->prox);
    	}
    	else{
    		*Mx = l; 
    		Mx = &((*Mx)->prox);
    	}
    	l = l->prox;
    }
    *mx = *Mx = NULL;
}

void merge (LInt *r, LInt a, LInt b){
	while(a && b){
	    *r = malloc(sizeof(struct lligada));
		if (a->valor > b->valor){
			(*r)->valor = b->valor;
			b = b->prox; 
		}
		else{
			(*r)->valor = a->valor;
			a = a->prox; 			
		}
		r = &((*r)->prox);
	}

	if(a) *r = a;
	else *r = b;
}

int removeOneOrd (LInt *l, int x){
	LInt aux;
    while(*l && (*l)->valor != x) l = &((*l)->prox);
    if(*l && (*l)->valor == x) {
    	aux = *l;
    	*l = (*l)->prox;
    	free(aux); 
    	return 0;
    }
    return 1;
}


void insertOrd (LInt *l, int x){
	LInt nova = malloc(sizeof(struct lligada));
	nova->valor = x;
	nova->prox = NULL;
    while(*l && (*l)->valor<x) l = &((*l)->prox);
    nova->prox = *l;
    *l = nova;
}

LInt reverseL (LInt l){//?
	LInt ant,prox;
	ant = NULL;
	while (l){
        prox = l->prox;   
        l->prox = ant;    
        ant = l; 
        l = prox; 
	} 
    l=ant;
	return l;
}

void imprimeL (LInt l){
	while(l){
		printf(%d/n,l->valor);
		l=l->prox;
	}
}

void freeL (LInt l){
	LInt aux;
	while(l){
		aux=l;
		l=l->prox;
		free(aux);
	}
}

int length (LInt l){
    int tam;
    for(tam=0;l;l=l->prox) tam++;
    return tam;
}