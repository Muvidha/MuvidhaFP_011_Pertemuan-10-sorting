//implementasi program C++ Radix sort
#include <iostream>
 
using namespace std;
 
// mendapatkan nilai maksimum dari array
int getMax(int arr[], int n)
{
	//fungsi void 
	int max = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
 
// mencetak array[].
//penyelesaian dengan menggunakan metode pemanggilan
void countSort(int arr[], int n, int exp)
{
	// Count[i] array akan menghitung jumlah nilai array yang memiliki digit 'i'.  
	int output[n], i, count[10] = {0};
 
	// menghitung berapa kali setiap digit muncul di setiap input.
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
 
	// Menghitung jumlah kumulatif array.
	for (i = 1; i < 10; i++)
		count[i] += count[i-1];
 
	// Menyisipkan nilai sesuai dengan digit.
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	// Menetapkan hasil ke pointer array.
	for (i = 0; i < n; i++)
		arr[i] = output[i];
} 
// mengurutkan array dengan variabel n menggunakan Radix Sort.
void radixsort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n);
	// Memanggil countSort() untuk digit di setiap input. 
	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
 
int main()
{
	// inisialisasi variabel
	int n, i;
	cout<<"Masukkan jumlah data dalam array : ";
	cin>>n;
	cout<<endl;
 
	cout << "Masukan " << n << " Nilai Array :"<<endl;
    int array[n];
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	cout<<endl;
	
	radixsort(arr, n);
 
	//----Proses sorting berakhir----
	// keluaran data yang sudah menggunakan radixsort
	cout<<"Array yang sudah disorting : \n";
	for(i = 0; i < n; i++)
	{
		cout<<"["<<arr[i]<<"] ";
	}
		
	return 0;
}
