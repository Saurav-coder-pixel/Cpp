#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Complex{
    private:
    float real;
    float imag;

    public:
    Complex(float r=0, float i=0){
        real = r;
        imag = i;
    }
    Complex operator +(Complex c){
        Complex temp;
        temp.real= real + c.real;
        temp.imag= imag + c.imag;
        return temp;
    }
    void display(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }
    void writeToFile(){
        ofstream fout("output.txt");
        if(!fout){
            cout<<"File not created!";
            return;
        }
        fout<< real<<'+' << imag<< 'i' << endl;
        fout.close();
    }
    void readFromFile(){
        ifstream fin("output.txt");
        if (!fin){
            cout<<"File not found!";
            return;
        }
        string line;
        getline(fin, line);
        cout<<"Data from file: "<<line<<endl;
        fin.close();
    }
};

    int main(){
        float r1, i1, r2, i2;
        cout<<"Enter real and imaginary parts of first complex number: ";
        cin>> r1 >> i1;
        cout<<"Enter real and imaginary parts of second complex number: ";
        cin>> r2 >> i2;
        Complex c1(r1, i1);
        Complex c2(r2, i2);
        Complex c3 = c1 + c2;
        cout<<"Sum of complex numbers: ";
        c3.display();
        c3.writeToFile();
        cout<<"Reading from file..."<<endl;
        c3.readFromFile();
        return 0;
    }