#include <iostream>
using namespace std;

const int MAX_LEN = 100;

void enterArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "\nNhap phan tu thu [" << i << "]: ";
		cin >> array[i];
	}
}

void printArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << "  ";
	}
	cout << " {Total: " << len << "}";
}

//1	Viết hàm xuất các số âm trong mảng
void cau1(int array[], int len)
{
	cout << "\n\nCac so am trong mang la:";
	for (int i = 0; i < len; i++)
	{
		if (array[i] < 0)//Điều kiện số âm
		{
			cout << array[i] << "  ";
		}
	}
}
//2	Viết hàm xuất các giá trị chẵn có ít nhất một lân cận cũng là giá trị chẵn
void cau2(int array[], int len)
{
	cout << "\n\nCac gia tri chan co it nhat mot lan can cung la gia tri chan luon:";
	for (int i = 0; i < len; i++)
	{
		if (array[i] % 2 == 0)
		{
			int preIndex = i - 1;
			int nextIndex = i + 1;
			if (preIndex >= 0 && array[preIndex] % 2 == 0)
			{
				cout << array[i] << "  ";
			}
			else if (nextIndex < len && array[nextIndex] % 2 == 0)
			{
				cout << array[i] << "  ";
			}
		}
	}
}

//3	Viết hàm xuất các vị trí của số chẵn lớn nhất trong mảng
int timGiaTriChanLonNhatTrongMang(int array[], int len)
{
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		if (array[i] % 2 == 0)
		{
			if (max == -1)
			{
				max = array[i];
			}
			else if (array[i] > max)
			{
				max = array[i];
			}
		}
	}
	return max;
}
void cau3(int array[], int len)
{
	int max = timGiaTriChanLonNhatTrongMang(array, len);
	if (max == -1)
	{
		cout << "\n\nMang khong ton tai gia tri Chan";
	}
	else
	{
		cout << "\n\nVi tri cac so chan Lon Nhat Trong mang la: ";
		for (int i = 0; i < len; i++)
		{
			if (max == array[i])
			{
				cout << i << "  ";
			}
		}
	}
}
//4	Viết hàm xuất tổng các giá trị đối xứng trong mảng các số nguyên. 1221 , 12321
bool isSymmetric(int num)
{
	int ori = num;
	int reversed = 0;

	if (num < 0) return false;
	while (num > 0)
	{
		int digit = num % 10;
		reversed = reversed * 10 + digit;
		num /= 10;
	}
	return ori == reversed;
}
void cau4(int array[], int len)
{
	cout << "\n\nTong cac gia tri doi xung trong mang: ";
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (isSymmetric(array[i]))
		{
			sum += array[i];
		}
	}
	cout << sum;
}
//5	Viết hàm xuất ra số lượng số chẵn có trong mảng.
void cau5(int array[], int len)
{
	cout << "\n\nSo luong so chan co trong mang: ";
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] % 2 == 0)
		{
			count++;
		}
	}
	cout << count;
}
//6	Viết hàm xuất các giá trị xuất hiện trong dãy quá một lần.Lưu ý : mỗi giá trị liệt kê một lần.
void cau6(int array[], int len)
{
	cout << "\n\nCac gia tri xuat hien trong Mang qua mot lan:";
	for (int i = 0; i < len; i++)
	{
		bool isDuplicated = false;
		for (int j = 0; j < i; j++)
		{
			if (array[i] == array[j])
			{
				isDuplicated = true;
				break;
			}
		}
		if (isDuplicated == true)
		{
			continue;
		}
		int count = 0;
		for (int j = 0; j < len; j++)
		{
			if (array[i] == array[j])
			{
				count++;
			}
		}
		if (count > 1)
		{
			cout << array[i] << "  ";
		}
	}
}
//7	Viết hàm xuất ra “giá trị nhỏ nhất” trong mảng
void cau7(int array[], int len)
{
	int min = array[0];
	for (int i = 1; i < len; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	cout << "\n\nGia tri nho nhat trong mang:" << min;
}
//8	Viết hàm trả về “giá trị dương nhỏ nhất” trong mảng, nếu không có thì trả về - 1
int cau8(int array[], int len)
{
	int min = -1;
	for (int i = 0; i < len; i++)
	{
		if (array[i] >= 0)
		{
			if (min == -1)
			{
				min = array[i];
			}
			else if (min > array[i])
			{
				min = array[i];
			}
		}
	}
	cout << "\n\nGia tri Duong Nho Nhat Trong mang: " << min;
	return min;
}
//9	Viết hàm xuất vị trí số dương lớn nhất cuối cùng trong mảng
int timSoDuongLonNhatTrongMang(int array[], int len)
{
	int max = -1;
	for (int i = 0; i < len; i++)
	{
		if (array[i] >= 0)
		{
			if (max == -1)
			{
				max = array[i];
			}
			else if (array[i] > max)
			{
				max = array[i];
			}
		}
	}
	return max;
}
void cau9(int array[], int len)
{
	int max = timSoDuongLonNhatTrongMang(array, len);
	if (max == -1)
	{
		cout << "\n\nMang khong ton tai gia tri Duong!";
	}
	else
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (array[i] == max)
			{
				cout << "\n\nVi Tri cuoi cung cua so Duong Lon Nhat [" << max << "] trong Mang la:" << i;
				break;
			}
		}
	}
}
//10	Viết hàm thực hiện Sắp xếp mảng a có thứ tự tăng dần.
//Selection Sort
void selectionSort(int array[], int len)
{
	// 2 1 3
	// 0 1 2
	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}
