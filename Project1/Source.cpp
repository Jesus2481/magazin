#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>

#if defined(max)
#undef max
#endif


// Учетные записи
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin","user" };
std::string* passwordArr = new std::string[userCount]{ "admin","user" };


// Склад
int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];


// Чек
int checkSize = 1;
int* countCheckArr = new int[checkSize];
double* priceCheckArr = new double[checkSize];
double* totalPriceCheckArr = new double[checkSize];
std::string* nameCheckArr = new std::string[checkSize];


//
template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);


// Функции
void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ShowStorage();
void RefilStorage();
void WriteOffFromStorage();
void ChangePrice();

void ChangeStaff();
void AddEmployee();
bool IsNumber(std::string string);
void EmployeeEdit();
void DeleteEmployee();

void ChangeStorage();
void AddProduct();
void ChangeProductName();
void DeleteProduct();

void Selling();




//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void CreateDynamicStorage();
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



//--------------------------
int main()
{
	Start(); // Динамический склад
	delete[]loginArr;
	delete[]passwordArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;
	delete[]priceCheckArr;
	delete[]totalPriceCheckArr;
	delete[]countCheckArr;
	delete[]nameCheckArr;
	return 0;
}
//--------------------------


// Начало
void Start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\t Гараж \n\n\n";
	if (Login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (isAdmin == true)
		{
			std::string choose;
			do
			{
				std::cout << "использовать готовый склад или создать новый?\n";
				std::cout << "1 - Готовый склад\n2 - Создать новый\n\nВвод: ";
				std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);

			if (choose == "1")
			{
				CreateStaticStorage();
			}
			else
			{
				// Создать динамического склада
			}

			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}
}

// Логин и пароль
bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "Введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "Ввелите пароль: ";
		std::getline(std::cin, pass, '\n');

		for (int i = 1; i < userCount; i++)
		{
			if (login == loginArr[0] && pass == passwordArr[0])
			{
				std::cout << "Добро пожаловать " << loginArr[0] << '\n';
				isAdmin = true;
				return true;
			}
			else if (login == loginArr[i] && pass == passwordArr[i])
			{
				std::cout << "Добро пожаловать " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "Неверно введен логин или пароль!\n";
	}
	return true;
}

// Меню пользователя
void ShopUserMenu()
{
	std::string choose{};
	while (true)
	{

		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Отчёт о прибыли\n";
			std::cout << "0. закрыть смену\n\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "UserMenuError";
		}
	}
}

// Меню админа
void ShopAdminMenu()
{
	std::string choose{};
	while (true)
	{

		do
		{
			std::cout << "1. Начать продажу\n";
			std::cout << "2. Показать склад\n";
			std::cout << "3. Пополнить склад\n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену\n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. Изменить персонал\n";
			std::cout << "8. Отчёт о прибыли\n";
			std::cout << "0. закрыть смену\n\n";

			std::cout << "Ввод: ";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);

		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{
			ShowStorage();
			RefilStorage();
		}
		else if (choose == "4")
		{
			ShowStorage();
			WriteOffFromStorage();
		}
		else if (choose == "5")
		{
			ShowStorage();
			ChangePrice();
		}
		else if (choose == "6")
		{
			ShowStorage();
			ChangeStorage();
		}
		else if (choose == "7")
		{
			ChangeStaff();
		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cerr << "AdminMenuError";
		}
	}
}

// Склад
void CreateStaticStorage()
{
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string nameStaticArr[staticSize]
	{ "Суп с креветками (Виагра)            ", "Шоколадное пирожное (Поцелуй негра)",
	  "Сукияки (Мясо по японски)            ", "Овощи в соусе (Шмурдяк)             ",
	  "БОМЖенщина (Холодная закуска)        ", "Носы говяжьи (Холодная закуска)     ",
	  "Мозги компостированные (Закуска)", "Мужские слезы (Салат)               ",
	  "Волосатая дева (Коктейль)            ", "Могилка (Торт)                    "
	};

	int countStaticArr[staticSize]{ 35,3,4,8,5,2,10,10,5,5 };

	double priceStaticArr[staticSize]{ 15000.0, 140000.0, 96000.0, 20000.0, 51000.0, 120000.0, 2300.0, 11000.0, 88000.0, 52000.0 };


	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);
}

// Показать склад
void ShowStorage()
{
	std::cout << "ID\tНазвание\t\t\t\tЦена\tкол-во\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << nameArr[i] << "\t" << priceArr[i] << "\t" << countArr[i] << "\n";

	}
}

