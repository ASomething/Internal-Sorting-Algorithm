/*  test.c -- ���Լ��������㷨�ȶ���   */  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>    
#define MAX (10)  
#define SIZE (30)  

int flag = 0;  
typedef struct    //����ṹ��
{  
    int key ;  
    int logo ;  
} Item ;  
  
int main (void) ;  
int initialize (Item * const array, const int size) ;       //��ʼ������

/*  ��������������  */  
void insertionSort (Item * const array, const int size) ;  
void binarySort(Item * const array, const int size);
void shellSort (Item * const array, const int size) ;  
void bubbleSort (Item * const array, int size) ;  
void quickSort (Item * const array, int left, const int right) ; 
void selectSort (Item * const array, const int size) ;
void heapSort (Item * const array, int size) ;  
void mergeSort (Item * const array, const int left, const int right) ;  
 
int test (const Item * const array, const int size) ;  
void printArray (const Item * const array, const int size) ;     //����������� 
void result(const char * name);                            //����������Խ��
  
int main (void)      //������
{  
    Item array[SIZE] ;  
    int size ;  
	int choice; 
    size = SIZE ;  
	printf("��ѡ��Ҫ���Ե������㷨��\n");
	printf("\n");
	printf("1.ֱ�Ӳ�������(InsertionSort)\n");
	printf("2.�۰��������(BinarySort)\n");
	printf("3.ϣ������(ShellSort)\n");
	printf("4.ð������(BubbleSort)\n");
	printf("5.��������(QuickSort)\n");
	printf("6.��ѡ������(SelectSort)\n");
	printf("7.������(HeapSort)\n");
	printf("8.�鲢����(MergeSort)\n");
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
				initialize (array, size) ;       
				insertionSort (array, size) ;  
				test (array, size) ;  
				printArray (array, size) ; 
				printf("\n");
				result("InsertionSort");
				goto l;
		   }
       case 2://�۰��������
		   {
				initialize (array, size) ;       
				binarySort (array, size) ;  
				test (array, size) ;  
				printArray (array, size) ; 
				printf("\n");
				result("BinarySort");
				goto l;
		   }
	   case 3://ϣ������
		   {
				initialize (array, size) ;  
				shellSort (array, size) ;  
				test (array, size) ;  
				printArray (array, size) ;
				printf("\n");
				result("ShellSort");
				goto l;
		   }
	   case 4://ð������
		   {
				initialize (array, size) ;  
				bubbleSort (array, size) ; 
				test (array, size) ;  
				printArray (array, size) ;
				printf("\n");
				result("BubbleSort");
				goto l;
		   }
	   case 5://��������
		   {
				initialize (array, size) ;  
				quickSort (array, 0, size-1) ;
				test (array, size) ;  
				printArray (array, size) ;
				printf("\n");
				result("QuickSort");
				goto l;
		   }  
	   case 6://��ѡ������
		   {
				initialize (array, size) ;  
				selectSort (array, size) ;  
				test (array, size) ;  
				printArray (array, size) ;
				printf("\n");
				result("SelectSort");
				goto l;
		   }
	   case 7://������ 
		   {
				initialize (array, size) ;  
				heapSort (array, size) ;  
				test (array, size) ;  
				printArray (array, size) ;
				printf("\n");
				result( "HeapSort");
				goto l;
		   }
	   case 8://��·�鲢���� 
		   {
				initialize (array, size) ;  
				mergeSort (array, 0, size-1) ;   
				test (array, size) ;  
				printArray (array, size) ;
				printf("\n");
				result("MergeSort");
				goto l;
		   }
	   
	   default:
		   printf("ָ���������������룡\n");
		   printf("\n");
		   goto l;
	}
    return 0 ;  
}  
  
