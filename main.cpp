/* Another push has been done */

#include <iostream>
#include <vector>
using namespace std;

void addItem(vector<int> &c,int item);
void displayItems(vector <int> &c);
void searchAnItem(vector<int> c, int key);
void deleteItem(vector<int> &c, int pos);
void sortItems(vector<int> &c, char orderChoice);
//void *(*const *array[10][10][10])();        // What is this?

int main(){
    cout << "Welcome! Please select your option." << endl << endl;

    int choice {};
    vector<int> collection {};
    while(1) {
        cout << "(1) Add an Item. " << endl;
        cout << "(2) View all Items. " << endl;
        cout << "(3) Search for an Item. " << endl;
        cout << "(4) Delete an Item. " << endl;
        cout << "(5) Sort the Items. " << endl;
        cout << "(6) Exit. " << endl;

        cout << endl << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            int choice2 {};
            cout << "Enter your value that you want to add: ";
            cin >> choice2;
            addItem(collection, choice2);
        }

        if(choice == 2)
            displayItems(collection);

        if(choice == 3){
            int choice2;
            cout << "What value would you like to search for? \n>> ";
            cin >> choice2;
            searchAnItem(collection, choice2);
        }

        if(choice == 4){
            int posChoice {};
            cout << "Which position would you like to remove?\n>>";
            cin >> posChoice;
            deleteItem(collection, posChoice);
        }

        if(choice == 5){
            char orderChoice;
            cout << "Which order would you like to choose?" << endl;
            cout << "(A) Descending" << endl;
            cout << "(B) Ascending" << endl;
            cout << ">> ";
            cin >> orderChoice;
            sortItems(collection, orderChoice);
        }

        if(choice == 6)
            break;
    }
    return 0;
}

void addItem(vector<int> &c, int item){
    c.push_back(item);
    cout << "\nValue added successfully." << endl;
}

void displayItems(vector <int> &c){
    if(c.empty()) {
        cout << "The list is empty." << endl;
        return;
    }

    cout << "Items in the list [";
    for(int i: c)
        cout << i << " ";
    cout << "]" << endl;
}

void searchAnItem(vector<int> c, int key){
    int left = 0;
    int right = c.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(c.at(mid) == key) {
            cout << "Value located at index " << mid << endl;
            break;
        }
        else if(c.at(mid) < key)
            left = mid + 1;
        else if(c.at(mid) > key)
            right = mid - 1;
    }
    cout << "Value not found" << endl;
}

void deleteItem(vector<int> &c, int pos){
    c.erase(c.begin() + pos);
}

void sortItems(vector<int> &c, char orderChoice){
    if(orderChoice == 'A'){
        for(int i {0}; i < c.size(); i++){
            for(int j{i + 1}; j < c.size(); j++){
                if(c.at(i) < c.at(j))
                    swap(c.at(i), c.at(j));
            }
        }
    }
    else{
        for(int i {0}; i < c.size(); i++){
            for(int j{i + 1}; j < c.size(); j++){
                if(c.at(i) > c.at(j))
                    swap(c.at(i), c.at(j));
            }
        }
    }
}