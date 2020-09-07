#include<iostream>
#include<string>
#include<fstream>

using namespace std;


class LogToFile {

private:
	string filePath;

	LogToFile() : filePath("Messages.txt") {}
	LogToFile& operator=(LogToFile&) = delete;
	LogToFile(const LogToFile&) = delete;

public:

	static LogToFile& GetInstance() {
		static LogToFile instance;
		return instance;
	}

	void SetFilePath(string fp) {
		filePath = fp;
	}

	void SaveMessage(string msg) {

		ofstream fout;
		fout.open(filePath, fstream::app);

		if (bool isOpen = fout.is_open()) {

			fout << msg << endl;			
		}
		else {
			throw exception("Error! Unable to open file \n");
		}

		fout.close();
	}

	void ReadMessage()
	{
		ifstream fin;
		fin.open(filePath);
		string temp;

		if (bool isOpen = fin.is_open()) {

			while (!fin.eof()) {

				getline(fin, temp);				
				if (temp != "")
					cout << temp << endl;
				else
					break;				
			}
		}
		else {
			throw exception("Error! Unable to open file \n");
		}

		fin.close();
	}

};

int main() {

	LogToFile& single = LogToFile::GetInstance();

	try
	{
		single.SaveMessage("Hello dear");
		single.SaveMessage("Bob");

		LogToFile::GetInstance().ReadMessage();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}	

	system("pause");
	return 0;
}