#include <stdio.h>
void Matrixchain(int p[100], int m[100][100], int s[100][100], int n);
void print(int s[][100], int i, int j);
int main() 
{
	int x[100], y[100][100], z[100][100], n, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) 
	{
		scanf_s("%d", &x[i]);
	}
	Matrixchain(x, y, z, n - 1);
	printf("��С�ܴ���Ϊ: %d\n", y[1][n - 1]);
	printf("���Ż�����Ϊ��");
	print(z, 1, n - 1);
}
void Matrixchain(int p[100], int m[100][100], int s[100][100], int n)
{
	int length, i, j, k, t;
	for (length = 2; length <= n; length++)
	{//rΪ��ǰ�����ģ�����ȣ�
		for (i = 1; i <= n - length + 1; i++)
		{ //i����㲻�ϱ仯������r��
			j = i + length - 1;  //��ͬ�յ�
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//����ΪAi(Ai+1...Aj),��ʱk=i
			s[i][j] = i;//��ʼ�� sλ��Ϊi 
			for (k = i + 1; k <= j - 1; k++)
			{
				t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void print(int s[][100], int i, int j)
{//���Ż�����
	if (i == j)
	{
		printf("A%d", i);
	}
	else
	{
		printf("(");
		print(s, i, s[i][j]);
		print(s, s[i][j] + 1, j);
		printf(")");
	}
}