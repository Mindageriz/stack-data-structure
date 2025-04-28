#include <iostream>
using namespace std;

#define MAXSIZE 5	// Apibreziamas maksimalus Steko dydis

template <typename T>	// Sablonas, klase bus tinkama ivairiem duomenu tipam
class Stekas {			// Steko klase
private:
	int top;			// Virsutinio elemento indeksas
	T array[MAXSIZE];	// Steko elementu statinis masyvas

public:
	Stekas() {			// Konstruktorius
		top = -1;		// Virsutinio elemento indeksas == -1, kai stekas tuscias
	}

	bool isFull() {						// Tikrina ar stekas pilnas
		return (top == MAXSIZE - 1);	// TOP skaiciuojamas nuo 0, MAXSIZE nuo 1
	}

	void push(T value) {			// PUSH'ina elementa
		if (isFull()) {				// Tikrina ar stekas pilnas
			cout << "FULL" << endl;	// Jei stekas pilnas		
		}
		else {						// Jei stekas nera pilnas
			top++;					// TOP -> naujas elementas (virsutinis)
			array[top] = value;		// Uzpildoma elemento reiksme (value)
		}
	}

	void pop() {						// POP'ina elementa
		if (isEmpty()) {				// Tikrina ar stekas tuscias
			cout << "EMPTY" << endl;	// Jei stekas tuscias
		}
		else {							// Jei stekas nera tuscias
			top--;						// Virsutinio elemento indeksas sumazinamas (jis bus overwritintas/ignoruojamas)
		}
	}
	
	T peek() {				// Grazina virsutini steko elementa
		return array[top];			
	}

	bool isEmpty() {		// Tikrina ar stekas tuscias
		return (top == -1);	// TOP default == -1, jei issitustina == -1
	}

	void clear() {	// Isvalomas stekas
		top = -1;	// Tuscio steko indeksas, elementai bus overwritinti/ignoruojami	
	}

	void display() {					// Isveda steka i konsole
		if (isEmpty()) {				// Tikrina ar stekas tuscias
			cout << "EMPTY" << endl;	// Jei stekas tuscias
		}
		else {									// Jei stekas nera tuscias
			Stekas<T>* temp = new Stekas<T>;	// Sukuriamas TEMP steko pointeris
			while (top != -1) {					// Ciklas kol originalus stekas netuscias
				cout << peek() << " ";			// Isvedamas virsutinis elementas
				temp->push(peek());				// Virsutinis elementas PUSH'inamas i TEMP steka
				pop();							// Elementas POP'inamas is originalaus steko
			}
			while (temp->top != -1) {			// Ciklas kol TEMP stekas netuscias
				push(temp->peek());				// I originalu steka PUSH'inamas TEMP steko virsutinis elementas
				temp->pop();					// Elementas POP'inamas is TEMP steko
			}
			cout << endl;
			delete temp;	// Istrinamas pointeris i TEMP steka
		}
	}
};

int main() {
	Stekas<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.display();
	s.pop();
	s.display();
	s.clear();
	s.display();

	return 0;
}