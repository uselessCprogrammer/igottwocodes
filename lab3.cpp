#include <iostream>

using namespace std;
string convert_string(string s){ /** CONVERT TO UPPER CASE STRING **/
string s1 = s;                   /** This function is mainly used to compare strings. **/
for(int i=0;i<s.size();i++){
    s1[i]=toupper(s1[i]);
}
return s1;
}
typedef struct node{ /** ## DEFINITIONS ## **/
string first_name;
string last_name;
int age;
node* next_link;
}node;
typedef node* nodePtr;
nodePtr myList;
/** ### START OF QUEUE IMPLEMENTATION ### **/

struct queuee{
nodePtr head;
nodePtr tail;
};
queuee myQueue,temp_queue,temp_queue1;
/** ### INIT QUEUE METHOD ### **/
    void queue_init(queuee &q){
    q.head = 0;
    q.tail = 0;
    }
/** ### INSERT NEW PERSON (PUSH) METHOD ### **/
    void queue_push(queuee &q,string first_names,string last_names,int ages){
    nodePtr desiredNode = new node;
    desiredNode->age = ages; /** THIS WILL BE USED FOR NON EMPTY QUEUE **/
    desiredNode->first_name=first_names;
    desiredNode->last_name=last_names;
    desiredNode->next_link=0;
    if(q.head==0){ /** CHECK IF OUR QUEUE IS EMPTY **/
        q.head = new node;
        q.head->age = ages;
        q.head->first_name=first_names;
        q.head->last_name=last_names;
        q.head->next_link=0;
        q.tail = q.head;
    }
    else{ /** ELSE IF OUR QUEUE IS NOT EMPTY **/
        q.tail->next_link=desiredNode;
        q.tail=desiredNode;
    }
    }
    /** QUEUE POP FUNCTION **/
    void queue_pop(queuee &q){
         if(q.head==0){
            cout << "Queue is empty nothing to pop" << endl;
         }
            else{
            if(q.head==q.tail){
            free(q.head);
            q.head=q.tail=0;
         }
         else{
            nodePtr temp = new node;
            temp = q.head;
            q.head = q.head->next_link;
            free(temp);

         }

            }

    }
    void queue_remove(queuee &q,string first_names,string last_names,int ages){
        nodePtr temp,temp1 = new node;
        temp1 = temp_queue1.head;
        temp =q.head;
    if(q.head == 0){
        cout << "Queue is empty nothing to remove." << endl;
    }
    /** LOOP USED TO FIND WHERE OUR ELEMENT IS LOCATED AT **/
    else{
            while(temp!=0){ /** PUSH ALL ELEMENTS BESIDES DESIRED PERSON INTO OUR QUEUE **/
          if((convert_string(first_names) != convert_string(temp->first_name) ) && (convert_string(last_names) != convert_string(temp->last_name) ) && ( ages != temp->age )){
            queue_push(temp_queue1,temp->first_name,temp->last_name,temp->age);
          }
          queue_pop(q); /** USING THIS TO REMOVE ALL ELEMENTS FROM THE QUEUE **/
        temp = temp->next_link;
    }
        temp1 = temp_queue1.head;
    while(temp1!=0){
        queue_push(q,temp1->first_name,temp1->last_name,temp1->age); /** PUSH ELEMENTS TO OUR ORIGINAL QUEUE **/
        temp1 = temp1->next_link;
    }
    queue_init(temp_queue1);
    }









    }
    /** FUNCTION TO TRAVERSE FORWARD OUR QUEUE **/

    void traverse_forward_queue(queuee q){
    if(q.head == 0){
        cout << "Queue is empty nothing to display." << endl;
    }
    else{
        nodePtr temp = new node;
        temp = q.head;
        cout << "=================" << endl;
        while(temp!=0){
            cout << "First name : " << temp->first_name << endl;
            cout << "Last name : " << temp->last_name << endl;
            cout << "Age : " << temp->age << endl;
            temp = temp->next_link;
        }
        cout << "=================" << endl;
    }

    }
    void reverse_queue(queuee &start, queuee &destination){
                if(start.head==0){
                return;
            }
            else{
                  string first_name = start.head->first_name; /** SAVE ELEMENT AT HEAD **/
                  string last_name = start.head->last_name;
                  int age = start.head->age;
                  queue_pop(start); /** POP IT**/
                  reverse_queue(start,destination); /** USING RECURSION TO LOOP THROUGH ALL ELEMENTS **/
                  queue_push(destination,first_name,last_name,age); /** PUSH ELEMENTS ONE BY ONE STARTING FROM END TO FIRST **/
            }

    }
    void traverse_backward_queue(queuee &q){
    reverse_queue(q,temp_queue); /** REVERSE MY QUEUE **/
    traverse_forward_queue(temp_queue); /** PRINT IT **/
    reverse_queue(temp_queue,q); /** RECOVER PREVIOUS QUEUE **/
    queue_init(temp_queue); /** RESET TEMP QUEUE **/
    }