void cau10(int array[], int len)
{
	int oriArray[MAX_LEN];
	for (int i = 0; i < len; i++)
	{
		oriArray[i] = array[i];
	}
	selectionSort(array, len);
	cout << "\n\nMang sau khi duoc sap xep tang dan:";
	printArray(array, len);


	for (int i = 0; i < len; i++)
	{
		array[i] = oriArray[i];
	}
}

//11	Viết hàm Trả về số lượng phần tử có giá trị là x.
void cau11(int array[], int len)
{
	int x;
	cout << "\n\nNhap x: ";
	cin >> x;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			count++;
		}
	}
	cout << "\nSo luong phan tu co gia tri la " << x << ": " << count;
}
//12	Viết hàm Trả về địa chỉ phần tử có giá trị x tìm thấy đầu tiên trong danh sách
void cau12(int array[], int len)
{
	int x;
	cout << "\n\nNhap x: ";
	cin >> x;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			cout << "\nVi tri phan tu co gia tri la " << x << " dau tien: " << i;
			break;
		}
	}
}
//13	Viết hàm Trả về địa chỉ phần tử có giá trị x tìm thấy cuối cùng trong danh sách
void cau13(int array[], int len)
{
	int x;
	cout << "\n\nNhap x: ";
	cin >> x;
	for (int i = len - 1; i >= 0; i--)
	{
		if (array[i] == x)
		{
			cout << "\nVi tri phan tu co gia tri la " << x << " cuoi cung: " << i;
			break;
		}
	}
}
//14	Viết hàm Trả về địa chỉ phần tử có giá trị x thứ 2 tìm thấy trong danh sách
void cau14(int array[], int len)
{
	int x;
	cout << "\n\nNhap x: ";
	cin >> x;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			count++;
			if (count == 2)
			{
				cout << "\nVi tri phan tu co gia tri la " << x << " tim thay thu 2 trong danh sach: " << i;
				break;
			}
		}
	}
}
//15	Kiểm tra mảng có tăng hay không ? Nếu có trả về 1, ngược lại trả về 0.
bool cau15(int array[], int len)
{
	for (int i = 1; i < len; i++)
	{
		if (array[i] <= array[i - 1])
		{
			cout << "\n\nMang Khong Tang!";
			return false;
		}
	}
	cout << "\n\nMang Tang!";
	return true;
}
void loaiBoGiaTriTrung(int array[], int& len)
{
	int tempArray[MAX_LEN];
	int tempLen = 0;
	for (int i = 0; i < len; i++)
	{
		bool isDuplicated = false;
		for (int j = 0; j < tempLen; j++)
		{
			if (array[i] == tempArray[j])
			{
				isDuplicated = true;
			}
		}
		if (isDuplicated == true)
		{
			continue;
		}
		else
		{
			tempArray[tempLen] = array[i];
			tempLen++;
		}
	}
	len = tempLen;
	for (int i = 0; i < tempLen; i++)
	{
		array[i] = tempArray[i];
	}
}
//16	Viết hàm xuất ra các phần tử có giá trị bằng tổng 02 phần tử kế tiếp.
void cau16(int array[], int len)
{
	cout << "\n\nCac phan tu co gia tri bang tong 2 phan tu ke tiep: ";
	for (int i = 0; i < len - 2; i++)
	{
		if (array[i] == array[i + 1] + array[i + 2])
		{
			cout << array[i] << "  ";
		}
	}
}
//17	Viết hàm xuất ra các phần tử có giá trị bằng tổng 02 phần tử liền kề trước đó.
void cau17(int array[], int len)
{
	cout << "\n\nCac phan tu co gia tri bang tong 2 phan tu ke tiep: ";
	for (int i = 2; i < len; i++)
	{
		if (array[i] == array[i - 1] + array[i - 2])
		{
			cout << array[i] << "  ";
		}
	}
}

