#include <iostream>
using namespace std;
const int N=5;

//�Գƾ���ѹ���󣺴洢����λ��N*(N+1)/2
//���i>=j,��Ԫ��λ�������ǲ���,ֱ���ù�ʽi*(i+1)/2��ǰ���е�����Ԫ�ء�+j
//���i<j,���������ǲ��֣����ڶԳ��ԣ�ͬ��j*(j+1)/2��ij=ji,����һ����ʽ�� 


int main()
{
	////////����1//////////
	int A[N][N];
	///////////////////////
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<=i;j++)
			A[i][j]=A[j][i]=i+j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
        ////////����2//////////
	int SA[N*(N+1)/2];
	int index = 0;
	for (int i = 0; i < N;i++){
		for (int j = 0; j <= i;j++){
			SA[index++] = A[i][j];
		}
	}
		///////////////////////
		cout << "�������кź��кţ�";
	cin>>i>>j;
	cout<<i<<"��"<<j<<"�е�Ԫ��ֵ��:";
        ////////����3//////////
	if(i>=j){
		cout << SA[i * (i + 1) / 2 + j] << endl;
	}
	else{
		cout << SA[j * (j + 1) / 2 + i] << endl;
	}
	///////////////////////
	system("pause");
	return 0;
}