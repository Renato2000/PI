#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
	int valor;
	struct lligada *prox;
} *LInt;

typedef struct nodo {
	int valor;
	struct nodo *esq, *dir;
} *ABin;

int main() {
}

/* Exercicio 51 - correto REVER
int deProcuraAux (int min, int max, ABin a){
	int r = 1;
	if(a){
		r = deProcuraAux(a->valor, max, a->dir) && deProcuraAux(min, a->valor, a->esq) && (a->valor <= max) && (a->valor >= min);
	}
	return r;
}
int deProcura (ABin a){
	int r = 1;
	ABin min = a, max = a;
	if(a){
		while(min->esq) min = min->esq;
		while(max->dir) max = max->dir;
		r = deProcuraAux(min->valor,max->valor,a);
	}
	return r;
}
*/

/* Exercicio 50 - correto
void insere (ABin novo, ABin *a){ // Função que insere um nodo numa arvore de procura 
    while(*a){
        if((*a)->valor < novo->valor) a = &((*a)->dir);
        else a = &((*a)->esq);
    }
    *a = novo;
}
void listToBTree (LInt l, ABin *a){
    ABin novo;
    while(l){
        novo = malloc(sizeof(struct nodo));
        novo->valor = l->valor;
        novo->dir = novo->esq = NULL;
        insere(novo,a);
        l = l->prox;
    }
}
*/

/* Exercicio 49 - correto TENTAR MELHORAR
int quantosMaiores (ABin a, int x){
	int n=0;
	if(a){
	    if(a->valor == x) n--;
		if(a->valor < x) n = n + quantosMaiores(a->dir, x);
		else if(a->esq && (a->esq)->valor > x) n = n + 1 + quantosMaiores(a->dir,x) + quantosMaiores(a->esq,x);
			else n = n + 1 + quantosMaiores(a->dir,x);
	} 
	return n;
}
*/

/* Exercicio 48 - correto
void removeMaiorA (ABin *a){
    ABin aux;
    while(*a && (*a)->dir){
    	a = &((*a)->dir);
    }
    aux = (*a)->esq;
    free (*a);
    *a = aux;
}
*/

/* Exericio 47 - correto
int maiorAB (ABin a){
    while(a && a->dir){
    	a = a->dir;
    }
	return a->valor;
}
*/

/* Exericio 46 - correto
int depthOrd (ABin a, int x){
	int n = 0, depth = 0;
    while(a && !n){
        if(a->valor == x) n = 1;
        else{
            if (x < a->valor) a = a->esq;
            else a = a->dir;
        }
        depth ++;
    }
    if(n == 0) depth = -1;
	return depth;
}
//Forma recursiva
int depthOrd (ABin a, int x) {
    int r=0,v;
    if(a){
        if(a->valor == x) return 1;
        else{
            if(a->valor > x) {
                v = depthOrd(a->esq,x);
                if(v != -1) r = r+1+v;
                else r = -1;
            }
            else{
                v = depthOrd(a->dir,x);
                if(v != -1) r = r+1+v;
                else r = -1;
            }
        }
    }
    else r=-1;
    return r;
}
*/

/* Exercicio 45 - correto
int lookupAB (ABin a, int x){
	int n = 0;
	if(a){
	    if(a->valor == x) n = 1;
	    else{
	    	if(a->valor > x && !a->dir || a->valor < x && !a->esq) n = 0;
	    	else{
	    		if(a->valor > x) n = lookupAB(a->dir, x);
	    		else n = lookupAB(a->esq, x);
	    	}
	    }
	}
	return n;
}
*/

/* Exericio 44 - correto
int addOrd (ABin *a, int x) {
    int r=0;
    ABin novo;
    while(*a && !r){
        if((*a)->valor == x) r=1;
        else{
            if((*a)->valor > x) a = &((*a)->esq);
            else a = &((*a)->dir);
        }
    }
    if(!r){
        novo = malloc(sizeof(struct nodo));
        novo->valor = x;
        novo->dir = novo->esq = NULL;
        *a = novo;
    }
    return r;
}
//Forma recursiva
int addOrd (ABin *a, int x){
	ABin novo = malloc(sizeof(struct nodo));
	int n;
	if (!*a){
		novo->valor = x;
		novo->dir = novo->esq = NULL;
		*a = novo;
		return 0;
	}
	else{
		if ((*a)->valor == x) return 1;
		if(x > (*a)->valor) n = addOrd(&((*a)->dir), x);
		else n = addOrd(&((*a)->esq), x); 
    }
	return n;
}
*/

