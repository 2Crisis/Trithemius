#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void matchcipher();
void shifter();

struct ciphertextinfo {
       int length;
       string ciphertext;
       int numerics[];       
};

ciphertextinfo ctinfo;

char capsalphabet[26] = {
     'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
     
     char alphabet[26] = {
     'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
     
//int alnum[26] = {
  //   '1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26' };

//int alnum[26] = {
  //   1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };


int main(int argc, char *argv[])
{
    string line;
    ifstream myfile( "myfile.txt");
    
    
    if (myfile.is_open())
    {
           while ( myfile.good() )
           {
                 getline (myfile, ctinfo.ciphertext);
                 cout << "Cipher Text: " << ctinfo.ciphertext << endl;
                 
                 matchcipher();
                 //ctinfo.numerics.push_back(alphabet[1]);
                 cout << "   Numerics: ";
                 for(int i = 0; i < ctinfo.ciphertext.length(); i++)
                 { 
                         if ( ctinfo.numerics[i] == -1 ) cout << "- ";
                         else cout << ctinfo.numerics[i] << " ";
                 }
            }
            myfile.close();
     }
                 
    else cout << "Unable to open file";
      
    system("PAUSE");
    return EXIT_SUCCESS;
}

void matchcipher()
{
     for(int i = 0; i < ctinfo.ciphertext.length(); i++)
     {
             char cpchar = ctinfo.ciphertext[i];
             //cout << cpchar << " ";
             if(cpchar == ' ')
             {
                       ctinfo.numerics[i] = -1;
                          //cout << "this char is a space" << endl;
             }
             else for(int j = 0; j < 26; j++)
             {
                     //cout << "checking cpchar: " << cpchar << " vs " << capsalphabet[j] << endl;
                     if(cpchar == capsalphabet[j])
                     {
                             //cout << "this char is a " << j+1 << endl;
                             ctinfo.numerics[i] = j+1;
                     }
             }
             
      }
}

void shifter()
{
     
     
     
}
