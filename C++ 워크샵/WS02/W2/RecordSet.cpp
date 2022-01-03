#include <cstring>
#include <iomanip>
#include "RecordSet.h"

using namespace std;
namespace sdds {

	RecordSet::RecordSet() {

		record = nullptr;
		num = 0;

	}

	RecordSet::RecordSet(const string& File_name) {

		string buff;
		ifstream file(File_name.c_str());
		int i = 0;

		while (!file.eof()) {
			getline(file, buff, ' ');
			i++;
		}

		record = new string[i + 1];
		buff = {};
		file.close();
		file.open(File_name);

		i = 0;

		while (getline(file, buff, ' ')) {
			record[i] = buff;
			i++;
		}
		num = i;

	}

	RecordSet::RecordSet(const RecordSet& copy) {
		*this = copy;
	}

	RecordSet::RecordSet(RecordSet&& copy) {
		*this = move(copy);
	}


	RecordSet& RecordSet::operator=(const RecordSet& copy) {

		num = copy.num;
		record = new string[num];

		for (unsigned int i = 0; i < num; i++) {

			record[i] = copy.record[i];

		}

		return *this;
	}

	RecordSet& RecordSet::operator=(RecordSet&& copy) {

		if (this != &copy) {

			num = copy.num;
			record = copy.record;

			copy.num = 0;
			copy.record = nullptr;

		}
		return *this;
	}



	RecordSet::~RecordSet() {

		delete[] record;
		record = nullptr;

	}
	size_t RecordSet::size() const {
		return num;
	}
	string RecordSet::getRecord(size_t index) {

		if (record != nullptr) {
			return string(record[index]);
		}
		else {
			return "";
		}
	}

}