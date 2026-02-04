#include<stdio.h>
#include<stdlib.h>
#define SIZE 50
typedef struct{
	int id;
	char pName[20];
	int priority;
	float BT;
}Process;
int count=0;
void Add(Process table[],int n){
	printf("Enter process-%d details\n",count+1);
	printf("Enter Pid\n");
	scanf("%d",&table[count].id);
	printf("Enter process name\n");
	scanf("%s",table[count].pName);
	printf("Enter priority\n");
	scanf("%d",&table[count].priority);
	printf("Enter BT\n");
	scanf("%f",&table[count].BT);
	count++;
}
void Display(Process table[],int n){
	int i;
	for(i=0;i<count;i++)
	{
	printf("\nprocess-%d ",i+1);
	printf("Pid=%d\tPname=%s\tpriority=%d\tBT=%f\n",
	table[i].id,table[i].pName,table[i].priority,table[i].BT);
    }
}
void BubbleSortByPriority(Process table[],int n){
	int i,j;
	for(i=0;i<count;i++)
	{
		for(j=0;j<count-i-1;j++)
		{
			if(table[j].priority>table[j+1].priority)
			{
				int temp=table[j].priority;
				table[j].priority=table[j+1].priority;
				table[j+1].priority=temp;
			}
		}
	}
	
	
}
void InsertionSortByPid(Process table[],int n){
		int i,j,key;
	for(i=1;i<n;i++)
	{
        key=arr[i];
		j=i-1;
	
	while(j>=0 && (arr[j]>key))
	{
		arr[j+1]=arr[j];
		j--;
	}
	arr[j+1]=key;
}
void shellSortByBT(Process table[],int n){
	int i,j,gap,key;
	for(int gap=n;gap>=1;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			key = arr[i];
			j = i-gap;
			while(gap>=0 && (arr[j]>key))
			{
				arr[j+gap] = arr[j];
				j = j-gap;
			}
			arr[j+1]=key;
		}
	}
}
void linearSearchByPid(Process table[],int n,int key){
	int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }
}
void BinarySearchByPid(Process table,int n,int key){
	 int low = 0, high = n - 1, mid;
    int found = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        } 
        else if (arr[mid] < key) {
            low = mid + 1;
        } 
         else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }
}
main(){
 Process table[SIZE];
	while(1){
	printf("1.Add\n2.Display\n3.BubbleSortByPriority\n4.InsertionSortByPid\n5.shellSortByBT\n6.linearSearchByPid\n7.BinarysearchByPid\n8.exit\n");
	int choice;
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1:Add(table,SIZE);break;
    	case 2:Display(table,SIZE);break;
    	case 3:BubbleSortByPriority(table,SIZE);break;
    	case 4:InsertionSortByPid();break;
    	case 5:shellSortByBT();break;
    	case 6:linearSearchByPid();break;
    	case 7:printf("come here after sorting");
		       BinarySearchByPid();break;
	    case 8:exit(0);break;	
	}
}
    
	
}
