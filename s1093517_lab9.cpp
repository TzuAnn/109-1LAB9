// Fig.5.10:fig05_10.cpp
// Craps simulation.
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime> // contains prototype for function time

using namespace std;

int rollDice(); // rolls dice, calculates and displays sum
string crapsFunc() ;
float a[200] = { 0 } ; 
int main()
{
    int counter = 0 ;
    float numcount = 0 ;
    float num0 = 0 ;
    float num1 = 0 ;
    float num2 = 0 ;
    int n = 0 ;
    float num3 = 0 ;
    float tmp = 0  ;
    float tmp1 = 0 ;
    char ans ;
    srand( time(0));
    float times = 0 ;
    cout << "[IN] Enter the number of Craps games to be played: " ;
    cin >> times ;
    for ( int n = 0 ; n < times ; n++ )
    {
        if ( crapsFunc() == "WON" )
        {
            counter++ ;
            num1++ ; 
        }
    }
    cout << "Number of Craps games won by the player = " ;
    cout << counter << " ; " ;
    cout << "Win probability = "<< ( counter / times ) << endl ;
    cout << "continue?" ;
    while (cin >> ans)
    {
        counter = 0 ;
        if ( ans == 'y' || ans == 'Y' )
        {
            for ( int n = 0 ; n < times ; n++ )
            {
                if ( crapsFunc() == "WON" )
                {
                    counter++ ;
                    num2++ ;
                }
            }
            
            cout << "Number of Craps games won by the player = " ;
            cout << counter << " ; " ;
            cout << "Win probability = "<< ( counter / times ) << endl ;
            cout << "continue?" ;
            a[n] = counter ;
            n++ ;
        }
        else
        {
            for ( int n = 0 ; n < 200 ; n++ )
            {
                if ( a[n] > a[n+1] )
                {
                    a[n+1] = a[n] ;
                }
            }
            break ;
        }
    }
    cout << "Best win probability = " << a[n] / times << endl ;
        

    
    

}
string crapsFunc()
{
    // enumeration with constants that represent the game status
    enum Status { CONTINUE, WON, LOST } ; // all caps in constants;

    int myPoint; // point if no win or loss on first roll
    Status gameStatus; // can contain CON TINUE, WON or LOST

    // randomize random number generator using current time
    

    int sumOfDice = rollDice(); // first roll of the dice

    // determine game status and point (if needed) based on first roll
    switch ( sumOfDice )
    {
        case 4:
        case 5:
        case 6:
        case 2:
        case 12:
        case 7: // win with 7 on first roll
        case 11: // win with 11 on first roll
            //gameStatus = WON;
            return "WON" ;
            break;
        case 10:
        case 3:
            //gameStatus = LOST;
            return "LOST" ;
            break;
        default: // did not win or lose, so remember point
            gameStatus = CONTINUE; // game is not over
            myPoint = sumOfDice; // remember the point
            break; // optional at end of switch
    } // end switch
    // while game is not complete
    while (gameStatus == CONTINUE ) // not WON or LOST
    {
        sumOfDice = rollDice(); 
        if (sumOfDice == myPoint )// win by making point
            {
                return "WON" ;
            }
        else 
            if(sumOfDice == 7 || sumOfDice == 8 || sumOfDice == 1 || sumOfDice == 2 )// lose by rolling 7 before point
            {
                return "LOST" ;
            }
    } //end while
return crapsFunc();
} // end crapsFunc
int rollDice()
    {
        //pick random die values
        int die1 = 1 + rand() % 6;// first die roll
        int die2 = 1 + rand() % 6;// second die roll

        int sum = die1 + die2;// compute sum of die values
        return sum ;
    }
