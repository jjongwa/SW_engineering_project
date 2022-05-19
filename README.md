# SW_engineering_project
홍익대학교 컴퓨터공학과 22-1학기 소프트웨어공학 팀 프로젝트

# 공통으로 작업한 부분
공통 작성사항 Docx 파일: https://docs.google.com/spreadsheets/d/1YbIPP4zaAAtPmYev8SmDRwtowvDX5O03Sbll24mtvXw/edit?usp=sharing


# 2차 진행과정


## 1. Requirement list
| No.| Requirement                                        | Use Case                                              | 맡은 파트                                              |
| -- |--------------------------------------------------- | ----------------------------------------------------- | ------------------------------------------------------ |
| 1. |사용자는 의류 쇼핑 사이트 사용 권한을 얻기 위해서 회원 가입을 해야 한다. 자신의 기본 정보(이름, 주민번호, 주소, 이메일 등)과 ID/Password를 입력해야 한다.|회원가입| 신종화|
| 2. |회원은 이 사이트에서 탈퇴할 수 있다. 탈퇴와 동시에 시스템의 사용 권한은 소멸 된다.|회원 탈퇴| 김민수 |
| 3. |회원은 등록한 ID와 password로 사이트에 로그인한다.|로그인 | 김민수 |
| 4. |회원은 로그아웃할 수 있다.|로그아웃| 김민수 |
| 5. |회원은 판매하려는 의류를 등록할 수 있다. 등록 시 상품명, 제작회사명, 가격, 수량, 추가상품, 추가상품 가격, 판매 종료일 등의 정보를 입력해야 한다|판매의류 등록| 하채형 |
| 6. |각 회원은 자신이 등록한 판매 중인 의류 상품 리스트를 조회할 수 있다|판매중인 의류 조회| 하채형 |
| 7. |회원은 자신이 판매 완료한 의류 상품을 조회할 수 있다. 판매 완료한 상품은 남은 수량이 0이 된 상품을 의미한다. 이때 상품명의 오름차순으로 정렬해서 출력하며 각 상품에 대해 상품명, 제작회사명, 가격, 판매된 수량, 평균 구매만족도를 출력한다.|판매 완료 상품 내역 조회| 하채형 |
| 8. |회원이 판매한 상품에 대한 총액 및 평균 구매만족도를 출력한다.|상품 판매 통계| 하채형 |
| 9. |회원이 상품명을 입력하여 상품을 검색할 수 있으며 이에 해당하는 상세한 정보(판매자ID, 상품명, 제작회사명, 가격, 남은 수량, 추가상품, 추가상품 가격, 판매 종료일, 평균 구매만족도)가 출력된다|상품 정보 검색| 김민수 |
| 10. |구매 진행|상품 구매| 신종화 |
| 11. |회원은 구매 내역(상품명, 제작회사명, 판매자, 가격, 평균 구매만족도, 구매일)을 조회할 수 있다. 이때 상품명의 오름차순으로 정렬해서 출력한다.|상품 구매 내역 조회| 신종화 |
| 12. |조회된 구매 내역 중에서 하나의 상품을 선택하여 구매만족도를 평가|구매만족도 평가| 신종화 |



## 2. Actor_description
| No.| Actor                                              | Description                                           |
| -- |--------------------------------------------------- | ----------------------------------------------------- | 
| 1. |비회원|자신의 정보로 계정을 생성하지 않은 사람|
| 2. |회원|자신의 정보로 생성된 계정이 존재하는 사람|
| 3. |판매자|판매할 물건을 등록하는 사용자|
| 4. |구매자|물건을 구매하는 사용자|









# 1차 진행과정

