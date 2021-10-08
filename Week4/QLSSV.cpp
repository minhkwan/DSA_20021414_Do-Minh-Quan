#include <iostream>
using namespace std;

struct Student {
	int ID;
	string Name, Class;
	Student() {
		ID = -1;
	}
	Student(int _ID, string _Name, string _Class) {
		ID = _ID;
		Name = _Name;
		Class = _Class;
	}
	void Delete() {
		ID = -1;
		Name = "";
		Class = "";
	}
};

struct StudentManagement {
	Student s[100];
	void Insert(int ID, string Name, string Class) {
		int index = ID % 100;
		while (s[index].ID != -1) {
			index = (index + 1) % 100;
		}
		Student newStu(ID, Name, Class);
		s[index] = newStu;
	}

	int search(int ID) {
		int index = ID % 100;
		while (s[index].ID != ID && s[index].ID != -1)
			index = (index + 1) % 100;
		if (s[index].ID == ID)
			return index;
		return -1;
	}

	void Delete(int ID) {
		int index = search(ID);
		if (index != -1) {
			s[index].Delete();
		}
	}

	void Infor(int ID) {
		int index = search(ID);
		if (index != -1) {
			cout << s[index].Name << "," << s[index].Class << endl;
		}
		else {
			cout << "NA,NA\n";
		}
	}
};

int main(){
    StudentManagement a;
    string s;
    while(cin >> s){
    //Lay chi so de phan biet lenh Insert, Delete, Infor.
    int index = s.find("(");

    //Lay ra ID.
    int index1 = s.find("(");
    int index2 = s.find(",");
    int ID = stoi(s.substr(index1+1,index2 - index1 - 1));

    //Lay ra Name.
    index1 = index2;
    index2 = s.find(",",index1+1);
    string Name = s.substr(index1 + 1,index2 - index1 - 1);

    //Lay ra Class.
    index1 = index2;
    index2 = s.find(")",index1+1);
    string Class = s.substr(index1+1, index2 - index1 - 1);

    if(s.substr(0, index) == "Insert"){
    a.Insert(ID, Name, Class);
    }
    else if(s.substr(0, index) == "Delete"){
            a.Delete(ID);
    }
    else if(s.substr(0, index) == "Infor"){
        a.Infor(ID);
    }
}





}







