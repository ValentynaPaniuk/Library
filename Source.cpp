# include <iostream>
# include <string>
# include <fstream>
# include <iomanip>
# include <stdlib.h>
# include <conio.h>


using namespace std;
int  SIZE = 7; //Кількість книжок у файлі
int  numberClientsFromFile = 4;

/*3. Предметна область - бібліотека.
Розв'язувані задачі: видача довідок про наявність книг, журналів, газет.
Реалізувати наступні сервіси:
/////////1.Заповнення бази даних
/////////2.Перегляд даних про всі джерела
/////////3. Доповнення бази даних записом джерела
/////////4. Видалення джерела із бази даних
////////5. Упорядкування по полях : тип інформаційного джерела(книга, журнал, газета) і назва
////////6. Пошук : наявність заданої книги(відомі автор і назва), наявність заданого журналу
////////7. Вибірка : книги автора ХХ;
////////8. Вибірка : книги певної категорії(фантастика, детектив тощо),
////////9. Вибірка : журнали за певний рік(відомі рік і назва журналу)
////////10. Обчислення: кількість книг деякої категорії
////////11. Корекція : видалення зведень про газети за певний рік
12. Табличний звіт : список боржників книг певного автора
	Для обробки даних скористатися динамічним масивом покажчиків на структури відповідного типу.
*/


/// BOOK///////////////////////////////////////////////////
struct cardBook
{

	string kindBook;
	string title;
	string author;
	string description;
	int idCardBook = 0;
	int pages;
	int yearOfPublication;
	int dateBookReceivedLibrary;
	bool statusOfBook = false; // Якщо книга в бібліотеці
	void ShowInfoCardBook()
	{
		cout << "\t----------------------------------------" << endl;
		cout << idCardBook<<" "<<kindBook << " :\t" << title << "\n\tAUTHOR:\t\t" << author << "\n\tPAGES:\t\t" << pages << "\n\tYEAR OF PUBLICATION:\t\t" << yearOfPublication << "\n\tDATE BOOK RECEIVED OF THE LIBRARY:\t\t" << dateBookReceivedLibrary << "\n\tDESCRIPTION:\t\t" << description << endl;
		cout << "\tSTATUS OF BOOK (0 - in the library, 1- in the client) =\t"<< statusOfBook << endl;
		cout << "\t----------------------------------------" << endl;
	}
};

//2. Перегляд даних про книги
void ShowInfoCardBook(cardBook *&cardBooks, int &SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cardBooks[i].ShowInfoCardBook();
	}
}


// 1. Читання бази даних із файлу
void FillCollectionFromFile(cardBook *&cardBooks) //11.Enter books from File\n";
{

	string path = "db.txt";
	ifstream readFile;
	readFile.open(path);
	if (!readFile.is_open())
	{
		cout << "Can't open file " << endl;
	}
	else
	{
		cout << "======= COLLECTION OF LIBRARY BOOKS =========" << endl;
		
		char temp[255];
		readFile.getline(temp, 255);
		SIZE = atoi(temp);
		cardBooks = new cardBook[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			readFile.getline(temp, 255);
			cardBooks[i].idCardBook = atoi(temp);
			readFile.getline(temp, 255);
			cardBooks[i].kindBook = temp;
			readFile.getline(temp, 255);
			cardBooks[i].title = temp;
			readFile.getline(temp, 255);
			cardBooks[i].author = temp;
			readFile.getline(temp, 255);
			cardBooks[i].description = temp;
			readFile.getline(temp, 255);
			cardBooks[i].pages = atoi(temp);
			readFile.getline(temp, 255);
			cardBooks[i].dateBookReceivedLibrary = atoi(temp);
			readFile.getline(temp, 255);
			cardBooks[i].yearOfPublication = atoi(temp);
			readFile.getline(temp, 255);
			cardBooks[i].statusOfBook = atoi(temp);


		}
			   
	}
	readFile.close();

}


void PrintCollectionFromFile(cardBook *&cardBooks, int &SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cardBooks[i].ShowInfoCardBook();
	}

}

// 1. Запис  книг у файл
void OutputCollectionInFile(cardBook *&cardBooks)
{
	ofstream writeFile;
	string path = "db1.txt";
	string text;
	writeFile.open(path, ofstream::app);
	if (!writeFile.is_open())
	{
		cout << "Can't open file!" << endl;
	}
	else
	{
		cout << "File saved!" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			writeFile << "**************   Cardbook number: " << i + 1 << "**********************" << endl;
			writeFile << "Card ID:\t" << cardBooks[i].idCardBook << endl;
			writeFile << "Kind:\t   " << cardBooks[i].kindBook << endl;
			writeFile << "Title:\t   " << cardBooks[i].title << endl;
			writeFile << "Author:\t   " << cardBooks[i].author << endl;
			writeFile << "Description:\t   " << cardBooks[i].description << endl;
			writeFile << "Pages:\t   " << cardBooks[i].pages << endl;
			writeFile << "Year of publication:\t   " << cardBooks[i].yearOfPublication << endl;
			writeFile << "The year the book was received by the library:\t   " << cardBooks[i].dateBookReceivedLibrary << endl;
			writeFile << "Status of the book:\t   " << cardBooks[i].statusOfBook<< endl;

		}

	}

	writeFile.close();
}





