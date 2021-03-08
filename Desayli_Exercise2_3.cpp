#include <iostream>
using namespace std;
 
class Waktu{
	private:
	    int jam;
	    int menit;
	    int detik;
 
	public:
		Waktu(){
			this->jam = 0;
			this->menit = 0;
			this->detik = 0;
		}
		
		Waktu(int j,int m,int d){
			this->jam = j;
			this->menit = m;
			this->detik = d;
		}
		
   		void inputWaktu(int a){
   			int k = a;
			
			cout << "= Masukan Waktu ke-" << a << " =" <<endl;
    		cout << "Jam   : "; cin >> jam;
    		cout << "Menit : "; cin >> menit;
    		cout << "Detik : "; cin >> detik;
    		cout << endl;
		};
   		
		void result(){
  			cout << "=====================================" << endl << endl << "Waktu setelah di tambahkan : ";
   			cout << jam << ":" << menit << ":" << detik << endl;
		};
		   
    	void proses(Waktu pertama,Waktu kedua){
   	 	    this->detik = pertama.detik + kedua.detik;
    		this->menit = pertama.menit + kedua.menit + (this->detik/60);
  			this->jam   = pertama.jam + kedua.jam + (this->menit/60);
    		this->menit %= 60;
    		this->detik %= 60;	
		};
};
 
 
int main()
{
	int a;
    Waktu pertama, kedua, ketiga;
    a=1;
	pertama.inputWaktu(a);
	a=2;
    kedua.inputWaktu(a);
    
    ketiga.proses(pertama,kedua);
    ketiga.result();
     
    return 0;
}