int initialize (Item * const array, const int size)  
{  
    int * temp ;  
    int max, i ;  
  
    max = MAX ;  
    temp = (int *) malloc (sizeof (int) * max) ;  
    if (NULL == temp)  
        return 0 ;  
    srand ((unsigned int) time (NULL)) ;  
    for (i = 0; i < size; i++)  
        array[i].key = rand () % max ;  
    for (i = 0; i < max; i++)  
        temp[i] = 0 ;  
    for (i = 0; i < size; i++)  
        temp[array[i].key]++ ;  
    for (i = size - 1; i >= 0; i--)  
        array[i].logo = temp[array[i].key]-- ;
	printArray(array,size);
    free (temp) ;      //�ͷ�tempռ�õ��ڴ�ռ�
  
    return 1 ;  
}  
//ֱ�Ӳ�������
void insertionSort (Item * const array, const int size)  
{  
    Item temp ;  
    int i, j ;  
  
    for (i = 1; i < size; i++)  
    {  
        temp = array[i] ;  
        for (j = i; j > 0; j--)  
        {  
            if (temp.key < array[j - 1].key)  
                array[j] = array[j - 1] ;  
            else  
                break ;  
        }  
        array[j] = temp ;  
    }  
}  
//�۰��������
void binarySort(Item * const array, const int size) 
{
    int low, mid, high;
    Item temp;
    for (int i = 1; i < size; ++i)
	{
		temp = array[i];
		low = 0;
		high = i-1;
		while (low <= high) 
		{
			mid = (low+high)/2;
			if (array[i].key < array[mid].key)
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
void shellSort (Item * const array, const int size)  
{  
    Item temp ;  
    int p, i, j ;  
  
    for (p = size / 2; p > 0; p /= 2)  
    {  
        for (i = p; i < size; i++)  
        {  
            temp = array[i] ;  
            for (j = i; j - p >= 0; j -= p)  
            {  
                if (temp.key < array[j - p].key)  
                    array[j] = array[j - p] ;  
                else  
                    break ;  
            }  
            array[j] = temp ;  
        }  
    }  
}  
//������ 
void heapSort (Item * const array, int size)  
{  
    Item temp ;  
    int i, j, child ;  
  
    /*  Build heap. */  
    for (i = size / 2; i >= 0; i--)  
    {  
        temp = array[i] ;  
        for (j = i; j * 2 + 1 <= size - 1; j = child)  
        {  
            child = j * 2 + 1 ;  
            if (child != size - 1 && array[child].key < array[child + 1].key)  
                child++ ;  
            if (temp.key < array[child].key)  
                array[j] = array[child] ;  
            else  
                break ;  
        }  
        array[j] = temp ;  
    }  
    while (size > 1)  
    {  
        /* ����   */  
        temp = array[0] ;  
        array[0] = array[size - 1] ;  
        array[size - 1] = temp ;  
        size-- ;  
        /*  Percolate down. */  
        temp = array[0] ;  
        for (j = 0; j * 2 + 1 <= size - 1; j = child)  
        {  
            child = j * 2 + 1 ;  
            if (child != size - 1 && array[child].key < array[child + 1].key)  
                child++ ;  
            if (temp.key < array[child].key)  
                array[j] = array[child] ;  
        }  
        array[j] = temp ;  
    }  
}  
//�鲢����  
void mergeSort (Item * const array, const int left, const int right)  
{  
    Item * temp ;  
    int size, middle, i, j, k ;  
      
    if (left < right)  
    {  
        middle = (left + right) / 2 ;  
        mergeSort (array, left, middle) ;  
        mergeSort (array, middle + 1, right) ;  
        /*  Merge.  */  
        size = right - left + 1 ;  
        temp = (Item *) malloc (sizeof (Item) * size) ;  
        if (NULL == temp)  
        {  
            puts ("Out of space.") ;  
            return ;  
        }  
        i = left ;  
        j = middle + 1 ;  
        k = 0 ;  
        while (i <= middle && j <= right)  
        {  
            /*  "<=" */  
            if (array[i].key <= array[j].key)  
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
//��������  
void quickSort (Item * const array, int left, const int right)  
{  
    Item temp ;  
    int i, j, pivot ;  
  
    while (left < right)  
    {  
        i = left ;  
        j = right - 1 ;  
        pivot = right ;  
        while (i < j)  
        {  
            while (i != right && array[i].key <= array[pivot].key)  
                i++ ;  
            while (j != left && array[j].key > array[pivot].key)  
                j-- ;  
            if (i < j)  
            {  
                temp = array[i] ;  
                array[i] = array[j] ;  
                array[j] = temp ;  
            }  
            else  
                break ;  
        }  
        temp = array[i] ;  
        array[i] = array[pivot] ;  
        array[pivot] = temp ;  
        quickSort (array, left, i - 1) ;  
        left = i + 1 ;  
    }  
}  
//ð������  
void bubbleSort (Item * const array, int size)  
{  
    Item temp ;  
    int j ;  
    int index ;  
    index = 1 ;  
    for (; 1 == index && size > 1; size--)  
    {  
        index = 0 ;  
        for (j = 1; j < size; j++)  
        {  
            if (array[j].key < array[j - 1].key)  
            {  
                index = 1 ;  
                temp = array[j] ;  
                array[j] = array[j - 1] ;  
                array[j - 1] = temp ;  
            }  
        }  
    }  
}  
//��ѡ������          
void selectSort (Item * const array, const int size)  
{  
    Item temp ;  
    int i, j, minIndex ;  
  
    for (i = 0; i < size - 1; i++)  
    {  
        minIndex = i ;  
        for (j = i + 1; j < size; j++)  
        {  
            if (array[j].key < array[minIndex].key)  
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
 
  
int test (const Item * const array, const int size)  
{  
    int i ;  
    for (i = 1; i < size; i++)  
    {  
        if (array[i].key == array[i - 1].key && array[i].logo < array[i - 1].logo)  
        {    
            
			puts("\n---------------------------------\n");
			flag = 1;
            return 0 ;  
        }  
    }
    printf ("\n---------------------------------\n");  
  
    return 1 ;  
}  
  
void printArray (const Item * const array, const int size)  
{  
    int i ;  
  
    for (i = 0; i < size; i++)  
        printf ("key:%-3dlogo:%3d\n", array[i].key, array[i].logo) ;  
}  

void result(const char * name)
{
	if(flag)
		printf("%s is unstable.\n",name);
	else
		printf("%s is stable. \n",name);
	flag = 0;
}