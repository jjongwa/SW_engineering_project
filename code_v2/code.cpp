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

ifstream in_fp (INPUT_FILE_NAME);   
ofstream out_fp (OUTPUT_FILE_NAME); 




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
		int averageEvaluation=0;
		// vector<Evaluation> evaluationCollection;
	public:
		Cloth(string input_clothName, string input_companyName, int input_price, int input_quantity){
			clothName = input_clothName;
			companyName = input_companyName;
			price = input_price;
			quantity = input_quantity;
		};

		bool operator== (const string& s){
				if(this->getName().compare(s) == 0){
					return true;
				}else{
					return false;
				}
			};

		string getName() const {return clothName;};
		string getCompany(){return companyName;};
		int getprice(){return price;};
		int getquantity(){return quantity;};
		int getAverageEvaluation(){return averageEvaluation;};

};
vector <Cloth> Clothes;	// Cloth���� �ּҸ� ��Ƶδ� �迭


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
	bool operator== (const string& s){
				if(this->getID().compare(s) == 0){
					return true;
				}else{
					return false;
				}
			};
	string getName(){return name;}
	string getSSN(){return SSN;}
	string getID() const {return ID;} 
	string getPassword(){return password;}  
	bool is_available;	// �� ������ ��밡������ (Ż������ �ʾҴ���);
};
vector <Member> Members;	// Member���� �ּҸ� ��Ƶδ� �迭
Member* loginUser; //�α����� �����

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
vector <Seller> Sellers;	//Seller���� �ּҸ� ��Ƶδ� �迭

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

/*
	Ŭ���� �̸� : SignOut
	�ǹ�	  : ȸ��Ż�� control class
*/
class SignOut
{
	public: 
		void deleteMember(Member user){
			auto tmp_idx1 = find(Members.begin(), Members.end(), user.getID());
			Members.erase(tmp_idx1);

			auto tmp_idx2 = find(Sellers.begin(), Sellers.end(), user.getID());
			Sellers.erase(tmp_idx2);
			out_fp << "> " << user.getID() << endl;
			
			loginUser = nullptr;
		};
};

/*
	Ŭ���� �̸� : SignOUtUI
	�ǹ�	  :  ȸ��Ż�� boundary class
*/
class SignOutUI
{
	public:
		void startInterface(){out_fp << "1.2. ȸ��Ż��" << endl;};

};

/*
	Ŭ���� �̸� : LogIn
	�ǹ�	  : �α��� control class
*/
class LogIn
{
	public: 
		void loginMember(string id, string password);
};

/*
	Ŭ���� �̸� : LogInUI
	�ǹ�	  :  �α��� boundary class
*/
class LogInUI
{
	public:
		void startInterface(){out_fp << "2.1. �α���" << endl;};

};

/*
	Ŭ���� �̸� : LogOut
	�ǹ�	  : �α׾ƿ� control class
*/
class LogOut
{
	public: 
		void logoutMember(Member user){
			out_fp << "> " << user.getID() << endl;
			
			loginUser = nullptr;
		};
};

/*
	Ŭ���� �̸� : LogOutUI
	�ǹ�	  :  �α׾ƿ� boundary class
*/
class LogOutUI
{
	public:
		void startInterface(){out_fp << "2.2. �α׾ƿ�" << endl;};

};

/*
	Ŭ���� �̸� : SearchCloth
	�ǹ�	  : ��ǰ�˻� control class
*/
class SearchCloth
{
	public: 
		void searchClothByName(string clothName);
};

/*
	Ŭ���� �̸� : SearchClothUI
	�ǹ�	  :  ��ǰ�˻� boundary class
*/
class SearchClothUI
{
	public:
		void startInterface(){out_fp << "4.1. ��ǰ ���� �˻�" << endl;};

};







void doTask();
void program_exit();


int main()
{
	doTask();
	return 0;
}


