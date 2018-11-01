#include<iostream>
#include<ctime>
#include<cstdlib>

int main(){
	int i, j;

	// 设置种子
	srand((unsigned)time(NULL));

	for (i = 0; i < 10; i++)
	{
		// 生成实际的随机数
		j = rand();
		cout << "随机数： " << j << endl;
	}

	return 0;
}