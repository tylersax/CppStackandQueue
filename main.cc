#ifndef MAIN_CC
#define MAIN_CC
#include "main.h"
#include <string>
/*
int main(){
        Queue<string> s1;
        s1.enqueue("veggies");
        s1.enqueue("taste");
        s1.enqueue("good.");
        s1.printInternal();
        cout<<"-----dequeue------"<<endl;
        cout<<s1.dequeue()<<endl;
        s1.printInternal();
        cout<<s1.size()<<endl;
        s1.clear();
        cout<<"------cleared------"<<endl;
        s1.printInternal();

return 0;
}*/


/////////////////////////////////////////////


int main(){
	
try{
	Stack<int> s1, s2;
	Queue<string> q1, q2;
	s1.push(3);
	q1.enqueue("apples");
	q1.enqueue("bananas");
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.printInternal();
	cout<<"-----pop------"<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	s1.printInternal();
	cout<<"ALL POPPED"<<endl;
	s1.push(10);
	s1.push(11);
	s1.push(12);
	cout<<"3 pushed"<<endl;
	cout<<"size:"<<s1.size()<<endl;
	//s1.clear();
	//cout<<"------cleared------"<<endl;
	//s1.printInternal();
	s2 = s1;
	cout<<"s2 = s1"<<endl;
	cout<<"print s2"<<endl;;
	s2.printInternal();
	q2 = q1;
	cout<<"q1 copy"<<endl;
	q2.printInternal();
	s1.clear();
	s1.pop();

}//try
catch(StackEmpty){
cout<<"PASS __STACK EMPTY"<<endl;
}
return 0;
}
//this main function was used to test the Stack class



/*
/////////////////////////////////////////
int main(){

	Node<int> *np = new Node<int>(5);
	cout<<np->getObject()<<endl;
	np->setNextPtr(new Node<int>(7));
	Node<int> *ptr = np->getNextPtr();
	cout<<ptr->getObject()<<endl;
	ptr->setObject(12);
	cout<<ptr->getObject()<<endl;

return 0;
}//this main was used to test all of the methods in the Node class.
// all methods executed successfully with both ints and strings
//clean up using main provided in notes*/

#endif
