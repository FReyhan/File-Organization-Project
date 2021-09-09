//1306180011
//Fatma Reyhan AKIN
//File Organization Proje Odevi

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <regex>
#include <stdlib.h>
#include <vector>
using namespace std;

int kirmizi[24];   //Kirmizi pullarin dizisi
int beyaz[24];     //Beyaz pullarin dizisi
int Z1;            //Zar1
int Z2;            //Zar2
int KB=0;          //Kirik beyaz pul sayisi
int KK=0;          //Kirik kirmizi pul sayisi

vector<char>buffer;  //Kaydedilen oyun dosyasindaki bilginin okunmasinda kullanilacak buffer


void ekrana_yazdirma(){

  cout<<"************************************************"<<endl;
  cout<<"11  10  9   8   7   6    5   4   3   2   1   0  "<<endl;
  cout<<"------------------------------------------------"<<endl;
  cout<<"1   2   3   4   5   6    6   5   4   3   2   1  "<<endl;
  for(int i=11;i>=0;i--){
      if(kirmizi[i]!=0 && beyaz[i]==0){
        cout<<kirmizi[i]<<"K  ";
      }

      if(beyaz[i]!=0 && kirmizi[i]==0){
        cout<<beyaz[i]<<"B  ";
      }
      else if(beyaz[i]==0 && kirmizi[i]==0){
        cout<<"    ";
      }
   }
  cout<<endl;
  cout<<"                                                "<<endl;
  cout<<"                "<<KB<<"KB "<<Z1<<"   "<<Z2<<"  "<<KK<<"KK                "<<endl;
  cout<<"                                                "<<endl;

  for(int i=12;i<24;i++){
      if(kirmizi[i]!=0 && beyaz[i]==0){
        cout<<kirmizi[i]<<"K  ";
      }

      if(beyaz[i]!=0 && kirmizi[i]==0){
        cout<<beyaz[i]<<"B  ";
      }
      else if(beyaz[i]==0 && kirmizi[i]==0){
        cout<<"    ";
      }
   }
   cout<<endl;
   cout<<"1   2   3   4   5   6    6   5   4   3   2   1  "<<endl;
   cout<<"------------------------------------------------"<<endl;
   cout<<"12  13  14  15  16  17   18  19  20  21  22  23 "<<endl;
   cout<<"************************************************"<<endl;

}

void dosyaya_yazdirma(){
  ofstream gameFile;
  gameFile.open("tavla.dat");
  gameFile<<"******************GAME BOARD********************"<<endl;
  gameFile<<endl;
  gameFile<<"1   2   3   4   5   6    6   5   4   3   2   1  "<<endl;
  for(int i=11;i>=0;i--){
      if(kirmizi[i]!=0 && beyaz[i]==0){
        gameFile<<kirmizi[i]<<"K  ";
      }

      if(beyaz[i]!=0 && kirmizi[i]==0){
        gameFile<<beyaz[i]<<"B  ";
      }
      else if(beyaz[i]==0 && kirmizi[i]==0){
        gameFile<<"    ";
      }
   }
  gameFile<<endl;
  gameFile<<"                                                "<<endl;
  gameFile<<"                "<<KB<<"KB "<<Z1<<"   "<<Z2<<"  "<<KK<<"KK                "<<endl;
  gameFile<<"                                                "<<endl;

  for(int i=12;i<24;i++){
      if(kirmizi[i]!=0 && beyaz[i]==0){
        gameFile<<kirmizi[i]<<"K  ";
      }

      if(beyaz[i]!=0 && kirmizi[i]==0){
        gameFile<<beyaz[i]<<"B  ";
      }
      else if(beyaz[i]==0 && kirmizi[i]==0){
        gameFile<<"    ";
      }
   }
   gameFile<<endl;
   gameFile<<"1   2   3   4   5   6    6   5   4   3   2   1  "<<endl;
   gameFile<<endl;
   gameFile<<"******************GAME BOARD********************"<<endl;

  gameFile.close();
}

void zar_atma(){
  ofstream zarFile;
  zarFile.open("zar.dat",std::ios_base::app);
  srand(time(NULL));
  Z1=rand() % 6 + 1;
  Z2=rand() % 6 + 1;
  //Atilan zar bilgilerinin zar.dat dosyasina kaydedilmesi
  zarFile<<"Z1:"<<Z1<<endl;
  zarFile<<"Z2:"<<Z2<<endl;
  zarFile<<"--------"<<endl;
  zarFile.close();
}

