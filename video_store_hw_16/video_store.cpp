#include "video_store.h"

video_store::video_store()
{
    Name = "";
    Genre = "";
    Derected = "";
    Rating = 0;
    Price = 0;
}

video_store::video_store(string _Name, string _Genre,
    string _Derected, double _Rating, double _Price)
{
    Name = _Name;
    Genre = _Genre;
    Derected = _Derected;
    Rating = _Rating;
    Price = _Price;
}

void video_store::Print()
{
    cout << setw(20) << Name << setw(12) << Genre << setw(20) << Derected <<
        setw(9) << Rating << setw(10) << Price << endl;
}

void Search(vector <video_store> films)
{
    char n = 0;
    bool key_2 = 1;
    bool key = 1;
    string Name;
    string home;
    vector <video_store> tmp;
    do
    {

        cout << "1 - �� ��������" << endl;
        cout << "2 - �� �����" << endl;
        cout << "3 - �� ��������" << endl;
        cout << "4 - �� ��������" << endl;
        cout << "5 - �� ����" << endl;
        cout << "0 - ���������" << endl;

        try
        {
            cin >> n;
            system("cls");
            if (n > '5' || n < '0')
            {
                throw n;
            }
            else
            {
                switch (n)
                {
                case '1':
                {
                    key_2 = 1;
                    do
                    {
                        cout << "������� �������� ������: ";
                        cin >> Name; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Name == Name)
                            {                                
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;  
                                tmp.push_back(films[i]);
                            }
                        }
                        w_a_r(tmp, "Search", 1);
                        tmp.clear();
                        if (key_2 != 0)
                        {
                            throw 5;
                        }
                    } while (key_2);
                }
                break;
                case '2':
                {
                    key_2 = 1;
                    do
                    {
                        cout << "������� ����: ";
                        cin >> Name; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Genre == Name)
                            {                                
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;
                                tmp.push_back(films[i]);
                            }
                        }
                        w_a_r(tmp, "Search", 1);
                        tmp.clear();
                        if (key_2 != 0)
                        {
                            throw 5;
                        }
                    } while (key_2);
                }
                break;
                case '3':
                {
                    key_2 = 1;
                    do
                    {
                        cout << "������� ������� ��������: ";
                        cin >> Name; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Derected == Name)
                            {                                
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;
                                tmp.push_back(films[i]);
                            }
                        }
                        w_a_r(tmp, "Search", 1);
                        tmp.clear();
                        if (key_2 != 0)
                        {
                            throw 5;
                        }
                    } while (key_2);
                }
                break;
                case '4':
                {
                    key_2 = 1;
                    do
                    {
                        int _Rating = 0;
                        cout << "������� ������� ������: ";
                        cin >> _Rating; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Rating >= _Rating)
                            {
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;
                                tmp.push_back(films[i]);
                            }
                        }
                        w_a_r(tmp, "Search", 1);
                        tmp.clear();
                        if (key_2 != 0)
                        {
                            throw 5;
                        }
                    } while (key_2);
                }
                break;
                case '5':
                {
                    key_2 = 1;
                    do
                    {
                        double _Price = 0;
                        cout << "������� ��������� ������: ";
                        cin >> _Price; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Price <= _Price)
                            {

                                cout << setw(5)  << "  "; films[i].Print();
                                key_2 = 0;
                                tmp.push_back(films[i]);
                            }
                        }
                        w_a_r(tmp, "Search", 1);
                        tmp.clear();
                        if (key_2 != 0)
                        {
                            throw 5;
                        }
                    } while (key_2);
                }
                break;
                case '0':
                {
                    key = 0;
                }
                break;

                default:
                    break;
                }
            }

        }
        catch (int n)
        {
            cout << "����� �� ������!" << endl;
            cout << "���������� �����?" << endl;
            cout << "1 - ��\n0 - ���" << endl;
            cin >> key_2;
        }
        catch (char n)
        {
            cout << "������� ������������ ������, ���������� �����: " << endl;
        }

    } while (key);
}

