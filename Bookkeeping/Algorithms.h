#pragma once
#include "Header.h"

template<typename T>
inline void fromTxtFileInRing(MyRing<T>& ring, string fName) {
	T tmp;
	TextFile<T> file(fName);
	if (file.openToOutput()) {
		while (true)
		{
			file.outputToFile(tmp);
			if (file.endFile())
				break;
			ring.pushToBack(tmp);

		}
	}
}

template<typename T>
inline void fromBinFileInVector(vector<T>& vect, string fName) {
	T tmp;
	BinaryFile<T> accsFile(fName);
	if (accsFile.openToOutput()) {
		while (true)
		{
			accsFile.outputToFile(tmp);
			if (accsFile.endFile())
				break;
			vect.push_back(tmp);

		}
	}
}

template<typename T>
inline void fromTextFileInVector(vector<T>& vect, string fName) {
	T tmp;
	TextFile<T> accsFile(fName);
	if (accsFile.openToOutput()) {
		while (true)
		{
			accsFile.outputToFile(tmp);
			if (accsFile.endFile())
				break;
			vect.push_back(tmp);

		}
	}
}

template<typename T>
inline void objAddInTxtFile(T& obj, string fName) {
	TextFile<T> newAcc(fName);
	if (newAcc.openToAdd()) {
		newAcc.inputToFile(obj);
	}
}

template<typename T>
inline T objAddInBinFile(T& obj, string fName) {
	BinaryFile<T> newAcc(fName);
	if (newAcc.openToAdd()) {
		newAcc.inputToFile(obj);
	}
}

template<typename T>
inline void ringAddInTxtFile(MyRing<T>& obj, string fName) {
	Iterator<T> begin = obj.Begin();
	Iterator<T> tmp = begin;
	TextFile<T> newAcc(fName);
	if (obj.getSize() == -1) {
		newAcc.openToInput();
	}
	else {
		if (newAcc.openToInput()) {
			do {
				newAcc.inputToFile(tmp.curr->data);
				++tmp;
			} while (tmp != obj.Begin());
		}
		
	}
}


template<typename T>
inline void ringAddInBinFile(MyRing<T>& obj, string fName) {
	Iterator<T> begin = obj.Begin();
	Iterator<T> tmp = begin;
	BinaryFile<T> newAcc(fName);
	if (obj.getSize() == -1) {
		newAcc.openToInput();
	}
	else{
		if (newAcc.openToInput()) {
			do {
				newAcc.inputToFile(tmp.curr->data);
				++tmp;
			} while (tmp != obj.Begin());
		}
	}
}


template<typename T>
inline void vectorAddInTxtFile(vector<T>& obj, string fName) {
	TextFile<T> newAcc(fName);
	if (obj.empty()) {
		newAcc.openToInput();
	}
	else {
		for (int i = 0; i < obj.size(); i++) {
			
			if (newAcc.openToInput()) {
				newAcc.inputToFile(obj[i]);
			}
		}
	}
}


template<typename T>
inline void vectorAddInBinFile(vector<T>& obj, string fName) {
	BinaryFile<T> newAcc(fName);
	for (int i = 0; i < obj.size(); i++) {
		
		if (newAcc.openToInput()) {
			newAcc.inputToFile(obj[i]);
		}
	}
	if (obj.empty()) {
		newAcc.openToInput();
	}
}

template <typename T> 
inline MyRing<T> printObligatory(MyRing<T>& ring) {
	Iterator<T> help(ring.Begin());
	MyRing<T> newRing;
	Date pattern(0,0,0);
	if (help == NULL || ring.getSize() == -1) {
		return newRing;
	}
	else {
		int i;
		for (i = 0; i < ring.getSize() + 1; i++) {
			if ((*help).getPeriod() != pattern) {
				newRing.pushToBack(*help);
			}
			++help;
		}
	}
	return newRing;
}

//Выполнение периодических транакций
template<typename T>
inline bool toCompleteTransactions(MyRing<T>& allTrans, Account& acc) {

	//Переодические транзакции
	MyRing<T> perTrans;
	perTrans = printObligatory(allTrans);

	//Дата на сегоднешний день
	time_t Time = time(NULL);
	tm LocalDate;
	localtime_s(&LocalDate, &Time);
	Date today(LocalDate.tm_mday, LocalDate.tm_mon + 1, LocalDate.tm_year + 1900), noDate(0,0,0);

	//Итераторы для кольца с периодическими транзкциями и для всех транзакций
	Iterator<T> help(perTrans.Begin()), forAllTrans(allTrans.Begin());
	

	if (help == NULL || perTrans.getSize() == -1) {
		return false;
	}
	else {
		//Цикл по переодическим транзаакциям
		for (int i = 0; i < perTrans.getSize() + 1; i++) {
			T tmp;
			tmp = *help;
			tmp.setPeriod(noDate);
			
			//Если транзакция достигла даты
			while ((*help).getPeriod() + tmp.getDate() <= today) {
				allTrans.pushToFront(tmp);
				
				if (!(allTrans.Begin()->data.procBankAcc(acc))) return false; //Вычет из счета
				tmp.setDate(tmp.getDate() + (*help).getPeriod());

					do {
						++forAllTrans;
					} while (forAllTrans != allTrans.Begin() && (!(*help).equal(*forAllTrans)));

			(*forAllTrans).setDate((*help).getPeriod() + (*help).getDate());
			}

			++help;
		}
	}
	return true;
}

