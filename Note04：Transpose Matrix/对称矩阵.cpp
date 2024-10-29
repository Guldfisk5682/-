#include <iostream>
using namespace std;
const int N=5;

//对称矩阵压缩后：存储三角位置N*(N+1)/2
//如果i>=j,则元素位于下三角部分,直接用公式i*(i+1)/2【前面行的所有元素】+j
//如果i<j,则在上三角部分，由于对称性，同理j*(j+1)/2【ij=ji,所以一个公式】 


int main()
{
	////////补充1//////////
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
        ////////补充2//////////
	int SA[N*(N+1)/2];
	int index = 0;
	for (int i = 0; i < N;i++){
		for (int j = 0; j <= i;j++){
			SA[index++] = A[i][j];
		}
	}
		///////////////////////
		cout << "请输入行号和列号：";
	cin>>i>>j;
	cout<<i<<"行"<<j<<"列的元素值是:";
        ////////补充3//////////
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