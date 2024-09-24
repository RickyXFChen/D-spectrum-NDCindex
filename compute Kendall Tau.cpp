#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <list>
#include <sstream>
#include <math.h>
#include <numeric>
#include <regex>
#include <iomanip>
#include <cmath>

using namespace std;


void writetofilei(string filename, vector<int>A){
ofstream tf;
string yy;

 tf.open(filename,ios::app|ios::out);
  for(int b = 0; b< A.size(); b = b + 1){
  	
	  yy=std::to_string(A[b]);
  	  tf << yy <<" ";
  }
  tf << endl;
  tf.close();	
}




void writetofiled(string filename, vector<double>A){
ofstream tf;
string yy;

  tf.open(filename);
  for(int b = 0; b< A.size(); b = b + 1){
  	
	  yy=std::to_string(A[b]);
  	  tf << yy <<'\n';
  }
  tf.close();	
}
//end of block


vector<double> readfromfiled(string filename, vector<double>&A){
    string line;
    ifstream tf2 (filename);
    if (tf2.is_open() && tf2.good()) 
    {
        while (getline (tf2,line) && !line.empty()) 
        {
            try { 
                char * cstr = new char [line.length()+1];
                std::strcpy (cstr, line.c_str());
                std::string::size_type sz;
                A.push_back(stod(cstr,&sz)); 
                delete[] cstr;
            }
            catch (const std::invalid_argument& e) { 
                cout << "Invalid argument: " << e.what() << endl;
            }
            catch (const std::out_of_range& e) { 
                cout << "Out of range: " << e.what() << endl;
            }
        }
        tf2.close();
    }
    else cout << "Unable to open file";

    return A;
}
//end of block


  
double compare(vector<double> A, vector<double> B){
int conc=0;
int disc=0;
int ncd=0;
int nov=A.size();

for(int k=0;k<nov-1;k++){
	for(int j=k+1;j<nov;j++){	
	if ((A[k]>A[j]&&B[k]>B[j])||(A[k]<A[j]&&B[k]<B[j])){conc=conc+1; }
	if ((A[k]>A[j]&&B[k]<B[j])||(A[k]<A[j]&&B[k]>B[j])){disc=disc+1; }
	}
}
double dconc=(double) conc;
double ddisc=(double) disc;
double q=2*(dconc-ddisc)/(nov*(nov-1));
return q;
}
//end of block

    int main (int argc, char** argv){
	string netname="email_output";
      
vector<double> prob;    
    
//prob={0.00786467,0.0393234, 0.0786467,0.11797,0.157293, 0.314587, 0.47188,  0.629174,  0.786467};  //router
//prob={0.00565368,0.0282684,0.0565368,0.0848053,0.113074, 0.226147,  0.339221, 0.452295,   0.565368, }; //email
//prob={0.00265667,0.0132833, 0.0265667,0.03985,0.0531334,0.106267,0.1594,    0.212533,  0.265667, }; //jazz
//prob={0.00230613,0.0115307,0.0230613,0.034592, 0.0461226,0.0922453, 0.138368, 0.184491,   0.230613 };//usair
//prob={0.0012459,0.00622948, 0.012459,  0.0186884, 0.0249179, 0.0498358,  0.0747537, 0.0996716,0.12459}; //pb
//prob={0.00784168,0.0392084,0.0784168,0.117625,0.156834, 0.313667 };//barndgraph3k_output
//prob={0.0042195,0.0210975,0.042195,0.0632925,0.08439, 0.16878 };//barndgraph3k5_output
//prob={0.00998256,0.0499128,0.0998256,0.149738,0.199651, 0.399302 };//rndgraph003_output
//prob={0.005558,0.02779,0.05558,0.08337,0.11116, 0.22232 };//rndgraph006_output

prob={0.0565368}; 

vector<double> qinf;
vector<double> Ninf;
vector<double> Sum;

readfromfiled(netname+" index to compare"+".txt",Sum);
  

for(int k=0;k<prob.size();k++){
	cout<<prob[k]<<endl;
	stringstream sssss;
	sssss << prob[k];
	string str4 = sssss.str();	
	readfromfiled(netname+" vertex infection rates p"+str4+".txt",Ninf);	
	double temp = 0;
	temp = compare(Sum,Ninf);	
	qinf.push_back(temp);
	Ninf.clear();
	if (qinf.size() == qinf.capacity()) { 
        qinf.reserve(qinf.capacity() * 2); 
        }

writetofiled(netname+" kendall tau.txt",qinf);

}



}








