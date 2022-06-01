#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME	"input.txt"
#define OUTPUT_FILE_NAME "output.txt"

ifstream in_fp(INPUT_FILE_NAME);
ofstream out_fp(OUTPUT_FILE_NAME);





// Class 선언




/*
	클래스 이름 : Cloth
	의미	  : 옷 정보를 담고 있다
*/
class Cloth
{
private:
	string clothName;
	string companyName;
	int price;
	int quantity;
	int averageEvaluation = 0;
	// vector<Evaluation> evaluationCollection;
public:
	Cloth(string input_clothName, string input_companyName, int input_price, int input_quantity) {
		clothName = input_clothName;
		companyName = input_companyName;
		price = input_price;
		quantity = input_quantity;
	};

	bool operator== (const string& s) {
		if (this->getName().compare(s) == 0) {
			return true;
		}
		else {
			return false;
		}
	};

	string getName() const { return clothName; };
	string getCompany() { return companyName; };
	int getprice() { return price; };
	int getquantity() { return quantity; };
	int getAverageEvaluation() { return averageEvaluation; };
	void buyCloth();
	void updateRate(Cloth* cloth, int rate);

};
vector <Cloth> Clothes;	// Cloth들의 주소를 모아두는 배열

/*
	클래스 이름 : ClothRating
	의미	  : 해당 의류의 구매만족도가 담겨있다. 
*/
class ClothRating
{
private:
	Cloth* cloth;
	int rate;
public:
	Cloth* getCloth() { return cloth; };
	int getRate() { return rate; };
	ClothRating(Cloth* cloth, int rate);
};
vector <ClothRating> ClothRatingList;



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
	bool operator== (const string& s) {
		if (this->getID().compare(s) == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	string getName() { return name; }
	string getSSN() { return SSN; }
	string getID() const { return ID; }
	string getPassword() { return password; }
	bool is_available;	// 이 계정이 사용가능한지 (탈퇴하지 않았는지);
};
vector <Member> Members;	// Member들의 주소를 모아두는 배열
Member* loginUser; //로그인한 사용자

/*
	클래스이름 : Seller
	의미	: 판매자 정보를 담고 있다.
*/
class Seller : public Member
{
private:
	vector<Cloth> sellClothCollection;
	vector<Cloth> soldoutClothCollection;
public:
	Seller(Member member) : Member(member.getName(), member.getSSN(), member.getID(), member.getPassword()) {};
	bool operator== (const string& s) {
		if (this->getID().compare(s) == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	void createSellCloth(Cloth cloth) {
		sellClothCollection.push_back(cloth);
	};
	vector<Cloth> getSellClothlist() { return sellClothCollection; };
	vector<Cloth> getSoldoutClothlist() { return soldoutClothCollection; };
};
vector <Seller> Sellers;	//Seller들의 주소를 모아두는 배열



/*
	클래스 이름 : PurchaseProcudt
	의미		: 구매내역 (구매자 이름, 상품이름)
*/
class PurchaseProcudt
{
private:
	string buyerID;
	Cloth* product;
public:
	PurchaseProcudt(string input_buyer, Cloth* input_product);
	string getBuyerID() { return buyerID; };
	Cloth* getProduct() { return product; };

};
vector <PurchaseProcudt> PurchaseProductList;	//PurchaseProcudt들의 주소를 모아두는 배열

/*
	클래스 이름 	: PurchaseCloth
	기능	  		: 의류 구매 control class
	작성자			: 신종화
*/
class PurchaseCloth
{
public:
	void purchaseClothRequest(string buyer, string productName);
};



/*
	클래스 이름 	: PurchaseClothUI
	기능	  		: 의류 구매 boundary class
	작성자			: 신종화
*/
class PurchaseClothUI
{
public:
	void purchase(string buyer, string productName);
};


/*
	클래스 이름 	: PurchaseListUI
	기능	  		: 상품 구매내역 조회 boundary class
	작성자			: 신종화
*/
class PurchaseListUI
{
public:
	void showPurchaseList(string buyerID);
};


/*
	클래스 이름 	: PurchaseList
	기능	  		: 상품 구매내역 조회 controll class
	작성자			: 신종화
*/
class PurchaseList
{
public:
	void showPurchaseProduct(string buyerID);
};


/*
	클래스 이름 	: RatingUI
	기능	  		: 구매만족도 평가 boundary class
	작성자			: 신종화
*/
class RatingUI
{
public:
	void ratingProduct(string buyerID, string productName, int rate);
};


/*
	클래스 이름 	: Rating
	기능	  		: 구매만족도 평가 controll class
	작성자			: 신종화
*/
class Rating
{
public:
	void createRate(string buyerID, string productName, int rate);

};




/*
	클래스 이름 	: SignUp
	기능	  		: 회원 가입 control class
	작성자		: 신종화
*/
class SignUp
{
public:
	void createMemRequest(string name, string SSN, string ID, string password);
};


/*
	클래스 이름	: SignUpUI
	기능  		: 회원 가입 boundary class
	작성자		: 신종화
*/
class SignUpUI
{
public:
	void signUpRequest();
};

/*
	클래스 이름 : AddSellCloth
	의미	  : 판매의류 등록 control class
*/
class AddSellCloth
{
public:
	void addSellCloth(Cloth cloth, Member user);
};

/*
	클래스 이름 : AddSellClothUI
	의미	  : 판매의류 등록 boundary class
*/
class AddSellClothUI
{
public:
	Cloth createSellCloth(string clothName, string companyName, int price, int quantity) {
		Cloth cloth = Cloth(clothName, companyName, price, quantity);
		return cloth;
	};
	void startInterface();

};

/*
	클래스 이름 : SignOut
	의미	  : 회원탈퇴 control class
*/
class SignOut
{
public:
	void deleteMember(Member user) {
		vector<Member>::iterator tmp_idx1 = find(Members.begin(), Members.end(), user.getID());
		Members.erase(tmp_idx1);

		vector<Seller>::iterator tmp_idx2 = find(Sellers.begin(), Sellers.end(), user.getID());
		Sellers.erase(tmp_idx2);
		out_fp << "> " << user.getID() << endl;

		loginUser = nullptr;
	};
};

/*
	클래스 이름 : SignOUtUI
	의미	  :  회원탈퇴 boundary class
*/
class SignOutUI
{
public:
	void startInterface() { out_fp << "1.2. 회원탈퇴" << endl; };

};

/*
	클래스 이름 : LogIn
	의미	  : 로그인 control class
*/
class LogIn
{
public:
	void loginMember(string id, string password);
};

/*
	클래스 이름 : LogInUI
	의미	  :  로그인 boundary class
*/
class LogInUI
{
public:
	void startInterface() { out_fp << "2.1. 로그인" << endl; };

};

/*
	클래스 이름 : LogOut
	의미	  : 로그아웃 control class
*/
class LogOut
{
public:
	void logoutMember(Member user) {
		out_fp << "> " << user.getID() << endl;

		loginUser = nullptr;
	};
};

/*
	클래스 이름 : LogOutUI
	의미	  :  로그아웃 boundary class
*/
class LogOutUI
{
public:
	void startInterface() { out_fp << "2.2. 로그아웃" << endl; };

};

/*
	클래스 이름 : SearchCloth
	의미	  : 상품검색 control class
*/
class SearchCloth
{
public:
	void searchClothByName(string clothName);
};

/*
	클래스 이름 : SearchClothUI
	의미	  :  상품검색 boundary class
*/
class SearchClothUI
{
public:
	void startInterface() { out_fp << "4.1. 상품 정보 검색" << endl; };

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
	//cout << "doTask들어옴"<< endl;
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	Member m = Member("TMP_NAME", "000-0000", "tmp_id", "tmp_pw");
	loginUser = &m;	//로그인한 회원없어서 임시로 만듬
	// Members.push_back(m);
	string searchProductName;	// 4.1 상품 정보 검색에서 검색한 상품 이름을 저장하기 위한 변수 (4.2 상품 구매에서 활용) 

	int is_program_exit = 0;

	while (!is_program_exit)
	{
		string dummy;	// 루프 방지를 위한 변수
		int menu_level_1 = 0, menu_level_2 = 0;
		// 입력파일에서 메뉴 숫자 2개를 읽기
		in_fp >> menu_level_1 >> menu_level_2;
		//cout << "확인용) 현재 받은 method 번호: " << menu_level_1 << " " << menu_level_2 << endl;
		
		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1:	// "1.1. 회원가입“ 메뉴 부분
			{
				SignUpUI* startSignUpUI = new SignUpUI;
				startSignUpUI->signUpRequest();

				out_fp << endl;
				break;
			}
			case 2:	// 1.2 회원탈퇴
			{
				SignOutUI signOutUI = SignOutUI();
				SignOut signOut = SignOut();

				signOutUI.startInterface();
				signOut.deleteMember(*loginUser);

				out_fp << endl;
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1:	// 2.1 로그인
			{
				string id, password;
				in_fp >> id;
				in_fp >> password;

				LogInUI logInUI = LogInUI();
				LogIn logIn = LogIn();

				logInUI.startInterface();
				logIn.loginMember(id, password);
				//cout << loginUser->getID() << " " << loginUser->getName() << endl;

				out_fp << endl;
				break;
			}
			case 2:	// 2.2 로그아웃
			{
				LogOutUI logOutUI = LogOutUI();
				LogOut logout = LogOut();

				logOutUI.startInterface();
				logout.logoutMember(*loginUser);

				out_fp << endl;
				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1:	// 3.1 판매 의류 등록
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
				Cloth cloth = addSellClothUI.createSellCloth(clothName, companyName, price, quantity);
				addSellCloth.addSellCloth(cloth, *loginUser);

				out_fp << endl;
				break;
			}
			}
			break;
		}
		case 4:
		{
			switch (menu_level_2)
			{
			case 1:	// 4.1 상품 정보 검색
			{
				string clothName;
				in_fp >> clothName;
				searchProductName = clothName;	// 검색한 상품 이름 저장 (구매할때를 대비해)
				SearchCloth searchCloth = SearchCloth();
				SearchClothUI searchCLothUI = SearchClothUI();

				searchCLothUI.startInterface();
				searchCloth.searchClothByName(clothName);

				out_fp << endl;
				break;
			}
			case 2:	// 4.2 상품 구매
			{
				PurchaseClothUI* startPurchaseClothUI = new PurchaseClothUI;
				startPurchaseClothUI->purchase(loginUser->getID(), searchProductName);


				out_fp << endl;
				break;
			}
			case 3:	// 4.3 상품 구매 내역 조회
			{
				PurchaseListUI* newPurchaseListUI = new PurchaseListUI;
				newPurchaseListUI->showPurchaseList(loginUser->getID());

				out_fp << endl;
				break;
			}
			case 4:	// 4.4 상품 구매만족도 평가
			{
				string productName; 
				int rate;
				in_fp >> productName >> rate;

				string loginUserID = loginUser->getID();

				RatingUI* newRatingUI = new RatingUI;
				newRatingUI->ratingProduct(loginUserID, productName, rate);


				out_fp << endl;
				break;
			}
			}
			break;
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1:	// 6.1 종료
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










// 함수 선언

/*
	함수 이름	: Member:::Member()
	기능		: 새로운 회원을 만드는 생성자
	전달 인자	: string input_name, string input_SSN, string input_ID, string input_password
	반환값	: 없음
	작성자	: 신종화
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
	함수 이름	: SignUpUI::signUpRequest()
	기능		: 회원가입 진행을 시작하는 함수, 회원가입에 필요한 정보를 입력받음
	전달 인자	: 없음
	반환값	: 없음, SignUp->createMemRequest() 호출
	작성자	: 신종화
*/
void SignUpUI::signUpRequest()
{
	// 출력 형식
	out_fp << "1.1. 회원가입" << endl;

	string name, SSN, ID, password;
	in_fp >> name >> SSN >> ID >> password;

	SignUp* startSignUp = new SignUp;
	startSignUp->createMemRequest(name, SSN, ID, password);

}

/*
	함수 이름	: SignUpUI::createMemRequest(string name, string SSN, string ID, string password)
	기능		: 회원가입 진행, 입력받은 정보로 Member 클래스 만들어 Members 벡터에 저장
	전달 인자	: string name, string SSN, string ID, string password
	반환값	: 없음
	작성자	: 신종화
*/
void SignUp::createMemRequest(string name, string SSN, string ID, string password)
{
	Member newMem = Member(name, SSN, ID, password);
	Members.push_back(newMem);

	//cout << "확인용(멤버 저장됐는지) 방금 저장된 계정의 사람 이름  " << Members.back().getName() << endl;
	// 출력 형식
	out_fp << "> " << name << " " << SSN << " " << ID << " " << password << endl;
}

/*
	함수 이름	: AddSellCloth::addSellCloth(Cloth cloth, Member user)
	기능		: 판매자 생성 및 이미 존재시 판매의류 목록에 Cloth 추가
	전달 인자	: Cloth cloth, Member user
	반환값	: 없음
	작성자	: 하채형
*/
void AddSellCloth::addSellCloth(Cloth cloth, Member user)
{
	string user_id = user.getID();
	Clothes.push_back(cloth);
	if (find(Sellers.begin(), Sellers.end(), user_id) == Sellers.end()) {
		Seller seller = Seller(user);
		seller.createSellCloth(cloth);
		Sellers.push_back(seller);
		//cout << "check1 " << seller.getName() << "\n";

	}
	else {
		int idx = find(Sellers.begin(), Sellers.end(), user_id) - Sellers.begin();
		Sellers[idx].createSellCloth(cloth);
		//cout << "check2 " << Sellers[idx].getName() << "\n";
	}
	out_fp << "> " << cloth.getName() << " " << cloth.getCompany() << " " << cloth.getprice() << " " << cloth.getquantity() << endl;

};

/*
	함수 이름	: AddSellClothUI::startInterface()
	기능		: 판매의류 추가 UI생성
	전달 인자	: 없음
	반환값	: 없음
	작성자	: 하채형
*/
void AddSellClothUI::startInterface()
{
	out_fp << "3.1. 판매 의류 등록" << endl;
}

/*
	함수 이름	: LogIn::loginMember(string id, string password)
	기능		: 로그인
	전달 인자	: string id, string password
	반환값	: 없음
	작성자	: 하채형
*/
void LogIn::loginMember(string id, string password) {
	int tmp_idx1 = find(Members.begin(), Members.end(), id) - Members.begin();
	Member tmp = Members[tmp_idx1];

	if (tmp.getPassword().compare(password) == 0) {
		out_fp << "> " << tmp.getID() << " " << tmp.getPassword() << endl;
	}
	else {
		out_fp << "> 비밀번호가 틀립니다." << endl;
	}

	loginUser = &Members[tmp_idx1];
};

/*
	함수 이름	: SearchCloth::searchClothByName(string clothName)
	기능		: 상품검색
	전달 인자	: string clothName
	반환값	: 없음
	작성자	: 하채형
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
	함수 이름	: PurchaseProcudt::PurchaseProcudt(string buyer, Cloth* product)
	기능		: 새로운 구매내역을 만드는 생성자
	전달 인자	: string buyer, Cloth* product
	반환값	: 없음
	작성자	: 신종화
*/

PurchaseProcudt::PurchaseProcudt(string input_buyerID, Cloth* input_product) {
	buyerID = input_buyerID;
	product = input_product;
}



/*
	함수 이름	: PurchaseClothUI::purchase()
	기능		: 상품 구매 UI에서 호출
	전달 인자	: string productName
	반환값		: 없음
	작성자		: 신종화
*/
void PurchaseClothUI::purchase(string buyerID, string productName)
{
	// 출력 형식
	out_fp << "4.2. 상품 구매" << endl;

	PurchaseCloth* startPurchaseCloth = new PurchaseCloth;
	startPurchaseCloth->purchaseClothRequest(buyerID, productName);

}


/*
	함수 이름	: PurchaseCloth::purchaseClothRequest()
	기능		: 상품 구매 진행( productName을 받아 이름이 같은 Cloth를 찾고 새로운 구매내역 생성, Closth의 수량 변경 함수 호출)
	전달 인자	: string productName
	반환값		: 없음
	작성자		: 신종화
*/
void PurchaseCloth::purchaseClothRequest(string buyerID, string productName)
{
	for (vector< Cloth>::size_type i = 0; i < Clothes.size(); i++) {
		if (Clothes[i].getName() == productName && Clothes[i].getquantity() > 0) {	// 상품목록 중 일치하는 이름이 있다면
			// 1. 구매내역에 추가
			PurchaseProcudt* newPurchaseProcudt = new PurchaseProcudt(buyerID, &Clothes[i]);
			PurchaseProductList.push_back(*newPurchaseProcudt);

			// 2. 상품 수량 -1
			Clothes[i].buyCloth();

			// 3. productNmae을 통해 Seller를 찾고 seller ID 출력
			for (vector<Seller>::size_type j = 0; j < Sellers.size(); j++) {				
				for (vector<Cloth>::size_type k = 0; k < Sellers[j].getSellClothlist().size(); k++) {
					if (Sellers[j].getSellClothlist()[k].getName() == productName) {
						out_fp << "> " << Sellers[j].getID();
					}
				}
			}

			// 4. 상품명 출력
			out_fp <<" " << newPurchaseProcudt->getProduct()->getName() << endl;
		}
	}
	
}

/*
	함수 이름	: PurchaseListUI::showPurchaseList(string buyerID)
	기능		: 구매 내역 조회 UI 호출
	전달 인자	: string buyerID
	반환값		: 없음
	작성자		: 신종화
*/
void PurchaseListUI::showPurchaseList(string buyerID)
{
	// 출력 형식
	out_fp << "4.3. 상품 구매 내역 조회" << endl;

	PurchaseList* newPurchaseList = new PurchaseList;
	newPurchaseList->showPurchaseProduct(buyerID);
}

/*
	함수 이름	: Cloth::buyCloth()
	기능		: 상품의 수량 변경
	전달 인자	: string productName
	반환값		: 없음
	작성자		: 신종화
*/
void Cloth::buyCloth() {
	quantity -= 1;
}


/*
	함수 이름	: PurchaseList::showPurchaseProduct(string buyerID)
	기능		: 구매 내역 호츌
	전달 인자	: string buyerID
	반환값		: 없음
	작성자		: 신종화
*/
void PurchaseList::showPurchaseProduct(string buyerID)
{
	for (vector< PurchaseProcudt>::size_type i = 0; i < PurchaseProductList.size(); i++) {
		if (PurchaseProductList[i].getBuyerID() == buyerID) {

			for (vector<Seller>::size_type j = 0; j < Sellers.size(); j++) {
				for (vector<Cloth>::size_type k = 0; k < Sellers[j].getSellClothlist().size(); k++) {
					if (Sellers[j].getSellClothlist()[k].getName() == PurchaseProductList[i].getProduct()->getName()) {
						out_fp << "> " << Sellers[j].getID();
					}
				}
			}
			out_fp << " " << PurchaseProductList[i].getProduct()->getName() << " " << PurchaseProductList[i].getProduct()->getCompany();
			out_fp << " " << PurchaseProductList[i].getProduct()->getprice() << " " << PurchaseProductList[i].getProduct()->getquantity();
			out_fp << " " << PurchaseProductList[i].getProduct()->getAverageEvaluation() << endl;

		}
	}
}



/*
	함수 이름	: RatingUI::ratingProduct(string productName) 
	기능		: 구매만족도 평가 UI 호출
	전달 인자	: string productName
	반환값		: 없음
	작성자		: 신종화
*/
void RatingUI::ratingProduct(string buyerID, string productName, int rate)
{
	// 출력 형식
	out_fp << "4.4. 상품 구매만족도 평가" << endl;
	Rating* newRating = new Rating;
	newRating->createRate(buyerID, productName, rate);
}

/*
	함수 이름	: ClothRating::ClothRating(Cloth* cloth, int rate)
	기능		: 상품 구매만족도 생성자
	전달 인자	: Cloth* cloth, int rate
	반환값		: ClothRating
	작성자		: 신종화
*/
ClothRating::ClothRating(Cloth* input_cloth, int input_rate)
{
	cloth = input_cloth;
	rate = input_rate;
}



/*
	함수 이름	: Rating::createRate(string productName)
	기능		: 구매만족도 평가 호출
	전달 인자	: string productName
	반환값		: 없음
	작성자		: 신종화
*/
void Rating::createRate(string buyerID, string productName, int rate)
{
	int avg;
	// 이 상품의 구매자인지 확인 필요
	for (vector< PurchaseProcudt>::size_type i = 0; i < PurchaseProductList.size(); i++) { // 구매목록 벡터 for문
		if (PurchaseProductList[i].getBuyerID() == buyerID && PurchaseProductList[i].getProduct()->getName() == productName) {
			PurchaseProductList[i].getProduct()->updateRate(PurchaseProductList[i].getProduct(), rate);
			avg = PurchaseProductList[i].getProduct()->getAverageEvaluation();
		}
	}

	// 판매자 아이디 알아야함..!ㅜ
	for (vector< PurchaseProcudt>::size_type i = 0; i < PurchaseProductList.size(); i++) {
		if (PurchaseProductList[i].getBuyerID() == buyerID) {

			for (vector<Seller>::size_type j = 0; j < Sellers.size(); j++) {
				for (vector<Cloth>::size_type k = 0; k < Sellers[j].getSellClothlist().size(); k++) {
					if (Sellers[j].getSellClothlist()[k].getName() == productName) {
						out_fp << "> " << Sellers[j].getID();
					}
				}
			}
			out_fp << " " << productName << " "<< avg << endl;

		}
	}

}

/*
	함수 이름	: Cloth::updateRate(int rate)
	기능		: 상품의 평균 구매만족도를 변경한다.
	전달 인자	: int rate
	반환값		: 없음
	작성자		: 신종화
*/
void Cloth::updateRate(Cloth* cloth, int rate)
{
	// 1. 구매만족도 생성
	ClothRating* newClothRating = new ClothRating( cloth, rate);
	ClothRatingList.push_back(*newClothRating);
	
	double updateRate = 0;
	double ratecount = 0;
	double avgRate = 0;
	for (vector< ClothRating>::size_type i = 0; i < ClothRatingList.size(); i++) { // 구매목록 벡터 for문
		if (ClothRatingList[i].getCloth() == cloth) {
			updateRate += ClothRatingList[i].getRate();
			ratecount += 1;
		}
	}
	avgRate = updateRate / ratecount;

	averageEvaluation = round(avgRate);

}




/*
	함수 이름	: program_exit()
	기능		: 프로그램 종료 (doTask 종료)
	전달 인자	: 없음
	반환값	: 없음
	작성자	: 신종화
*/
void program_exit()
{
	// 출력 형식
	out_fp << "6.1. 종료" << endl;
}


