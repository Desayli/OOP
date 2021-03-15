#include <iostream>

using namespace std;

class Andre{
	private:
		int nilai_ass, nilai_quiz, nilai_atd, nilai_mid, nilai_final, nilai_total;
		string huruf;
		
	public:	
		void proses(int ass, int quiz, int atd, int mid, int final);
		void display(int tampilan);
		void prosesAkhir();
};

void Andre::proses(int ass, int quiz, int atd, int mid, int final)
{
	nilai_ass 	= (ass*20)/100;
	nilai_quiz	= (quiz*10)/100;
	nilai_atd	= (atd*10)/100;
	nilai_mid	= (mid*30)/100;
	nilai_final = (final*30)/100;
}


void Andre::prosesAkhir()
{
	nilai_total = nilai_ass + nilai_atd + nilai_quiz + nilai_mid + nilai_final;

	if (nilai_total >= 91 && nilai_total <=100)
	{
		huruf = "A";
	}
	else if (nilai_total >= 85 && nilai_total <= 90)
	{
		huruf = "A-";
	}
	else if (nilai_total >= 82 && nilai_total <= 84)
	{
		huruf = "B+";
	}
	else if (nilai_total >= 78 && nilai_total <= 81)
	{
		huruf = "B";
	}
	else if (nilai_total >= 75 && nilai_total <= 77)
	{
		huruf = "B-";
	}
	else if (nilai_total >= 70 && nilai_total <= 74)
	{
		huruf = "C+";
	}
	else if (nilai_total >= 67 && nilai_total <= 69)
	{
		huruf = "C";
	}
	else if (nilai_total >= 60 && nilai_total <= 66)
	{
		huruf = "C-";
	}
	else if (nilai_total >= 40 && nilai_total <= 59)
	{
		huruf = "D";
	}
	else if (nilai_total >= 0  && nilai_total <= 39)
	{
		huruf = "F";
	}
}

void Andre::display(int tampilan)
{
	cout << "|    " << tampilan << "\t\t" << nilai_total << "(" << huruf << ")\t|" << endl;
}

int main()
{
	int jumlah, input_assignment, input_quiz, input_attendance, input_midExam, input_finalExam;
			
	cout << " GRADING SYSTEM V1.0" << endl;
	cout << "=====================" << endl;
	cout << "Jumlah Mahasiswa : "; cin >> jumlah;
		
	Andre mahasiswa[jumlah+1];

	for(int i=0; i<jumlah; i++) {
		cout << endl << "Masukan Nilai Mahasiswa " << i+1 << endl;
		cout << "Assignment\t:"; 	cin >> input_assignment;
		cout << "Quiz\t\t:"; 		cin >> input_quiz;
		cout << "Attendance\t:"; 	cin >> input_attendance;
		cout << "Mid Exam\t:"; 		cin >> input_midExam;
		cout << "Final Exam\t:"; 	cin >> input_finalExam;
		mahasiswa[i].proses(input_assignment, input_quiz, input_attendance, input_midExam, input_finalExam);	
		mahasiswa[i].prosesAkhir();
	}
	

	
	cout << endl << "|=======================|" << endl;
	cout << "|     Student Grade     |" << endl;
	cout << "|=======================|" << endl;
	cout << "|Mahasiswa\tGrade   |" << endl;
	cout << "|-----------------------|" << endl;
	
	for(int j=0; j<jumlah; j++){
		mahasiswa[j].display(j+1);
	}
	
	cout << "|=======================|" << endl;
	
	return 0;
}