void kirmiziHamle(){
     cout<<endl;
     cout<<"KIRMIZININ SIRASI"<<endl;
     ekrana_yazdirma();
     int kirmiziyuva1;
     int kirmizizar1;
     if(KK==0){
         cout<<"Oynamak istediginiz yuvayi giriniz."<<endl;
         cin>>kirmiziyuva1;
         cout<<"Oynamak istediginiz zari giriniz."<<endl;
         cin>>kirmizizar1;
         if(0<=kirmiziyuva1 && kirmiziyuva1<24){
            if(kirmizizar1==Z1 || kirmizizar1==Z2){
                if(kirmizi[kirmiziyuva1]!=0){//Gidilecek yuvalanin kontrolü
                   if(kirmizi[kirmiziyuva1+kirmizizar1]>0){//Gidilecek yuvada en az bir tane kirmizi pul var ise
                       kirmizi[kirmiziyuva1]--;
                       kirmizi[kirmiziyuva1+kirmizizar1]++;
                   }
                   else if(kirmizi[kirmiziyuva1+kirmizizar1]==0 && beyaz[kirmiziyuva1+kirmizizar1]==0){//Gidilecek yuva bos ise
                       kirmizi[kirmiziyuva1]--;
                       kirmizi[kirmiziyuva1+kirmizizar1]++;
                   }
                   else if(beyaz[kirmiziyuva1+kirmizizar1]==1){//Gidilecek yuvada bir tane beyaz pul var ise kirma islemi yapilir
                       beyaz[kirmiziyuva1+kirmizizar1]=0;
                       kirmizi[kirmiziyuva1+kirmizizar1]++;
                       kirmizi[kirmiziyuva1]--;
                       KB++;
                   }
                   else if(beyaz[kirmiziyuva1+kirmizizar1]>1){//Gidilecek yuvada birden fazla beyaz pul var ise
                       cout<<"Yuva beyaz ile dolu, gidemezsiniz.Tekrar secim yapiniz."<<endl;
                       kirmiziHamle();
                   }
              }
              else{
              cout<<"Bu yuvada kirmizi pul bulunmamaktir.Hamle yapilamaz.Tekrar secim yapiniz."<<endl;
              kirmiziHamle();
              }
            }
            else{
                cout<<"Böyle bir zar atmadiniz.Tekrar secim yapiniz"<<endl;
                kirmiziHamle();
            }

         }
         else{
            cout<<"Böyle bir yuva bulunmamaktadir.Tekrar secim yapiniz."<<endl;
            kirmiziHamle();
         }

     }
     else{
        cout<<"Yerlestirmek istediginiz yuvayi giriniz."<<endl;
        cin>>kirmiziyuva1;
        cout<<"Kullanmak istediginiz zari giriniz."<<endl;
        cin>>kirmizizar1;
        if(kirmiziyuva1+1==kirmizizar1 && (beyaz[kirmiziyuva1]==0 || kirmizi[kirmiziyuva1]!=0)){
                  if(beyaz[kirmiziyuva1]==0){
                     kirmizi[kirmiziyuva1]=1;
                     KK--;
                  }
                  else if( beyaz[kirmiziyuva1]==1){
                     beyaz[kirmiziyuva1]=0;
                     KB++;
                  }
              }
         else{
            cout<<"Yanlis hamle yaptiniz.Tekrar secim yapiniz."<<endl;
            kirmiziHamle();
         }
     }
   ekrana_yazdirma();
   dosyaya_yazdirma();
   system("cls");

}



