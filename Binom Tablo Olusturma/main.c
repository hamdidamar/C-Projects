#include <stdio.h>
#include <stdlib.h>

double DereceliUsAl(double alinanSayi,int dereceSayisi);
double BinomOlasilikHesapla(int elemanSayisi,int eylemSayisi,double olmaOlasiligi);

const int olasilikOranSayisi = 11;
const float olasilikOranlari[11] = {0.05,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,0.95};

int main()
{

    printf("Hello world!\n");
    BinomTabloOlustur(15);
    return 0;
}

double FaktoriyelAl(int alinanSayi)
{

    if(alinanSayi>=1)
    {
        return alinanSayi* FaktoriyelAl(alinanSayi-1);

    }

    else return 1;

}

double DereceliUsAl(double alinanSayi,int dereceSayisi)
{
    int sayiSayac=0;
    double tumDeger=1;
    if(dereceSayisi==0) return 1;

    else if(dereceSayisi>0)
    {



        for(sayiSayac = dereceSayisi; sayiSayac>0;sayiSayac--)
            {
                tumDeger*=alinanSayi;
            }

        return tumDeger;

    }

    else
        {
            for(sayiSayac = dereceSayisi; sayiSayac>-1;sayiSayac--)
            {
                alinanSayi/=alinanSayi;
            }
            return alinanSayi;
        }


}



double BinomOlasilikHesapla(int elemanSayisi,int eylemSayisi,double olmaOlasiligi)
{
  return  FaktoriyelAl(elemanSayisi)/
  (FaktoriyelAl(eylemSayisi)*
   FaktoriyelAl(elemanSayisi-eylemSayisi))*
   DereceliUsAl(olmaOlasiligi,eylemSayisi)*
   DereceliUsAl((1-olmaOlasiligi),(elemanSayisi-eylemSayisi));
}

void BinomTabloOlustur(int maxNDegeri)

{
    printf("\n \t \t \t \t \t \t \t \t p\n");
    AyiracYazdir();
    printf("\n \t n \t | x \t  ");
    int yazdirmaSayac=0;
    for(yazdirmaSayac = 0; yazdirmaSayac<olasilikOranSayisi;yazdirmaSayac++)printf("|%.3f\t ",olasilikOranlari[yazdirmaSayac]);
    printf("\n");
    int simdikiNDegeri = 1;

    while(simdikiNDegeri!=maxNDegeri)
        {
            BinomBirimTabloOlustur(++simdikiNDegeri);
        }

}

void BinomBirimTabloOlustur(int NDegeri)
{
    AyiracYazdir();
    int yazdirmaSayac=0;
    int xSayaci;
    for(xSayaci=0; xSayaci<=NDegeri;xSayaci++)
    {
    printf("\n \t %d \t | %d \t  ",NDegeri,xSayaci);
    for(yazdirmaSayac = 0; yazdirmaSayac<olasilikOranSayisi;yazdirmaSayac++)printf("|%.3f\t ",BinomOlasilikHesapla(NDegeri,xSayaci,olasilikOranlari[yazdirmaSayac]));
    printf("\n");
    }
}

void AyiracYazdir()
{
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
}
