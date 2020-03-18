/*  test.c -- 实现几种排序算法   */  
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>    
//#define MAX (10)  
#define SIZE (6)  
  
int main (void) ;  
int initialize (int * const array, const int size) ;       //初始化数组

/*  各排序函数的声明  */  
void insertionSort (int * const array, const int size) ;  
void binarySort(int * const array, const int size);
void shellSort (int * const array, const int size) ;  
void bubbleSort (int * const array, int size) ;  
void quickSort (int * const array, int left,int right) ; 
void selectSort (int * const array, const int size) ;
void mergeSort (int * const array, const int left, const int right) ;  
 
  
void printArray (const int * const array, const int size,const char *name) ;     //用于输出数组数据 

  
int main (void)      //主函数
{  
	int array[20] ;
	int size ; 
	printf("待排关键字个数：");
	scanf("%d",&size); 
	printf("请给数组赋值：");
	initialize (array, size) ;
	int choice;
	printf("请选择要使用的排序算法：\n");
	printf("\n");
	printf("1.直接插入排序(InsertionSort)\n");
	printf("2.折半插入排序(BinarySort)\n");
	printf("3.希尔排序(ShellSort)\n");
	printf("4.冒泡排序(BubbleSort)\n");
	printf("5.快速排序(QuickSort)\n");
	printf("6.简单选择排序(SelectSort)\n");
	printf("7.归并排序(MergeSort)\n");
	printf("*.按0退出\n");
	printf("\n");
l:	printf("输入你的选择==>:");
	scanf("%d",&choice);
	printf("\n");
	switch(choice)
	{
	   case 0:
		   printf("退出成功!\n");
		   break;
	   case 1://直接插入排序
		   {       
				insertionSort (array, size) ;   
				printArray (array, size,"InsertionSort") ; 
				printf("\n");
				goto l;
		   }
       case 2://折半插入排序
		   {     
				binarySort (array, size) ;   
				printArray (array, size,"BinarySort") ; 
				printf("\n");
				goto l;
		   }
	   case 3://希尔排序
		   { 
				shellSort (array, size) ;   
				printArray (array, size,"ShellSort") ;
				printf("\n");
				goto l;
		   }
	   case 4://冒泡排序
		   { 
				bubbleSort (array, size) ;  
				printArray (array, size,"BubbleSort") ;
				printf("\n");
				goto l;
		   }
	   case 5://快速排序
		   { 
				quickSort (array, 0, size-1) ;
				printArray (array, size,"QuickSort") ;
				printf("\n");
				goto l;
		   }  
	   case 6://简单选择排序
		   { 
				selectSort (array, size) ;  
				printArray (array, size,"SelectSort") ;
				printf("\n");
				goto l;
		   }
	   case 7://二路归并排序 
		   {

				mergeSort (array, 0, size-1) ;     
				printArray (array, size,"MergeSort") ;
				printf("\n");
				goto l;
		   }
	   default:
		   printf("指令有误，请重新输入!\n");
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
//直接插入排序
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
//折半插入排序
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
//希尔排序
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
//归并排序  
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
        if (temp==NULL)       //Nothing else！仅仅是为了防止上一步开辟空间失败！
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
//快速排序(以第一个关键字为枢轴) 
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
//冒泡排序  
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
//简单选择排序          
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
	printf("%s排序结果：",name);
    for (i = 0; i < size; i++)  
        printf ("%-5d", array[i]) ;  
}  
