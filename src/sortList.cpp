/*
 * sortList.cpp
 *
 *  Created on: 2019年3月13日
 *      Author: jix
 */
#include "sortList.h"
#include <iostream>
using namespace std;
void radixSort(RadixNode *&p, int r, int d)
{
	RadixNode **head = new RadixNode*[r]; //存储基数的每一个字符的头节点
	RadixNode **tail = new RadixNode*[r]; //存储基数的每一个字符的尾节点
	while (--d >= 0) //对集合中所有数字的每一位进行分配和收集
	{
		//分配
		for (int i = 0; i < r; i++) //初始化头结点和尾节点
			head[i] = tail[i] = NULL;
		while (p != NULL) //分配集合中的每一个元素
		{
			int i = p->val[d] - '0'; //获取元素第d位对应的字符下标
			if (head[i] == NULL) //分配到对应的字符组，组中没有元素的情况
				head[i] = tail[i] = p;
			else //分配到对应的字符组，组中已经有元素的情况
				tail[i] = tail[i]->next = p;
			p = p->next;
		}
		//收集
		p = NULL;
		auto q = p;
		for (int i = 0; i < r; i++) //收集每一个组的所有元素
		{
			if (head[i] != NULL) //组不为空收集
			{
				if (p == NULL) //还未收集到元素的情况
				{
					p = head[i];
					q = tail[i];
				}
				else //已经收集到元素的情况
				{
					q->next = head[i];
					q = tail[i];
				}
			}
		}
		if(q) q->next = NULL; //添加链表结束标志
	}
	delete [] head;
	delete [] tail; //释放空间
}

