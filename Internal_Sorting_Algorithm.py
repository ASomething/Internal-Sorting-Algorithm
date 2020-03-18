#Author:Chen Liu
import copy
#1.直接插入排序：
        #*思想：  （1）在一个长度为n的数组A中，认为第一个元素A[0]是已排序的;
                # （2）取下一个元素，从后向前扫描已排序部分，将大于该元素的所有关键字依次向后移动一个位置；
                # （3）重复步骤(2)，直到遇到一个关键字key的值不大于该元素时，就把此元素插入到key后面；
                # （4）重复步骤(2)(3)，直到无序部分关键字个数减为0，排序过程结束。
def direct_insert_sort(array, size):
    "直接插入排序"
    for i in range(1,size):
        temp = array[i]
        for j in range(i, 0, -1):                  #都是for循环在作祟！！！（j等于1就会退出，而不等到j等于0）
            if temp<array[j-1]:
                array[j] = array[j-1]
            else:
                break
            j -= 1                                 #因此要加上这句！仔细思考一下，为何不是将下面那句改为：array[j-1] = temp ?
        array[j] = temp
    return 0
#====================================================================================================================
#2.折半插入排序：
        #*思想：  （1）使用折半查找法求出中间位置下标mid = (low + high)/2，取无序部分第一个关键字key与A[mid]比较；
                # （2）若key < A[mid]，则令high = mid - 1；
                # （3）若key > A[mid]，则令low = mid + 1；
                # （4）若key = A[mid]，则将key插到A[mid]后面；
                # （5）重复步骤(2)(3)(4)，当low > high时，将关键字key插入到下标为high的关键字之后；
                # （6）重复步骤(1)(2)(3)(4)(5)，直到无序部分关键字全部插入，排序结束。
def binary_sort(array, size):
    "折半插入排序"
    for i in range(1, size):
        temp = array[i]
        low = 0
        high = i-1
        while low<=high:
            mid = int((low+high)/2)
            if array[i]<array[mid]:
                high = mid-1
            else:
                low = mid+1
        for j in range(i-1, low-1, -1):
            array[j+1] = array[j]
        array[low] = temp
    return 0
#====================================================================================================================
#3.希尔排序：
        #*思想：  （1）按照某种增量选取规则确定好增量序列；
                # （2）依次以不同增量分割初始序列，得到几组子序列；
                # （3）分别对(2)中得到的子序列进行直接插入排序；
                # （4）然后将排过序的几组关键字按组序再次合成一组；
                # （5）重复(2)(3)(4)，直到增量序列中数字全部用完，排序。
def shell_sort(array, size):
    "希尔排序"
    i = int(size/2)                 # i即为增量
    while i>0:
        for j in range(i, size):
            temp = array[j]
            # for k in range(j, i-1, -i):
            k = j
            while k>=i:
                if temp<array[k-i]:
                    array[k] = array[k-i]
                else:
                    break
                k = k - i
            array[k]  = temp
        i = int(i/2)
    return 0
#====================================================================================================================
#4.快速排序：
        #*思想：  （1）开始时设置两个变量：i = 0，j = n-1，并把第一个关键字作为枢轴，将其值赋给临时变量：temp = A[0];
                # （2）从j开始向前扫描(j--)，当A[j] < temp时,执行A[i] = A[j];
                # （3）从i开始向前扫描(i++)，当A[i] > temp时,执行A[j] = A[i];
                # （4）重复(2)(3)，当i = j时，令A[i] = temp，一趟冒泡排序结束；
                # （5）分别递归处理A[0]~A[i-1]和A[i+1]~A[n-1]。
def quick_sort(array, left, right):
    "快速排序"
    if left<right:
        i = left
        j = right
        pivot = left
        temp = array[pivot]
        while i!=j:
            while (j>i) & (array[j]>temp):
                j -= 1
            if i<j:
                array[i] = array[j]
                i += 1
            while (i<j) & (array[i]<=temp):
                i =i+1
            if i<j:
                array[j] = array[i]
                j -= 1
        array[i] = temp
        quick_sort(array, left, i-1)
        quick_sort(array, i+1, right)
    return 0
