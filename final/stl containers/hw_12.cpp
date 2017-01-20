#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>

using namespace std;

class Student {
	string first;
	string middle;
	string last;
public:
	Student(string name="");
	Student(const Student &s);
	virtual bool operator < (const Student & s) const;
	friend ostream & operator << (ostream &out, const Student &s);
};

class PriorityStudent : public Student
{
	int priorityNumber;
public:
	PriorityStudent(string name, int number) :Student(name), priorityNumber(number) {}
	PriorityStudent(const Student &s, int number) :Student(s), priorityNumber(number) {}
	bool operator < (const PriorityStudent & ps) const { return this->priorityNumber < ps.priorityNumber; }
	friend ostream & operator << (ostream &out, const PriorityStudent &s);
};

Student::Student(string name):first(""), middle(""), last("")
{
	unsigned int pos;
	vector<string> names;
	if (name == "") return;
	string temp = name;
	while (temp != "")
	{
		pos = temp.find(' ');
		if (pos == string::npos) pos = temp.size();
		names.push_back(temp.substr(0, pos));
		temp = temp.erase(0, pos + 1);
	}
	first = names[0];
	if (names.size() == 3)
		middle = names[1];
	last = names.at(names.size()-1);
}

Student::Student(const Student &s) :first(s.first), middle(s.middle), last(s.last)
{ }

bool Student::operator < (const Student & s) const
{
	return this->last < s.last;
}

ostream & operator << (ostream &out, const Student &s)
{
	if (s.middle != "")
		out << s.first << " " << s.middle << " " << s.last;
	else
		out << s.first << " " << s.last;
	return out;
}

ostream & operator << (ostream &out, const PriorityStudent &s)
{
	out << static_cast<Student>(s);
	out << " (Priority: " << s.priorityNumber << ")";
	return out;
}


void part1()
{
	string line;
	int nrand;
	srand(time(0));
	list<Student> students;
	ifstream fin("hw12names.txt");

	cout << "Reading students\n";
	while (!fin.eof())
	{
		getline(fin, line);
		//Student s(line);
		students.emplace_back(line);
	}
	
	students.sort();

	cout << "\n\nDisplay list of students sorted by last name\n\n";
	for (auto it = students.begin(); it != students.end(); it++)
		cout << *it << endl;

	priority_queue<PriorityStudent> prioritizedStudents;

	cout << "\n\nAssign lottery pick and put students in priorty queue\n\n";
	for (auto it = students.begin(); it != students.end(); it++)
	{
		nrand = floor(rand() % 1000);
		PriorityStudent ps(*it, nrand);
		prioritizedStudents.push(ps);
	}

	cout << "\n\nDisplay students with highest priority\n";
	for (int i = 0; i <= 5 && !prioritizedStudents.empty(); i++)
	{
		cout << prioritizedStudents.top() << endl;
		prioritizedStudents.pop();
	}
	
}


string rpnEval(string formula);

void part2()
{
	string formula1 = "3 5 +",			//3 + 5
		   formula2 = "3 2 9 + *",		// 3 * (2 + 9)
		   formula3 = "10 8 - 16 6 - /"; // (10-8) / (16-6)
	cout << "The result of: " << formula1 << " is: " << rpnEval(formula1) << endl;
	cout << "The result of: " << formula2 << " is: " << rpnEval(formula2) << endl;
	cout << "The result of: " << formula3 << " is: " << rpnEval(formula3) << endl;

}


string rpnEval(string formula)
{
	string strOperand, strOperator, token;
	int pos;
	stack<string> formulaStack;
	while (formula != "")
	{
		pos = formula.find(' ');
		if (pos == string::npos) pos = formula.size();
		token = formula.substr(0, pos);
		formula.erase(0, pos+1);
		if (token.find_first_of("+-*/") == string::npos)  //not an operator
			formulaStack.push(token);
		else
		{
			string strOp1, strOp2;
			double op1, op2, result;
			strOp1 = formulaStack.top(); formulaStack.pop();
			strOp2 = formulaStack.top(); formulaStack.pop();
			op1 = stod(strOp1);
			op2 = stod(strOp2);
			if (token == "+")
			{
				result = op1 + op2;
				formulaStack.push(to_string(result));
			}
			else if (token == "-")
			{
				result = op2 - op1;
				formulaStack.push(to_string(result));
			}
			else if (token == "*")
			{
				result = op1 * op2;
				formulaStack.push(to_string(result));
			}
			else // token == "/"
			{
				result = op2 / op1;
				formulaStack.push(to_string(result));
			}
		}  //end token is operator
	} //end formula has coontent
	return formulaStack.top();
}

int main()
{
	part1();
	//part2();
	return 0;
}