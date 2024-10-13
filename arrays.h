// Автор: Калашников А.Н.
#pragma once // защита от повторного подключения заголовочного файла
#include <iostream> // заголовочный файл с классами, функциями
//и переменными для организации ввода-вывода
#include <fstream> // Заголовочный файл для работы с файловыми потоками
#include <vector> // Заголовочный файл для работы с вектором. Вектор представляет контейнер,
//который содержит коллекцию объектов одного типа.
// Контейнеры - шаблоны классов
#include <string> // Заголовочный файл для работы со строками
#include <stdexcept> // Заголовочный файл, используемый для сообщений об исключениях
using namespace std; // Позволяет использовать все имена из стандартного
//пространства имен (std) без необходимости добавления префикса std::
namespace templates{
	/// Заполнение массива array размера n элементами типа T вручную
	template <typename T>
	void arr_input(T* array, size_t n){
		if (array == nullptr) // Если массив - пустой указатель
			throw invalid_argument("Ошибка: массив пуст"); // Бросаем ошибку типа invalid_argument
		if (n == 0) // Если длина массива равна 0
			throw length_error("Ошибка: длина массива не может быть = 0"); // Бросаем ошибку типа length_error
		for (int i = 0; i < n; i++){
			cout << "Введите " << i+1 << "-й элемент массива ";
			cin >> array[i]; 
		}
	}
/// Заполнение массива array размера n элементами типа T случайными числами
template <typename T>
void arr_input_random(T* array, size_t n){
		if (array == nullptr) // Если массив - пустой указатель
			throw invalid_argument("Ошибка: массив пуст"); // Бросаем ошибку типа invalid_argument
		if (n == 0) // Если длина массива равна 0
			throw length_error("Ошибка: длина массива не может быть = 0"); // Бросаем ошибку типа length_error
		for (int i = 0; i < n; i++){
			array[i] = rand() - 16383.5; // массив заполняется случайными числами в диапазоне [-16383.5; 16383.5]
		}
	}
/// Вывод элементов массива array размера n типа T на экран
template <typename T>
void arr_output(T* array, size_t n){
		if (array == nullptr) // Если массив - пустой указатель
			throw invalid_argument("Ошибка: массив пуст"); // Бросаем ошибку типа invalid_argument
		if (n == 0) // Если длина массива равна 0
			throw length_error("Ошибка: длина массива не может быть = 0"); // Бросаем ошибку типа length_error
		cout << endl;
		for (int i = 0; i < n; i++){
			cout << array[i] << " ";
		}
	}
/// Возвращает сумму a1^2 + ... + an^2 n элементов типа T из массива array
template <typename T>
double arr_calc(T* array, size_t n){
		if (array == nullptr) // Если массив - пустой указатель
			throw invalid_argument("Ошибка: массив пуст"); // Бросаем ошибку типа invalid_argument
		if (n == 0) // Если длина массива равна 0
			throw length_error("Ошибка: длина массива не может быть = 0"); // Бросаем ошибку типа length_error
		T sum = 0; // переменная суммы
		for (int i = 0; i < n; i++){
			sum += array[i] * array[i];
		}
		return sum;
	}
/// Запись элементов типа T массива array размера n в файл с названием fname
template <typename T>
void arr_input_file(T* array, size_t n, const string &fname){
		if (array == nullptr) // Если массив - пустой указатель
			throw invalid_argument("Ошибка: массив пуст"); // Бросаем ошибку типа invalid_argument
		if (n == 0) // Если длина массива равна 0
			throw length_error("Ошибка: длина массива не может быть = 0"); // Бросаем ошибку типа length_error
		ofstream f(fname); // Открываем файл на запись
		if (f.is_open()){ // Если файл открыт
			for (int i = 0; i < n; i++){
			f << array[i]; // Записываем элементы вектора построчно
			f << endl;
			}
			f.close(); 
		}
}
/// Возвращает массив типа T размера n, заполненный элементами из файла fname
template <typename T>
T* arr_output_file(const string &fname, size_t n){
		if (n == 0) // Если длина массива равна 0
			throw length_error("Ошибка: длина массива не может быть = 0"); // Бросаем ошибку типа length_error
		size_t i = 0;
		ifstream f(fname); // Открываем файл на чтение
		if (f.is_open()){ 
			T s; // переменная для данных на текущей строке
			T *arr = new T[n];
			while (f >> s){ // пока не считали все данные из файла
				arr[i] = s; // заполняем массив
				i++;
			}
			f.close();
			return arr; 
		}
	}
	template <typename T>
	void array_input_bin(){
		return 0;
	}
	/// Заполнение вектора v элементами типа T вручную
	template <typename T>
	void vect_input(vector<T> &v){
		for (int i = 0; i < v.size(); i++){
			cout << "Введите " << i+1 << "-й элемент массива ";
			cin >> v[i]; 
		}
	}
	/// Заполнение вектора v случайными числами типа T
	template <typename T>
	void vect_input_random(vector<T> &v){
		for (int i = 0; i < v.size(); i++){
			v[i] = rand() - 16383.5; // вектор заполняется случайными числами в диапазоне [-16383.5; 16383.5]
		}
	}
	/// Вывод элементов вектора v типа T на экран
	template <typename T>
	void vect_output(const vector<T> &v){
		for (int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
	}
	/// Возвращает сумму a1^2 + ... + an^2 n элементов типа T из вектора v
	template <typename T>
	double vect_calc(const vector<T> &v){
		T sum = 0.0; // переменная суммы
		for (int i = 0; i < v.size(); i++){
			sum += v[i] * v[i];
		}
		return sum;
	}
	/// Запись элементов типа T вектора v в файл с названием fname
	template <typename T>
	void vect_input_file(const vector<T> &v, const string &fname){
		ofstream f(fname); // Открываем файл на запись
		if (f.is_open()){ // Если файл открыт
			for (int i = 0; i < v.size(); i++){
			f << v[i]; // Записываем элементы вектора построчно
			f << endl;
			}
			f.close(); 
		}
	}
	/// Чтение элементов типа T из файла fname построчно, запись в вектор v
	template <typename T>
	void vect_output_file(vector<T> &v, const string &fname){
		ifstream f(fname); // Открываем файл на чтение
		if (f.is_open()){ 
			T s; // переменная для данных на текущей строке
			while (f>>s){ // пока не считали все данные из файла
				v.push_back(s); // Записываем в конец вектора
			}
			f.close(); 
		}
	}
}
/// Пространство имён с функциями для работы с массивами
namespace arrays{
	/// Возвращает количество элементов в файле fname
	size_t count_n(const string &fname);
}
