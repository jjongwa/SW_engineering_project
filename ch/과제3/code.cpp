#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME	"input.txt"
#define OUTPUT_FILE_NAME "output.txt"


// Class ����

/*
	Ŭ���� �̸� : Cloth
	�ǹ�	  : �� ������ ��� �ִ� 
*/
class Cloth 
{
	private:
		string clothName;
		string companyName;
		int price;
		int quantity;
		// vector<Evaluation> evaluationCollection;
	public:
		Cloth(string input_clothName, string input_companyName, int input_price, int input_quantity){
			clothName = input_clothName;
			companyName = input_companyName;
			price = input_price;
			quantity = input_quantity;
		};
		string getName(){return clothName;};
		string getCompany(){return companyName;};
		int getprice(){return price;};
		int getquantity(){return quantity;};

};

/*
	Ŭ���� �̸� : Member
	�ǹ�	  : ȸ�� ������ ��� �ִ� 
*/
class Member
{		
private:
	string name, SSN, ID, password;	// �̸�, �ֹι�ȣ, ���̵�, ��й�ȣ
public:
	Member(string input_name, string input_SSN, string input_ID, string input_password);
	string getName(){return name;}
	string getSSN(){return SSN;}
	string getID() const {return ID;} 
	string getPassword(){return password;}  
	bool is_available;	// �� ������ ��밡������ (Ż������ �ʾҴ���);
};
vector <Member> Members;	// Member���� �ּҸ� ��Ƶδ� �迭


/*
	Ŭ�����̸� : Seller
	�ǹ�	: �Ǹ��� ������ ��� �ִ�. 
*/
class Seller : public Member
{
	private:
		vector<Cloth> sellClothCollection;
		vector<Cloth> soldoutClothCollection;
	public:
		Seller(Member member) : Member(member.getName(), member.getSSN(), member.getID(), member.getPassword()){};
		bool operator== (const string& s){
				if(this->getID().compare(s) == 0){
					return true;
				}else{
					return false;
				}
			};
		void createSellCloth(Cloth cloth){
			sellClothCollection.push_back(cloth);
		};
		vector<Cloth> getSellClothlist(){return sellClothCollection; };
		vector<Cloth> getSoldoutClothlist(){return soldoutClothCollection; };
};
vector <Seller> sellers;	//Seller���� �ּҸ� ��Ƶδ� �迭


/*
	Ŭ���� �̸� 	: SignUp
	���	  		: ȸ�� ���� control class
	�ۼ���		: ����ȭ
*/
class SignUp
{
public:
	void createMemRequest(string name, string SSN, string ID, string password);
};


/*
	Ŭ���� �̸�	: SignUpUI
	���  		: ȸ�� ���� boundary class
	�ۼ���		: ����ȭ
*/
class SignUpUI
{
public:
	void signUpRequest();
};

/*
	Ŭ���� �̸� : AddSellCloth
	�ǹ�	  : �Ǹ��Ƿ� ��� control class
*/
class AddSellCloth
{
	public: 
		void addSellCloth(Cloth cloth, Member user);
};

/*
	Ŭ���� �̸� : AddSellClothUI
	�ǹ�	  : �Ǹ��Ƿ� ��� boundary class
*/
class AddSellClothUI
{
	public:
		Cloth createSellCloth(string clothName, string companyName, int price, int quantity ){
			Cloth cloth = Cloth(clothName, companyName, price, quantity);
			return cloth;
		};
		void startInterface();

};


void doTask();
void join();
void program_exit();


ifstream in_fp (INPUT_FILE_NAME);   
ofstream out_fp (OUTPUT_FILE_NAME); 


int main()
{
	doTask();
	return 0;
}


void doTask()
{
	//cout << "doTask����"<< endl;
	// �޴� �Ľ��� ���� level ������ ���� ����
	
	int is_program_exit = 0;
	
	while(!is_program_exit)
	{	

		Member user = Member("TMP_NAME", "000-0000","tmp_id","tmp_pw");	//�α����� ȸ����� �ӽ÷� ����
		string dummy;	// ���� ������ ���� ����
		int menu_level_1 = 0, menu_level_2 = 0;
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		in_fp >> menu_level_1 >> menu_level_2;
		cout << "Ȯ�ο�) ���� ���� method ��ȣ: "<< menu_level_1 << " " <<menu_level_2<< endl;
		
		
		
		// �޴� ���� �� �ش� ���� ����
		switch(menu_level_1)
		{
			case 1:
			{		
				switch(menu_level_2)
				{
					case 1:	// "1.1. ȸ�����ԡ� �޴� �κ�
					{						
						// join() �Լ����� �ش� ��� ���� 
						SignUpUI* startSignUpUI = new SignUpUI;
						startSignUpUI->signUpRequest();
						
						//join();
						break;
					}
					case 2:	// 1.2 ȸ��Ż��
					{
			   
						break;
					}
				}
				break;
			}
			case 2:
			{	
				switch(menu_level_2)
				{
					case 1:	// 2.1 �α���
					{				
						in_fp >> dummy;	// ���ѷ��� ��������, �ڵ� �ϼ��ϸ� �����ּ���
						in_fp >> dummy;	// ���ѷ��� ��������, �ڵ� �ϼ��ϸ� �����ּ���
						
						break;
					}
					case 2:	// 2.2 �α׾ƿ�
					{
			   
						break;
					}
				}
				break;
			}
			case 3:
			{
				switch(menu_level_2)
				{
					case 1:	// 3.1 �Ǹ� �Ƿ� ���
					{		
						string clothName, companyName;
						int price, quantity;
						in_fp >> clothName;	
						in_fp >> companyName;	
						in_fp >> price;	
						in_fp >> quantity;

						AddSellCloth addSellCloth = AddSellCloth();
						AddSellClothUI addSellClothUI = AddSellClothUI();

						addSellClothUI.startInterface();
						Cloth cloth = addSellClothUI.createSellCloth(clothName, companyName,price, quantity);
						addSellCloth.addSellCloth(cloth, user);
						break;
					}
					case 2:	// 3.2 ��� ��ǰ ��ȸ
					{
			   
						break;
					}
					case 3:	// 3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ
					{
			   
						break;
					}
				}
				break;
			}
			case 4:
			{
				switch(menu_level_2)
				{
					case 1:	// 4.1 ��ǰ ���� �˻�
					{				
						in_fp >> dummy;	// ���ѷ��� ��������, �ڵ� �ϼ��ϸ� �����ּ���
						break;
					}
					case 2:	// 4.2 ��ǰ ����
					{
			   
						break;
					}
					case 3:	// 4.3 ��ǰ ���� ���� ��ȸ
					{
			   
						break;
					}
					case 4:	// 4.4 ��ǰ ���Ÿ����� ��
					{
						in_fp >> menu_level_1;	// ���ѷ��� ��������, �ڵ� �ϼ��ϸ� �����ּ���
						break;
					}
				}
				break;
			}
			case 5:
			{
				switch(menu_level_2)
				{
					case 1:	// 5.1 �Ǹ� ��ǰ ���
					{				
		
						break;
					}
					
				}
				break;
			}
			case 6:
			{
				switch(menu_level_2)
				{
					case 1:	// 6.1 ����
					{	
						is_program_exit = 1;							
						program_exit();
						break;						
					}
					
				}
				break;
			}		  		  		  		
		}
	}
	
	return;
}


