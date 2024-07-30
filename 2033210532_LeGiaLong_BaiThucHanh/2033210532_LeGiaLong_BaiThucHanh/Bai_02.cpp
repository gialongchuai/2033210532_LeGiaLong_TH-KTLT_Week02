/*
	Bài 2. Tạo mảng 1 chiều b chứa hỗn số (gồm 2 thành phần: phần nguyên và phân số). Viết các
	hàm:
	1. Tạo mảng b chứa giá trị hỗn số ngẫu nhiên. Lưu ý mẫu khác 0.
	2. Xuất danh sách hỗn số.
	3. So sánh 2 hỗn số.
	4. Chuyển hỗn số -> phân số
	5. Chuyển phân số -> hỗn số.
	6. Tính tổng, hiệu, tích, thương 2 hỗn số.
	7. Sắp xếp b tăng/giảm theo 3 giải thuật sắp xếp đã học
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int phanNguyen;
	int tuSo;
	int mauSo;
} HonSo;

void taoMangHonSo(HonSo b[], int n);
void xuatMangHonSo(HonSo b[], int n);
int soSanhHonSo(HonSo a, HonSo b);
void chuyenHonSoSangPhanSo(HonSo hs, int* tuSo, int* mauSo);
HonSo chuyenPhanSoSangHonSo(int tuSo, int mauSo);
HonSo tongHonSo(HonSo a, HonSo b);
HonSo hieuHonSo(HonSo a, HonSo b);
HonSo tichHonSo(HonSo a, HonSo b);
HonSo thuongHonSo(HonSo a, HonSo b);
void sapXepTangDan(HonSo b[], int n);
void sapXepGiamDan(HonSo b[], int n);
void doiCho(HonSo *a, HonSo *b);

int main() {
	int n, choice;
	HonSo b[100];

	printf("Nhap so luong phan tu cua mang: ");
	scanf("%d", &n);

	do {
		printf("\nMenu\n");
		printf("1. Tao mang hon so\n");
		printf("2. Xuat mang hon so\n");
		printf("3. So sanh 2 hon so\n");
		printf("4. Chuyen hon so sang phan so\n");
		printf("5. Chuyen phan so sang hon so\n");
		printf("6. Tinh tong, hieu, tich, thuong 2 hon so\n");
		printf("7. Sap xep tang/giam mang hon so\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			taoMangHonSo(b, n);
			break;
		case 2:
			xuatMangHonSo(b, n);
			break;
		case 3: {
					int i, j;
					printf("Nhap chi so cua 2 hon so can so sanh (0-%d): ", n - 1);
					scanf("%d %d", &i, &j);
					int cmp = soSanhHonSo(b[i], b[j]);
					if (cmp > 0)
						printf("Hon so thu %d lon hon hon so thu %d\n", i, j);
					else if (cmp < 0)
						printf("Hon so thu %d nho hon hon so thu %d\n", i, j);
					else
						printf("2 hon so bang nhau\n");
					break;
		}
		case 0:
			printf("Thoat chuong trinh\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (choice != 0);

	return 0;
}

void taoMangHonSo(HonSo b[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		b[i].phanNguyen = rand() % 10;
		b[i].tuSo = rand() % 10;
		b[i].mauSo = rand() % 9 + 1; // mau so khac 0
	}
}

void xuatMangHonSo(HonSo b[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d/%d\n", b[i].phanNguyen, b[i].tuSo, b[i].mauSo);
	}
}

int soSanhHonSo(HonSo a, HonSo b) {
	int tuSoA, mauSoA, tuSoB, mauSoB;
	chuyenHonSoSangPhanSo(a, &tuSoA, &mauSoA);
	chuyenHonSoSangPhanSo(b, &tuSoB, &mauSoB);
	int phanSoA = tuSoA * mauSoB;
	int phanSoB = tuSoB * mauSoA;
	return phanSoA - phanSoB;
}

void chuyenHonSoSangPhanSo(HonSo hs, int* tuSo, int* mauSo) {
	*tuSo = hs.phanNguyen * hs.mauSo + hs.tuSo;
	*mauSo = hs.mauSo;
}

HonSo chuyenPhanSoSangHonSo(int tuSo, int mauSo) {
	HonSo hs;
	hs.phanNguyen = tuSo / mauSo;
	hs.tuSo = tuSo % mauSo;
	hs.mauSo = mauSo;
	return hs;
}