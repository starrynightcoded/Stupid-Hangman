#include <iostream>
#include <string>
#include <vector>
using namespace std;
string arr[] = {"alphabet", "horse", "cat", "orca"};

void clean(vector <int> & indexes){
    for(int i=0; i<indexes.size(); i++){
        indexes[i] = 0;
    }
}
void findIndexesHangman(const char & alpha, string &word, vector<int> & indexes){
    for(int i=0; i<word.size(); i++){
        if(word[i]==alpha){
            indexes.push_back(i);
        }
    }
}
bool searchHangman(const char & alpha, string &word){
        bool found = false;
    for(int i=0; i<word.size(); i++){
        if(word[i]==alpha){
            found = true;
            break;
        }
    }
        return found;
}
int calculateFrequency(const char & alpha, string &word){
    int count = 0;
    for(int i=0; i<word.size(); i++){
        if(alpha == word[i]){
            count++;
        }
    }
    return count;
}
string concatenate(const char & alpha, string &word){  // calculate indexs and then add it to string no matter what is the poition just verify size
    string temp = "";
    for(int i=0; i<word.size(); i++){
        if(alpha == word[i]){
            temp+=word[i];
        }
    }
    return temp;
}
void display_Dashes(const string& word){
    for(int i=0; i<word.size(); i++){
        cout<<" _";
    }
}


void display_Guesses(string &temp, const string & word,vector<int> indexes, char alpha ){
    for(int i=0; i<temp.size(); i++){
        for(int j=0; j<indexes.size(); j++){
            temp[indexes[j]] = alpha;
        }
    }
    for(int i=0; i<temp.size(); i++){
        cout<<" "<<temp[i];
    }
}
int main(){
   int choice = 0;
   string temp= "";

    cout << "Welcome to Hangman!" << endl;
    cout<< "Player 1: Select a word from dictionary for player 2 to guess!(0 to 3): "<<endl;
    cin>>choice;
    temp.resize(arr[choice].size());
    int life_Count = 5, length_Count = 0;
    char guess =' ';
    if(choice >=0 && choice <=3){
        while(true){
            if(life_Count==0){
                cout <<"Game Over! Player 1 won"<<endl;
                break;
            } else if(temp==arr[choice]){
                cout<<"Congrats! Player 2 won!"<<endl;
                break;
            }
            cout<<"Player 2: Enter your guess!: "<<endl;
            cin>>guess;
             vector <int> indexes;
            findIndexesHangman(guess, arr[choice], indexes);
            //for(auto &i : indexes){
             //   cout<<"Debugging.."<<endl;
             //   cout<<i<<endl;
            //}
            if(searchHangman(guess, arr[choice])){
                cout<<"Correct guess!"<<endl;
                display_Guesses(temp,arr[choice], indexes, guess);
                cout<<endl;
                display_Dashes(arr[choice]);
                cout<<endl;
               // clean(indexes);
                length_Count++;

            }else{
                life_Count--;
                cout<<"Incorrect guess! :/ Lives Left: "<<life_Count<<endl;
                display_Guesses(temp, arr[choice], indexes, guess);
                cout<<endl;
                display_Dashes(arr[choice]);
                cout<<endl;
                //clean(indexes);
            }
        }

    } else{
        cout<<"Invalid choice"<<endl;
    }
    return 0;
}

