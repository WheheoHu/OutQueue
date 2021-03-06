//约瑟夫（Joseph）问题
//编号为1，2，3，…，n的n个人按顺时针方向围坐一圈，每人持有一个密码〈正整数〉
//一开始任选一个正整数作为报数上限值m，从第一个人开始按顺时针方向自1开始顺序报数，报到m时停止报数
//报m的人出列，将他的密码作为新的m值，从他在顺时针方向上的下一个人开始重新从1报数
//如此下去，直至所有人全部出列为止。

//使用单循环链表模拟
//程序运行后首先要求用户指定初始报数上限值，然后读取各人的密码(小于30)。

//Input
//输入包括两行，第一行包括报数上限值m和人数n，第二行为n个人的密码，所有数据之间由空格分隔。
//Output
//输出一行，共n个整数，表示各编号人的出列顺序。各数之间由空格分隔。
//Sample Input
//20 7
//3 1 7 2 4 8 4
//Sample Output
//6 1 4 7 2 3 5

#include <iostream>
#include <fstream>
#include"cyclelinkedlist.h"


int main() {
	//文件输入输出
	std::fstream inputFile, outfile;
	inputFile.open("input", std::ios::in);
	outfile.open("output", std::ios::out);
	int MaxNum, Num_Human;

	//读入上限MaxNum与人数Num_Human
	inputFile >> MaxNum;
	inputFile >> Num_Human;
	//将每个人的密码存储进循环链表
	Cycle_Linked_List<int> CLList;
	for (int i = 0; i < Num_Human; i++)
	{
		int elem;
		inputFile >> elem;
		CLList.CycleListInsert(i + 1, elem ,i+1);
	}
	//mans用来存储出队顺序
	int *mans = new int[Num_Human];


	CLList.Joseph(mans, MaxNum, Num_Human);

	//将出队列顺序输出到文件output
	for (int i = 0; i < Num_Human; i++)
	{
		outfile << *(mans+i) << " ";
	}
	delete []mans;
	inputFile.close();
	outfile.close();
}