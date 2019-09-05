//HAMD� DAMAR 172802029
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
typedef struct {
 char isim[100];
 char TCKimlikNo[20];
 char telefon[20];
char eposta[100];
char adres[100];
 }personel;

 void anamenu();
 void anasecim();
 void kayitekle();
 void  personellistele();
 void kayitduzenle();
 void tcilebul();
 void isimilebul();
 void kayitsil();
 void cikis();
 void bekle();
personel p_personel;

int main()
{


   setlocale(LC_ALL,"Turkish");
   anamenu();

    return 0;
}
void anamenu()
{
    printf("************PERSONEL B�LG� S�STEM�************\n");
    printf("�SLEMLER\n");
    printf("1. Kay�t Ekle\n");
    printf("2. Personel Listele\n");
    printf("3. Kayd� D�zenle\n");
    printf("4. TC Kimlik No ile Kay�t Bul\n");
    printf("5. �sim ile Kay�t Bul\n");
    printf("6. Kay�t Sil\n");
    printf("0. ��k��\n");
    printf("********************************************\n");

    anasecim();


}
void anasecim()
{
    int secimm;
    printf("L�tfen Se�iminizi Giriniz : \n");
    scanf("%d",&secimm);
    switch(secimm)
    {
    case 1:
        {
            kayitekle();
            break;
        }
    case 2:
        {
            personellistele();
            break;
        }
    case 3:
        {
            kayitduzenle();
            break;
        }
    case 4:
        {
            tcilebul();
            break;
        }
    case 5:
        {
          isimilebul();
          break;
        }
    case 6:
        {
            kayitsil();
            break;
        }
    case 0:
        {
            cikis();
            break;
        }
    default:
        {
            printf("Yanl�� Secim Girdiniz L�tfen Tekrar Deneyin \a \n");
            anasecim();
        }
    }
}
void kayitekle()
{
 personel kayitgir;
 FILE *dosya;
 dosya=fopen("personel.txt","a+");

 if (dosya==NULL)
 {
     printf("Dosya Olu�turulurken Hata Olu�tu...");
     exit(1);
 }

 printf("\nL�tfen Ad�n�z� Giriniz :");
 scanf("%s",kayitgir.isim);

 printf("L�tfen TC Kimlik No Giriniz :");
 scanf("%s",kayitgir.TCKimlikNo);

 printf("L�tfen Telefon No Giriniz :");
 scanf("%s",kayitgir.telefon);

 printf("L�tfen E-posta Giriniz :");
 scanf("%s",kayitgir.eposta);

 printf("L�tfen Adres Giriniz :");
 scanf("%s",kayitgir.adres);

 fwrite(&kayitgir,sizeof(kayitgir),1,dosya);
 fclose(dosya);

 printf("Yeni Kay�t Eklemek �stermisiniz ? E/H ?");
if (toupper(getche())=='E'){
      kayitekle();
        }
     else{
         printf("\n Ana Men�ye Gitmek ��in E ��k�� ��in Herhangi Bir Tu�a Bas�n�z.. \n");
  if (toupper(getche())=='E')
{
        printf(" Ana Sayfaya Y�nlendiriliyorsunuz...\n\n");
        bekle(1);
        system("cls");
        anamenu();
        }
     }

 bekle(1);
 system("cls");
 anamenu();

}
void personellistele()
{
    FILE *dosya1;
    dosya1 = fopen("personel.txt","r");

 if (dosya1 == NULL)
 {
     printf("Dosya Olu�turulurken Hata Olu�tu...");
     exit(1);
 }
system("cls");
 personel personellistele1;
 while(fread(&personellistele1,sizeof(personellistele1),1,dosya1) == 1)
 {
     printf("�sim : %s \n",personellistele1.isim);
     printf("TC Kimlik : %s \n ",personellistele1.TCKimlikNo);
     printf("Telefon No : %s \n ",personellistele1.telefon);
     printf("E Posta : %s \n",personellistele1.eposta);
     printf("Adres : %s \n\n",personellistele1.adres);
 }
 printf(" Ana Men�ye Gitmek �stermisiniz ? E/H \n");
  if (toupper(getche())=='E')
{
        printf(" Ana Sayfaya Y�nlendiriliyorsunuz...\n\n");
        bekle(1);
        }
     else{
         personellistele();
     }
     fclose(dosya1);
 system("cls");
 anamenu();

}
void kayitduzenle()
{

     FILE *gunceldosya1;
    gunceldosya1= fopen("personel.txt","r");
    personel personellistele10;
    char duzenlenecektc[20];
    printf("L�tfen D�zenlemek �stedi�iniz Kayd�n TC Kimlik Numaras�n� Giriniz :\n");
    scanf("%s",duzenlenecektc);

    if (gunceldosya1 == NULL)
     {
         printf("Dosya Olu�turulurken Hata Olu�tu...");
         exit(1);
     }

    int aranankayitsirasi = 0;
    int bulunansayi = 0;

    while(fread(&personellistele10,sizeof(personellistele10),1,gunceldosya1) == 1)
     {
            aranankayitsirasi++;
         if(strcmp(personellistele10.TCKimlikNo,duzenlenecektc) == 0)
            {
                bulunansayi++;
                    break;
            }
    }
    fclose(gunceldosya1);
    FILE *gunceldosya5;
    personel personellistele15;
    gunceldosya5= fopen("personel.txt","rb+");

    if(bulunansayi == 1)
    {
        printf("L�tfen Yeni Ad�n�z� Giriniz :");
         scanf("%s",personellistele15.isim);

         printf("L�tfen Yeni TC Kimlik No Giriniz :\n");
         scanf("%s",personellistele15.TCKimlikNo);

         printf("L�tfen Yeni Telefon No Giriniz :");
         scanf("%s",personellistele15.telefon);

         printf("L�tfen Yeni E-posta Giriniz :");
         scanf("%s",personellistele15.eposta);

         printf("L�tfen Yeni Adres Giriniz :");
         scanf("%s",personellistele15.adres);

        fseek(gunceldosya5,(aranankayitsirasi-1)* sizeof(personellistele15),SEEK_SET);

        fwrite(&personellistele15,sizeof(personellistele15),1,gunceldosya5);

    }
    fclose(gunceldosya5);


     printf("\n Ana Men�ye Gitmek ��in E ��k�� ��in Herhangi Bir Tu�a Bas�n�z.. \n");
  if (toupper(getche())=='E')
{
        printf(" Ana Sayfaya Y�nlendiriliyorsunuz...\n\n");
        bekle(1);
        system("cls");
        anamenu();
        }

}
void tcilebul()
{
    FILE *dosya2;
    dosya2 = fopen("personel.txt","r+");

 if (dosya2 == NULL)
 {
     printf("Dosya Olu�turulurken Hata Olu�tu...");
     exit(1);
 }


     char aranantc[20];
     printf("L�tfen Arad���n�z TC Kimlik Numaras�n� Giriniz :");
     scanf("%s",aranantc);

     personel personellistele2;
    while(fread(&personellistele2,sizeof(personellistele2),1,dosya2) ==1 )
 {

     if(strcmp(aranantc,personellistele2.TCKimlikNo)==0)
{
     printf("\n �sim : %s \n",personellistele2.isim);
     printf("TC Kimlik : %s \n ",personellistele2.TCKimlikNo);
     printf("Telefon No : %s \n ",personellistele2.telefon);
     printf("E Posta : %s \n",personellistele2.eposta);
     printf("Adres : %s \n",personellistele2.adres);
 }
}
fclose(dosya2);
 printf("\n Ana Men�ye Gitmek ��in E ��k�� ��in Herhangi Bir Tu�a Bas�n�z.. \n");
  if (toupper(getche())=='E')
{
        printf(" Ana Sayfaya Y�nlendiriliyorsunuz...\n\n");
        bekle(1);
        system("cls");
        anamenu();
        }
}
void isimilebul()
{
    FILE *dosya3;
    dosya3 = fopen("personel.txt","r");

 if (dosya3 == NULL)
 {
     printf("Dosya Eri�im Hatas� Olu�tu...");
     exit(1);
 }

     char arananisim[20];
     printf("L�tfen Arad���n�z �smi Giriniz :");
     scanf("%s",arananisim);

     personel personellistele3;
    while(fread(&personellistele3,sizeof(personellistele3),1,dosya3) == 1)
 {

     if(strcmp(personellistele3.isim,arananisim) == 0)
{
     printf("\n�sim : %s \n",personellistele3.isim);
     printf("TC Kimlik : %s \n ",personellistele3.TCKimlikNo);
     printf("Telefon No : %s \n ",personellistele3.telefon);
     printf("E Posta : %s \n",personellistele3.eposta);
     printf("Adres : %s \n",personellistele3.adres);
 }
}
fclose(dosya3);
printf("\n Ana Men�ye Gitmek ��in E ��k�� ��in Herhangi Bir Tu�a Bas�n�z.. \n");
  if (toupper(getche())=='E')
{
        printf(" Ana Sayfaya Y�nlendiriliyorsunuz...\n\n");
        bekle(1);
        system("cls");
        anamenu();
        }
}
void kayitsil()
{
    FILE *dosya4;

    FILE *gecici;
    int bulunan;
    dosya4=fopen("personel.txt","r");
    gecici=fopen("gecici.txt","w");

    char silinecek_tc[20];

    printf("\nSilinecek Personelin T.C Numaras�:");
    scanf("%s",&silinecek_tc);

    while(fread(&p_personel,sizeof(p_personel),1,dosya4))
        {
        if(strcmp(silinecek_tc,p_personel.TCKimlikNo)!=0)
            {fwrite(&p_personel,sizeof(p_personel),1,gecici);
            }
        else {bulunan=1;}
        }
    if(bulunan!=1)printf("T.C Bulunamadi\n");

    fclose(gecici);
    fclose(dosya4);
    remove("personel.txt");
    rename("gecici.txt","personel.txt");

     printf("\n Ana Men�ye Gtmek ��in E ��k�� ��in Herhangi Bir Tu�a Bas�n�z.. \n");
  if (toupper(getche())=='E')
{
        printf(" Ana Sayfaya Y�nlendiriliyorsunuz...\n\n");
        bekle(1);
        system("cls");
        anamenu();
        }

}
void cikis()
{
   printf("��k�� Yapmak �stiyormusunuz: ");

    if (toupper(getche())=='E'){
        exit(1);
        }
     else{
         system("cls");
         anamenu();
     }
}

void bekle(int zaman)
{
    clock_t son;
    son = clock() + zaman * CLK_TCK ;
    while(clock()<son)
    {

    }
}

