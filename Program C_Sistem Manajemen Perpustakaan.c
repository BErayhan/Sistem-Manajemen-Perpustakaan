//***HEADER YANG DIGUNAKAN***//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//***PASSWORD ADMINISTRATOR***//

char password[5]="kel11";

//***STRUCK YANG DIGUNAKAN***//

struct info_buku{
	char judul[50];
	char penulis[30];
	char id[20];
	int jumlah;
	int sisa;
}buku,copy_buku;

struct tanggal
{
    int dd;
	int mm;
	int yy;
};

struct info_user
{
    char id[20];
    char nama[30];
    char id_buku[20];
    struct tanggal pinjam;
    struct tanggal kembali;
}user,copy_user;

//***POINTER YANG DIGUNAKAN***//

FILE *info,*info2;

//***FUNCTION YANG DIGUNAKAN***//

void menuUtama(void);
void Admin(void);
void User();
void keluar(void);
void menuBuku(void);
void tambahBuku(void);
void editBuku(void);
void hapusBuku(char[20],int);
void menuUser(void);
void tambahUser();
void editUser(void);
void hapusUser(char[20],int);
void daftarBuku(void);
void daftarUser(void);
void pinjamBuku(void);
void kembaliBuku(void);
void cariBuku(void);
void cariUser(void);
int cek_buku(char[20]);
int cek_user(char[20]);
int cek_tanggal(struct tanggal);
void tenggat(void);
int denda(struct tanggal,int);

//***FUNCTION MAIN***//

int main(void)
{
    system("cls");
    system("color 2F");
    printf("\n\n\n\t\t\t **-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t Sistem Manajemen Perpustakaan");
	printf("\n\t\t\t **-**-**-**-**-**-**-**-**-**");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t Oleh :");
	printf("\n\t\t\t\t\t\t\t\t Kelompok 11"); 
	printf("\n\t\t\t\t\t\t\t\t Dasar Komputer-03");
    printf("\n\n\t\t Tekan tombol apa saja untuk melanjutkan...");
    getch();
    menuUtama();
    return 0;
}

//***FUNCTION MENU UTAMA***//

void menuUtama(void)
{
    int menu;
    do
    {
        system("cls");
        printf("\n\n\n\t\t\t **-**--**-**");
        printf("\n\t\t\t  Menu Utama");
        printf("\n\t\t\t **-**--**-**");
        printf("\n\n\t\t [1] Administrator");
        printf("\n\t\t [2] Anggota");
        printf("\n\t\t [3] Keluar");
        printf("\n\n\t\t Silakan masukkan pilihan Anda (1-3) : ");
        fflush(stdin);
        scanf("%d",&menu);
        switch(menu)
        {
            case 1: Admin();
                    break;
            case 2: User();
                    break;
            case 3: keluar();
                    break;
            default: printf("\n\n\t\t >>> Pilihan Anda tidak sesuai.");
                     getch();
        }
    }while(1);
    getch();
}

//***FUNCTION MENU ADMINISTRATOR***//

void Admin(void)
{
	label :
    system("cls");
    printf("\n\n\t\t Silakan masukkan password : ");
    char str[20];
    char ch;
	int i=0;
    while((ch=getch())!='\r'&&i<20)
    {
        putch('*');
        str[i++]=ch;
    }
    str[i]='\0';
    if(strcmp(str,password)==0)
        {
            printf("\n\n\n\t\t >>> Proses autentikasi berhasil. ");
            printf("\n\n\t\t Tekan tombol apa saja untuk melanjutkan...");
            getch();
        }
    else
        {
            printf("\n\n\n\t\t >>> Password yang Anda masukkan salah.");
            printf("\n\n\t\t Tekan tombol apa saja untuk melanjutkan...");
            getch();
            return;
        }
    int pilihan1;
    do
    {
	    system("cls");
	    printf("\n\n\t\t\t\t **-**-**-**-**-**-**");
		printf("\n\t\t\t\t  Menu Administrator");
		printf("\n\t\t\t\t **-**-**-**-**-**-**");
		printf("\n\n\t\t [1] Tambah/Edit Buku");
		printf("\n\t\t [2] Tambah/Edit Anggota");
		printf("\n\t\t [3] Daftar Buku");
		printf("\n\t\t [4] Daftar Anggota");
		printf("\n\t\t [5] Peminjaman Buku");
		printf("\n\t\t [6] Pengembalian Buku");
		printf("\n\t\t [7] Menu Utama"); 
		printf("\n\t\t [8] Keluar");
		printf("\n\n\t\t Silakan masukkan pilihan Anda (1-8) : ");
		fflush(stdin);
	    scanf("%d",&pilihan1);
    	switch(pilihan1)
        {
            case 1: menuBuku();
					break;
            case 2: menuUser();
					break;
            case 3: daftarBuku();
					break;
            case 4: daftarUser();
					break;
            case 5: pinjamBuku();
					break;
            case 6: kembaliBuku();
					break;
            case 7: menuUtama();
					break;
            case 8: keluar();
					break;
            default: printf("\n\n\t\t >>> Pilihan Anda tidak sesuai.");
                 	 getch();
        }
    }while(1);
    getch();
}

