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
};

#endif // STRUCT_H_INCLUDED
