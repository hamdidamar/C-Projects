#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
    int temp,count;

    printf("Lutfen Dizinin Boyutunu Giriniz:\n");
    scanf("%d",&k);
    int dizi[k];
    //boyut ayarlama
    for(int i=0; i<k; i++)
    {
        printf("Lutfen %d. Sayiyi Giriniz:\n",i+1);
        scanf("%d",&dizi[i]);
    }
    //sýralama
    count = k;
    for(int i=1; i<k-1; i++)
    {
            for(int j=0;j<count-1; j++)
            {
                if(dizi[j]>dizi[j+1])
                {
                    temp=dizi[j];
                    dizi[j]=dizi[j+1];
                    dizi[j+1]=temp;
                }
            }

    }
    //fonksiyonlar
    aritmetikhesapla(dizi,k);
    geometrikhesapla(dizi,k);
    medyanbulma(dizi,k);
    return 0;
}
void aritmetikhesapla(int siralidizi[],int uzunluk)
{
    float toplam=0;
    float aritmetikortalama = 0;

    for (int i=0; i<uzunluk; i++)
    {
        toplam += siralidizi[i];
    }
    aritmetikortalama = toplam/uzunluk;
    printf("aritmetik ortalama = %0.2f ",aritmetikortalama);
}
void geometrikhesapla(int siralidizi[],int uzunluk)
{
    float carpim=1;
    float geometrikortalama = 0;

    for (int i=0; i<uzunluk; i++)
    {
        carpim *= siralidizi[i];
    }
    geometrikortalama = pow(carpim,(double)1/uzunluk);
    printf("Geometrik Ortalama Sonucu : %0.2f ",geometrikortalama);
}
void medyanbulma(int siralidizi[],int uzunluk)
{
    float medyan;

    if(uzunluk%2==0)
    {
       medyan=((siralidizi[uzunluk/2-1]+(siralidizi[uzunluk/2]))/2);
    }
    else if (uzunluk%2==1)
    {
        medyan = siralidizi[(uzunluk+1)/2 - 1];
    }
    printf("medyan: %0.2f ",medyan);
}
void modbulma(int siralidizi[],int uzunluk)
{
    for(int i=0 ; i<uzunluk-1; i++)
    {
        for(j=0; j<uzunluk-1; j++)
            {

            }

    }

}