//***FUNCTION DATA BUKU***//

void menuBuku(void)
{
    int list1;
    char id[20];
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t **-**-**-**");
        printf("\n\t\t\t\t  Data Buku");
        printf("\n\t\t\t\t **-**-**-**");
        printf("\n\n\t\t [1] Tambah Buku");
		printf("\n\t\t [2] Edit Detail Buku");
		printf("\n\t\t [3] Hapus Buku");
		printf("\n\t\t [4] Menu Administrator");
		printf("\n\t\t [5] Keluar");
        printf("\n\n\t\t Silahkan masukkan pilihan Anda (1-5) : ");
        fflush(stdin);
        scanf("%d",&list1);
        switch(list1)
        {
            case 1: tambahBuku();
					break;
           	case 2: editBuku();
			   		break;
           	case 3: hapusBuku(id,0);
			   		break;
           	case 4: Admin();
			   		break;
           	case 5: keluar();
			   		break;
            default: printf("\n\n\t\t >>> Pilihan Anda tidak sesuai.");
                     getch();
        }
    }while(1);
}

//***FUNCTION TAMBAH BUKU***//

void tambahBuku(void)
{
	info=fopen("info_buku.txt","a");
	int ulang;
	do
	{	
		system("cls");
		printf("\n\n\t\t\t Tambah Buku");
        printf("\n\t\t\t ~~~~~~~~~~~");
        printf("\n\n\t\t Silakan masukkan detail berikut : ");
        printf("\n\n\t ID buku : ");
		fflush(stdin);
		scanf("%255[^\n]",&buku.id); 
		if(cek_buku(buku.id)==0)
        {
            printf("\n\t Judul buku : ");
			fflush(stdin);
			scanf("%255[^\n]", &buku.judul);
			printf("\n\t Penulis : ");
			fflush(stdin);
			scanf("%255[^\n]", &buku.penulis);
			printf("\n\t Jumlah buku : ");
			fflush(stdin);
			scanf("%d", &buku.jumlah);
			fflush(stdin);
			buku.sisa=buku.jumlah;
			fwrite(&buku,sizeof(struct info_buku),1,info);    
			printf("\n\n\t >>> Buku berhasil ditambahkan.");
            printf("\n\n\t Apakah Anda ingin menambahkan buku yang lain? [1] Ya [0] Tidak : ");
            scanf(" %d",&ulang);
        }
        else
        {
            printf("\n\n\t >>> ID buku sudah terdaftar.");
            printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
            getch();
        }
	}while(ulang==1);   
    fclose(info); 
    return;
}

//***FUNCTION CEK BUKU***//

int cek_buku(char id[20])
{
    FILE *buku;
    int i=0;
    buku=fopen("info_buku.txt","r");
    while(!feof(buku))
    {
        if(fread(&copy_buku,sizeof(struct info_buku),1,buku)==1)
        {
            if(strcmp(copy_buku.id, id)==0)  
        	{
            i=1;
            break;
        	}
    	}
	}
    fclose(buku);
    return i;
}

//***FUNCTION EDIT BUKU***//

