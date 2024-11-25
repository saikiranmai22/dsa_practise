#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item{
    int value, weight;
    Item(int v, int w): value(v),weight(w){}
};
bool compare(Item a, Item b){
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}
double fractional(int capacity, vector<Item> &items){
    sort(items.begin(), items.end(), compare); 

    double max=0.0;
    for(auto &item:items){
        if(capacity>=item.weight){
            capacity -=item.weight; //subtract
            max +=item.value; //add
        }else{
            max +=(double)item.value*capacity/item.weight;
            break;
        }
    }
    return max;
}
int main(){
    vector<Item> items= {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    // Call the fractional knapsack function
    double result = fractional(capacity, items);
    // Print the result
    cout << "Maximum value in the knapsack = " << result << endl;
    return 0;
}