#include<stdio.h>
#include<stdlib.h>

void scan(int services[], int n, int currhead) {
    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (services[j] > services[j + 1]) {
                int temp = services[j];
                services[j] = services[j + 1];
                services[j + 1] = temp;
            }
        }
    }

    int i = 0;
    for (i; i < n; i++) {
        if (services[i] >= currhead) {
            break;
        }
    }

    int left[100];
    int right[100];
    for (int j = 0; j < i; j++) {
        left[j] = services[j];
    }
    for (int j = 0; j < n - i; j++) {
        right[j] = services[j + i];
    }

    // Assuming right first
    int moved=0;
    for (int k = 0; k < n - i; k++) {
        printf("%d\t", right[k]);
    }
    for (int k = i - 1; k >= 0; k--) {
        printf("%d\t", left[k]);
    }
}

void cscan(int services[], int n, int currhead){
    // Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (services[j] > services[j + 1]) {
                int temp = services[j];
                services[j] = services[j + 1];
                services[j + 1] = temp;
            }
        }
    }
    int i=0;
    for(i;i<n;i++){
        if(services[i]>currhead){
            break;
        }
    }
    int left[100];
    int right[100];
    for(int j=0;j<i;j++){
        left[j]=services[j];
    }
    for(int j=i;j<n;j++){
        right[j-i]=services[j];
    }
    //right first
    int moved=0;
    for(int k=0;k<i;k++){
        printf("%d\t",right[k]);
        if(k==i-1){
            continue;
        }
        moved+=abs(right[k+1]-right[k]);
    }
    moved+=abs(199-right[i-1]);
    moved+=abs(0-left[0]);
    for(int k=0;k<n-i;k++){
        printf("%d\t", left[k]);
        if(k==n-i-1){
            continue;
        }
        moved+=abs(left[k+1]-left[k]);
    }
    printf("\n the head move distance is :%d\n",moved);
}

int main() {
    int n;
    printf("Enter number of services: ");
    scanf("%d", &n);
    int services[n];
    printf("Enter the services: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &services[i]);
    }

    int currhead;
    printf("Enter the current head position: ");
    scanf("%d", &currhead);

    scan(services, n, currhead);
    printf("\n");
    cscan(services, n, currhead);

    return 0;
}