// �Լ� ����

/*
	�Լ� �̸�	: Member:::Member()
	���		: ���ο� ȸ���� ����� ������
	���� ����	: string input_name, string input_SSN, string input_ID, string input_password
	��ȯ��	: ����
	�ۼ���	: ����ȭ
*/
Member::Member(string input_name, string input_SSN, string input_ID, string input_password)
{
	name = input_name;
	SSN = input_SSN;
	ID = input_ID;
	password = input_password;
	is_available = true;
}


/*
	�Լ� �̸�	: SignUpUI::signUpRequest()
	���		: ȸ������ ������ �����ϴ� �Լ�, ȸ�����Կ� �ʿ��� ������ �Է¹���
	���� ����	: ����
	��ȯ��	: ����, SignUp->createMemRequest() ȣ�� 
	�ۼ���	: ����ȭ
*/
void SignUpUI::signUpRequest()
{
	// ��� ����
	out_fp << "1.1. ȸ������" << endl;
	
	string name, SSN, ID, password;
	in_fp >> name >> SSN >> ID >> password;
	
	SignUp* startSignUp = new SignUp;
	startSignUp->createMemRequest(name, SSN, ID, password);
	
}

/*
	�Լ� �̸�	: SignUpUI::createMemRequest(string name, string SSN, string ID, string password)
	���		: ȸ������ ����, �Է¹��� ������ Member Ŭ���� ����� Members ���Ϳ� ����
	���� ����	: string name, string SSN, string ID, string password
	��ȯ��	: ����
	�ۼ���	: ����ȭ
*/
void SignUp::createMemRequest(string name, string SSN, string ID, string password)
{
	Member newMem = Member(name, SSN, ID, password);
	Members.push_back(newMem);
	
	cout << "Ȯ�ο�(��� ����ƴ���) ��� ����� ������ ��� �̸�  "<<Members.back().getName() << endl;
	// ��� ����
	out_fp << "> " << name << " " << SSN << " " << ID << " " << password <<endl;
}

/*
	�Լ� �̸�	: AddSellCloth::addSellCloth(Cloth cloth, Member user)
	���		: �Ǹ��� ���� �� �̹� ����� �Ǹ��Ƿ� ��Ͽ� Cloth �߰� 
	���� ����	: Cloth cloth, Member user
	��ȯ��	: ����
	�ۼ���	: ��ä��
*/
void AddSellCloth::addSellCloth(Cloth cloth, Member user){
			string user_id = user.getID();
			if(find(sellers.begin(), sellers.end(), user_id) == sellers.end()){
				Seller seller = Seller(user);
				seller.createSellCloth(cloth);
				sellers.push_back(seller);
				cout<<"check"<<seller.getName()<<"\n";

			}else{
				int idx = find(sellers.begin(), sellers.end(), user_id)-sellers.begin();
				sellers[idx].createSellCloth(cloth);
				cout<<"check"<<sellers[idx].getName()<<"\n";
			}
			out_fp << "> " << cloth.getName() << " " << cloth.getCompany() << " " << cloth.getprice() << " " << cloth.getquantity() <<endl;
			
		};

/*
	�Լ� �̸�	: AddSellClothUI::startInterface()
	���		: �Ǹ��Ƿ� �߰� UI����
	���� ����	: ����
	��ȯ��	: ����
	�ۼ���	: ��ä��
*/
void AddSellClothUI::startInterface(){
			out_fp << "3.1. �Ǹ� �Ƿ� ���" << endl;
		}

void program_exit()    
{
	// ��� ����
	out_fp << "6.1. ����" << endl;
}

bool operator== (const string& s, const Seller& seller){
				if(seller.getID().compare(s) == 0){
					return true;
				}else{
					return false;
				}
			};
