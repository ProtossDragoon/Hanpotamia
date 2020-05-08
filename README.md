# Hanpotamia
Civilization at Han River



## 이름 규칙

### 참조

- NHN/C++ 코딩 규칙
- 안용학 교수님이 수업에서 언급했던 규칙
- Google C++ Style Guide

#### 파일명

- 지금 하고 있는 프로젝트의 컨벤션, 안용학교수님의 컨벤션에 따른다.
- 클래스를 설계하는 경우, 파일 앞에 대문자 C 를 붙인이고, 대쉬 (-) 를 붙이고, 대표 class 이름으로 사용하며, C 를 제외하고는 소문자와 언더바를 사용한다. ex : C-rect_base
- 테스트용 (실행 파일) 의 경우, Test- 를 가장 처음에 포함한다. ex : Test-rect_base
- 파일 이름에 대쉬(-) 를 두 개 이상 사용하지 않는다.

#### 함수명

- 일반적인 함수는 대문자로 시작하며, 각 새로운 단어마다 대문자를 사용한다. 언더라인은 사용하지 않는다. ex : MyExcitingFunction()
- 접근자와 수정자(get, set)는 변수 이름과 일치시킨다. ex : Set_strMyExcitingMemberVariable()
- True/False 값을 return 하는 경우, 함수 이름은 is 혹은 has 로 시작한다. ex : IsHungry()
- private 함수 이름은 언더바(_) 로 시작한다. ex : _DontTouchMe()

