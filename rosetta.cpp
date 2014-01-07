#include "rosetta.h"

class RPNParse
{
    public:
        stack<double> stk;
        multiset<int> digits;

        void op(function<double(double,double)> f)
        {
            if(stk.size() < 2)
                throw "Improperly written expression";
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            stk.push(f(a, b));
        }

        void parse(char c)
        {
            if(c >= '0' && c <= '9')
            {
                stk.push(c - '0');
                digits.insert(c - '0');
            }
            else if(c == '+')
                op([](double a, double b) {return a+b;});
            else if(c == '-')
                op([](double a, double b) {return a-b;});
            else if(c == '*')
                op([](double a, double b) {return a*b;});
            else if(c == '/')
                op([](double a, double b) {return a/b;});
        }

        void parse(string s)
        {
            for(unsigned int i = 0; i < s.size(); ++i)
                parse(s[i]);
        }

        double getResult()
        {
            if(stk.size() != 1)
                throw "Improperly written expression";
            return stk.top();
        }
};

void showMultisetInt(multiset<int> m)
{
    for(auto iter=m.begin(); iter!=m.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

multiset<int> rosetta()
{
    multiset<int> digits0;
    random_device seed;
    mt19937 engine(seed());
    uniform_int_distribution<> distribution(1, 9);
    auto rnd = bind(distribution, engine);

    // cout << "Make 24 with the digits0: ";
    for(int i = 0; i < 4; ++i)
    {
        int n = rnd();
        digits0.insert(n);
    }
    // cout << endl;
    return digits0;
}

bool correctness;

string judgeAns(string input, multiset<int> digits0)
{
    RPNParse parser;

    correctness = false;

    try
    {
        //string input;
        //getline(cin, input);
        parser.parse(input);

        if(digits0 != parser.digits)
        {
            // cout << "Error: Not using the given digits0" << endl;
            cout << "The input numbers are: ";
            showMultisetInt(parser.digits);
            cout << "The shown numbers are: ";
            showMultisetInt(digits0);
            return "\nError: Not using the given digits";
        }
        else
        {
            double r = parser.getResult();
            cout << "Result: " << r << endl;

            if(r > 23.999 && r < 24.001)
            {
                cout << "Good job!" << endl;
                correctness = true;
                return "\nGood job!";
            }
            else
            {
                cout << "Try again." << endl;
                return "\nWrong Answer.";
            }
        }
    }
    catch(char* e)
    {
        cout << "Error: " << e << endl;
        return "\nError";
    }
}

bool getCorrectness()
{
    return correctness;
}
