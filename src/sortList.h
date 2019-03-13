/*
 * sortList.h
 *
 *  Created on: 2019年3月13日
 *      Author: jix
 *      插入排序：直接插入排序，折半插入排序，希尔排序
 *      交换排序：冒泡排序，快速排序
 *      选择排序：直接选择排序，堆排序
 *      归并排序
 *      基数排序
 */

#ifndef SRC_SORTLIST_H_
#define SRC_SORTLIST_H_

#include <iostream>
using namespace std;


template <typename T>
void printList(T a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << "  ";
	}
	cout << endl;
}

template <typename T>
void printList(T a[], int n, int index){
	for(int i = 0; i < n; i++){
		if(i == index){
			cout << "x" << "  ";
		}else{
			cout << a[i] << "  ";
		}
	}
	cout << endl;
}

/*
直接插入排序
a：待排序元素集合
n：集合中元素的个数
步骤：
（1）选取无序区中第一个元素i
（2）将i与有序区中元素j(0 <= j <= i-1)比较，寻找插入位置，同时移动元素
（3）将该元素插入合适位置
（4）重复（1）（2）（3）直至无序区长度为0
*/
template <typename T>
void insertSort(T a[], int n){
	for(int i = 1; i < n; i++){
		if(a[i] < a[i - 1]){
			T value = a[i];
			int index = i - 1;
			while(index >= 0 && a[index] > value){
				a[index + 1] = a[index];
				printList(a, n, index);
				index--;
			}
			a[index+1] = value;
			printList(a, n);
			cout<<"-----------"<<endl;
		}
	}
}


/*
折半插入排序
a：待排序元素集合
n：集合中元素的个数
步骤：
（1）选取无序区中第一个元素i
（2）在有序区间折半搜索该元素应该插入的位置
（3）将该元素插入合适位置
（4）重复（1）（2）（3）直至无序区长度为0
*/
template <typename T>
void binarySort(T a[], int n){
	for(int i = 1; i < n; i++){
		T value = a[i];
		int left = 0, right = i - 1, mid;
		while(left <= right){
			mid = (left + right) / 2;
			if(a[mid] < value){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}
		int index = i - 1;
		while(index >= right + 1){
			a[index + 1] = a[index];
			printList(a, n, index);
			index--;
		}
		a[index + 1] = value;
		printList(a, n);
		cout<<"-----------"<<endl;
	}
}


/*
希尔排序
a：待排序元素集合
n：集合中元素的个数
步骤：
（1）将待排序集合分成k个组，且每个组元素下标的差值为k
（2）对每个组的元素进行直接插入排序
（3）减少组的规模（这里采用折半减少的方式），重复（1）（2）直至规模为最小值1
*/
template <class T>
void shellSort(T a[], int n){
	int k = n / 2;
	while(k > 0){
		for(int g = 0; g < k; g++){
			for(int i = g + k; i < n; i += k){
				T value = a[i];
				int index = i - k;
				while(index >= 0 && a[index] > value){
					a[index + k] = a[index];
					index -= k;
				}
				a[index + k] = value;
			}
			printList(a, n);
		}
		k = k / 2;
		cout << "-------" << endl;
	}
}

/*
冒泡排序
a：待排序元素集合
n：集合中元素的个数
步骤：
（1）从无序区间的最后一个元素开始，如果该元素小于它相邻的前一个元素，则两者交换，重复比较直至无序区所有元素都比较完成
（2）将无序区间的第一个元素置入有序区间
（3）重复（1）（2）直至无序区间长度为0
*/
template <typename T>
void bubbleSort(T a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j - 1]){
				T value = a[j];
				a[j] = a[j - 1];
				a[j - 1] = value;
			}
			printList(a, n);
		}
		cout << "-------" << endl;
	}
}

/*
快速排序
a：待排序元素集合
left：集合中第一个元素下标
right：集合中最后一个元素下标
步骤：
（1）以集合第一个元素为基准，进行划分，将小与它的元素放在它左边，将大于它的元素放在它右边
（2）将左边元素的区间、右边元素的区间递归进行划分
（3）重复（1）（2），直至子区间不能再划分为止
*/
template <typename T>
void quickSort(T a[], int left, int right){
	if(left >= right) return;
	int i = left, j = right;
	T value = a[left];
	while(i < j){
		while(i < j && a[j] >= value){
			j--;
		}
		a[i] = a[j];
		while(i < j && a[i] <= value){
			i++;
		}
		a[j] = a[i];
	}
	a[i] = value;
	cout<<"left="<<left<<" right="<<right<<" i="<<i<<endl;
	printList(a, 8);
	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
}


/*
直接选择排序
a：待排序元素集合
n：集合中元素的个数
步骤：
（1）从无序区间选择最小的元素置入有序区间
（2）重复（1）直至无序区间长度为0
*/
template <typename T>
void selectSort(T a[], int n){
	for(int i = 0; i < n; i++){
		int index = i;
		for(int j = i + 1; j < n; j++){
			if(*(a+j) < *(a + index)){
				index = j;
			}
		}
		if(index != i){
			T value = a[i];
			a[i] = a[index];
			a[index] = value;
		}
		printList(a, 8);
	}
}


/*
调整堆：给定一个非叶子节点，递归向下调整，使其满足堆的结构（根节点大于它的左右孩子节点）
a：待排序元素集合
i：非叶子节点的下标
n：集合中元素的个数
步骤：
（1）若左右孩子节点的最大值大于当前节点，将其和最大值的节点交换
（2）交换后可能会导致子树不满足堆的定义，所以要递归进行调整
*/
template <typename T>
void adjustHeap(T a[], int i, int n){
	T value = a[i];
	int j = i * 2 + 1; //j指向i的左孩子节点
	while (j < n)
	{
		if (j + 1 < n && a[j] < a[j + 1]) j++; //如果右子树大于它的左子树，则j改为指向右子树
		if (value < a[j]) a[(j - 1) / 2] = a[j]; //如果孩子节点较大，则将孩子节点与父节点交换（因为是递归调整，所以不用修改孩子节点的值）
		else break;
		j = j * 2 + 1; //递归遍历孩子节点
	}
	//j < n ? (a[j] = value) : (a[(j - 1) / 2] = value); //递归出口，被break掉的情况和j越界的情况
}
/*
堆排序
a：待排序元素集合
n：集合中元素的个数
步骤：
（1）建立堆
（2）每次取无序区堆顶元素，置入有序区
（3）调整堆
（4）重复（2）（3）直至无序区长度为0
*/
template<typename T>
void heapSort(T a[], int n)
{
	//构建堆
	for (int i = n / 2 - 1; i >= 0; i--) //从第一个非叶子节点开始，向上调整堆直至调整至堆顶
		adjustHeap(a, i, n);
	//堆排序
	for (int i = n - 1; i >= 0; i--) //每次选取堆顶元素置入有序区
	{
		T max = a[0];
		a[0] = a[i];
		a[i] = max;
		adjustHeap(a, 0, i); //调整堆
		printList(a, n);
	}
}
#endif /* SRC_SORTLIST_H_ */
