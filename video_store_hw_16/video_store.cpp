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
    do
    {

        cout << "1 - По названию" << endl;
        cout << "2 - По жанру" << endl;
        cout << "3 - По режиссёру" << endl;
        cout << "4 - По рейтингу" << endl;
        cout << "5 - По цене" << endl;
        cout << "0 - Вернуться" << endl;

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
                        cout << "Введите название фильма: ";
                        cin >> Name; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Name == Name)
                            {                                
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;
                            }
                        }
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
                        cout << "Введите жанр: ";
                        cin >> Name; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Genre == Name)
                            {                                
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;
                            }
                        }
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
                        cout << "Введите фамилию режиссёра: ";
                        cin >> Name; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Derected == Name)
                            {                                
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;
                            }
                        }
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
                        cout << "Введите рейтинг фильма: ";
                        cin >> _Rating; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Rating >= _Rating)
                            {
                                cout << setw(5) << "  "; films[i].Print();
                                key_2 = 0;
                            }
                        }
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
                        cout << "Введите стоимость фильма: ";
                        cin >> _Price; cout << endl;
                        h();
                        for (int i = 0; i < films.size(); i++)
                        {
                            if (films[i].Price <= _Price)
                            {

                                cout << setw(5)  << "  "; films[i].Print();
                                key_2 = 0;
                            }
                        }
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
            cout << "Фильм не найден!" << endl;
            cout << "Возоновить поиск?" << endl;
            cout << "1 - да\n0 - нет" << endl;
            cin >> key_2;
        }
        catch (char n)
        {
            cout << "Введены некорректные данные, попробуйте снова: " << endl;
        }

    } while (key);
}

void Sort(vector <video_store> &films)
{
    bool key_2 = 1;
    char k2;
    do
    {

        cout << "1 - По названию" << endl;
        cout << "2 - По жанру" << endl;
        cout << "3 - По режиссёру" << endl;
        cout << "4 - По рейтингу" << endl;
        cout << "5 - По цене" << endl;
        cout << "0 - Вернуться" << endl;

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
            cout << "Некорректые данные, введите заново: " << endl;
        }
    } while (key_2);
}

void Add(vector <video_store>& films, int* _size)
{
    bool key;

    do
    {
        video_store tmp;
        cin >> tmp;
        films.push_back(tmp);
        system("cls");
        *_size += 1;
        cout << "Добавить еще?\n1 - да\n0 - нет" << endl;
        cin >> key;
    } while (key);

}

void Delete(vector <video_store>& films, int* _size)
{
    vector <video_store> ::iterator it = films.begin();
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
        cout << "\nВыберите из списка какой удалить: " << endl;
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
                advance(it, choice - 1);
                films.erase(it);
                key = 0;
                *_size -= 1;
            }
        }
        catch (int n)
        {
            cout << "Ошибка! Некорректные данные!" << endl;
            cout << "Возобновить ввод?\n1 - да\n0 - нет" << endl;
            cin >> key;
        }


    } while (key);
}

void Read_(string s)
{

    bool bb = 1;
    int size = 100;
    video_store* _films = new video_store[size]{};
    ifstream fin;


    try
    {
        string path="";
        if (s == "Sort")
        {
            //fin.open("Sort_films.txt");
            //if (!fin.is_open())
            //{
            //    throw bb;
            //}
            //else
            //{
            //    cout << "File open" << endl;
            //    int i = 0;               
            //    h();
            //    while (fin.read((char*)&_films[i], sizeof(video_store)))
            //    {
            //        cout << setw(3) << i + 1 << ")"; _films[i].Print();
            //        i++;
            //    }
            //}
            path = "Sort_films.txt";
        }
        else if (s == "Search")
        {
            path = "Search_films.txt";
        }
        else
        {
            path = "films.txt";
        }

        fin.open(path);

        if (!fin.is_open())
        {
            throw bb;
        }
        else
        {
            cout << "File open" << endl;
            int i = 0;

            while (fin.read((char*)&_films[i], sizeof(video_store)))
            {
                _films[i].Print();
            }

        }
    }

    catch (bool b)
    {
        cout << "Ошибка, не удалось открыть файл!!!" << endl;
    }

    fin.close();
    delete[]_films;
    
    cout << "End read" << endl;
}