void editBuku(void)
{
    char id[20];
	int ganti;
	int ulang;
    system("cls");
    printf("\n\n\t\t\t\t Edit Buku");
    printf("\n\t\t\t\t ~~~~~~~~~");
    printf("\n\n\t Masukkan ID buku yang ingin Anda edit : ");
    fflush(stdin);
    scanf("%255[^\n]",&id);
    if(cek_buku(id)==1){
		hapusBuku(id, 1);
        struct info_buku edit_buku;
        edit_buku = copy_buku;
        l2:
        printf("\n\t >>> Informasi buku yang tersedia,");
        printf("\n\t ID Buku : %s \n\t [1] Judul Buku : %s \n\t [2] Penulis : %s \n\t [3] Jumlah Buku : %d ",edit_buku.id,edit_buku.judul,edit_buku.penulis,edit_buku.jumlah);
        printf("\n\n\t Silakan masukkan informasi yang ingin Anda edit (1-3) : ");
        scanf("%d",&ganti);
        switch(ganti)
        {
            case 1: printf("\n\n\t Masukkan judul buku yang baru : ");
            		fflush(stdin);
                    scanf("%255[^\n]", &edit_buku.judul);
                    break;
            case 2: printf("\n\n\t Masukkan penulis yang baru : ");
            		fflush(stdin);
                    scanf("%255[^\n]", &edit_buku.penulis);
                    break;
            case 3: printf("\n\n\t Masukkan jumlah buku yang baru : ");
                    int temp;
                    temp=edit_buku.jumlah;
                    fflush(stdin);
                    scanf("%d",&edit_buku.jumlah);
                    edit_buku.sisa=edit_buku.sisa+edit_buku.jumlah-temp;
                    break;
            default: printf("\n\n\t >>> Pilihan Anda tidak sesuai.");
                     printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
                     getch();
                     goto l2;
        }
        printf("\n\t Apakah Anda ingin mengedit informasi yang lain? [1] Ya [0] Tidak : ");
        int ulang;
        fflush(stdin);
        scanf(" %d",&ulang);
        if(ulang==1)
            goto l2;
        info=fopen("info_buku.txt","a");
        fwrite(&edit_buku,sizeof(struct info_buku),1,info);
        fclose(info);
        printf("\n\n\t >>> Buku berhasil diperbarui.");
        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
        getch();
    }
    else
    {
        printf("\n\n\t >>> ID buku yang Anda masukkan tidak ada.");
        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
        getch();
    }
    getch();
    return;
}

//***FUNCTION HAPUS BUKU***//

void hapusBuku(char id[20], int x)
{
    FILE *temp;
    int flag=0, ulang;
    temp=fopen("temp.txt","w");
    if(x == 0){
        flag=1;
        system("cls");
        printf("\n\n\t\t Hapus Buku");
        printf("\n\t\t ~~~~~~~~~~");
        printf("\n\n\t Masukkan ID buku yang ingin Anda hapus : ");
        fflush(stdin);
        gets(id);
        if(cek_buku(id)==0){
            printf("\n\n\t >>> ID buku yang Anda masukkan tidak ada.");
            printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
            return;
        }
    }
	info=fopen("info_buku.txt","r");
    while(!feof(info))
    {
        if(fread(&buku,sizeof(struct info_buku),1,info)==1)
            if(strcmp(buku.id, id) != 0)
                fwrite(&buku,sizeof(struct info_buku),1,temp);
    }
    fclose(info);
    fclose(temp);
    remove("info_buku.txt");
    rename("temp.txt","info_buku.txt");
    if(flag)
    {
        printf("\n\n\t >>> Buku berhasil dihapus. ");
        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan... ");
        getch();
    }
    return;
}

//***FUNCTION DAFTAR BUKU***//

void daftarBuku(void)
{
	int j;
	int list;
	system("cls");
	printf("\n\n\t\t\t Daftar Buku");
    printf("\n\t\t\t ~~~~~~~~~~~");
	for(j=97;j<=122;j++){
		info = fopen("info_buku.txt","r"); 
		fflush(stdin);
		list=0;
			while(fread(&buku,sizeof(struct info_buku),1,info)==1)
			{
				if(buku.judul[0]==j||buku.judul[0]==j-32)
				{
					printf("\n\n\t ID buku : %s \n\t Judul buku : %s \n\t Penulis : %s \n\t Jumlah buku : %d \n\t Buku tersedia : %d",buku.id,buku.judul,buku.penulis,buku.jumlah,buku.sisa);
					list++;
				}
			}
			fclose(info);
	}
	printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
	getch();
	return;
}

//***FUNCTION CARI BUKU***//

