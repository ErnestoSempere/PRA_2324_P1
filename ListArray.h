#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T *arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
		T a = new T [new_size];
		for(int i = 0; i < max; i++){
			a[i] = arr[i];
		}
		delete []arr;
		arr = a;
		max = new_size;
	}

    public:
        ListArray(){
		arr = new T [MINSIZE];
		max = MINSIZE;
		n = 0;
	}	

	~ListArray(){
		delete[] arr;
	}

	T operator[](int pos){
		if(pos < 0 || pos > n - 1){
			throw std::out_of_range("Posición no válida");
		}
		else{
			return arr[pos];
		}
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		out << "List [ ";
		for(int i = 0; i < list.n; i++){
			out << list.arr[i] << " ";
		}
		out << "]" << std::endl;
		return out;
	}
    
};
