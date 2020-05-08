# Hanpotamia
Civilization at Han River



## 이름 규칙

### 참조

- NHN/C++ 코딩 규칙
- 안용학 교수님이 수업에서 언급했던 규칙
- Google C++ Style Guide


### 파일명

- 지금 하고 있는 프로젝트의 컨벤션, 안용학교수님의 컨벤션에 따른다.
- 클래스를 설계하는 경우, 파일 앞에 대문자 C 를 붙인이고, 대쉬 (-) 를 붙이고, 대표 class 이름으로 사용하며, C 를 제외하고는 소문자와 언더바를 사용한다. ex : C-rect_base
- 테스트용 (실행 파일) 의 경우, Test- 를 가장 처음에 포함한다. ex : Test-rect_base
- 파일 이름에 대쉬(-) 를 두 개 이상 사용하지 않는다.


### 함수명

- 일반적인 함수는 대문자로 시작하며, 각 새로운 단어마다 대문자를 사용한다. 언더라인은 사용하지 않는다. ex : MyExcitingFunction()
- 접근자와 수정자(get, set)는 변수 이름과 일치시킨다. ex : Set_strMyExcitingMemberVariable()
- True/False 값을 return 하는 경우, 함수 이름은 is 혹은 has 로 시작한다. ex : IsHungry()
- private 함수 이름은 언더바(_) 로 시작한다. ex : _DontTouchMe()


### 타입명

- 타입명은 대문자로 시작하며, 각 새로운 단어마다 대문자를 갖으며 언더라인을 사용하지 않는다. ex : MyRectangle

### 변수 및 상수명

- 변수명은 소문자로 시작하며, 대문자와 소문자를 섞어서 사용한다.
- 클래스 멤버 변수는 'm_' 으로 시작하며, 간단한 자료형 [string : str, integer : n]을 그 뒤에 표기한 후 이름을 붙인다. ex : m_strMyExcitingLocalVariable
- static 멤버 변수의 경우 's_' 으로 시작한다. ex : s_nMyExcitingStaticVariable
- 이름은 가능한 설명적으로 짓는다. 공간 절약이 중요한 게 아니라, 코드를 즉시 보고 이해할 수 있어야 한다. ex : numCompletedConnections
- 모호한 약어나 의미를 알 수 없는 임의의 문자를 사용하지 않는다. ex : nerr (?)
- 구조체의 데이터 멤버는 일반적인 변수처럼 이름을 짓는다. 클래스처럼 언더라인으로 끝나지 않는다.
- 전역 변수는 특별한 요구사항이 없으며, 거의 사용을 하지 않는다. 만약 사용한다면, g_로 시작하거나 로컬 변수와 구별되는 표시를 한다.
- 상수는 k로 시작하며 대소문자를 섞어서 사용한다 : ex : kDaysInAWeek


### 기타

- 들여쓰기는 Tab 을 사용한다.
- 간단한 생성자 초기화는 콜론 초기화로 한다.
- 이항 연산자 (=, >, <, 등..) 앞과 뒤에 공백을 제공한다. ex : a = b + c
- 단항 연산자 앞과 뒤에 공백을 제공하나, (A++), [--BB], {--KK}와 같이 사용할 때는 공백이 없어도 좋다.
- 일부 연산자(“ , “, “ ; “)는 연산자 뒤에 공백을 제공해야 한다. ex : for( i = 0; i < 3; i++)
- brace( { )는 분리된 라인에 작성한다.

<br>

```C++
class People
{
// 내용
}
void main()
{
// 내용
}
struct DataStructure
{
// 내용
}
```