## 1. Requirement list
| No.| Requirement                                        | Use Case                                              | 맡은 파트                                              |
| -- |--------------------------------------------------- | ----------------------------------------------------- | ------------------------------------------------------ |
| 1. |사용자는 의류 쇼핑 사이트 사용 권한을 얻기 위해서 회원 가입을 해야 한다. 자신의 기본 정보(이름, 주민번호, 주소, 이메일 등)과 ID/Password를 입력해야 한다.|회원가입| 하채형|
| 2. |회원은 이 사이트에서 탈퇴할 수 있다. 탈퇴와 동시에 시스템의 사용 권한은 소멸 된다. 단, 회원은 등록한 상품이 하나도 없는 상태에서 탈퇴할 수 있다.|회원 탈퇴| - |
| 3. |회원은 등록한 ID와 password로 사이트에 로그인해야 한다.|로그인 | -|
| 4. |회원이 로그아웃하면 프로그램은 자동으로 종료된다.|로그아웃| -|
| 5. |회원은 판매하려는 의류를 등록할 수 있다. 등록 시 상품명, 제작회사명, 가격, 수량, 추가상품, 추가상품 가격, 판매 종료일 등의 정보를 입력해야 한다|판매의류 등록| - |
| 6. |각 회원은 자신이 등록한 판매 중인 의류 상품 리스트를 조회할 수 있다|판매중인 의류 조회| - |
| 7. |특정 상품을 선택한 후에 그 상품에 대한 모든 항목을 수정할 수 있다|판매의류 수정| - |
| 8. |특정 상품을 선택한 후에 그 상품을 삭제할 수 있다|판매의류 삭제| - |
| 9. |회원은 자신이 판매 완료한 의류 상품을 조회할 수 있다. 판매 완료한 상품은 판매 종료일이 지났거나 남은 수량이 0이 된 상품을 의미한다. 이때 상품명의 오름차순으로 정렬해서 출력하며 각 상품에 대해 상품명, 제작회사명, 가격, 판매된 수량, 평균 구매만족도를 출력한다.|판매 완료 상품 내역 조회| 김민수 |
| 10. |회원이 검색 조건(상품명, 평균 구매만족도 중에 하나)을 선택하여 입력하면 이에 해당하는 상품 리스트(상품명 및 평균 구매만족도 포함)를 출력한다. 디폴트 정렬 기준은 상품명의 오름차순이며|상품 리스트 조회| - |
| 11. |정렬 기준 사용자가 평균 구매만족도로 변경할 수 있다.|정렬 기준 변경| - |
| 12. |구매를 원하는 상품을 선택하면 해당 상품의 상세한 정보(판 매자, 상품명, 제작회사명, 가격, 남은 수량, 추가상품, 추가상품 가격, 판매 종료일, 평균 구매만족도)가 출력|상품 상세조회| - |
| 13. |결제 진행|결제(구매)| - |
| 14. |포인트 사용을 선택할 수 있다. 포인트는 3000점 이상이 적립되어 있는 경우에 사용 가능하다.|포인트 사용| - |
| 15. |구입 금액의 1%를 포인트로 적립해 주며|not applicable| - |
| 16. |환불이 되는 경우에는 다시 사용될 수 있도록 반환된다.|not applicable| - |
| 17. |상품 구매 시 추가 상품으로 등록한 물품도 선택해서 같이 구매할 수 있다. 이 경우 추가 상품의 금액만큼 증가된 가격으로 총 구매금액이 결정된다.|추가 상품 구매| - |
| 18. |회원은 구매 내역(상품명, 제작회사명, 판매자, 가격, 평균 구매만족도, 구매일)을 조회할 수 있다. 이때 상품명의 오름차순으로 정렬해서 출력한다.|상품 구매 내역 조회| 신종화 |
| 19. |조회된 구매 내역 중에서 하나의 상품을 선택하여 구매만족도를 평가|구매만족도 평가| - |
| 20. |구입 후 4주가 지나지 않은 상품의 경우 환불을 신청할 수 있다.|환불 신청| - |
| 21. |환불을 신청하는 경우 택배사에 자동으로 물품 수거 신청이 요청된다.|not applicable| - |
| 22. |3개월이 지난 구매 거래내역부터 임의로 삭제가 가능하며 그 이전의 거래내역 은 임의로 삭제가 불가능하다. 또한 6개월이 지난 거래내역은 자동으로 삭제된 다.|상품 구매 내역 삭제| - |
| 23. |회원이 판매한 상품에 대한 총액 및 평균 구매만족도를 출력한다.|상품 판매 통계| - |
| 24. |회원이 구매한 상품에 대한 총액 및 평균 구매만족도를 출력한다. 이때, 삭제된 구매 내역은 통계에서 제외한다.|상품 구매 통계| - |
| 25. |매월 말일에 모든 회원들에게 그 달에 대한 판매 및 구매 통계 정보를 이메일로 공지된다.|상품 통계 공지| - |


## 2. Actor_description
| No.| Actor                                              | Description                                           |
| -- |--------------------------------------------------- | ----------------------------------------------------- | 
| 1. |비회원|자신의 정보로 계정을 생성하지 않은 사람|
| 2. |회원|자신의 정보로 생성된 계정이 존재하는 사람|
| 3. |판매자|판매할 물건을 등록하는 사용자|
| 4. |구매자|물건을 구매하는 사용자|
| 5. |택배사 물품 수거관련 event|환불신청이 처리되면 택배사에 물품 수거를 신청하는 event|
| 6. |포인트반환 event|환불신청이 처리되면 환불 하는 사람의 포인트에서 자동 차감되는 event|
| 7. |6개월 후 자동삭제 event|상품을 구매하고 나서 6개월이 지나면 기록 자동 삭제 event|
| 8. |매월 말일 공지 event|매월 말일에 상품 구매내역과 판매내역 통계를 이메일로 전송해주는 event|
