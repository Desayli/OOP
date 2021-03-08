#include <iostream>
using namespace std;

class Employee{
	private:
		int employeeNumber;
		float employeeCompensation;
	
	public:
		Employee(){
			employeeNumber = 0;
			employeeCompensation = 0;
		}
		
		void input_no(int number){
			employeeNumber = number;
		}
		
		void input_kom(float compensation){
			employeeCompensation = compensation;
		}
		
		void display(){
			cout << "Nomor Pegawai : " << employeeNumber << endl;
			cout << "Kompensasi Pegawai : Rp." << employeeCompensation << endl;
		}
};

int main(){
	int nomor;
	float kompensasi;
	
	Employee info[5];
	
	for(int i=1; i<=3; i++){
		cout << "Masukan Nomor Pegawai : "; cin >> nomor;
		info[i].input_no(nomor);
		cout << "Masukan Kompensasi Pegawai : Rp."; cin >> kompensasi;
		info[i].input_kom(kompensasi);
	}
	
	cout << endl << "=============================" << endl;
	
	for(int j=1;j<=3; j++){
		info[j].display();
		cout << endl;
	}
	
	return 0;
}
