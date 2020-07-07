class IntArray//функции в классе называются МЕТОДАМИ!
{
	//int size;//елси не указано то по умолчанию будет относиться в private

public://можно доставать функции и данные (то что доступно всем, и классу и пользователям)
	
	//возвращает размер массива
	int getSize() const; //cons в функции означает что нельзя менять состояние объекта

	//меняет размер массива сохраняя данные по возможности
	void setSize(int n);

	//получает текущее кол-во созданных объектов
	static int getArrCount()
	{
		return arrCount;
	}
	
	//метод возвращающий значение элемента массива с индексом index
	//!!!TODO!!!
	//!исправить ошибку коогда index > size
	int  getElem(int index) const;

		//метод задающий значение элемента массива с индексом index
		void  setElem(int index, int val);

		//Метод удаляющий элемент с индексом index 
		void deleteElem(int index);
	
		//Метод добавления элемента в конец
		void addElem(int val);

		//Метод добавляющий элемент в произвольное место массива
		void addElemMiddle(int index, int vall);

		//Метод, сравнивающий текущий массив с другим  по размеру
		IntArray& intArrayCompare( IntArray& anotherArr);

	//конструктор
	//Конструктор по умолчанию
	IntArray();
	IntArray(int n, bool random = false);
	IntArray(int n, const  int* arr);
	//Копирующий конструктор 
	IntArray(const IntArray &sec_arr);

	//Деструктор
	~IntArray();

	void print() const;
	
private:
	//статическая переменная
	//подсчитывает кол-во объектов данного класса
	static int arrCount;
	
	//доступно только внутри класса и друзьям
	int size;
	//указатель на массив
	int* array;
	

	//protected://те поля и те методы которые доступны как самому классу так и его потомкам (наследникам и друзьям)


};

