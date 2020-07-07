class IntArray//������� � ������ ���������� ��������!
{
	//int size;//���� �� ������� �� �� ��������� ����� ���������� � private

public://����� ��������� ������� � ������ (�� ��� �������� ����, � ������ � �������������)
	
	//���������� ������ �������
	int getSize() const; //cons � ������� �������� ��� ������ ������ ��������� �������

	//������ ������ ������� �������� ������ �� �����������
	void setSize(int n);

	//�������� ������� ���-�� ��������� ��������
	static int getArrCount()
	{
		return arrCount;
	}
	
	//����� ������������ �������� �������� ������� � �������� index
	//!!!TODO!!!
	//!��������� ������ ������ index > size
	int  getElem(int index) const;

		//����� �������� �������� �������� ������� � �������� index
		void  setElem(int index, int val);

		//����� ��������� ������� � �������� index 
		void deleteElem(int index);
	
		//����� ���������� �������� � �����
		void addElem(int val);

		//����� ����������� ������� � ������������ ����� �������
		void addElemMiddle(int index, int vall);

		//�����, ������������ ������� ������ � ������  �� �������
		IntArray& intArrayCompare( IntArray& anotherArr);

	//�����������
	//����������� �� ���������
	IntArray();
	IntArray(int n, bool random = false);
	IntArray(int n, const  int* arr);
	//���������� ����������� 
	IntArray(const IntArray &sec_arr);

	//����������
	~IntArray();

	void print() const;
	
private:
	//����������� ����������
	//������������ ���-�� �������� ������� ������
	static int arrCount;
	
	//�������� ������ ������ ������ � �������
	int size;
	//��������� �� ������
	int* array;
	

	//protected://�� ���� � �� ������ ������� �������� ��� ������ ������ ��� � ��� �������� (����������� � �������)


};