void Sort(vector <video_store> &films)
{
    bool key_2 = 1;
    char k2;
    do
    {

        cout << "1 - �� ��������" << endl;
        cout << "2 - �� �����" << endl;
        cout << "3 - �� ��������" << endl;
        cout << "4 - �� ��������" << endl;
        cout << "5 - �� ����" << endl;
        cout << "0 - ���������" << endl;

        try
        {
            cin >> k2;
            system("cls");
            if (k2 > '5' || k2 < '0')
            {
                throw k2;
            }
            else
            {
                switch (k2)
                {
                case '1':
                {
                    h();
                    for (int i = 0; i < films.size(); i++)
                        for (int j = i + 1; j < films.size(); j++)
                            if (films[i].Name > films[j].Name)
                            {
                                swap(films[i], films[j]);
                            }

                    for (int i = 0; i < films.size(); i++)
                    {
                        cout << setw(3) << i + 1 << " )"; films[i].Print();
                        Sleep(100);
                    }

                    w_a_r(films, "Sort", 1);
                }
                break;
                case '2':
                {
                    h();
                    for (int i = 0; i < films.size(); i++)
                        for (int j = i + 1; j < films.size(); j++)
                            if (films[i].Genre > films[j].Genre)
                            {
                                swap(films[i], films[j]);
                            }
                    for (int i = 0; i < films.size(); i++)
                    {
                        cout << setw(3) << i + 1 << " )"; films[i].Print();
                        Sleep(100);
                    }
                    w_a_r(films, "Sort", 1);
                }
                break;
                case '3':
                {
                    h();
                    for (int i = 0; i < films.size(); i++)
                        for (int j = i + 1; j < films.size(); j++)
                            if (films[i].Derected > films[j].Derected)
                            {
                                swap(films[i], films[j]);
                            }
                    for (int i = 0; i < films.size(); i++)
                    {
                        cout << setw(3) << i + 1 << " )"; films[i].Print();
                        Sleep(100);
                    }
                    w_a_r(films, "Sort", 1);
                }
                break;
                case '4':
                {
                    h();
                    for (int i = 0; i < films.size(); i++)
                        for (int j = i + 1; j < films.size(); j++)
                            if (films[i].Rating < films[j].Rating)
                            {
                                swap(films[i], films[j]);
                            }
                    for (int i = 0; i < films.size(); i++)
                    {
                        cout << setw(3) << i + 1 << " )"; films[i].Print();
                        Sleep(100);
                    }
                    w_a_r(films, "Sort", 1);
                }
                break;
                case '5':
                {
                    h();
                    for (int i = 0; i < films.size(); i++)
                        for (int j = i + 1; j < films.size(); j++)
                            if (films[i].Price < films[j].Price)
                            {
                                swap(films[i], films[j]);
                            }
                    for (int i = 0; i < films.size(); i++)
                    {
                        cout << setw(3) << i + 1 << " )"; films[i].Print();
                        Sleep(100);
                    }
                    w_a_r(films, "Sort", 1);
                }
                break;
                case '0':
                {
                    key_2 = 0;
                }
                break;
                default:
                    break;
                }
            }
        }
        catch (char n)
        {
            cout << "����������� ������, ������� ������: " << endl;
        }
    } while (key_2);
}

void Add(vector <video_store>& films, int* _size)
{
    bool key;
    vector <video_store> tmp1;
    do
    {
        video_store tmp;
        cin >> tmp;
        films.push_back(tmp);
        system("cls");
        *_size += 1;

        tmp1.push_back(tmp);
        w_a_r(tmp1, "Add", 1);
        tmp1.clear();

        cout << "�������� ���?\n1 - ��\n0 - ���" << endl;
        cin >> key;
    } while (key);

}

void Delete(vector <video_store>& films, int* _size)
{
    vector <video_store> ::iterator it = films.begin();
    vector <video_store> tmp;
    int choice = 0;
    bool key = 1;
    do
    {
        h();
        for (int i = 0; i < films.size(); i++)
        {
            cout << setw(3) << i + 1 << " )"; films[i].Print();
            Sleep(100);
        }
        cout << "\n�������� �� ������ ����� �������: " << endl;
        cin >> choice;
        system("cls");
        cout << endl;
        try
        {
            if (choice < 0 || choice > *_size)
            {
                throw choice;
            }
            else
            {
                tmp.push_back(films[choice-1]);
                w_a_r(tmp, "Delete", 1);
                tmp.clear();
                advance(it, choice - 1);
                films.erase(it);
                key = 0;
                *_size -= 1;
            }
        }
        catch (int n)
        {
            cout << "������! ������������ ������!" << endl;
            cout << "����������� ����?\n1 - ��\n0 - ���" << endl;
            cin >> key;
        }


    } while (key);
}

void Popular_film(vector <video_store> films)
{

    video_store  tmp = films[0];
    for (int i = 0; i < films.size(); i++)
    {
        if (tmp.Rating < films[i].Rating)
        {
            swap(tmp, films[i]);
        }
    }
    cout << "------------------------------------------------------------------------" << endl;

    cout << "����� ���������� �����:  \n" << endl;
    cout << "     "; tmp.Print(); cout << endl << endl;
    //delete &tmp;
}

