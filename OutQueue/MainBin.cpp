//���Ϊ1��2��3������n��n���˰�˳ʱ�뷽��Χ��һȦ��ÿ�˳���һ�����롴��������
//һ��ʼ��ѡһ����������Ϊ��������ֵm���ӵ�һ���˿�ʼ��˳ʱ�뷽����1��ʼ˳����������mʱֹͣ����
//��m���˳��У�������������Ϊ�µ�mֵ��������˳ʱ�뷽���ϵ���һ���˿�ʼ���´�1����
//�����ȥ��ֱ��������ȫ������Ϊֹ��

//ʹ�õ�ѭ������ģ��
//�������к�����Ҫ���û�ָ����ʼ��������ֵ��Ȼ���ȡ���˵�����(С��30)��

//Input
//����������У���һ�а�����������ֵm������n���ڶ���Ϊn���˵����룬��������֮���ɿո�ָ���
//Output
//���һ�У���n����������ʾ������˵ĳ���˳�򡣸���֮���ɿո�ָ���
//Sample Input
//20 7
//3 1 7 2 4 8 4
//Sample Output
//6 1 4 7 2 3 5

#include <iostream>
#include <fstream>
#include"cyclelinkedlist.h"


int main() {
	//�ļ��������
	std::fstream inputFile, outfile;
	inputFile.open("input", std::ios::in);
	outfile.open("output", std::ios::out);
	int MaxNum, Num_Human;

	//��������MaxNum������Num_Human
	inputFile >> MaxNum;
	inputFile >> Num_Human;
	//��ÿ���˵�����洢��ѭ������
	Cycle_Linked_List<int> CLList;
	for (int i = 0; i < Num_Human; i++)
	{
		int elem;
		inputFile >> elem;
		CLList.CycleListInsert(i + 1, elem );
	}





	

	inputFile.close();
	outfile.close();
}