void cariBuku()
{
	int k;
	int list;
	int ulang;
	char keyword[50] = {0};
	info=fopen("info_buku.txt","r");	
	system("cls");      
	list=0;
	printf("\n\n\t\t\t\t Cari Buku");
    printf("\n\t\t\t\t ~~~~~~~~~");
	printf("\n\n\t\t [1] ID Buku \n\t\t [2] Judul Buku \n\t\t [3] Penulis\n");
	printf("\n\t\t Silakan masukan pilihan Anda (1-3) : ");
	fflush(stdin);
	scanf("%d",&k);                
		switch(k)
		{
		case 1:
			{
			rewind(info);
			printf("\n\t\t Masukkan ID buku yang ingin Anda cari : ");
			fflush(stdin);
			scanf("%255[^\n]",&keyword);	
			printf("\n\n\t\t >>> Hasil pencarian untuk ID buku %s,",keyword);	
					while(fread(&buku,sizeof(struct info_buku),1,info)==1)
					{
						if(strstr(buku.id,keyword)!= 0)
						{
						printf("\n\n\t\t ID buku : %s \n\t\t Judul buku : %s \n\t\t Penulis : %s \n\t\t Jumlah buku : %d \n\t\t Buku tersedia : %d",buku.id,buku.judul,buku.penulis,buku.jumlah,buku.sisa);
						list++;
						}
					}
					printf("\n\n\t\t Jumlah buku yang ditemukan : %d",list);
					if(list==0)
					{
						printf("\n\n\n\t\t >>> ID buku yang Anda masukkan tidak ada.");
					}
					break;
			}
		case 2:
			{		
			printf("\n\t\t Masukkan judul buku yang ingin Anda cari : ");
			fflush(stdin);
			scanf("%255[^\n]",&keyword);
			printf("\n\n\t\t >>> Hasil pencarian untuk judul buku %s,",keyword);	
					while(fread(&buku,sizeof(struct info_buku),1,info)==1)
					{
						if(strstr(buku.judul,keyword)!=0)
						{
						printf("\n\n\t\t ID buku : %s \n\t\t Judul buku : %s \n\t\t Penulis : %s \n\t\t Jumlah buku : %d \n\t\t Buku tersedia : %d",buku.id,buku.judul,buku.penulis,buku.jumlah,buku.sisa);
						list++;
						}
					}
					printf("\n\n\t\t Jumlah buku yang ditemukan : %d",list);
					if(list==0)
					{
						printf("\n\n\n\t\t >>> Judul buku yang Anda masukkan tidak ada.");
					}
					break;
			}
		case 3:
			{
			printf("\n\t\t Masukkan penulis yang ingin Anda cari : ");
			fflush(stdin);
			scanf("%255[^\n]",&keyword);
			printf("\n\n\t\t >>> Hasil pencarian untuk judul penulis %s,",keyword);			
					while(fread(&buku,sizeof(struct info_buku),1,info)==1)
					{
						if(strstr(buku.penulis,keyword)!=0)
						{
						printf("\n\n\t\t ID buku : %s \n\t\t Judul buku : %s \n\t\t Penulis : %s \n\t\t Jumlah buku : %d \n\t\t Buku tersedia : %d",buku.id,buku.judul,buku.penulis,buku.jumlah,buku.sisa);
						list++;
						}
					}
						printf("\n\n\t\t Jumlah buku yang ditemukan : %d",list);
						if(list==0) {
							printf("\n\n\n\t\t >>> Penulis yang Anda masukkan tidak ada.");
						}
					break;
			} 
		}
		fclose(info);
		printf("\n\n\t\t Apakah Anda ingin mencari buku yang lain? [1] Ya [0] Tidak : "); 
		fflush(stdin);
		scanf("%d",&ulang);
		if(ulang==1)
		cariBuku();	
		return;
}

//***FUNCTION DATA ANGGOTA***//

void menuUser(void)
{
    int list2;
    char id[20];
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t **-**-**-**-**");
        printf("\n\t\t\t\t  Data Anggota");
        printf("\n\t\t\t\t **-**-**-**-**");
        printf("\n\n\t\t [1] Tambah Anggota");
		printf("\n\t\t [2] Edit Detail Anggota");
		printf("\n\t\t [3] Hapus Anggota"); 
		printf("\n\t\t [4] Menu Administrator");
		printf("\n\t\t [5] Keluar");
        printf("\n\n\t\t Silakan masukkan pilihan Anda (1-5) : ");
        fflush(stdin);
        scanf("%d",&list2);
        switch(list2)
        {
            case 1:	tambahUser();
					break;
            case 2: editUser();
					break;
            case 3: hapusUser(id,0);
					break;
            case 4: Admin();
					break;
            case 5: keluar();
            default: printf("\n\n\t\t >>> Pilihan Anda tidak sesuai.");
                     getch();
        }
    }while(1);
}

//***FUNCTION TAMBAH ANGGOTA***//

