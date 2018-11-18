#include <stdio.h>
#include <stdlib.h>
MAX_SIZE 1000

void printPairs(int arr[], int arr_size, int x) {
	bool hSet[MAX_SIZE] = {0};
	int temp = 0;
	
	for(int i=0; i<arr_size; i++){
		temp = x - arr[i];
		if (temp >=0 && hSet[temp] == 1){
			printf("%d %d\n",arr[i], temp);
		}
		hSet[arr[i]] = 1;
	}
}

int main(){
	int arr[] = {4, 6, 9, 12, 15, 20};
	int x = 21;
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	printPairs(arr, arr_size, x);
	return 0;
}
