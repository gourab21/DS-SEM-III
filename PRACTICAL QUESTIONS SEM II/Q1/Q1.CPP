
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Set
{
private:
    int *ar, size;

public:
    Set(int);
    void getinput();
    int at(int);
    void display();
    int getcardinality();
    static bool ismember(int, Set *);
    static string powerset(Set *);
};


void clrscr();


void handleMenu(Set *);


Set::Set(int size)
{
    this->size = size;
    this->ar = new int[this->size];
}


void Set::getinput()
{
    cout << "Enter elements of the set: ";
    for (int i = 0; i < this->size; i++)
        cin >> this->ar[i];
}


void Set::display()
{
    cout << "Set A: { ";
    for (int i = 0; i < this->size; i++)
    {
        cout << this->ar[i];
        if (i == size - 1)
            cout << " ";
        else
            cout << ", ";
    }
    cout << "}";
}


int Set::at(int i)
{
    return this->ar[i];
}


int Set::getcardinality()
{
    return this->size;
}


bool Set::ismember(int el, Set *s)
{
    
    for (int i = 0; i < s->getcardinality(); i++)
    {
        
        if (el == s->at(i))
            return true;
    }
    return false;
}


string Set::powerset(Set *s)
{
    
    stringstream sout;

    
    unsigned int size = s->getcardinality();
    unsigned int count = pow(2, size);

    
    sout << "{\n {},\n ";

    
    for (int i = 1; i < count; i++)
    {
        sout << "{";
        for (int j = 0; j < size; j++)
           
            if (i & (1 << j))
                sout << s->at(j) << ",";
        sout << "\b}";
        if (i < count - 1)
            sout << ",\n ";
    }
    sout << "\n}";

    
    return sout.str();
}

int main()
{
    Set *A;
    handleMenu(A);
    return 0;
}

void handleMenu(Set *A)
{
    int el, size, choice, flag = 1;

    cout << "Enter Size of Set: ";
    cin >> size;

    A = new Set(size);
    A->getinput();

    while (flag)
    {
        clrscr();

        A->display();

        cout << "\n\n==== MENU ==================\n";
        cout << "  (1) Get Cardinality\n";
        cout << "  (2) Check Membership\n";
        cout << "  (3) Display Powerset\n";
        cout << "  (4) Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Cardinality of A: ";
            cout << A->getcardinality();
            cout << endl;
            break;
        case 2:
            cout << "Enter Element to Check: ";
            cin >> el;
            cout << "Result: " << el;
            if (Set::ismember(el, A))
                cout << " is a member of A";
            else
                cout << " is not a member of A";
            cout << endl;
            break;
        case 3:
            cout << "Powerset of A:\n";
            cout << Set::powerset(A);
            cout << endl;
            break;
        case 4:
            flag = 0;
            break;
        default:
            cout << "Invalid Option";
            break;
        }

        if (flag)
        {
            cout << "\nPress Enter to Continue... ";
            cin.sync();
            cin.get();
        }
    }

    delete A;
    return;
}

void clrscr()
{
#ifdef _WIN32
    system("cls");
#elif __unix__
    system("clear");
#endif
}