void tambahUser()
{
    info2=fopen("info_user.txt","a");
    int ulang;
    do
    {
        system("cls");
        printf("\n\n\t\t\t Tambah Anggota");
        printf("\n\t\t\t ~~~~~~~~~~~~~~");
        printf("\n\n\t\t Silakan masukkan detail berikut : ");
        printf("\n\n\t ID anggota : ");
        fflush(stdin);
        scanf("%255[^\n]",&user.id);
        if(cek_user(user.id)==0)
        {
            printf("\n\t Nama anggota : ");
            fflush(stdin);
            scanf("%255[^\n]",&user.nama);
            strcpy(user.id_buku, "0");
            user.pinjam.dd=user.pinjam.mm=user.pinjam.yy=user.kembali.dd=user.kembali.mm=user.kembali.yy=0;
            fwrite(&user,sizeof(struct info_user),1,info2);
            printf("\n\n\t >>> Anggota berhasil ditambahkan.");
            printf("\n\n\t Apakah Anda ingin menambahkan anggota yang lain? [1] Ya [0] Tidak : ");
            scanf("%d",&ulang);
        }
        else
        {
            printf("\n\n\t >>> ID anggota sudah terdaftar. ");
            printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
            getch();
        }
    }while(ulang==1);
    fclose(info2);
    return;
}

//***FUNCTION CEK ANGGOTA***//

int cek_user(char id[20])
{
    FILE *user;
    int i=0;
    user=fopen("info_user.txt","r");
    while(!feof(user))
    {
        if(fread(&copy_user,sizeof(struct info_user),1,user)==1)
            if(strcmp(copy_user.id, id)==0)
        {
            i=1;
            break;
        }
    }
    fclose(user);
    return i;
}

//***FUNCTION EDIT ANGGOTA***//

void editUser()
{
    char id[20];
	int ganti;
    int ulang;
    system("cls");
    printf("\n\n\t\t\t\t Edit Detail Anggota");
    printf("\n\t\t\t\t ~~~~~~~~~~~~~~~~~~~");
    printf("\n\n\t Masukkan ID anggota yang ingin Anda edit : ");
    fflush(stdin);
    scanf("%255[^\n]",&id);
    if(cek_user(id)==1)
    {
        hapusUser(id,1);
        struct info_user edit_user;
        edit_user=copy_user;
        l2:
        printf("\n\t >>> Informasi anggota yang tersedia, ");
        printf("\n\t [1] ID Anggota : %s \n\t [2] Nama Anggota : %s ",edit_user.id,edit_user.nama);
        printf("\n\n\t Silakan masukkan informasi yang ingin Anda edit : ");
        fflush(stdin);
        scanf("%d",&ganti);
        switch(ganti)
        {
            case 1: l1:
                    printf("\n\n\t Masukkan ID anggota yang baru : ");
                    fflush(stdin);
                    scanf("%255[^\n]",&edit_user.id);
                    if(cek_user(edit_user.id)==1)
                    {
                        printf("\n\n\t >>> ID anggota sudah terdaftar.");
                        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
                        getch();
                        goto l1;
                    }
                    break;
            case 2: printf("\n\n\t Masukkan nama anggota yang baru : ");
            		fflush(stdin);
                    scanf("%255[^\n]", &edit_user.nama);
                    break;
            default: printf("\n\n\t >>> Pilihan Anda tidak sesuai.");
                     printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
                     getch();
                     goto l2;
        }
        printf("\n\t Apakah Anda ingin mengedit informasi yang lain? [1] Ya [0] Tidak : ");
        fflush(stdin);
        scanf("%d",&ulang);
        if(ulang == 1)
            goto l2;
        info2=fopen("info_user.txt","a");
        fwrite(&edit_user,sizeof(struct info_user),1,info2);
        fclose(info2);
        printf("\n\n\t >>> Anggota berhasil diperbarui. ");
        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
        getch();
    }
    else
    {
        printf("\n\n\t >>> ID anggota yang Anda masukkan tidak ada. ");
        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan... ");
        getch();
    }
    return;
}

//***FUNCTION HAPUS ANGGOTA***//

