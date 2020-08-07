#include <iostream>
#include <queue> 
using namespace std;

/* Recursive Descent Parser for the following grammar
 * 
 * S -> NP VP
 * NP -> A N
 * VP -> V NP
 * A -> a | the
 * V -> eats | loves | hates
 * 
 */

void S();
void NP();
void VP();
void A();
void N();
void V();
void errormessage(string m);
queue <string> sentence;
string nextword;

int main()
{
    sentence.push("the");
    sentence.push("dog");
    sentence.push("loves");
    sentence.push("the");
    sentence.push("cat");
    S();
    cout << "Success" << endl;
    return 0;  
}

void S() 
{
    // S -> NP VP
    
    NP();
    VP();
}

void NP() 
{
    // NP -> A NP
    
    A();
    N();
}

void VP() 
{
    // VP -> V NP
    
    V();
    NP();
}

void A() 
{
    // A -> the | a
     
    nextword = sentence.front();
    //cout << "nextword: " << nextword << endl;
    
   if( nextword.compare("the") == 0 || 
       nextword.compare("a") == 0 ) 
       sentence.pop();
    
    else 
        errormessage("Error in Article"); 
    
}

void N() 
{
    // N -> dog | cat | rat
    
    nextword = sentence.front();
    //cout << "nextword: " << nextword << endl;
    
    if( nextword.compare("dog") == 0 || 
        nextword.compare("cat") == 0  ||
        nextword.compare("rat") == 0 )
            
        sentence.pop();
    
    else
        errormessage("Error in Noun"); 
  
}

void V() 
{
    // V -> likes | hates | loves
    
    nextword = sentence.front();
    //cout << "nextword: " << nextword << endl;
    
    if( nextword.compare("eats") == 0 || 
        nextword.compare("hates") == 0  ||
        nextword.compare("loves") == 0 )
            
          sentence.pop();
     
    else
         errormessage("Error in Verb");
}

void errormessage(string message) {
    
    cout << message << endl;
   // exit(-1);
   //return ;
  // EXIT(1);
    
}