/* Exericio 43 - correto
ABin cloneMirror (ABin a){
	ABin b = malloc(sizeof(struct nodo));
	if(!a) return NULL;
	else{
		b->valor = a->valor;
		b->dir = cloneMirror (a->esq);
		b->esq = cloneMirror (a->dir); 
	}
	return b;	
}
*/

/* Exercicio 42 - correto
int contaFolhas (ABin a){
	int n=0;
	if(a){
		if (!(a->esq) && !(a->dir)) n++;
		else{
			n = n + contaFolhas(a->esq);
			n = n + contaFolhas(a->dir);
		}
	}
	return n;
}
*/

/* Exercicio 41 - correto
int somasAcAaux(ABin a){
    int r=0;
    if (a){
        r = a->valor;
        r += somasAcAaux(a->dir);
        r += somasAcAaux(a->esq);
    }
    return r;
}
ABin somasAcA (ABin a) {
    ABin b = NULL;
    if(a){
        b = malloc(sizeof(struct nodo));
		b->dir = somasAcA(a->dir);
		b->esq = somasAcA(a->esq);
		b->valor = somasAcAaux(a);
    }
    return b;
}
*/	

/* Exercicio 40 - correto
int dumpAbin (ABin a, int v[], int N){
	int c=0;
	if (a && c<N){
	    c = c + dumpAbin (a->esq,v+c,N-c);
	    if(c<N){
	        v[c] = a->valor;
	        c++;
	    }
	    c = c + dumpAbin (a->dir,v+c,N-c);
	}
	return c;
}
*/


/* Exercicio39 - correto
int nivelV (ABin a, int n, int v[]){
	int c=0;
	if(a){
	    if(n==1){
		    v[c] = a->valor;
		    c++;
	    }
    	else{
    		c = c + nivelV(a->esq,n-1,v+c);
    		c = c + nivelV(a->dir,n-1,v+c);
        }	
	}
	return c;
}
*/

/* Exericio 38 - correto
LInt nivelL (ABin a, int n){
	LInt l1=NULL,l2=NULL,aux=NULL;
	if(a){
	    if(n==1){ //Cria a lista quando o nível é 1
		    aux = malloc(sizeof(struct lligada));
		    aux->valor = a->valor;
	    	aux->prox = NULL;
	    }
    	else{ //Caso o nível não seja 1
	    	l1 = nivelL(a->esq,n-1); //Cria a lista para a árvore à esquerda
		    l2 = nivelL(a->dir,n-1); //Cria a lista para a árvore à direita
		    if(l1){ //Caso a lista da árvore à esquerda exista(para evitar os casos em q não existe)
    	        aux = l1; //Guarda o inicio da lista
    	        for(; l1->prox; l1 = l1->prox); //Anda com a lista até chegar ao ultimo elemento
    	        l1->prox = l2; //Define o proximo elemento como o primeiro elemento da proxima lista
    	    }
    	    else aux = l2; //Caso a primeria lista seja nula, vai devolver apenas a segunda lista
        }	
	}
	return aux; //Devolve o inicio da lista resultante
}
*/

/* Exercicio 37 - correto
int iguaisAB (ABin a, ABin b){
	int n=0;
	if(!a && !b) return 1;
	if(a && b){
		n = iguaisAB(a->dir,b->dir) && iguaisAB(a->esq,b->esq) && (a->valor == b->valor);
	}
	return n;
}
*/

/* Exercicio 36 - correto
int pruneAB (ABin *a, int l){
	int n=0;
	if (*a){
		n = n + pruneAB(&((*a)->dir),l-1) + pruneAB(&((*a)->esq),l-1);
		if (l<=0){
            free (*a);
            *a = NULL;
            n++;
		}
	}
    return n;
}
*/

