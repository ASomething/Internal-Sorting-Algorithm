/*  test.c -- ʵ�ּ��������㷨   */  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>    
//#define MAX (10)  
#define SIZE (6)  
  
int main (void) ;  
int initialize (int * const array, const int size) ;       //��ʼ������

/*  ��������������  */  
void insertionSort (int * const array, const int size) ;  
void binarySort(int * const array, const int size);
void shellSort (int * const array, const int size) ;  
void bubbleSort (int * const array, int size) ;  
void quickSort (int * const array, int left,int right) ; 
void selectSort (int * const array, const int size) ;
void mergeSort (int * const array, const int left, const int right) ;  
 
  
void printArray (const int * const array, const int size,const char *name) ;     //��������������� 

  
int main (void)      //������
{  
	int array[20] ;
	int size ; 
	printf("���Źؼ��ָ�����");
	scanf("%d",&size); 
	printf("������鸳ֵ��");
	initialize (array, size) ;
	int choice;
	printf("��ѡ��Ҫʹ�õ������㷨��\n");
	printf("\n");
	printf("1.ֱ�Ӳ�������(InsertionSort)\n");
	printf("2.�۰��������(BinarySort)\n");
	printf("3.ϣ������(ShellSort)\n");
	printf("4.ð������(BubbleSort)\n");
	printf("5.��������(QuickSort)\n");
	printf("6.��ѡ������(SelectSort)\n");
	printf("7.�鲢����(MergeSort)\n");
	printf("*.��0�˳�\n");
	printf("\n");
l:	printf("�������ѡ��==>:");
	scanf("%d",&choice);
	printf("\n");
	switch(choice)
	{
	   case 0:
		   printf("�˳��ɹ�!\n");
		   break;
	   case 1://ֱ�Ӳ�������
		   {       
				insertionSort (array, size) ;   
				printArray (array, size,"InsertionSort") ; 
				printf("\n");
				goto l;
		   }
       case 2://�۰��������
		   {     
				binarySort (array, size) ;   
				printArray (array, size,"BinarySort") ; 
				printf("\n");
				goto l;
		   }
	   case 3://ϣ������
		   { 
				shellSort (array, size) ;   
				printArray (array, size,"ShellSort") ;
				printf("\n");
				goto l;
		   }
	   case 4://ð������
		   { 
				bubbleSort (array, size) ;  
				printArray (array, size,"BubbleSort") ;
				printf("\n");
				goto l;
		   }
	   case 5://��������
		   { 
				quickSort (array, 0, size-1) ;
				printArray (array, size,"QuickSort") ;
				printf("\n");
				goto l;
		   }  
	   case 6://��ѡ������
		   { 
				selectSort (array, size) ;  
				printArray (array, size,"SelectSort") ;
				printf("\n");
				goto l;
		   }
	   case 7://��·�鲢���� 
		   {

				mergeSort (array, 0, size-1) ;     
				printArray (array, size,"MergeSort") ;
				printf("\n");
				goto l;
		   }
	   default:
		   printf("ָ����������������!\n");
		   printf("\n");
		   goto l;
	}
    return 0 ;  
}  
  
