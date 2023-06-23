#include <iostream>
#include <conio.h> 
#include <string> 
#include <stdlib.h> 
#include <ctime>

#define WRONGTRIES 7

using namespace std;

void start()
{
  cout << "||======================================||\n";
  cout << "||                                      ||\n";
  cout << "||	HANGMAN : THE DEADLY GAME  	||\n";
  cout << "||				        ||\n";
  cout << "||======================================||\n";
  cout << "\nInstructions: Save your friend from being hanged by guessing the name of FRUIT.\n\n";
}

void DrawMan(int tries){
	cout<<endl<<endl;
     cout<<"  -----"<<endl;
	 cout<<"  |   |"<<endl; 
	 cout<<"  |   ";
	 if(tries<=6)cout<<"|";  
     if(tries<=5) cout<<endl<<"  |   O    ";	
     if(tries==4) cout<<endl<<"  |   |    ";
	 if(tries==3) cout<<endl<<"  |  /|  ";
	 if(tries<=2) cout<<endl<<"  |  /|\\ ";
if(tries<=1 && tries !=0){cout<<endl<<"  |  /";}
if(tries==0) {cout<<endl<<"  |  / \\ ";}
cout<<endl<<"  |"<<endl; 
	  cout<<"  |"<<endl; 
	  cout<<"  |"<<endl; 
	  cout<<"__|__"<<endl;
	  
	  	if(tries==1)
	{
		cout<<"\n\nTHIS IS YOUR LAST ATTEMPT.if you make mistake ,your friend will be hanged.\n\n";
	}	
}

int main(){
	
	srand (time(NULL));
	string wordList[22] = {"chikoo","pomgranate","pumpkin","cherry","lemon","blueberry","date","jackfruit","pineapple","watermelon","kiwi","orange","graphes","pear","papaya","guava","coconut","apple","peach","banana","strawberry","mango"};
	string word;
	string guessed;
	
	word = wordList[rand()%20];
	
	int wordLength = word.length();
	string dispWord (wordLength, '*');
	int found = 0;
	char guess = ' ';
	int tries = 7; //No of wrong tries
	int flagFound = 0; 
  
	while(tries>=0){

system("cls");
start(); 
		cout<<"Guess the Fruit Name: "<<endl<<endl;
		 
		for(int i=0; i<wordLength; i++)
			cout<<" "<<dispWord[i]<<" "; 
		cout<<endl<<endl<<endl;
		 		
		cout<<"remaining Attempts: "<<tries<<" / "<<WRONGTRIES<<endl;
		cout<<"guessed letters: "<<guessed<<endl; 
		
		DrawMan(tries);
		if( tries == 0) break; 

		
		
		cout<<"Please enter your guess:";
		guess = getche();
		
		guessed = guessed + " " + guess;
		
		if( dispWord.find(guess)!=string::npos ) tries--;
		
		flagFound = 0;
		for(int i=0; i<wordLength; i++){
			if( word[i]==guess && dispWord[i]=='*' ){
				dispWord[i] = guess;
				found++;
				flagFound = 1; 
			}
		}
		 
		if( !flagFound )
		{
		
			tries--;
	}
	
	if( found == wordLength ){
			cout<<endl;
			{ cout<<"as you guessed it right,your fruit name is \""<<word<<"\"\n";
    cout<<"Hooray! You saved the friend from being hanged and earned a medal of honor!\n";
    cout<<"Congratulations!!\n";
            }
			break;
			
			}
			
	}
	
	if( found != wordLength ){
		cout<<endl;
		cout<<"On no! your friend  is hanged!\n";
    cout<<"btw actual fruit name was \"" <<word<< "\"";
    
	}
	

	return 0;
}

