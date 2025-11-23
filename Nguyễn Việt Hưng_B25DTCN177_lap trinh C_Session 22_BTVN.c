/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<string.h>

struct DateOfBirth{
    int day;
    int month;
    int year;
};

struct Student{
    char id[15];
    char name[50];
    char address[100];
    char phoneNumber[15];
    struct DateOfBirth date;
};

void enterStudent(struct Student *arr, int *length) {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    getchar();

    int start = *length;

    for (int i = 0; i < n; i++) {
        int pos = start + i;

        printf("\nSinh vien thu %d:\n", pos + 1);

        printf("Nhap id sinh vien: ");
        fgets(arr[pos].id, sizeof(arr[pos].id), stdin);
        arr[pos].id[strcspn(arr[pos].id, "\n")] = '\0';

        printf("Ten sinh vien: ");
        fgets(arr[pos].name, sizeof(arr[pos].name), stdin);
        arr[pos].name[strcspn(arr[pos].name, "\n")] = '\0';

        printf("Nhap ngay thang nam sinh: ");
        scanf("%d %d %d", &arr[pos].date.day, &arr[pos].date.month, &arr[pos].date.year);
        getchar();

        printf("Dia chi sinh vien: ");
        fgets(arr[pos].address, sizeof(arr[pos].address), stdin);
        arr[pos].address[strcspn(arr[pos].address, "\n")] = '\0';

        printf("So dien thoai sinh vien: ");
        fgets(arr[pos].phoneNumber, sizeof(arr[pos].phoneNumber), stdin);
        arr[pos].phoneNumber[strcspn(arr[pos].phoneNumber, "\n")] = '\0';
    }

    *length += n;
}

void printInfo(struct Student *arr, int length) {
    printf("\n=========== Danh sach sinh vien ===========\n");
    for (int i = 0; i < length; i++) {
        printf("| ID: %s | Name: %s | DateOfBirth: %d/%d/%d | Address: %s | PhoneNumber: %s |\n",
               arr[i].id, arr[i].name,
               arr[i].date.day, arr[i].date.month, arr[i].date.year,
               arr[i].address, arr[i].phoneNumber);
    }
}

void addStudent(struct Student *arr, int *length) {
    int i = *length;
    printf("\n=====Them sinh vien moi=====\n");

    printf("Nhap ID: ");
    scanf("%s", arr[i].id);
    getchar();

    printf("Nhap ten: ");
    fgets(arr[i].name, sizeof(arr[i].name), stdin);
    arr[i].name[strcspn(arr[i].name, "\n")] = '\0';

    printf("Nhap ngay thang nam sinh: ");
    scanf("%d %d %d", &arr[i].date.day, &arr[i].date.month, &arr[i].date.year);
    getchar();

    printf("Nhap dia chi: ");
    fgets(arr[i].address, sizeof(arr[i].address), stdin);
    arr[i].address[strcspn(arr[i].address, "\n")] = '\0';

    printf("Nhap so dien thoai: ");
    scanf("%s", arr[i].phoneNumber);
    getchar();

    (*length)++;
    printf("Da them sinh vien thanh cong!\n");
}

void deleteStudentID(struct Student *arr, int *length) {
    char id[15];
    int found = 0;

    printf("Nhap id sinh vien can xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < *length; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            found = 1;

            for (int j = i; j < *length - 1; j++) {
                arr[j] = arr[j + 1];
            }

            (*length)--;
            printf("Xoa sinh vien thanh cong!\n");
            return;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co id %s\n", id);
    }
}

void updateStudent(struct Student *arr, int length) {
    char id[15];
    printf("Nhap ID sinh vien can cap nhat: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < length; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            printf("\n--- Cap nhat thong tin ---\n");

            printf("Nhap ten moi: ");
            fgets(arr[i].name, sizeof(arr[i].name), stdin);
            arr[i].name[strcspn(arr[i].name, "\n")] = '\0';

            printf("Nhap ngay thang nam sinh moi: ");
            scanf("%d %d %d", &arr[i].date.day, &arr[i].date.month, &arr[i].date.year);
            getchar();

            printf("Nhap dia chi moi: ");
            fgets(arr[i].address, sizeof(arr[i].address), stdin);
            arr[i].address[strcspn(arr[i].address, "\n")] = '\0';

            printf("Nhap so dien thoai moi: ");
            fgets(arr[i].phoneNumber, sizeof(arr[i].phoneNumber), stdin);
            arr[i].phoneNumber[strcspn(arr[i].phoneNumber, "\n")] = '\0';

            printf("Cap nhat thanh cong!\n");
            return;
        }
    }

    printf("Khong tim thay sinh vien!\n");
}

void sortStudent(struct Student *arr, int length) {
    struct Student temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep thanh cong!\n");
}

void searchStudent(struct Student *arr, int length) {
    char id[15];
    printf("Nhap ID can tim: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < length; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            printf("\n--- Ket qua tim thay ---\n");
            printf("ID: %s\n", arr[i].id);
            printf("Ten: %s\n", arr[i].name);
            printf("Ngay sinh: %d/%d/%d\n", arr[i].date.day, arr[i].date.month, arr[i].date.year);
            printf("Dia chi: %s\n", arr[i].address);
            printf("SDT: %s\n", arr[i].phoneNumber);
            return;
        }
    }

    printf("Khong tim thay sinh vien!\n");
}

int main() {
    struct Student arr[100];
    int length = 0;
    int choice = 0;

    do {
        printf("\n====================Menu====================");
        printf("\n1. Nhap thong tin sinh vien");
        printf("\n2. Hien thi thong tin sinh vien");
        printf("\n3. Them sinh vien vao cuoi danh sach");
        printf("\n4. Xoa sinh vien theo id");
        printf("\n5. Cap nhat thong tin sinh vien theo id");
        printf("\n6. Sap xep sinh vien theo ho ten(A-Z)");
        printf("\n7. Tim kiem sinh vien theo id");
        printf("\n8. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                enterStudent(arr, &length);
                break;

            case 2:
                printInfo(arr, length);
                break;

            case 3:
                addStudent(arr, &length);
                break;

            case 4:
                deleteStudentID(arr, &length);
                break;

            case 5:
                updateStudent(arr, length);
                break;

            case 6:
                sortStudent(arr, length);
                break;

            case 7:
                searchStudent(arr, length);
                break;

            case 8:
                printf("Da thoat chuong trinh!\n");
                return 0;

            default:
                printf("Vui long chon tu 1 -> 8!\n");
        }
    } while (1);

    return 0;
}