int initialize (int * const array,const int size)  
{  
 
	for(int i=0;i<size;++i)
	{
		scanf("%d",&array[i]);
	}
    
    return 1 ;  
}  
//ֱ�Ӳ�������
void insertionSort (int * const array, const int size)  
{  
    int temp ;  
    int i, j ;  
    for (i = 1; i < size; i++)  
    {  
        temp = array[i] ;  
        for (j = i; j > 0; j--)  
        {  
            if (temp < array[j - 1])  
                array[j] = array[j - 1] ;  
            else  
                break ;  
        }  
        array[j] = temp ;  
    }  
}  
//�۰��������
void binarySort(int * const array, const int size) 
{
    int low, mid, high;
    int temp;
    for (int i = 1; i < size; ++i)
	{
		temp = array[i];
		low = 0;
		high = i-1;
		while (low <= high) 
		{
			mid = (low+high)/2;
			if (array[i] < array[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		for (int j = i - 1; j >= low; --j)
			array[j+1] = array[j];
		array[low] = temp;
     }
}
//ϣ������
void shellSort (int * const array, const int size)  
{  
    int temp ;  
    int p, i, j ;  
  
    for (p = size / 2; p > 0; p /= 2)  
    {  
        for (i = p; i < size; i++)  
        {  
            temp = array[i] ;  
            for (j = i; j >= p; j -= p)  
            {  
                if (temp < array[j - p])  
                    array[j] = array[j - p] ;  
                else  
                    break ;  
            }  
            array[j] = temp ;  
        }  
    }  
}  
//�鲢����  
void mergeSort (int * const array, const int left, const int right)  
{  
    int * temp ;  
    int size, middle, i, j, k ;  
      
    if (left < right)  
    {  
        middle = (left + right) / 2 ;  
        mergeSort (array, left, middle) ;  
        mergeSort (array, middle + 1, right) ;  
        /*  Merge.  */  
        size = right - left + 1 ;  
        temp = (int *) malloc (sizeof (int) * size) ;  
        if (temp==NULL)       //Nothing else��������Ϊ�˷�ֹ��һ�����ٿռ�ʧ�ܣ�
        {  
            puts ("Out of space.") ;  
            return ;  
        }  
        i = left ;  
        j = middle + 1 ;  
        k = 0 ;  
        while (i <= middle && j <= right)  
        {    
            if (array[i] <= array[j])  
                temp[k++] = array[i++] ;  
            else  
                temp[k++] = array[j++] ;  
        }  
        if (i > middle)  
        {  
            while (j <= right)  
                temp[k++] = array[j++] ;  
        }  
        else  
        {  
            while (i <= middle)  
                temp[k++] = array[i++] ;  
        }  
        j = 0 ;  
        for (i = left; i <= right; i++)  
            array[i] = temp[j++] ;  
        free (temp) ;  
    }  
}   
//��������(�Ե�һ���ؼ���Ϊ����) 
void quickSort (int * const array, int left, int right)  
{  
	int temp;
    int i, j, pivot ;  
    if (left < right)  
    {  
        i = left;  
        j = right;  
        pivot = left ;
		temp = array[pivot];
        while(i != j)  
        {  
             
            while (j>i && array[j] > temp)    --j ;
			if(i<j)
			{
                array[i] = array[j];
				++i;
			}
			while (i<j && array[i] <= temp)   ++i ;
			if (i < j)
			{
                array[j] = array[i];
				--j;	
			}  
        }	  
        array[i] = temp ;  
		quickSort (array, left, i-1) ; 
		quickSort (array, i+1, right) ;
	}
}  
//ð������  
void bubbleSort (int * const array, int size)  
{  
    int temp ;  
    int j;  
    int index ;  
    index = 1 ;  
	//int bub_count = 0;
    for (; 1 == index && size > 1; size--)  
    {  
        index = 0 ;  
        for (j = 1; j < size; j++)  
        {  
            if (array[j] < array[j - 1])  
            {  
                index = 1 ;  
                temp = array[j] ;  
                array[j] = array[j - 1] ;  
                array[j - 1] = temp ;  
            }  
        }  
    }  
	//printf("%d",bub_count);
}  
//��ѡ������          
void selectSort (int * const array, const int size)  
{  
    int temp ;  
    int i, j, minIndex ;  
  
    for (i = 0; i < size - 1; i++)  
    {  
        minIndex = i ;  
        for (j = i + 1; j < size; j++)  
        {  
            if (array[j] < array[minIndex])  
                minIndex = j ;  
        }  
        if (minIndex != i)  
        {  
            temp = array[i] ;  
            array[i] = array[minIndex] ;  
            array[minIndex] = temp ;  
        }  
    }  
}  
 
  
void printArray (const int * const array, const int size,const char *name)  
{  
    int i ;  
	printf("%s��������",name);
    for (i = 0; i < size; i++)  
        printf ("%-5d", array[i]) ;  
}  