void AddNewCardBook(cardBook *&cardBooks, int &SIZE)
{
	cardBook tempCardBooks;
	bool exit = false;

	cout << "*****************  ADD CARD OF THE BOOK: => " << tempCardBooks.idCardBook + 1 << "****************************" << endl;
	while (!exit)
	{
		cout << "=============================================================================" << endl;
		cout << "\nKind of book (BOOK, MAGAZINE, NEWSPAPER, BOOKLET):  " << endl;
		cin >> tempCardBooks.kindBook;
		if (tempCardBooks.kindBook == "BOOK" || tempCardBooks.kindBook == "book" || tempCardBooks.kindBook == "magazine" || tempCardBooks.kindBook == "MAGAZINE" || tempCardBooks.kindBook == "newspaper" || tempCardBooks.kindBook == "NEWSPAPER" || tempCardBooks.kindBook == "booklet" || tempCardBooks.kindBook == "BOOKLET")
		{
			exit = true;
		}
		else
		{
			cout << "Enter the printed type correctly!!! " << endl;
		}
	}

	cout << "Title: \t";
	cin.ignore(1, '#');
	getline(cin, tempCardBooks.title);
	cout << "Author: \t";
	getline(cin, tempCardBooks.author);
	cout << "Description (science, technology, math...): \t";
	getline(cin, tempCardBooks.description);
	exit = false;
	while (!exit)
	{
		cout << "Pages: \t";
		cin >> tempCardBooks.pages;
		if (tempCardBooks.pages < 1)
		{
			cout << "!!! Enter the correct number of pages: " << endl;
		}
		else
		{
			exit = true;
		}
	}
	exit = false;
	while (!exit)
	{
		cout << "The Year the book was received by the library \t";
		cin >> tempCardBooks.dateBookReceivedLibrary;
		if (tempCardBooks.dateBookReceivedLibrary < cardBooks->yearOfPublication && tempCardBooks.dateBookReceivedLibrary < 1940)
		{
			cout << "!!! Enter the correct year the book was received by the library: " << endl;
		}
		else
		{
			exit = true;
		}
	}

	exit = false;
	while (!exit)
	{
		cout << "Year of publication: \t";
		cin >> tempCardBooks.yearOfPublication;
		if (1100 > tempCardBooks.yearOfPublication || tempCardBooks.yearOfPublication > 2019)
		{
			cout << "!!! Enter the correct Year of publication:  " << endl;
		}
		else
		{
			exit = true;
		}
	}

	cout << "Status of book (0 - in the library, 1 - in the client):" << endl;
	cin >> tempCardBooks.statusOfBook;


	cardBook *NewCardBooks = new cardBook[SIZE + 1];
	int i = 0;
	cout << "SIZE=" << SIZE << endl;
	for (int i = 0; i < SIZE; i++)
	{
		
		NewCardBooks[i].idCardBook = cardBooks[i].idCardBook;
		NewCardBooks[i].kindBook = cardBooks[i].kindBook;
		NewCardBooks[i].title = cardBooks[i].title;
		NewCardBooks[i].description = cardBooks[i].description;
		NewCardBooks[i].pages = cardBooks[i].pages;
		NewCardBooks[i].dateBookReceivedLibrary = cardBooks[i].dateBookReceivedLibrary;
		NewCardBooks[i].yearOfPublication = cardBooks[i].yearOfPublication;
		NewCardBooks[i].statusOfBook = cardBooks[i].statusOfBook;
	}
	
			NewCardBooks[SIZE].idCardBook = tempCardBooks.idCardBook;
			NewCardBooks[SIZE].kindBook = tempCardBooks.kindBook;
			NewCardBooks[SIZE].author = tempCardBooks.author;
			NewCardBooks[SIZE].description = tempCardBooks.description;
			NewCardBooks[SIZE].pages = tempCardBooks.pages;
			NewCardBooks[SIZE].dateBookReceivedLibrary = tempCardBooks.dateBookReceivedLibrary;
			NewCardBooks[SIZE].yearOfPublication = tempCardBooks.yearOfPublication;
		
	
	delete []cardBooks;
	cardBooks = NewCardBooks;
	SIZE++;
}




// 5. Упорядкування по полях : тип інформаційного джерела(книга, журнал, газета) і назва
void SortByKind(cardBook *&cardBooks)
{
	cout << "Kind of book: BOOK, MAGAZINE, NEWSPAPER, BOOKLET" << endl;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (cardBooks[j].kindBook > cardBooks[j + 1].kindBook)
			{
				swap(cardBooks[j], cardBooks[j + 1]);
			}
		}
	}

}

// Сортування по прізвищу автора
void SortByAuthor(cardBook *&cardBooks)
{
	cout << "SORTING BY THE AUTHOR OF BOOK: " << endl;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (cardBooks[j].author > cardBooks[j + 1].author)
			{
				swap(cardBooks[j], cardBooks[j + 1]);
			}
		}
	}

}

