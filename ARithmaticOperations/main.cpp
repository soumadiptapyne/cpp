#include <iostream>
#include <vector>

using namespace std;

void display_menu();
char selection_upper();
void menu_option(char c);

void display_menu(){
    cout <<endl <<endl;
    cout << "P - Print Numbers" << endl;
    cout << "A - Add a Number" << endl;
    cout << "M - Display Mean of the number" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\n--------------------------------------" << endl;
    cout << "Enter your selection: ";
}

char selection_upper(){
    char selection;
    cin>>selection;
    return (toupper(selection));
}

void print_numbers(const vector <int> &data){
        if(data.size() == 0)
        {
            cout << "[] - The list is empty.\nPlease enter some data to the list by choosing option A." <<endl <<endl; 
        }
        else{
            for (int x: data)
            cout << x << " ";
        }
}

void add_numbers(vector <int> &data){
    int num{};
        cout << "Enter the number you want to add: ";
        cin >> num;
        data.push_back(num);
        cout << num << " is added to the list."<<endl <<endl;
}

void mean_numbers(vector<int> &data){
    double Mean{};
    double sum{};
    for(size_t i=0; i<data.size(); ++i)
            {
                sum += data.at(i);
            }
        Mean = sum/data.size();
        cout << "The mean of the current list is " << Mean << endl;
}

void smallest_numbers(vector<int> &data){
    if(data.size() ==0)
            cout << "Unable to determine the smallest number, list is empty." <<endl;
        else
        {
            int smallest = data.at(0);
            for (auto num: data)
                if(num < smallest)
                    smallest = num;
            cout << "The smallest number in the current list is " << smallest <<endl;
        }
}

void Largest_numbers(vector<int> &data)
{
    if(data.size() ==0)
            cout << "Unable to determine the Largest number, list is empty." <<endl;
        else
        {
            int largest = data.at(0);
            for (auto num: data)
                if(num > largest)
                    largest = num;
            cout << "The largest number in the current list is " << largest <<endl;
        }
}

void quit_numbers(){
    cout << "Goodbye!!!" <<endl;
}


int main() {
    
    char selection{};
    vector <int> numbers;
    
    do{
    display_menu();
    selection = selection_upper();
    cout << "\nYou selected Option: " << selection <<endl;
    
    switch (selection){
        case 'P':
            print_numbers(numbers);
            break;
        case 'A':
            add_numbers(numbers);
            break;
        case 'M':
            mean_numbers(numbers);
            break;
        case 'S':
            smallest_numbers(numbers);
            break;
        case 'L':
            Largest_numbers(numbers);
            break;
        case 'Q':
            quit_numbers();
            break;
    }
    
    }while(selection != 'q' && selection != 'Q');
    
    cout<<endl;
    return 0;
}

