# 프로젝트 개요
1인칭 멀티 공포게임

# HorrorGame
3D 멀티 공포게임

# 프로젝트 정보
### 1. 제작기간(미완성)
> 2025.4.4 ~ ing...
### 2. 게임소개
> 리썰컴퍼니라는 게임처럼 아이템을 수집 후 돌아가서 판매해서 아이템을 구매하는 방식으로 진행하는 게임

### 3. 게임계획
- 스폰 된 몬스터는 죽이거나, 무력화 시킬 수 있게 만들 예정
- 물건 수집 후 복귀 해 연구 성과로 업그레이드가 가능 할 예정
- 인벤토리, 배낭 추가 할 예정
- 숨기 기능 넣을 예정

# 사용 엔진 및 프로그램
- 언리얼 엔진5(C++)
- 블렌더

# 현재 기능
- 로비 맵, 병원 맵
- 스팀 연동
- 음성 채팅
- 몬스터 Hehavier Tree로 AI 제작
- 인벤토리
- 멀티 플레이 방 검색, 방 입장, 옵션 등
- 세이브 기능
- 상점 기능
- 체력과 스태미너

# 스크린샷
<details>
  <summary>기본 캐릭터</summary>
    <img width="326" height="174" alt="Image" src="https://github.com/user-attachments/assets/48a41073-2191-460a-a3b8-a895c3bf70d4" />
    <img width="465" height="249" alt="Image" src="https://github.com/user-attachments/assets/959b223c-1b50-4519-aeb3-a25bb691748b" />
</details>
<details>
  <summary>아이템</summary>
    <p>손전등의 배터리는 서버에서 공유</p>
    <img width="864" height="257" alt="Image" src="https://github.com/user-attachments/assets/4eff0485-95f9-404d-8ac1-61d68b5d1efd" />
</details>
<details>
  <summary>몬스터</summary>
    <img width="439" height="609" alt="Image" src="https://github.com/user-attachments/assets/7e13951c-060a-4af8-b898-14d905e6e345" />
</details>
<details>
  <summary>맵</summary>
  <p>로비</p>
  <img width="559" height="256" alt="Image" src="https://github.com/user-attachments/assets/cb934b8c-d55b-49a5-81b2-7551cbc0b61f" />
  <p>병원 맵</p>
  <img width="654" height="728" alt="Image" src="https://github.com/user-attachments/assets/cb9c2353-f915-46b1-bf41-4842a0bc29ce" />
  <img width="340" height="577" alt="Image" src="https://github.com/user-attachments/assets/c6ffc090-9836-43a9-a30a-b0e5fde96d77" />
  <p>상점</p>
  <img width="741" height="401" alt="Image" src="https://github.com/user-attachments/assets/2edbd8b1-7f52-4443-a373-c29f8c93f1ef" />
</details>
<details>
  <summary>맵 이동</summary>
  <img width="556" height="272" alt="Image" src="https://github.com/user-attachments/assets/97d24c1b-fff1-4219-80de-f9d5f44fd9d0" />
</details>


# 느낀 점
- 블렌더로 모델 제작 후 적용하는 과정이 쉽지않다
- 언리얼 엔진이 블루프린터와 C++를 적절히 섞어야 이쁜 구조가 가능하다
- 멀티 방식의 인벤토리 제작이 상당히 어렵다
> 기본적으로 멀티 방식의 디버그가 쉽지 않고 아마 스팀연동이 없었으면 편했을 것 같다 그리고 멀티 서버에는 데디케이트, 호스트 방식이 있는데
> 호스트 방식을 선택함으로서 호스트가 클라이언트와 같은 동작을 처리하게 하는 이중방식이 상당히 고역이다. 코드엔 문제가 없다 생각했는데 문제가 있는 일이 많았다
> 방식이 클라이언트에서 서버를 호출 후 서버에서 실행해서 클라이언트로 뿌려주는 방식이다
> 세가지 RPC(Remote Procedure Call)가 있는데 클라이언트에서 Server로 보내 보내에서 처리해야한다 하나의 클라이언트를 처리하려면
> Server로 보내면서 본인의 컨트롤러등을 같이 보내서 서버에서 처리하게 할 수 있다. 물론 서버에서도 모든 컨트롤러를 가지고 있기 때문에 특정할 수 있다면 가능하다
> 서버에서는 Multicast로 모든 클라이언트에게 함수를 호출 시킬 수 있다
- 개발의 난항을 많이 겪어서 다시 최적화 후 다르게 제작 할 예정이다.