//6.1 Пошук : наявність заданої книги (відомі автор і назва)
void FindCardBook(cardBook *&cardBooks, int menu, string FindBookTitle, string FindBookAuthor)
{
	bool isBookTitle = false;
	bool isBookAuther = false;
	cout << "Enter TITLE of book do You want to find : " << endl;
	cin.ignore();
	getline(cin, FindBookTitle);
	//cin >> FindBookTitle;
	cout << "Enter AUTHOR of book do You want to find : " << endl;
	getline(cin, FindBookAuthor);
	//cin >> FindBookAuthor;
	for (int i = 0; i < SIZE; i++)
	{
		if (cardBooks[i].title == FindBookTitle && cardBooks[i].author == FindBookAuthor)
		{
			isBookTitle = true;
			isBookAuther = true;
			cardBooks[i].ShowInfoCardBook();
			cout << endl;
		}
	}
	if (!isBookTitle || !isBookAuther)
	{
		cout << "Please, enter correct data." << endl;
	}
}

//6.2 Пошук : наявність заданого журналу
void FindMagazineTitle(cardBook *&cardBooks, string FindBookTitle)
{
	bool isMagazine = false;
	cout << "Enter the TITLE of manager do You want to find : " << endl;
	//cin >> FindBookTitle;
	cin.ignore();
	getline(cin, FindBookTitle);
	for (int i = 0; i < SIZE; i++)
	{
		if (cardBooks[i].title == FindBookTitle && cardBooks[i].kindBook == "MAGAZINE")
		{
			isMagazine = true;
			cardBooks[i].ShowInfoCardBook();
			cout << endl;
		}
	}
	if (!isMagazine)
	{
		cout << "There is no such magazine in the library.\nCheck the search terms. " << endl;
	}

}


//7. Вибірка : книги автора ХХ;
void FindBooksAuthor(cardBook *&cardBooks, int menu, string FindBookAuthor)
{
	bool isAuthor = false;

	cout << "Enter the AUTHOR of books do You want to find : " << endl;
	cin.ignore();
	getline(cin, FindBookAuthor);
	//cin >> FindBookAuthor;

	for (int i = 0; i < SIZE; i++)
	{
		if (cardBooks[i].author == FindBookAuthor)
		{
			isAuthor = true;
			cardBooks[i].ShowInfoCardBook();
			cout << endl;
		}
	}
	if (!isAuthor)
	{
		cout << "There are no books by this author" << endl;
		cout << "***************************************" << endl;

	}


}

//8. Вибірка : книги певної категорії(фантастика, детектив тощо), 
void FindBooksDescription(cardBook *&cardBooks, int menu, string FindDescription)
{
	bool isDescription = false;

	cout << "Enter the DESCRIPTION of books do You want to find : " << endl;
	cin.ignore();
	getline(cin, FindDescription);
	//cin >> FindDescription;

	for (int i = 0; i < SIZE; i++)
	{
		if (cardBooks[i].description == FindDescription)
		{
			isDescription = true;
			cardBooks[i].ShowInfoCardBook();
			cout << endl;
		}
	}
	if (!isDescription)
	{
		cout << "There are no books in this description" << endl;
		cout << "***************************************" << endl;

	}


}

// 9. Вибірка : журнали за певний рік(відомі рік і назва журналу)
void FindMagazineTitleYear(cardBook *&cardBooks, int menu, int FindYearMagazine)
{
	bool isMagazine = false;

	cout << "Enter the YEAR the magazine was printed : ";
	cin >> FindYearMagazine;

	for (int i = 0; i < SIZE; i++)
	{
		if (cardBooks[i].kindBook == "MAGAZINE" && cardBooks[i].yearOfPublication == FindYearMagazine)
		{
			isMagazine = true;
			cardBooks[i].ShowInfoCardBook();
			cout << endl;
		}
	}
	if (!isMagazine)
	{
		cout << "There are no magazines published this year" << endl;
		cout << "***************************************" << endl;

	}


}

// 10. Обчислення: кількість книг деякої категорії
void SumBooksDescription(cardBook *&cardBooks, int menu, string FindDescription)
{
	bool isDescription = false;
	int summa = 0;

	cout << "Enter the DESCRIPTION of books do You want to find : " << endl;
	cin.ignore();
	getline(cin, FindDescription);
	//cin >> FindDescription;

	for (int i = 0; i < SIZE; i++)
	{
		if (cardBooks[i].description == FindDescription)
		{
			isDescription = true;
			summa++;
			cardBooks[i].ShowInfoCardBook();
			cout << endl;
		}
	}
	if (!isDescription)
	{
		cout << "There are no books in this description" << endl;
		cout << "***************************************" << endl;

	}
	cout << "===========================================================================" << endl;
	cout << "Number of books in the category: \" " << FindDescription << "\" = " << summa << endl;

}



// 11. Корекція : видалення зведень про газети за певний рік

