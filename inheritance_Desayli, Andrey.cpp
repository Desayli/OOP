#include <iostream>

using namespace std;

class Person{
	protected:
		string name;
		char gender;
		
	public:
		Person(){
		};
		
		void setName(string n){
			name = n;
		}
		
		void setGender(char jk){
			gender =  jk;
		}
		
		string getName(){
			return name;
		}
		
		char getGender(){
			return gender;
		}
};

class Teacher : public Person{
	private:
		int nik;
		string faculty;
	
	public:
		void setNik(int setnik){
			nik = setnik;
		}
		
		void setFaculty(string setfac){
			faculty = setfac;
		}
		
		int getNik(){
			return nik;
		}
		
		string getFaculty(){
			return faculty;
		}
		
		void setData(){
		}
		
		displayData(){
		}
};

class Student : public Person{
	private:
		int nim;
		string registration_number;
		string prodi;
	
	public:
		void setNim(int setnim){
			nim = setnim;
		}
		
		void setRegistraionNumber(string setNoReg){
			registration_number = setNoReg;
		}
		
		void setProdi(string setprodi){
			prodi = setprodi;
		}
		
		int getNim(){
			return nim;
		}
		
		string getRegistrationNumber(){
			return registration_number;
		}
		
		string getProdi(){
			return prodi;
		}
};

int main(){
	return 0;
}
