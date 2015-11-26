#include <stdio.h>
#include <cstdlib>
#include <iostream>
#define N 9
using namespace std;
 
void binaryRhomb(int A[][N]){    
     
     int i,St,En,Mi,key,x,y,suspect,j,fin, e, hit, temphit;
     
     do{
         e=0;
         hit=0;
         temphit=0;
         
         St=1;
         fin=((N*N)/2)+1;
         En=((N*N)/2)+1;
         Mi=(N*N/4)+1;
     
     
     
         printf("The key you want to search: ");
         scanf("%d",&key);
         printf("\n");
     
         if(En==key){
               x=N/2;
               y=N/2;
               printf("The key was found at the position: (%d,%d).\n\n",x,y);
               St=En+1;
               hit=1;
         }

         while(St<=En){
           j=1;
           for (e=0; e<=N/2-1; e++){  
               
               if(temphit==0){
                 for (i=N/2; i>=e; i--){ 
                       if (j==Mi){
                           suspect=A[i][N/2-i+e];
                           x=i;
                           y= N/2-i+e;
                           temphit=1;
                           break;}
                       j++;
                 }
               }
               if(temphit==0){
                 for(i=1+e; i<=N/2-1; i++){
                       if (j==Mi){
                           suspect=A[i][N/2+i-e];
                           x=i;
                           y= N/2+i-e;
                           temphit=1;
                           break;}
                       j++;
                 }
               }
               if(temphit==0){ 
                 for(i=N/2; i<=N-1-e; i++){
                        if (j==Mi){
                           suspect=A[i][N+N/2-1-i-e];
                           x=i;
                           y= N+N/2-1-i-e;
                           temphit=1;
                           break;}
                       j++;
                 }
               }
               if(temphit==0){   
                 for(i=N-2-e; i>=N/2+1;i--){
                       A[i][i-N/2+e]=j;
                       if (j==Mi){
                           suspect=A[i][i-N/2+e];
                           x=i;
                           y= i-N/2+e;
                           temphit=1;
                           break;}
                       j++;
                 }
               }
           }
         if (suspect==key){
                  hit=1;
                  printf("The key was found at the position: (%d,%d).\n\n",x,y);
                  St=En+1;}
         else if (suspect<key  && key<=A[N/2][N/2]){
                  St=Mi;
                  Mi=(En+St)/2;
                  temphit=0;}
         else if (suspect>key && key<=A[N/2][N/2]){
                  En=Mi;
                  Mi=En/2;
                  temphit=0;}
         else
                  St=En+1;
         }
         if (hit==0)
            printf("The key doesn't exist in the table.\n\n");
        
     }while(1);
 
}
 

void fillzeros(int A[][N], int M) {
     
     int i,j;
     
     for (i=0; i<=M-1; i++)
          for (j=0; j<=M-1; j++)
          A[i][j]=0;
 
}

void Rhomb(int A[][N], int M){    
     
     int i,j;
     int e=0;
     int k=1;
     
     for (e=0; e<=M/2-1; e++){  
         for (i=M/2; i>=e; i--){
              A[i][M/2-i+e]=k;
              k++;}
         for(i=1+e; i<=M/2-1; i++){ 
              A[i][M/2+i-e]=k;
              k++;}
         for(i=M/2; i<=M-1-e; i++){       
              A[i][M+M/2-1-i-e]=k;
              k++;}
         for(i=M-2-e; i>=M/2+1;i--){  
              A[i][i-M/2+e]=k;
              k++;}
         }
     A[M/2][M/2]=k;
 
}

void disp(int A[][N], int M){
     
     int i,j;
     
     printf("The generated table is the following: \n");
     for (i=0; i<=M-1; i++){
          for (j=0; j<=M-1; j++){
              printf("%d\t",A[i][j]);
          }
          printf("\n\n");
     }
}
 
int main(int argc, char *argv[]){
    
    int M=N;
    int A[N][N];
    fillzeros(A,M);
 
    Rhomb(A,M);
 
    disp(A,M);
    binaryRhomb(A);
    int i,j;
    system("PAUSE");
    return EXIT_SUCCESS;
}
