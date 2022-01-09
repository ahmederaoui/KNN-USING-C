#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "knn.h"
#define N 141
void saisir(tiris *new){
    puts("entrer les données de la nouvelle cas\n");
    printf("Sepal length de l'iris\n");
    scanf("%f",&new->slenght);
    printf("Sepal width de l'iris\n");
    scanf("%f",&new->swidth);
    printf("Petal length de l'iris\n");
    scanf("%f",&new->plenght);
    printf("Petal width de l'iris\n");
    scanf("%f",&new->pwidth);
}
void distance(tiris *dataset,tdistance *T,tiris *new, int l){
    
    
    int i,j;
    tdistance min;
    for(i=0;i<N;i++){
        T[i].dis=sqrt(((new->slenght-dataset[i].slenght)*((*new).slenght-dataset[i].slenght))
                +((new->swidth-dataset[i].swidth)*(new->swidth-dataset[i].swidth))
                +((new->plenght-dataset[i].plenght)*(new->plenght-dataset[i].plenght))
                +((new->pwidth-dataset[i].pwidth)*(new->pwidth-dataset[i].pwidth)));
        
        T[i].classe=dataset[i].classe;
        T[i].nligne=i+1;
    }
    for(i=0;i<N;i++){
        for(j=i;j<N;j++){
                if(T[j].dis<T[i].dis){
                    min=T[j];
                    T[j]=T[i];
                    T[i]=min;

                }
        
        
        
        }
    }
      
    /*for(i=l;i<N;i++){
        
        T[i].dis=sqrt(((new->slenght-dataset[i].slenght)*((*new).slenght-dataset[i].slenght))
                +((new->swidth-dataset[i].swidth)*(new->swidth-dataset[i].swidth))
                +((new->plenght-dataset[i].plenght)*(new->plenght-dataset[i].plenght))
                +((new->pwidth-dataset[i].pwidth)*(new->pwidth-dataset[i].pwidth)));
        max=T[0];
        for(j=0;j<l;j++){
            if(max.dis<T[j].dis){
                max=T[j];
                T[j]=T[0];
                T[0]=max;
            }
                
                
        }
        
        if(T[i].dis<=max.dis){
            T[0].dis=T[i].dis;
            T[0].classe=dataset[i].classe;
            T[0].nligne=i+1;
        } 
                  
        
    }*/

}

    

void  afficher(tdistance *T,int l){
    int s=0,v=0,g=0 ;
    int i ;
    printf("affchage des %d plus proches voisins de la nouvelle cas\n",l) ;
    puts("numéro_de_ligne    la_distance      la_classe\n");
    for(i=0;i<l;i++){
        printf("      %d          %f           %d\n",T[i].nligne,T[i].dis,T[i].classe) ;
    }
    for(i=0;i<l;i++){
        if(T[i].classe==2)
            s+=1;
        if(T[i].classe==0)
            v+=1;
        if(T[i].classe==1)
            g+=1;    
    }
    if(s<=v && g<=v)
        printf("l'iris est de type Versicolour");
    if(v<=s && g<=s)
        printf("l'iris est de type Setosa");
    if(v<=g && s<=g)
        printf("l'iris est de type Virginica");
        
        
}






    


