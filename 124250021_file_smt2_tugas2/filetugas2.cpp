#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct netfilm
{char name[80];
 double price;
 int year;	
 double rating;};
netfilm arr[50];

void quick_sort(netfilm array[], int first, int last) //rumus quick sort desc
{
 int low = first;
 int high = last;
 netfilm temp;
 double pivot = array[(first + last) / 2].rating;
 do {
 while(array[low].rating > pivot)
 low++;
 while(array[high].rating < pivot)
 high--;
 if(low <= high)
 {
 temp = array[low];
 array[low++] = array[high];
 array[high--] = temp;
 }
 } while(low <= high);
 if(first < high) quick_sort(array, first, high);
 if(low < last) quick_sort(array, low, last);
}

void bubble_sort(netfilm array[], int size) //rumus bubble sort asc
{
 int i,j,k;
 netfilm temp;
 for(i=0;i<size-1;i++)
  {for(j=0;j<size-1-i;j++)
    {k=0;
     while(array[j].name[k] == array[j+1].name[k] && array[j].name[k] != '\0')
      {k++;}
        if(array[j].name[k] > array[j+1].name[k])
          {temp = array[j];
           array[j] = array[j+1];
           array[j+1] = temp;
          }
      }
   }
}

int main()
{
	int pilih; 
	int jumlah_film;
	do{
    system("cls");
	cout<<"+--------------------------------------+"<<endl;
    cout<<"|      NETFLIM SYSTEM - DASHBOARD      |"<<endl;
    cout<<"+--------------------------------------+"<<endl;
    cout<<"| [1] Lihat Katalog Film               |"<<endl;
    cout<<"| [2] Urutkan Rating (Quick Sort)      |"<<endl;
    cout<<"| [3] Urutkan Abjad (Bubble Sort)      |"<<endl;
    cout<<"| [4] Cari Film (Linear Search)        |"<<endl;
    cout<<"| [5] Cari Film (Binary Search)        |"<<endl;
    cout<<"| [6] Tambah Film Baru                 |"<<endl;
    cout<<"| [0] Keluar & Simpan                  |"<<endl;
    cout<<"+--------------------------------------+"<<endl<<endl;
	cout<<"Pilih Menu > ";
	cin>>pilih;
	if(pilih==6) //masukin data film ke netfilm_db.txt
	{FILE *file;
	 file=fopen("netfilm_db.txt","a");
	 if(file==NULL)
	 {printf("Error !");   
      exit(1);             
     }
	 cout<<"Masukkan Jumlah Film yang Ingin Anda Masukkan : ";
	 cin>>jumlah_film;
	 cin.ignore();
	 for(int i=0;i<jumlah_film;i++)
	 {cout<<"Film ke-"<<i+1<<endl;
	  cout<<"Input Judul  : ";
	  cin.getline(arr[i].name,80);
	  cout<<"Input Harga  : ";
	  cin>>arr[i].price;
	  cout<<"Input Tahun  : ";
	  cin>>arr[i].year;
	  cout<<"Input Rating : ";
	  cin>>arr[i].rating;
	  cin.ignore();
	  fprintf(file, "%s;%.0lf;%d;%.1lf\n", arr[i].name, arr[i].price, arr[i].year,
      arr[i].rating);
	  }
	 fclose(file);
	 cout<<"\n[ SUCCESS ] Data berhasil disinkronkan ke netfilm_db.txt"<<endl;
	 cout<<"[ SUCCESS ] Film ditambahkan."<<endl<<endl;
	 cout<<"Tekan Enter untuk kembali ke menu...";
	 cin.get();
	 }
	 
	 if(pilih==1) //nampilin semua judul dalam array
	 {cout<<"\nNETFILM CONTENT CATALOG"<<endl;
     cout<<"______________________________________________________________________________"<<endl;
      printf("%-4s %-29s %-10s %-10s %-10s\n","ID","Judul Film","Lisensi","Tahun","Rating");
      cout<<"______________________________________________________________________________"<<endl;
     FILE *file;
	 file=fopen("netfilm_db.txt","r");
	 if(file==NULL)
	 {printf("Error !");   
     exit(1);}
	 int i = 0;
     while (fscanf(file, " %[^;];%lf;%d;%lf\n", arr[i].name, &arr[i].price,&arr[i].year, &arr[i].rating) != EOF) 
     {cout<<"["<<i+1<<"] ";
      printf("%-30s %-10.0lf %-10d %-10.1lf\n", arr[i].name, arr[i].price, arr[i].year,
      arr[i].rating);
      i++;
     }
     cout<<"______________________________________________________________________________"<<endl;
     fclose(file);
     cout<<"\nTekan Enter untuk kembali ke menu...";
     cin.ignore();
     cin.get();}
     
     if(pilih==2) //quick sort rating desc
     {cout<<"\nNETFILM CONTENT CATALOG"<<endl;
     cout<<"______________________________________________________________________________"<<endl;
      printf("%-4s %-29s %-10s %-10s %-10s\n","ID","Judul Film","Lisensi","Tahun","Rating");
      cout<<"______________________________________________________________________________"<<endl;
     FILE *file;
	 file=fopen("netfilm_db.txt","r");
	 if(file==NULL)
	 {printf("Error !");   
     exit(1);}
     int i=0;
     while (fscanf(file, " %[^;];%lf;%d;%lf\n", arr[i].name, &arr[i].price,&arr[i].year, &arr[i].rating) != EOF)
     {i++;}
     fclose(file);
     int jumlah_data = i;
     quick_sort(arr,0,jumlah_data-1);
     for(i=0;i<jumlah_data;i++)
     {cout<<"["<<i+1<<"] ";
     printf("%-30s %-10.0lf %-10d %-10.1lf\n",
     arr[i].name,arr[i].price,arr[i].year,arr[i].rating);
     }
     cout<<"______________________________________________________________________________"<<endl;
     cout<<"[!] Katalog Berhasil Diurutkan Berdasarkan Rating Tertinggi"<<endl;
	 cout<<"\nTekan Enter untuk kembali ke menu...";
     cin.ignore();
     cin.get();}
     
    if(pilih==3) //bubble sort name asc
    {cout<<"\nNETFILM CONTENT CATALOG (SORT BY TITLE)"<<endl;
    cout<<"______________________________________________________________________________"<<endl;
    printf("%-4s %-29s %-10s %-10s %-10s\n","ID","Judul Film","Lisensi","Tahun","Rating");
    cout<<"______________________________________________________________________________"<<endl;
    FILE *file;
    file=fopen("netfilm_db.txt","r");
    if(file==NULL)
    {printf("Error !");
     exit(1);}
    int i=0;
    while (fscanf(file, " %[^;];%lf;%d;%lf\n", arr[i].name, &arr[i].price,&arr[i].year, &arr[i].rating) != EOF)
     {i++;}
     fclose(file);
     int jumlah_data = i;
     bubble_sort(arr, jumlah_data); 
    for(i=0;i<jumlah_data;i++)
    {cout<<"["<<i+1<<"] ";
     printf("%-30s %-10.0lf %-10d %-10.1lf\n",arr[i].name,arr[i].price,arr[i].year,arr[i].rating);
    }
    cout<<"______________________________________________________________________________"<<endl;
    cout<<"[!] Katalog Berhasil Diurutkan berdasarkan Abjad (A-Z)."<<endl;
    cout<<"\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
    }
    
  if(pilih==4) //linear search tanpa sentinel
  { char linears[80];
    cout<<"Masukkan Judul Film : ";
    cin.ignore();
    cin.getline(linears,80);
    FILE *file;
    file=fopen("netfilm_db.txt","r");
    if(file==NULL)
    {printf("Error !");
     exit(1);}
    int i=0;
    while (fscanf(file," %[^;];%lf;%d;%lf\n",arr[i].name,&arr[i].price,&arr[i].year,&arr[i].rating) != EOF)
    {i++;}
    fclose(file);
    int jumlah_data = i;
    bool ditemukan = false;
    if(jumlah_data >= 30) //jika jumlah data lebih atau sama dengan 30
    {
    cout<<"\nJumlah film >= 30."<<endl;
    cout<<"Gunakan Binary Search pada menu 5."<<endl;
    }
    else //jika jumlah data kurang dari 30 maka menjalankan linear search
    {
    for(i=0;i<jumlah_data;i++) //rumus linear search
    {int k=0;
     while(linears[k]==arr[i].name[k] && linears[k]!='\0')
     {k++;}
        if(linears[k]=='\0' && arr[i].name[k]=='\0')
        {cout<<"\n[ Found ] : ";
         cout << arr[i].name << " (" << arr[i].year << ")" << endl;
         ditemukan=true;
        }
    }
    }
    if(!ditemukan)
    {cout<<"\nData Tidak Ditemukan"<<endl;}
    cout<<"\nTekan Enter untuk melanjutkan...";
    cin.get();
   }
   if(pilih==5) // binary search
   {char binarys[80];
    cout<<"Masukkan Judul Lengkap film (Exact): ";
    cin.ignore();
    cin.getline(binarys,80);
    FILE *file;
    file=fopen("netfilm_db.txt","r");
    if(file==NULL)
    {printf("Error !");
     exit(1);}
    int i=0;
    while(fscanf(file," %[^;];%lf;%d;%lf\n",arr[i].name,&arr[i].price,&arr[i].year,&arr[i].rating)!=EOF)
    {i++;}
    fclose(file);
    int jumlah_data = i;
    if(jumlah_data < 30)
    {cout<<"\nJumlah film < 30."<<endl;
     cout<<"Gunakan Linear Search pada menu 4."<<endl;
    }
    else
    {// opsi buat ngurutin , soalnya binary butuh urut datanya
     char pilihSort;
     cout << "\nMenu ini perlu sorting dulu , apakah data anda sudah disortir? (y/n): ";
     cin >> pilihSort;
        if(pilihSort=='n' || pilihSort=='N')
        {// panggil bubble_sort 
            bubble_sort(arr, jumlah_data);
            cout << "[SORTIR SUCCESS] Data telah diurutkan A-Z." << endl;
        }
        // Binary Search rumus
        int low=0, high=jumlah_data-1, mid;
        bool ditemukan=false;
        while(low<=high)
        {mid = (low + high)/2;
         int k=0;
         while(binarys[k]==arr[mid].name[k] && binarys[k]!='\0') k++;
            if(binarys[k]=='\0' && arr[mid].name[k]=='\0')
            {cout<<"\n[Judul Ditemukan] "<<arr[mid].name<<" ("<<arr[mid].year<<")"<< endl;
             ditemukan=true;
             break;
            }
            else
            {// jika binarys < arr[mid] → cari kiri
             int cmp=0;
             while(binarys[cmp]==arr[mid].name[cmp] && binarys[cmp]!='\0') cmp++;
             if(binarys[cmp] < arr[mid].name[cmp]) high = mid-1;
             else low = mid+1;
            }
        }
        if(!ditemukan)
        {cout << "\n[!] Judul tidak ditemukan. Pastikan data sudah di-sort A-Z." << endl;}
    }
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}
     if(pilih==0)
     {cout<<"[ SUCCESS ] Data berhasil disinkronkan ke netfilm_db.txt"<<endl<<endl;
	  cout<<"Sistem Offline. Terimakasih!";
	  exit(1);
	 }
}while(pilih!=0);
}