//18	Viết hàm kiểm tra trong mảng này có phần tử nào là số nguyên tố hay không ? 
// Nếu có trả về vị trí phần tử đầu tiên được tìm thấy.
bool kiemTraNguyenTo(int num)
{
	if (num < 2) return false;
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}
void cau18(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (kiemTraNguyenTo(array[i]) == true)
		{
			cout << "\n\nVi tri phan tu la so nguyen to dau tien [" << array[i] << "] :" << i;
			break;
		}
	}
}
//19	Viết hàm trả về số lượng các số hoàn hảo được tìm thấy trong danh sách.
bool kiemTraHoanHao(int num)
{
	if (num < 6) return false;
	int sum = 0;
	for (int i = 1; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			sum += i;
		}
	}
	if (sum == num)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void cau19(int array[], int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (kiemTraHoanHao(array[i]) == true)
		{
			count++;
		}
	}
	cout << "\n\nSo luong so hoan hao co trong mang:" << count;
}
//20	Viết hàm xuất ra giá trị các phần tử có giá trị là số chính phương.
bool kiemTraChinhPhuong(int num)
{
	if (num < 4) return false;
	for (int i = 2; i < num; i++)
	{
		if (i * i == num)
		{
			return true;
		}
	}
	return false;
}
void cau20(int array[], int len)
{
	cout << "\n\nCac gia tri chinh phuon co trong mang:";
	for (int i = 0; i < len; i++)
	{
		if (kiemTraChinhPhuong(array[i]) == true)
		{
			cout << array[i] << "  ";
		}
	}
}
//21	Viết hàm kiểm tra mảng có phải là dãy cấp số nhân 3 hay không ? Nếu có trả về 1, ngược lại, trả về 0.
//VD: 1 3 9 27
bool kiemTraCapSoNhan3(int array[], int len)
{
	if (len < 2)
	{
		return true;
	}
	for (int i = 1; i < len; i++)
	{
		if (array[i] != array[i - 1] * 3)
		{
			return false;
		}

	}
	return true;
}
void cau21(int array[], int len)
{
	bool isX3 = kiemTraCapSoNhan3(array, len);
	if (isX3 == true)
	{
		cout << "\n\nMang la cap so nhan 3!";
	}
	else

	{
		cout << "\n\nMang khong phai cap so nhan 3!";
	}
}
//22	Viết hàm trả về giá trị số âm lớn nhất trong mảng
void cau22(int array[], int len)
{
	int soAmLonNhat = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] < 0)
		{
			if (soAmLonNhat == 0)
			{
				soAmLonNhat = array[i];
			}
			else if (array[i] > soAmLonNhat)
			{
				soAmLonNhat = array[i];
			}
		}
	}
	if (soAmLonNhat == 0)
	{
		cout << "\n\nMang khong ton tai so am!";
	}
	else
	{
		cout << "\n\nSo am lon nhat trong mang la: " << soAmLonNhat;
	}
}
//23	Sử dụng thuật toán sắp xếp tuần tư, hãy viết hàm sắp xếp mảng giảm dần.
void optionSelectionSort(int array[], int len, bool mode)
{
	for (int i = 0; i < len - 1; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < len; j++)
		{
			if (mode == true)//Sap xep tang dan
			{
				if (array[j] < array[minIndex])
				{
					minIndex = j;
				}
			}
			else//Giam dan
			{
				if (array[j] > array[minIndex])
				{
					minIndex = j;
				}
			}

		}
		if (minIndex != i)
		{
			int temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
	}
}
void cau23(int array[], int len)
{
	cout << "\n\nMang truoc khi duoc sap xep giam: ";
	printArray(array, len);
	cout << "\n\nMang sau khi duoc sap xep giam dan: ";
	optionSelectionSort(array, len, false);
	printArray(array, len);
}
//24	Viết hàm chèn giá trị a vào trước phần tử có giá trị x.
void cau24(int array[], int& len)
{
	if (len == MAX_LEN)
	{
		cout << "\n\nMang day!";
		return;
	}
	int a, x;
	cout << "\nNhap a can chen: ";
	cin >> a;
	cout << "\nNhap gia tri x: ";
	cin >> x;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			if (len == MAX_LEN)
			{
				cout << "\n\nMang day!";
				cout << "\nHam dung lai o " << x << " thu " << count + 1;
				break;
			}
			else
			{
				for (int j = len; j != i; j--)
				{
					// 5 6 7
					// 5 6 7 7
					// 5 6 6 7
					// 5 0 6 7
					array[j] = array[j - 1];
				}
				array[i] = a;
				len++;
				i++;
				count++;
			}
		}
	}
	if (count > 0)
	{
		cout << "\n\nMang sau khi chen " << a << " vao truoc cac phan tu co gia tri la " << x << ": ";
		printArray(array, len);
	}
	else
	{
		cout << "\n\nKhong tim thay gia tri " << x << " trong mang!";
	}
}
//25	Viết hàm chèn giá trị a vào sau phần tử có giá trị x.
void cau25(int array[], int& len)
{
	if (len == MAX_LEN)
	{
		cout << "\n\nMang day!";
		return;
	}
	int a, x;
	cout << "\nNhap a can chen: ";
	cin >> a;
	cout << "\nNhap gia tri x: ";
	cin >> x;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			if (len == MAX_LEN)
			{
				cout << "\n\nMang day!";
				cout << "\nHam dung lai o " << x << " thu " << count + 1;
				break;
			}
			else
			{
				for (int j = len; j != i; j--)
				{
					// 5 6 7
					// 5 6 7 7
					// 5 6 6 7
					// 5 0 6 7
					array[j] = array[j - 1];
				}
				array[i + 1] = a;
				len++;
				i++;
				count++;
			}
		}
	}
	if (count > 0)
	{
		cout << "\n\nMang sau khi chen " << a << " vao truoc cac phan tu co gia tri la " << x << ": ";
		printArray(array, len);
	}
	else
	{
		cout << "\n\nKhong tim thay gia tri " << x << " trong mang!";
	}
}
//26	Viết hàm chèn giá trị a vào sau vị trí pos.
//   7 8 9
//ps 0 1 2
//a = 5, pos = 1
//>  7 8 5 9

