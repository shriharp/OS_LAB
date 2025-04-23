#include<stdio.h>
#include<stdbool.h>

void matrixprint(int arr[][3],int m,int n){
    for(int i=0;i<m;i++){
        printf("p%d\t",i);
        for(int j=0;j<n;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    int total[3];
    printf("enter maximum number of each resource type: ");
    scanf("%d%d%d",&total[0],&total[1],&total[2]);
    printf("enter number of processes: ");
    int max[100][3], needed[100][3], allocated[100][3], avail[3];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter maximum resources for process p%d: ",i);
        scanf("%d%d%d", &max[i][0], &max[i][1], &max[i][2]);
        printf("enter the allocated resources for process p%d: ", i);
        scanf("%d%d%d",&allocated[i][0],&allocated[i][1],&allocated[i][2]);
        needed[i][0]=max[i][0]-allocated[i][0];
        needed[i][1]=max[i][1]-allocated[i][1];
        needed[i][2]=max[i][2]-allocated[i][2];
    }
    printf("The maximum available resources:\n");
    matrixprint(max,n,3);
    printf("The allocated resources are:\n");
    matrixprint(allocated,n,3);
    printf("The need for each process is:\n");
    matrixprint(needed,n,3);
    int sum[3]={0,0,0};
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            sum[i]+=allocated[j][i];
        }
    }
    for(int i=0;i<3;i++){
        avail[i]=total[i]-sum[i];
    }
    printf("the available resources are:\t%d\t%d\t%d", avail[0],avail[1],avail[2]);

    //start of bankers algorithm
    bool finished[n];
    for(int i=0;i<n;i++){
        finished[i]=false;
    }

    int sequence[n];

    int done=0;
    while(done<n){
        int checker=0;
        for(int i=0;i<n;i++){
            if(!finished[i] && needed[i][0]<=avail[0] && needed[i][1]<=avail[1] && needed[i][2]<=avail[2]){
                avail[0]+=allocated[i][0];
                avail[1]+=allocated[i][1];
                avail[2]+=allocated[i][2];
                sequence[done]=i;
                finished[i]=true;
                done++;
                checker++;
            }
        }
        if(checker==0){
            break;
        }
    }
    if(done<n){
        printf("\nunsafe state");
    }else{
        printf("\nsafe state\nsafe sequence:");
        for(int i=0;i<n;i++){
            printf("\t%d",sequence[i]);
        }
    }
    
}