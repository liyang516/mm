#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

void PrintArray(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		if(i==len-1)
			cout<<a[i];
		else
			cout<<a[i]<<", ";
	}
	cout<<endl;
}

// 交换两个整数
void Swap(int &a, int &b)
{
	if(a==b)
		return;
	a = a^b;
	b = a^b;
	a = a^b;
}

// 冒泡排序,相邻元素两两比较,大的往后放,一次循环后,最大的出现在最后面
void BubbleSort(int a[], int num)
{
	if(NULL==a || num<=0)
		return;
	for(int i=0;i<num-1;i++)
	{
		for(int j=0;j<num-1-i;j++)
		{
			if(a[j]>a[j+1])
				Swap(a[j],a[j+1]);
		}
	}
}

// 选择排序,第i(i=0,1,2...)个元素依次和后面的元素比较,小的放前面,第一次循环后,最小的出现在最左侧
void SelectSort(int a[], int num)
{
	if(NULL==a||num<=0)
		return;
	for(int i=0;i<num-1;i++)
	{
		for(int j=i+1;j<num;j++)
		{
			if(a[i]>a[j])
				Swap(a[i],a[j]);
		}
	}
}

//插入排序,将前i个元素假象为有序数组，对前i个元素进行排序，小的往前放
void InsertSort(int a[], int num)
{
	if(NULL==a||num<=0)
		return;
	for(int i=1;i<num;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(a[j]<a[j-1])
			{
				Swap(a[j],a[j-1]);
			}

		}
	}
}

// 快速排序,每次循环选一个基准值,比基准值小的放在基准值左边,比基准值大的放在基准值右边
int getPartition(int a[], int low, int high)
{
	if(NULL==a||low>high)
		return -1;
	int pivotKey = a[low];
	while(low<high)
	{
		while(low<high && a[high]>=pivotKey)
			--high;
		Swap(a[low],a[high]);
		while(low<high && a[low]<=pivotKey)
			++low;
		Swap(a[low],a[high]);
	}
	return low;
}

// 快速排序
void QuickSort(int a[], int low, int high)
{
	if(low<high)
	{
		int pivotIndex = getPartition(a,low,high);
		QuickSort(a,low,pivotIndex-1);
		QuickSort(a,pivotIndex+1,high);
	}
}

// 归并排序,采用分治思想(合并有序数组),先将数组分成一个个小数组进行排序，在合并各个小数组
void MergeArray(int a[], int low, int mid,int high, int pArray[])
{
	int i=low,j=mid+1;
	int m=mid,n=high;
	int k=0;
	while(i<=m && j<=n)
	{
		if(a[i]<a[j])
			pArray[k++] = a[i++];
		else
			pArray[k++] = a[j++];
	}

	while(i<=m)
		pArray[k++] = a[i++];
	while(j<=n)
		pArray[k++] = a[j++];
	for(int i=0;i<k;i++)
		a[low+i] = pArray[i];
}

void mergesort(int a[], int low, int high, int pArray[])
{
	if(low<high)
	{
		int mid = (low+high)/2;
		mergesort(a,low,mid,pArray);
		mergesort(a,mid+1,high,pArray);
		MergeArray(a,low,mid,high,pArray);
	}
}


int MergeSort(int a[], int num)
{
	if(NULL==a||num<=0)
		return -1;
	int *pArray = new int[num];
	mergesort(a,0,num-1,pArray);
	delete []pArray;
	return 1;
}

//剪绳子
int getMaxProduct(int length)
{
	if(length<2)
		return 0;
	if(length==2)
		return 1;
	if(length==3)
		return 2;
	int timesOf3 = length/3;
	if(length - timesOf3*3 == 1)
		timesOf3--;
	int timesOf2 = (length - timesOf3*3)/2;
	return pow(3,timesOf3)*pow(2,timesOf2);
}

// 求一个整数二进制格式中1的个数
int getNumberOf1InBinary(int num)
{
	int count = 0;
	while(num)
	{
		count++;
		num = num&(num-1);
	}
	return count;
}

int MinInOrder(int a[], int low, int high)
{
	int result = a[low];
	for(int i=low+1;i<=high;i++)
	{
		if(a[i]<result)
			result = a[i];
	}
	return result;
}

int MinValueInRotateArray(int a[], int num)
{
	int low = 0;
	int high = num-1;
	int mid = low;
	while(a[low]>=a[high])
	{
		if(high-low==1)
		{
			mid = high;
			break;
		}

		mid = (low+high)/2;
		// if(a[low]==a[high] && a[low]==a[mid])
		// 	return MinInOrder(a,low,high);
		if(a[mid]>=a[low])
			low = mid;
		else if(a[mid]<=a[high])
			high = mid;
	}
	return a[mid];
}


bool BinarySearch(int a[], int value)
{
	// if(NULL==a)
	return false;
		
}

int main(int argc, char **argv)
{
	int a[] = {3,1,5,4,6,2};
	int a_len = sizeof(a)/sizeof(a[0]);
	int rotate_array[] = {1,1,1,0,1};
	int b[] = {2,1,4,3,5};
	int b_len = sizeof(b)/sizeof(b[0]);
	// cout<<MinValueInRotateArray(rotate_array,5)<<endl;
	PrintArray(a,a_len);
	// PrintArray(b,b_len);
	QuickSort(a,0,a_len-1);
	PrintArray(a,a_len);
	// BubbleSort(a,6);
	// SelectSort(a,6);
	// InsertSort(a,6);
	// MergeSort(b,b_len);
	// PrintArray(b,b_len);
	// cout<<(3+4)/2<<endl;
	// cout<<getMaxProduct(16)<<endl;
	// cout<<getNumberOf1InBinary(7)<<endl;

	return 0;
}