#include<bits/stdc++.h> 
using namespace std;
const int N = 100;
int C[N][N],//BC��ֵΪ0
	B[N][N];//B��ֵ��1ɾ��y 2ɾ��x 3ɾ������
int m = 7, n = 6;
string X = " ABCBDAB", Y = " BDCABA",ans;

void print(int i, int j) {
	if (!i || !j) {
		cout <<"�����������Ϊ��" <<ans << endl;
		return;
	}
	if (B[i][j] == 3) {
		ans = X[i] + ans;
		print(i - 1, j - 1);
	}
	else if (B[i][j] == 1)
		print(i - 1, j);
	else print(i, j - 1);
}

int main() {
	cout << "����X" << X << endl;
	cout << "����Y" << Y << endl;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 3;
			}
			else {
				if (C[i][j - 1] >= C[i - 1][j]) {
					C[i][j] = C[i][j - 1];
					B[i][j] = 2;
				}
				else {
					C[i][j] = C[i-1][j];
					B[i][j] = 1;//ɾ��x
				}
			}
		}
	}
	cout << "����������г���Ϊ��"<<C[m][n] << endl;
	print(m, n);
}
