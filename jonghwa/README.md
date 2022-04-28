# SW_engineering_project
홍익대학교 컴퓨터공학과 22-1학기 소프트웨어공학 팀 프로젝트
## 개발일지- B611107신종화
### 1) Requirement list
+ 먼저 functional과 non-functional을 구분하자
  + functional이란?
  
    System이 반드시 해야 하는 것 -> 기능
    input과 output이 존재한다
    UseCase Diagram에 표현할 수 있다.
    
  + Non-functional은?
    
    기능 그 자체가 아닌것들
    성능, 신뢰성, 보안성, 안정성, 가용성 등의 키워드
    + 어떠한 퍼포먼스의 기준
    + 예상되는 data의 양, 그 양의 척도
    + 보안 레벨
    그림으로 표현하기 어렵다 -> List의 형식으로 표현

참고 링크: https://ee-22-joo.tistory.com/2

+ 각 기능들을 구분해보자
    + 회원 가입 기능 -> func
      + 이름, 주민번호, 주소, 이메일, Id, Pw 입력 -> 회원가입 완료
    + 회원 탈퇴 기능 -> func
      + 탈퇴와 동시에 권한 소멸 -> 회원 탈퇴 description
      + 등록 상품이 없는 상태에서 탈퇴 가능 -> 회원 탈퇴 description
    + 로그인/로그아웃 기능
      +    로그인: Id, Pw 입력 -> 로그인 여부 확인 -> func
      +    로그아웃 -> func (프로그램 종료는 description으로)
    + 판매 의류 등록 및 조회/수정 기능 
      + 상품명, 제작회사명, 가격, 수량, 추가상품, 추가상품 가격, 판매 종료일 입력 -> 판매 등록 -> func
      + 판매 리스트 조회 -> func
      + 특정 상품 수정 -> func
    + 판매 완료된 상품 내역 조회 기능 -> func
      + 종료일 지났거나 수량 0 의 조건 존재
      + 오름차순 정렬 
    + 상품 정보 조회 및 상품 구매 기능-> func
      + 회원이 검색조건 입력 -> 해당하는 리스트 출력
    + 결제 기능 
      + 결제요청 -> 결제 실행 -> func
      + 포인트 사용 선택 가능 -> description
      + 포인트 3000점 이상일때만 가능이라은 기준 존재 -> description
    + 포인트 적립 기능 -> func
      + 구매 금액의 1% 적립 -> description
      + 환불시 포인트 반황 -> event
    + 추가 상품 구매 기능 - func
      + 상품 구매 시 추가상품 선택 -> extend
      + 이 때 계산은 한꺼번에 -> description
    + 상품 구매 내역 관리 기능
      + 구매 내역 조회 -> func
      + 구매만족도 평가 -> func
      + 환불신청 -> func 
      + 구입 후 4주 제한 조건 존재 -> description
    + 상품 구매 내역 삭제 기능 -> func
      + 3개월이 지난 구매 거래내역 -> 조건 -> description
      + 6개월 이상 자동 삭제 -> event
    + 상품 판매/구매 통계 기능
      + 판매/구매한 상품 선택 -> 총액 및 평균 구매만족도 출력 - func
      + 삭제한 구매내역은 제외 -> description
      + 매월 말일에 통계정보 이메일로 공지 -> event