/* Exercicio 35 - correto
int freeAB (ABin a){
	int n;
	if (!a) return 0;
	n = 1 + freeAB(a->dir) + freeAB(a->esq);
	free (a);
	return n;
}
*/

/* Exericio 34 - correto
int depth (ABin a, int x){
	int n,ad,ae;
	if (!a) return -1;
	else{
		if (a->valor == x) return 1;;

		ad = 1 + depth (a->dir,x);
		ae = 1 + depth (a->esq,x);
		if ((depth (a->dir,x)) < 0 && (depth (a->esq,x)) >= 0) return ae;
		if ((depth (a->esq,x)) < 0 && (depth (a->dir,x)) >= 0) return ad;
		if ((depth (a->esq,x)) < 0 && (depth (a->dir,x)) < 0) return -1;
		n = ae > ad ? ad : ae;
	}
	return n;
}
*/

/* Exercicio 33 - correto
void posorder (ABin a, LInt *l){
	if (a){
	    posorder (a->esq,l);
		while(*l) l = &((*l)->prox);
	    posorder (a->dir,l);
	    while(*l) l = &((*l)->prox);
	    *l = malloc(sizeof(struct lligada));
	    (*l)->valor = a->valor;
	    (*l)->prox = NULL;
	    l = &((*l)->prox);
	}
	else *l = NULL;	
}
*/

/* Exercicio 32 - correto
void preorder (ABin a, LInt *l){
	if (a){
		*l = malloc(sizeof(struct lligada));
	    (*l)->valor = a->valor;
	    (*l)->prox = NULL;
	    l = &((*l)->prox);
	    preorder (a->esq,l);
		while(*l) l = &((*l)->prox); 
	    preorder (a->dir,l);
	}
	else *l = NULL;	
}
*/

/* Exercicio 31 - correto
void inorder (ABin a, LInt *l){
	if (a){
	    inorder (a->esq,l);
	    while(*l) l = &((*l)->prox);
	    *l = malloc(sizeof(struct lligada));
	    (*l)->valor = a->valor;
	    (*l)->prox = NULL;
	    l = &((*l)->prox);
	    inorder (a->dir,l);
	}
}
*/

/* Exericio 30 - correto
void mirror (ABin *a){
	ABin aux;
	if (*a){
	    aux = (*a
}
*/

/* Exercicio 11 - correto
void strrev (char s[]) {
    int i,j,n;
    for(i=0;s[i];i++);)->dir;
	    (*a)->dir = (*a)->esq;
	    (*a)->esq = aux;
		mirror (&(*a)->esq);
		mirror (&(*a)->dir); 
	}
}
*/

/* Exericio 29 - correto
ABin cloneAB (ABin a){
	ABin novo = malloc(sizeof(struct nodo));
	if (!a) return NULL;
	else{
		novo->valor = a->valor;
		novo->dir = cloneAB (a->dir);
		novo->esq = cloneAB (a->esq); 
	}
	return novo;
}
*/

/* Exericio 28 - correto
int altura (ABin a){
	int n,ad,ae;
	if (!a) return 0;
	else{
		ad = 1 + altura (a->dir);
		ae = 1 + altura (a->esq); 
		n = ad > ae ? ad : ae; 
	}
	return n;
}
*/

