#include<iostream>
#include<ctime>
#include<cstdlib>

int main(){
	int i, j;

	// ��������
	srand((unsigned)time(NULL));

	for (i = 0; i < 10; i++)
	{
		// ����ʵ�ʵ������
		j = rand();
		cout << "������� " << j << endl;
	}

	return 0;
}