void hapusUser(char id[20], int x)
{
    FILE *temp;
    int flag=0;
    temp=fopen("temp.txt","w");
    if(x==0)
    {
        flag=1;
        system("cls");
        printf("\n\n\t\t\t Hapus Anggota");
        printf("\n\t\t\t ~~~~~~~~~~~~~");
        printf("\n\n\t Masukkan ID anggota yang ingin Anda hapus : ");
        fflush(stdin);
		gets(id);
        if(cek_user(id)==0){
            printf("\n\n\t >>> ID anggota yang Anda masukkan tidak ada.");
            printf("\n\n\t Tekan tombol apa saja untuk melanjutkan... ");
            getch();
            return;
    	}
    }
    info2=fopen("info_user.txt","r");
    while(!feof(info2))
    {
        if(fread(&user,sizeof(struct info_user),1,info2)==1)
            if(strcmp(user.id, id)!=0)
                fwrite(&user,sizeof(struct info_user),1,temp);
    }
    fclose(info2);
    fclose(temp);
    remove("info_user.txt");
    rename("temp.txt","info_user.txt");
    if(flag)
    {
    	printf("\n\n\t >>> Anggota berhasil dihapus. ");
    	printf("\n\n\t Tekan tombol apa saja untuk melanjutkan... ");
        getch();
    }
    return;
}

//***FUNCTION DAFTAR ANGGOTA***//

void daftarUser(void)
{
    int j,list;
    system("cls");
    printf("\n\n\t\t\t\t Daftar Anggota");
    printf("\n\t\t\t\t ~~~~~~~~~~~~~~");
    for(j=97;j<=122;j++){
		info2 = fopen("info_user.txt","r");  
		fflush(stdin);
		list=0;
			while(fread(&user,sizeof(struct info_user),1,info2)==1)
			{
				if(user.nama[0]==j || user.nama[0]==j-32)
				{
					fflush(stdin);
					printf("\n\n\t ID anggota : %s \n\t Nama anggota : %s \n\t ID buku yang dipinjam : %s \n\t Tanggal peminjaman buku : %d-%d-%d \n\t Batas pengembalian buku : %d-%d-%d",user.id,user.nama,user.id_buku,user.pinjam.dd,user.pinjam.mm,user.pinjam.yy,user.kembali.dd,user.kembali.mm,user.kembali.yy);
					list++;
				}
			}
			fclose(info);
	}
	printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
	getch();
    return;
}

//***FUNCTION CARI ANGGOTA***//

void cariUser(){
	int k;
	int list;
	int ulang;
	char keyword[30]={0};
	info2=fopen("info_user.txt","r");
	system("cls");      
	list=0;
	printf("\n\n\t\t\t\t Info Anggota");
    printf("\n\t\t\t\t ~~~~~~~~~~~~");
	printf("\n\n\t\t [1] ID Anggota \n\t\t [2] Nama Anggota");
	printf("\n\n\t\t Silakan masukan pilihan Anda (1-2) : ");
	fflush(stdin);
	scanf("%d",&k);                
		switch(k)
		{
		case 1:
			{
			rewind(info2);
			printf("\n\t\t Masukkan ID anggota yang ingin Anda cari : ");
			fflush(stdin);
			scanf("%255[^\n]",&keyword);
			printf("\n\n\t\t >>> Hasil pencarian untuk ID anggota %s,",keyword);		
				while (fread(&user,sizeof(struct info_user),1,info2)==1)
				{
					if(strstr(user.id, keyword)!= 0)
					{
               		printf("\n\n\t\t ID anggota : %s \n\t\t Nama anggota : %s \n\t\t ID buku yang dipinjam : %s \n\t\t Tanggal peminjaman buku : %d-%d-%d \n\t\t Batas pengembalian buku : %d-%d-%d",user.id,user.nama,user.id_buku,user.pinjam.dd,user.pinjam.mm,user.pinjam.yy,user.kembali.dd,user.kembali.mm,user.kembali.yy);
					list++;
					}
				}
				printf("\n\n\t\t Jumlah anggota yang ditemukan : %d",list);
				if(list==0) 
				{
					printf("\n\n\n\t\t >>> ID anggota yang Anda cari tidak ada.");
				}
				break;
				}
		case 2:	
			{
			printf("\n\t\t Masukkan nama anggota yang ingin Anda cari : ");
			fflush(stdin);
			scanf("%255[^\n]", &keyword);
			printf("\n\n\t\t >>> Hasil pencarian untuk nama anggota %s,",keyword);
				while(fread(&user,sizeof(struct info_user),1,info2)==1)
				{
					if(strstr(user.nama,keyword)!=0)
					{
					printf("\n\n\t\t ID anggota : %s \n\t\t Nama anggota : %s \n\t\t ID buku yang dipinjam : %s \n\t\t Tanggal peminjaman buku : %d-%d-%d \n\t\t Batas pengembalian buku : %d-%d-%d",user.id,user.nama,user.id_buku,user.pinjam.dd,user.pinjam.mm,user.pinjam.yy,user.kembali.dd,user.kembali.mm,user.kembali.yy);
					list++;
					}
				}
				printf("\n\n\t\t Jumlah anggota yang ditemukan : %d",list);
				if(list==0)
				{
					printf("\n\n\n\t\t >>> Nama anggota yang Anda cari tidak ada.");
				}
				break;
		 	}
		}
		fclose(info);
		printf("\n\n\t\t Apakah Anda ingin mencari anggota yang lain? [1] Ya [0] Tidak : "); 
		fflush(stdin);
		scanf("%d",&ulang);
		if(ulang==1)
		cariUser();	
		return;
}