/** ### END OF QUEUE IMLPEMENTATION ### **/

/** ## START OF STACK IMPLEMENTATION ### **/
typedef struct{
string first_name;
string last_name;
int age;
nodePtr top;
}stackk;
stackk myStack,temp_stack;
void stack_init(stackk &s){ /** INITIALIZE OUR STACK **/
    s.top=0; 
}
void stack_pop(stackk &s){
if(s.top==0){
    cout << "Stack is empty nothing to pop." << endl;
}
else {
    nodePtr temp = new node; /** DELETE ELEMENT AT TOP OF THE STACK **/
    temp = s.top;
    s.top = s.top->next_link;
    free(temp);

}
}

void stack_push(stackk &s,string first_names,string last_names,int ages){
    nodePtr desiredNode = new node; /** CREATE OUR NODE **/
    desiredNode->age = ages; /** FILL IT WITH ELEMENTS **/
    desiredNode->first_name=first_names;
    desiredNode->last_name=last_names;
    desiredNode->next_link=s.top;
    s.top=desiredNode; /** MAKE OUR NEW NODE THE DESIRED HEAD/TOP **/
}

void stack_reverse(stackk &start,stackk &destination){ /** USEFUL FUNCTION FOR REVERSING STACK **/
        while(start.top!=0){
        string first_name = start.top->first_name; /** SAVE ELEMENT AT TOP OF STACK**/
        string last_name = start.top->last_name;
        int age = start.top->age;
        stack_pop(start); /** POP IT **/
        stack_push(destination,first_name,last_name,age); /** PUSH IT IN OUR NEW STACK**/
        }
}

