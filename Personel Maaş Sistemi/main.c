
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

long int TCKimlik[50];
char Ad[50][50],Soyad[50][50],MedeniHal,EsCalismaDur,EngelDurum,PerEkle,YedekAdDizi[50],YedekSoyadDizi[50];
float AylikBrutUcret[50],AylikTopBrutUcret[50],AylikGunTopBrutUcret[50],VergidenSonraBrut[50],ToplamGenel,ToplamVergiKes,IlkParaToplam,EnYuksekBrutuOlan,EnYukAylikUcret;
int EsYardimi,CocukYardim,CocukSay,YasBuyuk,EngelOran,EngelIndirimi=0,EngelDerece=0;
int PersonelSay=-1,IkiBinAltinda=0;
int k1[100],k50[100],k25[100],k10[100],k5[100],k01[100];
int b200[100],b100[100],b50[100],b20[100],b10[100],b5[100];
int DonusumTam[50],KurusDonusum[50];
int Top200,Top100,Top50,Top20,Top10,Top5,Top1,Topk50,Topk25,Topk10,Topk5,Topk1;
int YirmiYediVergi=0,OtuzBesVergi=0,YirmiVergi=0,OnBesVergi=0;
float YirmiYediVergiYuzde,OtuzBesVergiYuzde,YirmiVergiYuzde,OnBesVergiYuzde;
int i,k,j,EvliSay=0,BekarSay=0,EsCalisiyor=0,CocuguOlan=0,TopCocSay=0,UctenFazlaCoc=0,EngCalSay=0;
int main()
{
    setlocale(LC_ALL,"Turkish");
    PersonelBilgi();
}
void PersonelBilgi()
{
    PersonelSay++;
    printf("TC Kimlik Numaranýz:");
    scanf("%ld",&TCKimlik[PersonelSay]);
    printf("Adýnýz Soyadýnýz:");
    scanf("%s %s",&YedekAdDizi,&YedekSoyadDizi);
    for(i=0;i<strlen(YedekAdDizi);i++)
        {
            Ad[PersonelSay][i]=YedekAdDizi[i];
            Soyad[PersonelSay][i]=YedekSoyadDizi[i];
        }
    printf("Aylýk Brüt Ücretinizi Giriniz:");
    scanf("%f",&AylikBrutUcret[PersonelSay]);
    EsDurum();
}
void EsDurum()
{
    printf("Medeni Durumunuz:(e/E/b/B) ");
    scanf("%s",&MedeniHal);
    if (MedeniHal=='e'|| MedeniHal=='E')
    {
        printf("Eþiniz Çalýþýyor Mu: (e/E/h/H) ");
        scanf("%s",&EsCalismaDur);
        if (EsCalismaDur == 'e'||EsCalismaDur=='E')
        {
            EvliSay++;
            EsCalisiyor++;
            CocukBilgileri();
        }
        else if (EsCalismaDur == 'h'||EsCalismaDur=='H')
        {
            EvliSay++;
            EsYardimi=220;
            CocukBilgileri();
        }
        else
        {
            printf("Lütfen Ýstenen Deðerleri Giriniz\a\a");
            EsDurum();
        }
    }
    else if (MedeniHal=='B'|| MedeniHal=='b')
    {
        BekarSay++;
        VergiHesabi();
    }
    else
    {
        printf("Lütfen Ýstenen Deðerleri Giriniz\a\a");
        EsDurum();
    }
}
void CocukBilgileri()
{
    printf("Bakmakla yükümlü olduðu çocuk sayýsý: ");
    scanf("%d",&CocukSay);
    if (CocukSay>0)
    {
        printf("6 Yaþýndan Büyük Çocuk Sayýsý: ");
        scanf("%d",&YasBuyuk);
        if (CocukSay>=YasBuyuk)
        {
            CocuguOlan++;
            TopCocSay+=CocukSay;
            CocukYardim=(YasBuyuk*45)+(CocukSay-YasBuyuk)*25;
            if (CocukSay>3)
            {
                UctenFazlaCoc++;
            }
            VergiHesabi();
        }
        else
        {
            printf("O kadar çocuðunuz yok \a\a");
            CocukBilgileri();
        }
    }
    else if (CocukSay==0)
    {
        VergiHesabi();
    }
    else
    {
        printf("Çocuk Sayýsý Negatif Olamaz\a\a");
        CocukBilgileri();
    }
}
void VergiHesabi()
{
    AylikTopBrutUcret[PersonelSay]=AylikBrutUcret[PersonelSay]+EsYardimi+CocukYardim;
    AylikGunTopBrutUcret[PersonelSay]=AylikTopBrutUcret[PersonelSay];
    if (AylikTopBrutUcret[PersonelSay] < 2000)
    {
        AylikTopBrutUcret[PersonelSay] -= AylikTopBrutUcret[PersonelSay] * 15/100;
        OnBesVergi++;
        EngelBilgileri();
    }
    else if (AylikTopBrutUcret[PersonelSay] >= 2000 && AylikTopBrutUcret[PersonelSay] < 5000)
    {
        AylikTopBrutUcret[PersonelSay] -= AylikTopBrutUcret[PersonelSay] * 20/100;
        YirmiVergi++;
        EngelBilgileri();
    }
    else if (AylikTopBrutUcret[PersonelSay] >= 5000 && AylikTopBrutUcret[PersonelSay] < 10000)
    {
        AylikTopBrutUcret[PersonelSay] -= AylikTopBrutUcret[PersonelSay] * 27/100;
        YirmiYediVergi++;
        EngelBilgileri();
    }
    else if (AylikTopBrutUcret[PersonelSay] >= 10000)
    {
        AylikTopBrutUcret[PersonelSay] -= AylikTopBrutUcret[PersonelSay] * 35/100;
        OtuzBesVergi++;
        EngelBilgileri();
    }
}
void EngelBilgileri()
{
    VergidenSonraBrut[PersonelSay]=AylikTopBrutUcret[PersonelSay];
    printf("Her Hangi Bir Engeliniz Var mý:(e/E/h/H) ");
    scanf("%s",&EngelDurum);
    if (EngelDurum=='e'|| EngelDurum=='E')
    {
        EngCalSay++;
        printf("Engel Oranýný Giriniz: ");
        scanf("%d",&EngelOran);
        if (EngelOran>=80)
        {
            VergidenSonraBrut[PersonelSay]+=900;
            EngelDerece=1;
            Donusum();
        }
        else if (EngelOran>=60&&EngelOran<80)
        {
            VergidenSonraBrut[PersonelSay]+=470;
            EngelDerece=2;
            Donusum();
        }
        else if (EngelOran>=40&&EngelOran<60)
        {
            VergidenSonraBrut[PersonelSay]+=210;
            EngelDerece=3;
            Donusum();
        }
        else if (EngelOran==0&&EngelOran<40)
        {
            Donusum();
        }

    }
    else if (EngelDurum=='h'|| EngelDurum=='H')
        {
            Donusum();
        }

}
void Donusum()
{
    DonusumTam[PersonelSay] = (int)VergidenSonraBrut[PersonelSay];
    b200[PersonelSay] = (DonusumTam[PersonelSay] /200);
    b100[PersonelSay] = (DonusumTam[PersonelSay] %200)/100;
    b50[PersonelSay]  = (DonusumTam[PersonelSay] %100)/50;
    b20[PersonelSay]  = (DonusumTam[PersonelSay] % 50)/20;
    b10[PersonelSay]  = (DonusumTam[PersonelSay] % 15)/10;
    b5[PersonelSay]   = (DonusumTam[PersonelSay] % 10)/5;
    k1[PersonelSay]   = (DonusumTam[PersonelSay] %  5)/1;

    KurusDonusum[PersonelSay] = (VergidenSonraBrut[PersonelSay] - DonusumTam[PersonelSay])*100; /*Virgülden sonraki kýsmý bulmak için yaptýk */
    k50[PersonelSay] = (KurusDonusum[PersonelSay] /50);
    k25[PersonelSay] = (KurusDonusum[PersonelSay] %50)/25;
    k10[PersonelSay] = (KurusDonusum[PersonelSay] %25)/10;
    k5[PersonelSay]  = (KurusDonusum[PersonelSay] %10)/5;
    k01[PersonelSay] = (KurusDonusum[PersonelSay] % 5)/1;



    printf("\n\nTC Kimlik Numarasý ve Adý Soyadý:%ld  %s %s",TCKimlik[PersonelSay],Ad[PersonelSay],Soyad[PersonelSay]);
    printf("\nAylýk Brüt Ücreti:%.2f",AylikBrutUcret[PersonelSay]);
    printf("\nEþ Ýçin Aile Yardým Ödeneði:%d",EsYardimi);
    printf("\nÇocuk Ýçin Aile Yardýmý Ödeneði:%d",CocukYardim);
    printf("\nAylýk Toplam Brüt Ücreti:%.2f",AylikBrutUcret[PersonelSay]+EsYardimi+CocukYardim);
    printf("\nGelir Vergisi Kesintisi:%.2f",AylikGunTopBrutUcret[PersonelSay]-AylikTopBrutUcret[PersonelSay]);
    printf("\nEngel Derecesi:%d",EngelDerece);
    printf("\nAylýk net ücreti:%.2f",VergidenSonraBrut[PersonelSay]);
    printf("\n\n\n200\t 100\t 50\t 20\t 10\t 5\t 1\t0.5\t0.25\t0.1\t0.05\t0.01");
    printf("\n---\t ---\t ---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t ");
    printf("\n%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d ",b200[PersonelSay],b100[PersonelSay],b50[PersonelSay],b20[PersonelSay],b10[PersonelSay],b5[PersonelSay],k1[PersonelSay],k50[PersonelSay],k25[PersonelSay],k10[PersonelSay],k5[PersonelSay],k01[PersonelSay]);
    printf("\n\nBaþka Personel Eklemek Ýster Misiniz:(e/E/h/H) ");
    scanf("%s",&PerEkle);
    if (PerEkle=='e'|| PerEkle=='E')
    {
        PersonelBilgi();
    }
    else if (PerEkle=='h'|| PerEkle=='H')
    {
        GenelTablo();
    }
}
void GenelTablo()
{
    for (i=0;i<=PersonelSay;i++)
    {
        ToplamGenel+=VergidenSonraBrut[i];
        Top200+=b200[PersonelSay];
        Top100+=b100[PersonelSay];
        Top50+=b50[PersonelSay];
        Top20+=b20[PersonelSay];
        Top10+=b10[PersonelSay];
        Top5+=b5[PersonelSay];
        Top1+=k1[PersonelSay];
        Topk50+=k50[PersonelSay];
        Topk25+=k25[PersonelSay];
        Topk10+=k10[PersonelSay];
        Topk5+=k5[PersonelSay];
        Topk1+=k01[PersonelSay];
    }
    for (i=0;i<PersonelSay;i++)
    {
        ToplamVergiKes+=AylikGunTopBrutUcret[PersonelSay]-AylikTopBrutUcret[PersonelSay];
        if (VergidenSonraBrut[i]<2000)
        {
            IkiBinAltinda++;
        }
    }
    for (i=0;i<PersonelSay;i++)
    {
        IlkParaToplam+=AylikBrutUcret[PersonelSay];
    }

    if (OnBesVergi==0)
        OnBesVergiYuzde==0;
    else
        OnBesVergiYuzde=OnBesVergi/(PersonelSay+1);
    if(YirmiVergi==0)
        YirmiVergiYuzde==0;
    else
        YirmiVergiYuzde=YirmiVergi/(PersonelSay+1);
    if(YirmiYediVergi==0)
        YirmiYediVergiYuzde==0;
    else
        YirmiYediVergiYuzde=YirmiYediVergi/(PersonelSay+1);
    if (OtuzBesVergi==0)
        OtuzBesVergiYuzde==0;
    else
        OtuzBesVergiYuzde=OtuzBesVergi/(PersonelSay+1);

    EnYuksekBrutuOlan=AylikGunTopBrutUcret[0];
    for (i=0;i<PersonelSay+1;i++)
    {
        if (EnYuksekBrutuOlan<AylikGunTopBrutUcret[i])
        {
            EnYuksekBrutuOlan=AylikGunTopBrutUcret[i];
        }
    }
    for (i=0;i<PersonelSay+1;i++)
    {
        if (AylikGunTopBrutUcret[i]==EnYuksekBrutuOlan)
        {
            k=i;
            break;
        }
    }
    EnYukAylikUcret=VergidenSonraBrut[0];
    for (i=0;i<PersonelSay+1;i++)
    {
        if (EnYukAylikUcret<VergidenSonraBrut[i])
        {
            EnYukAylikUcret=VergidenSonraBrut[i];
        }
    }
    for (i=0;i<PersonelSay+1;i++)
    {
        if (VergidenSonraBrut[i]==EnYukAylikUcret)
        {
            j=i;
            break;
        }
    }



    printf("\nTüm Personellere Ödenen Aylýk Toplam Net Ücret Tutarý: %.2f",ToplamGenel);
    printf("\nDevlete Aktarýlan Vergi Miktarý: %.2f",ToplamVergiKes);
    printf("\nTüm Çalýþanlarýn Aylýk Toplam Brüt Ücretlerinin Ortalamasý: %.2f",IlkParaToplam/(PersonelSay+1));
    printf("\nTüm Çalýþanlarýn Aylýk Toplam Net Ücretlerinin Ortalamasý: %.2f",ToplamGenel/(PersonelSay+1));
    printf("\nTedavülde Bulunmasý Gereken Para Miktarlarý;");
    printf("\n\n200\t 100\t 50\t 20\t 10\t 5\t 1\t0.5\t0.25\t0.1\t0.05\t0.01");
    printf("\n---\t ---\t ---\t---\t---\t---\t---\t---\t---\t---\t---\t---\t ");
    printf("\n%d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d \t %d ",Top200,Top100,Top50,Top20,Top10,Top5,Top1,Topk50,Topk25,Topk10,Topk5,Topk1);
    printf("\n2000 TL’nin Altýnda Aylýk Net Ucret Alan Çalýþanlarýn Sayýsý:%d",IkiBinAltinda+1);
    printf("\nGelir Vergi Oraný 15 Olan Kiþi Sayýsý Ve Yüzdesi: %d  %.2f",OnBesVergi,OnBesVergiYuzde);
    printf("\nGelir Vergi Oraný 20 Olan Kiþi Sayýsý Ve Yüzdesi: %d  %.2f",YirmiVergi,YirmiVergiYuzde);
    printf("\nGelir Vergi Oraný 27 Olan Kiþi Sayýsý Ve Yüzdesi: %d  %.2f",YirmiYediVergi,YirmiYediVergiYuzde);
    printf("\nGelir Vergi Oraný 35 Olan Kiþi Sayýsý Ve Yüzdesi: %d  %.2f",OtuzBesVergi,OtuzBesVergiYuzde);
    printf("\n\nEn Yüksek Maaþlý Kiþinin;");
    printf("\nTC Kimlik Numarasý: %ld",TCKimlik[k]);
    for (i=0;i<50;i++)
    {
        YedekAdDizi[i]=Ad[k][i];
        YedekSoyadDizi[i]=Soyad[k][i];
    }
    printf("\nAdý Soyadý: %s %s",YedekAdDizi,YedekSoyadDizi);

    printf("\nAylýk Toplam Brüt Ücreti:%.2f",AylikGunTopBrutUcret[k]);
    printf("\nGelir Vergisi Kesintisi:%.2f",AylikGunTopBrutUcret[k]-AylikTopBrutUcret[k]);
    printf("\nAylýk Net Ücreti:%.2f",VergidenSonraBrut[k]);


    printf("\n\nAylýk Net Ücreti En Yüksek Olan Çalýþaný;");
    printf("\nTC Kimlik Numarasý: %ld",TCKimlik[j]);
        for (i=0;i<50;i++)
    {
        YedekAdDizi[i]=Ad[j][i];
        YedekSoyadDizi[i]=Soyad[j][i];
    }
    printf("\nAdý Soyadý: %s %s",YedekAdDizi,YedekSoyadDizi);
    printf("\nAylýk Toplam Brüt Ücreti:%.2f",AylikGunTopBrutUcret[j]);
    printf("\nGelir Vergisi Kesintisi:%.2f",AylikGunTopBrutUcret[j]-AylikTopBrutUcret[j]);
    printf("\nAylýk Net Ücreti:%.2f",VergidenSonraBrut[j]);
    printf("\nTüm Çalýþanlar Ýçindeki Evli Oraný: %.2f",(float)EvliSay/(float)(PersonelSay+1));
    printf("\nTüm Çalýþanlar Ýçindeki Bekar Oraný: %.2f",(float)BekarSay/(float)(PersonelSay+1));
    printf("\nEvli Olan Çalýþanlarýn Ýçinde, Eþleri De Çalýþanlarýn Yüzdesi: %f",(float)EsCalisiyor/(float)EvliSay);
    printf("\nSadece Bakmakla Yükümlü Çocuðu Olanlar Dikkate Alýnarak, Çalýþanlarýn Bakmakla Yükümlü Olduklarý Çocuk Sayýsýnýn Ortalamasý: %f",(float)TopCocSay/(float)CocuguOlan);
    printf("\nBakmakla Yükümlü Olduðu Çocuk Sayýsý 3’ten Fazla Olan Çalýþanlarýn Sayýsý: %d",UctenFazlaCoc);
    printf("\nEngelli Çalýþanlarýn Sayýsý Ve Tüm Çalýþanlar Ýçindeki Yüzdesi: %.2f",(float)EngCalSay/(float)(PersonelSay+1));


}














