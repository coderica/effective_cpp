#include <iostream>
#include <fstream>
#include <string>
#include <strstream>
#include <list>
#include <map>
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
	Student(string name = "");
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

Student::Student(string name) :first(""), middle(""), last("")
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
	last = names.at(names.size() - 1);
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
	srand(static_cast<unsigned int>(time(0)));
	list<Student> students;
	ifstream fin("students.txt");

	cout << "Reading students\n";
	while (!fin.eof())
	{
		getline(fin, line);
#if 0 // one way
		Student s(line);
		students.push_back(s);
#else // another way
		students.emplace_back(line);
#endif
	}

	students.sort();

	cout << "\n\nDisplay list of students sorted by last name\n\n";
	for (auto it = students.begin(); it != students.end(); it++)
		cout << *it << endl;

	priority_queue<PriorityStudent> prioritizedStudents;

	cout << "\n\nAssign lottery pick and put students in priorty queue\n\n";
	for (auto it = students.begin(); it != students.end(); it++)
	{
		nrand = static_cast<int>(floor(rand() % 1000));
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


/////////////////////// PART 2 /////////////////////////


double rpnEval(string formula);

void part2()
{
	string formula1 = "3 5 +",			//3 + 5
		formula2 = "3 2 9 + *",		// 3 * (2 + 9)
		formula3 = "10 8 - 16 6 - /"; // (10-8) / (16-6)

	try
	{
		cout << "The result of: " << formula1 << " is: " << rpnEval(formula1) << " (expected 8)" << endl;
	}
	catch (string error)
	{
		cout << error << endl;
	}

	try
	{
		cout << "The result of: " << formula2 << " is: " << rpnEval(formula2) << " (expected 33)" << endl;
	}
	catch (string error)
	{
		cout << error << endl;
	}

	try
	{
		cout << "The result of: " << formula3 << " is: " << rpnEval(formula3) << " (expected 0.2)" << endl;
	}
	catch (string error)
	{
		cout << error << endl;
	}
}

enum eOperator
{
	kOp_Add = 0,
	kOp_Subtract,
	kOp_Multiply,
	kOp_Divide,
	kOp_Invalid,
	kOp_Num = kOp_Invalid
};

eOperator isOperator(const string& token)
{

	if (token.size() == 1)
		// Could also test with:
		//	if (token.find_first_of("+-*/") != string::npos)
	{
		switch (token[0])
		{
		case '+':
			return kOp_Add;
			break;
		case '-':
			return kOp_Subtract;
			break;
		case '*':
			return kOp_Multiply;
			break;
		case '/':
			return kOp_Divide;
			break;
		}
	}
	return kOp_Invalid;
}

double operatorAdd(double param1, double param2)
{
	return param1 + param2;
}
double operatorSubtract(double param1, double param2)
{
	return param2 - param1;
}
double operatorMultiply(double param1, double param2)
{
	return param1 * param2;
}
double operatorDivide(double param1, double param2)
{
	return param2 / param1;
}

typedef double(*tOperatorFunc)(double param1, double param2);

#if 1 // Solution using arrays

tOperatorFunc s_OperatorTable[kOp_Num] =
{
	operatorAdd,		// kOp_Add
	operatorSubtract,	// kOp_Subtract
	operatorMultiply,	// kOp_Multiply
	operatorDivide		// kOp_Divide
};

#else // Solution using std::map
map<eOperator, tOperatorFunc> s_OperatorTable =
{
	std::make_pair(kOp_Add, operatorAdd),
	std::make_pair(kOp_Subtract, operatorSubtract),
	std::make_pair(kOp_Multiply, operatorMultiply),
	std::make_pair(kOp_Divide, operatorDivide)
};
#endif
void applyOperator(eOperator op, stack<double>& formulaStack)
{
	double result;
	double op1, op2;

	op1 = formulaStack.top(); formulaStack.pop();
	op2 = formulaStack.top(); formulaStack.pop();

	tOperatorFunc opFunc = s_OperatorTable[op];
	result = (*opFunc)(op1, op2);
	formulaStack.push(result);
}

void applyToken(stack<double>& formulaStack, const string& token)
{
	eOperator op = isOperator(token);
	if (op != kOp_Invalid)
	{
		applyOperator(op, formulaStack);
	}
	else
	{
		double param = stod(token);
		formulaStack.push(param);
	}
}

#if 1 // Using istrtream
double rpnEval(string formula)
{
	stack<double> formulaStack;
	istrstream istrstream(formula.c_str());

	while (!istrstream.eof())
	{
		string token;
		istrstream >> token;
		applyToken(formulaStack, token);
	}

	if (formulaStack.size() > 1)
	{
		// Some sort of error occurred.
		throw string("Error! Invalid Formula: ") + formula;
	}
	return formulaStack.top();
}
#else // Using std::string only
double rpnEval(string formula)
{
	int pos;
	stack<double> formulaStack;

	while (formula != "")
	{
		string token;

		pos = formula.find(' ');
		if (pos == string::npos) pos = formula.size();
		token = formula.substr(0, pos);

		applyToken(formulaStack, token);
	}

	if (formulaStack.size() > 1)
	{
		// Some sort of error occurred.
		throw string("Error! Invalid Formula: ") + formula;
	}
	return formulaStack.top();
}


string strOperand, strOperator, token;
int pos;
stack<string> formulaStack;
while (formula != "")
{
	pos = formula.find(' ');
	if (pos == string::npos) pos = formula.size();
	token = formula.substr(0, pos);
	formula.erase(0, pos + 1);
	if (token.find_first_of("+-*/") == string::npos)  //not an operator
		formulaStack.push(token);
	else


#endif

		int main()
	{
		cout << "-=-=-=-=-=-=-=-=- PART 1 -=-=-=-=-=-=-=-=-" << endl << endl;
		part1();
		cout << endl << "-=-=-=-=-=-=-=-=- PART 2 -=-=-=-=-=-=-=-=-" << endl << endl;
		part2();
		return 0;
	}


