#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct life {
	char ch[10];
	int score;
};

int main(void) {
	struct life life_j[10];
	int n, s = 0;		//n�Է°��� , s�ִ��������°����
	int max_n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		life_j[i].score = 0;
		scanf("%s", &life_j[i].ch);
	}

	for (int i = 0; i < n; i++) {		//i����ü���²��
		for (int j = 0; j < strlen(life_j[i].ch); j++) {	//j���ڿ����°����
			life_j[i].score += life_j[i].ch[j] - 'a' + 1;	//�������ϱ�
		}
		if (max_n < life_j[i].score) {	//������ ���±����߿� ���� ������
			max_n = life_j[i].score;	//��������
			s = i;						//�������²�� ����
		}
	}
	printf("%s", life_j[s].ch);	//����ū������ ���ڿ����


	return 0;
}