// Пополнить склад
void RefilStorage()
{
	std::string idStr, addStr;
	int id{}, add{};
	bool exit = false;

	while (true)
	{
		std::cout << "Введите ID товара\t0 - Выход\tВвод: ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id - 1 << "\t" << std::left
				<< std::setw(30) << nameArr[id - 1] << "\t"
				<< countArr[id - 1] << "\n";

			while (true)
			{
				std::cout << "Введите кол-во товара на пополнение: ";
				std::getline(std::cin, addStr, '\n');
				if (IsNumber(addStr))
				{
					add = std::stoi(addStr);
					if (add >= 0 && add < 1000)
					{
						countArr[id - 1] += add;
						std::cout << "\nТовар успешно пополнен\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nОшибка ввода\n\n";
					}
				}
			}
		}
	}

	/*
	do
	{
		std::cout << "Пополнение склада\n Введите id товара: ";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}

	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);

	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << "\n";

	int add{};
	do
	{
		std::cout << "Введите кол-во товаа для пополнения: ";
		std::cin >> add;
	} while (add < 0 || add > MAXINT - countArr[id - 1]);

	countArr[id - 1] += add;
	std::cout << "Товар " << nameArr[id - 1] << " Успешно пополнен\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("pause");
	*/
}

// Списать со склада
void WriteOffFromStorage()
{
	std::string idStr, delStr;
	int id{}, del{};
	bool exit = false;

	while (true)
	{
		std::cout << "Введите ID товара\t0 - Выход\tВвод: ";
		std::getline(std::cin, idStr, '\n');
		if (idStr == "0")
		{
			break;
		}
		else if (IsNumber(idStr))
		{
			id = std::stoi(idStr);
			std::cout << id - 1 << "\t" << std::left
				<< std::setw(30) << nameArr[id - 1] << "\t"
				<< countArr[id - 1] << "\n";

			while (true)
			{
				std::cout << "Введите кол-во товара на списание: ";
				std::getline(std::cin, delStr, '\n');
				if (IsNumber(delStr))
				{
					del = std::stoi(delStr);
					if (del >= 0 && del <= countArr[id - 1])
					{
						countArr[id - 1] -= del;
						std::cout << "\nТовар успешно списан\n\n";
						break;
					}
					else
					{
						std::cout << "\n\nОшибка ввода\n\n";
					}
				}
			}
		}
	}
}

// Изменить цену
void ChangePrice()
{
	std::string idStr;

	do
	{
		std::cout << "Изменение цены\n Введите id товара: ";
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0)
		{
			break;
		}

	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);

	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << " Текущая цена " << priceArr[id - 1] << "\n\n";

	double newPrice{};
	do
	{
		std::cout << "Введите новую цену: ";
		std::cin >> newPrice;
	} while (newPrice < 0 || newPrice > MAXINT);

	priceArr[id - 1] = newPrice;
	std::cout << "Товар " << nameArr[id - 1] << " Принял новую стоимость " << newPrice << "\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("pause");
}

// Изменить персонал
void ChangeStaff()
{
	std::string choose;
	std::cout << "Изменение персонала магазина\n\n";

	do
	{
		std::cout << "1 - Добавить сотрудника\n2 - Изменить логин и пароль\n3 - Удалить текущего сотрудника\n0 - Выход\n\nВвод: ";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 51);

	if (choose == "1")
	{
		AddEmployee();
	}
	else if (choose == "2")
	{
		EmployeeEdit();
	}
	else if (choose == "3")
	{
		DeleteEmployee();
	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cerr << "\nChangeStaffError\n\n";
	}
}

// Добавить персонал
void AddEmployee()
{
	for (int i = 0; i < userCount; i++)
	{
		std::cout << i + 1 << "\t" << std::left << std::setw(10)
			<< loginArr[i] << "\t" << passwordArr[i] << "\n";
	}
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++)
	{
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}

	//std::swap(loginArr, tempLogin);

	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	loginArr = new std::string[userCount];
	passwordArr = new std::string[userCount];
	for (int i = 0; i < userCount - 1; i++)
	{
		loginArr[i] = tempLogin[i];
		passwordArr[i] = tempPass[i];
	}

	std::string newLogin, newPass;
	std::cout << "Введите логин нового сотрудника: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника: ";
	std::getline(std::cin, newPass, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPass;
	// test
	for (int i = 0; i < userCount; i++)
	{
		std::cout << "Добавленные пользователи - " << loginArr[i] << " " << passwordArr[i] << "\n";
	}
}

