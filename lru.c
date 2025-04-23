#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int page;
    int lastUsed;
} page;



int lru(int reference[], int n, int framesize){
    page curr[framesize];
    for(int i=0;i<framesize;i++){
        curr[framesize].page=-1;
    }
    for(int i=0;i<n;i++){
        
    }
}

int main(){
    int numref;
    printf("enter number of page references: ");
    scanf("%d",&numref);
    page pageref[numref];
    for(int i=0;i<numref;i++){
        scanf("%d",pageref[i].page);
    }
    int framesize;
    printf("enter the frame size: ");
    scanf("%d",&framesize);
    lru(pageref, numref, framesize);
}