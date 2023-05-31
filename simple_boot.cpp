#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    string name;
    string e_mail;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your email: ";
    cin >> e_mail;

    vector<vector<string>> dialogues = {
        {"my name ?", "Your name is: ", name},
        {"your name ?", "My name is TalkingBot."},
        {"hello", "Hello!", "Hola!", "Hi!"},
        {"age ?", "I am a bot, so I don't have an age."},
        {"created", "I was created by a team of developers.", "My creators remain anonymous."},
        {"price of vegetables", "The prices are as follows:", "Prices are as follows:"}
    };

    while (true) {
        cout << "User: ";
        string user;
        getline(cin,user);
        cout<<user<<"\n";

        int k = 1;
        bool flag = false;

        for (int i = 0; i < dialogues.size(); i++) {
            if (user.find(dialogues[i][0]) != string::npos) {
                k = k % dialogues[i].size();
                if (k == 0) {
                    k++;
                }
                cout << "Bot: " << dialogues[i][k] << endl;
                if(dialogues[i][k] == "The prices are as follows:"){
                    ifstream fin("vegetable.txt");
                    string line;
                    while(getline(fin,line)){
                        cout<<line;
                    }
                    
                }
                flag = true;
                break;
            }
            k++;
        }

        if (!flag) {
            cout << "Bot: Sorry, I don't understand!" << endl;
        }
        k+=2;
    }

    return 0;
}