void cau26(int array[], int len)
{
	if (len == MAX_LEN)
	{
		cout << "\n\nMang day!";
		return;
	}
	int a, pos;
	cout << "\nNhap a can chen: ";
	cin >> a;
	cout << "\nNhap vi tri pos: ";
	cin >> pos;
	if (pos < 0 || pos >= len)
	{
		cout << "\n\nPosition khong hop le!";
		return;
	}
	for (int i = len; i > pos + 1; i--)
	{
		array[i] = array[i - 1];
	}
	array[pos + 1] = a;
	len++;
	cout << "\n\nMang sau khi chen " << a << " vao sau vi tri " << pos << ": ";
	printArray(array, len);
}
//27	Viết hàm chèn giá trị a vào trước vị trí pos.
//  7 8 9
//  0 1 2
// 
// pos = 1, a =5
// 
//	5 7 8 9
//	0 1 2 3
void cau27(int array[], int len)
{
	if (len == MAX_LEN)
	{
		cout << "\n\nMang day!";
		return;
	}
	int a, pos;
	cout << "\nNhap a can chen: ";
	cin >> a;
	cout << "\nNhap vi tri pos: ";
	cin >> pos;
	if (pos < 1 || pos >= len)
	{
		cout << "\n\nPosition khong hop le!";
		return;
	}
	for (int i = len; i > pos - 1; i--)
	{
		array[i] = array[i - 1];
	}
	array[pos - 1] = a;
	len++;
	cout << "\n\nMang sau khi chen " << a << " vao sau vi tri " << pos << ": ";
	printArray(array, len);
}
//28	Viết hàm xóa phần tử có giá trị x đầu tiên được tìm thấy
//vd 5 6 7
//ps 0 1 2
//   6 6 7
//   6 7 7
//   6 7
void cau28(int array[], int len)
{
	int x;
	bool found = false;
	cout << "\n\nNhap x can xoa: ";
	cin >> x;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			if (found == false)
			{
				found = true;
				for (int j = i; j < len - 1; j++)
				{
					array[j] = array[j + 1];
				}
				array[len - 1] = 0;
				len--;
				break;
			}
		}
	}
	cout << "\n\nMang sau khi xoa phan tu co gia tri " << x << " dau tien duoc tim thay: ";
	printArray(array, len);
}
//29	Viết hàm xóa phần tử có giá trị x cuối cùng được tìm thấy
void cau29(int array[], int len)
{
	int x;
	bool found = false;
	cout << "\n\nNhap x can xoa: ";
	cin >> x;
	for (int i = len-1; i != 0; i--)
	{
		if (array[i] == x)
		{
			if (found == false)
			{
				found = true;
				for (int j = i; j < len - 1; j++)
				{
					array[j] = array[j + 1];
				}
				array[len - 1] = 0;
				len--;
				break;
			}
		}
	}
	cout << "\n\nMang sau khi xoa phan tu co gia tri " << x << " cuoi cung duoc tim thay: ";
	printArray(array, len);
}
//30	Viết hàm xóa tất cả các phần tử có giá trị x.
void cau30(int array[], int len)
{
	int x;
	int count = 0;
	cout << "\n\nNhap x can xoa: ";
	cin >> x;
	for (int i = len -1 ; i >= 0; i--)
	{
		if (array[i] == x)
		{
			count++;
			for (int j = i; j < len - 1; j++)
			{
				array[j] = array[j + 1];
			}
			array[len - 1] = 0;
			len--;
		}
	}
	if (count > 0)
	{
		cout << "\n\nMang sau khi xoa tat ca phan tu co gia tri " << x << " duoc tim thay: ";
		printArray(array, len);
	}
	else
	{
		cout << "\n\nKhong tim thay phan tu nao co gia tri "<<x;
	}
}
//31	Viết hàm xóa phần tử có giá trị x thứ 2 được tìm thấy.
void cau31(int array[], int len)
{
	int x;
	int count = 0;
	cout << "\n\nNhap x can xoa: ";
	cin >> x;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			count++;
			if (count > 1)
			{
				for (int j = i; j < len - 1; j++)
				{
					array[j] = array[j + 1];
				}
				array[len - 1] = 0;
				len--;
				break;
			}
		}
	}
	if (count > 1)
	{
		cout << "\n\nMang sau khi xoa phan tu co gia tri " << x << " thu 2 duoc tim thay: ";
		printArray(array, len);
	}
	else
	{
		cout << "\n\nKhong tim thay phan tu co gia tri " << x << " thu 2!";
	}
}
//32	Viết hàm xóa tất cả các phần tử có giá trị x từ phần tử thứ 2 trở đi được tìm thấy.
//vd 1 2 1 5
//   0 1 2 3 4
void cau32(int array[], int len)
{
	int x;
	int count = 0;
	cout << "\n\nNhap x can xoa: ";
	cin >> x;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			count++;
			if (count > 1)
			{
				for (int j = i; j < len - 1; j++)
				{
					array[j] = array[j + 1];
				}
				array[len - 1] = 0;
				len--;
				i--;
			}
		}
	}
	if (count > 1)
	{
		cout << "\n\nMang sau khi xoa phan tu co gia tri " << x << " thu 2 duoc tim thay: ";
		printArray(array, len);
	}
	else
	{
		cout << "\n\nKhong tim thay phan tu co gia tri " << x << " thu 2!";
	}
}
//33	Viết hàm thay thế các phần tử có giá trị x sang giá trị y.
void cau33(int array[], int len)
{
	int x, y;
	cout << "\n\nNhap x: ";
	cin >> x;
	cout << "\n\nNhap y: ";
	cin >> y;
	bool found = false;
	for (int i = 0; i < len; i++)
	{
		if (array[i] == x)
		{
			if (!found)
			{
				found = true;
				array[i] = y;
			}
			else
			{
				array[i] = y;
			}
		}
	}
	if (found)
	{
		cout << "\n\nMang sau khi thay " << x << " thanh " << y << " :";
		printArray(array, len);
	}
	else
	{
		cout << "\n\nKhong tim thay phan tu mang gia tri " << x;
	}
}
//34	Cho 02 mảng D1 và D2, viết hàm chèn xen kẻ các phần tử D2 vào D1
void cau34()
{
	int d1[MAX_LEN], d2[MAX_LEN], d3[MAX_LEN];
	int len1, len2, len3;
	cout << "\n\nNhap so luong phan tu D1:";
	cin >> len1;
	enterArray(d1, len1);
	cout << "\n\nNhap so luong phan tu D2:";
	cin >> len2;
	enterArray(d2, len2);

	int i = 0, j = 0, k = 0;
	//Vòng lặp chính để chèn xen kẻ d2 vào d1
	// d1 1  2  3
	// d2 99 88 77 66 55
	// d3 1  99 2 88 3 77 66 55
	while (i < len1 && j < len2)
	{
		d3[k] = d1[i];
		k++;
		d3[k] = d2[j];
		k++;
		i++;
		j++;
	}

	while (i < len1)
	{
		d3[k] = d1[i];
		k++;
		i++;
	}

	while (j < len2)
	{
		d3[k] = d2[j];
		k++;
		j++;
	}

	len3 = len1 + len2;

	cout << "\n\nMang sau khi chen xet ke: ";
	printArray(d3, len3);
}
//35	Giả sử, cho 02 mảng d1 và d2 có thứ tự tăng, viết hàm chèn các phần tử d2 vào d1 sao cho d1 vẫn có thứ tự
void cau35()
{
	int d1[MAX_LEN], d2[MAX_LEN], d3[MAX_LEN];
	int len1, len2, len3;
	cout << "\n\nNhap so luong phan tu D1:";
	cin >> len1;
	enterArray(d1, len1);
	cout << "\n\nNhap so luong phan tu D2:";
	cin >> len2;
	enterArray(d2, len2);

	selectionSort(d1, len1);
	selectionSort(d2, len2);

	cout << "\n\nD1: ";
	printArray(d1, len1);
	cout << "\n\nD2: ";
	printArray(d2, len2);

	int i = 0, j = 0, k = 0;
	//Vòng lặp chính để chèn xen kẻ d2 vào d1
	// d1 1  2  3
	// d2 99 88 77 66 55
	// d3 1  99 2 88 3 77 66 55
	while (i < len1 && j < len2)
	{
		if (d1[i] < d2[j])
		{
			d3[k++] = d1[i++];
		}
		else
		{
			d3[k++] = d2[j++];
		}
	}

	while (i < len1)
	{
		d3[k++] = d1[i++];
	}

	while (j < len2)
	{
		d3[k++] = d2[j++];
	}

	len3 = len1 + len2;

	cout << "\n\nMang sau khi chen xet ke co thu tu: ";
	printArray(d3, len3);
}
//36	Cho 02 mảng d1 và d2 viết hàm chép các phần tử d2 nối tiếp vào d1.
void cau36()
{
	int d1[MAX_LEN], d2[MAX_LEN];
	int len1, len2;
	cout << "\n\nNhap so luong phan tu D1:";
	cin >> len1;
	enterArray(d1, len1);
	cout << "\n\nNhap so luong phan tu D2:";
	cin >> len2;
	enterArray(d2, len2);

	cout << "\n\nD1: ";
	printArray(d1, len1);
	cout << "\n\nD2: ";
	printArray(d2, len2);

	if (len1 + len2 > MAX_LEN)
	{
		cout << "\n\nD2 qua dai de noi vao D1!";
		return;
	} 
	//d1 1 2 3    len1 = 3
	//   0 1 2 3
	//d2 4 5 6
	for (int i = 0; i < len2; i++)
	{
		d1[len1 + i] = d2[i];
	}
	len1 = len1 + len2;
	cout << "\n\nD1 sau khi noi D2: ";
	printArray(d1, len1);
}
//37	Viết hàm copy mảng a thành 02 mảng mới b và c, 
//trong đó, b là mảng chứa các phần tử có giá dương và c là mảng chứa các phần tử có giá trị âm.
void cau37(int array[], int len)
{
	int i = 0, j = 0;
	int d1[MAX_LEN], d2[MAX_LEN];
	for (int k = 0; k < len; k++)
	{
		if (array[k] < 0)
		{
			d2[j++] = array[k];
		}
		else
		{
			d1[i++] = array[k];
		}
	}
	cout << "\n\nMang B toan phan tu duong: ";
	printArray(d1, i);
	cout << "\n\nMang C toan phan tu am: ";
	printArray(d2, j);
}
//40	"Cho mảng số thực có nhiều hơn hai giá trị và các giá trị trong mảng khác nhau từng đôi một.
//Hãy viết hàm tìm hai giá trị gần nhau nhất trong mảng.Lưu ý : Mảng có các giá trị khác nhau từng đôi một còn có tên là mảng phân biệt."
//vd 1.5, 3.2, 7.8 9.0 4.1
//   3.2 va 4.1 => 0.9
void cau40()
{
	float fArray[MAX_LEN];
	int len;
	cout << "\nNhap do dai cua mang so thuc: ";
	cin >> len;
	for (int i = 0; i < len; i++)
	{
		cout << "\nNhap phan tu thu [" << i << "]: ";
		cin >> fArray[i];
	}
	if (len < 2)
	{
		cout << "\nMang phai co it nhat 2 gia tri tro len!";
		return;
	}
	float value1, value2;
	float min;
	value1 = fArray[0];
	value2 = fArray[1];
	min = value2 - value1;
	if (min < 0)
	{
		min *= -1;
	}
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			float temp = fArray[j] - fArray[i];
			if (temp < 0)
			{
				temp *= -1;
			}
			if (temp < min)
			{
				min = temp;
				value1 = fArray[i];
				value2 = fArray[j];
			}
		}
	}
	cout << "\n\nHai gia tri gan nhau nhat la " << value1 << " va " << value2 << " [" << min << "]";
}


