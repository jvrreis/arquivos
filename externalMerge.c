#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#define N 8

struct_ENDEREÇO{
    char logradouro[72];
    char bairro[72];
    char cidade[72];
    char uf[72];
    char sigla[2];
    char cep[8];
    char lixo[2];
}

int compara(const void *e1, const void *e2){
   return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}


void intercala(char* arq1, char* arq2, char *saida){
    FILE *a, *b, *saida;
	Endereco ea, eb;

	a = fopen("arq1","r");
	b = fopen("arq2","r");
	saida = fopen("saida","b");

	fread(&ea,sizeof(Endereco),1,a);
	fread(&eb,sizeof(Endereco),1,b);

	while(!feof(a) && !feof(b))
	{
		if(compara(&ea,&eb)<0)
		{
			fwrite(&ea,sizeof(Endereco),1,saida);
			fread(&ea,sizeof(Endereco),1,a);
		}
		else
		{
			fwrite(&eb,sizeof(Endereco),1,saida);
			fread(&eb,sizeof(Endereco),1,b);
		}
	}

	while(!feof(a))
	{
		fwrite(&ea,sizeof(Endereco),1,saida);
		fread(&ea,sizeof(Endereco),1,a);		
	}
	while(!feof(b))
	{
		fwrite(&eb,sizeof(Endereco),1,saida);
		fread(&eb,sizeof(Endereco),1,b);		
	}

	fclose(a);
	fclose(b);
	fclose(saida);
}


int main(int argc, char** arvg){
    FILE *f;
    Endereco *e, *e2;
    int h, hreg, qtd, ultimo_qtd, espaco, espaco2, i, n, blocos, c, a;
    
    f = fopen("cep.dat", "rb");
    fseek(f,0,SEEK_END);
    h = ftell(f);
    hreg = h/sizeof(Endereço);
    qtd = sizeof(Endereço)/N;
    ultimo_qtd = qtd + sizeof(Endereço)%n;
    espaco = (Endereço*) malloc(qtd*sizeof(Endereço));
    espaco2 = (Endereço*) malloc(ultimo_qtd*sizeof(Endereço));
    rewind(f);

    for(i = 0; i<=N; i++){
        printf(strcep, "cep%d.dat",i);
        FILE*f = fopen(strcep,"w");
        if(i<N){
            fread(espaco,sizeof(Endereço),ultimo_qtd,f);
            qsort(espaco, qtd, sizeof(Endereço), compara);
            fwrite(espaco, sizeof(Endereço),ultimo_qtd,f);
        }
        else{
            fread(espaco2, sizeof(Endereço), ultimo_qtd,f);
            qsort(espaco2, ultimo_qtd, sizeof(Endereço), compara);
            fwrite(espaco2, sizeof(Endereço), ultimo_qtd, f)
        }
        fclose(f);
    }
    
    n = N;
    blocos = n;
    c = 1;

    while(n>=2){
        a = 1;
        while(c<= blocos){
            printf(arq1, "cep%d.dat",c);
            printf(arq2,"cep%d.dat",c+1);
            printf(saida,"cep%d.dat",blocos+a);
            intercala(arq1,arq2,saida);
            remove(arq1);
            remove(arq2);
            a++;
            c+=2;
        }
        n = n/2;
        blocos = blocos + n;
    }


    char nome[10];
    printf(nome,"cep%d.dat");
    rename(nome,"cep_ordenado.dat");

    fclose(f);
}