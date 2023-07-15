/*
Потребно е да се имплементираат класи File (датотека) и Folder (директориум) за работа со едноставен податочен систем.

Во класата File треба да се чуваат следниве податоци:

Име на датотеката (динамички алоцирана низа од знаци)
Екстензија на датотеката (енумерација со можни вредности: txt, pdf, exe)
Име на сопственикот на датотеката (динамички алоцирана низа од знаци)
Големина на датотеката (цел број на мегабајти)
Дополнително, во класата потребно е да се напишат и:

Конструктор без параметри
Конструктор со параметри
Конструктор за копирање
Деструктор
Преоптоварување на операторот =
Метод за печатење на информациите за една датотека (видете го излезот од тест примерите за структурата на печатење) - print()
Метод за проверка на еднаквост помеѓу две датотеки со потпис bool equals(const File & that) кој ќе враќа true ако датотеките имаат исто име, екстензија и сопственик
Метод за споредба на типот помеѓу две датотеки со потпис bool equalsType(const File & that) кој ќе враќа true ако датотеките се од ист тип, т.е. имаат исто име и екстензија
Во класата Folder треба да се чуваат следниве податоци:

Име на директориумот (динамички алоцирана низа од знаци)
Број на датотеки во него (на почеток директориумот е празен)
Динамички алоцирана низа од датотеки, објекти од класата File
Дополнително, во класата потребно е да се напишат и:

Конструктор со потпис Folder(const char* name)
Деструктор
Метод за печатење на информациите за еден директориум (видете го излезот од тест примерите за структурата на печатење) - print()
Метод за бришење на датотека од директориумот со потпис void remove(const File & file) кој ќе ја избрише првата датотека од директориумот која е еднаква според equals методот
Метод за додавање на датотека во директориумот со потпис void add(const File & file) кој ќе додава датотеката во директориумот
Не го менувајте почетниот код.
*/

#include<iostream>
#include<cstring>

using namespace std;

enum Extension {
    PDF,TXT,EXE
};

class File {
private:
	char* name;
	char* owner;
	int size;
	Extension extension;

	void copy(const File & that) {
		this->name = new char[strlen(that.name) + 1];
		strcpy(this->name, that.name);
		this->owner = new char[strlen(that.owner) + 1];
		strcpy(this->owner, that.owner);
		this->size = that.size;
		this->extension = that.extension;
	}
public:
	File() {
		this->name = new char[0];
		this->owner = new char[0];
		this->size = 0;
	}
	File(const char* name, const char* owner, const int size, const Extension extension) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->owner = new char[strlen(owner) + 1];
		strcpy(this->owner, owner);
		this->size = size;
		this->extension = extension;
	}

	File(const File & that) {
		copy(that);
	}

	File & operator = (const File & that) {
		if (&that != this) {
			delete [] name;
			delete [] owner;
			copy(that);	
		}
		return *this;
	}

	bool equals(const File & that) {
		return equalsType(that)&&strcmp(this->owner, that.owner) == 0;
	}

	bool equalsType(const File & that) {
		return strcmp(this->name, that.name) == 0&&this->extension == that.extension;
	}

	void print() {
        char* ext = "";
        if (extension == 0) ext = "pdf";
        if (extension == 1) ext = "txt";
        if (extension == 2) ext = "exe";
		cout << "File name: " << name << "." << ext << endl;
		cout << "File owner: " << owner << endl;
		cout << "File size: " << size << endl;
	}

	~File() {
		delete [] name;
		delete [] owner;
	}
};

class Folder {
private:
	char* name;
	int numberOfFiles;
	File* files;
public:
	Folder(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->numberOfFiles = 0;
		this->files = 0;
	}

	void add(const File & file) {
		File* tmp = files;
		this->files = new File[numberOfFiles + 1];
		for (int i = 0; i < numberOfFiles; i++)
			files[i] = tmp[i];
		files[numberOfFiles++] = file;
	}


//  void add(const File &f){
        
// //        File* tmp = files;
//         File *temp = new File[br_dat+1];
//         for(int i=0;i<br_dat;i++){
//             temp[i]=files[i];
//         }
//         temp[br_dat++]=f;
//         delete [] files;
//         files=temp;
//     }

	void remove(const File & file) {
		int indexToDelete = -1;
		for (int i = 0; i < numberOfFiles; i++)
			if (files[i].equals(file)) {
				indexToDelete = i;
				break;
			}

		if (indexToDelete != -1) {
			File* tmp = files;
			this->files = new File[numberOfFiles - 1];
			for (int i = 0, j = 0; i < numberOfFiles; i++)
				if (i != indexToDelete)
					files[j++] = tmp[i];
			numberOfFiles--;
		}
	}

	void print() {
		cout << "Folder name: " << name << endl;
		for (int i = 0; i < numberOfFiles; i++)
			files[i].print();
	}

	~Folder() {
		delete [] name;
		delete [] files;
	}
};

int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
		File copied = File(created);
		File assigned = created;

		cout << "======= CREATED =======" << endl;
		created.print();
		cout << endl;
        cout << "======= COPIED =======" << endl;
		copied.print();
		cout << endl;
        cout << "======= ASSIGNED =======" << endl;
		assigned.print();
	}
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;	

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
			cout << "TRUE" << endl;
		else
			cout << "FALSE" << endl;

	}
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}