void DelYearTitleNewspaper(cardBook *&cardBooks, int menu, string FindNewspaper, int &SIZE)
{
	int DelYearNewspaper;

	bool isDelYearNewspaper = false;
	

	cout << "Enter the Year the newspaper was printed for removal: " << endl;
	cin >> DelYearNewspaper;
	cout << "Enter the Title of the newspaper was printed for removal: " << endl;
	//cin >> FindNewspaper;
	cin.ignore();
	getline(cin, FindNewspaper);
	cout << "FOR DELETE = >>>>>>>" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (DelYearNewspaper == cardBooks[i].yearOfPublication && cardBooks[i].title == FindNewspaper)
		{
			cardBooks[i].ShowInfoCardBook();
			isDelYearNewspaper = true;

			int iterator = 0;
			cardBook *NewCardBooks = new cardBook[SIZE];

			for (int i = 0; i < SIZE; i++)
			{

				if (cardBooks[i].yearOfPublication != DelYearNewspaper)
				{
					NewCardBooks[iterator].idCardBook = cardBooks[i].idCardBook;
					NewCardBooks[iterator].kindBook = cardBooks[i].kindBook;
					NewCardBooks[iterator].title = cardBooks[i].title;
					NewCardBooks[iterator].author = cardBooks[i].author;
					NewCardBooks[iterator].description = cardBooks[i].description;
					NewCardBooks[iterator].pages = cardBooks[i].pages;
					NewCardBooks[iterator].yearOfPublication = cardBooks[i].yearOfPublication;
					NewCardBooks[iterator].dateBookReceivedLibrary = cardBooks[i].dateBookReceivedLibrary;
					NewCardBooks[iterator].statusOfBook = cardBooks[i].statusOfBook;
					iterator++;
				}

			}

			delete[] cardBooks;
			cardBooks = NewCardBooks;
			SIZE--;

		}

	}
	
	if (!isDelYearNewspaper)
	{
		cout << "Enter the correct Year the newspaper was printed" << endl;
	}


	
}

void DelTitleBook(cardBook *&cardBooks, int menu, string FindBookTitle, string FindBookAuthor, int &SIZE)
{
	bool isFindBook = false;


	cout << "Enter the Title of the book for removal: " << endl;
	cin.ignore();
	getline(cin, FindBookTitle);
	cout << "Enter the Author of the book for removal: " << endl;
	getline(cin, FindBookAuthor);
	cout << "\n>>>>>>>>>>> BOOK FOR DELETE = >>>>>>>" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (cardBooks[i].title == FindBookTitle)
		{
			cardBooks[i].ShowInfoCardBook();
			isFindBook = true;
			

		}

	}

	if (!isFindBook)
	{
		cout << "Enter the correct Title and Author of book for removal" << endl;
	}

	int iterator = 0;
	cardBook *NewCardBooks = new cardBook[SIZE];

	for (int i = 0; i < SIZE; i++)
	{

		if (cardBooks[i].title != FindBookTitle)
		{
			NewCardBooks[iterator].idCardBook = cardBooks[i].idCardBook;
			NewCardBooks[iterator].kindBook = cardBooks[i].kindBook;
			NewCardBooks[iterator].title = cardBooks[i].title;
			NewCardBooks[iterator].author = cardBooks[i].author;
			NewCardBooks[iterator].description = cardBooks[i].description;
			NewCardBooks[iterator].pages = cardBooks[i].pages;
			NewCardBooks[iterator].yearOfPublication = cardBooks[i].yearOfPublication;
			NewCardBooks[iterator].dateBookReceivedLibrary = cardBooks[i].dateBookReceivedLibrary;
			NewCardBooks[iterator].statusOfBook = cardBooks[i].statusOfBook;
			iterator++;
		}

	}

	delete[] cardBooks;
	cardBooks = NewCardBooks;
	SIZE--;
	
}


// 12. Табличний звіт : список боржників книг певного автора

//void ListDebtorsBooks(cardBook *&cardBooks, int &SIZE, int menu)
//{
//
//}





/////  CLIENT    ////////////////////////////////////////////
struct cardClient
{
	string idCard;
	string name;
	string surname;
	string hobby;
	int dateOfBirthday;
	int monthOfBirthday;
	int yearOfBirthday;

	void ShowInfoCardClient()
	{
		cout << "-----------------------------------------------------------------------" << endl;
		cout << "ID card\t" << idCard << "\nName " << name << " " << surname << "\nHobby:\t" << hobby << "\nDate of birthday:\t" << dateOfBirthday << " " << monthOfBirthday << " " << yearOfBirthday << endl;
		cout << "-----------------------------------------------------------------------" << endl;
	}
};

//2. Перегляд даних про читачів
void ShowInfoClient(cardClient *&cardClients, int &numberClientsFromFile)
{
	for (int i = 0; i < numberClientsFromFile; i++)
	{
		cardClients[i].ShowInfoCardClient();
	}

}


