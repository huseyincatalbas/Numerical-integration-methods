/*
#Ad-Soyad = Huseyin ÇATALBAŞ
#E-posta = hcatalbas@ceng.ktu.edu.tr
#Proje = Numerical integration methods
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void polDivide(char *argv[],int fixedVal);
void coefficientFind(char *argv[], int index);
void expFind(char *argv[], int startIndex);
void fixFind(char *argv[]);
void polCalc(char *argv[], int fragmentationValue, char integralType);

int polLength=0, polCounter=0,fixedVal=0;
int coefficientArray[100];
int expArray[100];
double polSmallValue, polBigValue;


int main(int argc, char *argv[])
{
    char integralType=argv[5][0];
    int fragmentationValue=atoi(argv[4]);

    polDivide(argv, fixedVal);

     polSmallValue=((double)argv[2][0])-48;
     polBigValue=((double)argv[3][0])-48;

    printf("Girilen Polinom Ifadesi\t:%s\n",argv[1]);
    printf("Baslangic Degeri\t:%.2f \n",polSmallValue);
    printf("Bitis Degeri\t\t:%.2f\n",polBigValue);
    printf("Parcalama Miktari\t:%d\n",fragmentationValue);
    printf("Hangi Yontem\t\t:");

    if(integralType=='0'){printf("Dikdortgen Kurali\n");}
    if(integralType=='1'){printf("Dikdortgen Orta Nokta Kurali\n");}
    if(integralType=='2'){printf("Yamuk(Trapez) Kurali\n");}
    if(integralType=='3'){printf("Simpson Kurali\n");}

    for(int i=1;i<=polCounter;i++)
    //Polinom ifadesindeki üsleri,katsayıları ve sabitleri yazdırdım.
    {
        printf("%d.Terimin Katsayi Degeri:%d \n",i,coefficientArray[i]);
        printf("%d.Terimin Us Degeri \t:%d \n",i,expArray[i]);
    }
    printf("Sabit Sayi Degeri\t:%d\n",fixedVal);

    polCalc(argv, fragmentationValue, integralType);
    return 0;
}

void polDivide(char *argv[], int fixedVal)
 {
    while(argv[1][polLength]!=0)
    {polLength++;}
    //Polinomun karakter uzunluğunu belirledim.

   for(int i=0;i<polLength;i++)
   {
            if(argv[1][i]=='x')
            {
                polCounter++;
                coefficientFind(argv, i);
                if(argv[1][i+1]=='^')expFind(argv, i+2);
            }
   }
   fixFind(argv);
 }

void coefficientFind(char *argv[], int startIndex)
{
    if(polCounter == 1 && startIndex == 0)coefficientArray[polCounter]=1;
    else
    {
        int finishIndex=0;
         for(int i=startIndex-1; i>=0; i--)
        {
            if('+' == argv[1][i] || '-' == argv[1][i] )
            {
                finishIndex = i+1;
                break;
            }
        }
        
        int coefficientValue=1;
        int coefficientSum=0;

        for(int i=startIndex-1; i>=finishIndex; i--)
        {
                coefficientSum+= (((int)argv[1][i])-48) * coefficientValue;
                coefficientValue *= 10;
        }
        coefficientArray[polCounter]=coefficientSum;
    }
}

void expFind(char *argv[], int startIndex)
{
    int finishIndex=0;
    int expValue=1;
    int expSum=0;
    for(int i=startIndex; i<=polLength; i++)
    {
        if('+' == argv[1][i] || '-' == argv[1][i] || polLength == (((int)argv[1][i])-48))
        {
            finishIndex = i-1;
            break;
        }
    }


    for(int i=finishIndex; i>=startIndex; i--)
    {
        expSum+= (((int)argv[1][i])-48) * expValue;
        expValue *= 10;
    }
    expArray[polCounter]=expSum;
    
}

void fixFind(char *argv[])
{
    int fixedNumberVal=1;
    int fixedNumberSum=0;
        for(int i=polLength-1; i>=0; i--)
        {
                if('+' == argv[1][i] || '-' == argv[1][i]) {break;}
                else
                {
                fixedNumberSum+=(((int)argv[1][i])-48) * fixedNumberVal;
                fixedNumberVal *= 10;
                }
                
        }
    fixedVal=fixedNumberSum;
}

void polCalc(char *argv[], int fragmentationValue, char integralType)
{
    if(polCounter<=0)
    //İfadenin polinom olup olmadığını polCounter değişkenin aldığı değeri kontrol ettirerek baktırdım.
    {
    printf("Gecersiz Polinom Ifadesi:%s",argv[1]);
    return;
    }

    double integralTypeResult=0;
    double temporaryIntegralTypeResult=0;
    double numberIncreaseAmount=(polBigValue-polSmallValue)/fragmentationValue;
    /*Komut ekranından girilen büyük sayı ile küçük sayı arasındaki farkı bulup istenilen fragmentationValue
     değişkenine böldürterek her adımdaki artış miktarını buldurdum.*/
    double tempIntegralBigValue=polSmallValue+numberIncreaseAmount;
    double tempIntegralSmallValue=polSmallValue;
    //Üst sınır her adımda değişeceği için tempIntegralBigValue adlı bir değişkene ihtiyaç duydum.


    for(double i=polSmallValue; i<=polBigValue; i+=numberIncreaseAmount)
    {
        if(integralType == '3')
        {
            for(int j=1;j<=polCounter;j++)
            {temporaryIntegralTypeResult+=(double)coefficientArray[j]*pow((tempIntegralSmallValue+tempIntegralBigValue)/2,(double)expArray[j]);}

            temporaryIntegralTypeResult+=fixedVal;//Oluşan geçici sonuca sabit sayısını ekledim.
            temporaryIntegralTypeResult*=4;

            for(int j=1;j<=polCounter;j++)
            {temporaryIntegralTypeResult+=(double)coefficientArray[j]*pow(tempIntegralBigValue,(double)expArray[j]);}

            temporaryIntegralTypeResult+=fixedVal;//Oluşan geçici sonuca sabit sayısını ekledim.

            for(int j=1;j<=polCounter;j++)
            {temporaryIntegralTypeResult+=(double)coefficientArray[j]*pow(tempIntegralSmallValue,(double)expArray[j]);}
            
        }
        else
        {
            for(int j=1;j<=polCounter;j++)
            {
                if(integralType == '0' || integralType == '2')
                {temporaryIntegralTypeResult+=(double)coefficientArray[j]*pow(tempIntegralSmallValue,(double)expArray[j]);}
                else if(integralType == '1')
                {temporaryIntegralTypeResult+=(double)coefficientArray[j]*pow((tempIntegralSmallValue+tempIntegralBigValue)/2,(double)expArray[j]);}
            }
        }
           
        temporaryIntegralTypeResult+=fixedVal;//Oluşan geçici sonuca sabit sayısını ekledim.

        if(integralType == '3') 
        {integralTypeResult+=temporaryIntegralTypeResult*((tempIntegralBigValue-tempIntegralSmallValue)/6);}
        else if(integralType == '2') 
        {integralTypeResult+=(temporaryIntegralTypeResult/2)*(tempIntegralBigValue-tempIntegralSmallValue);}
        else 
        {integralTypeResult+=temporaryIntegralTypeResult*(tempIntegralBigValue-tempIntegralSmallValue);}

        tempIntegralSmallValue=tempIntegralBigValue;
        //Sonraki adımda tempIntegralBigValue polSmallValue olacağı için değer aktarma işlemi yaptım.
        tempIntegralBigValue+=numberIncreaseAmount;
        //Sonraki adımda tempIntegralBigValue artış miktarı kadar artması gerekeceği için değer artırma işlemi yaptım.
        temporaryIntegralTypeResult=0;
        //temporaryIntegralTypeResult değişkenini sıfırlayarak bir sonraki aralıktaki değerleri adım adım almayı sağlıyoruz.
    }
           
    printf("Integralin Sonucu\t:%.2f",integralTypeResult);

}