// Удалить персонал
void DeleteEmployee()
{
	std::string chooseID;
	int empID{};
	while (true)
	{
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10)
				<< loginArr[i] << "\t" << passwordArr[i] << "\n";
		}
		std::cout << "Введите сотрудника для удаления\t0 - Выход\nВвод: ";
		std::getline(std::cin, chooseID, '\n');
		if (chooseID == "0")
		{
			break;
		}
		else if (IsNumber(chooseID))
		{
			empID = std::stoi(chooseID);
			std::string* tempLogin = new std::string[userCount];
			std::string* tempPass = new std::string[userCount];
			for (int i = 0; i < userCount; i++)
			{
				tempLogin[i] = loginArr[i];
				tempPass[i] = passwordArr[i];
			}
			delete[]loginArr;
			delete[]passwordArr;
			userCount--;
			loginArr = new std::string[userCount];
			passwordArr = new std::string[userCount];

			for (int i = 0, j = 0; i < userCount, j < userCount; i++, j++)
			{
				if (i == empID - 1)
				{
					i++;
					loginArr[j] == tempLogin[i];
					passwordArr[j] == tempPass[i];
				}
				else
				{
					loginArr[j] == tempLogin[i];
					passwordArr[j] == tempPass[i];
				}
			}
			break;
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}
}

// Изменить персонал
void EmployeeEdit()
{
	std::string chooseID, newLogin, newPass;
	int empID = 0;
	while (true)
	{
		for (int i = 0; i < userCount; i++)
		{
			std::cout << i + 1 << "\t" << std::left << std::setw(10)
				<< loginArr[i] << "\t" << passwordArr[i] << "\n";
		}

		std::cout << "Выберите ID пользователя\t0 - Выход\nВвод: ";
		std::getline(std::cin, chooseID, '\n');

		if (chooseID == "0")
		{
			break;
		}
		else if (IsNumber(chooseID))
		{
			empID = std::stoi(chooseID);
			for (int i = 0; i < userCount; i++)
			{
				if (i == empID - 1)
				{
					std::cout << "Введите новый логин: ";
					std::getline(std::cin, newLogin, '\n');
					std::cout << "Введите новый пароль: ";
					std::getline(std::cin, newPass, '\n');

					loginArr[i] = newLogin;
					passwordArr[i] = newPass;
					break;
				}
			}
		}
		else
		{
			std::cout << "\n\nОшибка ввода\n\n";
		}
	}
}

// Добавить продукты
void AddProduct()
{
	std::string choose;

	while (true)
	{
		std::cout << "1 - Добавить новый продукт\t0 - выход\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];

			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[] idArr;
			delete[] countArr;
			delete[] priceArr;
			delete[] nameArr;

			size++;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0; i < size - 1; i++)
			{
				idArr[i] = tempID[i];
				countArr[i] = tempCount[i];
				priceArr[i] = tempPrice[i];
				nameArr[i] = tempName[i];
			}

			std::string newName, newCountStr, newPriceStr;
			int newCount{};
			double newPrice{};

			while (true)
			{
				std::cout << "Введите название нового товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[size - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\n\nМакс длина названия 30 символов\n\n";
				}
			}

			while (true)
			{
				std::cout << "Введите кол-во нового товара: ";
				std::getline(std::cin, newCountStr, '\n');
				if (IsNumber(newCountStr))
				{
					if (std::stoi(newCountStr) >= 0 && std::stoi(newCountStr) < 1000)
					{
						countArr[size - 1] = std::stoi(newCountStr);
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ввод\n\n";
					}
				}
			}

			while (true)
			{
				std::cout << "Введите цену нового товара: ";
				std::getline(std::cin, newPriceStr, '\n');
				if (IsNumber(newPriceStr))
				{
					if (std::stoi(newPriceStr) >= 0 && std::stoi(newPriceStr) < 10000)
					{
						priceArr[size - 1] = std::stod(newPriceStr);
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ввод\n\n";
					}
				}
				else
				{
					std::cout << "\n\nНекоректный ввод\n\n";
				}
			}

			idArr[size - 1] = size;

			std::cout << idArr[size - 1] << '\t' << std::left << std::setw(30) << nameArr[size - 1] << '\t'
				<< countArr[size - 1] << '\t' << priceArr[size - 1] << "\n\nТовар успешно добавлен на склад\n\n";

			delete[] tempID;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;

			break;
		}
		else
		{
			std::cout << "\n\nНекоректный ввод\n\n";
		}
	}
}

// Изменить имя продукта
void ChangeProductName()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Изменить название товара\t0 - Выход\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			std::string idStr, newName;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара: ";
				std::getline(std::cin, idStr, '\n');
				if (IsNumber(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ввод\n\n";
					}
				}
				else
				{
					std::cout << "\n\nНекоректный ввод\n\n";
				}
			}

			while (true)
			{
				std::cout << idArr[size - 1] << '\t' << std::left << std::setw(30) << nameArr[size - 1] << '\t'
					<< countArr[size - 1] << "\n\n";

				std::cout << "Введите название нового товара: ";
				std::getline(std::cin, newName, '\n');
				if (newName.size() <= 30)
				{
					nameArr[size - 1] = newName;
					break;
				}
				else
				{
					std::cout << "\n\nМакс длина названия 30 символов\n\n";
				}
			}

			std::cout << idArr[size - 1] << '\t' << std::left << std::setw(30) << nameArr[size - 1] << '\t'
				<< countArr[size - 1] << '\t' << priceArr[size - 1] << "\n\nНазвание товара изменено\n\n";

			break;
		}
		else
		{
			std::cout << "\n\nНекоректный ввод\n\n";
		}
	}
}

