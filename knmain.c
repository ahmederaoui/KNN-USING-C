#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "knn.h"
#define N 141



int main (){
    tiris *New;
    int K;
    int i,j,k;
    FILE * file;
    file=fopen("IRIS.csv","r");
    float G[5];
    char *line=NULL;
    char *token;
    tiris *dataset = malloc(N*sizeof(tiris));
    size_t len=0;
    if (file==NULL)
        exit(1);
    for(i=0;i<N;i++){
        getline(&line,&len,file);
        token=strtok(line,",");
        for(j=0;j<5;j++){
            G[j]=atof(token);
            token= strtok (NULL,",") ;
        }
        dataset[i].slenght = G[0];
        dataset[i].swidth = G[1];
        dataset[i].plenght = G[2];
        dataset[i].pwidth = G[3];
        dataset[i].classe = G[4]; 
    
    }
    printf("veuillez entrer k le nobre des proche voisins qu'on va les calculer la ditance :");
    scanf("%d",&k);
    saisir(New);
    tdistance *T=malloc(N*sizeof(tdistance));
    distance(dataset,T,New,k);
    afficher(T,k);
    
    
    

    return 0 ;
}