#====================================================================================================================
#5.冒泡排序：
        #*思想：  （1）从左向右依次比较相邻关键字；
                # （2）若前者大于后者，交换二者位置；否则，不交换，直到比较完参与此趟比较的所有关键字；
                # （3）判断，如果某趟排序过程中没有发生过交换动作，则整个排序过程结束；
                # （4）此时，将处理过的参与比较的关键字序列中的最后一个去掉；
                # （5）以剩余的关键字序列。
def bubble_sort(array, size):
    "冒泡排序"
    index = 1
    while (index==1) & (size>1):
        index = 0
        for i in range(1, size):
            if array[i]<array[i-1]:      #冒泡排序结束的条件是在一趟排序中没有发生关键字交换
                index =1
                temp = array[i]
                array[i] = array[i-1]
                array[i-1] = temp
    return 0
#====================================================================================================================
#6.简单选择排序：
        #*思想：  （1）从前向后扫描数组，挑选出最小的关键字key与数组第一个元素A[0]交换位置；
                # （2）从A[1]开始向后扫描，挑选出最小的关键字key与A[1]交换位置；
                # （3）……
                # （4）第i趟从A[i+1]先后扫描挑选出最小的关键字key与A[i+1]交换位置；
                # （5）……
                # （6）第n次无序部分仅剩下一个关键字A[n-1]，排序结束。
def select_sort(array, size):
    "简单选择排序"
    for i in range(0, size-1):
        minIndex = i
        for j in range(i+1, size):
            if array[j]<array[minIndex]:
                minIndex = j
        if minIndex!=i:
            temp = array[i]
            array[i] = array[minIndex]
            array[minIndex] = temp
    return 0
#====================================================================================================================
#7.堆排序：
        #*思想：  （1）将初始序列中的关键字依次录入一棵完全二叉树的结点中（从上至下，从左至右）；
                # （2）调整关键字位置，使完全二叉树变成堆；
                # （3）将堆的根结点中的关键字取下，放入有序序列；
                # （4）重复(2)(3)，直到完全二叉树变成空树，排序结束。
def swap(array, i, j):          #交换函数
    temp = array[i]
    array[i] = array[j]
    array[j] = temp
def adjustHeap(array, i, size):      #调整节点符合堆定义(大顶堆)
    left = i*2+1
    right = left+1
    root = i
    if left<size and array[root]<array[left]:
        root = left
    if right<size and array[root]<array[right]:
        root = right
    if root != i:
        swap(array, root, i)
        adjustHeap(array, root, size)
def heap_sort(array, size):
    "堆排序"                                 #构建大顶堆
    for i in range(int(size/2)-1, -1, -1):   #从第一个非叶节点，从下至上、从至右调整
        adjustHeap(array, i, size)
    for j in range(size-1, -1, -1):        #交换堆顶元素和末尾元素，并调整堆结构
        swap(array, 0, j)                  #与C语言不同，这里也可直接写成：array[0], array[j] = array[j], array[0]
        adjustHeap(array, 0, j)            #好好想想这个0
    return 0
#====================================================================================================================
#8.二路归并排序：
        #*思想：  （1）将初始序列中每一个关键字看作一个子序列，并对它们编号；
                # （2）按照组号两两合并，形成若干新的更大的分组；
                # （3）分别对每组排序，这里可以嵌套使用其他排序算法；
                # （4）重复（2）（3），直到将所有子序列合并成一个序列，排序结束。
def merge_sort(array, left, right):
    "二路归并排序"
    if left<right:
        mid = int((left+right)/2)
        merge_sort(array, left, mid)
        merge_sort(array, mid+1, right)

        temp = []
        i = left
        j = mid+1
        while (i<=mid)&(j<=right):
            if array[i]<=array[j]:
                temp.append(array[i])               #列表和数组还是有些不同的！！！当列表为空时。temp[0]不存在，当然不能用；其他类似！
                i += 1
            else:
                temp.append(array[j])
                j += 1
        if i>mid:
            while j<=right:
                temp.append(array[j])
                j += 1
        else:
            while i<=mid:
                temp.append(array[i])
                i += 1
        j = 0
        for i in range(left, right+1):
            array[i] = temp[j]
            j += 1
    return 0