void doTask()
{
	//cout << "doTask����"<< endl;
	// �޴� �Ľ��� ���� level ������ ���� ����
	Member m = Member("TMP_NAME", "000-0000","tmp_id","tmp_pw");
	loginUser = &m;	//�α����� ȸ����� �ӽ÷� ����
	// Members.push_back(m);

	int is_program_exit = 0;
	
	while(!is_program_exit)
	{	
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
						SignOutUI signOutUI = SignOutUI();
						SignOut signOut = SignOut();

						signOutUI.startInterface();
						signOut.deleteMember(*loginUser);

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
						string id, password;		
						in_fp >> id;	
						in_fp >> password;

						LogInUI logInUI = LogInUI();
						LogIn logIn = LogIn();

						logInUI.startInterface();
						logIn.loginMember(id,password);
						break;
					}
					case 2:	// 2.2 �α׾ƿ�
					{
						LogOutUI logOutUI = LogOutUI();
						LogOut logout = LogOut();

						logOutUI.startInterface();
						logout.logoutMember(*loginUser);
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
						addSellCloth.addSellCloth(cloth, *loginUser);
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
						string clothName;		
						in_fp >> clothName;	

						SearchCloth searchCloth = SearchCloth();
						SearchClothUI searchCLothUI = SearchClothUI();

						searchCLothUI.startInterface();
						searchCloth.searchClothByName(clothName);
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
void AddSellCloth::addSellCloth(Cloth cloth, Member user)
{
			string user_id = user.getID();
			Clothes.push_back(cloth);
			if(find(Sellers.begin(), Sellers.end(), user_id) == Sellers.end()){
				Seller seller = Seller(user);
				seller.createSellCloth(cloth);
				Sellers.push_back(seller);
				cout<<"check1 "<<seller.getName()<<"\n";

			}else{
				int idx = find(Sellers.begin(), Sellers.end(), user_id)-Sellers.begin();
				Sellers[idx].createSellCloth(cloth);
				cout<<"check2 "<<Sellers[idx].getName()<<"\n";
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
void AddSellClothUI::startInterface()
{
			out_fp << "3.1. �Ǹ� �Ƿ� ���" << endl;
}

/*
	�Լ� �̸�	: LogIn::loginMember(string id, string password)
	���		: �α���
	���� ����	: string id, string password
	��ȯ��	: ����
	�ۼ���	: ��ä��
*/
void LogIn::loginMember(string id, string password){
			int tmp_idx1 = find(Members.begin(), Members.end(), id)-Members.begin();
			Member tmp = Members[tmp_idx1];

			if(tmp.getPassword().compare(password)==0){
				out_fp << "> " << tmp.getID() <<" "<<tmp.getPassword()<< endl;
			}else{
				out_fp << "> ��й�ȣ�� Ʋ���ϴ�." << endl;
			}
			
			loginUser = &Members[tmp_idx1];
		};

/*
	�Լ� �̸�	: SearchCloth::searchClothByName(string clothName)
	���		: ��ǰ�˻�
	���� ����	: string clothName
	��ȯ��	: ����
	�ۼ���	: ��ä��
*/
void SearchCloth::searchClothByName(string clothName)
{
	for (Seller s : Sellers)
	{
		vector<Cloth> clothlist = s.getSellClothlist();
		if (find(clothlist.begin(), clothlist.end(), clothName) != clothlist.end())
		{
			int tmp_idx1 = find(clothlist.begin(), clothlist.end(), clothName) - clothlist.begin();
			Cloth cloth = clothlist[tmp_idx1];
			out_fp << "> " << s.getID() << " " << cloth.getName() << " " << cloth.getCompany()
				   << " " << cloth.getprice() << " " << cloth.getquantity() << " " << cloth.getAverageEvaluation() << endl;
			break;
		}
	}
};












/*
	�Լ� �̸�	: program_exit()  
	���		: ���α׷� ���� (doTask ����)
	���� ����	: ����
	��ȯ��	: ����
	�ۼ���	: ����ȭ
*/
void program_exit()    
{
	// ��� ����
	out_fp << "6.1. ����" << endl;
}


