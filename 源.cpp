#include"List.h"
#include<fstream>
using namespace std;

int main()
{
	ofstream ofs("1234.text");
	ofs << "1 2 3 4 5 7";
	ofs.close();
	ifstream ifs("1234.text");
	int i;
	vector<int> ivec;
	while (ifs >> i) ivec.push_back(i);
	List l(ivec);
	l.printAll();
	/*int arr[6] = { 2, 3, 3, 4, 3, 5 };
	List list1(arr, 6);
	list1.printAll();
	list1.insert(3, 6);
	list1.printAll(); // Your output should be: 2 3 3 6 4 3 5
	cout << list1.remove(2) << endl; // Your output should be: 3
	cout << list1.length() << endl; // Your output should be: 4
	int arr1[6] = { 2,3,3,4,3,6 };
	List list2(arr1, 6);
	list2.insert(3, 6);
	list2.printAll();
	list2.printAll();
	cout << list2.remove(3) << endl;
	cout << list2.length() << endl;
	vector<int> ivec = { 9,8,7,6,8,4,7,5 };
	List list3(ivec);
	cout << list3.find(7) << "\t" << list3.find(4) << endl;
	list3.printAll();
	*/

	
	return 0; // Your list should be deallocated before exit.
}