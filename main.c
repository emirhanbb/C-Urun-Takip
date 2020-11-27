#include <stdio.h>

int main()
{
	int boyut = 10;
	int secim;
	int urunid[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int adet[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int birimfiyat[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	
  	int urunidTemp;
	int adetTemp;
	int birimfiyatTemp;
	float zam;
	float indirim;
	
	while(1){
		
		printf("1- Urun Girisi \n2- Urun Sil\n3- Zam Yap\n4- Indirim Yap\n5- Satis Yap\n");
		scanf("%d", &secim);
		
		 switch(secim)
    {
        case 1:
			        	  
			            printf("1- Urun Girisi\n\n");
			            printf("Sirasi ile Urun Id, Adet, Birim Fiyat Giriniz: ");
			            scanf("%d %d %d",&urunidTemp, &adetTemp, &birimfiyatTemp);
			            
			            int durum = 0;
			            int i;
			            for(i=0;i<boyut;i++){
			            	if(urunid[i] == urunidTemp){
			            		adet[i] = adet[i] + adetTemp;
			            		birimfiyat[i] = birimfiyatTemp;
			            		durum = 1;
							}
						}
			            
			            if(durum == 0){
			            	int i;
			            	int kontrol = 0;
			            	for(i = 0; i<boyut;i++){
			            		if(urunid[i] == -1){
			            			urunid[i] = urunidTemp;
			            			adet[i]= adetTemp;
			            			birimfiyat[i] = birimfiyatTemp;
			            			kontrol = 1;
									break;
								}
							}
							if(kontrol == 0){
								printf("\n10 urunden fazla giris yapilamamaktadir!\n");
								break;
							}
						}
						
						  
						urunListele(urunid, adet, birimfiyat);
			            
            
            break;

        case 2:
    
				            printf("2- Urun Sil\n");
				        	printf("Silinecek urunun id'sini giriniz: ");
				        	int urunsil;
				        	int silinecekUrunIndex;
				    		scanf("%d", &urunsil);
				    		
				    		int a;
				    		for(a= 0; a<boyut;a++){
				    			if(urunid[a] == urunsil){
				    				silinecekUrunIndex = a;
								}
							}
							
							    if(silinecekUrunIndex < 0 || silinecekUrunIndex > boyut)
				    {
				        printf("Lutfen gecerli bir index giriniz!");
				    }
				    else
				    {	int i;
				        for(i=silinecekUrunIndex-1; i<boyut-1; i++)
				        {
				            urunid[i] = urunid[i + 1];
				            adet[i] = adet[i + 1];
				            birimfiyat[i] = birimfiyat[i + 1];
				        }
				
							urunListele(urunid, adet, birimfiyat);
				
				       
				    }

		
            break;

        case 3:
				      printf("3- Zam Yap\n");
				      printf("Lutfen urunid ve zam yuzdesini giriniz:");
				      scanf("%d %f", &urunidTemp, &zam);
				      int c;
				      int index;
				        int durum1 = 0;
				    		for(c= 0; c<boyut;c++){
				    			if(urunid[c] == urunidTemp){
				    				index = c;
				    				durum1=1;
								}
							}
				      
				      if(durum1 == 0){
								printf("Girdiginiz Id'de urun bulunmamaktadir!!! \n \n'");
								break;
							} 
				      
				      birimfiyat[index] = birimfiyat[index] + (birimfiyat[index]*zam)/100;
				      printf("Zamli fiyat eklenmistir!\n");
				      urunListele(urunid, adet, birimfiyat);

      
            break;

        case 4:
	        	
	        			printf("4- Indirim Yap\n");
					      printf("Lutfen urunid ve indirim yuzdesini giriniz:");
					      scanf("%d %f", &urunidTemp, &indirim);
					      int e;
					      int index2;
					      int durum2 = 0;
					    		for(e= 0; e<boyut;e++){
					    			if(urunid[e] == urunidTemp){
					    				index2 = e;
					    				durum2 = 1;
									}
								}
								
								if(durum2 == 0){
									printf("Girdiginiz Id'de urun bulunmamaktadir!!! \n \n'");
									break;
								} 
					      
					      birimfiyat[index2] = birimfiyat[index2] - (birimfiyat[index2]*indirim)/100;
					      printf("Indirimli fiyat eklenmistir!\n");
					      urunListele(urunid, adet, birimfiyat);
         
            break;
            
        case 5:
			            printf("5- Satis Yap\n");
			        	printf("Lutfen urunid ve adet giriniz:");
						scanf("%d %d", &urunidTemp, &adetTemp);
						int t;
						int durum3 = 0;
			 			int index3;
						for(t= 0; t<boyut;t++){
							    			if(urunid[t] == urunidTemp){
							    				index3 = t;
							    				durum3 = 1;
											}
										}
						
			           if(durum3 == 0){
											printf("Girdiginiz Id'de urun bulunmamaktadir!!! \n \n'");
											break;
										} 
										
							int cikar=adet[index3] - adetTemp;	
						if(cikar > 0){
							adet[index3] = cikar;
							printf("%d Adet Urun Satilmistir\n",adetTemp);
							urunListele(urunid, adet, birimfiyat);
						} 
						if(cikar == 0){
							adet[index3] = cikar;
							int n;
							printf("%d Adet Urun Satilmistir\n",adetTemp);
				        	for(n=index3-1; n<boyut-1; n++)
				        	{
				            urunid[n] = urunid[n + 1];
				            adet[n] = adet[n + 1];
				            birimfiyat[n] = birimfiyat[n + 1];
				       		 }
				
							urunListele(urunid, adet, birimfiyat);
				
						}
						
						if(cikar<0){
							printf("Yeterli adet bulunmamaktadir!!!");
						}
            break;
            
        case -1:
        	
        	urunListele(urunid, adet, birimfiyat);
            return 0;
            break;

        default:
            printf("Lutfen gecerli bir sayi giriniz");
    }
	}

    return 0;
}


int urunListele(int urunid[], int adet[], int birimfiyat[]){
		printf("id\tadet\tfiyat\n");
		int i;
			for(i=0;i<10;i++){
           		if(urunid[i] != -1){
				printf("%d\t",urunid[i]);
				printf("%d\t",adet[i]);
				printf("%d\n",birimfiyat[i]); }
	
}}

