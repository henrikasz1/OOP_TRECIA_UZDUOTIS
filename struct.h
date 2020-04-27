//#define pragma once
#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

using namespace std;


/*                             IKI V1.0 versijos
struct student{
  string name;//vardas
  string lastName;//pavarde
  int egz;//egzamino rezultatai
  double median;//naudojamas medianos isvedimui
  double average;//naudojamas vidurkio isvedimui
  int m=0; //namu darbu rezultatu kiekis
  vector<int> A; //vektorius, kuriame bus saugojami namu darbu rezultatai
};//struktura

#endif // STRUCT_H_INCLUDED
*/

class student {                         //struct to class to conform V1.1 version
private:
    string name;//vardas
    string lastName;//pavarde
    int egz;//egzamino rezultatas
    double median;
    double finalMedian;
    double average;
    double finalAverage;
    vector<int> A; //namu darbu rezultatai
public:
   student() : egz(0), median(0.0), average(0.0), finalAverage(0.0), finalMedian(0.0) {}   //default constructor
   ~student() {} //destructor which is irrelevant in this case(i guess :/)

    //getters
    string getName() const {return name;}
    string getLastName() const {return lastName;}
    double getMedian() const {return finalMedian;}
    double getAverage() const {return finalAverage;}
    int getEgz() const {return egz;}
    //setters
    void setName(string name) {this->name = name;}
    void setLastName (string lastName) {this->lastName = lastName;}
    void setEgz (int egz) {this->egz = egz;}
    void setHW (vector<int> X) { A=X;}
    //methods
    void calculations();
    //operators
    friend ostream& operator<<(ostream& out, vector<student>&vect) { //isvedimo operatorius
        for (vector<student>::iterator i = vect.begin(); i != vect.end(); ++i)
        {
            out.width(15);
            out << left << (*i).name;
            out.width(15);
            out << left << (*i).lastName;
            out.width(15);
            out << left << fixed << setprecision(2) << (*i).finalMedian;
            out.width(15);
            out << left << setprecision(2) << (*i).finalAverage << endl;
        }
        return out;
    }
    friend istream& operator>>(istream& in, student &vect) { //ivedimo operatorius(naudoju tik vardui ir pavardei ivesti)

        in >> vect.name >> vect.lastName;
        return in;
    }
    friend bool operator<(const student &A, int n) // operatorius, kuris bus naudojamas vektoriaus paskirstymui
    {
        return (A.finalAverage < n);
    }
    //paskutiniai trys operatoriai panaudojami if salygoje, kuri isveda i console mokinius pagal tam tikra seka -> functions.cpp 45 eilute
    friend bool operator>(const student &a, const student &b)
    {
        return (a.name > b.name);
    }
    friend bool operator==(const student &a, const student &b)
    {
        return (a.name==b.name);
    }
    friend bool operator<(const student &a, const student &b)
    {
        return (a.lastName<b.lastName);
    }
};

#endif // STRUCT_H_INCLUDED