void stack_traverse_backward(stackk s){ /** PRINTS ELEMENTS FROM END TO FIRST PERSON **/
if(s.top==0){
    cout << "Stack is empty." << endl;
}
else{
    nodePtr temp=new node;
    temp = s.top;
        cout << "=================" << endl;
        while(temp!=0){
            cout << "First name : " << temp->first_name << endl;
            cout << "Last name : " << temp->last_name << endl;
            cout << "Age : " << temp->age << endl;
            temp = temp->next_link; /** MOVE ALONG THE STACK **/
        }
        cout << "=================" << endl;
}
}
void stack_traverse_forward(stackk s){ /** PRINT ELEMENTS FROM FIRST PERSON TO LAST PERSON INSERTED **/
    stack_init(temp_stack);
if(s.top == 0){
    cout << "Stack is empty." << endl;
}
else{
    stack_reverse(s,temp_stack); /** FUNC CALL TO REVERSE STACK **/
    stack_traverse_backward(temp_stack); /** PRINT OUR REVERSED STACK**/
    stack_reverse(temp_stack,s); /** RECOVER OUR ORIGINAL STACK **/
    stack_init(temp_stack); /** RESET OUR TEMP STACK **/

}

}
void stack_remove(stackk &s,string first_names,string last_names,int ages){
    stack_init(temp_stack);
    nodePtr temp,temp1 = new node;
if(s.top==0){ /** CHECK IF THE STACK IS EMPTY **/
    cout << "Nothing to delete." << endl;
}
else{ /** SEARCH FOR THE PERSON **/
  temp = s.top;
  while(temp!=0){
    if((convert_string(first_names) != convert_string(temp->first_name) ) && (convert_string(last_names) != convert_string(temp->last_name) ) && ( ages != temp->age )){
        stack_push(temp_stack,temp->first_name,temp->last_name,temp->age);
        /** PUSH ALL ELEMENTS BESIDES THE ONE YOU WANNA DELETE **/

    }
    stack_pop(s); /** POP THE WHOLE STACK**/
    temp=temp->next_link;

  }
  temp1 = temp_stack.top;
    while(temp1!=0){
            /** FILL OUR ORIGINAL STACK BACK WITH ELEMENTS **/
        stack_push(s,temp1->first_name,temp1->last_name,temp1->age);
        temp1=temp1->next_link;
    }
  }
}


/** ## END OF STACK IMPLEMENTATION ## **/

void print_stuff(char in){
    string first_name;
    string last_name;
    int age;
bool run = true;
    cout << "a. Insert Person :" << endl;
    cout << "b. Delete Person :"<< endl;
    cout << "c. Traverse FW :"<< endl;
    cout << "d. Traverse BW :"<<endl;
if(in == 'S'){
    while(run){
     char input;
    cout << "->" << endl;
    cin  >> input;
    switch(input){
case 'a':
    cout << "Enter first name :" << endl;
    cin >> first_name;
    cout << "Enter last name : " << endl;
    cin >> last_name;
    cout << "Enter age :" << endl;
    cin >> age;
    stack_push(myStack,first_name,last_name,age);
    break;
case 'b':
    cout << "Enter first name :" << endl;
    cin >> first_name;
    cout << "Enter last name : " << endl;
    cin >> last_name;
    cout << "Enter age :" << endl;
    cin >> age;
    stack_remove(myStack,first_name,last_name,age);
    break;
case 'c':
    stack_traverse_forward(myStack);
    break;
case 'd':
    stack_traverse_backward(myStack);
    break;
case 'q':
    cout << "Exit." << endl;
    run = false;
    break;
default:
    cout << "Invalid answer" << endl;
    break;
    }
}
}
else{
    while(run){
    char input;
    cout << "->" << endl;
    cin >>input;
    switch(input){
case 'a':
    cout << "Enter first name :" << endl;
    cin >> first_name;
    cout << "Enter last name : " << endl;
    cin >> last_name;
    cout << "Enter age :" << endl;
    cin >> age;
    queue_push(myQueue,first_name,last_name,age);
    break;
case 'b':
    cout << "Enter first name :" << endl;
    cin >> first_name;
    cout << "Enter last name : " << endl;
    cin >> last_name;
    cout << "Enter age :" << endl;
    cin >> age;
    queue_remove(myQueue,first_name,last_name,age);
    break;
case 'c':
    traverse_forward_queue(myQueue);
    break;
case 'd':
    traverse_backward_queue(myQueue);
    break;
case 'q':
    cout << "Exit." << endl;
    run = false;
    break;
default:
    cout << "Invalid answer" << endl;
    break;
    }
}
}
}


int main()
{
    char input;
    stack_init(myStack);
    queue_init(myQueue);
    cout << "Which implementation you want to use (S/Q) : " << endl;
    cin >> input;
    switch(input){
case 'S':
    print_stuff(input);
    break;
case 'Q':
    print_stuff(input);
    break;
default:
    cout << "Wrong implementation." << endl;
    break;
    }
    return 0;
}
