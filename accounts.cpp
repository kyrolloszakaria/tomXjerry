#include "accounts.h"

//account handling with hashtables so it takes
using namespace std;
//could have made an AVL tree but choose instead to use
Node* accounts::NewNode(QString s, QString p,int sscore) {
        Node* n = new Node;
        n->name = s;
        n->password = p;
        n->next = NULL;
        n->topscore = sscore;
        return n;
}
 //3 files to fill this up
int accounts::hash(QString n) {
        int sum = 0;
        sum= n.toInt();
        for (int i = 0; i < n.size(); i++) {
            //int x= n[i].tossInt();
           // sum += n[i];
        }

        sum = sum % 10;
       // cout << sum << endl;
        return sum;

};

void accounts::AddAccount(QString nme, QString pass,int score) {
        Node* n = NewNode(nme, pass,score);
        //cout << nme << " has hash of "; //
        int index = hash(nme); //why is hashing wrong
       // cout << index << endl;
        if (arr[index] != NULL) {
            Node* temp = arr[index];
            while (temp->next != NULL && temp->name!=nme) {
                temp = temp->next;
            }
            if(temp->name!= nme){
            temp->next = n;}
        }
        else {
            arr[index] = n;
        }
    }
accounts::accounts() {
        for (int i = 0; i < 10; i++) {
            arr[i] = NULL; //maybe call parameterised constructor straight away with files as paameters
        }
        currentscore=10;
        readFile();
}

        //read from file and use function create account

void accounts::copyTableToFile() {
        //fstream f;
        QFile f("sources/Usernames.txt");
        QFile fpass("sources/AccountsPass.txt"); //make files instead of passing pointers to files
        QFile scor("sources/Scores.txt");
        QTextStream stream(&f);
        QTextStream stream2(&fpass);
        QTextStream stream3(&scor);
        f.open(QIODevice::WriteOnly);
        fpass.open(QIODevice::WriteOnly);
        scor.open(QIODevice::WriteOnly);
        for (int i = 0; i < 10; i++) {
            Node* temp;
            temp = arr[i];
            int count = 0;
            if (arr[i] != NULL) {
                while (temp!= NULL) {
                    stream << '\n'<< temp->name;
                    stream2 << '\n'<<temp->password;
                    stream3 << '\n'<<temp->topscore;
                    temp = temp->next;
                    count++;
                }
            }
        }
        f.close();
        fpass.close();
        scor.close();
    }
void accounts::readFile() {
        QFile f("sources/Usernames.txt");
        QFile fpass("sources/AccountsPass.txt"); //make files instead of passing pointers to files
        QFile scor("sources/Scores.txt");
        //f.open(QIODevice::ReadOnly);
        //fpass.open(QIODevice::ReadOnly);
        scor.open(QIODevice::ReadOnly);
        QTextStream stream (&f);
        QTextStream stream2 (&fpass);
        QTextStream stream3(&scor);
        QString name;
        QString password;
        int score;
        if (!f.open(QIODevice::ReadOnly) || !fpass.open(QIODevice::ReadOnly)) {
            qDebug() << "fail";
            exit(1);
        }
        else {
            try {

                while (!stream.atEnd() && !stream2.atEnd() && !stream3.atEnd()) {
                    stream>> name;
                    stream2 >> password;
                    stream3 >> score;
                    if (name != "" && password != "") {
                        AddAccount(name, password, score);
                    }
                }
            }
            catch (...) {
                f.close();
                fpass.close();
                exit(1);
            }
        }
    }

void accounts::RemoveAccount(QString nme) { //make with 2 pointers  and maybe add password to confirm that it is indeed them

    //make loop to getline for each file and check  if it is the name. then, go to password file with that line and remove
        int index = hash(nme);
        QString line;
        Node* temp = arr[index];
        Node* temp2 = arr[index];


        if (arr[index] != NULL) {
            if (arr[index]->name == nme) { //here condition head is being removed
                temp = arr[index]->next;
                delete arr[index];
                arr[index] = temp;
            }
            else {
                while (temp->next != NULL && temp->name != nme) {
                    temp2 = temp;
                    temp = temp->next;
                } //does this work if element to be deleted is last?
                if (temp->name == nme) {
                    temp2->next = temp->next;
                    delete temp;
                }
                else {
                    cout << "account not present"; //change this to raising an error.
                }
            }
        }
    } //maybe make another function to check index of name.

void accounts::correctHighScore(QString n,int newscore) {
        int index = hash(n);
        Node* temp = arr[index];
        if (arr[index] != NULL) {
            if (arr[index]->name == n) {
                if (newscore > arr[index]->topscore) {
                    arr[index]->topscore = newscore;
                }
            }
            else {
                while (temp->next!= NULL && temp->name != n) {
                    temp = temp->next;
                }
                if (temp->name == n) {
                    if (temp->topscore < newscore) {
                        temp->topscore = newscore;
                        //cout << "REACHEDDDD";
                    }
                }               //POSSIBLE IMPROVEMENT HEAP TREE TO STORE THE SCORES AS NODES WITH NAMES TO OUTPUT HIGHSCORES
            }
        }
    }
bool accounts::Login(QString n,QString pass) {
       int index = hash(n);
       Node* temp = arr[index];
       if (arr[index] != NULL) {
           if (arr[index]->name == n) {
               if (pass== arr[index]->password) {
                   return true;
               }
           }
           else {
               while (temp->next != NULL && temp->name != n) {
                   temp = temp->next;
               }
               if (temp->name == n) {
                   if (temp->password == pass) {
                       return true;
                   }
                   else{return false;}
               }
               else{return false;}
           }
       }
       return false;
   }

void accounts::showAccounts() {
        for (int i = 0; i < 10; i++) {
            if (arr[i] != NULL) {
                Node* temp;
                temp = arr[i];
                while (temp != NULL) {
                    qDebug() << temp->name << " w/ score " <<temp->topscore;
                    temp = temp->next;
                }
            }
        }
    }


accounts::~accounts(){
correctHighScore(currentaccount,currentscore);
copyTableToFile();
}

//int main()

/*
{
    Accounts LeaderBoard;
    LeaderBoard.readFile();

    LeaderBoard.showAccounts();
    LeaderBoard.correctHighScore("Mae", 30); //

    LeaderBoard.copyTableToFile();
    return 0;


}*/

//IMPORTANT NOTE ALWAYS COPYTABLE TO FILE IN END. AND READ FILE AT BEGINNING
