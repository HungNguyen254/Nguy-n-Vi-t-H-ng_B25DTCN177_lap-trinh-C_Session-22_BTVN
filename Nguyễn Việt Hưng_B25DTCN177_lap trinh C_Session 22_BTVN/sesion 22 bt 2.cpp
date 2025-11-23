#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    int phonenumber;
    char email[100];
}Contact;
void addcontact(Contact *array, int *size) {
    int add;
    printf("Nhap so lien he muon them: ");
    scanf("%d",&add);
    getchar();
    for (int i=0;i<add;i++) {
        printf("Nhap sdt cua lien he: ");
        scanf("%d",&array[*size].phonenumber);
        getchar();
        printf("Nhap ten cua lien he: ");
        fgets(array[*size].name,sizeof(array[*size].name),stdin);
        array[*size].name[strcspn(array[*size].name, "\n")]='\0';
        printf("Nhap email cua lien he: ");
        fgets(array[*size].email,sizeof(array[*size].email),stdin);
        array[*size].email[strcspn(array[*size].email, "\n")] = '\0';
        (*size)++;
    }
}
void printcontact(Contact *array, int *size) {
    for (int i=0;i<*size;i++) {
        printf("\n|| SDT: %d || Ten: %s || Email: %s ||\n",array[i].phonenumber, array[i].name, array[i].email);
    }
}
void searchcontact(Contact *array, int *size) {
    char namesearch[100];
    getchar();
    printf("Nhap ten lien he muon tim: ");
    fgets(namesearch,sizeof(namesearch), stdin);
    namesearch[strcspn(namesearch,"\n")]='\0';
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strstr(array[i].name, namesearch)!=NULL) {
            printf("|| SDT: %d || Ten: %s || Email: %s ||\n",array[i].phonenumber,array[i].name, array[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay lien he ten: %s", namesearch);
    }
}
void deletecontact(Contact *array, int *size) {
    getchar();
    char namedelete[100];
    printf("Nhap ten lien he muon xoa: ");
    fgets(namedelete, sizeof(namedelete), stdin);
    namedelete[strcspn(namedelete, "\n")] = '\0';
    int index = -1;
    for (int i=0;i<*size;i++) {
        if (strcmp(array[i].name,namedelete)==0){
            index=i;
            break;
        }
    }
    if (index==-1){
        printf("Khong tim thay lien he!\n");
        return;
    }
    for (int i=index;i<*size-1;i++) {
        array[i] = array[i + 1];
    }
    (*size)--;
    printcontact(array, size);
}

int main() {
    int choice = 0;
    Contact array[100];
    int size = 0;
    do {
        printf("\n--------------Menu---------------");
        printf("\n1. Them lien he moi");
        printf("\n2. Hien thi tat ca cac lien he");
        printf("\n3. Tim kiem lien he theo ten");
        printf("\n4. Xoa lien he theo ten");
        printf("\n5.Thoat chuong trinh");
        printf("\nNhap tu 1-4: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:{
            	addcontact(array, &size); 
				break;
			}
            case 2:{
            	printcontact(array, &size);
				break;
			}
            case 3:{
            	searchcontact(array, &size);
				break;
			}
            case 4:{
            	deletecontact(array, &size);
				break;
			}
			case 5:{
				printf("Tam biet");
				return 0;
				break;
			}
        }
    } while (1);
}

