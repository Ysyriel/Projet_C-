#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main()
{
	int* num = new int(7);
	
	cout << *num << "ET\n" << num << "ET\n" << endl;
	
	
	int* tab = new int[4];
	tab[0]=2;
	cout << tab[0] << "adresse:\n" << tab <<endl;
	
	
	int nums[2];
	nums[0] = 5;
	nums[1] = 10;

  int* p=nums;
  cout << p << endl;
  
  vector<int> Vect;
  
  Vect.push_back(1);
  Vect.push_back(2);
  Vect.push_back(3);
  Vect.push_back(4);
  
  for(int i = 0; i<4 ; i++)
		cout << Vect[i] <<endl;
		
	random_shuffle (Vect.begin(), Vect.end());
	
	for(int i = 0; i<4 ; i++)
		cout << Vect[i] <<endl;
  
  
  
  
  
  
  
	
	
	
	
}
