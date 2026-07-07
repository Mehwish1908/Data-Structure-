#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[100],n,i,pos,value,choice,found;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    if(n<1||n>100)
    {
        printf("Invalid number of elements! Must be between 1 and 100.\n");
        return 0;
    }
    printf("Enter elements: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Traversal\n2. Insertion\n3. Deletion\n4. Searching\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Array elements are: ");
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
                break;
            case 2:
                if(n>=100)
                {
                    printf("Array is full! Cannot insert.\n");
                    break;
                }
                printf("Enter position (1-%d) and value: ",n+1);
                scanf("%d %d",&pos,&value);
                if(pos<1||pos>n+1)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    for(i=n;i>=pos;i--)
                    {
                        arr[i]=arr[i-1];
                    }
                    arr[pos-1]=value;
                    n++;
                    printf("Insertion successful.\n");
                }
                printf("Array after insertion: ");
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
                break;
            case 3:
                printf("Enter position (1-%d) to delete: ",n);
                scanf("%d",&pos);
                if(pos<1||pos>n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    for(i=pos-1;i<n-1;i++)
                    {
                        arr[i]=arr[i+1];
                    }
                    n--;
                    printf("Deletion successful.\n");
                }
                printf("Array after deletion: ");
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d",&value);
                found=0;
                for(i=0;i<n;i++)
                {
                    if(arr[i]==value)
                    {
                        printf("Element found at position %d\n",i+1);
                        found=1;
                        break;
                    }
                }
                if(found==0)
                    printf("Element not found\n");
                printf("Current array: ");
                for(i=0;i<n;i++)
                {
                    printf("%d ",arr[i]);
                }
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    while(choice!=5);
    return 0;
}