//***FUNCTION MENU ANGGOTA***//

void User(void)
{
    int pilihan2;
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t **-**-**-**-**");
        printf("\n\t\t\t\t  Menu Anggota");
        printf("\n\t\t\t\t **-**-**-**-**");
        printf("\n\n\t\t [1] Cari Buku");
		printf("\n\t\t [2] Info Anggota");
		printf("\n\t\t [3] Menu Utama");
		printf("\n\t\t [4] Keluar");
        printf("\n\n\t\t Silakan masukkan pilihan Anda (1-4) : ");
        fflush(stdin);
        scanf("%d",&pilihan2);
        switch(pilihan2)
        {
            case 1: cariBuku();
					break;
            case 2: cariUser();
					break;
            case 3: menuUtama();
					break;
            case 4: keluar();
					break;
            default: printf("\n\n\t\t >>> Pilihan Anda tidak sesuai.");
                     getch();
        }
    }while(1);
}

//***FUNCTION PEMINJAMAN BUKU***//

void pinjamBuku(void)
{
    system("cls");
	char idBuku[20];
	char idUser[20];
    printf("\n\n\t\t\t Peminjaman Buku");
    printf("\n\t\t\t ~~~~~~~~~~~~~~~");
    printf("\n\n\t Masukkan ID anggota : ");
    fflush(stdin);
    scanf("%255[^\n]",&idUser);
    if(cek_user(idUser)==1)
    {
        if(strcmp(copy_user.id_buku, idBuku)==0) 
        {
            printf("\n\n\t >>> Anggota sudah meminjam satu buku.");
            printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
            getch();
        }
        else
        {
            printf("\n\t Masukkan ID buku yang ingin dipinjam : ");
            fflush(stdin);
            scanf("%255[^\n]",&idBuku);
            if(cek_buku(idBuku)==1)
            {
                if(copy_buku.sisa==0)
                {
                    printf("\n\n\t >>> Buku tidak tersedia sekarang.");
                    printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
                    getch();   
                }
                else
                {
                    do
                    {
                        printf("\n\t Masukkan tanggal peminjaman (dd-mm-yyyy) : ");
                        fflush(stdin);
                        scanf("%d-%d-%d",&copy_user.pinjam.dd,&copy_user.pinjam.mm,&copy_user.pinjam.yy);
                        if(cek_tanggal(copy_user.pinjam))
                            break;
                        printf("\n\n\t >>> Silakan masukkan tanggal yang benar.\n");
                        getch();
                    }while(1);
                    tenggat();
                    printf("\n\t Batas tanggal pengembalian : %d-%d-%d",copy_user.kembali.dd,copy_user.kembali.mm,copy_user.kembali.yy);
                    hapusUser(copy_user.id, 1);
                    info2=fopen("info_user.txt","a");
                    strcpy(copy_user.id_buku, idBuku);
                    fwrite(&copy_user,sizeof(struct info_user),1,info2);
                    fclose(info2);
                    hapusBuku(copy_buku.id, 1);
                    info=fopen("info_buku.txt","a");
                    copy_buku.sisa--;
                    fwrite(&copy_buku,sizeof(struct info_buku),1,info);
                    fclose(info);
                    printf("\n\n\n\t >>> Buku berhasil dipinjam.");
                    printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
                    getch();
                }
            }
            else
            {
                printf("\n\n\t >>> ID buku yang Anda masukkan tidak ada. ");
                printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
                getch();
            }
        }
    }
    else
    {
        printf("\n\n\t >>> ID anggota yang Anda masukkan tidak ada.");
        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
        getch();
    }
    return;
}

//***FUNCTION CEK TANGGAL***//

