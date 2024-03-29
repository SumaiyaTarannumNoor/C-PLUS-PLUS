// C++ program to find first
// non-repeating character
#include <iostream>
using namespace std;
#define NO_OF_CHARS 256
#include <cstdlib>


/* Returns an array of size 256 containing count
of characters in the passed char array */
int* getCharCountArray(char* str)
{
	int* count = (int*)calloc(sizeof(int), NO_OF_CHARS);
	int i;
	for (i = 0; *(str + i); i++)
		count[*(str + i)]++;
	return count;
}

/* The function returns index of first
non-repeating character in a string. If all
characters are repeating then returns -1 */
int firstNonRepeating(char* str)
{
	int* count = getCharCountArray(str);
	int index = -1, i;

	for (i = 0; *(str + i); i++) {
		if (count[*(str + i)] == 1) {
			index = i;
			break;
		}
	}

	// To avoid memory leak
	free(count);
	return index;
}

/* Driver program to test above function */
int main()
{
	char str[300];
	cout << "Enter a word: ";
	cin >> str[300];
	int index = firstNonRepeating(str);
	if (index == -1)
		cout << "Either all characters are repeating or "
			"string is empty";
	else
		cout << "First non-repeating character is "<<
			str[index];
	getchar();
	return 0;
}

// This code is contributed by shivanisinghss2110