/* Exercicio 27 - correto REVER
LInt parte (LInt l){
	LInt *aux, inicio, *p, a;
	aux = &inicio;
	p = &l;
	int n=1;
	while (*p){
		if (n%2 == 0){
			*aux = malloc(sizeof(struct lligada));
			(*aux)->valor = (*p)->valor;
			a = (*p)->prox;
			free (*p);
			*p = a;
			aux = &((*aux)->prox);
		}
		else p=&((*p)->prox);
		n++;
	}
	*aux = NULL;
	return inicio;
}
//OU
LInt parte (LInt l){
	LInt *aux, inicio, p;
	aux = &inicio;
	int n=1;
	while (l){
		if (n%2 == 0){
			*aux = malloc(sizeof(struct lligada));
			(*aux)->valor = l->valor;
			p->prox = l->prox;
			free (l);
			l = p->prox;
			aux = &((*aux)->prox);
		}
		else {
		    p = l; 
		    l=l->prox;
		}
		n++;
	}
	*aux = NULL;
	return inicio;
}
//OU
LInt parte (LInt l){REVER
	LInt *aux, inicio, p, ant=NULL;
	aux = &inicio; //Guarda o endereço do incio da lista
	int n=1;
	while (l){
		if (n%2 == 0){
			*aux = malloc(sizeof(struct lligada)); //cria um nodo
			(*aux)->valor = l->valor; //guarda o valor da lista l na lista aux
			p = l->prox; //guarda o prox da lista l
			free (l); //liberta o novo
			ant->prox = p; //corrige a lista l
			aux = &((*aux)->prox); //avança com a lista aux
			l=l->prox; //avança com a lista l
		}
		else {
		    ant=l; //guarda o l
		    l=l->prox; //avança com a lista l
		}
		n++; //incrementa o contador
	}
	*aux = NULL; //coloca o fim da lista aux a NULL
	return inicio;
}
//OU
LInt parte(LInt l){
	LInt inicio, *aux, *p;
	int n=0;
	aux = &l;
	p = &inicio;
	while(*aux){
		if(n%2){
			*p = *aux;
			p = &((*p)->prox);
			*aux = (*aux)->prox;
		}
		else aux = &((*aux)->prox);
		n++;
	}
	*p = NULL;
	return inicio;
}
*/

/* Exercicio 26 - correto REVER
LInt rotateL (LInt l){
    LInt *aux, inicio=NULL;
    aux = &l;
    while(*aux) aux = &((*aux)->prox);
    *aux = l;
    if(l){
        inicio = l->prox;
        (*aux)->prox = NULL; //l->prox = NULL; funciona pq?
    }
    return inicio;
}
*/

/* Exercicio 25 - correto
void remreps (LInt l){
	int n;
    LInt aux,*e;
	while (l){
		e = &(l->prox);
	    while (*e && (*e)->valor == l->valor){
		    aux = (*e)->prox;
			free (*e);
			*e = aux;
	    }
		l = l->prox;
	}
}
*/

/* Exercicio 24 - correto
LInt somasAcL (LInt l){
	LInt *e,i;
	e = &i; 
	int s=0;
	while (l){
		*e = malloc(sizeof (struct lligada));
		(*e)->valor = s + l->valor;
		s += l->valor;
		e = &((*e)->prox);
		l=l->prox;
	}
	*e = NULL;
	return i;
}
*/

/* Exerciico 23 - correto
LInt arrayToList (int v[], int N){
	LInt l = malloc (sizeof (struct lligada));
	l = NULL;
	while (N>0){
	    LInt aux = malloc (sizeof (struct lligada));
		aux->valor = v[N-1];
		aux->prox = l;
		l = aux; 
		N--;
	}
	return l;
}
*/

/* Exericio 22 - correto
int listToArray (LInt l, int v[], int N){
 	int n;
	for (n=0; l && N; n++){
		v[n] = l->valor;
		N--;
		l=l->prox;
	}
	return n;
}
*/

/* Exercicio 21 - correto
LInt NForward (LInt l, int N){
	LInt aux = l;
	while (N > 0){
		if (!aux) aux = l;
		else aux = aux->prox;
		N--; 
	}	
	return aux;
}
*/

/* Exercicio 20 - correto
int drop (int n, LInt *l){
	LInt aux;
	int c=0;
	while (*l && n){
		aux = (*l)->prox;
		free (*l);
		*l = aux;
		c++;
		n--;
	}
	return c;
}
*/

/* Exercicio 19 - correto
int take (int n, LInt *l){
	LInt aux;
	int c=0;
	while (*l && n){
		l=&((*l)->prox);
		c++;
		n--;
	}
	while (*l){
		aux = (*l)->prox;
		free (*l);
		*l = aux;
	}
	return c;
}
*/

/* Exercicio 18 - correto
int maximo (LInt l){
	int m = l->valor;
	while (l){
		if (l->valor > m) m = l->valor;
		l = l->prox;
	}
	return m;
}
*/