#====================================================================================================================
#9.计数排序：
        #*思想： （1）对于列表中的每个元素，使用循环将其与整个列表（包括自身）逐个比较，统计出有多少元素小于等于该元素；
                #（2）若有count个元素小于等于某元素，则 count-1 就是该元素在排序结束后列表中的下标。
                #因此，这种排序过程貌似不允许列表有重复元素了！
def count_sort(array, size):
    "计数排序"
    array2 = copy.deepcopy(array)                   #深度copy,两个列表完全独立（相当于array2 = array[:]）
    mark = []                                       #标记数组，还不是为了解决重复关键字问题。。。
    for k in range(size):
        mark.append(0)
    for i in range(0, size):
        count = 0
        for j in range(0, size):
            if array2[j]<=array2[i]:
                count += 1
        while mark[count-1]==1:                      #因为自身也和自身比较了一次，所以要用count-1
            count -= 1
        array[count-1] = array2[i]
        mark[count-1] = 1
    return 0
#=====================================================================================================================
#*******初始化函数*********
def initialize(array, size):
    "初始化函数"
    del array[:]  # 清空列表(或array.clear())，以备下次排序（必须清空，因为列表的传递是引用传递。
                  # 即否则第二次排序使用的列表会是第一次排序后的结果列表！）
    for k in range(0, size):
        array.append(int(input()))           #因为Python默认输入类型为字符（且Python对字符和字符串不作区分！）
    return 0
#********输出函数**********
def printArray(array, size, name):
    "输出函数"
    print("%s排序结果："%name, end="")
    for i in range(0, size):
        print(array[i], end="\t")
    return 0
#********主函数************
if __name__=="__main__":   #(此句话下面的代码需要手动执行；将本文件其当做模块导入的时候，此句话下面的代码就不会执行！)

    array = []  # 创建一个空列表，用来存储待排序数据
    while True:
        print("\033[31;1m选项：\033[0m")
        print("\t\033[32;1m0.退出系统！\033[0m")                    #带色输出
        print("\t\033[32;1m1.直接插入排序（InsertionSort）\033[0m")
        print("\t\033[32;1m2.折半插入排序（BinarySort）\033[0m")
        print("\t\033[32;1m3.希尔排序（ShellSort）\033[0m")
        print("\t\033[32;1m4.快速排序（QuickSort）\033[0m")
        print("\t\033[32;1m5.冒泡排序（BubbleSort）\033[0m")
        print("\t\033[32;1m6.简单选择排序（SelectSort）\033[0m")
        print("\t\033[32;1m7.堆排序（HeapSort）\033[0m")
        print("\t\033[32;1m8.二路归并排序（MergeSort）\033[0m")
        print("\t\033[32;1m9.计数排序（CountSort）\033[0m")
        while True:
            print("请选择要使用的排序算法：", end="")
            choice = int(input())
            if (choice<0)|(choice>9):
                print("\033[31;1m指令有误！请重新输入-->\033[0m")
                break
            if choice==0:
                exit("\033[31;1m退出系统成功！\033[0m")
            else:
                print("待排序关键字个数（请输入一个自然数）：", end="")
                size = int(input())
                print("请给数组赋值：", end="")  # 使不换行!
                initialize(array, size)
            if choice==1:
                direct_insert_sort(array, size)
                printArray(array, size, "InsertionSort")
                print("\n")
            elif choice==2:
                binary_sort(array, size)
                printArray(array, size, "BinarySort")
                print("\n")
            elif choice==3:
                shell_sort(array, size)
                printArray(array, size, "ShellSort")
                print("\n")
            elif choice==4:
                quick_sort(array, 0, size-1)
                printArray(array, size, "QuickSort")
                print("\n")
            elif choice==5:
                bubble_sort(array, size)
                printArray(array, size, "BubbleSort")
                print("\n")
            elif choice==6:
                select_sort(array, size)
                printArray(array, size, "SelectSort")
                print("\n")
            elif choice==7:
                heap_sort(array, size)
                printArray(array, size, "HeapSort")
                print("\n")
            elif choice==8:
                merge_sort(array, 0, size-1)
                printArray(array, size, "MergeSort")
                print("\n")
            elif choice==9:
                count_sort(array, size)
                printArray(array, size, "CountSort")
                print("\n")