void FillClientsFromFile(cardClient *&cardClients) //11.Enter books from File\n";
{
	string path = "db2.txt";
	ifstream readFile;
	readFile.open(path);
	if (!readFile.is_open())
	{
		cout << "Can't open file " << endl;
	}
	else
	{

		char temp1[255];
		readFile.getline(temp1, 255);
		numberClientsFromFile = atoi(temp1);
		cardClients = new cardClient[numberClientsFromFile];
		for (int i = 0; i < numberClientsFromFile; i++)
		{
			readFile.getline(temp1, 255);
			cardClients[i].idCard = atoi(temp1);
			readFile.getline(temp1, 255);
			cardClients[i].name = temp1;
			readFile.getline(temp1, 255);
			cardClients[i].surname = temp1;
			readFile.getline(temp1, 255);
			cardClients[i].hobby = temp1;
			readFile.getline(temp1, 255);
			cardClients[i].yearOfBirthday = atoi(temp1);
			readFile.getline(temp1, 255);
			cardClients[i].monthOfBirthday = atoi(temp1);
			readFile.getline(temp1, 255);
			cardClients[i].dateOfBirthday = atoi(temp1);
		
		}

	}
	readFile.close();

}

void PrintClientsFromFile(cardClient *&cardClients, int &numberClientsFromFile)
{
	for (int i = 0; i < numberClientsFromFile; i++)
	{
		cout << "=========CARD CLIENTS NUMBER: " <<i+1<<" =============================" << endl;
		cardClients[i].ShowInfoCardClient();
	}
	cout << endl;
}

// 
void OutputClientsInFile(cardClient *&cardClients, int &numberClientsFromFile)
{
	ofstream writeFile;
	string path = "db3.txt";
	string text;
	writeFile.open(path, ofstream::app);
	if (!writeFile.is_open())
	{
		cout << "Can't open file!" << endl;
	}
	else
	{
		cout << "File saved!" << endl;
		for (int i = 0; i < numberClientsFromFile; i++)
		{
			writeFile << "**************   Cardclient number: " << i + 1 << "**********************" << endl;
			writeFile << "Card ID:\t" << cardClients[i].idCard << endl;
			writeFile << "Name:\t   " << cardClients[i].name<<" " << cardClients[i].surname << endl;
			writeFile << "Hobby:\t   " << cardClients[i].hobby << endl;
			writeFile << "Birthday:\t  " << cardClients[i].dateOfBirthday <<" "<< cardClients[i].monthOfBirthday <<" "<< cardClients[i].yearOfBirthday << endl;
			
		}

	}

	writeFile.close();
}


//1. Заповнення бази даних читачами бібліотеки
void CreateCollectionCardClients(cardClient *&cardClients, int &numberClientsFromFile)
{
	cardClient tempCardClients;

		
		tempCardClients.idCard = numberClientsFromFile + 1;
		cout << "********************** Add card of the client: => " << numberClientsFromFile + 1 << endl;
		cout << "Name of client:\t";
		cin.ignore();
		getline(cin, tempCardClients.name);
		//cin >> tempCardClients.name;
		cout << "Surname of client:\t";
		//cin >> tempCardClients.surname;
		getline(cin, tempCardClients.surname);
		cout << "Hobby:\t";
		cin >> tempCardClients.hobby;
		getline(cin, tempCardClients.hobby);
		

		bool exit = false;
		while (!exit)
		{
			cout << "Year of birthday:\t" << endl;
			cin >> tempCardClients.yearOfBirthday;
			if (tempCardClients.yearOfBirthday < 1930 || tempCardClients.yearOfBirthday > 2019)
			{
				cout << "!!! Enter the correct Year of birthday:" << endl;
			}
			else
			{
				exit = true;
			}
		}
		exit = false;
		while (!exit)
		{
			cout << "Month of birthday (from 1 to 12):\t";
			cin >> tempCardClients.monthOfBirthday;
			if (tempCardClients.monthOfBirthday < 1 || tempCardClients.monthOfBirthday > 12)
			{
				cout << "!!! Enter the correct Month of birthday:" << endl;
			}
			else
			{
				exit = true;
			}
		}
		exit = false;
		while (!exit)
		{
			cout << "Date of birthday:\t";
			cin >> tempCardClients.dateOfBirthday;
			if (tempCardClients.monthOfBirthday % 2 == 0 && tempCardClients.monthOfBirthday != 8 && tempCardClients.monthOfBirthday != 2 && tempCardClients.dateOfBirthday < 1 || tempCardClients.dateOfBirthday > 30)
			{
				cout << "!!! Enter the correct Day of birthday (from 1 to 30):" << endl;
			}
			else if (tempCardClients.monthOfBirthday % 2 != 0 && tempCardClients.monthOfBirthday == 8 && tempCardClients.dateOfBirthday < 1 || tempCardClients.dateOfBirthday > 31)
			{
				cout << "!!! Enter the correct Day of birthday (from 1 to 31):" << endl;
			}
			else if (tempCardClients.yearOfBirthday % 2 == 0 && tempCardClients.monthOfBirthday == 2 && tempCardClients.dateOfBirthday < 1 || tempCardClients.dateOfBirthday > 28)
			{
				cout << "!!! Enter the correct Day of birthday (from 1 to 28):" << endl;
			}
			else if (tempCardClients.yearOfBirthday % 2 != 0 && tempCardClients.monthOfBirthday == 2 && tempCardClients.dateOfBirthday < 1 || tempCardClients.dateOfBirthday > 29)
			{
				cout << "!!! Enter the correct Day of birthday (from 1 to 29):" << endl;
			}
			else
			{
				exit = true;
			}

		}
	
		cardClient *NewCardClients = new cardClient[numberClientsFromFile + 1];

		for (int i = 0; i < numberClientsFromFile; i++)
		{
			NewCardClients[i].idCard = cardClients[i].idCard;
			NewCardClients[i].name = cardClients[i].name;
			NewCardClients[i].surname = cardClients[i].surname;
			NewCardClients[i].hobby = cardClients[i].hobby;
			NewCardClients[i].yearOfBirthday = cardClients[i].yearOfBirthday;
			NewCardClients[i].monthOfBirthday = cardClients[i].monthOfBirthday;
			NewCardClients[i].dateOfBirthday = cardClients[i].dateOfBirthday;

		}

		NewCardClients[numberClientsFromFile] = tempCardClients;

		delete[] cardClients;
		cardClients = NewCardClients;
		numberClientsFromFile++;

}

