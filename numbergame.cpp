#include<iostream>
#include<ctime>
#include<cstdlib>
#include <cstring>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS


int toplamEksi = 0;
int toplamArti = 0;
int EksidenSonrasi = 0;
char UretilenSayi[4];
char KullanicininGirdigiSayi [20];
char sayilar[] = {'0','1','2','3','4','5','6','7','8','9'};


int i, j, arti, eksi, isGameOver, TahminSayisi ,puan;
string kullaniciAdi;

void sayiBelirleme(){
	
    TahminSayisi = 0;
    srand(time(0));
    	
  	 int index;
      

		for(int i =0 ; i < 4 ; i++) {
			
		int x = 1;
		
		
		while(x){
			
			x=0;
			index = rand() %9; 
			UretilenSayi[i] = sayilar[index];
			
				for(int j=0;j<i;j++){					
					if(UretilenSayi[i]==UretilenSayi[j]) x = 1;
					
				}
		}
		
	}
	
}

void karsilastirma(){
	//Tutulan sayý ve girilen sayý karþýlaþtýrýlýyor.
		 arti = 0;
         eksi = 0;
         for ( i = 0; i < 4; i = i + 1) 
            for (j = 0; j < 4; j = j + 1)
               if (KullanicininGirdigiSayi[i] == UretilenSayi[j])
                  if (i == j)
                     arti = arti + 1;
                  else
                     eksi = eksi + 1;
            cout<<" "<<endl;
        	cout<<"+"<< arti<<"......." << "-"<<  eksi  <<"       "<< arti << 
		 	" sayi bildiniz yeri dogru, " << eksi << " sayi bildiniz yeri yanlis..." <<endl;
		 	cout<<" "<<endl;
		 	toplamEksi = eksi + toplamEksi;
	 		toplamArti = arti + toplamArti;
}

void puanHesap(int hak){
	
	int EksidenSonrasi = (toplamArti*toplamEksi)/(toplamArti+toplamEksi);
	puan = ((10*toplamArti)+(5*toplamEksi)+(1000/hak))-EksidenSonrasi;

	cout<<puan<<endl;
	
}


int main() {
	
      //RAKAMLARI FARKLI 4 BASAMAKLI BÝR SAYI ÜRETÝYOR
      sayiBelirleme();
      
      
      cout<<"4 BASAMAKLI BILMECE OYUNUNA HOSGELDIN "<<endl;
      cout <<"KURALLAR \n 1-) 4 Basamaklý Rakamlarý Farklý Bir Sayi Giriniz... \n 2-) Pozitif Bir Sayi Giriniz..."<<endl;
      cout<<"OYUNA BASLAYABILIRSIN \n   "<<endl;
      
      isGameOver = 0;
      TahminSayisi = 0; 
      	int x=1;
      	int sayac=0;
      	int kontrol=0;


       while(isGameOver == 0 ){
       		do{	
			cout <<"DOGRU SAYIYA ULASMAK ICIN "<< 10-TahminSayisi <<" HAKKIN VAR"<<endl;
      		cin >> KullanicininGirdigiSayi;
      						
      						
      				for(i=0,sayac=0;KullanicininGirdigiSayi[i]!='\0';i++,sayac++);
			
      				//Kullanicinin girdiði sayida harf olup olmadýðýný denetliyor.     				
					  	kontrol = 0;
        				for(i = 0;i<sayac;i++){
        					for(j = 0;j<10;j++){
								if(KullanicininGirdigiSayi[i] == sayilar[j]){
        						kontrol++;
        						} 
							}
					    }
					
				
              		if(kontrol!=sayac ) {
            			cout << " Lutfen Pozitif Bir Sayi Giriniz" << endl;
							
					}else if(sayac!=4) {
								cout << "Lutfen 4 basamakalý sayi giriniz." << endl;
								continue;
					}
					
					//girilen sayinin rakamlari farkli mi testi
        			if(sayac==4){
        				
						x=1;
        				for(i = 0;i<4;i++){
        					for(j = i+1;j<4;j++){
        						if(KullanicininGirdigiSayi[i] == KullanicininGirdigiSayi[j]){
        						x=0;
        						break;
        						
								} 
							}
						}
					}
									
		}while(x==0 || sayac!=4 || kontrol != 4);
		
		TahminSayisi = TahminSayisi + 1;
	   	karsilastirma();

         //KULLANICI 10 HAKKINI KULLANDIÐINDA PROGRAM DURUYOR
		 if(TahminSayisi == 10 && arti != 4){
         	isGameOver = 1;
         	cout << "10 Hakkýn vardý , bilemedin ..." ;
         	
		 }
         if (arti == 4) {
         	isGameOver = 1;
            puanHesap(TahminSayisi);
            cout<<TahminSayisi<< ".adimda bildiniz."<<"TEBRÝKLER"<<endl;
            cout << "Lütfen Kullanýcý Adýnýzý Giriniz." << endl;
            cin >> kullaniciAdi;
			cout << kullaniciAdi << " kullanicisi  bu oyundan " << puan << " puan aldý...\n TEBRÝKLEEEEEER"<<endl;    			      
  		 }
}
}


