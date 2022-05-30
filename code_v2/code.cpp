#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME	"input.txt"
#define OUTPUT_FILE_NAME "output.txt"


// Class 선언

/*
	클래스 이름 : Member
	의미	  : 회원 정보를 담고 있다 
*/
class Member
{		
private:
	string name, SSN, ID, password;	// 이름, 주민번호, 아이디, 비밀번호
public:
	Member(string input_name, string input_SSN, string input_ID, string input_password);
	string getName(){return name;}
	string getSSN(){return SSN;}
	string getID(){return ID;} 
	string getPassword(){return password;}  
	bool is_available;	// 이 계정이 사용가능한지 (탈퇴하지 않았는지);
};
vector <Member> Members;	// Member들의 주소를 모아두는 배열


/*
	클래스 이름 : SignUp
	의미	  : 회원 가입 control class
*/
class SignUp
{
public:
	void createMemRequest();
};



/*
	클래스 이름 : SignUpUI
	의미	  : 회원 가입 boundary class
*/
class SignUpUI
{
public:
	void inputInfo();
	void signUpRequest();
};





// 함수 선언

/*
	함수 이름 : Member:::Member()
	기능	  : 새로운 회원을 만드는 생성자
	전달 인자 : string input_name, string input_SSN, string input_ID, string input_password
	반환값    : 없음
*/
Member::Member(string input_name, string input_SSN, string input_ID, string input_password)
{
	name = input_name;
	SSN = input_SSN;
	ID = input_ID;
	password = input_password;
	is_available = true;
}


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
	//cout << "doTask들어옴"<< endl;
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;
	
	while(!is_program_exit)
	{
		// 입력파일에서 메뉴 숫자 2개를 읽기
		in_fp >> menu_level_1 >> menu_level_2;
		
		cout << "확인용) 현재 받은 method 번호: "<< menu_level_1 << " " <<menu_level_2<< endl;
		// 메뉴 구분 및 해당 연산 수행
		switch(menu_level_1)
		{
			case 1:
			{
				switch(menu_level_2)
				{
					case 1:	// "1.1. 회원가입“ 메뉴 부분
					{						
						// join() 함수에서 해당 기능 수행 
						join();
						break;
					}
					case 2:	// 1.2 회원탈퇴
					{
			   
						break;
					}
				}
			}
			case 2:
			{
				switch(menu_level_2)
				{
					case 1:	// 2.1 로그인
					{				
						
						break;
					}
					case 2:	// 2.2 로그아웃
					{
			   
						break;
					}
				}
				
			}
			case 3:
			{
				switch(menu_level_2)
				{
					case 1:	// 3.1 판매 의류 등록
					{				
		   
						break;
					}
					case 2:	// 3.2 등록 상품 조회
					{
			   
						break;
					}
					case 3:	// 3.3 판매 완료 상품 조회
					{
			   
						break;
					}
				}
				
			}
			case 4:
			{
				switch(menu_level_2)
				{
					case 1:	// 4.1 상품 정보 검색
					{				
		   
						break;
					}
					case 2:	// 4.2 상품 구매
					{
			   
						break;
					}
					case 3:	// 4.3 상품 구매 내역 조회
					{
			   
						break;
					}
					case 4:	// 4.4 상품 구매만족도 평가
					{
			   
						break;
					}
				}
				
			}
			case 5:
			{
				switch(menu_level_2)
				{
					case 1:	// 5.1 판매 상품 통계
					{				
		
						break;
					}
					
				}
				
			}
			case 6:
			{
				switch(menu_level_2)
				{
					case 1:	// 6.1 종료
					{				
						program_exit();						
						is_program_exit = 1;
						break;
					}
					
				}
				
			}		  		  		  		
		}
	}
	
	return;
}
  




/*
	함수 이름 : join()
	기능	  : 회원가입 파트에서 호출하는 함수
	전달 인자 : 없음
	반환값    : 없음
*/
void join()    
{
	string name, SSN, ID, password;
	/*
	char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING], 
		address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	*/
	
	// 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
	in_fp >> name >> SSN >> ID >> password;
	// 해당 기능 수행  
    Member newMem = Member(name, SSN, ID, password);
	Members.push_back(newMem);
	
	cout << "확인용(멤버 저장됐는지) 방금 저장된 계정의 사람 이름  "<<Members[0].getName() << endl;
	// 출력 형식
	out_fp << "1.1. 회원가입" << endl;
	out_fp << "> " << name << " " << SSN << " " << ID << " " << password <<endl;
}


void program_exit()    
{
	// 출력 형식
	out_fp << "6.1. 종료" << endl;
}