ostream& operator<< (ostream& os, video_store& v)
{
    os  <<setw(20)<< v.Name << setw(15) << v.Genre << setw(20) << v.Derected 
        << setw(6) << v.Rating << setw(8) << v.Price << endl;

    return os;
}

istream& operator >> (istream& is, video_store& v)
{
    cout << "������� �������� ������: ";
    is >> v.Name;
    cout << endl;
    cout << "������� ���� ������: ";
    is >> v.Genre;
    cout << endl;
    cout << "������� ������� ��������: ";
    is >> v.Derected;
    cout << endl;
    cout << "������� ������� ������: ";
    is >> v.Rating;
    cout << endl;
    cout << "������� ����: ";
    is >> v.Price;
    cout << endl;

    return is;
}

void w_a_r(vector<video_store>& films, string s, int _n)
{
    string path = "";
    if (s=="Sort")
    {
        path = "Sort_films.txt";
    }
    else if (s == "Search")
    {
        path = "Search_films.txt";
    }
    else if (s == "Delete")
    {
        path = "Delete_film.txt";
    }
    else if (s == "Add")
    {
        path = "Add_film.txt";
    }
    else
    {
        path = "films.txt";
    }

    try
    {

        if (_n==1)
        {
             ofstream fz;
             if (path == "films.txt")
                 fz.open(path, ofstream::out);
             else
                 fz.open(path, ofstream::app);

             if (!fz.is_open())
                 throw 5;
              else
              {
                  cout << "���� ������" << endl;
                  for (auto it = films.begin(); it != films.end(); it++)
                      fz << *it;
                  cout << "���� �������" << endl;
              }
              fz.close(); 
        }
        else if (_n==2)
        {
            ifstream is;
            is.open(path);
            if (!is.is_open())
                throw 5;
            else
            {
                cout << "���� ������" << endl;
                video_store tmp1;
                while (is >> tmp1.Name >> tmp1.Genre >> tmp1.Derected >>
                    tmp1.Rating >> tmp1.Price)
                {
                    films.push_back(tmp1);
                }
                is.close();
            }
        }

    }

    
    catch (int n)
    {
        cout << "������ �������� �����!!!" << endl;
    }
}

void h()
{
    cout << "  ----------------------------------------------------------------------------" << endl;
    cout << setw(28) << "��������  |" << setw(12) << "����  |" << setw(20) << "�������   |" <<
        setw(9) << "������� |" << setw(10) << "����  |" << endl;
    cout << "  ----------------------------------------------------------------------------" << endl;
}

void menu()
{
    cout << "1 - ����������" << endl;
    cout << "2 - �����" << endl;
    cout << "3 - ����� ���������� � �����" << endl;
    cout << "4 - �������" << endl;
    cout << "5 - ��������" << endl;
    cout << "6 - ������� � ��������" << endl ;
    cout << "7 - ������� ��� �����" << endl << endl;
    cout << "0 - �����" << endl ;


    //cout << "�������" << endl;
    //cout << "��������" << endl;
}

void  video_store::reading_all()
{
    vector<video_store> tmp;
    string path = "";

    try
    {
        h();
        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                path = "Sort_films.txt";
            }
            else if (i == 1)
            {
                path = "Search_films.txt";
            }
            else if (i == 2)
            {
                path = "Delete_film.txt";
            }
            else if (i == 3)
            {
                path = "Add_film.txt";
            }
            else
            {
                path = "films.txt";
            }

            ifstream is;
            is.open(path);
            if (!is.is_open())
            {
                throw 5;
            }
            else
            {
                cout << "-------------------------------------------------------" << endl;
                video_store tmp1;
                while (is >> tmp1.Name >> tmp1.Genre >> tmp1.Derected >>
                    tmp1.Rating >> tmp1.Price)
                {
                    tmp.push_back(tmp1);
                }
                is.close();
                if (i == 0)		 cout << "����������:" << endl << endl;
                else if (i == 1) cout << "�����:" << endl << endl;
                else if (i == 2) cout << "��������:" << endl << endl;
                else if (i == 3) cout << "����������:" << endl << endl;
                else			 cout << "��� ������:" << endl << endl;

                for (int i = 0; i < tmp.size(); i++)
                {
                    tmp[i].Print();
                }
                cout << "-------------------------------------------------------" << endl;
                tmp.clear();
            }
        }
    }
    catch (int n)
    {
        cout << "������ ������!!!" << endl;
    }
}