// Удалить продукт
void DeleteProduct()
{
	std::string choose;

	while (true)
	{
		std::cout << "1 - Удалить товар со склада\t0 - выход\nВвод: ";
		std::getline(std::cin, choose, '\n');
		if (choose == "0")
		{
			break;
		}
		else if (choose == "1")
		{
			std::string idStr;
			int id{};

			while (true)
			{
				std::cout << "Введите ID товара для удаления: ";
				std::getline(std::cin, idStr, '\n');
				if (IsNumber(idStr))
				{
					id = std::stoi(idStr);
					if (id > 0 && id <= size)
					{
						break;
					}
					else
					{
						std::cout << "\n\nНекоректный ввод\n\n";
					}
				}
				else
				{
					std::cout << "\n\nНекоректный ввод\n\n";
				}
			}

			int* tempID = new int[size];
			int* tempCount = new int[size];
			double* tempPrice = new double[size];
			std::string* tempName = new std::string[size];


			for (int i = 0; i < size; i++)
			{
				tempID[i] = idArr[i];
				tempCount[i] = countArr[i];
				tempPrice[i] = priceArr[i];
				tempName[i] = nameArr[i];
			}

			delete[] idArr;
			delete[] countArr;
			delete[] priceArr;
			delete[] nameArr;

			size--;

			idArr = new int[size];
			countArr = new int[size];
			priceArr = new double[size];
			nameArr = new std::string[size];

			for (int i = 0, j = 0; i < size, j < size; i++, j++)
			{
				if (i == id - 1)
				{
					i++;
					loginArr[j] = tempCount[i];
					passwordArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
					idArr[j] = tempID[j];
				}
				else
				{
					countArr[j] = tempCount[i];
					priceArr[j] = tempPrice[i];
					nameArr[j] = tempName[i];
					idArr[j] = tempID[j];
				}
			}

			std::cout << "\nТовар успешно удален\n\n";
			delete[] tempID;
			delete[] tempCount;
			delete[] tempPrice;
			delete[] tempName;

			break;
		}
		else
		{
			std::cout << "\n\nНекоректный ввод\n\n";
		}
	}
}

// Изменить склад
void ChangeStorage()
{
	std::string choose;
	std::cout << "Изменение склада магазина\n\n";

	do
	{
		std::cout << "1 - Добавить товара\n2 - Измение названия\n3 - Удалить товар\n0 - Выход\n\nВвод: ";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 51);

	if (choose == "1")
	{
		AddProduct();
	}
	else if (choose == "2")
	{
		ChangeProductName();
	}
	else if (choose == "3")
	{
		DeleteProduct();
	}
	else if (choose == "0")
	{

	}
	else
	{
		std::cerr << "\nChangeStaffError\n\n";
	}
}

// Продажа
void Selling()
{
	std::string chooseID, chooseCount;
	int id{}, count{};

	checkSize = 1;
	countCheckArr = new int[checkSize];
	priceCheckArr = new double[checkSize];
	totalPriceCheckArr = new double[checkSize];
	nameCheckArr = new std::string[checkSize];

	while (true)
	{
		system("cls");
		ShowStorage();
		std::cout << "Введите ID товара или 0 для завершения: ";
		std::getline(std::cin, chooseID, '\n');

		if (IsNumber(chooseID))
		{
			std::cout << "\n\nНекорректный ввод\n\n";
			continue;
		}
		else
		{
			id = std::stoi(chooseID);

			if (id == 0)
			{
				//!!!!
				break;
			}
			else if (id > 0 && id <= size)
			{

				while (true)
				{
					std::cout << "Введите кол-во " << nameArr[id - 1] << ": ";
					std::getline(std::cin, chooseCount, '\n');
					if (!IsNumber(chooseCount))
					{
						std::cout << "\n\nНекоректный ввод\n\n";
						continue;
					}
					else
					{
						count = std::stoi(chooseCount);
						if (count > 0 && count <= countArr[id - 1])
						{
							std::cout << std::left << std::setw(30) << nameArr[id - 1]
								<< " " << count << " добавлен в чек\n\n";

							countCheckArr[checkSize - 1] = count;
							priceCheckArr[checkSize - 1] = priceArr[id - 1];
							totalPriceCheckArr[checkSize - 1] = priceArr[id - 1] * count;
							nameCheckArr[checkSize - 1] = nameArr[id - 1];






							break;
						}
						else
						{
							std::cout << "\n\nНекорректное кол-во\n\n";
						}


					}


				}


			}


		}


	}


}












bool IsNumber(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}
	}
	return true;
}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";
	}
	std::cout << "\n";
}