template <typename T>
inline void printNotObligatory(MyRing<T>& ring) {
	Iterator<T> help(ring.Begin());
	Date pattern();
	if (help == NULL || ring.getSize() == -1) {
		cout << "Empty" << endl;
	}
	else {
		int i;
		for (i = 0; i < ring.getSize() + 1; i++) {
			if ((*help).getPeriod() == pattern) {
			cout << *help<< endl;				
			}
			++help;
			
		}
		if (i == 0) cout << "Empty" << endl;
	}
}

template <typename T>
inline void printNotObligatoryCount(MyRing<T>& ring, int size) {
	Iterator<T> help(ring.Begin());
	Date pattern(0,0,0);
	if (help == NULL || ring.getSize() == -1) {
		cout << "Empty" << endl;
	}
	else {

		int i = 0;
		if (ring.getSize() > size) {
			for (i = 0; i < size; i++) {
				if ((*help).getPeriod() == pattern) {
					cout << (*help) << endl;
				}
				++help;
			}
		}
		else {
			for (i = 0; i < ring.getSize() + 1; i++) {
				if ((*help).getPeriod() == pattern) {
					cout << (*help) << endl;
				}
				++help;
			}
		}

		if (i == 0) cout << "Empty" << endl;
	}
}


template<typename T>
inline void sortAscendingRing(Iterator<T> begin, int size)
{
	//Iterator<T> begin = ring.Begin();
	Iterator<T> curr = begin, next = begin;
	++next;
	T chen;

	for (int i = 0; i < size; i++) {
		curr = begin; next = begin; ++next;
		do {
			if (*curr < *next)
			{
				chen = *curr;
				*curr = *next;
				*next = chen;

				++curr;
				++next;
			}
			else {
				++curr;
				++next;
			}
		} while (next != begin.curr);
	}
}

template<typename T>
inline void sortDescendingRing(Iterator<T> begin, int size)
{
	//Iterator<T> begin = ring.Begin();
	Iterator<T> curr = begin, next = begin;
	++next;
	T chen;

	for (int i = 0; i < size; i++) {
		curr = begin; next = begin; ++next;
		do {
			if (*curr > *next)
			{
				chen = *curr;
				*curr = *next;
				*next = chen;

				++curr;
				++next;
			}
			else {
				++curr;
				++next;
			}
		} while (next != begin.curr);
	}
}

template <typename T>
inline void printFromTo(MyRing<T>& ring) {
	
	Date dateFrom;
	Date dateTo;

	do {
		cout << "Date from: ";
		cin >> dateFrom;
		cout << endl << "Date to: ";
		cin >> dateTo;
	} while (dateFrom >= dateTo);

	cout << "Your transactions from " << dateFrom << "to " << dateTo << endl;
	Iterator<T> help(ring.Begin());
	if (help == NULL || ring.getSize() == -1) {
		cout << "Empty" << endl;
	}
	else {
		for (int i = 0; i < ring.getSize() + 1; i++) {
			if (help.curr->data.getDate() >= dateFrom && help.curr->data.getDate() <= dateTo) {
				cout << help.curr->data << endl;
				
			}
			++help;
		}
	}
}

template <typename T>
inline MyRing<T> transactionsFromTo(MyRing<T>& ring) {
	Date dateFrom;
	Date dateTo;

	do {
		cout << "Date from: ";
		cin >> dateFrom;
		cout << endl << "Date to: ";
		cin >> dateTo;
	} while (dateFrom >= dateTo);
	
	MyRing<T> newRing;
	Iterator<T> help(ring.Begin());
	if (help == NULL || ring.getSize() == -1) {
		return newRing;
	}
	else {
		for (int i = 0; i < ring.getSize() + 1; i++) {
			if ((*help).getDate() >= dateFrom && (*help).getDate() <= dateTo) {
				
				newRing.pushToBack(*help);


			}
			++help;
		}
	}
	return newRing;
}