/* Exercicio 17 - correto REVER
LInt cloneRev (LInt l){
	LInt inicio = NULL,aux = NULL;
	while (l){
		aux = malloc(sizeof(struct lligada));
		aux->valor = l->valor;
		aux->prox = inicio;
		inicio = aux;
		l = l->prox;
	}
	return inicio;
}
*/

/* Exercicio 16 - deve estar correto
LInt cloneL (LInt l){
	LInt new=NULL,aux;
	if (l){
		new = aux = malloc(sizeof(struct lligada));
		new->valor = l->valor;
		l = l->prox;
		while(l){
			aux->prox = malloc(sizeof(struct lligada));
			aux = aux->prox;
			aux->valor = l->valor;
			l = l->valor;
		}		
		aux->prox = NULL;
	}
	return new;
}
//OU:
LInt cloneL (LInt l){
	Lista r, *e;
	e=&r; //e é um apontador para r
	while (l){
		*e = malloc(sizeof(struct lligada));
		(*e)->valor = l->valor;
		l = l->prox;
		e = &((*e)->prox);
 	}
 	*e = NULL;
 	return r;
}
*/

/* Exercicio 15 - correto
void concatL (LInt *a, LInt b){
	while (*a) a = &((*a)->prox);
    *a = b;
}
*/

/* Exericio 14 - correto
void appendL (LInt *l, int n){
	LInt novo = malloc (sizeof (struct lligada));
	novo->valor = n;
	novo->prox = NULL;
	if (*l)
		while (*l)
			l = &((*l)->prox);
    *l = novo;
}
*/

/* Exercicio 13 - correto
void init (LInt *l){
	while((*l)->prox)
		l = &((*l)->prox);
	free (*l);
	*l = NULL;
}
*/

/* Exercicio 12 - tentativa
void remove (LInt *l, int n){
	LInt aux;
	int v=1;

	while(*l && v){
		if ((*l)->valor == n){
			v=0;
			aux = (*l)->prox;
			free (*l);
			*l = aux;
		}
		l = &((*l)->prox);
	}
}
int maior(LInt l){ //Só recebe listas não vazias
	int m;
	m = l->valor;
	l=l->prox;
	while (l){
		if (l->valor > m) m =l->valor;
		l=l->prox;
	}
	return m;
}
*/
/* Exercicio 12 - correto
int removeMaiorL (LInt *l){
	int maior;
	LInt *aux,p;
	for (aux = l; *aux; aux = &((*aux)->prox))
		if ((*l)->valor < (*aux)->valor)
			l = aux;
	maior = (*l)->valor;
	p = (*l)->prox;
	free (*l);
	*l = p;
	return maior;
}
//OU
int removeMaiorL (LInt *l){
    int maior=(*l)->valor;
    LInt aux=*l;
    while(aux){
        if(aux->valor > maior) maior = aux->valor;
        aux = aux->prox;
    }
    while((*l)->valor != maior) l = &((*l)->prox);
    aux = (*l)->prox;
    free(*l);
    *l = aux;
    return maior;
}
*/

/* Exercicio 11 - correto
int removeAll (LInt *l, int x){
	int n=0;
	LInt aux;
	while (*l){
		if ((*l)->valor == x) {
			aux = (*l)->prox;
			free (*l);
			*l = aux;
			n++;
		}
		else l = &((*l)->prox);
	}
	return n;
}
int removeDups (LInt *l){
    int n=0;
    while(*l){
        n += removeAll(&(*l)->prox,(*l)->valor);
        l = &((*l)->prox);
    }
    return n;
}
*/

/* Exercicio 10 - correto
int removeAll (LInt *l, int x){
	int n=0;
	LInt aux;
	while (*l){
		if ((*l)->valor == x) {
			aux = (*l)->prox;
			free (*l);
			*l = aux;
			n++;
		}
		else l = &((*l)->prox);
	}
	return n;
}
*/

/* Exercicio 9 - correto REVER
LInt parteAmeio (LInt *l){
	int i,j;
	LInt *aux = l, inicio = *l;
	i = length(*l)/2;
	for (j=0; j<i; j++) aux = &((*aux)->prox);
	*l = *aux;
	*aux = NULL;
	if (i==0){
	    *l=inicio;
	    return NULL;
	}
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
*/

