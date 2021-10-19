#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct life {
	char ch[10];
	int score;
};

int main(void) {
	struct life life_j[10];
	int n, s = 0;		//n입력갯수 , s최대점수몇번째인지
	int max_n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		life_j[i].score = 0;
		scanf("%s", &life_j[i].ch);
	}

	for (int i = 0; i < n; i++) {		//i구조체몇번짼지
		for (int j = 0; j < strlen(life_j[i].ch); j++) {	//j문자열몇번째인지
			life_j[i].score += life_j[i].ch[j] - 'a' + 1;	//점수구하기
		}
		if (max_n < life_j[i].score) {	//점수가 여태까지중에 제일 높으면
			max_n = life_j[i].score;	//점수저장
			s = i;						//점수몇번짼지 저장
		}
	}
	printf("%s", life_j[s].ch);	//제일큰점수의 문자열출력


	return 0;
}