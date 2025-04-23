//still buggy

#include<stdio.h>

void firstFit(int n, int m, int holes[], int processes[], int allocation[]) {
    for (int i = 0; i < m; i++) {
        allocation[i] = -1; // Initialize allocation array
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (holes[j] >= processes[i] && allocation[i] == -1) {
                allocation[i] = j;
                holes[j] -= processes[i];
                break; // Move to the next process once allocated
            }
        }
    }
}

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void ascending(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void descending(int arr[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j]<arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void bestFit(int holes[], int processes[], int allocation[], int m, int n){
    for(int i=0;i<m;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<m;i++){
        ascending(holes, n);
        for(int j=0;j<n;j++){
            if(holes[j]>processes[i] && allocation[i]==-1){
                allocation[i]=holes[j];
                holes[j]-=processes[i];
            }
        }
    }
}

int main() {
    int n, m; // Number of holes and processes
    printf("Enter the number of holes and processes: ");
    scanf("%d%d", &n, &m);

    int holes[100];
    int processes[100];
    int allocation[100];

    printf("Enter holes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &holes[i]);
    }

    printf("Enter processes: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &processes[i]);
    }

    // Call the first-fit allocation function
    //firstFit(n, m, holes, processes, allocation);



    // Results
    for (int i = 0; i < m; i++) {
        if (allocation[i] == -1) {
            printf("Process %d was not allotted\n", i);
        } else {
            printf("Process %d was allotted to hole %d\n", i, allocation[i]);
        }
    }

    return 0;
}
