#include <stdio.h>
#include <stdlib.h>
void cal_average(int students, int subject, int (*arr)[subject+1]);
void print(int students, int subject, int(*arr)[subject+1]);
void sort(int students, int subject, int(*arr)[subject+1]);
int main(){
    int subject, students;
    printf("subject number : ");
    scanf("%d", &subject);
    printf("student number : ");
    scanf("%d", &students);

    //이차원 배열을 연속적으로 할당하는 방법
    int (*arr)[subject+1]=(int (*)[subject+1])malloc((subject+1)*students*sizeof(int));

    for(int i=0; i<students; i++){
        printf("Input subject's score this student : %d\n",subject);
        for(int j=0; j<subject; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    cal_average(students,subject,arr);
    printf("before sort \n");
    print(students,subject,arr);
    printf("------------------------------------------\n");

    sort(students,subject,arr);
    print(students,subject,arr);
    
    free(arr);
    return 0;
}
//평균값 계산하기
void cal_average(int students, int subject, int (*arr)[subject+1]){
    for(int i=0; i<students; i++){
        int student_score_sum=0;
        for(int j=0; j<subject; j++)
            student_score_sum+=arr[i][j];
        arr[i][subject]=student_score_sum/subject;
    }
}
//arr출력하는 함수
void print(int students, int subject, int(*arr)[subject+1]){
    for(int i=0; i<students; i++){
        for(int j=0; j<subject+1; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
//평균점수를 기준으로 오름차순 정렬하는 함수
void sort(int students, int subject, int(*arr)[subject+1]){
    for(int i=0; i<students-1; i++){
        for(int j=i+1; j<students; j++){
            if(arr[i][subject]>arr[j][subject]){
                // for(int k=0; k<subject+1; k++){
                //     int temp=arr[i][k];

                //     arr[i][k]=arr[j][k];
                //     arr[j][k]=temp;

                //     int
                // }
                int * temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

// #include<stdio.h>

// int main(void)
// {
//  int i, j;
 
//  int arr[2][4] = { {1,2,3,4},{5,6,7,8} };

//  int *temp[2];
//  int *tempp;

//  for (i = 0; i < 2; i++)
//  {
//   temp[i] = arr[i];//행의 주소를 temp배열에 저장
//  }

//  for (i = 0; i < 2; i++)
//  {
//   for (j = 0; j < 4; j++)
//   {
//    printf("%5d", temp[i][j]);
//   }
//   puts("");
//  }
//  puts("");
 
//  tempp = temp[0];
//  temp[0] = temp[1];
//  temp[1] = tempp;

//  for (i = 0; i < 2; i++)
//  {
//   for (j = 0; j < 4; j++)
//   {
//    printf("%5d", temp[i][j]);
//   }
//   puts("");
//  }
//  puts("");
 
//  return 0;
// }