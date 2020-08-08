//Parte A
typedef struct slist {int valor;struct slist *prox;} *LInt;
typedef struct nodo {int valor;struct nodo *esq, *dir;} *ABin;
//1
int limpaEspacos (char t[]){
	int r=0,i;
	for(i=0; t[i] != '\0'; i++){
		t[r] = t[i];
		if(t[i] != ' ' || t[i+1] != ' ') r++;
	}
	t[r] = '\0';
	return r;
}

//2
void transposta (int N, float m [N][N]){
	int i,j;
	float aux;
	for(i=0; i<N; i++){
		for(j=i; j<N; j++){
			aux = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = aux; 
		}
	}
}

//3
LInt clone (LInt l){
	LInt inicio=NULL, *nodo;
	nodo = &inicio;
	while(l){
		*nodo = malloc(sizeof(struct lligada));
		(*nodo)->valor = l->valor;
		nodo = &((*nodo)->prox);
		l = l->prox;
	}
	*nodo = NULL;
	return inicio;
}

//4
int nivelV (ABin a, int n, int v[]){
	int c=0;
	if(a){
	    if(n==1){
		    v[c] = a->valor;
		    c++;
	    }
    	else{
    		c += nivelV(a->esq,n-1,v+c);
    		c += nivelV(a->dir,n-1,v+c);
        }	
	}
	return c;
}

//5
void removeMaiorA (ABin *a){
    ABin aux;
	while((*a)->dir) a = &((*a)->dir);
	aux = (*a)->esq;
	free (*a);
	*a = aux;
}

//Parte B
typedef struct chunk {
	int vs [MAXc];
	struct chunk *prox;
} *CList;

typedef struct stackC {
	CList valores;
	int sp;
} StackC;
//1
int push (StackC *s, int x){
	int r=0;
	if(s->sp == MAXc){
		CList novo = malloc(sizeof(struct chunk));
		novo->vs[0] =  x;
		novo->prox = s->valores;
		s->valores = novo;
		s->sp = 1;
	}
	else {
		s->(valores->vs[(s->sp]) = x;
		s->sp ++;
	}
	return r;
}

//2
int pop (StackC *s, int *x){
	int r=0;
	CList aux;
	if(s->valores){
		if(s->sp == 1){
			aux = s->(valores->prox);
			free(s->valores);
			s->valores = aux;
			sp = MAXc;
		}
		else s->sp --;
	}
	else r=1;
	return r;
}