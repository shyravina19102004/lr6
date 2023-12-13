#pragma once

#include<math.h>
#include<string.h>
#include"../StackLib/Stack.h"
#include<ctype.h>
#include<cstdlib>
#include<fstream>

class Lexem
{
public: //интерфейс реализует различные типы лексем (операции или операнды) в математических выражениях
	virtual int prioritet() = 0; //Функция реализована в производных классах и возвращает приоритет операции или операнда
	virtual int getNumber() = 0; //Функция реализована в производных классах и возвращает значение числового операнда
	virtual Lexem* Calc(Lexem* a, Lexem* b) = 0; //Функция реализована в производных классах и выполняет вычисление операции над двумя операндами
};

class TNum : public Lexem //ащищенное поле data, которое представляет целочисленное значение
{
protected:
	int data;
public:
	TNum(int _d); //Конструктор принимает целочисленное значение и инициализирует поле data этим значением
	TNum(TNum& _d); //Конструктор копирования принимает объект типа TNum и создает новый объект, идентичный переданному
	TNum(char* s);//Конструктор принимает строку и преобразует ее в целочисленное значение, затем инициализирует поле data этим значением

	virtual int prioritet(); //Метод prioritet(), который возвращает приоритет операции типа TNum
	virtual int getNumber(); //Метод getNumber(), который возвращает целочисленное значение, хранящееся в поле data
	virtual Lexem* Calc(Lexem* a, Lexem* b); //принимает два указателя на объекты типа Lexem и выполняет вычисление на основе значения полей этих объектов. Возвращает указатель на объект типа Lexem, который представляет результат вычисления.
};

class TOper : public Lexem
{
protected:
	char data;
public: //объявляются два конструктора: TOper(char _d) и TOper(TOper& _d)
	TOper(char _d);
	TOper(TOper& _d);

	virtual int getNumber(); //виртуальная функция getNumber(), которая возвращает значение типа int
};


class TPlus : public TOper //операция сложения, определяет методы для получения приоритета операции и выполнения операции сложения
{
public:
	TPlus(char _d) : TOper(_d) {} //конструктор вызывает конструктор базового класса TOper и передает ему значение аргумента _d
	virtual int prioritet(); //виртуальная функция, которая возвращает приоритет операции
	virtual Lexem* Calc(Lexem* a, Lexem* b); //выполняет операцию сложения над двумя лексемами a и b и возвращает результат
};


class TSub : public TOper 
{
public:
	TSub(char _d) : TOper(_d) {} //определение класса TSub, который является наследником класса TOper
	virtual int prioritet(); //  возвращает целочисленное значение.определяет приоритет операции вычитания
	virtual Lexem* Calc(Lexem* a, Lexem* b); //принимает два указателя на объекты класса Lexem и возвращает указатель на объект класса Lexem. Функция предназначена для выполнения операции вычитания над операндами a и b
};

class TMultiplication : public TOper
{
public:
	TMultiplication(char _d) : TOper(_d) {} //Конструктор TMultiplication(char _d) инициализирует объект класса TMultiplication и вызывает конструктор базового класса TOper с аргументом _d
	virtual int prioritet(); //возвращает приоритет операции умножения
	virtual Lexem* Calc(Lexem* a, Lexem* b); //принимает два указателя на объекты класса Lexem и выполняет операцию умножения между ними, возвращая результат в виде указателя на объект класса Lexem
};

class TDivision : public TOper 
{
public:
	TDivision(char _d) : TOper(_d) {} //Класс TDivision имеет открытый (public) конструктор, который принимает символ _d и передает его в конструктор базового класса TOper
	virtual int prioritet(); //возвращает приоритет операции деления
	virtual Lexem* Calc(Lexem* a, Lexem* b); //Calc() принимает два операнда типа Lexem* и выполняет операцию деления над ними, возвращая результат также в виде объекта типа Lexem*
};

class TBracketOpen : public TOper
{
public:
	TBracketOpen(char _d) : TOper(_d) {} //Конструктор класса принимает символ открывающей скобки и передает его в конструктор базового класса TOper
	virtual int prioritet(); //возвращает приоритет операции
	virtual Lexem* Calc(Lexem* a, Lexem* b); //выполняет вычисления над двумя операндами a и b и возвращает результат
};

class TBracketClose : public TOper
{
public:
	TBracketClose(char _d) : TOper(_d) {}
	virtual int prioritet();
	virtual Lexem* Calc(Lexem* a, Lexem* b);
};

class TOperFactory
{
public:
	static void create(char* s, int& n, Lexem**& opers);
};

class TPolish //представляет обратную польскую запись и имеет статический метод Calculation(), который принимает строку s и возвращает результат вычисления выражения
{
public:
	static int Calculation(char* s);
};