void beyazHamle(){
     cout<<endl;
     cout<<"BEYAZIN SIRASI"<<endl;
     ekrana_yazdirma();
     int beyazyuva1;
     int beyazzar1;
     if(KB==0){
         cout<<"Oynamak istediginiz yuvayi giriniz."<<endl;
         cin>>beyazyuva1;
         cout<<"Oynamak istediginiz zari giriniz."<<endl;
         cin>>beyazzar1;
         if(0<=beyazyuva1 && beyazyuva1<24){
            if(beyazzar1==Z1 || beyazzar1==Z2){
                if(beyaz[beyazyuva1]!=0){//Gidilecek yuvanin kontrolu
                     if(beyaz[beyazyuva1-beyazzar1]>0){//Gidilecek yuvada en az bir tane beyaz pul var ise
                       beyaz[beyazyuva1]--;
                       beyaz[beyazyuva1-beyazzar1]++;
                   }
                   else if(beyaz[beyazyuva1-beyazzar1]==0 && kirmizi[beyazyuva1-beyazzar1]==0){//Gidilecek yuva bos ise
                       beyaz[beyazyuva1]--;
                       beyaz[beyazyuva1-beyazzar1]++;
                   }
                   else if(kirmizi[beyazyuva1-beyazzar1]==1){//Gidilecek yuvada bir tane beyaz pul var ise kirma islemi yapilacak
                       kirmizi[beyazyuva1-beyazzar1]=0;
                       beyaz[beyazyuva1-beyazzar1]++;
                       beyaz[beyazyuva1]--;
                       KK++;
                   }
                   else if(kirmizi[beyazyuva1-beyazzar1]>1){//Gidilecek yuvada birden fazla kirmizi var ise
                       cout<<"Yuva kirmizi ile dolu, gidemezsiniz.Tekrar secim yapiniz."<<endl;
                       beyazHamle();
                   }
              }
              else{
              cout<<"Bu yuvada kirmizi pul bulunmamaktir.Hamle yapilamaz.Tekrar secim yapiniz."<<endl;
              beyazHamle();
              }
            }
            else{
                cout<<"Böyle bir zar atmadiniz.Tekrar secim yapiniz"<<endl;
                beyazHamle();
            }

         }
         else{
            cout<<"Böyle bir yuva bulunmamaktadir.Tekrar secim yapiniz."<<endl;
            beyazHamle();
         }

     }
     else{//Kirik yerlestirmesi
        cout<<"Yerlestirmek istediginiz yuvayi giriniz."<<endl;
        cin>>beyazyuva1;
        cout<<"Kullanmak istediginiz zari giriniz."<<endl;
        cin>>beyazzar1;
        if((beyazyuva1-12)==beyazzar1 && (kirmizi[beyazyuva1]==0 || beyaz[beyazyuva1]!=0)){
                  if(kirmizi[beyazyuva1]==0){
                     beyaz[beyazyuva1]=1;
                     KB--;
                  }
                  else if( kirmizi[beyazyuva1]==1){
                     kirmizi[beyazyuva1]=0;
                     KK++;
                  }
              }
         else{
            cout<<"Yanlis hamle yaptiniz.Tekrar secim yapiniz."<<endl;
            beyazHamle();
         }
     }
    ekrana_yazdirma();
    dosyaya_yazdirma();
    system("cls");
}

void kirmiziPullariToplama(){
        cout<<"Kirmizi,Pullari toplamaya baslayabilirsin."<<endl;

        if(kirmizi[Z1+12]!=0){
            kirmizi[Z1+12]--;
        }
        else if(kirmizi[Z2+12]!=0){
            kirmizi[Z2+12]--;
        }

}

void beyazPullariToplama(){
    cout<<"Beyaz, Pullarini toplamaya baslayabilirsin."<<endl;

    if(beyaz[Z1-1]==0){
        beyaz[Z1-1]--;
    }
    else if(beyaz[Z2-1]==0){
        beyaz[Z2-1]--;
    }
}

void dizileriSaklama(){ //Her adimda dizilerdeki eleman sayilarinin diziler.dat dosyasina kaydedilmesi
  ofstream dizileriSakla;
  dizileriSakla.open("diziler.dat");
  for(int i=0;i<24;i++){
    dizileriSakla<<kirmizi[i];
  }
  for(int i=0;i<24;i++){
    dizileriSakla<<beyaz[i];
  }

  dizileriSakla<<KB;
  dizileriSakla<<KK;
}

void eskiOyun(){ //diziler.dat dosyasýndan bilgilerin okunup ilgili dizi ve degiskenlere kaydedilmesi
  ifstream dosyaOku("diziler.dat");
  char karakter;

  if ( dosyaOku.is_open() ){

    while ( dosyaOku.get(karakter) ){
      buffer.push_back(karakter);
    }
    dosyaOku.close();
  }


  for(int i=0;i<24;i++){
    kirmizi[i]=buffer[i]-'0';  //char olarak alinan verinin int'e donusturulmesi ve diziye atanmasi
  }
  for(int i=24;i<48;i++){
    beyaz[i-24]=buffer[i]-'0'; //char olarak alinan verinin int'e donusturulmesi ve diziye atanmasi
  }


  KB=buffer[48]-'0';           //char olarak alinan verinin int'e donusturulmesi ve ilgili degiskene atanmasi
  KK=buffer[49]-'0';           //char olarak alinan verinin int'e donusturulmesi ve ilgili degiskene atanmasi

}

void ilk_atama(int a){
  if(a==0){ //Yeni oyun icin pul dizilimi
  kirmizi[0]=2;
  kirmizi[11]=5;
  kirmizi[16]=3;
  kirmizi[18]=5;

  beyaz[23]=2;
  beyaz[5]=5;
  beyaz[7]=3;
  beyaz[12]=5;

  kirmizi[1]=0;
  kirmizi[2]=0;
  kirmizi[3]=0;
  kirmizi[4]=0;
  kirmizi[5]=0;
  kirmizi[6]=0;
  kirmizi[7]=0;
  kirmizi[8]=0;
  kirmizi[9]=0;
  kirmizi[10]=0;
  kirmizi[12]=0;
  kirmizi[13]=0;
  kirmizi[14]=0;
  kirmizi[15]=0;
  kirmizi[17]=0;
  kirmizi[19]=0;
  kirmizi[20]=0;
  kirmizi[21]=0;
  kirmizi[22]=0;
  kirmizi[23]=0;


  beyaz[0]=0;
  beyaz[1]=0;
  beyaz[2]=0;
  beyaz[3]=0;
  beyaz[4]=0;
  beyaz[6]=0;
  beyaz[8]=0;
  beyaz[9]=0;
  beyaz[10]=0;
  beyaz[11]=0;
  beyaz[13]=0;
  beyaz[14]=0;
  beyaz[15]=0;
  beyaz[16]=0;
  beyaz[17]=0;
  beyaz[18]=0;
  beyaz[19]=0;
  beyaz[20]=0;
  beyaz[21]=0;
  beyaz[22]=0;
  }
  else if(a==1){ //Eski oyun icin pul dizilimi
    eskiOyun();  //Eski oyundan devam edilecek ise
  }
}

