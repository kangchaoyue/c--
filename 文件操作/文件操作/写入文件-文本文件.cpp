#include<fstream>
using namespace std;
int main1()

{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "ni hao kcy" << endl;
	ofs << "ni hao kcy" << endl;
	ofs << "ni hao kcy" << endl;
	ofs.close();
	return 0;
}
