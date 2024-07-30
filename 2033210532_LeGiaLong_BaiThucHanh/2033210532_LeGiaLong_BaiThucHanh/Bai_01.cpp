/*
	Bài 1. Cho mảng một chiều a chứa n số nguyên. Xây dựng hàm thực hiện các yêu cầu sau:
	Lưu ý:
	- Để lấy số ngẫu nhiên từ 0 đến k, ta sử dụng rand()%(k+1)
	- Để lấy số ngẫu nhiên từ a đến b, ta sử dụng a + rand()%(b-a+1)
	1. Tạo mảng một chiều ngẫu nhiên có số phần tử lớn hơn hoặc bằng 15.
	2. Tạo mảng chứa toàn số chẵn.
	3. Tìm kiếm x trong a (trả về vị trí của x/ trả lời có hoặc không?) theo giải thuật tìm kiếm
	tuyến tính Linear Search.
	4. Sắp xếp a tăng dần/giảm dần theo giải thuật Interchange Sort.
	5. Tìm kiếm x trong a (trả về vị trí của x/ trả lời có hoặc không?) theo giải thuật tìm kiếm
	Binary Search với mảng a đã được sắp tăng.
	6. Sắp xếp a tăng dần theo giải thuật Selection Sort.
	7. Sắp xếp a tăng dần theo giải thuật Quick Sort.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createArray(int a[], int *n) {
    *n = rand() % 11 + 15; // Kích thước ngẫu nhiên từ 15 đến 25
    for(int i = 0; i < *n; i++) {
        a[i] = rand() % 101; // Số ngẫu nhiên từ 0 đến 100
    }
}

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void createEvenArray(int a[], int n, int evenArray[], int *evenCount) {
	*evenCount = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			evenArray[*evenCount] = a[i];
			(*evenCount)++;
		}
	}
}

int linearSearch(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) return i;
	}
	return -1;
}

void interchangeSort(int a[], int n, int ascending) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((ascending && a[i] > a[j]) || (!ascending && a[i] < a[j])) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int binarySearch(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) return mid;
		if (a[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

void selectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minIdx]) {
				minIdx = j;
			}
		}
		int temp = a[i];
		a[i] = a[minIdx];
		a[minIdx] = temp;
	}
}

int main() {
    srand(time(0));
    int a[100], n;
    int evenArray[100], evenCount;
    int x, result;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tao mang ngau nhien\n");
        printf("2. Tao mang chua toan so chan\n");
        printf("3. Tim kiem x trong mang theo Linear Search\n");
        printf("4. Sap xep mang tang/giam dan theo Interchange Sort\n");
        printf("5. Tim kiem x trong mang theo Binary Search\n");
        printf("6. Sap xep mang tang dan theo Selection Sort\n");
        printf("7. Sap xep mang tang dan theo Quick Sort\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createArray(a, &n);
                printf("Mang ngau nhien: ");
                printArray(a, n);
                break;
			case 2:
				createEvenArray(a, n, evenArray, &evenCount);
				printf("Mang so chan: ");
				printArray(evenArray, evenCount);
				break;
			case 3:
				printf("Nhap gia tri x: ");
				scanf("%d", &x);
				result = linearSearch(a, n, x);
				if (result != -1)
					printf("Tim thay x o vi tri: %d\n", result);
				else
					printf("Khong tim thay x\n");
				break;
			case 4:
				printf("1. Tang dan\n");
				printf("2. Giam dan\n");
				printf("Nhap lua chon: ");
				int order;
				scanf("%d", &order);
				interchangeSort(a, n, order == 1);
				printf("Mang sau khi sap xep: ");
				printArray(a, n);
				break;
			case 5:
				selectionSort(a, n); // Mang can duoc sap xep truoc khi tim kiem binary
				printf("Nhap gia tri x: ");
				scanf("%d", &x);
				result = binarySearch(a, n, x);
				if (result != -1)
					printf("Tim thay x o vi tri: %d\n", result);
				else
					printf("Khong tim thay x\n");
				break;
            case 8:
                printf("Thoat chuong trinh\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while(choice != 8);

    return 0;
}
