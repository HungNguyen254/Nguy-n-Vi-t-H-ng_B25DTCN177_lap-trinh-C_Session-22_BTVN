#include <stdio.h>
#include <string.h>
typedef struct {
	char name[100];
	int age;
	float grade;
}Student;
void studentinfo(Student *array,int *size){
	int i;
	printf("Nhap so hoc sinh muon nhap:");
	scanf("%d",&*size);
	for (i=0;i<*size;i++){
	printf("Nhap tuoi cua hoc sinh");
	scanf("%d",&array[i].age);
	getchar();
	printf("Nhap ten cua hoc sinh:");
	fgets(array[i].name,sizeof(array[i].name),stdin);
	array[i].name[strcspn(array[i].name,"\n")] = '\0';
	printf("Nhap diem trung binh cua hoc sinh");
	scanf("%f",&array[i].grade);
}
}
void printinfo(Student *array,int *size){
	int i;
	for (i=0;i<*size;i++){
	printf("\n||Ten hoc sinh:%s || tuoi hoc sinh: %d || Diem trung binh:%f ||\n",array[i].name,array[i].age,array[i].grade);
}
}
void avgpoint(Student *array,int *size){
	double avg;
	for (int i=0;i<*size;i++){
		avg += array[i].grade /(*size);
	}
	printf(" diem trung binh cua tat ca hoc sinh la:%f ",avg);
}
int main () {
	int choice =0;
	Student array[100];
	int size=0;
	do {
		printf("\n--------------Menu---------------");
		printf("\n1.Nhap thong tin hoc sinh");
		printf("\n2.Hien thi thong tin hoc sinh");
		printf("\n3.Tinh diem trung binh cua tat ca hoc sinh");
		printf("\nNhap tu 1-3:");
		scanf("%d",&choice);
		switch (choice) {
			case 1:{
				studentinfo(array,&size);
				break;
			}
			case 2:{
				printinfo(array,&size);
				break;
			}
			case 3:{
				avgpoint(array,&size);
				break;
			}
		}
	}while (1);
}

