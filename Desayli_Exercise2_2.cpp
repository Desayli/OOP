#include <iostream>
#include <stdlib.h>
using namespace std;


class Tol{
	private:
    	int mobil;
    	double uang;
    
    public:
  		Tol(){
			mobil = 0;
			uang = 0;
    	}
    	
		void bayar(){
        	mobil = mobil + 1;
        	uang = uang + 0.50;
    	}
    
		void tidakbayar(){
        	mobil = mobil + 1;
    	}
    
		void displayUang()
    	{
        	cout << "Total uang di Gerbang Tol = $ " << uang << endl << endl;
    	}
    
		void displayMobil()
    	{
        	cout << "Total mobil yang lewat Gerbang Tol = " << mobil << " unit" << endl;
    	}
    	
    	void displayThx()
    	{
    		cout << "\nTerima kasih sudah menggunakan program ini" << endl;
		}
};
 
int main()
{
    int pilihan;
    Tol pengguna;
	
	do{
		cout << "1. Mobil berbayar\n2. Mobil tidak berbayar\n3. Exit\nPilihan : "; cin >> pilihan;
		system("cls");
		switch (pilihan){
   			case 1:
    			pengguna.bayar();
        		pengguna.displayMobil();
        		pengguna.displayUang();
        		break;
    		case 2:
    			pengguna.tidakbayar();
    		    pengguna.displayMobil();
    		    pengguna.displayUang();
    		    break;
    		case 3:
    			pengguna.displayMobil();
    			pengguna.displayUang();
    			pengguna.displayThx();
		};
	}while(pilihan!=3);
	
	return 0;
}