// Сортування по прізвищу клієнта
void SortBySurname(cardClient *&cardClients)
{
	for (int i = 0; i < numberClientsFromFile - 1; i++)
	{
		for (int j = 0; j < numberClientsFromFile - i - 1; j++)
		{
			if (cardClients[j].surname > cardClients[j + 1].surname)
			{
				swap(cardClients[j], cardClients[j + 1]);
			}
		}
	}
}


//7. Пошук по прізвищу клієнта
void FindCardClientSurname(cardClient *&cardClients)
{
	bool isSurname = false;
	string CardClientsSurname;

	cout << "Enter the Surname of Client do You want to find : " << endl;
	cin >> CardClientsSurname;

	for (int i = 0; i < numberClientsFromFile; i++)
	{
		if (cardClients[i].surname == CardClientsSurname)
		{
			isSurname = true;
			cardClients[i].ShowInfoCardClient();
			cout << endl;
		}
	}
	if (!isSurname)
	{
		cout << "This client is not in the library database" << endl;
		cout << "***************************************" << endl;
	}


}



//Delete cardclients
void DelCardClients(cardClient *&cardClients, int &numberClientsFromFile, int menu, string FindName, string FindSurname)
{
	bool isSurname = false;

	cout << "Enter the Name of client for removal: " << endl;
	cin >> FindName;
	cout << "Enter the Surname of client for removal: " << endl;
	cin >> FindSurname;
	
	cout << "\n>>>>>>>> FOR DELETE = >>>>>>>" << endl;
	for (int i = 0; i < numberClientsFromFile; i++)
	{
		if (cardClients[i].name == FindName && cardClients[i].surname == FindSurname)
		{
			cardClients[i].ShowInfoCardClient();
			isSurname = true;

			int iterator = 0;
			cardClient *NewCardClients = new cardClient[numberClientsFromFile];

			for (int i = 0; i < numberClientsFromFile; i++)
			{

				if (cardClients[i].name != FindName)
				{
					NewCardClients[iterator].idCard = cardClients[i].idCard;
					NewCardClients[iterator].name = cardClients[i].name;
					NewCardClients[iterator].surname = cardClients[i].surname;
					NewCardClients[iterator].hobby = cardClients[i].hobby;
					NewCardClients[iterator].yearOfBirthday = cardClients[i].yearOfBirthday;
					NewCardClients[iterator].monthOfBirthday = cardClients[i].monthOfBirthday;
					NewCardClients[iterator].dateOfBirthday = cardClients[i].dateOfBirthday;
					iterator++;
				}

			}
				
			delete[] cardClients;
			cardClients = NewCardClients;
			numberClientsFromFile--;


		}

	}

	if (!isSurname)
	{
		cout << "Enter the correct name visitors" << endl;
	}
}


//Developer
struct developer
{
	string devel;
	string address;
	string email;

	void ShowInfoDev()
	{
		cout << "    Developer: \t" << devel << "\nAddress: \t" << address << "\ne-mail: \t" << email << endl;
		cout << "                           All rights reserved." << endl;
		cout << "     Support phone: +3(8)096-599-13-35 (paid from all Ukrainian networks)." << endl;
	}
};

void CreateDev(developer dev)
{

	dev.devel = "Paniuk Valentyna";
	dev.address = "str. Haidamatska, buil. 41, apt. 78, Rivne, 33000";
	dev.email = "valentyna.paniuk@gmail.com";
	dev.ShowInfoDev();
}

// Library
struct library
{
	cardBook book;
	string name;
	int booksCount;
	string director;
	string address;
	string contactManager;
	string workSchedule;
	string history;
	void ShowInfoLibrary()
	{
		cout << "LIBRARY:\t" << name << "\nAddress:\t" << address << "\nWorkSchedule\t" << workSchedule << endl;
	}
};

