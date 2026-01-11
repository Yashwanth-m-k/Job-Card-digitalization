#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    int secrate,guess;
    int attempts=0;

    srand(time(0));
     secrate = rand()%100+1;

    cout<<"Guessing game" <<endl;
    cout <<"Guess number from 1 to 100 "<<endl;

    while(1)
    {
        cout<<"Enter the number"<<endl;
        cin>> guess;
        attempts++;
        if(guess>secrate)
        {
            cout<<"Too high! try again..\n";
        }
        else if(guess<secrate)
        {
            cout<<"Too Low! try again..\n";
        }
        else{
            cout<<"Congragulation .. you guess Correctly..\n";
            cout<<"Number of attempts"<<attempts<<endl;
            break;
        }
    }

    return 0;    
    }


