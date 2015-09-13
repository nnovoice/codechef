#define NUMALPHABETS 26
#define ALPHABETSCOUNT 27
#define MAXCHARS 101

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>

using namespace std;

class TourishTranslations {
private:
	int nCases;
	char translation[ALPHABETSCOUNT];
	char englishAlphabets[ALPHABETSCOUNT];
	char sentence[MAXCHARS];

	int diff;
	char lowerCaseChar;
	int index;

	void init() {
		memset(sentence, '\0', sizeof(char) * MAXCHARS);
		diff = 0;
		lowerCaseChar = ' ';
		index = 0;
	}
	void translate() {
		char ch = ' ';
		for (int i = 0; sentence[i] != '\0'; ++i) {
			ch = sentence[i];
			if (ch == '_') {
				sentence[i] = ' ';
			}
			else if (ch == '?' || ch == '.' || ch == '!' || ch == ',') {
				sentence[i] = ch; // not required actually!
			}
			else {
				if (ch < 'a') {
					diff = ch - 'A';
					lowerCaseChar = 'a' + diff;
					index = lowerCaseChar - 'a';
					ch = translation[index];
					diff = ch - 'a';
					ch = 'A' + diff;
				}
				else {
					index = ch - 'a';
					ch = translation[index];
				}
				sentence[i] = ch;
			}
		}
		cout << sentence << endl;
	}

public:
	TourishTranslations() {
		memset(englishAlphabets, '\0', sizeof(char) * ALPHABETSCOUNT);
		char ch = 'a';
		for (int i = 0; i < NUMALPHABETS; ++i) {
			englishAlphabets[i] = ch + i;
		}
	}
	
	void lookup() {
		cin >> nCases;
		cin >> translation;
		for (int i = 0; i < nCases; ++i) {
			init();
			cin >> sentence;
			translate();
		}
	}
};

int main() {
	TourishTranslations translator;
	translator.lookup();
	return 0;
}
