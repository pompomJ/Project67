#include<iostream>
#include<string.h>

using namespace std;

class DrinkBox{
public:
	//�R���X�g���N�^
	DrinkBox(){}
	DrinkBox(const char *str, int n1, int n2) {
		name = new char[strlen(str) + 1];//�������ɍ��킹�ē��I�Ƀ��������m��
		strcpy(name, str);
		price = n1;
		count = n2;
	}
	//�f�X�g���N�^
	~DrinkBox(){
		delete[] name; //�����������
	}

int GetTotalPrice() {
	return count * price;
}

void PrintTitle() {
	cout << "���i��\t\t�P��\t����\t���z" << endl;
}

void PrintData() {
	cout << name << "\t" << price << "\t"
		<< count << "\t" << GetTotalPrice() << endl;
}

char *name;
int price;
int count;
};

class AlcoholBox : public DrinkBox {
public:
	AlcoholBox(const char *str, int n1, int n2, float f) {
		name = new char[strlen(str) + 1];
		strcpy(name, str);
		price = n1;
		count = n2;
		alcper = f;
	}
	void PrintTitle() {
		cout << "���i��(�x��[%])\t�P��\t����\t���z" << endl;
	}
	void PrintData() {
		cout << name << "(" << alcper << ") \t" << price << "\t"
			<< count << "\t" << GetTotalPrice() << endl;
	}

private:
	float alcper;
};

int main()
{
	DrinkBox coffee("�R�[�q�[",200, 3);
	DrinkBox oolongtea("�E�[������", 150, 2);
	AlcoholBox wine("���C��", 300, 2, 15.0);

	coffee.PrintTitle();
	coffee.PrintData();
	oolongtea.PrintData();
	wine.PrintTitle();
	wine.PrintData();

	int sum = coffee.GetTotalPrice()
		+ oolongtea.GetTotalPrice() + wine.GetTotalPrice();
	cout << "\n*** ���v���z" << sum << "�~***"<< endl;
	return 0;

}


