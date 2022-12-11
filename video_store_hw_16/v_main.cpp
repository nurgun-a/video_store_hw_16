#include "video_store.h"

void main()
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size = 10;

    video_store v1("Список_Шиндлера", "Драма", "Стивен_Спилберг", 9.1, 980.6);
    video_store v2("Джентельмены", "Криминал", "Гай_Ричи", 8.5, 550);
    video_store v3("Гнев_человеческий", "Боевик", "Гай_Ричи", 7.6, 870);
    video_store v4("Аватар", "Фантастика", "Джеймс_Кэмерон", 8.0, 2000.0);
    video_store v5("Интерстеллар", "Фантастика", "Кристофер_Нолан", 8.6, 399.0);
    video_store v6("Остров_проклятых", "Триллер", "Мартин_Скорсэзе", 8.5, 345.0);
    video_store v7("Титаник", "Мелодрама", "Джеймс_Кэмерон", 8.4, 675.6);
    video_store v8("Темный_рыцарь", "Фантастика", "Кристофер_Нолан", 8.5, 985.6);
    video_store v9("Область_тьмы", "Триллер", "Нил_Бергер", 3.5, 99.0);
    video_store v10("Легенда", "Криминал", "Брайан_Хелгеленд", 5.6, 199.0);

    video_store* v_all = new video_store[size]{ v1,v2,v3,v4,v5,v6,v7,v8,v9,v10 };

    vector <video_store> vv;
    vector <video_store> ::iterator it = vv.begin();

    for (int i = 0; i < size; i++)
    {
        vv.push_back(v_all[i]);
    } 

    bool b = 1;
    do
    {
        h();
        for (int i = 0; i < vv.size(); i++)
        {
            cout << setw(3) << i + 1 << " )"; vv[i].Print();
        }
        menu();
        char n; cout << "Enter: "; cin >> n;
        system("cls");
        try
        {
            if (n < '0' || n > '5')
            {
                throw n;
            }
            else
            {
                switch (n)
                {
                case '1':
                {
                    Sort(vv);
                }break;
                case '2':
                {
                    Search(vv);
                }break;
                case '3':
                {
                    Popular_film(vv);
                }break;
                case '4':
                {
                    Delete(vv, &size);
                }break;
                case '5':
                {
                    Add(vv, &size);
                }break;

                //case '6':
                //{
                //    int n = 0;
                //    cout << "1 - Записать\n2 - Считать" << endl;
                //    cin >> n;
                //    w_a_r(vv, "s", n);
                //}break;

                case '0':
                {
                    b = 0;
                }break;

                default:
                    break;
                }
            }
        }
        catch (char _n)
        {
            cout << "Некорректные данные, возобновите ввод" << endl;
        }
        
    } while (b);   

}