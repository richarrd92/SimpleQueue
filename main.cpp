//QUEUE IMPLEMENTATION PROGRAM
#include <iostream>
using namespace std;

class Queue{
private:
    int head, tail ,shadowTail , arrSize = 4; // initialization of elements
    int* arr = new int[arrSize]; // dynamic array

public:
    Queue(){
        head = -1; //start of queue
        tail = -1; // end of queue
        shadowTail = -1; // shadow of tail. used to change elements
        for(int i = 0; i < arrSize; i++) // fill up array with zeros
            arr[i] = 0;
    }

    bool isEmpty(){
        if(head == -1 && tail == -1) // if both tail and head are at the basement then queue empty
            return true;
        else
            return false;
    }

    bool isFull(){
        if(tail == arrSize-1){ // if tail is equal to the size of the array. the queue is at max capacity
            arrSize +=2; // if full add two more slots
            return true;
        }else
            return false;
    }

    void Enqueue(int element){
        if(isFull())
            cout << "Queue is FULL !" <<endl;
        else if(isEmpty()){ // if queue is empty. to add element. set both tail and head = 0
            tail = 0;
            head = 0;
            arr[tail] = element; // set item at index 0 = element
        } else{ // if queue is not full nor empty. then it must have multiply elements
            tail++; // add to the next empty slot
            shadowTail++; // keep track of where the tail is pointing
            arr[tail] =element; // add element at the slot, tail is pointing at
        }
    }

    int Dequeue(){
        int save; // variable to store value before it is changed to zero
        if(isEmpty()){
            return 0; // if empty do nothing
        }else if(tail == head){ // this would mean that there is only one element
            save = arr[head];  // saves value at index 0 into variable save
            arr[head] = 0; // then sets  value at index 0 = 0 to mimic removal
            head = -1; // sets head and tail back to -1 to mimic empty queue
            tail = -1;
            shadowTail = -1; // traces where tail is pointed at
            return save; // returns value
        }else{ // this is in the case queue is not empty and has multiple values
            save = arr[head];
            arr[head] = 0;
            head++; // head is incremented to point to the next position
            return save;
        }
    }

    void check(int position){
        if(isEmpty())
            cout << "Queue is EMPTY !" <<endl;
        else if (position < 0 || position > arrSize)
            cout << "INVALID index !" <<endl;
        else if (position > tail)
            cout << "Empty slot !" <<endl;
        else{
            cout << "Element at position " << position << " is " << arr[position-1]<< endl;
        }
    }

    int queueLength(){ // returns the length of the array/queue
        return arrSize;
    }

    bool emptySlot(int position){ // checks if slot is empty
        if(position-1 > tail) // -1 because users counts from 1 while comp counts from 0. we are comparing to comp
            return true;
        else
            return false;
    }

    void change(int position, int element){
        if(isEmpty())
            cout << "Cant change element! Queue is EMPTY !" <<endl;
        else{
            shadowTail = position-1; // using shadow tail, so that the index of the actual tail is not messed with
            arr[shadowTail] = element;
        }
    }

    int count(){
        if(isEmpty())
            return 0;
        else
            return (tail - head+1);
    }

    void display(){
        cout << "Elements in the queue: " <<endl<<endl;
        for (int i = 0; i < arrSize; i++)
            cout << arr[i] << "  |  ";
        cout <<endl;
    }

};

int main() {

    int element, option, position;
    Queue queue;
    cout << "\n ********** START OF PROGRAM *********" <<endl <<endl;
    int operations = 1;
    do {
        cout <<endl;
        cout << "--------------------------------------------------------------------------" <<endl;
        cout << "OPERATION: " << operations <<endl<<endl;
        cout << "1: Add Element: " <<endl;
        cout << "2: Remove Element: " <<endl;
        cout << "3: Check Element: " <<endl;
        cout << "4: Count Element(s): " <<endl;
        cout << "5: Change Element: " <<endl;
        cout << "6: Display Queue: " <<endl;
        cout << "7: Exit program: " <<endl;
        cout << "\nChoose Option: ";
        cin >> option;

        switch (option) {
            case 1:
                if (queue.isFull())
                    cout << "New memory allocated! Enter Element Again" <<endl;
                else{
                    cout << "Add Element: ";
                    cin >> element;
                    queue.Enqueue(element);
                }
                break;

            case 2:
                if(queue.isEmpty())
                    cout << "Cant remove element! Queue is EMPTY !" <<endl;
                else
                    cout << "Element " <<queue.Dequeue() << " removed" <<endl;
                break;

            case 3:
                if(queue.isEmpty())
                    cout << "Queue is EMPTY !" <<endl;
                else{
                    cout << "Enter position: ";
                    cin >> position;
                    queue.check(position);
                }
                break;

            case 4:
                if(queue.isEmpty())
                    cout << "Queue is EMPTY !"<<endl;
                else if (queue.count() == 1)
                    cout << "There is " << queue.count() <<" Element in the Queue "<<endl;
                else
                    cout << "There are " << queue.count() <<" Element(s)  in the Queue "<<endl;
                break;

            case 5:
                if(queue.isEmpty())
                    cout << "Cant change element! Queue is EMPTY !" <<endl;
                else{
                    cout << "Enter position: ";
                    cin >> position;
                    if((position <= queue.queueLength()) && (position > 0)){ //check for bounds
                        if(queue.emptySlot(position)) // check for empty slots
                            cout << "Empty slot !" <<endl;
                        else{
                            cout << "Enter element: ";
                            cin >> element;
                            queue.change(position, element);
                        }
                    } else
                        cout << "Out of Bounds !" <<endl;
                }
                break;

            case 6:
                queue.display();
                break;

            case 7:
                cout << "\n\n ********** END OF PROGRAM *********" <<endl <<endl;
                break;

            default:
                cout << "INVALID OPTION !!! " <<endl;
        }
        operations++;
    } while (option !=7);

    return 0;
}
