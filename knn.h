#ifndef _knn
    #define _knn
        typedef struct Tiris{
            float slenght,swidth,plenght,pwidth ;
            int classe;
        }tiris;
    
        typedef struct Tdistance{
            float dis ;
            int classe;
            int nligne;

        } tdistance;

        void saisir(tiris*);
        void distance(tiris* ,tdistance* ,tiris* , int );
        void  afficher(tdistance* ,int );
    



#endif