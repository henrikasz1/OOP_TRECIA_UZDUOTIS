#include "functions.h"
#include "struct.h"

void student::calculations ()
{
    //average
    int a, b;//laikinieji kintamieji medianos skaiciavimui
    sort(A.begin(), A.end());
    if (A.size()%2==0)
    {
        a=A.size()/2;
        b=A.size()/2-1;
        median = (A[a]+A[b])*1.0/2;
    }
    else
    {
        a=A.size()/2;
        median = A[a];
    }
    finalMedian = 0.4 * median + 0.6 * egz;
    //median
    int total=0;
    for(int i=0; i<A.size(); i++)
    {
        total+=A[i];
    }
    average = total*1.0/A.size();
    finalAverage = 0.4 * average + 0.6 * egz;
}

void calculate(vector<student> &M)
{
    for (int i=0; i<M.size(); i++)
    {
       M[i].calculations();
    }
}


void output (int n, vector<student> &B)
{
      system("cls");
      //surikiuoju duomenis pagal varda
      for (int i=0; i<n-1; i++)
          for (int j=i+1; j<n; j++)
              if (B[i].getName()>B[j].getName() || (B[i].getName()==B[j].getName() && B[i].getLastName()>B[j].getLastName()))
              {
                swap(B[i], B[j]);
              }
      //randa ilgiausia varda ir pavarde, tai pades graziai islygiuoti teksta
      int largestName=0;
      int largestLastName=0;
      for (int i=0; i<n; i++)
      {
        if (B[i].getName().size()>largestName) largestName=B[i].getName().size();
      }
      for (int i=0; i<n; i++)
      {
        if (B[i].getLastName().size()>largestLastName) largestLastName=B[i].getLastName().size();
      }
      //isvedimas
      cout << "-------------------------------------------------------------------" << endl;
      cout << left << setw(largestName+1) << "Vardas";
      cout << left << setw(largestLastName+3) << "Pavarde";
      cout << left << setw(16) << "Galutinis(Med.)";
      cout << "Galutinis(Vid.)\n";
      cout << "-------------------------------------------------------------------" << endl;
      for (int i=0; i<n; i++)
      {
        cout << left << setw (largestName+1) << B[i].getName();
        cout << left << setw (largestLastName+3) << B[i].getLastName();
        cout << left << setw (16) << fixed<<setprecision(2) << B[i].getMedian();
        cout << fixed << setprecision(2) << B[i].getAverage();
        cout<<endl;
      }
}

//good
void generateFile(int kiekis, int nddydis, string &a)
{
    auto start = chrono::steady_clock::now();
    //srand(time(NULL));
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1,10);

    string vardas= "vardas";
    string pavarde= "pavarde";
    string nd="ND";
    string egz="EGZ";
    stringstream numOfFile;
    numOfFile << kiekis;
    string num=numOfFile.str();
    a="randomly_generated_file_of "+num+".txt";
    ofstream fd(a);
    fd << left << setw(20) << vardas << left << setw(20) << pavarde;
    for (int i=1; i<=nddydis; i++)
    {
        fd << setw(5) << right << nd << i << " ";
    }
    fd << setw(5) << right << egz << endl;
    for(int j=1; j<=kiekis; j++)
    {
        fd << vardas << j;
        fd << setw(20-displayHelper(j)) << right;
        fd << pavarde << j;
        for (int k=0; k<nddydis; k++)
        {
            if (k==0)
            {
                fd << right << setw(18-displayHelper(j)) << dist(mt);
            }
            else fd << right << setw(7) << dist(mt);
        }
        fd << right << setw(7) << dist(mt) << endl;
    }
    fd.close();
    auto finish = chrono::steady_clock::now();
    cout<<"Faila sugeneravo per: "<<chrono::duration <double, milli>(finish - start).count()<<" ms"<<endl;
}
//good
int displayHelper (int number)
{
    int temp=0;
    while (number>0)//kadangi integeris suroundina, galima rasyt tokia salyga
    {
        number/=10;
        temp++;
    }
    return temp;
}
//bad
void readFile(vector<student> &M, string name)
{
    auto start = chrono::steady_clock::now();
    vector <int> temporary; //for the use of temporarily reading homework results
    int k=0;
    ifstream in(name);
    string line;
    string nname, lastName;
    int exam;
    int nd;
    getline(in, line);
    while(getline(in, line))
    {
        istringstream enter(line);
        M.push_back(student());
        enter >> nname >> lastName;
        M[k].setName(nname);
        M[k].setLastName(lastName);
       // enter >> M[k].name;
       // enter >> M[k].lastName;
        while(enter)//-------------!!!!!!!!!!!!!
        {
            enter >> nd;
            temporary.push_back(nd);
            //M[k].A.push_back(nd);
        }
        exam = temporary.back();
        temporary.pop_back();
        M[k].setHW(temporary);
        //M[k].egz=M[k].A.back();
        M[k].setEgz(exam);
        //M[k].A.pop_back();
        //M[k].median=0.4*median(M[k].A)+0.6*M[k].egz;
        //M[k].average=0.4*average(M[k].A)+0.6*M[k].egz;
        k++;
        temporary.clear();
    }
    calculate(M);
    auto finish = chrono::steady_clock::now();
    cout<<"Faila nuskaite per: "<<chrono::duration <double, milli>(finish - start).count()<<" ms"<<endl;
    in.close();
}
//bad
void distributeFile(int numOfStudents, vector<student> &M, vector<student> &kvaili)
{
    auto sstart = chrono::steady_clock::now();
    stringstream number;
    number << numOfStudents;
    string num=number.str();
    ofstream bad("apgailetini "+num+".txt");
    ofstream good("dievai "+num+".txt");



			auto a = stable_partition(M.begin(), M.end(), [&](const auto &tmp){return!(tmp.getAverage() < 5);});

            kvaili.insert(kvaili.end(), make_move_iterator(a), make_move_iterator(M.end()));

            M.erase(a, M.end());

    kvaili.shrink_to_fit();
    auto ffinish = chrono::steady_clock::now();
    cout << "Studentus surusiavo per: " << chrono::duration <double, milli>(ffinish - sstart).count() << "ms" << endl;
    auto start = chrono::steady_clock::now();

	for (vector<student>::iterator i = kvaili.begin(); i != kvaili.end(); ++i)
	{
		bad.width(15);
		bad << left << (*i).getName();
		bad.width(15);
		bad << left << (*i).getLastName();
		bad.width(15);
		bad << left << fixed << setprecision(2) << (*i).getMedian();
		bad.width(15);
		bad << left << setprecision(2) << (*i).getAverage() << endl;
	}
    for (vector<student>::iterator i=M.begin(); i!=M.end(); ++i)
    {
        good.width(15);
        good << left << (*i).getName();
        good.width(15);
        good << left << (*i).getLastName();
        good.width(15);
        good << left << setprecision(2) << (*i).getMedian();
        good.width(15);
        good << left << setprecision(2) << (*i).getAverage() << endl;
    }
    auto finish = chrono::steady_clock::now();
    cout << "Studentus isvede i naujus failus per: " << chrono::duration <double, milli>(finish - start).count() << "ms" << endl;
}
