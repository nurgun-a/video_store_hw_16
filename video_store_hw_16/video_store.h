#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class video_store
{
protected:
	string Name;
	string Genre;
	string Derected;
	double Rating;
	double Price;
public:
	video_store();
	video_store(string _Name, string _Genre,
		string _Derected, double _Rating, double _Price);

	void Print();

	friend void Search(vector <video_store> films);
	friend void Sort(vector <video_store> &films);
	friend void Add(vector <video_store>& films, int* _size);
	friend void Delete(vector <video_store>& films, int* _size);
	friend void Popular_film(vector <video_store> films);
	friend ostream& operator << (ostream& os, video_store& v);
	friend istream& operator >> (istream& is, video_store& v);	

	friend void w_a_r(vector <video_store>& films, string s, int _n);
	void reading_all();
};
void h();
void menu();