//1. About Library
void CreateLibrary(library &lib)
{
	lib.name = "Rivne Regional Universal Scientific Library";
	lib.booksCount = 10;
	lib.director = "Valentyna Petrivna Yaroschuk";
	lib.address = "33028, Rivne, Sq. Korolenko, 6";
	lib.workSchedule = "\t9:00=19:00; \nSunday:\t\t\t9:00 = 18:00;\n\t\t\tDay off is friday. ";
	lib.history = "Rivne Regional Universal Scientific Library was founded in February 1940.";
	lib.ShowInfoLibrary();
}


//Menu
void MenuManager(int menu, bool exit, cardBook *cardBooks, cardClient *cardClients, developer dev, library &lib, int SIZE, string FindBookTitle, string FindBookAuthor, string FindDescription, int FindYearMagazine, string FindNewspaper, string FindName, string FindSurname)
{

	while (!exit)
	{
		system("cls");
		cout << " =================     MENU   ==============================:\n";
		cout << "  1.About Library:\n"; // Ввід бази даних
		cout << "        11.Enter books from File\n";//+
		cout << "        12.Enter clients from File\n";//+
		cout << "  2.Browsing the database:\n"; //Перегляд бази дних
		cout << "  3.Editing the database:\n"; //Редагування бази даних
		cout << "        31.Add new card client:\n";//+
		cout << "        32.Add new card book:\n";//+
		cout << "        33.Delete card book\n";//+
		cout << "        34.Delete card client\n";
		cout << "        35.Deletion of newspaper information for a certain year\n";//+
		cout << "        36.Clear the database\n";//+
		cout << "  4.Database output:\n"; //Вивід бази даних
		cout << "        41. Books in File\n"; //+
		cout << "        42. Clients in File\n";//+
		cout << "  5.Data search:\n";//Пошук
		cout << "        51.By client's last name\n"; //+
		cout << "        52.By the Title and Author of the book\n"; //+
		cout << "        53.By the Title of magazine\n"; //+
		cout << "        54.By the Author of books\n"; //+
		cout << "        55.By the Description of books\n"; //+
		cout << "        56.By the Year of publication of magazine\n"; //+
		cout << "  6.Sorting:\n"; //Сортування
		cout << "        61.Sort by book Kind:\n"; //+
		cout << "        62.Sort by the Author of the book\n";//+
		cout << "        63.Sort by visitor Last name:\n";//+
		cout << "  7.Reports:\n"; //Звіти
		cout << "        71.Number of books in the category (fiction, detective, fashion...):\n";//+
		cout << "  8.About the developer\n";//+
		cout << "  9.Exit\n\n";//+

		cout << "Select menu item: ";
		cin >> menu;
		cardBook tempCardBooks;
		switch (menu)
		{
		case 1: //1.About Database:\n";
		{
			system("cls");
			CreateLibrary(lib);
			system("pause");
			break;

		}
		case 11: //11.From File\n";
		{
			system("cls");
			FillCollectionFromFile(cardBooks);
			PrintCollectionFromFile(cardBooks, SIZE);
			system("pause");
			break;
		}
		case 12: // 12. Enter books from Keyboard\n";
		{
			system("cls");
			FillClientsFromFile(cardClients);
			PrintClientsFromFile(cardClients, numberClientsFromFile);
			system("pause");
			break;
					   			
		}
		
		case 2: // 2.Browsing the database ÁÄ\n"; ïåðåãëÿä áàçè äàíèõ
		{
			system("cls");
			cout << "=================== COLLECTION OF BOOKS IN THE LIBRARY: ==========================" << endl;
			ShowInfoCardBook(cardBooks, SIZE);
			cout << "===================	VISITORS TO THE LIBRARY: ==================================" << endl;
			ShowInfoClient(cardClients, numberClientsFromFile);
			system("pause");
			break;
		}
		case 36: //36.Clear the database\n";
		{
			system("cls");

			delete[] cardBooks;
			cardBooks = nullptr;

			delete[] cardClients;
			cardClients = nullptr;
			
			cout << "Database is empty." << endl;
		
			system("pause");
			break;
		}
		case 31: //  31.Add new card clients:\n";
		{
			system("cls");
			CreateCollectionCardClients(cardClients, numberClientsFromFile);
			PrintClientsFromFile(cardClients, numberClientsFromFile);
			system("pause");
			break;
		}
		case 32: //23.Add new card book:\n";
		{
			system("cls");
			AddNewCardBook(cardBooks, SIZE);
			PrintCollectionFromFile(cardBooks, SIZE);
			system("pause");
			break;
		}
		case 33: //33.Delete card books\n";
		{
			system("cls");
			DelTitleBook(cardBooks, menu, FindBookTitle, FindBookAuthor, SIZE);
			cout << "********************************************" << endl;
			ShowInfoCardBook(cardBooks, SIZE);
			system("pause");
			break;
		}
		case 34: //34.Delete card client\n";
		{
			system("cls");
			DelCardClients(cardClients, numberClientsFromFile, menu, FindName, FindSurname);
			cout << "********************************************" << endl;
			ShowInfoClient(cardClients, numberClientsFromFile);
			system("pause");
			break;
		}
		case 35: //35.Deletion of newspaper information for a certain year\n";
		{
			system("cls");
			DelYearTitleNewspaper(cardBooks, menu, FindNewspaper, SIZE);
			cout << "********************************************" << endl;
			ShowInfoCardBook(cardBooks, SIZE);

			system("pause");
			break;
		}
		case 41: // 41.Database output in File\n";
		{
			system("cls");
			OutputCollectionInFile(cardBooks);
			system("pause");
			break;
		}
		case 42: //42.Database output on Screen\n";
		{
			system("cls");
			OutputClientsInFile(cardClients, numberClientsFromFile);
			system("pause");
			break;
		}
		case 51: // 51.Data search by client's last name:\n";
		{
			system("cls");
			FindCardClientSurname(cardClients);
			system("pause");
			break;
		}
		case 52: //52.Data search by the title and Author of the book:\n";
		{
			system("cls");
			FindCardBook(cardBooks, menu, FindBookAuthor, FindBookTitle);
			system("pause");
			break;
		}

		case 53: // 53.By the Title of magazine : \n";
		{
			system("cls");
			FindMagazineTitle(cardBooks, FindBookTitle);
			menu = 8;
			system("pause");
			break;
		}
		case 54://54.By the Author of books\n";
		{
			system("cls");
			FindBooksAuthor(cardBooks, menu, FindBookAuthor);
			menu = 8;
			system("pause");
			break;
		}

		case 55://55.By the Description of books\n";
		{
			system("cls");
			FindBooksDescription(cardBooks, menu, FindDescription);
			menu = 8;
			system("pause");
			break;
		}
		case 56: // 56.By the Title and Year of publication of magazine\n";
		{
			system("cls");
			FindMagazineTitleYear(cardBooks, menu, FindYearMagazine);
			menu = 8;
			system("pause");
			break;
		}
		case 61: // 61.Sort by book title:\n";
		{
			system("cls");
			SortByKind(cardBooks);
			ShowInfoCardBook(cardBooks, SIZE);
			system("pause");
			break;
		}
		case 62: //62.Sort by the author of the book:\n";
		{
			SortByAuthor(cardBooks);
			ShowInfoCardBook(cardBooks, SIZE);
			system("pause");
			break;
		}
		case 63: //63.Sort by visitor name:\n";
		{
			SortBySurname(cardClients);
			ShowInfoClient(cardClients, numberClientsFromFile);
			menu = 8;
			system("pause");
			break;
		}

		case 71: //71.Number of books in the category(fiction, detective, fashion, business) : \n";
		{
			SumBooksDescription(cardBooks, menu, FindDescription);
			menu = 8;
			system("pause");
			break;
		}
		
		case 8: //8.About the developer\n";
		{
			system("cls");
			CreateDev(dev);
			system("pause");
			menu = 8;
			break;
		}
		
		case 9: //10.Exit\n\n";
		{
			exit = true;
			break;
		}

		default:
		{
			cout << "ERROR! \n\n";
			menu = 8;
		}
		}

	}

}