void game(){
 while(!(kirmizi[0]==0&&kirmizi[1]==0&&kirmizi[2]==0&&kirmizi[3]==0&&kirmizi[4]==0&&kirmizi[5]==0&&kirmizi[6]==0&&kirmizi[7]==0&&kirmizi[8]==0&&kirmizi[9]==0&&kirmizi[10]==0&&kirmizi[11]==0&&
        kirmizi[12]==0&&kirmizi[13]==0&&kirmizi[14]==0&&kirmizi[15]==0&&kirmizi[16]==0&&kirmizi[17]==0&&kirmizi[18]==0&&kirmizi[19]==0&&kirmizi[20]==0&&kirmizi[21]==0&&kirmizi[22]==0&&kirmizi[23]==0)
        ||
        !(beyaz[0]==0&&beyaz[1]==0&&beyaz[2]==0&&beyaz[3]==0&&beyaz[4]==0&&beyaz[5]==0&&beyaz[6]==0&&beyaz[7]==0&&beyaz[8]==0&&beyaz[9]==0&&beyaz[10]==0&&beyaz[11]==0&&
         beyaz[12]==0&&beyaz[13]==0&&beyaz[14]==0&&beyaz[15]==0&&beyaz[16]==0&&beyaz[17]==0&&beyaz[18]==0&&beyaz[19]==0&&beyaz[20]==0&&beyaz[21]==0&&beyaz[22]==0&&beyaz[23]==0)){


            if(kirmizi[0]==0&&kirmizi[1]==0&&kirmizi[2]==0&&kirmizi[3]==0&&kirmizi[4]==0&&kirmizi[5]==0&&kirmizi[6]==0&&kirmizi[7]==0&&kirmizi[8]==0&&kirmizi[9]==0&&kirmizi[10]==0&&kirmizi[11]==0&&kirmizi[12]==0&&kirmizi[13]==0&&kirmizi[14]==0&&kirmizi[15]==0 &&kirmizi[16]==0&&kirmizi[17]==0 && KK==0){
                  zar_atma();
                  kirmiziPullariToplama();
                  dizileriSaklama();

               }
            else{
                zar_atma();
                int k=2;
                if(Z1==Z2){
                    k=4;
                }
                for(int i=0;i<k;i++){
                kirmiziHamle();
                dizileriSaklama();
                }
            }
            if(beyaz[6]==0&&beyaz[7]==0&&beyaz[8]==0&&beyaz[9]==0&&beyaz[10]==0&&beyaz[11]==0&&beyaz[12]==0
                &&beyaz[13]==0&&beyaz[14]==0&&beyaz[15]==0&&beyaz[16]==0&&beyaz[17]==0&&beyaz[18]==0&&beyaz[19]==0
                &&beyaz[20]==0&&beyaz[21]==0&&beyaz[22]==0&&beyaz[23]==0 &&KB==0){
                   zar_atma();
                   beyazPullariToplama();
                   dizileriSaklama();
            }
            else{
                zar_atma();
                int k=2;
                if(Z1==Z2){
                    k=4;
                }
                for(int i=0;i<k;i++){
                beyazHamle();
                dizileriSaklama();
            }
            }
}
}


















void startGame(){
    int a=0;
    ilk_atama(a);
    game();
}

void continueGame(){
   int a=1;
   ilk_atama(a);
   game();
}




void secim(int s){
  switch (s){
  case 1:
    startGame();
    break;
  case 2:
    cout<<"Yarim kalan oyuna devam edilecek."<<endl;
    continueGame();
    break;
  case 3:
    exit(0);
    break;
    default:
    cout << "Gecersiz karakter, lutfen tekrar secim yapiniz.";
  }
}

void menu(){
  int s;
  cout << "Seciminizi yapiniz:\n"
       << "1. Yeni oyun\n"
       << "2. Eski oyuna devam et\n"
       << "3. Cikis\n"
       << "Your option: ";
  cin >>s;
  secim(s);
}




int main(){
  menu();
  return 0;
}