void Write(vector <video_store> &films, int _size, string s)
{
    bool bb = 1;
    ofstream fout;
    try
    {
        if (s == "Sort")
        {
            fout.open("Sort_films.txt", ofstream::app);
            if (!fout.is_open()) throw bb;

            else
            {
                for (int i = 0; i < films.size(); i++)
                {
                    fout.write((char*)&films[i], sizeof(video_store));
                }
            }
        }
        else if (s == "Search")
        {
            fout.open("Search_films.txt", ofstream::app);

            if (!fout.is_open()) throw bb;

            else
            {
                fout.write((char*)&films, sizeof(video_store));
            }
        }
        else
        {
            fout.open("films.txt", ofstream::out);

            if (!fout.is_open())  throw bb; 

            else
            {
                for (int i = 0; i < films.size(); i++)
                {
                    fout.write((char*)&films[i], sizeof(video_store));

                }
            }
        }
    }

    catch (bool b)
    {
        cout << "Ошибка, не удалось открыть файл!!!" << endl;
    }

    fout.close();
    cout << "End of write" << endl;
    //system("person_all.txt");
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

    cout << "Самый популярный фильм:  \n" << endl;
    cout << "     "; tmp.Print(); cout << endl << endl;
    //delete &tmp;
}

ostream& operator<< (ostream& os, video_store& v)
{
    os  << v.Name  << v.Genre  << v.Derected << v.Rating << v.Price << endl;

    return os;
}

istream& operator >> (istream& is, video_store& v)
{
    cout << "Введите название фильма: ";
    is >> v.Name;
    cout << endl;
    cout << "Введите жанр фильма: ";
    is >> v.Genre;
    cout << endl;
    cout << "Введите фамилию режиссёра: ";
    is >> v.Derected;
    cout << endl;
    cout << "Введите рейтинг фильма: ";
    is >> v.Rating;
    cout << endl;
    cout << "Введите цену: ";
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
    else
    {
        path = "films.txt";
    }

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    try
    {
        if (!fs.is_open())
        {
            throw 5;
        }
        else
        {
            cout << "Файл открыт" << endl;
            if (_n==1)
            {
                for (int i = 0; i < films.size(); i++)
                {
                    fs.write((char*)&films[i], sizeof(video_store));
                }
            }
            else if (_n==2)
            {
                int size = 100;
                video_store* _films = new video_store[size]{};
                int i = 0;
                while (fs.read((char*)&_films[i], sizeof(video_store)))
                {
                    _films[i].Print();
                    i++;
                }
                delete[]_films;
            }


        }
        fs.close();
    }

    
    catch (int n)
    {
        cout << "Ошибка открытия файла!!!" << endl;
    }
}

void h()
{
    cout << "  ----------------------------------------------------------------------------" << endl;
    cout << setw(28) << "Название  |" << setw(12) << "Жанр  |" << setw(20) << "Режиссёр   |" <<
        setw(9) << "Рейтинг |" << setw(10) << "Цена  |" << endl;
    cout << "  ----------------------------------------------------------------------------" << endl;
}

void menu()
{
    cout << "1 - Сортировка" << endl;
    cout << "2 - Поиск" << endl;
    cout << "3 - Самый популярный в жанре" << endl;
    cout << "4 - Удалить" << endl;
    cout << "5 - Добавить" << endl;
    //cout << "6 - Считать и записать" << endl << endl;
    cout << "0 - Выход" << endl ;


    //cout << "Считать" << endl;
    //cout << "Записать" << endl;
}