void FirstMenu()
{
	bool exit = false;
	int menu = 8;
	/*int numberOfCardBooks = 0;
	int numberOfCardClients = 0;*/

	int index = 0;

	string FindBookTitle;
	string FindBookAuthor;
	string FindDescription;
	string FindNewspaper;
	string FindName; 
	string FindSurname;
	int FindYearMagazine = 0;


	developer dev;
	library lib;
	string personType;

	system("cls");
	cout << "======================================================================================" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|                               WELCAME TO THE LIBRARY!                              |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|                        People stop thinking, when they stop reading                |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "|                                                                                    |" << endl;
	cout << "=====================================================================================" << endl;
	cout << "\n\n\t\t\tAre you a client or manager?" << endl;
	cin >> personType;



	do
	{
		if (personType == "client" || personType == "Client" || personType == "CLIENT")
		{
			; // Calls Function mainMenu
		}

		else if (personType == "manager" || personType == "Manager" || personType == "MANAGER" || personType == "m")
		{
			/*cout << "How many clients cards we will enter: " << endl;
			cin >> numberOfCardClients;


			cout << "How many book cards we will enter: " << endl;
			cin >> numberOfCardBooks;*/

			

			cardClient *cardClients = new cardClient[numberClientsFromFile];
		
			/*int SIZE = numberBooksFromFile + numberOfCardBooks;*/



			cardBook *cardBooks = new cardBook[SIZE];

			

			MenuManager(menu, exit, cardBooks, cardClients, dev, lib, SIZE, FindBookTitle, FindBookAuthor, FindDescription, FindYearMagazine, FindNewspaper, FindName, FindSurname);

			delete[] cardBooks;
			cardBooks = nullptr;

			delete[] cardClients;
			cardClients = nullptr;

		}
	} while (personType == "client" || personType == "Client" || personType == "CLIENT" || personType == "manager" || personType == "Manager" || personType == "MANAGER");

	cout << endl << "Thank You for visiting our library. BYE !!! " << endl;

}



int main()
{
	FirstMenu();

	system("pause");
	return 0;
}