int cek_tanggal(struct tanggal a)
{
    if((a.dd>=1)&&(a.dd<=30)&&(a.mm>=1)&&(a.mm<=12)&&(a.yy>2000))
        return 1;
    else
        return 0;
}

//***FUNCTION TENGGAT***//

void tenggat(void)
{
    copy_user.kembali=copy_user.pinjam;
    copy_user.kembali.dd+=30;
    if(copy_user.kembali.dd>30)
    {
        copy_user.kembali.dd-=30;
        copy_user.kembali.mm++;
        if(copy_user.kembali.mm>12)
        {
            copy_user.kembali.mm-=12;
            copy_user.kembali.yy++;
        }
    }
    return;
}

//***FUNCTION PENGEMBALIAN BUKU***//

void kembaliBuku(void)
{
    system("cls");
	char idUser[20];
    printf("\n\n\t\t\t Pengembalian Buku");
    printf("\n\t\t\t ~~~~~~~~~~~~~~~~~");
    printf("\n\n\t Masukkan ID anggota : ");
    fflush(stdin);
    scanf("%255[^\n]",&idUser);
    if(cek_user(idUser)==0)
    {
        printf("\n\n\t >>> ID anggota yang Anda masukkan tidak ada.");
        printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
        getch();
    }
    else
    {
        if(copy_user.id_buku==0)
        {
            printf("\n\n\t >>> ID anggota %d belum meminjam buku apa pun.",idUser);
            printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
            getch();
        }
        else
        {
            struct tanggal r;
            int d;
            do
            {
                do
                {
                    printf("\n\t Masukkan tanggal pengembalian (dd-mm-yyyy) : ");
                    fflush(stdin);
                    scanf("%d-%d-%d",&r.dd,&r.mm,&r.yy);
                    if(cek_tanggal(r))
                        break;
                    printf("\n\n\t >>> Silakkan masukkan tanggal yang benar.\n");
                    getch();
                }while(1);
                d=denda(r,0);
                if(d>0)
                {
                    printf("\n\n\t Tanggal pengembalian seharusnya pada %d-%d-%d.",copy_user.kembali.dd,copy_user.kembali.mm,copy_user.kembali.yy);
                    printf("\n\n\t >>> Silakan membayar denda sebesar %d ribu rupiah.\n",d);
                    getch();
                    break;
                }
                else if(d<0)
                {
                    if(denda(r,1)<0)
                    {
                        printf("\n\n\t Tanggal peminjaman dilakukan pada %d-%d-%d.",copy_user.pinjam.dd,copy_user.pinjam.mm,copy_user.pinjam.yy);
                        printf("\n\n\t >>> Silakan masukkan tanggal setelah tanggal peminjaman.\n\n");
                        getch();
                    }
                    else
                        break;
                }
            }while(1);
            cek_buku(copy_user.id_buku);
            copy_buku.sisa++;
            hapusBuku(copy_user.id_buku, 1);
            info=fopen("info_buku.txt","a");
            fwrite(&copy_buku,sizeof(struct info_buku),1,info);
            fclose(info);
            hapusUser(idUser, 1);
            strcpy(copy_user.id_buku,"0");
            copy_user.pinjam.dd=copy_user.pinjam.mm=copy_user.pinjam.yy=copy_user.kembali.dd=copy_user.kembali.mm=copy_user.kembali.yy=0;
            info2=fopen("info_user.txt","a");
            fwrite(&copy_user,sizeof(struct info_buku),1,info2);
            fclose(info2);
            printf("\n\n\t >>> Buku berhasil dikembalikan.");
            printf("\n\n\t Tekan tombol apa saja untuk melanjutkan...");
            getch();
        }
    }
    return;
}

//***FUNCTION DENDA***//

int denda(struct tanggal r,int i)
{
    int d;
    if(i)
    {
         d=(r.yy-copy_user.pinjam.yy)*360+(r.mm-copy_user.pinjam.mm)*30+r.dd-copy_user.pinjam.dd;
        return d;
    }
    else
    {
        d=(r.yy-copy_user.kembali.yy)*360+(r.mm-copy_user.kembali.mm)*30+r.dd-copy_user.kembali.dd;
        return d;
    }
}

//***FUNCTION KELUAR***//

void keluar(void)
{
    system("cls");
    printf("\n\n\t\t Apakah Anda benar-benar ingin keluar program? [1] Ya [0] Tidak : ");
    int keluar;
    fflush(stdin);
    scanf("%d",&keluar);
    if(keluar==1)
        exit(1);
    return;
}
