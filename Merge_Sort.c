#include <stdio.h>
#include <math.h>

void merge(int [], int, int, int);
void mergeSort(int [],int, int);

int main()
{
   int n,arr[100],i;
   printf("Enter size of array: ");
   scanf("%d",&n);

   printf("Enter array: ");
   for(i=1; i<=n; i++)
   {
       scanf("%d",&arr[i]);
   }

   mergeSort(arr, 1, n);

   for(i=1; i<=n; i++)
   {
       printf("%d ",arr[i]);
   }
}

void mergeSort(int arr[], int start, int end)
{
    int mid;
    if(start < end)
    {
        mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid-start+1;
    int n2 = end - mid;

    int a1[100],a2[100],i,j,k;

    for(i=1; i<=n1; i++)
    {
        a1[i] = arr[start+i-1];
    }

    for(j=1; j<=n2; j++)
    {
        a2[j] = arr[mid+j];
    }

    a1[n1+1] = INFINITY;
    a2[n2+1] = INFINITY;

    i = 1;
    j = 1;

    for(k=start; k<=end; k++)
    {
        if(a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
        }
    }
}
