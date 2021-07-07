
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
    Set(int *, int);
    void getinput();
    int at(int);
    void display();
    int getcardinality();
    static bool ismember(int, Set *);
    static bool subset(Set *, Set *);
    static Set setUnion(Set *, Set *);
    static Set setIntersection(Set *, Set *);
	static Set complement(Set *);
    static Set difference(Set *, Set *);
    static Set symmetricdifference(Set *, Set *);
    static string cartesianproduct(Set *, Set *);
};


void clrscr();


void handleMenu(Set *, Set *);


int *insertionSort(int array[], int size)
{
    int i, j, k, key, iterCompCount, count = 0;
    for (i = 1; i < size; i++)
    {
        key = array[i];
        iterCompCount = 0;
        for (j = i - 1; j >= 0; j--)
        {
            count++;
            iterCompCount++;
            if (array[j] > key)
                array[j + 1] = array[j];
            else
                break;
        }
        array[j + 1] = key;
    }
    return array;
}


Set::Set(int size)
{
    this->size = size;
    this->ar = new int[this->size];
}


Set::Set(int *array, int size)
{
    this->size = size;
    this->ar = array;
}


void Set::getinput()
{
    cout << "Enter elements of the set: ";
    for (int i = 0; i < this->size; i++)
        cin >> this->ar[i];
}


