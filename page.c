#include<stdio.h>
#include<stdbool.h>

bool inside(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int fifo(int ref[], int pref, int fsize) {
    int curr[fsize];
    for (int i = 0; i < fsize; i++) curr[i] = -1;

    int faults = 0;
    int pointer = 0;

    for (int i = 0; i < pref; i++) {
        if (!inside(curr, fsize, ref[i])) {
            curr[pointer] = ref[i];
            pointer = (pointer + 1) % fsize;
            faults++;
        }
    }
    return faults;
}

int fifo(int ref[], int reflen, int framesize){
    int faults=0;
    int curr[framesize];
    for(int i=0;i<framesize;i++){
        curr[i]=-1;
    }
    int pointer=0;
    for(int i=0;i<reflen;i++){
        if(inside(curr, framesize, ref[i])){
            continue;
        }
        curr[pointer]=ref[i];
        pointer=(pointer+1)%framesize;
    }
}


void lru(){
    
}

void optimal(){

}

int main(){
    int pref;
    int fsize;
    printf("enter the number of page references and frame size: ");
    scanf("%d%d",&pref, &fsize);
    int ref[100];
    for(int i=0;i<pref;i++){
        scanf("%d",&ref[i]);
    }
    int t=fifo(ref,pref,fsize);
    printf("The number of page faults is: %d",t);
}