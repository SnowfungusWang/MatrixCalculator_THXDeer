 #include "pch.h"
#include <iostream>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;

class SimpleMatrix
{
public:
	SimpleMatrix();
	~SimpleMatrix();
	SimpleMatrix(const SimpleMatrix &SimMatr);
	//���������
	double** maxtrix;//��ά����
	int row=0, column=0;
	double rank=0;
	int trace=0;
	double* properValue=NULL;
	//����
	void creatMatrix();//��������
	void print();
	double  calculateRank();

private:
	

};



SimpleMatrix::SimpleMatrix()
{
	maxtrix = NULL;
}

SimpleMatrix::~SimpleMatrix()
{
}

SimpleMatrix::SimpleMatrix(const SimpleMatrix & SimMatr)
{
}


void SimpleMatrix:: creatMatrix(){
	cout << "Please first enter tne size of your maxtrix as : row column."<<endl
		<<"Then please enter your matrix with space seprating the element." << endl;

	cin >> row >> column;
	//�õ�������
	maxtrix = new double* [row];
	string curLine;
	int rowTest = 0;
	//��ʼ��������
	getline(cin, curLine);
	cout << curLine;
	do
	{
		getline(cin, curLine);
		if (curLine[0]=='\0') {
			break;
		}
		else if (rowTest > row - 1) {
			cerr << "Row oversteps.\nPlease input again." << endl;
			break;
		}
		//�õ���������

		maxtrix[rowTest] = new double[column];
		int columnTest = 0;
		istringstream is(curLine);
		double cur;
		do 
		{
			if (columnTest>column+1)break;
			is >> cur;
			maxtrix[rowTest][columnTest] = cur;
			columnTest++;
			//cout << cur<< ','<<columnTest << 's' << endl;
		} while (is);

		if (columnTest > column+1)
		{
			cout << "Column oversteps.\nPlease input again." << endl;
			break;
		}

		if (columnTest<column-1)
		{
			cout<< "Short of columns in row"<<columnTest+1<<".\nPlease input again." << endl;
			break;
		}
		//�洢һ��
		rowTest++;
	} while (true);
	if (rowTest < row - 1)
	{
		cout << "Short of rows, only " <<rowTest + 1 << " rows.\nPlease input again." << endl;
	}

}

//δ����Ƿ��ַ�
//δʵ��Ԫ�ؼӼ�

void SimpleMatrix::print() {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout <<maxtrix[i][j] << " ";
		}
		cout << endl;
	}
}

double SimpleMatrix::calculateRank() {
	if (row!=column)
	{
		cout << "It's not a determinant." << endl;
		return -1;
	}
	double calDet[1024][1024];
	memcpy(calDet, maxtrix, sizeof(maxtrix));

	for (int i = 0; i < row; i++)//ά�ȵݼ�
	{
		int division = i;
		double divisor = maxtrix[i][i];
		while (divisor==0&&i<row-1)
		{
			i++;
			divisor = maxtrix[i][division];
		}//�ҵ���һ������Ԫ�أ�i������������λ��
		if (i==row-1&&divisor==0)
		{
			rank = 0;
			return 0;
		}//����ȫΪ��
		
		//��ʼ����һ����������Ԫ�ػ�Ϊ��,�������м����
		for (int j =division; j < row&&j!=i; j++)//jΪ�к�
		{
			if (calDet[j][division]!=0)
			{//������Ԫ����Ҫ��Ϊ0
			for (int k = division+1; k < row; k++)
			{
				calDet[j][k] = calDet[j][k] -
					calDet[i][k] / divisor * calDet[j][division];
			}
			}//��������Ԫ�ز���0�ĵ�j��
		}
		
	}
	return 0.0;
}
int main()
{
	SimpleMatrix test;
	test.creatMatrix();
	test.print();
}