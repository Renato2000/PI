/* Exercicio 40 - correto
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
*/

/* Exercicio 25 - correto
int limpaEspacos (char texto[]) {
    int r=0,i;
    for(i=0; texto[i] != '\0'; i++){
        texto[r] = texto[i];
        if(texto[i] != ' ' || texto[i+1] != ' ') r++;
    }
    texto[r] = '\0';
    return r;
}
*/