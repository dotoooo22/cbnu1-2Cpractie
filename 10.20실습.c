//학생정보출력프로그램1

#include <stdio.h>
struct student {
    char name[20];
    int studentNumber;
    int birth;
};


int main(void) {
    int size = 0;
    scanf("%d", &size);
    struct student studentArr[10];

    for (int i = 0; i < size; i++) {
        scanf("%s", &studentArr[i].name);
        scanf("%d", &studentArr[i].studentNumber);
        scanf("%d", &studentArr[i].birth);
    }
    struct student* p = studentArr;
    for (int i = 0; i < size; i++) {
        printf("%10s    %10d    %10d\n", (p + i)->name, (p + i)->studentNumber, (p + i)->birth);
    }

    return 0;
}

//중첩구조체 문제#1-1
#include <stdio.h>

void print_average(struct student const* p);

struct subject {
    int math;
    int eng;
};
struct student {
    char name[20];
    int stunumber;
    struct subject score;
};

void main() {
    int i;
    struct student s[3];
    for (i = 0; i < 3; i++) {
        scanf("%s", &s[i].name);
        scanf("%d", &s[i].stunumber);
        scanf("%d", &s[i].score.eng);
        scanf("%d", &s[i].score.math);
    }
    print_average(s);

    return 0;
}
void print_average(struct student const* p) {
    float sum_eng = 0.0;
    float sum_math = 0.0;

    for (int i = 0; i < 3; i++) {
        sum_eng += (p + i)->score.eng;
        sum_math += (p + i)->score.math;
    }
    printf("영어 평균 : %.1lf    수학 평균 : %.1lf", sum_eng / 3.0, sum_math / 3.0);
}

//중첩구조체 문제 #1-2
#include <stdio.h>

void print_average(struct student const* p);
void printMaxStudent(struct student const* p);

struct subject {
    int math;
    int eng;
};
struct student {
    char name[20];
    int stunumber;
    struct subject score;
};

void main() {
    int i;
    struct student s[3];
    for (i = 0; i < 3; i++) {
        scanf("%s", &s[i].name);
        scanf("%d", &s[i].stunumber);
        scanf("%d", &s[i].score.eng);
        scanf("%d", &s[i].score.math);
    }
    print_average(s);
    printMaxStudent(s);

    return 0;
}
void print_average(struct student const* p) {
    float sum_eng = 0.0;
    float sum_math = 0.0;

    for (int i = 0; i < 3; i++) {
        sum_eng += (p + i)->score.eng;
        sum_math += (p + i)->score.math;
    }
    printf("영어 평균 : %.1lf    수학 평균 : %.1lf\n", sum_eng / 3.0, sum_math / 3.0);
}

void printMaxStudent(struct student const* p) {
    int maxindex = 0;
    float totalscore = 0;
    for (int i = 0; i < 3; i++) {
        totalscore = (p + i)->score.eng + (p + i)->score.math;
        if (totalscore > ((p + maxindex)->score.eng + (p + maxindex)->score.math))
            maxindex = i;
            
    }
    printf("영어와 수학 점수의 합이 제일 큰 학생 : %s", (p + maxindex)->name);
}