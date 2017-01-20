#pragma once

class Person : public Basket
{
public:
	string name;
	Person(string n = "") :Basket() { name = n; }
	void display() { cout << name; }
};

class Employee : public Person
{
public:
	int id;
	Employee(string empName, int empId) :Person(empName), id(empId) {}
	void display() override { cout << name << ":" << id; }
};