/* Exercicio 8 - correto
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
	while (l){
		if (l->valor < x){
			*mx = l;
			mx = &((*mx)->prox);
		}
		else {
			*Mx = l;
			Mx = &((*Mx)->prox);
		}
		l=l->prox;
	}
	*mx = *Mx = NULL;
}
*/

/* Exercicio 7 - correto 
void merge (LInt *r, LInt l1, LInt l2){
    while(l1 && l2){
        if(l1->valor < l2->valor){
            *r = l1;
            l1 = l1->prox;
        }
        else {
            *r = l2;
            l2 = l2->prox;
        }
        r = &((*r)->prox);
    }
    if(l1) {*r = l1; }
    else if(l2) {*r = l2; }
         else *r = NULL;
}
//OU
void merge (LInt *r, LInt a, LInt b){
	LInt aux;
	if (a==NULL) *r = b;
	else if (b==NULL) *r = a;
		else {
			if (a->valor < b->valor){
				*r = a;
				a = a->prox;
			} 
			else {
				*r = b;
				b = b->prox;
			}
			aux = *r;
			while (a && b){
				if (a->valor < b->valor){
					aux->prox = a;
					a = a->prox;
				} 
				else {
					aux->prox = b;
					b = b->prox;
				}
				aux=aux->prox;
			}
			if (a==NULL) aux->prox = b;
			else aux->prox = a;
		}
}
//OU
void merge (LInt *r, LInt l1, LInt l2){
    while(l1 && l2){
        if(l1->valor < l2->valor){
            *r = malloc(sizeof(struct lligada));
            (*r)->valor = l1->valor;
            r = &((*r)->prox);
            l1 = l1->prox;
        }
        else{
            *r = malloc(sizeof(struct lligada));
            (*r)->valor = l2->valor;
            r = &((*r)->prox);
            l2 = l2->prox;
        }
    }
    if(l1) (*r) = l1;
    else (*r)= l2;
}
*/

/* Exercicio 6 - correto 
int removeOneOrd (LInt *l, int n){
	LInt aux;
	int v=1;
	aux = *l;
	while (*l && (*l)->valor < n)
		l = &((*l)->prox);
	if (*l){
	    aux = (*l)->prox;
	    free(*l);
	    *l=aux;
	    v=0;
	}
	return v;
}
//OU
int removeOneOrd (LInt *l, int x){
    LInt aux, ant=NULL;;
    int n=1;
    while(*l && n){
        if((*l)->valor == x){
            n=0;
            aux = (*l)->prox;
            free(*l);
            if(ant) ant->prox = aux;
            else *l=aux;
        }
        else{
            ant = *l;
            l = &((*l)->prox);
        }
    }
    return n;
}
//OU
int removeOneOrd (LInt *l, int x){
    LInt aux, ant=NULL;;
    int n=1;
    while(*l && n){
        if((*l)->valor == x) n=0;
        else{
            ant = *l;
            l = &((*l)->prox);          					
        }
    }
    if(!n){
        aux = (*l)->prox;
        free(*l);
        if(ant) ant->prox = aux;
        else *l=aux;
    }
    return n;
}
*/

/* Exercicio 5 - corretos
void insertOrd (LInt *l, int x){
    LInt aux;
    while(*l && (*l)->valor<x) l=&((*l)->prox);
    aux = malloc(sizeof(struct lligada));
    aux->valor = x;
    aux->prox = *l;
    *l = aux;
}
*/

/* Exercicio 4 - correto REVER
LInt reverseL (LInt l){
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
*/

/* Exercicio 3 - correto
void imprimeL (LInt l){
	while(l != NULL) {
		printf("%d\n",l->valor);
		l=l->prox;
	}	
}
*/

/* Exerericio 2 - correto
void freeL (LInt l){
	LInt aux;
	aux = l;
	while (l){
		l=l->prox;
		free aux;
		aux = l;
	}
}
*/

/* Exercicio 1 - correto 
int length (LInt l){
	int n=1;
	if (!l) n=0;
	else while (l->prox){
	    n++;
		l=l->prox;
	} 
	return n;
}
*/