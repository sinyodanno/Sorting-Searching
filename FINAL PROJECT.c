#include<stdio.h>
#include<math.h>
#include<time.h>

/*function of insertion sort*/
void insertion_sort(int n, int *num){
	int i, j, temp;
	
	for(i=1; i<n; i++){
		j = i;
		while(num[j]<num[j-1] && j>0){
			/*swap*/
			temp = num[j];
			num[j] = num[j-1];
			num[j-1] = temp;
			
			j--;
		}
	}
}

/*function of bubble sort*/
void bubble_sort(int n, int *num){
	int i, j, temp;
	
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(num[j]>num[j+1]){
				/*swap*/
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
}

/*function for partition in quick sort*/
int partition(int *num, int low, int high){
	int i, j, pivot, temp;
	
	i = low-1;
	pivot = num[high];
	
	for(j=low; j<=high; j++){
		if(num[j]<=pivot){
			i++;
			temp = num[j];
			num[j] = num[i];
			num[i] = temp;
		}
	}
	return i;
}

/*function of quick sort*/
void quick_sort(int *num, int low, int high){
	int pivot;
	
	if(low<high){
		/*function calling*/
		pivot = partition(num, low, high);
		
		/*recursion for the left side
		numbers (smaller than pivot)*/
		quick_sort(num, low, pivot-1);
		
		/*recursion for the right side
		numbers (greater than pivot)*/
		quick_sort(num, pivot+1, high);
	}
}

/*function of sequential search*/
int sequential_search(int n, int *num, int searched){
	/*looping for returning the index of 
	the searched number by checking the numbers
	one by one*/
	int i;
	for(i=0; i<n; i++){
		if(searched==num[i]){
			return i+1;
		}
	}
	
	return -1;
}

/*function of binary search*/
int binary_search(int n, int *angka, int searched){
	int low, /*lower limit*/
		high, /*upper limit*/
		middle; /*middle index*/
	
	low = 0; /*lower limit starts from index-0*/
	high = n; /*upper limit starts from last index*/
	
	if(searched==angka[low]){
		return 0;
	} else if(searched==angka[high]){
		return n-1;
	} else {
		while(searched>angka[low] && searched<angka[high]){
			/*calculation of middle value*/
			middle = (low+high)/2;
			
			if(searched==angka[middle]){
				/*the searched number will always be in the middle value*/
				return middle+1;
			}
			
			/*condition to determine whether the "start" or "finish"
			variable that shifts next to the middle value by checking whether the
			searched number is greater or smaller than the middle value*/
			if(searched>angka[low] && searched<angka[middle]){
				high = middle-1;
			} else if(searched>angka[middle] && searched<angka[high]){
				low = middle+1;
			}
		}
	}
}

/*function of jump search*/
int jump_search(int n, int *angka, int searched){
	int saved1, /*lower limit*/
		saved2, /*upper limit*/
		jump; /*range of jump*/
	
	jump = sqrt(n); /*calculation for range of jump*/
	
	saved1 = 0; /*lower limit starts from index 0*/
	saved2 = jump; /*upper limit starts from the
					 index of the first jump*/
	
	/*as long as the searched number is greater 
	than the upper limit, the lower limit will
	move to the upper limit and the upper limit
	will move to the next index of jump*/
	while(saved2<n && searched>angka[saved2]){
		saved1 += jump;
		saved2 += jump;
		
		/*if the last jump is passing the last index, 
		then the last index will be the upper limit*/
		if(saved2>n){
			saved2 = n;
		}
	}
	
	/*when the searched number is smaller than
	the upper limit, the looping will going backwards.
	it starts from the upper limit to the lower limit
	to find the searched number. if the searched number
	is not found, it will return the value of -1.*/
	int i;
	for(i=saved2; i>saved1; --i){
		if(searched==angka[i]){
			return i+1;
		}
	}
	
	return 0;
}

/*function to ask if the user wants to repeat*/
void finishOrNot(){
	int option;
	printf("\nFinish? \n1. Yes \n2. No \n");
	scanf("%d", &option);
	
	if(option==1){
		printf("\nTHANK YOU!");
	} else if(option==2){
		printf("\n");
		main();
	} else {
		finishOrNot(option);
	}
}

int main(){
	int sortingOption, searchingOption, n, finish, wanted, result;
	float time, timeInSecond;
	
	printf("---FINAL PROJECT---");
	
	/*input of the array size (amount of the numbers)*/
	printf("\nHow many numbers do you want to be proceed? ");
	scanf("%d", &n);
	
	int arr[n];
	
	int i;
	for(i=0; i<n; i++){
		arr[i] = rand();
	}
	
	int j;
	for(j=0; j<n; j++){
		printf("\nNumber-%d = %d", j+1, arr[j]);
	}
	
	/*Display of the available options for sorting techniques*/
	printf("\n\nChoose the technique of sorting to sorts the numbers!");
	printf("\nAvailable options:");
	printf("\n1. Insertion Sort\n");
	printf("2. Bubble Sort\n");
	printf("3. Quick Sort\n");
	
	/*input of the sorting techniques option*/
	printf("\nOption : ");
	scanf("%d", &sortingOption);
	
	/*condition for the chosen technique of sorting*/
	if(sortingOption==1){ /*INSERTION SORT*/
		printf("\nRandom numbers that had been sorted");
		
		time = clock(); /*clock start*/
		insertion_sort(n, &arr[0]); /*function calling*/
		time = clock()-time; /*clock finish*/
		
		timeInSecond = time / CLOCKS_PER_SEC;
		
		int k;
		for(k=0; k<n; k++){
			printf("\nNumber-%d = %d", k+1, arr[k]);
		}
		
		printf("\nTime needed to sort the numbers : %.4lf second", timeInSecond);
	} else if(sortingOption==2){ /*BUBBLE SORT*/
		printf("\nRandom numbers that had been sorted");
		
		time = clock(); /*clock start*/
		bubble_sort(n, &arr[0]); /*function calling*/
		time = clock()-time; /*clock finish*/
		
		timeInSecond = time / CLOCKS_PER_SEC;
		
		int k;
		for(k=0; k<n; k++){
			printf("\nNumber-%d = %d", k+1, arr[k]);
		}
		
		printf("\nTime needed to sort the numbers : %.4lf second", timeInSecond);
	} else if(sortingOption==3){ /*QUICK SORT*/
		printf("\nRandom numbers that had been sorted");
		
		time = clock(); /*clock start*/
		bubble_sort(n, &arr[0]); /*function calling*/
		time = clock()-time; /*clock finish*/
		
		timeInSecond = time / CLOCKS_PER_SEC;
		
		int k;
		for(k=0; k<n; k++){
			printf("\nNumber-%d = %d", k+1, arr[k]);
		}
		
		printf("\nTime needed to sort the numbers : %.4lf second", timeInSecond);
	} else {
		printf("\nPlease choose the right option!\n\n");
		main();
	}
	
	/*input of wanted number*/
	printf("\n\nWhat number you are searching for? ");
	scanf("%d", &wanted);
	
	/*display of the availabe options for saearching techniques*/
	printf("\n\nChoose the technique of searching to search the number!");
	printf("\nAvailable options:");
	printf("\n1. Sequential Search\n");
	printf("2. Binary Search\n");
	printf("3. Jump Search\n");
	
	/*input of the searching techniques option*/
	printf("\nOption : ");
	scanf("%d", &searchingOption);
	
	if(searchingOption==1){ /*SEQUENTIAL SEARCH*/
		time = clock();
		result = sequential_search(n, &arr[0], wanted);
		time = clock()-time;
		
		timeInSecond = time / CLOCKS_PER_SEC;
		
		printf("\n=> %d is in index %d", wanted, result);
		printf("\nTime needed to searched the number : %.4lf second", time);
	} else if(searchingOption==2){ /*BINARY SEARCH*/
		time = clock();
		result = binary_search(n, &arr[0], wanted);
		time = clock()-time;
		
		timeInSecond = time / CLOCKS_PER_SEC;
		
		printf("\n=> %d is in index %d", wanted, result);
		printf("\nTime needed to searched the number : %.4lf second", time);
	} else if(searchingOption==3){ /*JUMP SEARCH*/
		time = clock();
		result = jump_search(n, &arr[0], wanted);
		time = clock()-time;
		
		timeInSecond = time / CLOCKS_PER_SEC;
		
		printf("\n=> %d is in index %d", wanted, result);
		printf("\nTime needed to searched the number : %.4lf second", time);
	} else {
		printf("\nChoose the right option!\n");
		main();
	}
	
	printf("\n");
	finishOrNot();
}