void Set::display()
{
    cout << "{ ";
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


bool Set::subset(Set *X, Set *Y)
{
    int i = 0, j = 0;
    
    for (i = 0; i < Y->getcardinality(); i++)
    {
        
        for (j = 0; j < X->getcardinality(); j++)
            
            if (Y->at(i) == X->at(j))
                break;
        
        if (j == X->getcardinality())
            return false;
    }
    
    return true;
}


Set Set::setUnion(Set *X, Set *Y)
{
    
    int size = X->getcardinality() + Y->getcardinality();
    int i = 0, j = 0, k = 0, flag, *array = new int[size];
    
    for (i = 0; i < X->getcardinality();)
        array[k++] = X->at(i++);
    
    for (i = 0; i < Y->getcardinality(); i++)
    {
        flag = 1;
        for (j = 0; j < X->getcardinality(); ++j)
            if (Y->at(i) == X->at(j))
            {
                flag = 0;
                break;
            }
        if (flag)
            array[k++] = Y->at(i);
    }
    
    size = k;
    
    array = insertionSort(array, size);
    
    return Set(array, size);
}

Set Set::setIntersection(Set *X, Set *Y)
{
    
    int size = X->getcardinality() + Y->getcardinality();
    int p=1,i = 0, j = 0, k = 0, m=0, *array = new int[size],*array2 = new int[size];
    
    for (i = 0; i < X->getcardinality();i++)
    {
    	for (j=0;j<Y->getcardinality(); j++)
			{
				if (X->at(i) == Y->at(j) )
				{
					array[k]=X->at(i);
					k++; 
				}
			}
    }
    array2[m]=array[0];
    m++;
    for (int i=1;i<k;i++)
    {
    	int temp=array[i],p=1;
    	for(int j=0;j<m;j++)
    	{
    		if (temp == array[j])
    		p=0;
		}
		if (p==1)
		{
			array2[m]=temp;
			m++;
		}
	}
    
    size = m;
    
    array2 = insertionSort(array2, size);
    
    return Set(array2, size);
}





Set Set::complement(Set *s)
{
    
    int flag, max, size = 0, universeLen, *universe, *complement;
    
    max = s->at(0);
    for (int i = 1; i < s->getcardinality(); i++)
        if (s->at(i) > max)
            max = s->at(i);
    
    universe = new int[max + 1];
    for (universeLen = 0; universeLen < max; universeLen++)
        universe[universeLen] = universeLen + 1;
    
    complement = new int[universeLen];
    
    int *sorted = new int[s->getcardinality()];
    for (int k = 0; k < s->getcardinality(); k++)
        sorted[k] = s->at(k);
    sorted = insertionSort(sorted, s->getcardinality());
    
    int i = 0, j = 0;
    while (i < universeLen && j < s->getcardinality())
    {
        
        if (universe[i] < sorted[j])
        {
            complement[size++] = universe[i++];
        }
        
        else if (universe[i] > sorted[j])
        {
            j++;
        }
        
        else if (universe[i] == sorted[j])
        {
            i++;
            j++;
        }
    }
    
    return Set(complement, size);
}


Set Set::difference(Set *X, Set *Y)
{
    
    int size = 0, flag, *difference, *sortedX, *sortedY;
    
    int max = X->getcardinality() > Y->getcardinality() ? X->getcardinality() : Y->getcardinality();
    difference = new int[max];
    sortedX = new int[X->getcardinality()];
    sortedY = new int[Y->getcardinality()];
    
    for (int k = 0; k < X->getcardinality(); k++)
        sortedX[k] = X->at(k);
    for (int k = 0; k < Y->getcardinality(); k++)
        sortedY[k] = Y->at(k);
    sortedX = insertionSort(sortedX, X->getcardinality());
    sortedY = insertionSort(sortedY, Y->getcardinality());
    
    for (int i = 0; i < X->getcardinality(); i++)
    {
        flag = 0;
        
        for (int j = 0; j < Y->getcardinality(); j++)
        {
            
            if (sortedX[i] == sortedY[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        
        if (flag == 1)
        {
            difference[size++] = sortedX[i];
        }
    }
    
    return Set(difference, size);
}


Set Set::symmetricdifference(Set *X, Set *Y)
{
    
    int size = 0, flag, *symmetricdifference;
    
    int max = X->getcardinality() > Y->getcardinality() ? X->getcardinality() : Y->getcardinality();
    symmetricdifference = new int[max];
    
    for (int i = 0; i < X->getcardinality(); i++)
    {
        flag = 0;
        for (int j = 0; j < Y->getcardinality(); j++)
        {
            if (X->at(i) == Y->at(j))
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
            symmetricdifference[size++] = X->at(i);
    }

    for (int k = 0; k < Y->getcardinality(); k++)
    {
        flag = 0;
        for (int h = 0; h < X->getcardinality(); h++)
        {
            if (Y->at(k) == X->at(h))
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
            symmetricdifference[size++] = Y->at(k);
    }
    
    return Set(symmetricdifference, size);
}


string Set::cartesianproduct(Set *X, Set *Y)
{
    
    stringstream sout;
    sout << "{ ";
    for (int i = 0; i < X->getcardinality(); i++)
        for (int j = 0; j < Y->getcardinality(); j++)
            
            sout << "(" << X->at(i) << ", " << Y->at(j) << ")"
                 << ", ";
    sout << "\b\b }";
    
    return sout.str();
}

int main()
{
    Set *A, *B;
    handleMenu(A, B);
    return 0;
}

void handleMenu(Set *A, Set *B)
{
    int size, choice, flag = 1;

    cout << "Enter Size of Set A: ";
    cin >> size;
    A = new Set(size);
    A->getinput();

    cout << "Enter Size of Set B: ";
    cin >> size;
    B = new Set(size);
    B->getinput();

    while (flag)
    {
        clrscr();

        cout << "Set A: ";
        A->display();
        cout << endl;
        cout << "Set B: ";
        B->display();

        cout << "\n\n==== MENU ==================\n";
        cout << "  (1) Subset\n";
        cout << "  (2) Union\n";
        cout << "  (3) Intersection\n";
        cout << "  (4) Complement\n";
        cout << "  (5) Set Difference\n";
        cout << "  (6) Symmetric Difference\n";
        cout << "  (7) Cartesian Product\n";
        cout << "  (8) Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            bool subsetAB, subsetBA;

            subsetAB = Set::subset(B, A);
            subsetBA = Set::subset(A, B);

            if (subsetAB && subsetBA)
                cout << "A is equal to B" << endl;
            else if (subsetAB)
                cout << "A is a subset of B" << endl;
            else if (subsetBA)
                cout << "B is a subset of A" << endl;
            else
                cout << "A is not a subset of B\n"
                     << "B is not a subset of A\n";
            break;
        case 2:
            cout << "Union A U B: ";
            Set::setUnion(A, B).display();
            cout << endl;
            break;
        case 3:
            cout << "Intersection A n B: ";
            Set::setIntersection(A, B).display();
            cout << endl;
            break;
		case 4:
            cout << "Complement of A wrt U: ";
            Set::complement(A).display();
            cout << endl;
            cout << "Complement of B wrt U: ";
            Set::complement(B).display();
            cout << endl;
            break;
        case 5:
            cout << "Set Difference A - B: ";
            Set::difference(A, B).display();
            cout << endl;
            cout << "Set Difference B - A: ";
            Set::difference(B, A).display();
            cout << endl;
            break;
        case 6:
            cout << "Symmetric Difference A (+) B: ";
            Set::symmetricdifference(A, B).display();
            cout << endl;
            cout << "Symmetric Difference B (+) A: ";
            Set::symmetricdifference(B, A).display();
            cout << endl;
            break;
        case 7:
            cout << "Cartesian product A x B: "
                 << Set::cartesianproduct(A, B)
                 << endl;
            cout << "Cartesian product B x A: "
                 << Set::cartesianproduct(B, A)
                 << endl;
            break;
        case 8:
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

    delete A, B;
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
