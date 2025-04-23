#include<stdio.h>
#include<stdbool.h>

bool inside(int key, int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int optimal(int references[], int n, int framesize){
    int faults=0;
    int curr[framesize];
    for(int i=0;i<framesize;i++){
        curr[i]=-1;
    }
    int i=0;
    for(i;i<n;i++){
        if(inside(references[i],curr,framesize)){
            continue;
        }
        bool arr[framesize];
        bool placed = false;
        for(int k=0;k<framesize;k++){
            if(curr[k]==-1){
                curr[k]=references[i];
                placed=true;
                break;
            }
        }
        if(!placed) continue;
        int farthest=-1;
        int indextoreplace=-1;
        for(int j=0;j<framesize;j++){
            int nextuse=-1;
            for(int k=i;k<n;k++){
                if(references[k]==curr[j]){
                    nextuse=k;
                    break;
                }
            }
            if(nextuse==-1){
                indextoreplace=j;
                break;
            }
            if(nextuse>farthest){
                farthest=nextuse;
            }
        }
        curr[indextoreplace]=references[i];
        faults++;
    }
    return faults;
}

int main(){
    int numberofreferences;
    int framesize;
    printf("Enter number of pages references and frame size: ");
    scanf("%d%d",&numberofreferences,&framesize);
    printf("Enter page References: ");
    int references[numberofreferences];
    for(int i=0;i<numberofreferences;i++){
        scanf("%d",&references[i]);
    }
    printf("%d",optimal(references,numberofreferences,framesize));
}