void main()
{
	int array[MAX_LEN] = { -1, 40, -8, -99 ,121 , 6 , -8, 7, -1, 28, 0, 4, 40, 121 };
	int len = 14;


	int choice = -1;
	do
	{
		system("cls");
		cout << "\n//============ Menu ===========//";
		cout << "\n0.  Nhap Mang Moi.";
		cout << "\n1.  Ham xuat cac so am trong mang";
		cout << "\n2.  Ham xuat cac gia tri chan co it nhat mot lan can cung la gia tri chan";
		cout << "\n3.  Ham xuat cac vi tri cua so chan lon nhat trong mang";
		cout << "\n4.  Ham xuat tong cac gia tri doi xung trong mang cac so nguyen.";
		cout << "\n5.  Ham xuat ra so luong so chan co trong mang.";
		cout << "\n6.  Ham xuat cac gia tri xuat hien trong day qua mot lan.Luu y : moi gia tri liet ke mot lan.";
		cout << "\n7.  Ham xuat ra 'gia tri nho nhat' trong mang";
		cout << "\n8.  Ham tra ve 'gia tri duong nho nhat' trong mang, neu khong co thi tra ve -1";
		cout << "\n9.  Ham xuat vi tri so duong lon nhat cuoi cung trong mang";
		cout << "\n10. Ham thuc hien Sap xep mang a co thu tu tang dan";
		cout << "\n11. Ham Tra ve so luong phan tu co gia tri la x.";
		cout << "\n12. Ham Tra ve dia chi phan tu co gia tri x tim thay dau tien trong danh sach";
		cout << "\n13. Ham Tra ve dia chi phan tu co gia tri x tim thay cuoi cung trong danh sach";
		cout << "\n14. Ham Tra ve dia chi phan tu co gia tri x thu 2 tim thay trong danh sach";
		cout << "\n15. Kiem tra mang co tang hay khong? Neu co tra ve 1, nguoc lai tra ve 0.";
		cout << "\n16. Ham xuat ra cac phan tu co gia tri bang tong 02 phan tu ke tiep.";
		cout << "\n17. Ham xuat ra cac phan tu co gia tri bang tong 02 phan tu lien ke truoc do.";
		cout << "\n18. Ham kiem tra trong mang nay co phan tu nao la so nguyen to hay khong?\n	Neu co tra ve vi tri phan tu dau tien duoc tim thay.";
		cout << "\n19. Ham tra ve so luong cac so hoan hao duoc tim thay trong danh sach.";
		cout << "\n20. Ham xuat ra gia tri cac phan tu co gia tri la so chinh phuong.";
		cout << "\n21. Ham kiem tra mang co phai la day cap so nhan 3 hay khong? Neu co tra ve 1, nguoc lai, tra ve 0.";
		cout << "\n22. Ham tra ve gia tri so am lon nhat trong mang.";
		cout << "\n23. Su dung thuat toan sap xep tuan tu, hay viet ham sap xep mang giam dan.";
		cout << "\n24. Ham chen gia tri a vao truoc phan tu co gia tri x.";
		cout << "\n25. Ham chen gia tri a vao sau phan tu co gia tri x.";
		cout << "\n26. Ham chen gia tri a vao sau vi tri pos.";
		cout << "\n27. Ham chen gia tri a vao truoc vi tri pos.";
		cout << "\n28. Ham xoa phan tu co gia tri x dau tien duoc tim thay.";
		cout << "\n29. Ham xoa phan tu co gia tri x cuoi cung duoc tim thay.";
		cout << "\n30. Ham xoa tat ca cac phan tu co gia tri x.";
		cout << "\n31. Ham xoa phan tu co gia tri x thu 2 duoc tim thay.";
		cout << "\n32. Ham xoa tat ca cac phan tu co gia tri x tu phan tu thu 2 tro di duoc tim thay.";
		cout << "\n33. Ham thay the cac phan tu co gia tri x sang gia tri y.";
		cout << "\n34. Cho 02 mang D1 va D2, viet ham chen xen ke cac phan tu D2 vao D1.";
		cout << "\n35. Gia su, cho 02 mang D1 va D2 co thu tu tang, viet ham chen cac phan tu D2 vao D1 sao cho D1 van co thu tu.";
		cout << "\n36. Cho 02 mang D1 va D2, viet ham chep cac phan tu D2 noi tiep vao D1.";
		cout << "\n37. Viet ham copy mang A thanh 02 mang moi B va C, \n	trong do B la mang chua cac phan tu co gia tri duong va C la mang chua cac phan tu co gia tri am.";
		cout << "\n40. Cho mang so thuc co nhieu hon hai gia tri va cac gia tri trong mang khac nhau tung doi mot.\n	Hay viet ham tim hai gia tri gan nhau nhat trong mang. \n	Luu y : Mang co cac gia tri khac nhau tung doi mot con co ten la mang phan biet.";
		cout << "\n999.Thoat chuong trinh.";
		cout << "\nOne-dimensional Array:";
		printArray(array, len);
		cout << "\nNhap lua chon: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "\n\nNhap chieu dai cua mang: ";
			cin >> len;
			enterArray(array, len);
			break;
		case 1:
			cau1(array, len);
			break;
		case 2:
			cau2(array, len);
			break;
		case 3:
			cau3(array, len);
			break;
		case 4:
			cau4(array, len);
			break;
		case 5:
			cau5(array, len);
			break;
		case 6:
			cau6(array, len);
			break;
		case 7:
			cau7(array, len);
			break;
		case 8:
			cau8(array, len);
			break;
		case 9:
			cau9(array, len);
			break;
		case 10:
			cau10(array, len);
			break;
		case 11:
			cau11(array, len);
			break;
		case 12:
			cau12(array, len);
			break;
		case 13:
			cau13(array, len);
			break;
		case 14:
			cau14(array, len);
			break;
		case 15:
			cau15(array, len);
			break;
		case 16:
			cau16(array, len);
			break;
		case 17:
			cau17(array, len);
			break;
		case 18:
			cau18(array, len);
			break;
		case 19:
			cau19(array, len);
			break;
		case 20:
			cau20(array, len);
			break;
		case 21:
			cau21(array, len);
			break;
		case 22:
			cau22(array, len);
			break;
		case 23:
			cau23(array, len);
			break;
		case 24:
			cau24(array, len);
			break;
		case 25:
			cau25(array, len);
			break;
		case 26:
			cau26(array, len);
			break;
		case 27:
			cau27(array, len);
			break;
		case 28:
			cau28(array, len);
			break;
		case 29:
			cau29(array, len);
			break;
		case 30:
			cau30(array, len);
			break;
		case 31:
			cau31(array, len);
			break;
		case 32:
			cau32(array, len);
			break;
		case 33:
			cau33(array, len);
			break;
		case 34:
			cau34();
			break;
		case 35:
			cau35();
			break;
		case 36:
			cau36();
			break;
		case 37:
			cau37(array, len);
			break;
		case 40:
			cau40();
			break;
		case 999:
			cout << "\nCHUONG TRINH DUNG LAI!";
			break;
		default:
			cout << "\n\nLUA CHON KHONG HOP LE!";
			break;
		}
		cout << "\n\n\n";
		system("pause");
	} while (choice != 999);
	//cau1(array, len);
	//cau2(array, len);
	//cau3(array, len);
	//cau4(array, len);
	//cau5(array, len);
	//cau6(array, len);
	//cau7(array, len);
	//cau8(array, len);
	//cau9(array, len);
	//cau10(array, len);
	//cau11(array, len);
	//cau12(array, len);
	//cau13(array, len);


	//cout << "\n\nMang sau khi duoc xep tang dan:";
	//selectionSort(array, len);
	//printArray(array, len);

	//loaiBoGiaTriTrung(array, len);
	//cout << "\n\nMang sau khi loai bo gia tri trung:";
	//printArray(array, len);

	//bool result = cau15(array, len);

	//cau16(array, len);
	//cau17(array, len);
	//cau18(array, len);
	//cau19(array, len);
	//cau20(array, len);

	//cout << "\nNhap do dai cua mang: ";
	//cin >> len;
	//enterArray(array, len);
	//cau21(array, len);
	//cau22(array, len);
	//cau23(array, len);
	//cau24(array, len);
	//cau25(array, len);

	//cau26(array, len);
	//cau27(array, len);
	//cau28(array, len);

	//cau29(array, len);
	//cau30(array, len);
	//cau31(array, len);
	//cau32(array, len);
	//cau33(array, len);
	//cau34();
	//cau35();
	//cau36();
	//cau37(array,len);

	//cau40();
	cout << "\n\n";
}