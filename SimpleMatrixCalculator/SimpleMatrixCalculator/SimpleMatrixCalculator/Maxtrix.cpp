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
	//矩阵的数据
	double** maxtrix;//二维数组
	int row=0, column=0;
	double rank=0;
	int trace=0;
	double* properValue=NULL;
	//方法
	void creatMatrix();//建立矩阵
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
	//得到行列数
	maxtrix = new double* [row];
	string curLine;
	int rowTest = 0;
	//开始解析输入
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
		//得到本行数据

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
		//存储一行
		rowTest++;
	} while (true);
	if (rowTest < row - 1)
	{
		cout << "Short of rows, only " <<rowTest + 1 << " rows.\nPlease input again." << endl;
	}

}

//未纠错非法字符
//未实现元素加减

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

	for (int i = 0; i < row; i++)//维度递减
	{
		int division = i;
		double divisor = maxtrix[i][i];
		while (divisor==0&&i<row-1)
		{
			i++;
			divisor = maxtrix[i][division];
		}//找到第一个非零元素，i保留这行所在位置
		if (i==row-1&&divisor==0)
		{
			rank = 0;
			return 0;
		}//本列全为零
		
		//开始将第一列所有其他元素化为零,并存入中间矩阵
		for (int j =division; j < row&&j!=i; j++)//j为行号
		{
			if (calDet[j][division]!=0)
			{//本行首元素需要化为0
			for (int k = division+1; k < row; k++)
			{
				calDet[j][k] = calDet[j][k] -
					calDet[i][k] / divisor * calDet[j][division];
			}
			}//处理完首元素不是0的第j行
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