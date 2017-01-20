#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
	string name;
	int age;
	string animalType;
public:
	Animal(string _name = "", int _age = 0) :name(_name), age(_age),animalType("unknown") {}
	virtual void speak() = 0;
	virtual void move() = 0;
};

class PlayfulAnimal:public Animal
{
	string toy;
public:
	PlayfulAnimal(string _name, int _age, string _toy) :Animal(),toy(_toy) {}
	virtual void play() { cout << "The " << animalType << " is playing with the " << toy << endl;  }
};

class Dog :public PlayfulAnimal
{
	string toy;
public:
	Dog(string _name, int _age, string _toy) :PlayfulAnimal(_name, _age, _toy) { animalType="dog"; }
	void speak() override { cout << "The dog barks\n"; }
	void move() override { cout << "The dog runs\n"; }
};

class Cat :public PlayfulAnimal
{
	string toy;
public:
	Cat(string _name, int _age, string _toy) :PlayfulAnimal(_name, _age, _toy) { animalType = "cat"; }
	void speak() override { cout << "The cat meows\n"; }
	void move() override { cout << "The cat pounces\n"; }
};

class Fish : public Animal
{
public:
	Fish(string _name, int _age) :Animal(_name, _age ) { animalType = "fish"; }
	void speak()  override { cout << "The fish says nothing\n"; }
	void move() override  { cout << "The fish is swimming\n"; }
};

int main()
{
	int i;
	Dog d1("fido", 4, "chew toy");
	Cat c1("fluffy", 2, "mouse");
	Fish f1("nemo", 1);

	Animal *allAnimals[3] = { &d1, &c1, &f1 };

	for (i = 0; i < 3; i++)
	{
		allAnimals[i]->speak();
	}

	cout << endl;

/*	Animal *playAnimals[2] = { &d1, &c1 };

	for (i = 0; i < 2; i++)
	{
		playAnimals[i]->speak();
		playAnimals[i]->play();
	}
*/
	return 0;
}